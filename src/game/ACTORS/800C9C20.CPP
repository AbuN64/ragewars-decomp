#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
const unsigned int D_80278C10_CA820[1] = {
    0x40800000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C4B34[3] = {
    0x3F800000, 0x3F800000, 0x40E00000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80278C10_CA820_us_rev1.c */
const unsigned int D_blob_68c3074edad0ea851da3[1] = {
    0x40800000,
};
#endif
