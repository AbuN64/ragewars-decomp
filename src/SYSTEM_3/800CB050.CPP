#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802A63A4_CBC50);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5DF8);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C61A8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C6168);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5EC8);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802A63A4_CBC50_us_rev1.c */
const unsigned int D_blob_f456bd3bc88b06ab000f[2] = {
    0x3C23D70A, 0x3E95CBEC,
};
#endif
