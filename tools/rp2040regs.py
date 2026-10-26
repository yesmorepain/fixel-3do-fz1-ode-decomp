"""RP2040 peripheral map (datasheet section 2.2 address map) for annotation."""

BLOCKS = [
    (0x00000000, 0x4000, "ROM"),
    (0x40000000, 0x4000, "SYSINFO"), (0x40004000, 0x4000, "SYSCFG"),
    (0x40008000, 0x4000, "CLOCKS"), (0x4000C000, 0x4000, "RESETS"),
    (0x40010000, 0x4000, "PSM"), (0x40014000, 0x4000, "IO_BANK0"),
    (0x40018000, 0x4000, "IO_QSPI"), (0x4001C000, 0x4000, "PADS_BANK0"),
    (0x40020000, 0x4000, "PADS_QSPI"), (0x40024000, 0x4000, "XOSC"),
    (0x40028000, 0x4000, "PLL_SYS"), (0x4002C000, 0x4000, "PLL_USB"),
    (0x40030000, 0x4000, "BUSCTRL"), (0x40034000, 0x4000, "UART0"),
    (0x40038000, 0x4000, "UART1"), (0x4003C000, 0x4000, "SPI0"),
    (0x40040000, 0x4000, "SPI1"), (0x40044000, 0x4000, "I2C0"),
    (0x40048000, 0x4000, "I2C1"), (0x4004C000, 0x4000, "ADC"),
    (0x40050000, 0x4000, "PWM"), (0x40054000, 0x4000, "TIMER"),
    (0x40058000, 0x4000, "WATCHDOG"), (0x4005C000, 0x4000, "RTC"),
    (0x40060000, 0x4000, "ROSC"), (0x40064000, 0x4000, "VREG_CHIP_RESET"),
    (0x4006C000, 0x4000, "TBMAN"),
    (0x50000000, 0x100000, "DMA"), (0x50100000, 0x10000, "USBCTRL_DPRAM"),
    (0x50110000, 0x10000, "USBCTRL_REGS"),
    (0x50200000, 0x100000, "PIO0"), (0x50300000, 0x100000, "PIO1"),
    (0x50400000, 0x100000, "XIP_AUX"),
    (0xD0000000, 0x1000, "SIO"),
    (0xE0000000, 0x10000, "PPB"),
    (0x14000000, 0x4000, "XIP_CTRL"), (0x18000000, 0x4000, "XIP_SSI"),
]

ALIAS = {0x0000: "", 0x1000: ".XOR", 0x2000: ".SET", 0x3000: ".CLR"}

SIO = {0x000: "CPUID", 0x004: "GPIO_IN", 0x008: "GPIO_HI_IN", 0x010: "GPIO_OUT",
       0x014: "GPIO_OUT_SET", 0x018: "GPIO_OUT_CLR", 0x01C: "GPIO_OUT_XOR",
       0x020: "GPIO_OE", 0x024: "GPIO_OE_SET", 0x028: "GPIO_OE_CLR", 0x02C: "GPIO_OE_XOR",
       0x050: "FIFO_ST", 0x054: "FIFO_WR", 0x058: "FIFO_RD", 0x05C: "SPINLOCK_ST",
       0x060: "DIV_UDIVIDEND", 0x064: "DIV_UDIVISOR", 0x068: "DIV_SDIVIDEND",
       0x06C: "DIV_SDIVISOR", 0x070: "DIV_QUOTIENT", 0x074: "DIV_REMAINDER", 0x078: "DIV_CSR",
       0x080: "INTERP0_ACCUM0", 0x0C0: "INTERP1_ACCUM0"}
for i in range(32):
    SIO[0x100 + 4 * i] = f"SPINLOCK{i}"

PIO = {0x000: "CTRL", 0x004: "FSTAT", 0x008: "FDEBUG", 0x00C: "FLEVEL",
       0x010: "TXF0", 0x014: "TXF1", 0x018: "TXF2", 0x01C: "TXF3",
       0x020: "RXF0", 0x024: "RXF1", 0x028: "RXF2", 0x02C: "RXF3",
       0x030: "IRQ", 0x034: "IRQ_FORCE", 0x038: "INPUT_SYNC_BYPASS",
       0x03C: "DBG_PADOUT", 0x040: "DBG_PADOE", 0x044: "DBG_CFGINFO",
       0x128: "INTR", 0x12C: "IRQ0_INTE", 0x130: "IRQ0_INTF", 0x134: "IRQ0_INTS",
       0x138: "IRQ1_INTE", 0x13C: "IRQ1_INTF", 0x140: "IRQ1_INTS"}
for i in range(32):
    PIO[0x048 + 4 * i] = f"INSTR_MEM{i}"
for sm in range(4):
    b = 0x0C8 + sm * 0x18
    for j, n in enumerate(["CLKDIV", "EXECCTRL", "SHIFTCTRL", "ADDR", "INSTR", "PINCTRL"]):
        PIO[b + 4 * j] = f"SM{sm}_{n}"

DMA_CH = ["READ_ADDR", "WRITE_ADDR", "TRANS_COUNT", "CTRL_TRIG",
          "AL1_CTRL", "AL1_READ_ADDR", "AL1_WRITE_ADDR", "AL1_TRANS_COUNT_TRIG",
          "AL2_CTRL", "AL2_TRANS_COUNT", "AL2_READ_ADDR", "AL2_WRITE_ADDR_TRIG",
          "AL3_CTRL", "AL3_WRITE_ADDR", "AL3_TRANS_COUNT", "AL3_READ_ADDR_TRIG"]
DMA = {0x400: "INTR", 0x404: "INTE0", 0x408: "INTF0", 0x40C: "INTS0",
       0x414: "INTE1", 0x418: "INTF1", 0x41C: "INTS1", 0x430: "MULTI_CHAN_TRIGGER",
       0x440: "SNIFF_CTRL", 0x444: "SNIFF_DATA", 0x44C: "FIFO_LEVELS", 0x450: "CHAN_ABORT"}
for ch in range(12):
    for j, n in enumerate(DMA_CH):
        DMA[ch * 0x40 + 4 * j] = f"CH{ch}_{n}"

TIMER = {0x00: "TIMEHW", 0x04: "TIMELW", 0x08: "TIMEHR", 0x0C: "TIMELR",
         0x10: "ALARM0", 0x14: "ALARM1", 0x18: "ALARM2", 0x1C: "ALARM3",
         0x20: "ARMED", 0x24: "TIMERAWH", 0x28: "TIMERAWL", 0x2C: "DBGPAUSE",
         0x30: "PAUSE", 0x34: "INTR", 0x38: "INTE", 0x3C: "INTF", 0x40: "INTS"}
RESETS = {0x0: "RESET", 0x4: "WDSEL", 0x8: "RESET_DONE"}
WATCHDOG = {0x00: "CTRL", 0x04: "LOAD", 0x08: "REASON", 0x2C: "TICK"}
for i in range(8):
    WATCHDOG[0x0C + 4 * i] = f"SCRATCH{i}"
I2C = {0x00: "IC_CON", 0x04: "IC_TAR", 0x08: "IC_SAR", 0x10: "IC_DATA_CMD",
       0x14: "IC_SS_SCL_HCNT", 0x18: "IC_SS_SCL_LCNT", 0x1C: "IC_FS_SCL_HCNT",
       0x20: "IC_FS_SCL_LCNT", 0x2C: "IC_INTR_STAT", 0x30: "IC_INTR_MASK",
       0x34: "IC_RAW_INTR_STAT", 0x38: "IC_RX_TL", 0x3C: "IC_TX_TL",
       0x40: "IC_CLR_INTR", 0x54: "IC_CLR_TX_ABRT", 0x6C: "IC_ENABLE",
       0x70: "IC_STATUS", 0x74: "IC_TXFLR", 0x78: "IC_RXFLR", 0x7C: "IC_SDA_HOLD",
       0x80: "IC_TX_ABRT_SOURCE", 0x94: "IC_ENABLE_STATUS", 0xA0: "IC_FS_SPKLEN"}
SPI = {0x00: "SSPCR0", 0x04: "SSPCR1", 0x08: "SSPDR", 0x0C: "SSPSR",
       0x10: "SSPCPSR", 0x14: "SSPIMSC", 0x18: "SSPRIS", 0x1C: "SSPMIS",
       0x20: "SSPICR", 0x24: "SSPDMACR"}
UART = {0x00: "UARTDR", 0x18: "UARTFR", 0x24: "UARTIBRD", 0x28: "UARTFBRD",
        0x2C: "UARTLCR_H", 0x30: "UARTCR", 0x38: "UARTIMSC", 0x44: "UARTICR",
        0x48: "UARTDMACR"}
PPB = {0xE010: "SYST_CSR", 0xE014: "SYST_RVR", 0xE018: "SYST_CVR",
       0xE100: "NVIC_ISER", 0xE180: "NVIC_ICER", 0xE200: "NVIC_ISPR",
       0xE280: "NVIC_ICPR", 0xE400: "NVIC_IPR0", 0xED00: "CPUID",
       0xED04: "ICSR", 0xED08: "VTOR", 0xED0C: "AIRCR", 0xED10: "SCR",
       0xED1C: "SHPR2", 0xED20: "SHPR3"}

REGS = {"SIO": SIO, "PIO0": PIO, "PIO1": PIO, "DMA": DMA, "TIMER": TIMER,
        "RESETS": RESETS, "WATCHDOG": WATCHDOG, "I2C0": I2C, "I2C1": I2C,
        "SPI0": SPI, "SPI1": SPI, "UART0": UART, "UART1": UART, "PPB": PPB}


def name(addr):
    """Return a symbolic name for an MMIO address, or None."""
    for base, size, blk in BLOCKS:
        if blk == "ROM":
            continue
        if base <= addr < base + size:
            off = addr - base
            alias = ""
            if blk.startswith("4") or (0x40000000 <= base < 0x50000000):
                alias = ALIAS.get(off & 0x3000, "")
                off &= 0xFFF
            if blk in ("PIO0", "PIO1", "DMA", "USBCTRL_REGS") and off >= 0x1000 and off < 0x4000:
                alias = ALIAS.get(off & 0x3000, "")
                off &= 0xFFF
            if blk == "IO_BANK0" and off < 0xF0:
                reg = f"GPIO{off // 8}_{'STATUS' if off % 8 == 0 else 'CTRL'}"
            elif blk == "PADS_BANK0" and 4 <= off < 0x7C:
                reg = f"GPIO{(off - 4) // 4}"
            else:
                reg = REGS.get(blk, {}).get(off)
            if reg:
                return f"{blk}{alias}.{reg}"
            return f"{blk}{alias}+0x{off:x}"
    return None
