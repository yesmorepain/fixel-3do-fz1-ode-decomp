# Firmware update, bootloader and recovery

How `update.ode` gets into flash, what the bootloader checks, and when it recovers by itself. Sources:
`source/src/ode.c` (`ode_stage_firmware_update`), `source/src/main.c`, and the bootloader reconstruction in
`bootloader/odeboot_main.c` (decoded from a flash dump; reference pseudo-C, not compilable).

For the practical side (keeping the official `update.ode` on the microSD card, BOOTSEL status, dumping the flash
with `dump_patch/`) see "Safety" and "Dumping your ODE's flash" in the top-level `README.md`.

## Overview

The firmware never writes its own flash. It only leaves a request in the RP2040's watchdog scratch registers,
which survive a watchdog reset, and lets the watchdog reset the chip. The bootloader then reads `update.ode` from
the drive and programs it.

```
menu "Update ODE" -> F0 command -> ode_stage_firmware_update
    checks /sd/update.ode or /usb/update.ode opens
    scratch = FEEDFACE, DEADF00D, BEEF00xx      (xx = 01 microSD, 02 USB)
    watchdog 1 s; main loop stops feeding it -> reset
bootloader: sees the request -> mounts the drive -> erase + program 4 KB at a time -> read-back verify
    success: scratch = "run app" marker -> reset -> new firmware starts
    failure: scratch = no marker -> reset -> retries from microSD on every boot
```

The screen stays on the menu's "Updating. Don't turn off power!" message during this; the menu gets no further
reply. Wait for the update to finish, then power-cycle (the README gives the steps).

## Staging (firmware side)

`ode_stage_firmware_update` (F0, 0x100177dc in the original):

| Drives mounted | Source chosen |
|---|---|
| microSD only | microSD |
| USB only | USB |
| both | The drive the menu is currently browsing (the current path starts with `/usb` or not) |
| none | Nothing staged, reply 0 |

It then checks that `update.ode` opens in the root of that drive (not the folder being browsed). If not, it
replies 0 and nothing happens. Otherwise it sets the scratch words, enables the watchdog with a 1 s timeout and
replies 1. The main loop feeds the watchdog only while scratch 0/1 do not hold the request, so the chip resets
about a second later.

## Scratch-register protocol

| Scratch 0, 1, 2 | Written by | Meaning to the bootloader |
|---|---|---|
| `BEEF0000 DEADF00D FEEDFACE` | Firmware `main()` at start-up; bootloader after a successful update | "Running / run the app": just boot it |
| `DEADF00D FEEDFACE BEEF0000` | Bootloader right before jumping to the app | "Boot attempt in progress": if this is still there after a watchdog reset, the app died before `main()` |
| `FEEDFACE DEADF00D BEEF00xx` | Firmware F0 command | "Update from xx" (1 microSD, 2 USB) |
| `00000000 DEADF00D FEEDFACE` | Bootloader after a failed update | Matches nothing: falls back to a microSD update |

## The bootloader

"odeboot", Bootstrap v1.1, built Aug 18 2022 with the same Pico SDK 1.3.0, its own FatFs and TinyUSB (with hub
support) and a flash driver in the style of the boot ROM's. It occupies the first 64 KB of flash, copies itself to
RAM and runs from there. Updates never rewrite it.

Its decision at every reset:

| Situation | Action |
|---|---|
| Power-on or reset pin (not a watchdog reset) | Boot the app |
| Watchdog reset with "run app" marker | Boot the app |
| App vector table invalid | Update from microSD |
| Watchdog reset with "boot attempt" marker (app died within 500 ms, before `main()`) | Update from microSD |
| Update request, source 2 | Update from USB: waits, retrying forever, until a USB drive with `update.ode` in its root appears |
| Update request, source 1, or anything else | Update from microSD: one attempt per boot |

Booting the app: the only check is the vector table at 0x10010100 (initial stack pointer in 0x20000000-0x200fffff,
reset vector in 0x10010000-0x10ffffff). It writes the "boot attempt" marker, starts a 500 ms watchdog, sets the
vector table base and jumps. The app's `main()` replaces the marker and re-arms the watchdog at 3 s within that
time.

Updating: it reads `update.ode` from the root of the drive in 4 KB pieces, erasing and programming each 4 KB flash
sector from 0x10010000 upwards (the last sector is programmed in full, so its tail holds leftover buffer bytes),
then reads everything back and compares it with the file. There is no checksum, no signature and no size limit
other than the 16 MB flash. The LED toggles during both passes. Any read error or mismatch counts as a failure.

## What recovers and what does not

| Failure | Result |
|---|---|
| Update interrupted or verify failed | Retried from `/sd/update.ode` on every reboot until it succeeds |
| Image with a broken vector table | Re-flashed from `/sd/update.ode` automatically |
| Image that crashes or hangs before `main()` (within 500 ms) | Re-flashed from `/sd/update.ode` automatically |
| Image that reaches `main()` and then hangs | Not recovered. `main()` has already written "run app", so every watchdog reset boots it again: a boot loop, with the menu unreachable. Only the RP2040's BOOTSEL mode (boot ROM) can recover it |
| `update.ode` only on a USB drive when recovery is needed | Not recovered: automatic recovery uses only the microSD card |

Automatic recovery always reads the microSD card root, so a known-good `update.ode` there is the safety net while
testing other images.

## Images other than the official one

Because the bootloader checks nothing but the vector table, any image linked for 0x10010000 installs: patched
images (`dump_patch/`, `patch_example/`) and the rebuilt firmware from `source/` have been installed this way and
run. Restoring stock firmware is the same procedure with the official `update.ode`.

The first 256 bytes of `update.ode` are the firmware's own copy of boot2 (CRC-protected). The bootloader writes
them to 0x10010000 but never runs them; the tools in this repository leave them unchanged.

## Flash backup

The firmware has no flash read-out command. `dump_patch/` is a small patch on the official image that writes the
whole 16 MB flash (bootloader included) to `fz1flash.bin` on the drive once per boot; the README has the steps.
The first 65,536 bytes of the dump are the bootloader, which is not available anywhere else.
