#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8043E7AC_E2F68);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9B7C);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800EE9BC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE33C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8043E7AC_E2F68_us_rev1.c */
const unsigned int D_blob_c5d40ecd1d01bf2a8b59[1] = {
    0x3F800000,
};
#endif
