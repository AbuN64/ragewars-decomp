#include "include_asm.h"

#if defined(VERSION_EU)
#ifdef NON_MATCHING
/* Drafted from the other version's body in its unit. */
#else
INCLUDE_ASM("ovl_80400000", Pak_CheckEuropeanSaveAvailability);
#endif
#endif
