OUTPUT_ARCH(mips)
SECTIONS
{
  .resource 0x800DCC34 : AT(0x800DCC34) { KEEP(*(.rsp.alignment)) }
  /DISCARD/ : { *(*) }
}
ASSERT(SIZEOF(.resource) == 8, "resource size differs from ROM extent")
INCLUDE versions/us-rev1/symbols.ld
