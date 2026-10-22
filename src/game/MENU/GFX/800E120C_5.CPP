#include "include_asm.h"

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800E1220);
#endif
#if !(defined(VERSION_DE))
INCLUDE_RODATA("data_800C", rodata_unresolved_800E1220);
#endif
