#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8022EC3C_C8B78);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3178);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3138);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8022EC3C_C8B78_us_rev1.c */
const unsigned int D_blob_db6a541da5827899415b[2] = {
    0x3F83126F, 0xBF83126F,
};
#endif
