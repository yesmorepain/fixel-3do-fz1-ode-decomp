/*
 * 3DO CD drive emulation: command handlers and dispatcher.
 * Command packets arrive from the FPGA (which runs the 3DO CD bus); every handler appends
 * to cd_state.reply, the dispatcher's tail adds the status byte and sends the reply.
 * Opcode names follow FCare/SataTo3DO src/interfaces/3DO.c.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "piode2.h"

cd_state_t cd_state;
volatile uint32_t g_cmd_pending;
uint32_t g_media_flags;

uint8_t fops_buffer[0x800];      /* E0..E7 file-operation buffer */
FIL     fops_file;
uint32_t fops_open;

#define NO_DISC() do { cd_state.status |= 0x10; cd_state.status &= ~1; cd_state.error = 0x15; } while (0)

/* wait until the FPGA data FIFO is ready (GPIO20), 100 ms timeout */
static inline void wait_data_ready(void)
{
    uint32_t t0 = g_ticks;
    while (!(sio_hw->gpio_in & (1u << PIN_DATA_READY))) {
        if (abs((int)(g_ticks - t0)) > 100) {
            puts("RD Timeout");
            sio_hw->gpio_set = 1u << PIN_FPGA_CTRL;
            sleep_us(10);
            sio_hw->gpio_clr = 1u << PIN_FPGA_CTRL;
            break;
        }
    }
}

static inline void set_cdda_mode(image_t *img)
{
    if (img->mode == 2) {
        if (!cd_state.cdda_mode) {
            fpga_write_ctrl(2);
            cd_state.cdda_mode = 1;
        }
    } else if (cd_state.cdda_mode) {
        fpga_write_ctrl(0);
        cd_state.cdda_mode = 1;     /* sic: never returns to 0 */
    }
}

#define cmd_u32(i) (uint32_t)(cd_state.cmd[i] << 24 | cd_state.cmd[(i) + 1] << 16 | cd_state.cmd[(i) + 2] << 8 | cd_state.cmd[(i) + 3])

/* FPGA GPIO21 rising edge: a command packet is waiting */
void cd_cmd_irq_cb(uint gpio, uint32_t events)
{
    g_cmd_pending = 1;
}

void cmd_02_spin_up(void)
{
    if (cd_state.disc_present & 1) {
        cd_state.status |= 0x21;
    } else {
        NO_DISC();
    }
}

void cmd_03_spin_down(void)
{
    if (cd_state.disc_present & 1) {
        cd_state.status &= ~0x20;
        cd_state.status |= 1;
    } else {
        cd_state.status |= 0x11;
        cd_state.error = 0x15;
    }
}

void cmd_06_eject_disc(void)
{
    cd_state.status &= 0x0d;
    cd_state.status |= 1;
}

void cmd_07_inject_disc(void)
{
    if (cd_state.disc_present & 1)
        cd_state.status |= 0xc1;
    else
        cd_state.status |= 0x80;
}

void cmd_0b_flush(void)
{
    for (int i = 0; i < 30; i++)
        reply_put(0);
    cd_state.status |= 1;
}

void cmd_80_data_path_check(void)
{
    reply_put(0xaa);
    reply_put(0x55);
    cd_state.status |= 1;
}

void cmd_83_read_id(void)
{
    reply_put(0x00);
    reply_put(0x10);
    reply_put(0x00);
    reply_put(0x01);
    reply_put(0x00);
    reply_put(0x00);
    reply_put(0x00);
    reply_put(0x00);
    reply_put(0x00);
    reply_put(0x00);
    cd_state.status |= 1;
}

void cmd_e6_write_buffer_offset(void)
{
    uint32_t off = (cd_state.cmd[1] << 8 | cd_state.cmd[2]) * 4;
    if (off < 0x800) {
        fops_buffer[off]     = cd_state.cmd[3];
        fops_buffer[off + 1] = cd_state.cmd[4];
        fops_buffer[off + 2] = cd_state.cmd[5];
        fops_buffer[off + 3] = cd_state.cmd[6];
    }
}

void cmd_8c_read_toc(void)
{
    image_t *img = ode_get_image();
    uint32_t t = cd_state.cmd[2];
    if ((cd_state.disc_present & 1) && img) {
        if (t <= img->last_track && t != 0) {
            uint8_t *e = &img->toc[t * 8];
            reply_put(e[1]);
            reply_put(e[2]);
            reply_put(e[3]);
            reply_put(e[4]);
            reply_put(e[5]);
            reply_put(e[6]);
            reply_put(e[7]);
            reply_put(e[8]);
            cd_state.status |= 1;
        } else {
            NO_DISC();
        }
    } else {
        NO_DISC();
    }
}

void cmd_8d_read_session(void)
{
    image_t *img = ode_get_image();
    if ((cd_state.disc_present & 1) && img) {
        reply_put(0);
        reply_put(0);
        reply_put(0);
        reply_put(0);
        reply_put(0);
        reply_put(0);
        cd_state.status |= 1;
    } else {
        NO_DISC();
    }
}

void cmd_08_abort(void)
{
    sio_hw->gpio_set = 1u << PIN_FPGA_CTRL;
    sleep_us(10);
    sio_hw->gpio_clr = 1u << PIN_FPGA_CTRL;
    cd_state.status &= ~1;
    for (int i = 0; i < 30; i++)
        reply_put(0);
}

void cmd_09_set_mode(void)
{
    switch (cd_state.cmd[1]) {
    case 0:
        cd_state.density = cd_state.cmd[2];
        cd_state.blen = cd_state.cmd[3] << 8 | cd_state.cmd[4];
        cd_state.flags = cd_state.cmd[5];
        printf("params dens %x, blen %d, flags %x ", cd_state.density, cd_state.blen, cd_state.flags);
        break;
    case 1:
        cd_state.err_mode = cd_state.cmd[2];
        cd_state.err_count = cd_state.cmd[3];
        printf("params err %x count %x ", cd_state.err_mode, cd_state.err_count);
        break;
    case 2:
        cd_state.stop_time = cd_state.cmd[2];
        printf("params stop %x ", cd_state.stop_time);
        break;
    case 3:
        cd_state.speed = cd_state.cmd[2];
        cd_state.pitch = cd_state.cmd[3] << 8 | cd_state.cmd[4];
        cd_state.status &= ~2;
        cd_state.status |= (cd_state.speed >> 6) & 2;   /* double speed */
        printf("params speed %x pitch %d ", cd_state.speed, cd_state.pitch);
        break;
    case 4:
        cd_state.chunk = cd_state.cmd[2];
        printf("params chunk %d ", cd_state.chunk);
        break;
    default:
        cd_state.status |= 0x10;
        cd_state.error = 0x10;
        break;
    }
}

void cmd_8b_read_disc_info(void)
{
    image_t *img = ode_get_image();
    if ((cd_state.disc_present & 1) && img) {
        reply_put(img->disc_type);
        reply_put(img->first_track);
        reply_put(img->last_track);
        reply_put(img->leadout[0]);
        reply_put(img->leadout[1]);
        reply_put(img->leadout[2]);
        cd_state.status |= 1;
        set_cdda_mode(img);
    } else {
        NO_DISC();
    }
}

void cmd_83_read_id(void);

void cmd_82_read_error(void)
{
    for (int i = 1; i < 7; i++) {
        if (cd_state.cmd[i] == 0x83) {
            puts("Caught dipir reset");
            cd_state.reply[0] = 0x83;
            cmd_83_read_id();
            return;
        }
    }
    for (int i = 0; i < 8; i++)
        reply_put(cd_state.error);
    cd_state.status |= 1;
}

void cmd_10_read_data(void)
{
    image_t *img = ode_get_image();
    uint8_t msf[3];
    msf[0] = cd_state.cmd[1];
    msf[1] = cd_state.cmd[2];
    msf[2] = cd_state.cmd[3];
    uint16_t count = cd_state.cmd[5] << 8 | cd_state.cmd[6];
    set_cdda_mode(img);
    for (;;) {
        uint32_t len = ode_read_sector_msf(msf);
        led_activity_on();
        wait_data_ready();
        if (len == 0) {
            cd_state.status |= 0x10;
            cd_state.status &= ~1;
            return;
        }
        uint32_t off;
        if (cd_state.blen == 0x800) {
            if (len > 0x800) {
                off = 0x10;             /* skip sync + header of a raw sector */
                len = 0x800;
            } else {
                off = 0;
                len = 0x800;
            }
        } else if (cd_state.blen == 0x930) {
            if (len == 0x800)
                puts("blah?\n");
            off = 0;
            len = 0x930;
        } else {
            printf("what? %d\n", cd_state.blen);
            off = 0;
        }
        uint8_t *buf = ode_get_sector_buf();
        if ((int8_t)cd_state.flags < 0)
            len += 1;
        if (cd_state.flags & 0x40)
            len += 0x60;
        fpga_send_data(buf + off, len);
        cd_state.status |= 1;
        if (++msf[2] == 75) {
            msf[2] = 0;
            if (++msf[1] == 60) {
                msf[1] = 0;
                msf[0]++;
            }
        }
        if (--count == 0)
            return;
    }
}

void cmd_e7_read_buffer(void)
{
    wait_data_ready();
    fpga_send_data(fops_buffer, 0x800);
    cd_state.status |= 1;
}

void cmd_85_read_capacity(void)
{
    if (!(cd_state.disc_present & 1)) {
        NO_DISC();
        return;
    }
    uint32_t msf = toc_get_leadout_msf();
    reply_put(0);
    reply_put(msf >> 16);
    reply_put(msf >> 8);
    reply_put(msf);
    cd_state.status |= 1;
}

void cmd_87_read_sub_q(void)
{
    uint8_t q[9];
    if (!(cd_state.disc_present & 1)) {
        NO_DISC();
        return;
    }
    cd_build_subq(q);
    reply_put(q[0]);
    reply_put(q[1]);
    reply_put(q[2]);
    reply_put(0);
    reply_put(q[3]);
    reply_put(q[4]);
    reply_put(q[5]);
    reply_put(q[6]);
    reply_put(q[7]);
    reply_put(q[8]);
    cd_state.status |= 1;
}

void cmd_93_ext_id(void)
{
    int dev = ode_get_boot_device();
    uint32_t hi = ode_get_6db4();
    reply_put((dev & 0x0f) | (hi << 4));
    reply_put('F');
    reply_put('Z');
    reply_put('1');
    reply_put('O');
    reply_put('D');
    reply_put('E');
    reply_put(1);
    reply_put(0);
    reply_put(main_get_counter_472c());
    cd_state.status |= 1;
}

void cmd_c0_change_toc(void)
{
    led_activity_on();
    ode_toc_change_dir(cmd_u32(1));
    cd_state.status |= 1;
}

void cmd_c1_get_toc(void)
{
    toc_entry te;
    int i;
    led_activity_on();
    uint32_t idx = cmd_u32(1);
    uint32_t off = cd_state.cmd[5] << 8 | cd_state.cmd[6];
    if (off == 0) {
        memset(tocbuffer, 0xff, 0x800);
        if (ode_toc_read_dir(idx, &te) > 0) {
            tocbuffer[0] = te.flags >> 24;
            tocbuffer[1] = te.flags >> 16;
            tocbuffer[2] = te.flags >> 8;
            tocbuffer[3] = te.flags;
            tocbuffer[4] = te.toc_id >> 24;
            tocbuffer[5] = te.toc_id >> 16;
            tocbuffer[6] = te.toc_id >> 8;
            tocbuffer[7] = te.toc_id;
            te.name_length++;
            tocbuffer[8] = te.name_length >> 24;
            tocbuffer[9] = te.name_length >> 16;
            tocbuffer[10] = te.name_length >> 8;
            tocbuffer[11] = te.name_length;
            for (uint32_t j = off, k = 12; j < te.name_length; j++, k++)
                tocbuffer[k] = te.name[j];
        }
    }
    for (i = 0; i < 16; i++)
        reply_put(tocbuffer[i + off]);
    cd_state.status |= 1;
}

void cmd_c3_clear_playlist(void)
{
    playlist_clear();
}

void cmd_c4_add_playlist(void)
{
    toc_entry te;
    int ok = 0;
    led_activity_on();
    int r = ode_toc_read_dir(cmd_u32(1), &te);
    if (r > 0) {
        ok = image_open(te.name);
        if (ok)
            ok = playlist_add(&g_image_new);
    }
    reply_put(r > 0);
    reply_put(ok > 0);
}

void cmd_c5_launch_playlist(void)
{
    ode_mount_next_image();
    main_request_reset();
}

void cmd_d1_get_toc_list(void)
{
    toc_entry te;
    led_activity_on();
    uint32_t idx = cmd_u32(1);
    int count = cd_state.cmd[5] << 8 | cd_state.cmd[6];
    uint32_t pos = 0;
    memset(tocbuffer, 0xff, 0x800);
    do {
        led_activity_on();
        if (ode_toc_read_dir(idx, &te) <= 0)
            break;
        if (te.name_length + 13 >= 0x800)
            break;
        tocbuffer[pos]     = te.flags >> 24;
        tocbuffer[pos + 1] = te.flags >> 16;
        tocbuffer[pos + 2] = te.flags >> 8;
        tocbuffer[pos + 3] = te.flags;
        tocbuffer[pos + 4] = te.toc_id >> 24;
        tocbuffer[pos + 5] = te.toc_id >> 16;
        tocbuffer[pos + 6] = te.toc_id >> 8;
        tocbuffer[pos + 7] = te.toc_id;
        if (te.flags == 0xffffffff)
            break;
        te.name[127] = 0;
        te.name_length = strlen(te.name) + 1;
        tocbuffer[pos + 8]  = te.name_length >> 24;
        tocbuffer[pos + 9]  = te.name_length >> 16;
        tocbuffer[pos + 10] = te.name_length >> 8;
        tocbuffer[pos + 11] = te.name_length;
        pos += 12;
        for (uint32_t j = 0; j < te.name_length; j++)
            tocbuffer[pos++] = te.name[j];
        idx++;
    } while (--count > 0 && pos < 0x800);
    wait_data_ready();
    fpga_send_data(tocbuffer, 0x800);
    puts("datfifoout");
    cd_state.status |= 1;
}

#define fops_close() do { f_sync(&fops_file); f_close(&fops_file); fops_open = 0; } while (0)

void cmd_e5_close_file(void)
{
    if (fops_open) {
        fops_close();
        printf(" fops file cs ===> %x \n", cd_state.fops_checksum);
    }
}

void cmd_e0_create_file(void)
{
    int ok = 0;
    if (fops_open)
        fops_close();
    uint32_t len = cd_state.cmd[2] << 16 | cd_state.cmd[3];
    if (len < 0x800) {
        fops_buffer[len] = 0;
        if (f_open(&fops_file, (char *)fops_buffer, FA_CREATE_ALWAYS | FA_WRITE) == FR_OK) {
            fops_open = 1;
            ok = 1;
        }
    }
    reply_put(ok);
}

void cmd_e1_open_file(void)
{
    FILINFO fi;
    char *name;
    int ok = 0;
    cd_state.fops_checksum = 0;
    BYTE mode = cd_state.cmd[6] ? (FA_CREATE_ALWAYS | FA_WRITE) : FA_READ;
    if (fops_open)
        fops_close();
    char *cur = ode_get_cur_path();
    if (cd_state.cmd[1] == 0) {
        uint32_t len = cd_state.cmd[2] << 8 | cd_state.cmd[3];
        if (len >= 0x800)
            goto out;
        fops_buffer[len] = 0;
        name = (char *)fops_buffer;
    } else if (cd_state.cmd[1] == 1) {
        if (!dir_get_nth_entry(cmd_u32(2), &fi))
            goto out;
        name = fi.fname;
    } else {
        goto out;
    }
    if (name) {
        snprintf((char *)tocbuffer, 0x800, "%s/%s", cur, name);
        FRESULT r = f_open(&fops_file, (char *)tocbuffer, mode);
        printf("Opening %s, res=%d  ", tocbuffer, r);
        if (r == FR_OK) {
            fops_open = 1;
            ok = 1;
        }
    }
out:
    reply_put(ok);
}

void cmd_e2_seek_file(void)
{
    if (fops_open)
        f_lseek(&fops_file, cmd_u32(1));
}

void cmd_e3_read_file_byte(void)
{
    UINT n = 0;
    if (fops_open) {
        UINT len = cd_state.cmd[1] << 8 | cd_state.cmd[2];
        if (len > 0x800)
            len = 0x800;
        if (f_read(&fops_file, fops_buffer, len, &n) != FR_OK)
            n = 0;
    }
    for (UINT i = 0; i < n; i++)
        cd_state.fops_checksum += fops_buffer[i];
    reply_put(n >> 8);
    reply_put(n);
}

void cmd_e4_write_file_byte(void)
{
    UINT n = 0;
    if (fops_open) {
        UINT len = cd_state.cmd[1] << 8 | cd_state.cmd[2];
        if (len > 0x800)
            len = 0x800;
        FRESULT r = f_write(&fops_file, fops_buffer, len, &n);
        if (r != FR_OK) {
            printf("write %x\n", r);
            n = 0;
        }
    }
    for (UINT i = 0; i < n; i++)
        cd_state.fops_checksum += fops_buffer[i];
    reply_put(n >> 8);
    reply_put(n);
}

void cmd_f0_update_ode(void)
{
    reply_put(ode_stage_firmware_update());
}

void cd_cmd_dispatch(void)
{
    cd_state.cmd_count++;
    if (!cd_recv_command(cd_state.cmd))
        return;
    cd_state.reply_len = 0;
    cd_state.reply_len = 1;
    cd_state.reply[0] = cd_state.cmd[0];
    cd_state.status &= ~0x10;
    if (cd_state.cmd[0] != 0x82)
        cd_state.error = 0;

    switch (cd_state.cmd[0]) {
    case 0x02: cmd_02_spin_up(); break;
    case 0x03: cmd_03_spin_down(); break;
    case 0x06: cmd_06_eject_disc(); break;
    case 0x07: cmd_07_inject_disc(); break;
    case 0x08: cmd_08_abort(); break;
    case 0x09: cmd_09_set_mode(); break;
    case 0x0b: cmd_0b_flush(); break;
    case 0x10: cmd_10_read_data(); break;
    case 0x80: cmd_80_data_path_check(); break;
    case 0x82: cmd_82_read_error(); break;
    case 0x83: cmd_83_read_id(); break;
    case 0x85: cmd_85_read_capacity(); break;
    case 0x87: cmd_87_read_sub_q(); break;
    case 0x8b: cmd_8b_read_disc_info(); break;
    case 0x8c: cmd_8c_read_toc(); break;
    case 0x8d: cmd_8d_read_session(); break;
    case 0x8e: break;               /* read device-ROM driver (Portfolio): status only */
    case 0x93: cmd_93_ext_id(); break;
    case 0xc0: cmd_c0_change_toc(); break;
    case 0xc1: cmd_c1_get_toc(); break;
    case 0xc2: break;               /* GET_DESC: status only */
    case 0xc3: cmd_c3_clear_playlist(); break;
    case 0xc4: cmd_c4_add_playlist(); break;
    case 0xc5: cmd_c5_launch_playlist(); break;
    case 0xd1: cmd_d1_get_toc_list(); break;
    case 0xe0: cmd_e0_create_file(); break;
    case 0xe1: cmd_e1_open_file(); break;
    case 0xe2: cmd_e2_seek_file(); break;
    case 0xe3: cmd_e3_read_file_byte(); break;
    case 0xe4: cmd_e4_write_file_byte(); break;
    case 0xe5: cmd_e5_close_file(); break;
    case 0xe6: cmd_e6_write_buffer_offset(); break;
    case 0xe7: cmd_e7_read_buffer(); break;
    case 0xf0: cmd_f0_update_ode(); break;
    default:
        cd_state.status |= 0x10;
        cd_state.error = 0x17;
        break;
    }
    reply_put(cd_state.status);
    cd_send_reply(cd_state.reply, cd_state.reply_len);
}

void cd_state_init(void)
{
    memset(&cd_state, 0, sizeof(cd_state));
    g_media_flags = 0;
    cd_state.blen = 0x800;
    g_cmd_pending = 0;
    cd_state.status = 0x81;
    gpio_set_irq_enabled_with_callback(PIN_CMD_IRQ, GPIO_IRQ_EDGE_RISE, true, cd_cmd_irq_cb);
}

void cd_state_reset(void)
{
    memset(&cd_state, 0, sizeof(cd_state));
    g_media_flags = 0;
    cd_state.blen = 0x800;
    g_cmd_pending = 0;
    cd_state.status = 0x81;
}

void cd_poll_media_change(void)
{
    image_t *img = ode_get_image();
    g_media_flags |= 1;
    uint8_t present = img->size != 0;
    if (cd_state.disc_present != present) {
        cd_state.disc_present = present;
        if (present)
            cd_state.status |= 0x40;
    }
}

void cd_cmd_poll(void)
{
    if (g_cmd_pending) {
        g_cmd_pending = 0;
        cd_cmd_dispatch();
    }
}
