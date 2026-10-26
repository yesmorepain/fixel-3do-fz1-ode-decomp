# The command set

Every command the firmware answers, and exactly what it replies. Source: `source/src/cdrom.c` (handlers and
dispatcher) and `source/src/ode.c` (directory listing, play queue, update). See [firmware.md](firmware.md) for how
the packets reach the RP2040.

Opcode names follow FCare's SataTo3DO (`docs/satato3do/3DO.c`, MIT), an open implementation of the same drive
protocol and of Fixel's ODE extensions. Its `case` for each opcode is a useful second reading. Where the two
disagree, this document describes what piode2 does.

## Packets and the dispatcher

The 3DO sends a 7-byte command: opcode in byte 0, arguments in bytes 1-6. Multi-byte arguments are big-endian.
The firmware answers with a status reply:

```
[opcode echo] [data bytes ...] [status]
```

`cd_cmd_dispatch` (0x10016854 in the original) does, for every command:

1. reads the command (SPI port 0x01) into `cd_state.cmd`;
2. starts the reply with the opcode echo;
3. clears CHECK_ERROR in the status byte, and clears the error code unless the opcode is 0x82 (READ_ERROR, which
   reports it);
4. jumps through a 241-entry table (opcodes 0x00-0xF0) to the handler;
5. appends the status byte and sends the reply (SPI port 0x02, at most 64 bytes).

Commands that return bulk data (READ_DATA, D1, E7) send it through the FPGA's data FIFO before the status reply.

An opcode with no handler (207 of the 241 slots, and anything above 0xF0 is never decoded) gets CHECK_ERROR and
error 0x17 (ILLEGAL_REQUEST).

## Drive state

`cd_state` (at 0x200050cc, layout in `source/src/piode2.h`) holds:

| Field | Meaning |
|---|---|
| status | 3DO drive status byte, bits below |
| error | Last error code, returned by READ_ERROR |
| disc_present | 1 while an image (or `boot.iso`) is mounted; updated every 10 ms |
| density, blen, flags | MODE SELECT page 0: block length 2048 (0x800) or 2352 (0x930), extra-byte flags |
| err_mode, err_count, stop_time, speed, pitch, chunk | MODE SELECT pages 1-4 (stored, mostly unused) |
| cdda_mode | FPGA switched to audio mode |
| fops_checksum | Byte sum of file-operation transfers (logged only) |

Status bits (names from SataTo3DO):

| Bit | Name | Set by |
|---|---|---|
| 0x80 | TRAY_IN | Reset state; INJECT |
| 0x40 | DISC_PRESENT | The 10 ms check, when an image becomes mounted; INJECT with a disc |
| 0x20 | SPINNING | SPIN_UP |
| 0x10 | CHECK_ERROR | Any failed command; cleared at the start of each command |
| 0x02 | DOUBLE_SPEED | MODE SELECT page 3, bit 7 of the speed byte |
| 0x01 | DISC_RDY | Most successful commands |

After a reset (boot, button press) the state is cleared to status 0x81, block length 2048.

Error codes used: 0x10 ILLEGAL_MODE (unknown MODE SELECT page), 0x15 DISC_REMOVED (no image mounted, or a TOC
request for a track that does not exist), 0x17 ILLEGAL_REQUEST (unknown opcode).

"No disc" below means: status |= CHECK_ERROR, DISC_RDY cleared, error = 0x15, no data bytes.

## Standard drive commands

| Op | Name | Arguments | Reply data | Notes |
|---|---|---|---|---|
| 02 | SPIN_UP | - | - | Disc present: status \|= SPINNING \| DISC_RDY. Else no disc |
| 03 | SPIN_DOWN | - | - | Disc present: clears SPINNING, sets DISC_RDY. Else CHECK_ERROR \| DISC_RDY, error 0x15. Not in SataTo3DO |
| 06 | EJECT | - | - | status &= 0x0d, then DISC_RDY: clears TRAY_IN, DISC_PRESENT, SPINNING, DOUBLE_SPEED. The image stays mounted |
| 07 | INJECT | - | - | Disc present: status \|= 0xc1. Else status \|= TRAY_IN |
| 08 | ABORT | - | 30 zero bytes | Pulses GPIO22 (FPGA), clears DISC_RDY |
| 09 | MODE_SELECT | 1: page; 2-5: page data | - | Page 0: density = b2, block length = b3-b4, flags = b5. Page 1: error mode b2, count b3. Page 2: stop time b2. Page 3: speed b2 (bit 7 = double speed), pitch b3-b4. Page 4: chunk b2. Other pages: CHECK_ERROR, error 0x10 |
| 0B | FLUSH | - | 30 zero bytes | Sets DISC_RDY |
| 10 | READ_DATA | 1-3: start M S F; 5-6: sector count | (data via FIFO) | See below |
| 80 | DATA_PATH_CHECK | - | `AA 55` | |
| 82 | READ_ERROR | - | error code repeated 8 times | If any of bytes 1-6 is 0x83, answered as READ_ID instead (echo changed to 0x83, log "Caught dipir reset") |
| 83 | READ_ID | - | `00 10 00 01 00 00 00 00 00 00` | Fixed drive identification |
| 85 | READ_CAPACITY | - | `00 M S F` | Lead-out address. No disc otherwise |
| 87 | READ_SUB_Q | - | `ctrl/adr track index 00 M S F M S F` | ctrl/adr = 0x12, index = 1; both addresses = the last sector read (relative = absolute). Track number: see quirks |
| 8B | READ_DISC_INFO | - | `type first last M S F` | Disc type 0x00, or 0x20 for a CUE whose last `TRACK` line is MODE2; lead-out M S F. Also switches the FPGA into or out of audio mode for the mounted image |
| 8C | READ_TOC | 2: track number | `00 ctrl/adr track 00 M S F 00` | Track 1 to last track only; track 0 or past the end is reported as "no disc". ctrl/adr 0x04 data, 0x12 audio |
| 8D | READ_SESSION | - | 6 zero bytes | Single-session disc |
| 8E | (read device-ROM driver) | - | - | Status only. In Portfolio's expansion-bus driver, 8E downloads a driver from the device's ROM; the console asks for it only when READ_ID announces one, which piode2's reply does not |
| C2 | GET_DESC | - | - | Status only. Fixel's protocol note: "description", format not settled, the menu does not read it |

### READ_DATA (0x10)

For each sector from the start address, up to the count (byte 4 is ignored):

1. read the sector from the mounted image into the sector buffer (see [storage.md](storage.md));
2. wait for GPIO20 (FIFO ready). After 100 ms (110-120 ms in practice: 10 ms ticks, `> 100`) the firmware logs
   `RD Timeout`, pulses GPIO22 and sends anyway. With control byte 2, GPIO20 is also high while data is still
   queued, so this wait does not hold the firmware back then (FPGA analysis [sim], see firmware.md "What the FPGA
   does");
3. pick what to send from the current block length:
   - 2048: the sector itself, or bytes 16-2063 of a raw 2352-byte sector (sync and header skipped);
   - 2352: the full raw sector (a 2048-byte ISO sector logs `blah?` and sends 2352 bytes from the buffer anyway);
4. add 1 byte if flags bit 7 is set and 0x60 (96) bytes if flags bit 6 is set. These come from whatever follows the
   sector in the buffer; the firmware does not generate error or subcode data;
5. send it to the FPGA (SPI port 0x05) and step M S F (75 frames per second, 60 seconds per minute).

If a sector cannot be read (past the end of the image, or no media) the command stops with CHECK_ERROR and DISC_RDY
cleared; the error code is not set. The status reply is sent after the last sector.

Before reading, the FPGA control byte is set to 2 if the mounted image's last track is an audio track,
and back to 0 otherwise. Control 2 makes the FPGA offer data to the 3DO at the 1x CD rate (75 Hz) [sim; 75 Hz with the
board's 12 MHz oscillator; "1x CD rate" as the purpose is an inference].

## ODE extension commands

These are not part of the 3DO drive protocol. Only Fixel's menu program (`boot.iso`) uses them, to browse the
drives, queue games, read and write files and start updates.

| Op | Name | Arguments | Reply data | Notes |
|---|---|---|---|---|
| 93 | EXT_ID | - | `devs F Z 1 O D E 1 0 presses` | See below |
| C0 | CHANGE_TOC | 1-4: entry id | - | Enter a directory, see "Directory browsing" |
| C1 | GET_TOC | 1-4: entry index; 5-6: byte offset | 16 bytes | One directory entry, 16 bytes at a time |
| C3 | CLEAR_PLAYLIST | - | - | Empties the play queue |
| C4 | ADD_PLAYLIST | 1-4: entry index | `found added` | Opens the image named by the entry and adds it to the queue (5 slots) |
| C5 | LAUNCH_PLAYLIST | - | - | Mounts the next queued image (or `boot.iso` if the queue is empty) and signals a media change. Unlike the button, it does not reset the drive state |
| D1 | GET_TOC_LIST | 1-4: first entry index; 5-6: entry count | (2 KB via FIFO) | Many directory entries in one data block |
| E0 | CREATE_FILE | 2-3: name length | `ok` | Name taken from the file buffer; created (truncating) for writing, relative to the current directory |
| E1 | OPEN_FILE | 1: 0 = by name, 1 = by entry; 2-3: name length, or 2-5: entry index; 6: non-zero = write | `ok` | Opens `<current path>/<name>`. Write mode creates or truncates |
| E2 | SEEK_FILE | 1-4: byte offset | - | |
| E3 | READ_FILE | 1-2: length (max 2048) | `n_hi n_lo` | Reads into the file buffer; fetch it with E7 |
| E4 | WRITE_FILE | 1-2: length (max 2048) | `n_hi n_lo` | Writes from the file buffer (filled with E6) |
| E5 | CLOSE_FILE | - | - | Syncs and closes |
| E6 | WRITE_BUFFER | 1-2: word index; 3-6: four bytes | - | Stores 4 bytes in the file buffer at index × 4 |
| E7 | READ_BUFFER | - | (2 KB via FIFO) | Sends the whole file buffer |
| F0 | UPDATE_ODE | - | `1` staged / `0` no file | Stages a firmware update, see [update.md](update.md) |

Only one file can be open at a time; opening or creating another closes the first. The menu uses the file commands
for its save-data (`.nvm`) handling; the details are on the menu side.

### EXT_ID (0x93)

| Reply byte | Meaning |
|---|---|
| 1 | Low nibble: mounted drives (bit 0 microSD, bit 1 USB). High nibble: where the mounted `boot.iso` came from (1 microSD, 2 USB, 4 built-in flash image). When `boot.iso` is mounted by a double click, or by a single click or C5 with an empty queue, these two codes are swapped (see quirks) |
| 2-7 | `FZ1ODE`: fixed, the same on every board |
| 8-9 | Firmware version 1, 0 |
| 10 | Number of button presses counted last time (the menu prints `v %d.%d.%d` from bytes 8-10) |

### Directory browsing (C0, C1, D1)

The firmware keeps one current directory and lists it in on-disk order (no sorting). Entries are numbered from 1;
index 0 is always `..`. Hidden and system files, names starting with `.` or `_`, `System Volume Information`, and
files whose 3-letter extension is not `iso`, `cue`, `nvm` or `ode` are skipped. Files without a 3-letter extension
are shown.

When both drives are mounted, the top level is a device list: entry 0 = `/sd` (id 1) and entry 1 = `/usb` (id 2).
With one drive, the top level is that drive's root.

C0 (CHANGE_TOC) takes an id:
- 0 with both drives mounted: go to the device list;
- 1 or 2 at the device list: enter `/sd` or `/usb`;
- 0xFFFFFFFF: go up one level (back to the device list from a drive root when both are mounted);
- n: enter entry n if it is a directory, otherwise do nothing.

Each entry is encoded as (big-endian):

```
u32 flags      1 = file, 2 = directory, file | 8 = .nvm, file | 0x10 = .ode, 0xFFFFFFFF = end of list
u32 toc_id     the index to pass back to C0/C4/E1 (0xFFFFFFFF for "..")
u32 name_len   length including the terminating zero
char name[]    zero-terminated
```

C1 builds one entry at offset 0 of a 2 KB buffer (filled with 0xFF) when called with offset 0, and returns 16
bytes from the given offset; the menu calls it repeatedly with offsets 0, 16, 32... D1 packs consecutive entries
into the 2 KB buffer (names cut to 127 characters) until the count is reached, the list ends (an end entry with
flags 0xFFFFFFFF is written as 8 bytes) or the buffer is full, and sends it through the data FIFO.

### Play queue (C3, C4, C5)

The queue has 5 slots. C4 opens an image by entry index from the current directory (see [storage.md](storage.md)
for the loaders) and copies its description into the next free slot. Reply byte 1 says whether the entry was
found, byte 2 whether it was opened and queued. C5 mounts the next slot in round-robin order. A single press of
the button does the same as C5, and a double press clears the queue and returns to `boot.iso`. The menu's A/B/P
controls build the queue from these commands.

## Quirks kept from the original

The reconstruction keeps these behaviours on purpose, because the stock firmware has them:

- READ_SUB_Q's track number comes from a loop that steps the wrong way, so in practice only the last track is
  compared against the address.
- Once the FPGA has been put in audio mode, `cdda_mode` never returns to 0, so later switches to data mode
  write control byte 0 again on every READ_DATA. The other side of this: a GPIO22 pulse (ABORT, read timeout)
  clears the FPGA's control byte [sim], but `cdda_mode` stays 1, so control 2 is not written again until the drive
  state is reset [inference].
- E1's argument layout (byte 1 = 0 by name, 1 by entry index) differs from an early protocol note by Fixel; the
  firmware is authoritative.
- E0 reads its name length from bytes 2-3 as `b2 << 16 | b3`.
- Remounting `boot.iso` from the button or C5 (double click, or an empty queue) reports microSD as 2 and USB as 1 in EXT_ID's high nibble, the reverse of
  the normal mount path.
- The `System Volume Information` filter compares the name of the last entry looked up, not the entry being
  tested; it still works when the two are the same.
