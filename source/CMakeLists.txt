# piode2 v0.1 (3DO FZ-1 internal ODE) - reconstructed source.
# Build: GNU Arm Embedded 10.3-2021.10 + Pico SDK 1.3.0, CMAKE_BUILD_TYPE=Debug (as the original).
cmake_minimum_required(VERSION 3.13)
# TinyUSB: 0.12.0 as in SDK 1.3.0, with the RP2040 host port changed the way the original firmware has it
set(PICO_TINYUSB_PATH ${CMAKE_CURRENT_LIST_DIR}/lib/tinyusb)
# The FPGA bitstream is Fixel's and is not shipped: tools/setup_from_official.py extracts it from the official update.ode
if(NOT EXISTS ${CMAKE_CURRENT_LIST_DIR}/src/fpga_bitstream.bin)
    message(FATAL_ERROR "src/fpga_bitstream.bin is missing. Download the official update.ode (rev 1.0) from "
        "https://github.com/fixelsan/3do-ode-firmware/releases and run: python3 tools/setup_from_official.py <update.ode>")
endif()
include(pico_sdk_import.cmake)
project(piode2 C CXX ASM)
pico_sdk_init()

# Source order = link order; it follows the layout of the original image.
add_executable(piode2
    src/main.c
    ff/ff.c
    ff/ffunicode.c
    src/diskio.c
    src/mmc_spi.c
    src/usb_msc.c
    src/fpga.c
    src/image.c
    src/cdrom.c
    src/ode.c
    src/buttons.c
    src/bitstream.S
)
target_include_directories(piode2 PRIVATE src ff)
target_compile_definitions(piode2 PRIVATE
    PICO_STACK_SIZE=0x3000
    PICO_CORE1_STACK_SIZE=0x2000
)
pico_set_linker_script(piode2 ${CMAKE_CURRENT_LIST_DIR}/memmap_piode2.ld)
pico_set_program_name(piode2 "piode2")
pico_set_program_version(piode2 "0.1")
target_link_libraries(piode2
    pico_stdlib pico_multicore hardware_spi hardware_i2c tinyusb_host
)
pico_add_extra_outputs(piode2)
# update.ode = raw binary of the app image
add_custom_command(TARGET piode2 POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:piode2> ${CMAKE_CURRENT_BINARY_DIR}/update.ode)
