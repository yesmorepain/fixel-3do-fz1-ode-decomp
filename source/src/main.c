/*
 * piode2 main: board bring-up, 10 ms timer, button actions, main loop.
 * Core 0 runs the 3DO side (FPGA command packets, media), core 1 runs TinyUSB host
 * and serves USB disk requests posted by core 0 through the SIO FIFO.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/gpio.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/irq.h"
#include "hardware/watchdog.h"
#include "hardware/structs/watchdog.h"
#include "tusb.h"
#include "piode2.h"

extern struct usb_req usb_req;          /* usb_msc.c, request block for core 1 */

static uint32_t g_btn_count;            /* clicks counted by btn_cb_count */
static uint32_t g_btn_count_last;       /* reported in EXT_ID */
static uint32_t g_btn_count_tick;
static uint32_t g_led_timer;
static volatile uint32_t g_main_state;  /* 1 = pulse FPGA control (media reset) */
volatile uint32_t g_main_flags;         /* bit0 core1 alive, bit1 core0 alive: kicks watchdog */
static volatile uint8_t g_core1_req;
static volatile uint32_t g_card_detect;          /* GPIO19 history, 1 bit per 10 ms */
static repeating_timer_t g_timer;
volatile uint32_t g_ticks;

void btn_cb_count(button_t *b)
{
    g_btn_count++;
    g_btn_count_tick = g_ticks;
}

/* core 1: SIO FIFO irq, a request code from core 0 */
void core1_sio_irq_handler(void)
{
    if (sio_hw->fifo_st & SIO_FIFO_ST_VLD_BITS)
        g_core1_req = multicore_fifo_pop_blocking();
    sio_hw->fifo_st = 0xff;
}

void core1_entry(void)
{
    tusb_init();
    g_core1_req = 0;
    sio_hw->fifo_st = 0xff;
    irq_set_exclusive_handler(SIO_IRQ_PROC1, core1_sio_irq_handler);
    irq_set_enabled(SIO_IRQ_PROC1, true);
    for (;;) {
        g_main_flags |= 1;
        tuh_task();
        if (g_core1_req) {
            usb_msc_service_request(g_core1_req, &usb_req);
            g_core1_req = 0;
        }
    }
}

void btn_read_cb(button_t *b)
{
    if (b)
        b->state = btn_gpio28_pressed();
}

void btn_cb_long_press(button_t *b)
{
    puts("long press");
}

void main_request_reset(void)
{
    g_main_state = 1;
}

void btn_cb_short_press(button_t *b)
{
    puts("short press");
    ode_mount_next_image();
    cd_state_reset();
    main_request_reset();
}

void btn_cb_boot_iso(button_t *b)
{
    puts("boot.iso requested");
    ode_mount_boot_iso();
    cd_state_reset();
    main_request_reset();
}

uint32_t main_get_counter_472c(void)
{
    return g_btn_count_last;
}

void board_init(void);

int main(void)
{
    uint32_t t0;
    button_t btn;

    /* disarm a pending update request (the bootloader checks these words) */
    watchdog_hw->scratch[0] = 0xbeef0000;
    watchdog_hw->scratch[1] = 0xdeadf00d;
    watchdog_hw->scratch[2] = 0xfeedface;
    watchdog_enable(3000, 1);
    stdio_uart_init_full(uart0, 3000000, 16, 17);
    puts("\n\n\nODE1 Entry");
    printf("version %d.%d\n", 1, 0);
    extern char __StackTop, __StackOneTop, __StackBottom, __StackOneBottom;
    printf("%x %x %x %x\n", &__StackTop, &__StackOneTop, &__StackBottom, &__StackOneBottom);
    memset(&__StackOneBottom, 0xcc, &__StackOneTop - &__StackOneBottom);
    g_btn_count = 0;
    g_btn_count_last = 0;
    g_btn_count_tick = 0;
    usb_disk_set_nodisk();
    multicore_launch_core1(core1_entry);
    buttons_init();
    board_init();
    printf("FPGA Init %d\n", fpga_init());
    cd_state_init();
    ode_media_init();
    g_main_state = 0;

    memset(&btn, 0, sizeof(btn));
    btn.dbl_ms = 1500;
    btn.long_ms = 3000;
    btn.read = btn_read_cb;
    btn.debounce_bits = 3;
    btn.enabled = 1;
    button_register(&btn, btn_cb_short_press, BTN_EV_CLICK);
    button_register(&btn, btn_cb_boot_iso, BTN_EV_DOUBLE);
    button_register(&btn, btn_cb_long_press, BTN_EV_LONG);
    button_register(&btn, btn_cb_count, BTN_EV_PRESS);
    g_main_flags = 0;

    for (;;) {
        g_main_flags |= 2;
        if (g_btn_count && abs((int)(g_ticks - g_btn_count_tick)) > 1499) {
            g_btn_count_last = g_btn_count;
            g_btn_count = 0;
        }
        if (!(sio_hw->gpio_in & (1u << PIN_FPGA_DONE))) {
            puts("WTF???");
            puts("FTW");
            for (;;)
                ;                   /* FPGA lost its configuration: let the watchdog reset */
        }
        buttons_process();
        cd_cmd_poll();
        ode_mount_media();
        if (g_main_state == 1) {
            g_main_state = 2;
            t0 = g_ticks;
            fpga_write_ctrl(1);
            printf("POLL1 %x\n", fpga_read_status());
        } else if (g_main_state == 2) {
            if (abs((int)(g_ticks - t0)) > 99) {
                g_main_state = 0;
                fpga_write_ctrl(0);
                printf("POLL1 %x\n", fpga_read_status());
            }
        } else {
            g_main_state = 0;
        }
        if (g_main_state == 1) {
            g_main_state = 0;
            fpga_write_ctrl(1);
            printf("POLL %x\n", fpga_read_status());
            fpga_write_ctrl(0);
        }
        if (g_main_flags == 3) {
            g_main_flags = 0;
            /* an armed update (see ode_stage_firmware_update) stops the kicks: reset into the bootloader */
            if (watchdog_hw->scratch[0] != 0xfeedface || watchdog_hw->scratch[1] != 0xdeadf00d)
                watchdog_update();
        }
    }
}

/* 10 ms repeating timer */
bool timer_10ms_cb(repeating_timer_t *t)
{
    g_ticks += 10;
    cd_poll_media_change();
    ode_nop();
    buttons_tick();
    if (g_led_timer > 10) {
        g_led_timer -= 10;
    } else {
        g_led_timer = 0;
        sio_hw->gpio_clr = 1u << PIN_LED;
    }
    g_card_detect <<= 1;
    g_card_detect |= !((sio_hw->gpio_in >> PIN_CARD_DET) & 1);
    return true;    /* the original falls off the end here; any non-zero r0 keeps the timer running */
}

void board_init(void)
{
    gpio_init(PIN_LED);
    spi_init(spi0, 400000);
    spi_init(spi1, 4000000);
    gpio_set_function(4, GPIO_FUNC_SPI);        /* SPI0 RX  (SD) */
    gpio_set_function(3, GPIO_FUNC_SPI);        /* SPI0 TX */
    gpio_set_function(2, GPIO_FUNC_SPI);        /* SPI0 SCK */
    gpio_init(PIN_CARD_DET);
    gpio_set_function(10, GPIO_FUNC_SPI);       /* SPI1 SCK (FPGA) */
    gpio_set_function(8, GPIO_FUNC_SPI);        /* SPI1 RX */
    gpio_set_function(11, GPIO_FUNC_SPI);       /* SPI1 TX */
    gpio_init(PIN_FPGA_CS);
    gpio_init(PIN_FPGA_RESET);
    gpio_init(PIN_FPGA_DONE);
    gpio_init(PIN_DATA_READY);
    gpio_init(PIN_CMD_IRQ);
    gpio_init(PIN_FPGA_CTRL);
    gpio_init(PIN_LED);
    gpio_init(PIN_BUTTON);
    gpio_set_dir(PIN_FPGA_DONE, GPIO_IN);
    gpio_set_dir(PIN_DATA_READY, GPIO_IN);
    gpio_set_dir(PIN_CMD_IRQ, GPIO_IN);
    gpio_set_dir(PIN_FPGA_CTRL, GPIO_OUT);
    gpio_set_dir(PIN_BUTTON, GPIO_IN);
    gpio_set_dir(PIN_CARD_DET, GPIO_IN);
    gpio_set_dir(PIN_LED, GPIO_OUT);
    gpio_put(PIN_LED, 0);
    gpio_set_drive_strength(PIN_LED, GPIO_DRIVE_STRENGTH_12MA);
    gpio_set_pulls(PIN_CARD_DET, true, false);
    gpio_set_dir(PIN_FPGA_CS, GPIO_OUT);
    gpio_set_dir(PIN_FPGA_RESET, GPIO_OUT);
    gpio_set_drive_strength(PIN_FPGA_CS, GPIO_DRIVE_STRENGTH_12MA);
    gpio_set_drive_strength(10, GPIO_DRIVE_STRENGTH_12MA);
    gpio_set_drive_strength(11, GPIO_DRIVE_STRENGTH_12MA);
    gpio_set_drive_strength(PIN_FPGA_CTRL, GPIO_DRIVE_STRENGTH_12MA);
    gpio_put(PIN_FPGA_CTRL, 0);
    gpio_put(PIN_FPGA_CS, 1);
    gpio_put(PIN_FPGA_RESET, 1);
    gpio_set_pulls(PIN_FPGA_DONE, true, false);
    g_led_timer = 0;
    gpio_init(PIN_SD_CS);
    gpio_set_dir(PIN_SD_CS, GPIO_OUT);
    gpio_put(PIN_SD_CS, 1);
    gpio_set_pulls(4, true, false);             /* SD MISO pull-up */
    spi_set_format(spi0, 8, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);
    spi_set_format(spi1, 8, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);
    gpio_set_function(27, GPIO_FUNC_I2C);
    gpio_set_function(26, GPIO_FUNC_I2C);
    gpio_set_pulls(27, true, false);
    gpio_set_pulls(26, true, false);
    g_ticks = 0;
    alarm_pool_add_repeating_timer_us(alarm_pool_get_default(), -10000, timer_10ms_cb, NULL, &g_timer);
    i2c_init(i2c1, 400000);
}

void sd_spi_set_fast(int fast)
{
    spi_set_baudrate(spi0, fast ? 20000000 : 400000);
}

void led_activity_on(void)
{
    g_led_timer = 100;
    sio_hw->gpio_set = 1u << PIN_LED;
}

int btn_gpio28_pressed(void)
{
    return !((sio_hw->gpio_in >> PIN_BUTTON) & 1);
}

/* GPIO19 debounced over 40 ms: 1 = low, 2 = high, 0 = changing */
int sd_card_detect_state(void)
{
    if ((g_card_detect & 0xf) == 0xf)
        return 1;
    if ((g_card_detect & 0xf) == 0)
        return 2;
    return 0;
}
