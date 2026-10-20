#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80403C98_E18B4);
#endif

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800DB938);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E84C8);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800ED308);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCC88);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80403C98_E18B4_us_rev1.c */
const unsigned int D_blob_2f2966fe540613a7b9f9[1] = {
    0x3F800000,
};
#endif
