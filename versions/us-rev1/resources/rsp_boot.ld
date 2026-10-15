OUTPUT_ARCH(mips)
SECTIONS
{
  .resource 0x4001000 : AT(0x800DCC40) { KEEP(*(.rsp.boot)) }
  /DISCARD/ : { *(*) }
}
ASSERT(SIZEOF(.resource) == 208, "resource size differs from ROM extent")
INCLUDE versions/us-rev1/symbols.ld
