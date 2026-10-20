#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_shared_800EED80);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9F45);
#endif
