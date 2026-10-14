OUTPUT_ARCH(mips)
SECTIONS
{
  .text : { *(.text) }
  /DISCARD/ : { *(*) }
}
INCLUDE versions/de/symbols.ld
