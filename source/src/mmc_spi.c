/*
 * SD card over SPI0 (CS = GPIO5): ChaN's generic MMC/SDC driver from the FatFs samples,
 * with Fixel's changes (settling delays around CS, debug prints, a 10 ms repeating timer).
 */
#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "ff.h"
#include "diskio.h"
#include "piode2.h"

/* MMC/SD commands */
#define CMD0    (0)             /* GO_IDLE_STATE */
#define CMD1    (1)             /* SEND_OP_COND (MMC) */
#define ACMD41  (0x80 + 41)     /* SEND_OP_COND (SDC) */
#define CMD8    (8)             /* SEND_IF_COND */
#define CMD9    (9)             /* SEND_CSD */
#define CMD10   (10)            /* SEND_CID */
#define CMD12   (12)            /* STOP_TRANSMISSION */
#define ACMD13  (0x80 + 13)     /* SD_STATUS (SDC) */
#define CMD16   (16)            /* SET_BLOCKLEN */
#define CMD17   (17)            /* READ_SINGLE_BLOCK */
#define CMD18   (18)            /* READ_MULTIPLE_BLOCK */
#define ACMD23  (0x80 + 23)     /* SET_WR_BLK_ERASE_COUNT (SDC) */
#define CMD24   (24)            /* WRITE_BLOCK */
#define CMD25   (25)            /* WRITE_MULTIPLE_BLOCK */
#define CMD32   (32)            /* ERASE_ER_BLK_START */
#define CMD33   (33)            /* ERASE_ER_BLK_END */
#define CMD38   (38)            /* ERASE */
#define CMD55   (55)            /* APP_CMD */
#define CMD58   (58)            /* READ_OCR */

/* card type flags */
#define CT_MMC3     0x01
#define CT_MMC4     0x02
#define CT_MMC      0x03
#define CT_SDC1     0x04
#define CT_SDC2     0x08
#define CT_SDC      0x0c
#define CT_BLOCK    0x10

#define MMC_GET_TYPE    10
#define MMC_GET_CSD     11
#define MMC_GET_CID     12
#define MMC_GET_OCR     13
#define MMC_GET_SDSTAT  14

static volatile DSTATUS Stat = STA_NOINIT;
static volatile UINT Timer1, Timer2;    /* 10 ms decrement timers (ms) */
static BYTE CardType;
static repeating_timer_t mmc_timer;
static int mmc_timer_started;

bool mmc_disk_timerproc(repeating_timer_t *t)
{
    UINT n = Timer1;
    Timer1 = n >= 10 ? n - 10 : 0;
    n = Timer2;
    Timer2 = n >= 10 ? n - 10 : 0;
    return true;    /* the original falls off the end here */
}

void mmc_power_on(void)
{
    gpio_set_dir(24, GPIO_OUT);         /* card power? */
    gpio_put(24, 1);
    gpio_put(PIN_SD_CS, 1);
    sd_spi_set_fast(0);
    if (!mmc_timer_started)
        alarm_pool_add_repeating_timer_us(alarm_pool_get_default(), -10000, mmc_disk_timerproc, NULL, &mmc_timer);
    mmc_timer_started = 1;
}

static BYTE xchg_spi(BYTE dat)
{
    BYTE r;
    spi_write_read_blocking(spi0, &dat, &r, 1);
    return r;
}

static int wait_ready(UINT wt)
{
    BYTE d;
    uint32_t t0 = g_ticks;
    do {
        d = xchg_spi(0xff);
        if ((uint32_t)abs((int)(g_ticks - t0)) >= wt)
            break;
    } while (d != 0xff);
    if (d != 0xff)
        printf("tmr %d res %x\n", Timer2, d);
    return d == 0xff;
}

static void deselect(void)
{
    busy_wait_us_32(10);
    xchg_spi(0xff);
    busy_wait_us_32(10);
    gpio_put(PIN_SD_CS, 1);
    xchg_spi(0xff);
    busy_wait_us_32(10);
}

static int mmc_select(void)
{
    xchg_spi(0xff);
    gpio_put(PIN_SD_CS, 0);
    if (wait_ready(500))
        return 1;
    deselect();
    return 0;
}

/* Original returns a SIGNED char: a 0xff response (timeout / select failure) is -1, so
 * "res > 1" after CMD55 and "send_cmd(ACMD41, 0) <= 1" treat it as success (ChaN's generic
 * driver uses BYTE). Kept as in the original. */
static signed char send_cmd(BYTE cmd, DWORD arg)
{
    BYTE n;
    signed char res;
    if (cmd & 0x80) {
        cmd &= 0x7f;
        res = send_cmd(CMD55, 0);
        if (res > 1)
            return res;
    }
    if (cmd != CMD12) {
        deselect();
        if (!mmc_select())
            return 0xff;
    }
    xchg_spi(0x40 | cmd);
    xchg_spi((BYTE)(arg >> 24));
    xchg_spi((BYTE)(arg >> 16));
    xchg_spi((BYTE)(arg >> 8));
    xchg_spi((BYTE)arg);
    n = 0xff;
    if (cmd == CMD0)
        n = 0x95;
    else if (cmd == CMD8)
        n = 0x87;
    xchg_spi(n);
    if (cmd == CMD12)
        xchg_spi(0xff);
    n = 10;
    do {
        res = xchg_spi(0xff);
    } while ((res & 0x80) && --n);
    return res;
}

static void rcvr_spi_multi(BYTE *buff, UINT btr)
{
    if (buff && btr)
        spi_read_blocking(spi0, 0xff, buff, btr);
}

static int rcvr_datablock(BYTE *buff, UINT btr)
{
    BYTE token;
    Timer1 = 200;
    do {
        token = xchg_spi(0xff);
    } while (token == 0xff && Timer1);
    if (token != 0xfe)
        return 0;
    rcvr_spi_multi(buff, btr);
    xchg_spi(0xff);
    xchg_spi(0xff);
    busy_wait_us_32(10);
    return 1;
}

static void xmit_spi_multi(const BYTE *buff, UINT btx)
{
    if (buff && btx)
        spi_write_blocking(spi0, buff, btx);
}

static int xmit_datablock(const BYTE *buff, BYTE token)
{
    BYTE resp;
    xchg_spi(token);
    if (token != 0xfd) {
        xmit_spi_multi(buff, 512);
        xchg_spi(0);
        xchg_spi(0);
        resp = xchg_spi(0xff);
        if ((resp & 0x1f) != 0x05)
            printf("wtf rsp? %x\n", resp);
    }
    int r = wait_ready(5000);
    if (!r)
        puts("wtf xmit nready");
    return r;
}

DSTATUS mmc_disk_initialize(void)
{
    BYTE n, cmd, ty, ocr[4];
    mmc_power_on();
    if (Stat & STA_NODISK)
        return Stat;
    sd_spi_set_fast(0);
    for (n = 0; n < 10; n++)
        xchg_spi(0xff);
    ty = 0;
    n = send_cmd(CMD0, 0);
    if (n != 1)
        return n;               /* sic: returns the R1 response, not Stat */
    Timer1 = 1000;
    if (send_cmd(CMD8, 0x1aa) == 1) {
        puts("sdv2");
        for (n = 0; n < 4; n++)
            ocr[n] = xchg_spi(0xff);
        if (ocr[2] == 0x01 && ocr[3] == 0xaa) {
            while (Timer1 && send_cmd(ACMD41, 1UL << 30))
                ;
            if (Timer1 && send_cmd(CMD58, 0) == 0) {
                for (n = 0; n < 4; n++)
                    ocr[n] = xchg_spi(0xff);
                ty = (ocr[0] & 0x40) ? CT_SDC2 | CT_BLOCK : CT_SDC2;
            }
        }
    } else {
        BYTE t;
        if (send_cmd(ACMD41, 0) <= 1) {
            t = CT_SDC1;
            cmd = ACMD41;
        } else {
            t = CT_MMC3;
            cmd = CMD1;
        }
        while (Timer1 && send_cmd(cmd, 0))
            ;
        if (Timer1 && send_cmd(CMD16, 512) == 0)
            ty = t;
    }
    CardType = ty;
    deselect();
    if (ty) {
        sd_spi_set_fast(1);
        Stat &= ~STA_NOINIT;
    } else {
        Stat = STA_NOINIT;
    }
    return Stat;
}

DSTATUS mmc_disk_status(void)
{
    return Stat;
}

DRESULT mmc_disk_read(BYTE *buff, LBA_t sector, UINT count)
{
    DWORD sect = (DWORD)sector;
    if (!count)
        return RES_PARERR;
    if (Stat & STA_NOINIT)
        return RES_NOTRDY;
    if (!(CardType & CT_BLOCK))
        sect *= 512;
    if (count == 1) {
        if (send_cmd(CMD17, sect) == 0 && rcvr_datablock(buff, 512))
            count = 0;
    } else {
        if (send_cmd(CMD18, sect) == 0) {
            do {
                if (!rcvr_datablock(buff, 512))
                    break;
                buff += 512;
            } while (--count);
            send_cmd(CMD12, 0);
        }
    }
    deselect();
    return count ? RES_ERROR : RES_OK;
}

DRESULT mmc_disk_write(const BYTE *buff, LBA_t sector, UINT count)
{
    DWORD sect = (DWORD)sector;
    if (!count)
        return RES_PARERR;
    if (Stat & STA_NOINIT)
        return RES_NOTRDY;
    if (!(CardType & CT_BLOCK))
        sect *= 512;
    if (count == 1) {
        if (send_cmd(CMD24, sect) == 0 && xmit_datablock(buff, 0xfe))
            count = 0;
    } else {
        if (CardType & CT_SDC)
            send_cmd(ACMD23, count);
        if (send_cmd(CMD25, sect) == 0) {
            do {
                if (!xmit_datablock(buff, 0xfc))
                    break;
                buff += 512;
            } while (--count);
            if (!xmit_datablock(0, 0xfd))
                count = 1;
        }
    }
    deselect();
    return count ? RES_ERROR : RES_OK;
}

DRESULT mmc_disk_ioctl(BYTE cmd, void *buff)
{
    DRESULT res;
    BYTE n, csd[16], *ptr = buff;
    DWORD csize, st, ed;
    LBA_t *dp;

    if (Stat & STA_NOINIT)
        return RES_NOTRDY;
    res = RES_ERROR;
    switch (cmd) {
    case CTRL_SYNC:
        if (mmc_select())
            res = RES_OK;
        break;
    case GET_SECTOR_COUNT:
        if (send_cmd(CMD9, 0) == 0 && rcvr_datablock(csd, 16)) {
            if ((csd[0] >> 6) == 1) {
                csize = csd[9] + ((WORD)csd[8] << 8) + ((DWORD)(csd[7] & 63) << 16) + 1;
                *(LBA_t *)buff = csize << 10;
            } else {
                n = (csd[5] & 15) + ((csd[10] & 128) >> 7) + ((csd[9] & 3) << 1) + 2;
                csize = (csd[8] >> 6) + ((WORD)csd[7] << 2) + ((WORD)(csd[6] & 3) << 10) + 1;
                *(LBA_t *)buff = csize << (n - 9);
            }
            res = RES_OK;
        }
        break;
    case GET_BLOCK_SIZE:
        if (CardType & CT_SDC2) {
            if (send_cmd(ACMD13, 0) == 0) {
                xchg_spi(0xff);
                if (rcvr_datablock(csd, 16)) {
                    for (n = 64 - 16; n; n--)
                        xchg_spi(0xff);
                }
                *(DWORD *)buff = 16UL << (csd[10] >> 4);
                res = RES_OK;
            }
        } else {
            if (send_cmd(CMD9, 0) == 0 && rcvr_datablock(csd, 16)) {
                if (CardType & CT_SDC1)
                    *(DWORD *)buff = (((csd[10] & 63) << 1) + ((WORD)(csd[11] & 128) >> 7) + 1) << ((csd[13] >> 6) - 1);
                else
                    *(DWORD *)buff = ((WORD)((csd[10] & 124) >> 2) + 1) * (((csd[11] & 3) << 3) + ((csd[11] & 224) >> 5) + 1);
                res = RES_OK;
            }
        }
        break;
    case CTRL_TRIM:
        if (!(CardType & CT_SDC))
            break;
        if (mmc_disk_ioctl(MMC_GET_CSD, csd))
            break;
        if (!(csd[10] & 0x40))
            break;
        dp = buff;
        st = (DWORD)dp[0];
        ed = (DWORD)dp[1];
        if (!(CardType & CT_BLOCK)) {
            st *= 512;
            ed *= 512;
        }
        if (send_cmd(CMD32, st) == 0 && send_cmd(CMD33, ed) == 0 && send_cmd(CMD38, 0) == 0 && wait_ready(30000))
            res = RES_OK;
        break;
    case MMC_GET_TYPE:
        *ptr = CardType;
        res = RES_OK;
        break;
    case MMC_GET_CSD:
        if (send_cmd(CMD9, 0) == 0 && rcvr_datablock(ptr, 16))
            res = RES_OK;
        break;
    case MMC_GET_CID:
        if (send_cmd(CMD10, 0) == 0 && rcvr_datablock(ptr, 16))
            res = RES_OK;
        break;
    case MMC_GET_OCR:
        if (send_cmd(CMD58, 0) == 0) {
            for (n = 0; n < 4; n++)
                *ptr++ = xchg_spi(0xff);
            res = RES_OK;
        }
        break;
    case MMC_GET_SDSTAT:
        if (send_cmd(ACMD13, 0) == 0) {
            xchg_spi(0xff);
            if (rcvr_datablock(ptr, 64))
                res = RES_OK;
        }
        break;
    default:
        res = RES_PARERR;
    }
    deselect();
    return res;
}
