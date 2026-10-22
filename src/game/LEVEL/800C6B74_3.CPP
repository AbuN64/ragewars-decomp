#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80204A68_C7774);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1D68);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1D28);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1A88);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80204A68_C7774_us_rev1.c */
const unsigned int D_blob_cc0e81d2f48cf663aae0[1] = {
    0x3C010204,
};
#endif
