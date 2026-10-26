/*
 * piode2 v0.1 — 3DO FZ-1 internal ODE — hand-reconstructed C for the core paths.
 *
 * Reconstructed from the disassembly (see piode2_disasm.s). Addresses are the
 * original function / global addresses in the 0x10010000-based application image.
 * Names of globals and struct fields are mine; behaviour follows the machine code.
 * Anything not verified instruction-by-instruction is marked  /* ... see listing */.
 *
 * Hardware picture recovered from the image:
 *   RP2040 (Pico SDK 1.3.0, boot2_w25q080), app linked at 0x10010000 behind a 64 KB bootloader
 *   Lattice iCE5LP4K-SG48 FPGA on SPI1 (CS = GPIO9) implements the 3DO CD bus; the RP2040
 *     exchanges command/reply packets with it. Bitstream embedded @0x1001f945, 71338 bytes.
 *   SD card + USB mass storage (TinyUSB host) with FatFs, paths "/sd" and "/usb"
 *   UART0 debug console, 3,000,000 baud, TX=GPIO16 RX=GPIO17
 *   GPIO13 is tested in the main loop (low -> prints "WTF???" "FTW" and halts)
 */
#include <stdint.h>

/* ---------------------------------------------------------------- globals */
typedef struct {                    /* @0x200050cc */
    uint8_t status;                 /* +0  CD status byte; bit4 (0x10) = CHECK_ERROR      */
    uint8_t error;                  /* +1  error code (0x17 for unknown command)          */
    uint8_t reply_len;              /* +2  bytes in reply[] (starts at 1: command echo)    */
    uint8_t _pad3[9];
    uint8_t cmd[7];                 /* +12 command packet received from the FPGA           */
    uint8_t reply[64];              /* +19 reply: [cmd echo, data..., status]              */
    /* ... */
    uint32_t cmd_count;             /* +80 incremented on every dispatch                   */
} cd_state_t;
extern cd_state_t cd_state;         /* 0x200050cc */
extern int  g_boot_device;          /* 0x2000697c  1=SD 2=USB 3=current dir decides        */
extern char g_cur_path[];           /* 0x2000488c  g_cur_path[1]=='u' -> "/usb..."          */

static inline void reply_put(uint8_t b) {           /* the idiom every handler uses */
    cd_state.reply[cd_state.reply_len++] = b;
}

/* ---------------------------------------------------------------- dispatcher */
/* 0x10016854 */
void cd_cmd_dispatch(void)
{
    cd_state.cmd_count++;
    if (!cd_recv_command(cd_state.cmd))             /* 0x10015108, SPI1 read of 10 bytes */
        return;

    cd_state.reply_len = 0;
    cd_state.reply_len = 1;
    cd_state.reply[0]  = cd_state.cmd[0];           /* echo opcode */
    cd_state.status   &= ~0x10;                     /* clear CHECK_ERROR */
    if (cd_state.cmd[0] != 0x82)                    /* READ_ERROR keeps the last error */
        cd_state.error = 0;

    switch (cd_state.cmd[0]) {                      /* jump table @0x100311b8, 241 entries */
    case 0x02: cmd_02_spin_up();            break;
    case 0x03: cmd_03_spin_down();          break;
    case 0x06: cmd_06_eject_disc();         break;
    case 0x07: cmd_07_inject_disc();        break;
    case 0x08: cmd_08_abort();              break;
    case 0x09: cmd_09_set_mode();           break;
    case 0x0b: cmd_0b_flush();              break;
    case 0x10: cmd_10_read_data();          break;
    case 0x80: cmd_80_data_path_check();    break;
    case 0x82: cmd_82_read_error();         break;
    case 0x83: cmd_83_read_id();            break;
    case 0x85: cmd_85_read_capacity();      break;
    case 0x87: cmd_87_read_sub_q();         break;
    case 0x8b: cmd_8b_read_disc_info();     break;
    case 0x8c: cmd_8c_read_toc();           break;
    case 0x8d: cmd_8d_read_session();       break;
    case 0x8e: case 0xc2:                   break;   /* no handler: status-only reply */
    case 0x93: cmd_93_ext_id();             break;
    case 0xc0: cmd_c0_change_toc();         break;
    case 0xc1: cmd_c1_get_toc();            break;
    case 0xc3: cmd_c3_clear_playlist();     break;
    case 0xc4: cmd_c4_add_playlist();       break;
    case 0xc5: cmd_c5_launch_playlist();    break;
    case 0xd1: cmd_d1_get_toc_list();       break;
    case 0xe0: cmd_e0_create_file();        break;
    case 0xe1: cmd_e1_open_file();          break;
    case 0xe2: cmd_e2_seek_file();          break;
    case 0xe3: cmd_e3_read_file_byte();     break;
    case 0xe4: cmd_e4_write_file_byte();    break;
    case 0xe5: cmd_e5_close_file();         break;
    case 0xe6: cmd_e6_write_buffer_offset();break;
    case 0xe7: cmd_e7_read_buffer();        break;
    case 0xf0: cmd_f0_update_ode();         break;
    default:                                         /* also any opcode > 0xf0 */
        cd_state.status |= 0x10;                     /* CHECK_ERROR */
        cd_state.error   = 0x17;
        break;
    }
    /* common tail @0x10016898 */
    reply_put(cd_state.status);
    cd_send_reply(cd_state.reply, cd_state.reply_len);   /* 0x100151b8 */
}

/* 0x100151b8: frame [0x02, payload...] and push it to the FPGA */
void cd_send_reply(const uint8_t *buf, unsigned len)
{
    uint8_t pkt[65 + 1];
    if (len > 64) len = 64;
    pkt[0] = 0x02;
    memcpy(&pkt[1], buf, len);
    gpio_put(9, 0);                                  /* SIO GPIO_OUT_CLR (1<<9) */
    spi_write_blocking(spi1, pkt, len + 1);
    /* ... CS release / handshake: see listing 0x100151f4.. */
}

/* 0x10015108: poll the FPGA for a new command packet */
int cd_recv_command(uint8_t *cmd /* 7 bytes */)
{
    uint8_t op = 0x01, rx[10], z = 0;
    if (!cmd) return 0;                               /* ... see listing */
    gpio_put(9, 0);
    spi_write_blocking(spi1, &op, 1);
    spi_read_blocking(spi1, 0xff, rx, 10);
    gpio_put(9, 1);
    gpio_put(9, 0);
    spi_write_blocking(spi1, &z, 1);
    gpio_put(9, 1);
    memcpy(cmd, &rx[2], 7);
    /* then validates cmd[0] (0x10 READ_DATA / 0x87 READ_SUB_Q get special handling) ... see listing */
}

/* 0x100161d8: 0x93 EXT_ID — device identification, layout as in Fixel's protocol note */
void cmd_93_ext_id(void)
{
    uint8_t lo = fn_10016cd8() & 0x0f;                /* boot device */
    uint8_t hi = fn_100170d0();
    reply_put(lo | (hi << 4));
    reply_put('F'); reply_put('Z'); reply_put('1'); reply_put('O'); reply_put('D');
    /* ... remaining name/rev bytes: see listing 0x10016232.. */
}

/* ---------------------------------------------------------------- firmware update */
/* 0x100177dc. The app only *stages* the update; the 64 KB bootloader (not in the
 * .ode file) flashes it after a watchdog reboot, keyed by these scratch values. */
int ode_stage_firmware_update(void)
{
    FIL fil;
    watchdog_hw->scratch[2] = 0xbeef0000;
    switch (g_boot_device) {
    case 1: watchdog_hw->scratch[2] |= 1; break;                       /* SD  */
    case 2: watchdog_hw->scratch[2] |= 2; break;                       /* USB */
    case 3: watchdog_hw->scratch[2] |= (g_cur_path[1] == 'u') ? 2 : 1; break;
    default: return 0;
    }
    switch (watchdog_hw->scratch[2] & 0xff) {
    case 1: if (f_open(&fil, "/sd/update.ode",  FA_READ) != FR_OK) return 0; break;
    case 2: if (f_open(&fil, "/usb/update.ode", FA_READ) != FR_OK) return 0; break;
    }
    f_close(&fil);
    printf("Updating from %x\n", watchdog_hw->scratch[2]);
    watchdog_hw->scratch[0] = 0xfeedface;
    watchdog_hw->scratch[1] = 0xdeadf00d;
    watchdog_enable(1000, 1);                        /* reset into bootloader */
    return 1;
}

/* ---------------------------------------------------------------- main */
/* 0x10010424 */
int main(void)
{
    /* disarm any pending update request (same magic words, different slots) */
    watchdog_hw->scratch[0] = 0xbeef0000;
    watchdog_hw->scratch[1] = 0xdeadf00d;
    watchdog_hw->scratch[2] = 0xfeedface;
    watchdog_enable(3000, 1);

    stdio_uart_init_full(uart0, 3000000, 16, 17);
    puts("\n\n\nODE1 Entry");
    printf("version %d.%d\n", 1, 0);                  /* r1=1 r2=0 at the call */
    printf("%x %x %x %x\n", 0x2000e600, 0x2000b600, 0x2000b600, 0x20009600);
    memset((void *)0x20009600, 0xcc, 0x2000);         /* paint 8 KB stack region */
    g_4728 = g_472c = g_4850 = 0;

    fn_10014dc4();
    multicore_launch_core1(core1_entry);              /* 0x10010358 */
    fn_1001797c();
    fn_100106e4();                                    /* timers / alarm pool, SPI0+SPI1 setup */
    printf("FPGA Init %d\n", fpga_init());            /* 0x10015004 */
    fn_10016980();
    fn_10016c20();
    g_6978 = 0;

    /* register 4 event callbacks with masks 8,4,0x20,1 via fn_10017d38(cfg, cb, mask);
       cfg = { cb=fn_100103b4, 3000, 1500, 3, 1, ... }  ... see listing 0x100104b0 */

    for (;;) {
        g_75e8 |= 2;
        /* ... debounce of g_4728/g_5374 (|delta| > 1499) ... */
        if (!(sio_hw->gpio_in & (1u << 13))) {        /* GPIO13 low */
            puts("WTF???"); puts("FTW");
            for (;;) ;                                /* watchdog will reset */
        }
        fn_100179ac();
        cd_cmd_poll();                                /* 0x10016a30 -> cd_cmd_dispatch */
        ode_mount_media();                            /* 0x10016ce4: /usb, /sd, boot.iso */
        /* state machine on g_6978 (1,2) issuing fpga_write_ctrl()/fpga_read_status()
           and printing "POLL1 %x"/"POLL %x"; g_75e8==3 path ... see listing */
    }
}
