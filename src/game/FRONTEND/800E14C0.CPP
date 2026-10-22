#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8041CAD8_E20C0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DC148);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E8CD8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EDB18);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD498);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8041CAD8_E20C0_us_rev1.c */
const unsigned int D_blob_9ec24c11a49589b0ad4b[2] = {
    0x46200000, 0x3C8EFA36,
};
#endif
