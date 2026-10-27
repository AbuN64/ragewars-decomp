#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_80209DAC_C79B0[2] = {
    0x3E860A93, 0x3E860A93,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C1BF8[2] = {
    0x001C0000, 0x00080008,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C1FA8[2] = {
    0x00229F54, 0x3B800000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C1F68[2] = {
    0x1440FFFD, 0x00000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80209DAC_C79B0_us_rev1.c */
const unsigned int D_blob_a2d7485e1df5f3becc88[2] = {
    0x3E860A93, 0x3E860A93,
};
#endif
