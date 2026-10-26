import sys
B, P = sys.argv[1], sys.argv[2]
sys.path.insert(0, B); from odeboot_matched import MATCHED
D = 0x200000c0 - 0x10000308  # RAM = flash + D for the copy_to_ram image
funcs = [(int(a, 16), int(s), n) for a, s, n in (l.split("\t") for l in open(B + "/odeboot_funcs.tsv").read().splitlines()[1:])]
fset = {a for a, _, _ in funcs}
names = {}
def put(a, n, how):
    if a not in names: names[a] = (n.replace("|", "__or__"), how)
for a, (n, how) in MATCHED.items():
    if a >= 0x200000c0: put(a, n, how)
for a, (n, how) in MATCHED.items():         # matched only in the flash load copy
    if 0x10000308 <= a < 0x10010000 and a + D in fset: put(a + D, n, how + " (on flash copy)")
for l in open(B + "/app2.txt"):
    a, s, sc, n = l.split()[:4]
    if float(sc) >= 0.90: put(int(a, 16), n, "app:%s %s" % (n, sc))
names[0x200043a6] = ("msc_write_complete_cb", "app: 2nd of identical read/write pair (as in app)")
for a, n in ((0x200001ec, "main"), (0x20000184, "try_boot_app"), (0x20000134, "core1_usb_task")):
    put(a, n, "manual: odeboot_main.c")
for a, n in ((0x20004810, "flash_page_program"), (0x200048a8, "flash_range_program"),
             (0x200048f0, "flash_user_erase"), (0x20004978, "flash_read_data")):
    put(a, n, "pflash.c assert string")
for a, n, why in (
        (0x20004644, "flash_cs_force", "pflash.c, writes QSPI SS OUTOVER"),
        (0x20004660, "connect_internal_flash", "pflash.c, reset IO/PADS_QSPI + funcsel 0 on 6 pins"),
        (0x20004688, "flash_init_spi", "pflash.c, SSI baud 6, ctrlr0 0x70000"),
        (0x200046a8, "flash_was_aborted", "pflash.c, QSPI SD1 INOVER bits"),
        (0x200046b8, "flash_put_get", "pflash.c, (tx, rx, count, rx_skip)"),
        (0x2000474c, "flash_do_cmd", "pflash.c"),
        (0x20004770, "flash_enable_write", "pflash.c, cmd 0x06"),
        (0x20004780, "flash_exit_xip", "pflash.c, 0xff 0xff sequence"),
        (0x2000496c, "flash_sector_erase", "pflash.c, flash_user_erase(addr, 0x20)"),
        (0x200049d6, "reset_unreset_block_wait_noinline", "reset/unreset/wait-done"),
        (0x20002238, "create_name", "FatFs, tchar2uni/strchr/ff_uni2oem (Fixel FatFs differs here, as in app)"),
        (0x200007d0, "sd_spi_set_speed", "spi_set_baudrate(fast if arg)"),
        (0x200007e0, "sd_spi_set_slow", "spi_set_baudrate(slow)"),
        (0x20003b7c, "wait_ready", "mmc_spi, xchg_spi loop"),
        (0x20003cb8, "rcvr_datablock", "mmc_spi, rcvr_spi_multi"),
        (0x20003d2c, "xmit_datablock", "mmc_spi, wait_ready + xmit_spi_multi"),
        (0x20003ef0, "mmc_disk_read", "mmc_spi, send_cmd + rcvr_datablock (app 0.69)"),
        (0x2000402c, "mmc_disk_ioctl", "mmc_spi, 15-entry switch, RES_NOTRDY/PARERR"),
        (0x200044d8, "usb_disk_initialize", "core1 FIFO request 1"),
        (0x200044f4, "usb_disk_status", "core1 FIFO request; main polls &STA_NODISK"),
        (0x20004510, "usb_disk_read", "core1 FIFO request + memcpy"),
        (0x20004578, "usb_disk_write", "core1 FIFO request + memcpy"),
        (0x200045d8, "usb_disk_ioctl", "core1 FIFO request"),
        (0x20007018, "_etoa", "printf.c, calls _ftoa/_ntoa_long"),
        (0x20007362, "_vsnprintf", "printf.c, format loop")):
    put(a, n, "L " + why)
for a, (n, how) in MATCHED.items():         # boot2 / vectors / crt0 in real flash
    if a < 0x10000308: put(a, n, how)
for a in list(names):                       # name the flash load copies after their RAM functions
    if a >= 0x200000c0 and a - D in fset and a - D >= 0x10000308:
        names[a - D] = ("lma_" + names[a][0], "flash load copy of %08x" % a)
with open(B + "/odeboot_symbols.txt", "w") as f:
    for a in sorted(names): f.write("%s %08x f\n" % (names[a][0], a))
with open(B + "/odeboot_functions.tsv", "w") as f:
    f.write("addr\tsize\tname\thow\n")
    for a, s, n in funcs:
        nm, how = names.get(a, (n, ""))
        f.write("%08x\t%d\t%s\t%s\n" % (a, s, nm, how))
ram = [a for a, _, _ in funcs if a >= 0x200000c0]
print("named %d/%d functions; RAM %d/%d" % (sum(a in names for a in fset), len(fset), sum(a in names for a in ram), len(ram)))
