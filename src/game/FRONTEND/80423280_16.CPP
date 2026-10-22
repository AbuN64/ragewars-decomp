#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_func_8042C018_de_800EE170);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9333);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EE173);
#endif
