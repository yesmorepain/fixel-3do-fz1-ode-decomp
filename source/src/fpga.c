/*
 * Lattice iCE5LP4K FPGA: configuration at boot and the SPI1 packet port (CS = GPIO9).
 * Port opcodes (first byte): 0x01 poll command (10-byte read), 0x02 status reply,
 * 0x03 read FPGA status, 0x04 control byte, 0x05 sector data.
 */
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "piode2.h"

extern const uint8_t fpga_bitstream[], fpga_bitstream_end[];

#define CS_LOW()  (sio_hw->gpio_clr = 1u << PIN_FPGA_CS)
#define CS_HIGH() (sio_hw->gpio_set = 1u << PIN_FPGA_CS)

/* configure the FPGA (SPI slave mode); returns CDONE */
int fpga_init(void)
{
    uint8_t buf[32];
    const uint8_t *img = fpga_bitstream;
    uint32_t sz = fpga_bitstream_end - fpga_bitstream;

    spi_set_baudrate(spi1, 2400000);
    printf("FPGA Image sz %d @%x\n", sz, img);
    sio_hw->gpio_clr = 1u << PIN_FPGA_RESET;
    sio_hw->gpio_clr = 1u << PIN_FPGA_CS;
    sleep_ms(1);
    sio_hw->gpio_set = 1u << PIN_FPGA_RESET;
    sio_hw->gpio_set = 1u << PIN_FPGA_CS;
    sleep_us(100);
    sio_hw->gpio_clr = 1u << PIN_FPGA_CS;
    sleep_us(10);
    spi_write_blocking(spi1, img, sz);
    sleep_us(20);
    sio_hw->gpio_set = 1u << PIN_FPGA_CS;
    sleep_us(100);
    sio_hw->gpio_clr = 1u << PIN_FPGA_CS;
    buf[0] = 0x0e;
    buf[1] = 0x03;
    spi_write_blocking(spi1, buf, 2);
    sleep_us(10);
    sio_hw->gpio_set = 1u << PIN_FPGA_CS;
    buf[0] = 0;
    buf[1] = 0;
    spi_write_blocking(spi1, buf, 32);     /* extra clocks; buf[2..] is whatever is on the stack */
    int done = (sio_hw->gpio_in >> PIN_FPGA_DONE) & 1;
    printf("FPGA Done = %d\r\n", done);
    if (done) {
        spi_set_baudrate(spi1, 30000000);
        sio_hw->gpio_set = 1u << PIN_FPGA_CTRL;
        sleep_us(10);
        sio_hw->gpio_clr = 1u << PIN_FPGA_CTRL;
    }
    return done;
}

int cd_recv_command(uint8_t *cmd)
{
    uint8_t rx[12];
    int i;
    if (!cmd)
        return 0;
    rx[0] = 0x01;
    CS_LOW();
    spi_write_blocking(spi1, rx, 1);
    spi_read_blocking(spi1, 0xff, rx, 10);
    CS_HIGH();
    i = 0;
    CS_LOW();
    spi_write_blocking(spi1, (uint8_t *)&i, 1);
    CS_HIGH();
    memcpy(cmd, &rx[2], 7);
    if (cmd[0] == 0x10)
        return 1;
    if (cmd[0] == 0x87)
        return 1;
    printf("CMD RX ");
    for (i = 0; i < 7; i++)
        printf("%.2x ", cmd[i]);
    printf(" => ");
    return 1;
}

void cd_send_reply(uint8_t *buf, uint32_t len)
{
    uint8_t pkt[68];
    if (len > 64)
        len = 64;
    pkt[0] = 0x02;
    memcpy(&pkt[1], buf, len);
    CS_LOW();
    spi_write_blocking(spi1, pkt, len + 1);
    CS_HIGH();
    if (buf[0] == 0x10 || buf[0] == 0x87)
        return;
    printf("STAT TX ");
    for (uint32_t i = 0; i < len; i++)
        printf("%.2x ", buf[i]);
    putchar('\n');
}

uint8_t fpga_read_status(void)
{
    uint8_t op = 0x03;
    uint8_t rx[3];
    CS_LOW();
    spi_write_blocking(spi1, &op, 1);
    spi_read_blocking(spi1, 0xff, rx, 3);
    CS_HIGH();
    return rx[2];
}

/* send one sector to the FPGA data FIFO; a raw sector (> 2048) goes in two parts */
void fpga_send_data(uint8_t *buf, uint32_t len)
{
    uint8_t op = 0x05;
    if (len <= 0x800) {
        CS_LOW();
        spi_write_blocking(spi1, &op, 1);
        spi_write_blocking(spi1, buf, len);
        CS_HIGH();
    } else if (len <= 0x9c4) {
        CS_LOW();
        spi_write_blocking(spi1, &op, 1);
        spi_write_blocking(spi1, buf, 0x800);
        CS_HIGH();
        sleep_us(10);
        while (fpga_read_status() & 0x20)
            sleep_us(10);
        sleep_us(320);
        CS_LOW();
        spi_write_blocking(spi1, &op, 1);
        spi_write_blocking(spi1, buf + 0x800, len - 0x800);
        CS_HIGH();
    }
    op = 0;
    CS_LOW();
    spi_write_blocking(spi1, &op, 1);
    CS_HIGH();
}

void fpga_write_ctrl(uint8_t v)
{
    uint8_t pkt[2];
    pkt[0] = 0x04;
    pkt[1] = v;
    CS_LOW();
    spi_write_blocking(spi1, pkt, 2);
    CS_HIGH();
}
