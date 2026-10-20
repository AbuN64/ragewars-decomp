#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80293F44_CB1B0);
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_func_80294158_de_800C5774);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80293F44_CB1B0_us_rev1.c */
const unsigned int D_blob_87177d2ab6f2ddab1fb2[1] = {
    0x42340000,
};
#endif
