OUTPUT_ARCH(mips)
SECTIONS
{
  .text : { *(.text) }
  /DISCARD/ : { *(*) }
}
INCLUDE versions/eu/symbols.ld
