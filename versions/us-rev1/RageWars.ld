OUTPUT_ARCH(mips)
SECTIONS
{
  .text : { *(.text) }
  /DISCARD/ : { *(*) }
}
INCLUDE versions/us-rev1/symbols.ld
