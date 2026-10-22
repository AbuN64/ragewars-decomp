#include "include_asm.h"

const char D_auto_rodata_shared_800E0D00[22] = "Mempak read temp data";

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DB996);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E8526);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800ED366);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCCE6);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E0D16);
#endif
