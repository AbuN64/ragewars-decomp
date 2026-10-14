OUTPUT_ARCH(mips)
SECTIONS
{
  .text : { *(.text) }
  /DISCARD/ : { *(*) }
}
INCLUDE versions/eu-x/symbols.ld
