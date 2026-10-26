/* Lattice iCE5LP4K-SG48 bitstream (iCEcube2 2020.12), streamed over SPI1 by fpga_init(). */
    .section .rodata.fpga_bitstream, "a"
    .global fpga_bitstream, fpga_bitstream_end
fpga_bitstream:
    .incbin "fpga_bitstream.bin"
fpga_bitstream_end:

/* Optional disc image served from flash (ode_media_init: used when > 1000 bytes). Empty, as in the original. */
    .section .rodata.ode_flash_image, "a"
    .global ode_flash_image, ode_flash_image_end
ode_flash_image:
ode_flash_image_end:
