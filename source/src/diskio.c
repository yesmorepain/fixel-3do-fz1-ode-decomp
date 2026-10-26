/* FatFs disk I/O glue: drive 0 = SD card ("/sd"), drive 1 = USB mass storage ("/usb"). */
#include "ff.h"
#include "diskio.h"
#include "piode2.h"

DSTATUS disk_initialize(BYTE pdrv)
{
    switch (pdrv) {
    case 0: return mmc_disk_initialize();
    case 1: return usb_disk_initialize();
    }
    return STA_NOINIT;
}

DSTATUS disk_status(BYTE pdrv)
{
    switch (pdrv) {
    case 0: return mmc_disk_status();
    case 1: return usb_disk_status();
    }
    return STA_NOINIT;
}

DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)
{
    switch (pdrv) {
    case 0: return mmc_disk_read(buff, sector, count);
    case 1: return usb_disk_read(buff, sector, count);
    }
    return RES_PARERR;
}

DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)
{
    switch (pdrv) {
    case 0: return mmc_disk_write(buff, sector, count);
    case 1: return usb_disk_write(buff, sector, count);
    }
    return RES_PARERR;
}

DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)
{
    switch (pdrv) {
    case 0: return mmc_disk_ioctl(cmd, buff);
    case 1: return usb_disk_ioctl(cmd, buff);
    }
    return RES_PARERR;
}
