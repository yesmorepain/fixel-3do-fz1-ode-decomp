# Fixel's 3DO FZ-1 ODE firmware, decompiled and reconstructed

An unofficial decompilation and C source reconstruction of the firmware for **Fixel's internal optical drive emulator
(ODE) for the Panasonic 3DO FZ-1**, hardware **Rev B** (Raspberry Pi RP2040 + Lattice iCE5LP4K FPGA).
Rev A was a 2020 prototype built around an Infineon XMC4700 instead of the RP2040; nothing here applies to it

The target is firmware `update.ode` "rev 1.0" (program `piode2` v0.1, built Aug 20 2022), the latest official FZ-1 ODE
firmware. No source code for it has been published, so this project rebuilds it from the binary.

The FZ-1 ODE has been out of production for a couple of years, and no hardware design, FPGA source or firmware source
was ever released (Fixel's hardware repository exists but is empty, checked 2026-10-26). The boards already in people's hands are all there is, so this project documents what the
firmware and bootloader do, to keep them repairable and understood.

> **Not affiliated with or endorsed by Fixel.** This is independent reverse-engineering work for preservation,
> repair and interoperability. See [Legal](#legal).

## How sure is each statement?

Statements in this README carry a label where it matters:

| Label | Meaning |
|---|---|
| **[hardware]** | Verified on a real Rev B ODE in an FZ-1 |
| **[code]** | Verified in Fixel's original code: read from the firmware, which the rebuild matches. Exactly what the original does, but not every case was tried on hardware |
| **[bootloader code]** | Read from a decompilation of the bootloader dumped from a Rev B board (decoded, not rebuilt) |
| **[doc]** | Taken from a document (datasheet, SDK, Fixel's quick-start guide); see the checks in [docs/source.md](docs/source.md) |
| **[inference]** | Derived from facts, not shown directly |
| **[estimate]** | A number worked out from the code or specifications, not measured |
| **[guess]** | Plausible, not verified |

## What's here

- **Fully annotated firmware analysis.** All 510 functions are named: library code (Pico SDK 1.3.0, TinyUSB, FatFs,
  newlib) was identified by byte-matching against a rebuild with the original toolchain, and the application code
  was named by hand. The annotated disassembly, function map, ELF with symbols and symbol files are regenerated
  locally from the official image (see "Getting the required files"); the Ghidra scripts are included.
- **Buildable C source** (`source/`): a Pico SDK 1.3.0 project that rebuilds the firmware. Each function is
  checked against the original binary: 340+ functions are byte-identical, and every remaining difference has been
  reviewed and is compiler-level only (register allocation, block order, assert line numbers). FatFs is
  byte-identical, Fixel's changes to the TinyUSB RP2040 host driver are reproduced, and the initialised data matches
  the original in size and content. [code]
- **Bootloader analysis** (`bootloader/`): how Fixel's 64 KB bootloader ("odeboot", Bootstrap v1.1) installs
  `update.ode`, what it checks (only a read-back verify, no checksum or signature) and when it recovers by itself.
  Its functions are named too (723 of 739, with how each name was found), and a Ghidra
  decompilation with the names is included. [bootloader code]
- **The 3DO drive protocol, documented in code:** every CD command the firmware handles (spin up, read data, TOC,
  sub-Q, mode select, ...) and the ODE extension commands the menu uses (directory browsing, playlist,
  file I/O, firmware update).
- **The RP2040 ↔ FPGA interface:** FPGA configuration at boot and the SPI packet protocol used to exchange 3DO
  commands, status and sector data.
- **Patching tools** (`tools/odepatch.py`) to add code to the original image, with two examples: a new 3DO
  command (builds; not tried on hardware), and a patch that dumps the whole 16 MB flash (bootloader included) to the
  microSD card or USB drive [hardware].
- **Library matcher and comparer** (`tools/match_libs.py`, `tools/compare_src.py`): reusable for other
  embedded ARM firmware reconstructions.

## Documentation

How the firmware works, written from the reconstructed source:

- [docs/firmware.md](docs/firmware.md): hardware, pins, boot sequence, cores, the FPGA and its SPI packet port, the
  button, memory map, debug log
- [docs/commands.md](docs/commands.md): every 3DO drive command and ODE extension command, with exact replies
- [docs/storage.md](docs/storage.md): microSD and USB, `boot.iso`, the ISO and CUE/BIN loaders, sector reads, the
  play queue
- [docs/update.md](docs/update.md): firmware update, the bootloader, what recovers by itself, flash backup
- [docs/source.md](docs/source.md): source layout, building, how the reconstruction was matched and verified, the
  checks against outside documents, safe editing and patching

## One device, three projects

Fixel's FZ-1 ODE has three programmed parts, and each is covered by its own project. Together they describe
everything Fixel programmed into the device, layer by layer, from the menu on the TV screen down to the timing on
the console's CD-ROM bus.

```
 3DO console                                ODE board (Rev B)
┌──────────────────────┐   CD-ROM bus   ┌──────────────┐   SPI + GPIO   ┌──────────────────┐   microSD / USB
│ Menu disc (boot.iso) │ ─────────────> │ FPGA         │ ─────────────> │ RP2040 firmware  │ ─────────────> disc images
│ LaunchMe, ode driver │ <───────────── │ (gateware)   │ <───────────── │ (update.ode)     │
└──────────────────────┘  7-byte cmds,  └──────────────┘  packets,      └──────────────────┘
      menu project        status, data    FPGA project    handshakes      firmware project
```

| Project | Layer | What it explains | State |
|---|---|---|---|
| **[Menu](https://github.com/yesmorepain/fixel-3do-fz1-ode-menu-decomp)** | Software on the 3DO | What the user sees and does: browsing, the play queue, saves, updates. It reaches the ODE only through 7-byte commands sent via its `ode` driver | Rebuilds byte for byte from reconstructed C; a menu disc with a rebuilt LaunchMe has booted on an FZ-1 |
| **[FPGA](https://github.com/yesmorepain/fixel-3do-fz1-ode-fpga-decomp)** | Gateware between the console and the RP2040 | How bytes cross the 3DO bus: buffers, handshakes, status, 75 Hz pacing, timing | Decoded and documented; a clean HDL version is proved equivalent on a zero-delay model. **Not tested on hardware** |
| **[Firmware](https://github.com/yesmorepain/fixel-3do-fz1-ode-decomp)** | Software on the RP2040 | What each command means: reading disc images, answering the console, update and recovery | Rebuilds from reconstructed C, mostly byte-identical; tested on a Rev B board |

This repository is the **firmware** project.

How they fit together:

- **Menu and firmware** share the ODE command set: the menu sends the commands, the firmware's
  `docs/commands.md` defines them. Every command the menu uses is documented on the firmware side.
- **Firmware and FPGA** share the SPI packet protocol and the GPIO handshake lines. The FPGA analysis explains what
  the firmware's FPGA accesses actually do, and corrected the firmware documentation in places (GPIO20 in CD-audio
  mode, what the GPIO22 reset clears, that the reset after configuration is required).
- **FPGA and console** share the 3DO drive bus. The FPGA's behaviour was checked against the 3DO technical guide,
  the FZ-1 service manual and the open SataTo3DO drive emulator.

What the whole adds up to: every part can be rebuilt from Fixel's official, freely available files, and each
finding is labelled by how well it is proven. That makes it a record for preserving and repairing an
out-of-production device, a reference for anyone building a replacement drive emulator or new ODE firmware, and a
safe starting point for changes.

What is still missing: the hardware design. Fixel's hardware repository is empty, so what is known about the board
comes from the bitstream, the firmware and the part markings (for example the two 12 MHz clocks). The FPGA side
also still needs confirmation on real hardware.

## Status

| Part | State |
|---|---|
| Function naming | Complete (510/510) |
| FatFs (R0.14b) | Byte-identical, original configuration recovered |
| Application C code | Builds; majority byte-identical, all remaining differences reviewed (compiler-level only) |
| TinyUSB RP2040 host port | Fixel's local modifications reproduced (only assert line numbers differ) |
| Bootloader ("odeboot") | Dumped from hardware; boot and update logic decoded; 723/739 functions named |
| FPGA gateware | Decoded, documented and reconstructed as clean HDL in a separate project, [fixel-3do-fz1-ode-fpga-decomp](https://github.com/yesmorepain/fixel-3do-fz1-ode-fpga-decomp) (simulation and formal checks only, **not tested on hardware**); see below |
| Hardware testing of the rebuild | [hardware] Verified on a Rev B board: menu, microSD/USB, ISO and BIN/CUE, CD audio, Eject button, play queue. Use at your own risk. |

## Hardware summary

| Item | Value |
|---|---|
| MCU | RP2040 (rev B2, chip marking RP2-B2), Pico SDK 1.3.0, app linked at 0x10010000 behind a 64 KB bootloader |
| Flash | Winbond W25Q128JVEQ, 16 MB (chip marking) |
| FPGA | Lattice iCE5LP4K-SG48 (bitstream header), loaded over SPI1 at every boot [code] |
| Storage | microSD (SPI0) and USB mass storage (TinyUSB host, on core 1), FatFs with exFAT |
| Images | ISO and CUE/BIN (NRG/CCD recognised, not supported) |
| Debug UART | UART0, 3,000,000 baud, TX = GPIO16 |

## Using the ODE: storage and image formats

Practical notes for owners, taken from how the firmware works. They apply to the stock firmware and the rebuild
alike. Unlabelled behaviour in this section is [code].

### microSD card or USB drive?

The ODE has a microSD slot (full-size SD cards do not fit) and a USB-A port. Both work. The microSD card is the better main drive:

| | microSD card | USB drive |
|---|---|---|
| Speed | SPI bus at 20 MHz [code], roughly 1–2 MB/s [estimate] | USB 1.1 (12 Mbit/s), one 512-byte block per request [code], slower [estimate] |
| Fast enough for games? | Yes [hardware] (a 3DO drive needs about 300 KB/s, the double-speed CD rate [inference]) | Yes [hardware] |
| `boot.iso` (the menu) | Loaded from the microSD card first | Used only when no microSD card is present |
| Automatic firmware recovery | The bootloader re-flashes from `update.ode` in the microSD card root | Never used for recovery |
| Compatibility | Most cards work, but see below [guess] | Some drives may not be recognised [guess] |

**Why some microSD cards work better than others.** The firmware talks to the card in SPI mode with a simple, strict
driver:
- SPI mode is required of every SD/microSD card [doc] but is less tested by makers; some newer high-capacity cards
  (especially A1/A2 "app performance" cards) handle it poorly [guess, from general experience with SPI-mode readers].
- The card must finish starting up within 1 second, or the mount fails and is retried.
- After start-up the bus runs at 20 MHz, with no fallback to a slower speed for marginal cards.
- A sector read that takes longer than 200 ms fails without a retry, which can make a game stutter or freeze on
  slow or worn cards.

**FAT32 or exFAT?** Both work: the firmware's FatFs reads FAT12/16/32 and exFAT, whichever the volume uses. They can
still behave differently on this ODE, for two reasons:

1. **Seeking inside the image.** Every sector the 3DO requests is read by seeking to its position in the image file.
   FatFs is built without its "fast seek" option, so a seek backwards walks the file's cluster chain from the start.
   - On **FAT32** that walk reads the FAT table (one 512-byte sector per 128 clusters). For a seek near the end of a
     650 MB image with 32 KB clusters that is roughly 160 extra sector reads, tens of milliseconds on a microSD card
     and much more over USB. Games seek backwards often (level loads, FMV, music), so this can show up as stutter or
     slow loading.
   - On **exFAT**, a file stored in one contiguous piece is marked as such, and its position is calculated directly
     without reading the FAT.
   - A fragmented exFAT file loses that mark and behaves like FAT32; heavy fragmentation makes FAT32 slower still.
     Larger clusters mean fewer steps (64 KB clusters halve the walk compared with 32 KB).
2. **The card behind the format.** exFAT usually means a 64 GB or larger SDXC card [doc: SD card standard]. Those tend to be newer, often A1/A2
   cards, the kind most affected by the SPI-mode, start-up time, fixed 20 MHz and no-retry limits above. A problem
   that looks like "exFAT is less stable" is often really the card [guess].

The latency figures above are estimates worked out from the code, not measurements on the hardware.

### ISO or BIN/CUE?

| | ISO | BIN/CUE |
|---|---|---|
| Content | One data track (2048-byte sectors) | Data track plus separate CD-audio tracks (raw 2352-byte sectors) |
| Game audio | Plays if it is stored in the data track (single-track games); separate CD-audio tracks are lost [code] | All tracks play [hardware: CD audio tested] |
| File size | Smaller | About 15% larger (2352 / 2048 bytes per sector) |

- Games with separate CD-audio tracks (more than one track on the disc): use **BIN/CUE**.
- Single-track games, including those whose music and sound are stored in the data track: either works; ISO is
  smaller and simpler.

BIN/CUE limits in this firmware:
- **One `.bin` file per game.** A `.cue` that lists several files (one per track, common in Redump-style dumps)
  does not load correctly [code; not tried with particular games]. Merge the tracks into a single `.bin` first with any BIN/CUE merging tool.
- The `.cue` file must be smaller than 2,000 bytes (normal cue sheets are far smaller).
- The `.cue` and its `.bin` should be in the same folder. If the file named in the `.cue` is not found, the firmware
  tries the `.cue` file's own name with the extension from the cue sheet.
- NRG and CCD images are recognised by extension but not supported.
- The 3dodev.com Fixel ODE page also lists `.nrg` images and cue + wav music CDs. It covers both ODE models; the
  FZ-1 firmware rev 1.0 supports neither (multi-file cue sheets read every track from the last file).

### Version numbers in the menu

The left pane of the menu shows two lines (examples from Fixel's quick-start guide, which shows an older firmware;
the meanings are [code], from the firmware and the menu's reconstructed source):

| Shown | Meaning | Where it comes from |
|---|---|---|
| `FZ1ODE:r3` | `FZ1ODE` = hardware detected; `r3` = menu version | `FZ1ODE` is a fixed ID string the firmware reports (it is the same on every board: it does **not** show Rev A/Rev B). `rN` is the menu's own version, part of `boot.iso`, not of the firmware. |
| `V 0.20.0` | Firmware version | The firmware reports major and minor (rev 1.0 sends 1 and 0). The **third digit is not part of the version**: it is the number of Eject presses the ODE last counted. The menu prints the three values as `v %d.%d.%d`. |

With the current official release (firmware rev 1.0 and its `boot.iso`) the pane shows `FZ1ODE:r5` and
`V 1.0.0` after power-on, or for example `V 1.0.2` after a double Eject press back to the menu. It is still the same firmware. The stock firmware and this rebuild report
exactly the same values, so the screen cannot tell them apart.

## Getting the required files

This repository contains only original work and open-source libraries. Everything derived from Fixel's firmware
is recreated locally from his official, freely available release:

1. Download `update.ode` (FZ-1 ODE firmware rev 1.0) from Fixel's release page:
   `https://github.com/fixelsan/3do-ode-firmware/releases`
2. Run (Python 3.8 or newer, any operating system):
   ```
   python3 tools/setup_from_official.py path/to/update.ode
   ```

The script checks that the file is exactly the official release (SHA-256
`5e98519d83c22605031a182acb6ecb3f4391aef2b922b02ec4ccb38918cf2fec`), then:
- extracts the FPGA bitstream to `source/src/fpga_bitstream.bin` (the only Fixel file the source build needs)
- copies the image to `original/update.ode` as the comparison reference
- runs `tools/analyze.py` to regenerate the annotated disassembly, the function map, the ELF with symbols and the
  symbol files from the naming tables in `tools/`

The build stops with a message pointing here if the bitstream is missing.

## Building

Requirements: GNU Arm Embedded **10.3-2021.10**, CMake ≥ 3.13, Pico SDK **1.3.0** (the original was built with these
exact versions; others will work but won't match byte-for-byte).

```
cd source
mkdir build && cd build
PICO_SDK_PATH=/path/to/pico-sdk-1.3.0 cmake -DCMAKE_BUILD_TYPE=Debug -DPICO_BOARD=pico ..
make -j
# output: build/update.ode
```

Compare against the original (after the setup step above):

```
python tools/compare_src.py piode2.elf functions.tsv source/build/CMakeFiles/piode2.dir
```

## Dumping your ODE's flash (`dump_patch/`)

`dump_patch/` builds a modified `update.ode` that, once installed, copies the ODE's whole 16 MB flash (bootloader,
firmware and the rest) to `fz1flash.bin` on the microSD card, or on the USB drive if no card is inserted. It is the
way to back up the bootloader without BOOTSEL/picotool or a debug probe. It has been used successfully on
a Rev B board with a USB drive [hardware]; the microSD path is the same code but was not tried.

1. Run the setup step above, then build the patch (needs `arm-none-eabi-gcc` and Python 3):
   ```
   cd dump_patch
   make
   ```
   This writes `dump_patch/update.ode`.
2. Use one drive only, with at least 20 MB free: a microSD card, or a USB drive with no microSD card inserted.
   Copy `dump_patch/update.ode` to its root as `update.ode`.
3. On the console open the **X** menu, choose **Update ODE** and confirm. The screen stays on "Updating. Don't turn
   off power!": that is normal. Wait, then power-cycle.
4. Leave the console running after it starts again. The dump runs right after the drive mounts (the access LED
   blinks): about 2 minutes on microSD, up to about 10 minutes on USB [estimate]. The console may show no disc or an error while
   the ODE is busy. Then power off.
5. On a PC, check that `fz1flash.bin` is exactly 16,777,216 bytes and keep copies. The first 65,536 bytes are the
   bootloader.
6. Put the official `update.ode` back on the drive and run **Update ODE** again to return to stock firmware.

The dump runs once per boot and is skipped if `fz1flash.bin` already exists. Installing any modified image carries
the risks described under [Safety](#safety); keep the official `update.ode` on the microSD card.

## Not included

This repository does not contain Fixel's binaries: the original `update.ode`, the FPGA bitstream, flash dumps or the
`boot.iso` menu. The firmware and menu are available from Fixel's release repository
(`github.com/fixelsan/3do-ode-firmware`); see "Getting the required files" above. The bootloader cannot be downloaded
anywhere: its analysis is included (`bootloader/`), and you can dump your own board's bootloader with `dump_patch/`.

## Safety

- The ODE installs firmware from `update.ode` on the microSD card or USB drive through its own **Update ODE** menu.
  The bootloader accepts any image whose vector table looks valid (no checksum or signature) and verifies the write
  by reading it back. [bootloader code]
- The bootloader re-flashes from `/sd/update.ode` (microSD card root only) by itself if the installed image is broken,
  crashes within about half a second of starting, or a previous update failed. Keep the official `update.ode` on
  the microSD card while experimenting. [bootloader code]
- It **cannot** recover from an image that starts normally and then hangs: that image is simply restarted in a loop,
  and the Update ODE menu becomes unreachable. Only BOOTSEL (below) gets you out, so have it available before
  testing a rebuilt or modified image. [bootloader code]
- The RP2040's BOOTSEL mode (mask ROM) is the hardware recovery path. On the Rev B board the only USB port is a
  USB-A socket (J5), wired as a host port: when the ODE runs, it supplies 5 V on that socket. Between the socket and
  the board's 5 V rail there is only a ferrite bead (FB1), with no power switch or diode visible, so a computer can
  most likely power the board backwards through it, the way a Raspberry Pi Pico runs from USB [inference from
  photos of the board; not traced].
  **BOOTSEL recovery has not been tested on this board yet.** Likely procedure:

  1. Remove the ODE from the console, or at least unplug its power cable (J4) and the 30-pin ribbon (J1).
  2. Hold SW1 and connect the ODE's USB-A socket to a computer with an ordinary A-to-A cable (5 V line connected).
  3. Look for an `RPI-RP2` drive or a picotool device.

  **Never connect the ODE to a computer while it is connected to the console.** The computer and the console would
  then both supply the same 5 V line. With the ODE out of the console only the computer supplies power, which is safe.

  | Part | Status |
  |---|---|
  | RP2040 BOOTSEL mode exists | [doc] RP2040 datasheet: it is in the chip's mask ROM and cannot be overwritten |
  | The USB-A socket is wired to the RP2040's USB pins | [inference] Very likely: the firmware uses the RP2040's only USB controller as host on that socket |
  | The socket's 5 V is the board's 5 V rail, so a computer can power the board | [inference] Likely: only a ferrite bead (FB1) is visible between them (from photos, not traced). If not, the board simply stays off |
  | A computer port supplies enough current | [estimate] Likely: the RP2040, FPGA and regulators should need well under 500 mA |
  | SW1 is the BOOTSEL button | [guess] From the board layout (similar to a Raspberry Pi Pico); unconfirmed |

  Try it once while the ODE still works, so you know whether recovery is available before you need it. Reports from
  anyone who has tested it are welcome.
- Back up the full 16 MB flash before experimenting, and keep the official `update.ode` to restore stock firmware.
- You use anything here at your own risk.

## Scope and future work

This project is a faithful reconstruction of the stock firmware: fixes and new features are deliberately left out,
so it can serve as a verified reference. What others do with it is up to them.

Separate projects:
- **The ODE menu (`boot.iso`):** [fixel-3do-fz1-ode-menu-decomp](https://github.com/yesmorepain/fixel-3do-fz1-ode-menu-decomp). The 3DO-side menu program talks to the ODE
  only through the command set documented here, so this firmware is effectively its specification. Its
  reconstruction is finished:
  the menu's programs rebuild byte-for-byte from reconstructed C, and a rebuilt menu has run on an FZ-1 [hardware].
- **The FPGA bitstream:** [fixel-3do-fz1-ode-fpga-decomp](https://github.com/yesmorepain/fixel-3do-fz1-ode-fpga-decomp). No source for the gateware exists, so the official
  bitstream was decoded with open-source tools and simulated. The analysis is finished: it documents the FPGA's
  behaviour and bus timing, and includes a clean, readable HDL reconstruction proved equivalent to the decoded
  original in simulation and on a formal model. The findings that matter for the firmware (bus protocol, buffer
  sizes, status flags, 75 Hz pacing, the RP2040 handshake signals, two timing races) are summarised in
  [docs/firmware.md](docs/firmware.md), "What the FPGA does", each marked by how well it is supported.
  **None of it has been tested on hardware.**

  What this is good for, and what it is not:
  - *Useful without hardware testing:* a precise description of the original, read from the bitstream and checked
    in simulation rather than guessed. It is a reference for replacement drive emulators, new ODE designs and ODE
    firmware, and it has already corrected earlier assumptions here and found two timing races in the original
    design.
  - *Still needs real hardware:* simulation can show that a description matches the bitstream, but not that the
    bitstream's own assumptions about the board hold (pin roles, timing margins against a real
    3DO). Gateware rebuilt with open-source tools has never run on an ODE.

  In short: trustworthy as a description, unproven as a drop-in replacement. Anyone with an ODE and a logic
  analyser can help close that gap.

Contributions and test reports, especially a BOOTSEL test on a Rev B board, are welcome.

## Acknowledgements

- Fixel, for designing the FZ-1 ODE.
- FCare's [SataTo3DO](https://github.com/FCare/SataTo3DO) (MIT), an open implementation of the same 3DO drive
  protocol, used as a reference for command names and formats.
- Raspberry Pi Pico SDK, TinyUSB (hathach) and FatFs (ChaN), whose sources made library identification possible.

## Legal

This is a clean-room-style analysis of firmware for hardware the author owns, for preservation, repair and
interoperability. Fixel's firmware license is listed as "TBD". The reconstructed application code is derived
from that firmware; third-party components keep their own licenses (Pico SDK: BSD-3-Clause, TinyUSB: MIT,
FatFs: ChaN's BSD-style license). Check the legal situation where you live before redistributing builds.
The original work in this repository (tools, scripts, patches, documentation and analysis) is under an
MIT-based license that forbids commercial use; see [LICENSE](LICENSE) for what it does and does not cover.
