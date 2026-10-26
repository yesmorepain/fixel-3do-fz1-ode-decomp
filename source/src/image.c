/*
 * Disc image loaders. image_open() opens a file into g_image_new and fills its TOC;
 * the loader is chosen by extension: ISO (2048-byte sectors) and CUE/BIN are implemented,
 * NRG and CCD are recognised but not supported.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "piode2.h"

image_t g_image_new;
static char cue_line[0x200];
static char cue_bin_path[0x200];

/* non-static on purpose: the original keeps this pointer in .data (0x20000574) */
const char *image_exts = "ISONRGCCDCUE";
/* loader index for each character offset in image_exts */
static const uint8_t image_ext_loader[12] = { 1, 1, 1, 4, 4, 4, 3, 3, 3, 2, 2, 2 };

static int image_open_none(char *path) { return 0; }
static int image_open_nrg(char *path) { return 0; }
static int image_open_ccd(char *path) { return 0; }

/* sector 0 starts with the Opera volume header: 01 5A 5A 5A 5A 5A 01 */
int image_is_3do(void)
{
    uint8_t buf[32];
    uint8_t *p;
    if (g_image_new.last_track > 1)
        return 0;
    if (!image_read_sector(&g_image_new, 0, buf, sizeof(buf)))
        return 0;
    if (g_image_new.sector_size == 0x800)
        p = buf;
    else if (g_image_new.sector_size == 0x930)
        p = buf + 16;
    else
        return 0;
    const uint8_t hdr[7] = { 0x01, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x01 };
    if (memcmp(p, hdr, 7) == 0)
        return 1;
    return 0;
}


static int image_open_iso(char *path)
{
    g_image_new.sector_size = 0x800;
    g_image_new.size = g_image_new.fil.obj.objsize;
    lba_to_msf(g_image_new.size >> 11, g_image_new.leadout);
    g_image_new.disc_type = 0;
    g_image_new.first_track = 1;
    g_image_new.last_track = 1;
    g_image_new.toc[8 + 5] = 0;     /* track 1 at 00:02:00 */
    g_image_new.toc[8 + 6] = 2;
    g_image_new.toc[8 + 7] = 0;
    g_image_new.toc[8 + 2] = 4;     /* data track */
    g_image_new.toc[8 + 3] = 1;
    g_image_new.mode = 1;
    if (!image_is_3do()) {
        f_close(&g_image_new.fil);
        g_image_new.first_track = 0;
        g_image_new.last_track = 0;
        return 0;
    }
    return image_is_3do();
}

static int image_open_cue(char *path)
{
    FIL cue = g_image_new.fil;
    char *p, *q;
    int err;
    if (cue.obj.objsize > 2000)
        return 0;
    while (f_gets(cue_line, sizeof(cue_line), &cue)) {
        if ((p = strstr(cue_line, "FILE"))) {
            int quotes = 0;
            for (uint32_t i = 0; i < strlen(cue_line); i++)
                if (cue_line[i] == '"')
                    quotes++;
            if (quotes != 2 && quotes != 0) {
                err = 1;
                goto out;
            }
            p = strchr(cue_line, ' ');
            if (!p) {
                err = 1;
                goto out;
            }
            char *name = p + 1;
            if (quotes == 0) {
                q = strchr(name, ' ');
            } else {
                name = p + 2;
                q = strchr(name, '"');
            }
            *q = 0;
            g_image_new.first_track = 1;
            g_image_new.last_track = 0;
            if (f_open(&g_image_new.fil, name, FA_READ) != FR_OK) {
                /* try the .cue's own name with the referenced file's extension */
                strncpy(cue_bin_path, path, sizeof(cue_bin_path));
                cue_bin_path[strlen(path) - 3] = name[strlen(name) - 3];
                cue_bin_path[strlen(path) - 2] = name[strlen(name) - 2];
                cue_bin_path[strlen(path) - 1] = name[strlen(name) - 1];
                if (f_open(&g_image_new.fil, cue_bin_path, FA_READ) != FR_OK) {
                    err = 1;
                    goto out;
                }
            }
            g_image_new.size = g_image_new.fil.obj.objsize;
        } else if ((p = strstr(cue_line, "TRACK"))) {
            p = strchr(p, ' ');
            if (!p)
                break;
            q = strchr(p + 1, ' ');
            *q = 0;
            if (++g_image_new.last_track > 100)
                break;
            uint32_t t = g_image_new.last_track;
            g_image_new.toc[8 * t + 3] = atoi(p + 1);
            q++;
            if ((p = strstr(q, "MODE"))) {
                if (p[4] == '1') {
                    g_image_new.mode = 1;
                    g_image_new.disc_type = 0;
                    g_image_new.toc[8 * t + 2] = 4;
                } else if (p[4] == '2') {
                    g_image_new.mode = 3;
                    g_image_new.disc_type = 0x20;
                    g_image_new.toc[8 * t + 2] = 4;
                } else {
                    g_image_new.mode = 0;
                }
                if (g_image_new.sector_size == 0) {
                    g_image_new.sector_size = atoi(p + 6);      /* MODEx/2352 */
                    lba_to_msf(g_image_new.size / g_image_new.sector_size, g_image_new.leadout);
                    printf("calc1 %d %d %d\n", g_image_new.leadout[0], g_image_new.leadout[1],
                           g_image_new.leadout[2]);
                    uint32_t lba = g_image_new.size / g_image_new.sector_size + 150;
                    g_image_new.leadout[0] = lba / 4500;
                    g_image_new.leadout[1] = (lba % 4500) / 75;
                    g_image_new.leadout[2] = (lba % 4500) % 75;
                    printf("calc2 %d %d %d\n", g_image_new.leadout[0], g_image_new.leadout[1],
                           g_image_new.leadout[2]);
                }
            } else if (strstr(q, "AUDIO") || strstr(q, "CDDA")) {
                g_image_new.mode = 2;
                g_image_new.disc_type = 0;
                g_image_new.sector_size = 0x930;
                g_image_new.toc[8 * t + 2] = 0x12;
                lba_to_msf(g_image_new.size / g_image_new.sector_size, g_image_new.leadout);
            } else {
                break;
            }
        } else if ((p = strstr(cue_line, "INDEX"))) {
            printf("%s", cue_line);
            p = strstr(cue_line, "INDEX");
            p = strchr(p, ' ');
            if (!p)
                break;
            q = strchr(p + 1, ' ');
            *q = 0;
            if (atoi(p + 1) != 1)
                break;
            p = strchr(q + 1, ':');
            *p = 0;
            g_image_new.toc[8 * g_image_new.last_track + 5] = atoi(q + 1);
            q = strchr(p + 1, ':');
            *q = 0;
            g_image_new.toc[8 * g_image_new.last_track + 6] = atoi(p + 1);
            uint32_t t = g_image_new.last_track;
            g_image_new.toc[8 * t + 7] = atoi(q + 1);
            if (t == 1 && g_image_new.toc[8 + 6] == 0)
                g_image_new.toc[8 + 6] = 2;     /* 2 s pregap */
        }
    }
    err = 0;
out:
    f_close(&cue);
    if (err)
        return 0;
    int r = image_is_3do();
    printf("Loaded cue/bin.. is 3do()=%d\n", r);
    return 1;
}

static int (*const image_loaders[])(char *path) = {
    image_open_none, image_open_iso, image_open_cue, image_open_ccd, image_open_nrg,
};

int image_open(char *path)
{
    char ext[4];
    int n = strlen(path);
    ext[0] = toupper((unsigned char)path[n - 3]);
    ext[1] = toupper((unsigned char)path[n - 2]);
    ext[2] = toupper((unsigned char)path[n - 1]);
    ext[3] = 0;
    const char *tbl = image_exts;
    char *hit = strstr(tbl, ext);
    uint32_t loader = hit ? image_ext_loader[hit - tbl] : 0;
    memset(&g_image_new, 0, sizeof(g_image_new));
    if (f_open(&g_image_new.fil, path, FA_READ) != FR_OK)
        return 0;
    if (!image_loaders[loader](path)) {
        memset(&g_image_new, 0, sizeof(g_image_new));
        f_close(&g_image_new.fil);
        return 0;
    }
    return 1;
}
