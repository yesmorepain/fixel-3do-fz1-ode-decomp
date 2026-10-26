# The reconstructed source

How `source/` is laid out, how it maps onto the original `update.ode`, how it was checked against the original, and
how to change it (or the original image) without breaking things.

## Layout and object order

`source/` is a Pico SDK 1.3.0 CMake project. The application files are linked in the order the original binary
shows (functions of one file sit together and in source order), so each file covers one address range of the
original. File names are ours; the original names are not in the binary.

| File | Original range | Contents |
|---|---|---|
| `src/main.c` | 0x10010310-0x10010920 | Core 1 entry, button actions, `main`, 10 ms timer, board set-up |
| `ff/ff.c`, `ff/ffunicode.c` | 0x10010920-0x10014320 | FatFs R0.14b, original configuration in `ff/ffconf.h` |
| `src/diskio.c` | 0x10014320-0x100143c8 | FatFs drive glue |
| `src/mmc_spi.c` | 0x100143c8-0x10014be8 | microSD over SPI0 (ChaN's generic driver, adapted) |
| `src/usb_msc.c` | 0x10014be8-0x10015004 | USB mass storage, core 0 ↔ core 1 requests |
| `src/fpga.c` | 0x10015004-0x1001539c | FPGA configuration and SPI packet port |
| `src/image.c` | 0x1001539c-0x100159b8 | ISO and CUE loaders |
| `src/cdrom.c` | 0x100159b8-0x10016a4c | Command handlers and dispatcher |
| `src/ode.c` | 0x10016a4c-0x1001797c | Mounting, directory listing, sector reads, play queue, update staging |
| `src/buttons.c` | 0x1001797c-0x10017df4 | Button debounce and events |
| Pico SDK, TinyUSB, newlib, libgcc | after 0x10017df4 | Library code, built from the real libraries |
| `src/bitstream.S` | 0x1001f945 | FPGA bitstream (`.incbin`) and the empty built-in disc image |

Also: `src/piode2.h` (pins, `cd_state_t`, `image_t`, prototypes), `src/tusb_config.h`, `lib/tinyusb/` (TinyUSB
0.12.0 with Fixel's changes to the RP2040 host port reproduced), `memmap_piode2.ld` (app at 0x10010000, original
RAM split and stack sizes).

The FPGA bitstream is Fixel's and is not included; `tools/setup_from_official.py <update.ode>` extracts it from the
official image into `source/src/fpga_bitstream.bin` (and recreates `original/`, the listings and the ELF).

## Build

Toolchain: GNU Arm Embedded 10.3-2021.10 (the one the original was built with), Pico SDK 1.3.0, CMake.

```
cd source && mkdir -p build && cd build
PICO_SDK_PATH=/path/to/pico-sdk-1.3.0 cmake -DCMAKE_BUILD_TYPE=Debug -DPICO_BOARD=pico .. && make -j
# -> build/update.ode
```

The result is 145,680 bytes (original 145,676). `.data` is the same size (2,588 bytes) with equivalent contents,
functions that run from RAM sit at the same RAM addresses, `.bss` is 4 bytes smaller, and the vector table and
boot2 are identical. A different toolchain or SDK version still builds, but the comparison below stops being
meaningful.

## How the reconstruction was made

1. **Identify the toolchain.** The boot2 stub, `binary_info` and assert paths give Pico SDK 1.3.0, board `pico`,
   build type Debug (`-Og`); the code generation matches GCC 10.3-2021.10.
2. **Name the library code.** `tools/build_ref.sh` builds reference objects (SDK, TinyUSB 0.12, FatFs R0.14b with a
   recovered `ffconf.h`, newlib, libgcc) with that toolchain. `tools/match_libs.py` byte-matches them against the
   image, treating relocated fields as wildcards, and propagates names through the relocations of matched
   functions. About 300 functions were named this way (`tools/names_matched.py`).
3. **Name the rest by hand** (`tools/names_manual.py`): from strings, call patterns, peripheral accesses and the
   SataTo3DO reference. Each entry is marked C (confirmed) or L (inferred, a guess).
4. **Write the C.** Each application function was written from the annotated disassembly (`piode2_disasm.s`) and
   the Ghidra output, then compiled and compared, until it matched or the remaining difference was understood.
5. **Check every function** with `tools/compare_src.py` (below), review all remaining differences against the
   disassembly, and finally test on hardware.

`tools/analyze.py original/update.ode <outdir>` regenerates the listing, function table, ELF and symbol files from
the name lists.

## Verification

```
cd source
python3 ../tools/compare_src.py ../piode2.elf ../functions.tsv build/CMakeFiles/piode2.dir [function ...]
```

(needs `pyelftools`; `capstone` adds a similarity score). For each function of the original it finds the rebuilt
one and reports:

- **MATCH**: the bytes are identical apart from relocated fields, and every call goes to the function the original
  calls;
- **DIFF**: with an instruction-shape similarity score and the ordered call lists side by side.

Status: 340+ functions MATCH. FatFs matches completely; TinyUSB's host core and MSC class match, and the RP2040 host
port differs only in assert line numbers. Every remaining DIFF in the application was reviewed against the
disassembly and is compiler-level only: register allocation, block order, or assert line numbers.

Real differences found and fixed during review, as examples of what this catches:

- the SD driver's `send_cmd` returns a signed `char` in the original (a 0xFF answer is -1 and passes `<= 1` checks);
- TinyUSB's enumeration buffer is 512 bytes, not 256;
- four log strings differed in `\r`/`\n`;
- the USB interrupt path runs from RAM (`__not_in_flash`), which also fixed the `.data` size;
- some globals must be non-static so they stay in `.data` at the original address.

Hardware: the rebuilt `update.ode` was installed through the ODE's own "Update ODE" on a Rev B board and behaved like
stock: menu, microSD and USB browsing, ISO and CUE/BIN (including subfolders), CD audio, the Eject button actions
and the play queue. Not tested: a long cold power-off, BOOTSEL recovery.

## Checked against outside documents

The rebuild proves the code is the original's; it cannot prove that the names and explanations in these docs are
right. Those were checked against independent sources (2026-10-26). Sources: **SDK** = 3DO Portfolio 2.5 headers
(`cdrom.h`, `io.h`, `device.h`); **PF** = Portfolio OS source `xbusdevice.c` (the console's expansion-bus driver);
**S3** = FCare's SataTo3DO (`docs/satato3do/3DO.c`); **FN** = Fixel's ODE protocol note (in the SataTo3DO files);
**QS** = Fixel's FZ1 ODE quick-start guide (written for firmware 0.20 and menu r3); **3D** = the 3dodev.com Fixel
ODE page; **DS** = RP2040 datasheet; **PS** = Pico SDK 1.3.0 source.

| Finding | Document evidence | Status |
|---|---|---|
| Commands are 7 bytes | PF sends 7 bytes per command (`SquirtOutCmd`) | match |
| Opcode numbers and names (02-8D, 93-F0) | S3 opcode list; FN for the ODE commands | match; 03 SPIN_DOWN exists only in piode2 |
| Status bits 0x80, 0x40, 0x20, 0x10, 0x02, 0x01 | SDK `CDROM_STATUS_DOOR`, `DISC_IN`, `SPIN_UP`, `ERROR`, `DOUBLE_SPEED`, `READY`; S3 | match (S3 names used here) |
| Error codes 0x10, 0x15, 0x17 | SDK `MEI_CDROM_mode_error`, `disc_out`, `illegal_request` | match |
| MODE SELECT pages 0-4 and their fields | SDK `CDROM_Parameters` (block, error recovery, stop time, speed 0x00/0x80 + pitch, chunk 1-8); Fixel's description quoted in S3 | match |
| Flags bit 7 = +1 byte, bit 6 = +96 bytes | SDK block sizes 2353, 2448, 2449; Fixel's description in S3 | match |
| READ_ID reply `00 10 00 01 00 00 00 00 00 00` | PF `ReadID`: maker (2 bytes), device (2), revision (2), flags (2), driver-table size (2) | match: maker 0x0010, device 1, revision 0, no device ROM driver. S3 differs only in the revision (0x3075) |
| **8E** | PF: 0x8E = read a driver from the device's ROM, only requested when READ_ID's flags announce one (piode2's do not). S3 and FN: GET_DESC is **0xC2** | was a doc error ([commands.md](commands.md) labelled 8E as GET_DESC), fixed 2026-10-26. No effect on behaviour (status only, never sent) |
| READ_DISC_INFO, READ_TOC, READ_SESSION layouts | SDK `CDROM_Disc_Information`, `CDROM_TOC_Entry` (8 bytes), `CDROM_Session_Information` (6 bytes); S3 | match |
| READ_CAPACITY `00 M S F` | SDK `CDROM_MSF` = {rfu, M, S, F}; S3 sends `M S F 00 00` | piode2 matches the SDK layout; S3 differs |
| ctrl/adr 0x04 (data), 0x12 (audio) | SDK `CD_CTL_*`: 0x04 = data track with no Q mode; 0x12 = copy permitted, Q position | consistent; pressed data discs usually report 0x14 [inference] |
| READ_SUB_Q layout | S3: ctrl/adr, track, index, 00, two M S F | match |
| READ_ERROR (8 bytes, code repeated) | S3: 8 bytes, code in byte 3 only | compatible (same length; the code is in byte 3 in both) |
| ABORT and FLUSH return 30 zero bytes | S3: status only | difference; piode2 is the original |
| DATA_PATH_CHECK `AA 55` | S3 (`A5 A5` there without a disc) | match with a disc |
| ODE command formats (93, C0, C1, C3-C5, D1, E0-E7, F0) | FN | match, except: E1 argument order and E0's length bytes (both listed under quirks), EXT_ID byte 10 = press count (FN: patch version), F0 adds a 1/0 byte (the menu reads it), C5 steps round-robin (FN: "first image") |
| EXT_ID boot-device codes 1, 2, 4 | FN: microSD 1, USB 2, flash 4, SATA 8 | match |
| Directory entry, 0xFF fill, names cut to 127, 8-byte end entry | FN (Fixel's own code) | match |
| C2 status only; no E8 | FN: C2 "description", format not settled, menu does not read it; E8 is XPort only | match |
| Scratch registers survive a watchdog reset; boot ROM uses scratch 4-7 | DS 4.7.4, 2.8.1.1 | match; piode2 uses scratch 0-2, no clash |
| boot2: 256 bytes, CRC-checked | DS 2.8.1: 252 bytes + CRC32 | match |
| Watchdog 1 s and 3 s | PS `watchdog_enable` doubles the count for erratum RP2040-E1 (DS) | match: the values are real times |
| SPI1 at 20.83 MHz, mode 0, MSB first | PS clocks (12 MHz crystal -> 125 MHz) and `spi_set_baudrate` (prescale 2, postdiv 3); `spi_init` format; crystal Y2 marked "120" | match (calculation reproduced from the SDK code) |
| A pause between SPI bytes | DS 4.4.3.10: in mode 0, back-to-back words pulse the frame select high between words, so the clock stops. The FPGA chip select (GPIO9) is a plain GPIO | supports the FPGA's need for a gap (was a guess) |
| Storage, formats, controls, queue, Eject presses, update | QS: ISO and CUE/BIN; FAT12/16/32 and exFAT; microSD boots first; 5 queue entries; Eject 1 press next disc, 2 presses `boot.iso`; `update.ode` in the root; ACCESS LED flashes during the update | match; the LED flashing is the bootloader toggling GPIO25 during programming and verify ([update.md](update.md)) |
| Supported formats per 3D | 3D lists `.nrg`, cue + wav music CDs, CD+G, VCD | difference: firmware rev 1.0 has a stub for NRG and reads multi-file cue sheets from the last file only ([storage.md](storage.md)). The page covers both ODE models [inference] |

## Faithfulness rules

The tree reproduces the stock firmware, including its oddities, so it can serve as a reference. Behaviour that
looks like a bug is kept and marked `sic` in a comment. The list of kept quirks is in [commands.md](commands.md);
others in the source include the CUE parser's handling of `INDEX 00` and multiple `FILE` lines
([storage.md](storage.md)) and timer callbacks that, in the original, fall off the end without a return value
(the C returns `true`, which behaves the same).

## Editing the source safely

- Keep each function in its file and in its position if you want `compare_src.py` to stay useful; run it after
  every change to see exactly which functions moved away from the original.
- Things that change the generated code although they look harmless: `static` vs non-static (moves data between
  `.data` and `.bss`), signedness of return types, the order of declarations, and where a function lives (flash or
  RAM).
- Assert messages contain `__FILE__` and line numbers, so adding lines above an assert changes the bytes but not the
  behaviour. The build path also ends up in the assert strings, so two builds in different folders differ there.
- `tools/odepatch.py info` reads opcode lists from the jump table address of the original; on a rebuilt image it
  reports nonsense. That is expected.
- Treat any changed image as untested until it has booted on the hardware, and read [update.md](update.md) first:
  an image that hangs after `main()` starts can only be recovered with BOOTSEL.

## Patching the original image instead

`tools/odepatch.py` changes the official `update.ode` directly, without rebuilding:

- `info <img>`: size, boot2 CRC, free opcodes.
- `apply <img> patches.json <out>`: append compiled code at 0x10033a00, overwrite bytes or words, retarget any `bl`
  call to new code, or install a handler for a free opcode (it writes a 12-byte trampoline,
  `bl handler; ldr r3,=tail; bx r3`, and points the jump-table slot at it, like the original case blocks).
- `selftest <img>`: re-encodes all 1,528 original `bl` instructions and checks that an opcode hook changes only its
  table entry.

`patch_example/` adds a new command (0xD2) in C: a handler linked at 0x10033a00 against `piode2_symbols.ld` (every
firmware function by name), then hooked with `odepatch.py`. Handlers follow the dispatcher's contract
([commands.md](commands.md)): `void handler(void)`, `cd_state.reply` already holds the opcode echo, append bytes, and
the dispatcher adds the status byte and sends the reply. Patch code must not use `.data` or `.bss`: the original
start-up code does not initialise anything past the original image, so use the stack or the firmware's own
buffers. `dump_patch/` is a second, real example (it retargets one `bl` in `main`).

Bus-timing changes cannot be made here: they belong to the FPGA design.
