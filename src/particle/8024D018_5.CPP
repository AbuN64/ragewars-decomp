#include "include_asm.h"

#if defined(VERSION_EU_X) || defined(VERSION_US)
#if defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C3F6C);
#endif
#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3F6C);
#endif
#endif
