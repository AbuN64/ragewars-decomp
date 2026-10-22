#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", D_80212FBC_C7DD0);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C23C8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2388);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80212FBC_C7DD0_us_rev1.c */
const unsigned int D_blob_14d4b3350c473f56c2b7[2] = {
    0x42CCCCCC, 0x424CCCCC,
};
#endif
