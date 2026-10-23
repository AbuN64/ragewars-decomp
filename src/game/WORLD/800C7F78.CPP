#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8022EC3C_C8B78[2] = {
    0x3F83126F, 0xBF83126F,
};
#endif

#if defined(VERSION_EU_X)
char rodata_unresolved_800C3178[8] =
    "els inde";
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C3138[2] = {
    0x2694FFFF, 0x8EA20024,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8022EC3C_C8B78_us_rev1.c */
const unsigned int D_blob_db6a541da5827899415b[2] = {
    0x3F83126F, 0xBF83126F,
};
#endif
