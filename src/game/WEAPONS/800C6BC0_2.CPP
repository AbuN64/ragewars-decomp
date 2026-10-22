#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80206080_C77C0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1A04);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1DB4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1D74);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80206080_C77C0_us_rev1.c */
const unsigned int D_blob_df97163a36facc18908f[1] = {
    0x3C23D70A,
};
#endif
