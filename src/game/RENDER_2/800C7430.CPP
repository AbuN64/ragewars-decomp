#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8021B1E4_C8030);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2274);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2624);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C25E4);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2344);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8021B1E4_C8030_us_rev1.c */
const unsigned int D_blob_ec5bf9e6172d2e35c3c8[1] = {
    0x4B18967F,
};
#endif
