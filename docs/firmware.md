# How the firmware works

An overview of `piode2` v0.1 (firmware "rev 1.0", built Aug 20 2022), the firmware of Fixel's internal ODE for the
Panasonic 3DO FZ-1, hardware Rev B. File and function names refer to the reconstructed source in `source/src/`.
Names are ours; the original symbols are not in the binary.

The other documents:

| Document | Contents |
|---|---|
| [commands.md](commands.md) | The 3DO drive commands and ODE extension commands, as the firmware answers them |
| [storage.md](storage.md) | microSD and USB drives, `boot.iso`, disc image loaders, the menu's directory listing, sector reads |
| [update.md](update.md) | Firmware update, the bootloader, recovery, flash backup |
| [source.md](source.md) | Source layout, build, how the reconstruction was matched and verified, safe editing |

Practical advice for owners (microSD vs USB, ISO vs BIN/CUE, version numbers in the menu) is in the top-level
`README.md` and is not repeated here.

## Hardware

```
              3DO CD bus (30-pin ribbon)
                        |
                 [bus transceivers]
                        |
    +-------------------+-------------------+
    |  Lattice iCE5LP4K FPGA                |   3DO bus timing, command/status/data FIFOs
    +-------------------+-------------------+
          SPI1 (CS GPIO9) | GPIO20/21/22, CDONE/CRESET
    +-------------------+-------------------+
    |  RP2040 (2x Cortex-M0+)               |   commands, disc images, file system, USB host
    +---+------------+-------------+--------+
        | SPI0       | USB host    | UART0 (debug, 3 Mbaud)
    [microSD]    [USB-A socket]   [16 MB QSPI flash: bootloader + firmware]
```

The RP2040 never touches the 3DO bus. The FPGA handles the bus signals and timing and buffers commands, status
replies and sector data. The RP2040 exchanges packets with it over SPI and decides what to answer. Anything about
bus timing is therefore in the FPGA design. A separate project, [fixel-3do-fz1-ode-fpga-decomp](https://github.com/yesmorepain/fixel-3do-fz1-ode-fpga-decomp), decodes the
official FPGA bitstream, simulates it and reconstructs it as clean HDL (nothing tested on hardware). It explains much of what the
firmware's FPGA accesses do; its results are marked here with labels, see "What the FPGA does" below.

### Pins

| GPIO | Use |
|---|---|
| 2, 3, 4 | SPI0 SCK, TX, RX (microSD; pull-up on RX) |
| 5 | microSD chip select |
| 8, 10, 11 | SPI1 RX, SCK, TX (FPGA) |
| 9 | FPGA chip select |
| 13 | FPGA CDONE (configuration done) |
| 14 | FPGA CRESET_B |
| 16, 17 | UART0 TX, RX (debug log, 3,000,000 baud) |
| 19 | Sampled every 10 ms; low means "microSD present". Used as card detect (name inferred from use) |
| 20 | From FPGA: high = data FIFO empty, can take a sector. Same signal as the 3DO's CDDTEN-, so with control bit 1 it is also high while data is still queued (see below) |
| 21 | From FPGA: rising edge = a command packet is waiting (high after the 7th command byte until the 0x01 read) |
| 22 | To FPGA: 10 µs pulse on abort, read timeout, and after configuration. Resets the FPGA's buffers, command byte counter and control byte [sim]; the pulse after configuration is required [sim] |
| 24 | Set as output by the SD driver (possibly card power; unconfirmed) |
| 25 | Activity LED (lit for 100 ms after each access) |
| 26, 27 | I2C1 at 400 kHz, initialised but never used |
| 28 | The ODE's button, low = pressed |

## Boot sequence

1. **Mask ROM and boot2.** The RP2040 boot ROM runs the 256-byte `boot2_w25q080` stub at the start of flash, which
   sets up execute-in-place for the Winbond flash.
2. **Bootloader** ("odeboot", Bootstrap v1.1, flash 0x10000000-0x1000ffff). It runs from RAM, decides from the
   watchdog scratch registers whether to start the firmware or install an update, checks the firmware's vector
   table and jumps to it with a 500 ms watchdog running. Details in [update.md](update.md).
3. **Firmware `main()`** (`source/src/main.c`):
   - writes the "running" marker into watchdog scratch 0-2 and re-arms the watchdog at 3 s (this disarms any
     pending update request and tells the bootloader the start succeeded);
   - starts the UART log (`ODE1 Entry`, `version 1.0`);
   - launches core 1 (USB host);
   - sets up GPIOs, SPI0 (400 kHz) and SPI1, and a 10 ms repeating timer;
   - configures the FPGA (`fpga_init`, below);
   - clears the drive state (`cd_state_init`) and enables the GPIO21 interrupt;
   - registers the button actions and enters the main loop.

## Cores and timing

| Context | Runs | Code |
|---|---|---|
| Core 0 main loop | Button events, command dispatch, mounting media, FPGA control pulses, watchdog | `main()` |
| Core 0 GPIO21 IRQ | Sets `g_cmd_pending`; nothing else | `cd_cmd_irq_cb` |
| Core 0 10 ms timer | `g_ticks += 10`, media-present check, button sampling, LED timeout, card-detect history | `timer_10ms_cb` |
| Core 1 | TinyUSB host task; serves USB disk requests from core 0 | `core1_entry`, `usb_msc.c` |

All file system work (FatFs) happens on core 0. When FatFs reads the USB drive, core 0 posts a request code
(1 status, 2 read, 3 write, 4 ioctl) through the SIO FIFO with its arguments in a shared block, and core 1 answers
after the USB transfer. One request is in flight at a time, one 512-byte block per request.

Commands are not handled in the interrupt. The interrupt only sets a flag, and the main loop calls
`cd_cmd_dispatch` on its next pass. A command that reads data (READ_DATA) keeps the main loop busy until all its
sectors are sent, so mounting, button handling and the watchdog wait for it.

### Watchdog

Each pass of the main loop sets bit 1 of `g_main_flags`; each pass of the core 1 loop sets bit 0. When both are set,
the main loop feeds the watchdog (3 s timeout) and clears the flags. So a hang on either core resets the board,
and the bootloader then starts the firmware again. While an update is staged the main loop stops feeding, so the
watchdog resets into the bootloader (see [update.md](update.md)).

If CDONE goes low (the FPGA lost its configuration), the main loop prints `WTF???` and stops, and the watchdog
resets the board.

## The FPGA

### Configuration

`fpga_init` (`source/src/fpga.c`) loads the iCE40 in SPI slave mode on every boot: SPI1 at 2.4 MHz, CRESET_B low
for 1 ms with CS low, release, then stream the 71,338-byte bitstream (embedded in the firmware image, built with
iCEcube2 2020.12 on Aug 19 2022), then extra clocks. If CDONE is high it raises SPI1 to 30 MHz (the actual rate
is whatever the RP2040's SPI divider gives) and pulses GPIO22. The UART log shows `FPGA Done = 1`.

### SPI packet port

After configuration the same SPI1 link carries short packets. The first byte selects the port:

| First byte | Direction | Payload | Used by |
|---|---|---|---|
| 0x01 | read | 10 bytes back; bytes 2-8 are the 7-byte 3DO command | `cd_recv_command` |
| 0x02 | write | reply bytes (at most 64): opcode echo, data, status | `cd_send_reply` |
| 0x03 | read | 3 bytes back; byte 2 is an FPGA status byte (bit 5 = data FIFO full) | `fpga_read_status` |
| 0x04 | write | 1 control byte | `fpga_write_ctrl` |
| 0x05 | write | sector data, up to 2048 bytes per packet | `fpga_send_data` |
| 0x00 | write | single byte, sent after 0x01 and 0x05 packets (meant as an end marker? It has no effect in the FPGA [sim]) | |

A sector larger than 2048 bytes (raw 2352-byte sectors, plus optional extra bytes) is sent as two 0x05 packets:
the first 2048 bytes, then a wait until status bit 5 clears plus 320 µs, then the rest.

Control byte values seen: 0 = normal, 2 = written before READ_DATA when the mounted image's last track is an audio
track (meaning inferred: CD audio mode; see [storage.md](storage.md)), and 1
held for 100 ms after a disc change or reset request (meaning inferred: signals a media change or drive reset to
the 3DO side). These meanings first came from when the firmware writes them; the FPGA analysis confirms bit 0
(CDMDCHG) and shows that bit 1 is a 75 Hz pacing gate, not an audio decoder (see below).

### Command flow

```
3DO writes 7 command bytes -> FPGA -> GPIO21 rising edge -> IRQ sets g_cmd_pending
main loop: cd_cmd_poll -> cd_cmd_dispatch
    cd_recv_command (SPI 0x01)          7-byte command into cd_state.cmd
    reply = [opcode]; handler appends data; reply += status
    data commands: wait GPIO20 (100 ms timeout), fpga_send_data (SPI 0x05) per sector
    cd_send_reply (SPI 0x02)            FPGA returns the status bytes to the 3DO
```

The handlers and the state they share are described in [commands.md](commands.md).

### What the FPGA does

> **Not tested on hardware.** These FPGA findings come from decoding and simulating the official bitstream only;
> none of them has been measured or tried on a real ODE or 3DO.

From the FPGA bitstream analysis (separate project). Labels:
**[sim+doc]** shown by simulating the bitstream and agreeing with an independent document (3DO technical guide,
FZ-1 service manual, or the open SataTo3DO drive emulator); **[sim]** shown by simulation or the netlist only;
**[inference]** derived from facts, not shown directly; **[guess]** plausible, unverified.

| Item | Finding | Label |
|---|---|---|
| Buffers | Command 7 bytes, reply 64 bytes, sector data 2048 bytes; all are FIFOs that drop (never overwrite) bytes that do not fit | [sim] |
| 0x01 layout | status byte, one stale byte, the 7 command bytes, 00; the end of the packet empties the command FIFO | [sim] |
| 0x03 | every returned byte is the status byte: bit 7 data FIFO empty, 6 reply FIFO empty, 5 data FIFO full (2048 unread), 4 = 0, 3-0 control byte echo | [sim] |
| GPIO21 | rises on the 7th command byte the 3DO writes (CDHWR-), falls during the 0x01 read; further command bytes are ignored while it is high | [sim]; 7-byte commands agree with SataTo3DO [sim+doc] |
| Opcode 0x08 | GPIO21 rises after the first byte only, as a ~14 ns pulse; the rest of the ABORT is counted as a new command. The ABORT handler's GPIO22 pulse puts the count right again | [sim]; that the RP2040 (125 MHz) always catches the pulse is a [guess] |
| Control bit 0 | drives CDMDCHG low (media changed) | [sim+doc] (SataTo3DO also holds it 100 ms) |
| Control bit 1 | CDDTEN- (data ready to the 3DO) may go low only in a 170 µs window every 160,001 oscillator cycles; 1/75 s with the board's 12 MHz oscillator, i.e. 1x CD real-time pacing | timer [sim]; 12 MHz from the oscillator's marking; "1x pacing" [inference] |
| Control bits 2-3 | stored and echoed, no other effect | [sim] |
| GPIO20 | the same signal as CDDTEN-: high when the data FIFO is empty or a 0x05 packet is in progress, and, with control bit 1, also outside the window even with unread data. So with control 2 the GPIO20 wait in READ_DATA does not wait | [sim]; effect on games with audio tracks unknown [guess: data can be dropped if the 3DO reads slower than the next sector arrives] |
| GPIO22 | resets all three FIFOs, the command byte counter and the control byte. Without the pulse after configuration GPIO21 never rises | [sim] |
| 0x00 marker, `0e 03` after configuration | no effect in the FPGA | [sim] |
| Timeouts | the FPGA has none; the 100 ms READ_DATA timeout is the firmware's own | [sim] |
| Timing races | two places in the FPGA design depend on routing delays: bit 4 of the first byte of a 0x01 packet (ignored by the firmware), and a 3DO command byte that ends exactly as GPIO21 falls, which can be stored without being counted and shift the next command | [sim]; how often on hardware: unknown |
| SPI1 rate | 20.83 MHz (125 MHz / 6), not 30 MHz; the FPGA needs a small gap between bytes, which the RP2040's SPI block leaves | rate: calculation from the SDK's default clocks (125 MHz from a 12 MHz crystal; the RP2040's crystal Y2 is marked "120" = 12.0 MHz); gap: RP2040 datasheet 4.4.3.10 (in SPI mode 0 the clock pauses between back-to-back bytes; the FPGA's chip select is a plain GPIO) |

Consequences for the firmware (analysis, [inference]):

- The firmware reads 0x01 only after a GPIO21 interrupt, which is what the FPGA's command counter needs.
- After an ABORT or a read timeout in audio mode the FPGA's control byte is 0 again, but `cdda_mode` stays 1, so
  the firmware does not write 2 again until the drive state is reset.
- A single or double click calls `cd_state_reset`, which clears `g_cmd_pending` without a GPIO22 pulse. If a
  command had just arrived, it is never read, GPIO21 stays high and the FPGA ignores all later commands until the
  next GPIO22 pulse or reboot. How often this happens: unknown [guess: rarely].
- A GPIO22 pulse (abort or read timeout) while the 3DO is in the middle of writing a command leaves the FPGA's
  command count out of step until the next pulse [guess: rare].

## The button

The ODE's button (GPIO28) is read by a small debounce library (`buttons.c`), sampled every 10 ms with 3 samples of
debounce:

| Action | Effect |
|---|---|
| Single click | Mount the next game in the play queue (or `boot.iso` if the queue is empty), reset the drive state, signal a media change (control byte 1 for 100 ms) |
| Double click (second press within 1.5 s) | Clear the play queue, mount `boot.iso`, reset, signal a media change: back to the menu |
| Long press (3 s) | Only logs `long press` |
| Every press | Counted. 1.5 s after the last press the count is stored and reported in the EXT_ID reply (the third digit of the version the menu shows) |

On an installed ODE, pressing the FZ-1's Eject button triggers these actions: a single press resets the game, a
double press returns to the menu (observed behaviour; the exact wiring from the Eject button to GPIO28 is not
traced).

## Memory map

### Flash (16 MB, XIP at 0x10000000)

| Range | Contents |
|---|---|
| 0x10000000-0x1000ffff | Bootloader (64 KB, never rewritten by updates) |
| 0x10010000-0x100100ff | Firmware's own boot2 copy (unused when the bootloader is present; CRC-protected, never modify) |
| 0x10010100 | Firmware vector table (initial SP, reset vector): the only thing the bootloader checks |
| 0x10010100-0x10032eef | `.text` and `.rodata`, including the FPGA bitstream at 0x1001f945 |
| 0x10032ef0-0x1003390b | `.data` load image (2,588 bytes) |
| 0x1003390c- | Not used by the firmware. In one dumped board everything above the image is erased, apart from the rest of the last 4 KB sector written by the updater |

`update.ode` is the raw image from 0x10010000 to the end of `.data` (145,676 bytes for rev 1.0). File offset =
address - 0x10010000.

### RAM

| Range | Contents |
|---|---|
| 0x20000000-0x200000bf | RAM vector table |
| 0x200000c0-0x20000adb | `.data` (initialised variables and functions that run from RAM, such as the USB IRQ path) |
| 0x20000ae0-0x200075f7 | `.bss` (drive state `cd_state` at 0x200050cc, image structures, FatFs objects, buffers) |
| 0x20009600-0x2000b600 | Core 1 stack (8 KB, filled with 0xcc at start) |
| up to 0x2000e600 | Core 0 stack (12 KB, initial SP 0x2000e600) |

Notable buffers: one 2,500-byte sector buffer, a 2 KB "TOC" buffer for the menu's directory listings, a 2 KB file
operation buffer, five image slots for the play queue, and one FatFs object per drive.

## Debug log

UART0 TX (GPIO16) prints at 3,000,000 baud, 8N1: boot messages, FPGA status, mounts, and every command and reply
except READ_DATA (0x10) and READ_SUB_Q (0x87), which would flood it. Example:

```
CMD RX 8b 00 00 00 00 00 00  => STAT TX 8b 00 01 01 1f 2e 05 81
```

(Values illustrative.) No serial header is fitted, and which board pads carry GPIO16 has not been confirmed;
reading the log needs soldering and a serial adapter that handles 3 Mbaud.
