#include "include_asm.h"

#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
INCLUDE_ASM("ovl_80400000", func_804143B0_de);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", rodata_unresolved_8041447C);
#endif
