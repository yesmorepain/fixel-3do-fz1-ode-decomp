# Drives, images and sector reads

How the firmware finds the menu and games and turns 3DO sector requests into file reads. Source:
`source/src/ode.c` (mounting, menu listing, sector reads), `image.c` (image loaders), `mmc_spi.c` (microSD),
`usb_msc.c` (USB), `diskio.c` (FatFs glue). Owner-facing advice drawn from this (which drive, which format, FAT32
or exFAT) is in the top-level `README.md`.

## File system

FatFs R0.14b, byte-identical to the original build, configured with exFAT, long file names (UTF-8), code page
437, 64-bit LBA, relative paths, `f_gets` string functions, and no real-time clock (files get the date 2022-09-01).
Fast seek is off (see the README for what that means for seek times). Two volumes:

| Volume | FatFs drive | Back end |
|---|---|---|
| `/sd` | 0 | microSD, `mmc_spi.c` |
| `/usb` | 1 | USB mass storage, `usb_msc.c` |

### microSD

ChaN's generic MMC/SD-over-SPI driver on SPI0, chip select GPIO5. Initialisation runs at 400 kHz and must finish
within 1 s; reads then run at 20 MHz with no slower fallback. A data token must arrive within 200 ms or the read
fails (no retry). The card is mounted when GPIO19 has read low for 40 ms in a row and unmounted when it has read
high for 40 ms.

The reconstruction found one real difference while checking this driver: `send_cmd` returns a signed char in the
original, so a 0xFF response (no card answer) counts as -1. This matters for which cards initialise.

### USB

TinyUSB 0.12 host stack on core 1, mass-storage class only, one device, no hub support (the bootloader's copy has
hub support; the firmware's does not). Fixel modified TinyUSB's RP2040 host driver so bulk endpoints share the one
hardware "EPX" endpoint more carefully; the reconstruction reproduces those changes. Core 0 reads the drive one
512-byte block per request through the inter-core FIFO (see [firmware.md](firmware.md)).

## Mounting and `boot.iso`

`ode_mount_media` runs on every main-loop pass:

- Every 200 ms it checks the USB drive. A newly present drive is mounted at `/usb`; a removed one is unmounted.
- On each pass it checks the microSD card detect and mounts or unmounts `/sd` the same way.
- When a drive mounts and nothing is mounted as a disc yet, the firmware changes to that drive's root and opens
  `boot.iso` there. If it opens, it becomes the current disc: a single 2048-byte data track starting at 00:02:00,
  lead-out computed from the file size. A USB mount also signals a media change to the 3DO; a microSD mount does
  not (the card normally mounts before the 3DO asks).
- Removing a drive closes the current disc.

`boot.iso` is served as-is: the firmware does not check its contents. In practice the microSD card mounts first at
power-on, so its `boot.iso` wins; the USB drive's is used when no card is inserted.

The build can also carry a disc image linked into flash (`ode_flash_image` in `bitstream.S`). If it is larger than
1000 bytes it is mounted at boot and a drive mounting does not replace it; it stays until a drive is removed
or the button or C5 mounts something else. In the official firmware it is empty.

### What is the "current disc"

| Source | Set by | Reads from |
|---|---|---|
| `boot.iso` | A drive mounting, double press, empty queue | The open `boot.iso` file |
| Queued image | C5 or a single button press | The image's own file handle |
| Built-in flash image | Boot, if present | Flash |

## Image loaders

Games are opened by ADD_PLAYLIST (C4), which calls `image_open` with the file name from the current directory.
The loader is chosen by the last three characters of the name, case-insensitive, looked up in the string
`ISONRGCCDCUE`:

| Extension | Loader | Result |
|---|---|---|
| `.iso` | `image_open_iso` | Supported |
| `.cue` | `image_open_cue` | Supported (one `.bin` file) |
| `.nrg`, `.ccd` | stubs | Recognised, always fail |
| anything else | none | Fails |

`.nrg` and `.ccd` files are not even shown by the menu listing, which only passes `iso`, `cue`, `nvm` and `ode`
(see [commands.md](commands.md)).

### ISO

- 2048-byte sectors, one data track (ctrl/adr 0x04) at 00:02:00, lead-out = file size / 2048 + 150 frames.
- Rejected unless sector 0 starts with the 3DO (Opera) volume header `01 5A 5A 5A 5A 5A 01`. A PC or other
  console ISO cannot be queued.

### CUE/BIN

A deliberately small parser (`image_open_cue`), reading the `.cue` line by line:

- The `.cue` must be at most 2,000 bytes.
- `FILE`: the name may be quoted or not. The file is opened relative to the current directory. If that fails, the
  `.cue`'s own name with the referenced file's extension is tried (so `game.cue` can find `game.bin` even if the
  sheet names something else). Each `FILE` line replaces the previous one, which is why multi-file cue sheets do
  not work: all tracks end up read from the last file.
- `TRACK nn MODE1/2352` or `MODE2/2352`: a data track (ctrl/adr 0x04). The first track with a mode sets the sector
  size from the number after the slash, and the lead-out from the `.bin` size. MODE2 sets the disc type to 0x20.
- `TRACK nn AUDIO` (or `CDDA`): an audio track (ctrl/adr 0x12), 2352-byte sectors.
- `INDEX 01 mm:ss:ff`: the track's start in the TOC. A first track at 00:00:00 is moved to 00:02:00 (the
  2-second pregap). Any other index number ends parsing (checked against the original binary). So an
  `INDEX 00` pregap line, common before audio tracks in some dumps, leaves that track without a start address and
  drops every later track. How this affects particular games has not been tested; cue sheets with only
  `INDEX 01` lines avoid it.
- Anything unexpected ends parsing; what was read so far is kept. Up to 100 tracks. The exception is a `FILE`
  line with unbalanced quotes or a file that cannot be opened: then the whole image fails.
- The 3DO header check runs and is logged, but its result is ignored for CUE images.

The image's mode is that of the last `TRACK` line (1 data, 2 audio, 3 mode 2). It decides the FPGA control byte
for READ_DATA: 2 when the last track is audio, otherwise 0. So for a game with audio tracks the FPGA runs in its
"audio" setting for data reads too (behaviour as in the original). In the FPGA, control 2 paces data to the 1x CD rate (75 Hz) for every read
[sim; 75 Hz from the 12 MHz oscillator; the 1x purpose is an inference], see [firmware.md](firmware.md) "What the FPGA does".

### TOC as stored

Each opened image keeps a small TOC: disc type, first and last track, lead-out M S F, and an 8-byte record per
track (ctrl/adr, track number, start M S F). READ_DISC_INFO, READ_TOC and READ_CAPACITY report from it.

## Sector reads

READ_DATA asks for an address in M S F. The firmware converts it to a sector number
(`lba = m*4500 + s*75 + f - 150`), seeks to `lba × sector size` in the image file, and reads one sector (2048 or
2352 bytes) into the sector buffer. There is no read-ahead or cache: every sector is one seek and one read through
FatFs. A read past the end of the file fails the command. What is then sent to the 3DO (header stripped or raw) is
described in [commands.md](commands.md).

The last address read is also what READ_SUB_Q reports as the current position.

## The play queue

Five image slots. C4 (or the menu's queue controls) copies an opened image description into a free slot; C5 and
a single button press mount the next filled slot, round-robin (the button press also resets the drive state; C5 does not); a double press clears
the queue and goes back to `boot.iso`. When the queue is empty C5 mounts `boot.iso`. All queued images keep their
files open.

## Menu file operations

The menu reads and writes files with the E0-E7 commands ([commands.md](commands.md)): open by name or by directory
entry, seek, read or write up to 2 KB at a time through a 2 KB buffer. These go through the same FatFs volumes,
relative to the current directory the menu has browsed to. Writes are synced on close.
