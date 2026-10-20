#include "include_asm.h"

const char D_auto_rodata_shared_800E0D90[18] = "Single Save Block";

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DBA22);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E85B2);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800ED3F2);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCD72);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E0DA2);
#endif
