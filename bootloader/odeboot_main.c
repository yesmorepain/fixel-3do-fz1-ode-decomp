/* Reference pseudo-C, not meant to compile. */
/* odeboot "Bootstrap v1.1" (Fixel, Aug 18 2022) - hand reconstruction of the boot/update logic.
 * Source: references/flash_dump/odeboot_bootloader.bin (first 64 KB of flash).
 * Build: Pico SDK 1.3.0 Debug, PICO_COPY_TO_RAM: crt0 copies flash 0x10000308.. to RAM 0x200000c0..0x2000bcc0
 * (.text) and 0x1000bf08.. to 0x2000bcc0..0x2000dfcc (.data). RAM addr = flash file offset + 0x1ffffdb8 (0x200000c0-0x308).
 * Ghidra output (all functions, named): odeboot_decompiled.c; names + provenance: odeboot_functions.tsv; pre-script MapOdeboot.java sets the RAM map.
 * Function names below are inferred from behaviour and SDK/FatFs call patterns (L = guess); addresses are RAM. */

#define APP_VECTORS   ((uint32_t *)0x10010100)   /* app image is at 0x10010000; its boot2 (first 256 B) is unused */
#define S0 watchdog_hw->scratch[0]
#define S1 watchdog_hw->scratch[1]
#define S2 watchdog_hw->scratch[2]

static uint8_t buf_file[0x1000];   /* 0x2000f084 */
static uint8_t buf_flash[0x1000];  /* 0x20010084 */

/* 0x20000184 */
static void try_boot_app(void)
{
    uint32_t *v = APP_VECTORS;
    printf("vectors %8.8x %8.8x\n", v[0], v[1]);
    /* the ONLY validity check: initial SP in 0x20000000..0x200fffff, reset vector in 0x10010000..0x10ffffff */
    if (v[0] >= 0x20000000 && v[1] > 0x1000ffff && v[0] <= 0x200fffff && v[1] < 0x11000000) {
        printf("found proper image %8.8x %8.8x\n", v[0], v[1]);
        scb_hw->vtor = (uint32_t)v;
        __set_MSP(v[0]);                      /* only if privileged */
        ((void (*)(void))v[1])();             /* does not return */
    }
}

/* 0x20000134: core1, USB host only */
static void core1_usb_task(void) { /* tusb_init(); loop { tuh_task(); handle msc requests from core0 } */ }

/* 0x200001ec */
int main(void)
{
    int flag, err;
    uint32_t src;

    stdio_uart_init_full(uart0, 3000000, 16, 17);

    if (!watchdog_caused_reboot()) {                     /* 0x2000698c: power-on / reset pin */
        goto boot;
    } else if (S0 == 0xbeef0000 && S1 == 0xdeadf00d && S2 == 0xfeedface) {
        goto boot;                                       /* "run app" marker (set by app main and after an update) */
    } else {
        flag = 0;
    }
    if (0) {
boot:
        puts("Attempt booting");
        watchdog_enable(500, 1);                         /* app must re-arm/feed within 500 ms */
        S0 = 0xdeadf00d; S1 = 0xfeedface; S2 = 0xbeef0000;   /* "boot attempt in progress" marker */
        try_boot_app();
        puts("Attempt failed");                         /* bad vectors -> fall through to update */
        flag = 4;
    }
    if (S0 == 0xdeadf00d && S1 == 0xfeedface && S2 == 0xbeef0000)
        flag = 1;                                        /* app died before main() rewrote the marker */
    if (S0 == 0xfeedface && S1 == 0xdeadf00d && (S2 & 0xffff0000) == 0xbeef0000)
        flag = 2;                                        /* update requested by app (ode_stage_firmware_update) */
    else if (flag == 1) {
        src = 1;                                         /* failed boot -> update from SD */
        goto have_src;
    }
    src = S2 & 0xffff;                                   /* 1 = SD, 2 = USB; anything else (0, 0xface) = SD */
have_src:
    S0 = S1 = S2 = 0;
    board_init();                                        /* 0x20000604 (L): GPIO/SPI0 for SD, LED GPIO25 */
    printf("\n\n\nBootstrap v1.1 flag %x scratch %x \n", flag, src);
    usb_disk_set_nodisk();                               /* 0x200044cc (byte-identical to the app) */
    memset(buf_file, 0, 0x200);
    sio_hw->gpio_set = 1u << 25;                         /* LED */

    if (src == 2) {                                      /* USB: retried forever until a stick with update.ode appears */
        multicore_launch_core1(core1_usb_task);
        do {
            while (usb_disk_status() & 2) sleep_ms(100); /* 0x200044f4, STA_NODISK */
            sleep_ms(100);
            if ((err = f_mount(&fs_usb, "/usb", 1)) == 0) { puts("mnt ok");
            if ((err = f_chdir("/usb/")) == 0)          { puts("dir ok");
            if ((err = f_chdrive("/usb")) == 0)         { puts("cdrive ok");
            if ((err = f_open(&fil, "update.ode", FA_READ)) == 0) { puts("file ok"); f_close(&fil); } } } }
        } while (err);
    } else {
        err = f_mount(&fs_sd, "/sd", 1);                 /* SD: single attempt per boot */
    }
    if (err) printf("mount %x\n", err);
    connect_internal_flash(); flash_exit_xip();          /* 0x20004660, 0x20004780 (pflash.c, bootrom-style) */

    if (!err) {
        err = f_open(&fil, "update.ode", FA_READ);       /* root of the current drive */
        if (!err) {
            uint32_t size = (uint32_t)f_size(&fil), off;
            UINT br;
            printf("Update size %x\n", size);
            /* no size/CRC/signature check. Flash driver (pflash.c) asserts addr < 16 MB. */
            for (off = 0; off < size; off += 0x1000) {
                if ((e2 = f_read(&fil, buf_file, 0x1000, &br))) { printf("read %x\n", e2); break; }
                flash_sector_erase(0x10000 + off);       /* 0x2000496c, cmd 0x20 */
                flash_range_program(0x10000 + off, buf_file, 0x1000);   /* whole 4 KB even for a short last read */
                printf("prg %x\n", off);
                watchdog_update(); toggle_led();
            }
            f_lseek(&fil, 0);
            for (off = 0; off < size; off += 0x1000) {   /* read-back verify against the file */
                flash_read_data(0x10000 + off, buf_flash, 0x1000);
                if ((e2 = f_read(&fil, buf_file, 0x1000, &br))) { printf("read %x\n", e2); break; }
                printf("verify %x %x\n", off, br);
                if (memcmp(buf_file, buf_flash, br)) { puts("verify failed"); e2 = 0xff; break; }
                watchdog_update(); toggle_led();
            }
            if (off < size) err = e2;
            f_close(&fil);
        } else printf("open %x\n", err);
    }

    if (!err) {
        S0 = 0xbeef0000; S1 = 0xdeadf00d; S2 = 0xfeedface;   /* next boot: run app */
        puts("Updated issue reboot");
    } else {
        S0 = 0; S1 = 0xdeadf00d; S2 = 0xfeedface;            /* matches nothing -> next boot retries SD update */
        puts("Can't mount or update, reset");
    }
    watchdog_enable(100, 1);
    for (;;) ;
}
