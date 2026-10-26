/*
 * piode2 v0.1 - 3DO FZ-1 internal ODE firmware (RP2040 + iCE5LP4K FPGA).
 * Reconstructed from the original update.ode (Aug 20 2022). Names are ours.
 */
#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "ff.h"

/* ---------------------------------------------------------------- pins */
#define PIN_SD_CS       5       /* SPI0 CS, SD card                                    */
#define PIN_FPGA_CS     9       /* SPI1 CS, FPGA command/data port                     */
#define PIN_FPGA_DONE   13      /* iCE40 CDONE: low = FPGA lost its configuration      */
#define PIN_FPGA_RESET  14      /* iCE40 CRESET_B                                      */
#define PIN_CARD_DET    19      /* sampled every 10 ms (low = active)                  */
#define PIN_DATA_READY  20      /* FPGA: data FIFO can take a sector                   */
#define PIN_CMD_IRQ     21      /* FPGA: command packet waiting (rising edge)          */
#define PIN_FPGA_CTRL   22      /* pulsed on abort / read timeout                      */
#define PIN_LED         25
#define PIN_BUTTON      28      /* low = pressed                                       */

/* ---------------------------------------------------------------- CD drive state */
typedef struct {
    uint8_t  status;            /* 0x00 3DO drive status (bit0 ready, 0x10 CHECK_ERROR, 0x40 disc changed) */
    uint8_t  error;             /* 0x01 */
    uint8_t  reply_len;         /* 0x02 */
    uint8_t  disc_present;      /* 0x03 */
    uint8_t  _04[8];
    uint8_t  cmd[7];            /* 0x0c command packet from the FPGA */
    uint8_t  reply[33];         /* 0x13 [echo, data..., status] */
    uint8_t  density;           /* 0x34 MODE SELECT page 0 */
    uint8_t  flags;             /* 0x35 bit7: +1 byte, bit6: +0x60 bytes per sector */
    uint16_t blen;              /* 0x36 block length 0x800 / 0x930 */
    uint8_t  _38[4];
    uint8_t  err_mode;          /* 0x3c page 1 */
    uint8_t  err_count;         /* 0x3d */
    uint8_t  stop_time;         /* 0x3e page 2 */
    uint8_t  _3f;
    uint8_t  speed;             /* 0x40 page 3 */
    uint8_t  _41;
    uint16_t pitch;             /* 0x42 */
    uint8_t  chunk;             /* 0x44 page 4 */
    uint8_t  _45[11];
    uint32_t cmd_count;         /* 0x50 */
    uint32_t cdda_mode;         /* 0x54 FPGA in audio mode */
    uint32_t fops_checksum;     /* 0x58 byte sum of file-op transfers */
} cd_state_t;                   /* 0x5c */

extern cd_state_t cd_state;
extern volatile uint32_t g_cmd_pending;
extern uint32_t g_media_flags;

static inline void reply_put(uint8_t b) { cd_state.reply[cd_state.reply_len++] = b; }

/* ---------------------------------------------------------------- disc images */
typedef struct {
    uint32_t pos;               /* 0x000 byte offset of the current sector */
    uint32_t _004;
    FIL      fil;               /* 0x008 */
    uint32_t sector_size;       /* 0x268 0x800 or 0x930 */
    uint32_t size;              /* 0x26c */
    union {                     /* 0x270: disc info, then 8-byte track records at toc[8 * n] */
        struct {
            uint8_t leadout[3]; /* 0x270 m s f */
            uint8_t _273[3];
            uint8_t disc_type;  /* 0x276 0x00 / 0x20 (mode 2) */
            uint8_t first_track;/* 0x277 */
            uint8_t last_track; /* 0x278 */
        };
        uint8_t toc[0x334];     /* track n: [8n+2] ctrl/adr, [8n+3] track no, [8n+5..7] m s f */
    };
    uint32_t mode;              /* 0x5a4 1 = mode1, 2 = audio, 3 = mode2 */
} image_t;                      /* 0x5a8 */

/* directory entry for the ODE menu (Fixel's toc_entry, see docs/satato3do/TOC.h) */
#define TOC_FLAG_FILE      0x1
#define TOC_FLAG_DIR       0x2
#define TOC_FLAG_INVALID   0xffffffff
typedef struct {
    uint32_t flags;
    uint32_t toc_id;            /* local toc id */
    uint32_t name_length;       /* strlen */
    char    *name;              /* 0 terminated */
} toc_entry;

extern image_t g_image;         /* mounted image */
extern image_t g_image_new;     /* being opened (image_open) */
extern FIL     g_file;
extern uint8_t g_sector_buf[];
extern uint8_t tocbuffer[0x800];
extern volatile uint32_t g_ticks;   /* ms, +10 every timer tick */

/* ---------------------------------------------------------------- prototypes */
/* main.c */
void main_request_reset(void);
uint32_t main_get_counter_472c(void);
void sd_spi_set_fast(int fast);
void led_activity_on(void);
int  btn_gpio28_pressed(void);
int  sd_card_detect_state(void);
/* fpga.c */
int  fpga_init(void);
int  cd_recv_command(uint8_t *cmd);
void cd_send_reply(uint8_t *buf, uint32_t len);
uint8_t fpga_read_status(void);
void fpga_send_data(uint8_t *buf, uint32_t len);
void fpga_write_ctrl(uint8_t v);
/* image.c */
int  image_is_3do(void);
int  image_open(char *path);
/* cdrom.c */
void cd_cmd_dispatch(void);
void cd_state_init(void);
void cd_state_reset(void);
void cd_poll_media_change(void);
void cd_cmd_poll(void);
/* ode.c */
int  msf_compare(uint8_t *a, uint8_t *b);
void lba_to_msf(uint32_t lba, uint8_t *msf);
int  msf_to_lba(uint8_t *msf);
int  ode_dir_list_filter(FILINFO *fi);
void ode_media_init(void);
void ode_nop(void);
int  ode_get_boot_device(void);
void ode_mount_media(void);
uint32_t toc_get_leadout_msf(void);
void cd_build_subq(uint8_t *q);
image_t *ode_get_image(void);
uint32_t ode_get_6db4(void);
uint8_t *ode_get_sector_buf(void);
char *ode_get_cur_path(void);
void ode_mount_boot_iso(void);
void ode_mount_next_image(void);
int  dir_get_nth_entry(int n, FILINFO *fi);
void ode_toc_change_dir(uint32_t id);
int  ode_toc_read_dir(uint32_t idx, toc_entry *e);
uint32_t image_read_sector(image_t *img, uint32_t lba, void *buf, uint32_t len);
uint32_t ode_read_sector_msf(uint8_t *msf);
int  ode_stage_firmware_update(void);
void playlist_clear(void);
int  playlist_add(image_t *img);
int  playlist_next(image_t *img);
/* buttons.c */
typedef struct button button_t;
#include "buttons.h"
typedef void (*button_cb_t)(button_t *b);
void buttons_init(void);
void buttons_process(void);
void buttons_tick(void);
int  button_register(button_t *desc, button_cb_t cb, uint32_t events);
/* diskio back ends (mmc_spi.c, usb_msc.c) */
#include "diskio.h"
DSTATUS mmc_disk_initialize(void);
DSTATUS mmc_disk_status(void);
DRESULT mmc_disk_read(BYTE *buff, LBA_t sector, UINT count);
DRESULT mmc_disk_write(const BYTE *buff, LBA_t sector, UINT count);
DRESULT mmc_disk_ioctl(BYTE cmd, void *buff);
void mmc_power_on(void);
DSTATUS usb_disk_initialize(void);
DSTATUS usb_disk_status(void);
DRESULT usb_disk_read(BYTE *buff, LBA_t sector, UINT count);
DRESULT usb_disk_write(const BYTE *buff, LBA_t sector, UINT count);
DRESULT usb_disk_ioctl(BYTE cmd, void *buff);
void usb_disk_set_nodisk(void);
void usb_msc_service_request(uint32_t req, void *blk);
