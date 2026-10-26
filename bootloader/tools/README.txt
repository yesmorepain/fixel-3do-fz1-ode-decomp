Naming the bootloader (odeboot) functions - how odeboot_functions.tsv / odeboot_symbols.txt were made (2026-10-25)

1. Ghidra project: analyzeHeadless <dir> odeboot -import references/flash_dump/odeboot_bootloader.bin
     -processor ARM:LE:32:Cortex -loader BinaryLoader -loader-baseAddr 0x10000000
     -scriptPath "ghidra;bootloader" -preScript MapOdeboot.java <bin> -postScript DumpFuncs.java odeboot_funcs.tsv
2. ELF wrapper for the matcher: objcopy -I binary the 64 KB file (.flash @0x10000000) and bytes 0x308..+0xdf0c
   (.ramimg @0x200000c0), link with l.ld -> odeboot.elf.
3. tools/match_libs.py odeboot.elf odeboot_funcs.tsv odeboot_matched.py ~/opt/ref/build <hub ref build>
   ~/opt/ref/libs/{libc,libm,libgcc}. Hub ref build = ~/opt/ref with tusb_config_hub.h (CFG_TUH_HUB 1,
   CFG_TUH_DEVICE_MAX 4): odeboot's usbh/hub/msc byte-match stock TinyUSB 0.12 built that way.
4. appmatch.py <dir> <piode2 dir> > app2.txt: compare leftovers with the app's named functions (BL and
   literal words masked); >= 0.90 accepted (Fixel's FatFs, mmc_spi, usb_msc, hcd port are shared with the app).
5. mknames.py <dir> <piode2 dir>: merge (byte match > app match > manual/L), lma_* for flash load copies.
6. ghidra/SyncNames.java odeboot_symbols.txt, then ghidra/ExportDecomp.java -> odeboot_decompiled.c.
