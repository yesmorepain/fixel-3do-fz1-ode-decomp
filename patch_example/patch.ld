/* Link patch code into the free flash after the original piode2 image. */
INCLUDE ../piode2_symbols.ld

MEMORY { PATCH (rx) : ORIGIN = 0x10033A00, LENGTH = 64K }

SECTIONS
{
    .text : {
        KEEP(*(.entry))          /* first function = handler entry @0x10033A00 */
        *(.text*)
        *(.rodata*)
    } > PATCH
    .data : { *(.data*) } > PATCH
    .bss  : { *(.bss*) *(COMMON) } > PATCH
    /DISCARD/ : { *(.ARM.exidx*) *(.comment) }
}
ASSERT(SIZEOF(.data) == 0 && SIZEOF(.bss) == 0, "patch code must not use .data/.bss (no RAM init)")
