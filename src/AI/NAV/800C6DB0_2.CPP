#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80209DAC_C79B0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1BF8);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1FA8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1F68);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80209DAC_C79B0_us_rev1.c */
const unsigned int D_blob_a2d7485e1df5f3becc88[2] = {
    0x3E860A93, 0x3E860A93,
};
#endif
