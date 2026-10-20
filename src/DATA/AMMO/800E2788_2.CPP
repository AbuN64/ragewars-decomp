#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_shared_800EEDE0);
#endif

#if defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_unresolved_800E9FA6);
#endif
