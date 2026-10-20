#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCFEC);
#endif
#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800DCFEC);
#endif
#endif
