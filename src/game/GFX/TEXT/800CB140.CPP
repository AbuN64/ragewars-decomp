#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802A84F8_CBD40);
#endif

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C5EE4);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C6294);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C6254);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5FB4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802A84F8_CBD40_us_rev1.c */
const unsigned int D_blob_ca5f9f198e28f70ece1c[1] = {
    0x3F800000,
};
#endif
