/*
 * piode2 flash dump patch: writes the whole 16 MB QSPI flash (64 KB bootloader + app + rest)
 * to fz1flash.bin once, on the first medium that mounts: /sd if a microSD card is mounted,
 * otherwise /usb (USB flash drive; slower - every sector goes through core 1).
 *
 * Installed by retargeting the main loop's `bl ode_mount_media` (0x1001057a) to dump_hook().
 * No .data/.bss allowed: the once-flag lives in SRAM above the firmware's stacks (unused).
 */
#include <stdint.h>

typedef unsigned int UINT;
typedef uint8_t BYTE;
typedef int FRESULT;
#define FA_READ           0x01
#define FA_WRITE          0x02
#define FA_CREATE_ALWAYS  0x08

/* firmware functions, resolved through piode2_symbols.ld */
void ode_mount_media(void);
int ode_get_boot_device(void);          /* bit0 = /sd mounted, bit1 = /usb mounted */
FRESULT f_open(void *fp, const char *path, BYTE mode);
FRESULT f_write(void *fp, const void *buff, UINT btw, UINT *bw);
FRESULT f_close(void *fp);
void watchdog_update(void);
void led_activity_on(void);
int printf(const char *fmt, ...);

#define FLASH_BASE  0x10000000u
#define FLASH_SIZE  (16u * 1024 * 1024)     /* Winbond W25Q128JVEQ */
#define CHUNK       4096u
#define DONE_FLAG   (*(volatile uint32_t *)0x20040000)  /* SRAM4, unused by piode2 */
#define DONE_MAGIC  0xD0B1F1A5u

__attribute__((section(".entry"), used))
void dump_hook(void)
{
    uint64_t fil[0x270 / 8];            /* FatFs FIL (0x260 bytes in this build) */
    UINT bw;

    ode_mount_media();                  /* what the original call did */

    if (DONE_FLAG == DONE_MAGIC)
        return;
    int dev = ode_get_boot_device();
    const char *path;
    if (dev & 1)
        path = "/sd/fz1flash.bin";
    else if (dev & 2)
        path = "/usb/fz1flash.bin";
    else
        return;
    DONE_FLAG = DONE_MAGIC;             /* one attempt per boot, success or not */

    if (f_open(fil, path, FA_READ) == 0) {
        f_close(fil);
        printf("dump: %s exists, skipping\n", path);
        return;
    }
    if (f_open(fil, path, FA_CREATE_ALWAYS | FA_WRITE) != 0) {
        printf("dump: cannot create %s\n", path);
        return;
    }
    printf("dump: writing %d bytes of flash to %s\n", FLASH_SIZE, path);
    for (uint32_t off = 0; off < FLASH_SIZE; off += CHUNK) {
        watchdog_update();
        if ((off & 0xffff) == 0)
            led_activity_on();
        FRESULT r = f_write(fil, (const void *)(FLASH_BASE + off), CHUNK, &bw);
        if (r != 0 || bw != CHUNK) {
            printf("dump: write error %d at %x\n", r, off);
            break;
        }
    }
    f_close(fil);
    printf("dump: done\n");
}
