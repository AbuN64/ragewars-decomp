#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802BF514_CDB10[4] = {
    0x40800000, 0x3F800000, 0x3B490FDB, 0x3C490FDB,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802BF514_CDB10_us_rev1.c */
const unsigned int D_blob_a2a46cb3e7d34be4a37c[4] = {
    0x40800000, 0x3F800000, 0x3B490FDB, 0x3C490FDB,
};
#endif
