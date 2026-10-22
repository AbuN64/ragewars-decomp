#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80217594_C7EDC);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2124);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C24D4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2494);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C21F4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80217594_C7EDC_us_rev1.c */
const unsigned int D_blob_667c528ce0704f8f6261[2] = {
    0x43E10000, 0x44160000,
};
#endif
