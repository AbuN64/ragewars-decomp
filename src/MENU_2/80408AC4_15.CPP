#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_EU)
#ifdef NON_MATCHING
/* Drafted from the shared unit body (other versions' twin). */
#else
INCLUDE_ASM("ovl_80400000", func_8040C700_de);
#endif
#endif
