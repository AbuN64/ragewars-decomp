#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B1FE8_CD330);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7404);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8AA4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C80D4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802B1FE8_CD330_us_rev1.c */
const unsigned int D_blob_049096e9a996bdbf5044[1] = {
    0x3F800000,
};
#endif
