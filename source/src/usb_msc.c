/*
 * USB mass storage. TinyUSB host runs on core 1; FatFs (core 0) posts one request at a time
 * through the SIO FIFO (1 status, 2 read, 3 write, 4 ioctl) with its arguments in usb_req,
 * and waits for core 1 to push back the result. Mount callbacks follow TinyUSB's msc_app.c.
 */
#include <stdio.h>
#include <string.h>
#include "pico/multicore.h"
#include "tusb.h"
#include "ff.h"
#include "diskio.h"
#include "piode2.h"

static scsi_inquiry_resp_t inquiry_resp;
static uint32_t usb_block_count;
static uint32_t usb_block_size;
static uint8_t usb_dev_addr;
static volatile DSTATUS usb_stat;

struct usb_req {
    uint32_t _0;
    uint32_t _4;
    uint32_t arg;               /* lba, or ioctl command */
    uint32_t val;               /* length, or ioctl result */
    uint32_t _10;
    uint8_t  buf[512];
};
struct usb_req usb_req;

static bool msc_inquiry_complete_cb(uint8_t dev_addr, msc_cbw_t const *cbw, msc_csw_t const *csw)
{
    if (csw->status != 0) {
        puts("Inquiry failed\r");
        return false;
    }
    if ((inquiry_resp.peripheral_device_type & 0x1f) == 0) {
        printf("%.8s %.16s rev %.4s\r\n", inquiry_resp.vendor_id, inquiry_resp.product_id, inquiry_resp.product_rev);
        uint32_t count = tuh_msc_get_block_count(dev_addr, cbw->lun);
        uint32_t size = tuh_msc_get_block_size(dev_addr, cbw->lun);
        usb_dev_addr = dev_addr;
        usb_stat &= ~STA_NODISK;
        usb_block_count = count;
        usb_block_size = size;
        printf("Disk Size: %lu MB\r\n", count / ((1024 * 1024) / size));
        printf("Block Count = %lu, Block Size: %lu\r\n", count, size);
    }
    return true;
}

static bool msc_read_complete_cb(uint8_t dev_addr, msc_cbw_t const *cbw, msc_csw_t const *csw)
{
    multicore_fifo_push_blocking(0);
    return true;    /* the original returns whatever is in r0 */
}

static bool msc_write_complete_cb(uint8_t dev_addr, msc_cbw_t const *cbw, msc_csw_t const *csw)
{
    multicore_fifo_push_blocking(0);
    return true;
}

void tuh_msc_mount_cb(uint8_t dev_addr)
{
    puts("A MassStorage device is mounted\r");
    tuh_msc_inquiry(dev_addr, 0, &inquiry_resp, msc_inquiry_complete_cb);
}

void tuh_msc_umount_cb(uint8_t dev_addr)
{
    puts("A MassStorage device is unmounted\r");
    usb_stat = STA_NODISK;
}

/* core 1: execute a request from core 0 */
void usb_msc_service_request(uint32_t req, void *blk)
{
    struct usb_req *r = blk;
    if (req == 3) {
        if (usb_stat == 0) {
            if (!tuh_msc_write10(usb_dev_addr, 0, r->buf, r->arg, 1, msc_write_complete_cb))
                multicore_fifo_push_blocking(1);
        } else {
            multicore_fifo_push_blocking(1);
        }
    } else if (req < 4) {
        if (req == 1) {
            multicore_fifo_push_blocking(usb_stat);
        } else if (req == 2) {
            if (usb_stat == 0) {
                if (!tuh_msc_read10(usb_dev_addr, 0, r->buf, r->arg, 1, msc_read_complete_cb))
                    multicore_fifo_push_blocking(1);
            } else {
                multicore_fifo_push_blocking(1);
            }
        }
    } else if (req == 4) {
        if (usb_stat == 0) {
            DRESULT res;
            if (r->arg == GET_SECTOR_COUNT) {
                r->val = usb_block_count;
                res = RES_OK;
            } else {
                res = RES_PARERR;
                if (r->arg == GET_BLOCK_SIZE) {
                    r->val = usb_block_size;
                    res = RES_OK;
                }
            }
            multicore_fifo_push_blocking(res);
        } else {
            multicore_fifo_push_blocking(RES_PARERR);
        }
    }
}

void usb_disk_set_nodisk(void)
{
    usb_stat = STA_NODISK;
}

DSTATUS usb_disk_initialize(void)
{
    uint32_t r;
    usb_req._0 = 0;
    usb_req._4 = 0;
    multicore_fifo_push_timeout_us(1, 300000);
    if (!multicore_fifo_pop_timeout_us(300000, &r))
        return STA_NOINIT;
    return r;
}

DSTATUS usb_disk_status(void)
{
    uint32_t r;
    usb_req._0 = 0;
    usb_req._4 = 0;
    multicore_fifo_push_timeout_us(1, 300000);
    if (!multicore_fifo_pop_timeout_us(300000, &r))
        return STA_NOINIT;
    return r;
}

DRESULT usb_disk_read(BYTE *buff, LBA_t sector, UINT count)
{
    uint32_t r;
    for (UINT i = 0; i < count; i++) {
        usb_req._0 = 0;
        usb_req._4 = 0;
        usb_req.arg = sector;
        usb_req.val = 512;
        multicore_fifo_push_timeout_us(2, 300000);
        if (!multicore_fifo_pop_timeout_us(3300000, &r)) {
            puts("usb read timeout");
            return RES_ERROR;
        }
        if (r)
            return r;
        memcpy(buff, usb_req.buf, 512);
        buff += 512;
        sector++;
    }
    return RES_OK;
}

DRESULT usb_disk_write(const BYTE *buff, LBA_t sector, UINT count)
{
    uint32_t r;
    for (UINT i = 0; i < count; i++) {
        usb_req._0 = 0;
        usb_req._4 = 0;
        usb_req.val = 512;
        usb_req.arg = sector;
        memcpy(usb_req.buf, buff, 512);
        multicore_fifo_push_timeout_us(3, 300000);
        if (!multicore_fifo_pop_timeout_us(2300000, &r))
            return RES_ERROR;
        if (r)
            return r;
        buff += 512;
        sector++;
    }
    return RES_OK;
}

DRESULT usb_disk_ioctl(BYTE cmd, void *buff)
{
    uint32_t r = RES_PARERR;
    usb_req._0 = 0;
    usb_req._4 = 0;
    if (cmd == GET_SECTOR_COUNT) {
        usb_req.arg = GET_SECTOR_COUNT;
        multicore_fifo_push_timeout_us(4, 300000);
        if (!multicore_fifo_pop_timeout_us(300000, &r))
            return RES_ERROR;
        if (r == 0)
            *(LBA_t *)buff = usb_req.val;
    } else if (cmd == GET_BLOCK_SIZE) {
        usb_req.arg = GET_BLOCK_SIZE;
        multicore_fifo_push_timeout_us(4, 300000);
        if (!multicore_fifo_pop_timeout_us(300000, &r))
            return RES_ERROR;
        if (r == 0)
            *(DWORD *)buff = usb_req.val;
    } else if (cmd == CTRL_SYNC && usb_disk_status() == 0) {
        r = RES_OK;
    }
    return r;
}
