OUTPUT_ARCH(mips)
SECTIONS
{
  .data : SUBALIGN(1) { *(.rdata .rdata.* .rodata .rodata.* .data .data.* .sdata .sdata.* .lit4 .lit8) }
  /DISCARD/ : { *(*) }
}
INCLUDE versions/eu-x/symbols.ld
