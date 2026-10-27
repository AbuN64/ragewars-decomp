#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802A5020_CBC18[2] = {
    0x3F800000, 0x3F000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802A5020_CBC18_us_rev1.c */
const unsigned int D_blob_3abbedbb9d463532a144[2] = {
    0x3F800000, 0x3F000000,
};
#endif
