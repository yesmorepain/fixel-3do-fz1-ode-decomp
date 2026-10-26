/*
 * ODE media layer: mounting /sd and /usb, boot.iso, the directory "TOC" the 3DO menu browses,
 * the multi-disc playlist, sector reads for READ_DATA, and staging firmware updates.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hardware/structs/watchdog.h"
#include "hardware/watchdog.h"
#include "piode2.h"
#include "diskio.h"

FIL     g_file;                 /* boot.iso when it is mounted directly */
static FATFS g_fs_sd, g_fs_usb;
image_t g_image;
static struct {
    uint32_t used;
    uint32_t _4;
    image_t img;
} g_playlist[5];
static DIR g_dir;
static FILINFO g_fno;
static int g_toc_dir;           /* -1: at the device list (both media mounted) */
static int g_toc_level;         /* directory depth below the device root */
char    g_cur_path[0x800];
uint8_t g_sector_buf[0x9c4];
uint8_t tocbuffer[0x800];
static uint32_t g_ode_ready;
static uint32_t g_mount_tick;
static int g_boot_device;       /* bit0 /sd mounted, bit1 /usb mounted */
static uint32_t g_pl_cur;
static uint32_t g_ext_dev;      /* reported in EXT_ID: 1 = sd, 2 = usb */
static uint32_t g_unmount;      /* bit0 sd, bit1 usb removed */
static uint8_t g_media_src;     /* 0 none, 1 flash, 2 playlist image, 3 g_file */

/* non-static: in .data in the original (0x20000578) */
const char *g_menu_exts[] = { "iso", "cue", "nvm", "ode", NULL };
int g_toc_last = -1;              /* 0x2000058c: written, never read (non-static so it stays in .data) */
/* optional disc image linked into flash (bitstream.S); empty in the original build */
extern const uint8_t ode_flash_image[], ode_flash_image_end[];

int msf_compare(uint8_t *a, uint8_t *b)
{
    if (!a)
        return 0;
    if (!b)
        return 0;
    if (a[0] > b[0])
        return 1;
    if (a[0] < b[0])
        return -1;
    if (a[1] > b[1])
        return 1;
    if (a[1] < b[1])
        return -1;
    if (a[2] > b[2])
        return 1;
    if (a[2] < b[2])
        return -1;
    return 0;
}

/* track containing msf (the original loop runs i upwards, so only the last track is really tested) */
static int toc_track_for_msf(uint8_t *msf)
{
    uint8_t n = g_image.last_track;
    for (int i = n - 1; i >= 0; n--, i++) {
        uint8_t t[3];
        t[2] = g_image.toc[8 * (i + 1) + 7];
        t[1] = g_image.toc[8 * (i + 1) + 6];
        t[0] = g_image.toc[8 * (i + 1) + 5];
        if (msf_compare(msf, t) >= 0)
            return n;
    }
    return 0;
}

static int ext_is_supported(const char *ext)
{
    for (int i = 0; g_menu_exts[i]; i++)
        if (strcasecmp(ext, g_menu_exts[i]) == 0)
            return 1;
    return 0;
}

static char *filinfo_get_ext(FILINFO *fi)
{
    if (!fi)
        return NULL;
    int n = strlen(fi->fname);
    if (fi->fname[n - 4] == '.')
        return &fi->fname[n - 3];
    return NULL;
}

/* 1 = hide from the menu */
int ode_dir_list_filter(FILINFO *fi)
{
    if (!fi)
        return 1;
    int n = strlen(fi->fname);
    char *ext = fi->fname[n - 4] == '.' ? &fi->fname[n - 3] : NULL;
    BYTE a = fi->fattrib;
    if (a & (AM_HID | AM_SYS))
        return 1;
    /* sic: compares the global g_fno, not fi */
    if ((a & AM_DIR) && strcasecmp(g_fno.fname, "System Volume Information") == 0)
        return 1;
    if (fi->fname[0] == '.')
        return 1;
    if (fi->fname[0] == '_')
        return 1;
    if (a & AM_DIR)
        return 0;
    if (!ext)
        return 0;
    if (!ext_is_supported(ext))
        return 1;
    return 0;
}

void lba_to_msf(uint32_t lba, uint8_t *msf)
{
    if (!msf)
        return;
    msf[0] = (lba + 150) / 4500;
    msf[1] = ((lba + 150) % 4500) / 75;
    msf[2] = ((lba + 150) % 4500) % 75;
}

int msf_to_lba(uint8_t *msf)
{
    if (!msf)
        return -1;
    return msf[2] + msf[1] * 75 + msf[0] * 4500 - 150;
}

void ode_media_init(void)
{
    g_ode_ready = 0;
    g_boot_device = 0;
    g_media_src = 0;
    g_unmount = 0;
    g_ext_dev = 0;
    memset(&g_image, 0, sizeof(g_image));
    g_ode_ready = 1;
    uint32_t sz = ode_flash_image_end - ode_flash_image;
    if (sz > 1000) {
        g_image.mode = 1;
        g_image.size = sz;
        g_image.sector_size = 0x800;
        g_image.first_track = 1;
        g_image.last_track = 1;
        g_image.toc[8 + 2] = 4;
        g_image.toc[8 + 3] = 1;
        g_image.toc[8 + 6] = 2;
        g_image.leadout[1] = 2;     /* sic: fixed leadout bytes, not computed from sz */
        g_image.leadout[2] = 1;
        g_ext_dev = 4;              /* flash */
        g_media_src = 1;
    }
}

void ode_nop(void)
{
}

int ode_get_boot_device(void)
{
    return g_boot_device;
}

/* g_file holds boot.iso: describe it in g_image as a one-track 2048-byte image */
static inline __attribute__((always_inline)) void mount_boot_file(uint32_t dev)
{
    uint32_t sz = g_file.obj.objsize;
    g_image.pos = 0;
    g_image.size = sz;
    uint32_t lba = (sz >> 11) + 150;
    g_image.disc_type = 0;
    g_image.mode = 1;
    g_image.first_track = 1;
    g_image.last_track = 1;
    g_image.toc[8 + 2] = 4;
    g_image.toc[8 + 3] = 1;
    g_image.toc[8 + 5] = 0;
    g_image.toc[8 + 6] = 2;
    g_image.toc[8 + 7] = 0;
    g_image.leadout[0] = lba / 4500;
    g_image.leadout[1] = (lba % 4500) / 75;
    g_image.leadout[2] = (lba % 4500) % 75;
    g_image.sector_size = 0x800;
    g_media_src = 3;
    g_ext_dev = dev;
    printf("image mounted  sz %x (%.2d:%.2d.%.2d\n", sz, g_image.leadout[0], g_image.leadout[1],
           g_image.leadout[2]);
}

/* main loop: every 200 ms, mount/unmount /usb and /sd and open boot.iso on the first one */
void ode_mount_media(void)
{
    DIR d;
    if (abs((int)(g_ticks - g_mount_tick)) > 199) {
        g_mount_tick = g_ticks;
        uint8_t st = usb_disk_status();
        if (!(g_boot_device & 2) && !(st & STA_NODISK)) {
            FRESULT r = f_mount(&g_fs_usb, "/usb", 1);
            if (r == FR_OK) {
                if (f_opendir(&d, "/usb/") == FR_OK) {
                    g_boot_device |= 2;
                    puts("usb mounted");
                    f_closedir(&d);
                    if (!g_media_src) {
                        f_chdrive("/usb");
                        f_chdir("/usb");
                        memcpy(g_cur_path, "/usb", 5);
                        if (f_open(&g_file, "/usb/boot.iso", FA_READ) == FR_OK) {
                            mount_boot_file(2);
                            main_request_reset();
                        }
                    }
                }
            } else {
                printf("/usb mount err %x\n", r);
            }
        } else if ((g_boot_device & 2) && (st & STA_NODISK)) {
            g_boot_device &= ~2;
            g_unmount |= 2;
        }
    }
    if (!(g_boot_device & 1) && sd_card_detect_state() == 1 && f_mount(&g_fs_sd, "/sd", 1) == FR_OK) {
        g_boot_device |= 1;
        if (f_opendir(&d, "/sd/") == FR_OK) {
            f_closedir(&d);
            puts("sd mounted");
            if (!g_media_src) {
                memcpy(g_cur_path, "/sd", 4);
                f_chdrive("/sd");
                f_chdir("/sd");
                memcpy(g_cur_path, "/sd", 4);
                if (f_open(&g_file, "/sd/boot.iso", FA_READ) == FR_OK)
                    mount_boot_file(1);
            }
        }
    }
    if ((g_boot_device & 1) && sd_card_detect_state() == 2) {
        g_boot_device &= ~1;
        g_unmount |= 1;
    }
    if (g_unmount) {
        if (g_unmount & 1) {
            g_media_src = 0;
            f_close(&g_file);
            f_mount(NULL, "/sd", 0);
            puts("sd unmounted");
        }
        if (g_unmount & 2) {
            g_media_src = 0;
            f_close(&g_file);
            f_mount(NULL, "/usb", 0);
            puts("usb unmounted");
        }
        g_unmount = 0;
    }
}

/* leadout as 0x00MMSSFF */
uint32_t toc_get_leadout_msf(void)
{
    return g_image.leadout[0] << 16 | g_image.leadout[1] << 8 | g_image.leadout[2];
}

/* READ_SUB_Q payload: ctrl/adr, track, index, relative msf, absolute msf (both = current) */
void cd_build_subq(uint8_t *q)
{
    if (!q)
        return;
    q[0] = 0x12;
    q[2] = 1;
    q[1] = toc_track_for_msf(&g_image._273[0]);
    memcpy(q + 3, &g_image._273[0], 3);
    memcpy(q + 6, &g_image._273[0], 3);
}

image_t *ode_get_image(void)
{
    return &g_image;
}

uint32_t ode_get_6db4(void)
{
    return g_ext_dev;
}

uint8_t *ode_get_sector_buf(void)
{
    return g_sector_buf;
}

char *ode_get_cur_path(void)
{
    return g_cur_path;
}

static void ode_cd(char *name)
{
    printf("\n >> cd from %s\n", g_cur_path);
    if (strcasecmp(name, "..") == 0) {
        int i = strlen(g_cur_path);
        while (--i >= 0) {
            if (g_cur_path[i] == '/') {
                g_cur_path[i] = 0;
                break;
            }
        }
        printf(">> New .. path %s\n", g_cur_path);
        f_chdir(g_cur_path);
    } else {
        memcpy(g_cur_path + strlen(g_cur_path), "/", 2);
        strncat(g_cur_path, name, 0x7ff);
        f_chdir(name);
        printf(">> New path %s\n", g_cur_path);
    }
}

void ode_mount_boot_iso(void)
{
    playlist_clear();
    if (f_open(&g_file, "/sd/boot.iso", FA_READ) == FR_OK)
        mount_boot_file(2);
    else if (f_open(&g_file, "/usb/boot.iso", FA_READ) == FR_OK)
        mount_boot_file(1);
}

void ode_mount_next_image(void)
{
    f_close(&g_file);
    if (!playlist_next(&g_image)) {
        puts("No more pl");
        g_media_src = 1;
        ode_mount_boot_iso();
    } else {
        printf("next image mounted  sz %x (%.2d:%.2d.%.2d)\n", g_image.size, g_image.leadout[0],
               g_image.leadout[1], g_image.leadout[2]);
        g_media_src = 2;
    }
}

/* n-th visible entry (1-based) of the current directory */
int dir_get_nth_entry(int n, FILINFO *fi)
{
    DIR dir;
    if (!n || !fi || f_opendir(&dir, ".") != FR_OK)
        return 0;
    int i = 1;
    while (f_readdir(&dir, fi) == FR_OK) {
        if (fi->fname[0] == 0)
            goto done;
        if (!ode_dir_list_filter(fi)) {
            if (i == n)
                goto done;
            i++;
        }
    }
    return 0;
done:
    f_closedir(&dir);
    return fi->fname[0] != 0;
}

/* C0: enter toc entry id (directory), -1 = "..", at the device list 1 = /sd, 2 = /usb */
void ode_toc_change_dir(uint32_t id)
{
    if (!g_boot_device)
        return;
    if (id == 0 && g_boot_device == 3) {
        puts("toc_ch Special case -- devs");
        g_toc_dir = -1;
        return;
    }
    if (g_toc_dir == -1) {
        if (id == 1) {
            g_toc_dir = 0;
            FRESULT r = f_chdrive("/sd");
            f_chdir("/sd");
            printf("toc_ch /sd/ %x\n", r);
            g_toc_level = 1;
            memcpy(g_cur_path, "/sd", 4);
            return;
        }
        if (id == 2) {
            g_toc_dir = 0;
            FRESULT r = f_chdrive("/usb");
            f_chdir("/usb");
            printf("toc_ch /usb/ %x\n", r);
            g_toc_level = 1;
            memcpy(g_cur_path, "/usb", 5);
            return;
        }
    }
    if (id == 0xffffffff) {
        ode_cd("..");
        printf("toc_ch .. cur %d\n", g_toc_level);
        g_toc_dir = 0;
        if (g_toc_level == 1) {
            if (g_boot_device == 3)
                g_toc_dir = -1;
            g_toc_level = 0;
        } else if (g_toc_level < 1) {
            g_toc_level = 0;
            if (g_boot_device == 3)
                g_toc_dir = -1;
        } else {
            g_toc_level--;
        }
    } else {
        FRESULT r = f_opendir(&g_dir, ".");
        if (r != FR_OK) {
            printf("toc change err1 %x\n", r);
        } else if (dir_get_nth_entry(id, &g_fno)) {
            printf("Seeking %x %s\n", id, g_fno.fname);
            if (g_fno.fattrib & AM_DIR) {
                g_toc_level++;
                g_toc_dir = id;
                ode_cd(g_fno.fname);
                g_toc_last = -1;
                printf("toc_ch %s lvl %d\n", g_fno.fname, g_toc_level);
                f_closedir(&g_dir);
            }
        }
    }
    return;
}

/* C1/C4/D1: describe toc entry idx of the current directory (0 = "..") */
int ode_toc_read_dir(uint32_t idx, toc_entry *te)
{
    if (!te)
        return 0;
    te->flags = TOC_FLAG_INVALID;
    if (!g_boot_device)
        return 1;
    if (g_toc_dir + 1 == 0 && g_boot_device == 3) {
        if (idx == 0) {
            te->flags = TOC_FLAG_DIR;
            te->toc_id = 1;
            te->name = "/sd";
            te->name_length = 4;
            puts("toc_rd /sd");
        } else if (idx == 1) {
            te->flags = TOC_FLAG_DIR;
            te->toc_id = 2;
            te->name = "/usb";
            puts("toc_rd /usb");
            te->name_length = strlen(te->name) + 1;
        } else {
            te->name_length = 0xffffffff;
        }
        return 1;
    }
    if (idx == 0) {
        te->flags = TOC_FLAG_DIR;
        te->toc_id = 0xffffffff;
        te->name = "..";
        printf("toc_rd .. lvl %d\n", g_toc_level);
        te->name_length = strlen(te->name) + 1;
        return 1;
    }
    if (!dir_get_nth_entry(idx, &g_fno))
        return -1;
    uint32_t f = (g_fno.fattrib & AM_DIR) ? TOC_FLAG_DIR : TOC_FLAG_FILE;
    te->flags = f;
    char *ext;
    if ((f & TOC_FLAG_FILE) && (ext = filinfo_get_ext(&g_fno))) {
        if (strcasecmp(ext, "NVM") == 0)
            te->flags = f | 8;
        if (strcasecmp(ext, "ODE") == 0)
            te->flags |= 0x10;
    }
    te->toc_id = idx;
    te->name_length = strlen(g_fno.fname);
    te->name = g_fno.fname;
    return 1;
}

uint32_t image_read_sector(image_t *img, uint32_t lba, void *buf, uint32_t len)
{
    UINT br;
    if (!buf)
        return 0;
    if (!img)
        return 0;
    if (img->size <= img->sector_size * lba)
        return 0;
    if (f_lseek(&img->fil, img->sector_size * lba) != FR_OK)
        return 0;
    if (f_read(&img->fil, buf, len, &br) != FR_OK)
        return 0;
    return br;
}

/* READ_DATA: fetch the sector at msf into g_sector_buf, returns its length */
uint32_t ode_read_sector_msf(uint8_t *msf)
{
    UINT br;
    uint8_t src = g_media_src;
    if (!src)
        return 0;
    int lba = msf_to_lba(msf);
    uint32_t n = g_image.sector_size;
    uint32_t pos = n * lba;
    g_image.pos = pos;
    memcpy(&g_image._273[0], msf, 3);
    if (src == 2) {
        return image_read_sector(&g_image, lba, g_sector_buf, n);
    } else if (src == 3) {
        f_lseek(&g_file, pos);
        f_read(&g_file, g_sector_buf, g_image.sector_size, &br);
        return br;
    } else if (src == 1) {
        memcpy(g_sector_buf, ode_flash_image + pos, n);
        return n;
    }
    return 0;
}

/* F0: check that update.ode exists, then arm the bootloader and let the watchdog reset */
int ode_stage_firmware_update(void)
{
    FIL fil;
    watchdog_hw->scratch[2] = 0xbeef0000;
    switch (g_boot_device) {
    case 1:
        watchdog_hw->scratch[2] |= 1;
        break;
    case 2:
        watchdog_hw->scratch[2] |= 2;
        break;
    case 3:
        watchdog_hw->scratch[2] |= g_cur_path[1] == 'u' ? 2 : 1;
        break;
    default:
        return 0;
    }
    switch (watchdog_hw->scratch[2] & 0xff) {
    case 1:
        if (f_open(&fil, "/sd/update.ode", FA_READ) != FR_OK)
            return 0;
        break;
    case 2:
        if (f_open(&fil, "/usb/update.ode", FA_READ) != FR_OK)
            return 0;
        break;
    }
    f_close(&fil);
    printf("Updating from %x\n", watchdog_hw->scratch[2]);
    watchdog_hw->scratch[0] = 0xfeedface;
    watchdog_hw->scratch[1] = 0xdeadf00d;
    watchdog_enable(1000, 1);
    return 1;
}

void playlist_clear(void)
{
    memset(g_playlist, 0, sizeof(g_playlist));
    g_pl_cur = 0;
}

int playlist_add(image_t *img)
{
    int i;
    if (!img)
        return 0;
    for (i = 0; i < 5 && g_playlist[i].used; i++)
        ;
    if (i >= 5)
        return 0;
    g_playlist[i].used = 1;
    memcpy(&g_playlist[i].img, img, sizeof(image_t));
    return 1;
}

int playlist_next(image_t *img)
{
    image_t *found = NULL;
    int tries = 0;
    do {
        if (g_playlist[g_pl_cur].used)
            found = &g_playlist[g_pl_cur].img;
        g_pl_cur = (g_pl_cur + 1) % 5;
        if (++tries > 5)
            return 0;
    } while (!found);
    memcpy(img, found, sizeof(image_t));
    return 1;
}
