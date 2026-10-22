#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_US)
#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C205C);
#endif
#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C205C);
#endif
#endif
