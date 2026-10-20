#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
INCLUDE_RODATA("data_800C", D_80278C10_CA820);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4B34);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80278C10_CA820_us_rev1.c */
const unsigned int D_blob_68c3074edad0ea851da3[1] = {
    0x40800000,
};
#endif
