#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
const unsigned int D_80212FBC_C7DD0[2] = {
    0x42CCCCCC, 0x424CCCCC,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C23C8[2] = {
    0x42400000, 0x437F0000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C2388[2] = {
    0x000B5842, 0x01646024,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80212FBC_C7DD0_us_rev1.c */
const unsigned int D_blob_14d4b3350c473f56c2b7[2] = {
    0x42CCCCCC, 0x424CCCCC,
};
#endif
