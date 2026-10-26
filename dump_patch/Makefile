# Requires arm-none-eabi-gcc (e.g. the Arm GNU Toolchain or the one used for the Pico SDK)
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
CFLAGS  = -mcpu=cortex-m0plus -mthumb -Os -ffreestanding -fno-pic -ffunction-sections -Wall
LDFLAGS = -nostdlib -T patch.ld -Wl,--gc-sections

ORIG ?= ../original/update.ode

all: update.ode

patch.elf: patch.c patch.ld ../piode2_symbols.ld
	$(CC) $(CFLAGS) $(LDFLAGS) patch.c -o $@
	arm-none-eabi-nm -n $@ | grep dump_hook   # must be 10033a00

patch.bin: patch.elf
	$(OBJCOPY) -O binary $< $@

update.ode: patch.bin patches.json
	python3 ../tools/odepatch.py apply $(ORIG) patches.json $@
	python3 ../tools/odepatch.py info $@

clean:
	rm -f patch.elf patch.bin update.ode
