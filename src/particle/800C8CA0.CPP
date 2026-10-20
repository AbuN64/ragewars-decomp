#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8024D028_C98A0);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3EA4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8024D028_C98A0_us_rev1.c */
const unsigned int D_blob_7cc7e29c68701fc467d3[1] = {
    0x3F800000,
};
#endif
