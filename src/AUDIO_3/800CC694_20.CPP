#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B5288_CD558);
#endif

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B5300_CD560);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7658);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8CF8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8328);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7738);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802B5288_CD558_us_rev1.c */
const unsigned int D_blob_7cfc0ff81f0572c9de9f[2] = {
    0x37800000, 0x3F800000,
};

const unsigned int D_auto_src_rw_pool_802B5300_CD560_us_rev1[10] = {
    0x00000000, 0x00000000, 0x3FF00000, 0x00000000, 0x3FE00000, 0x00000000, 0x3FE00000, 0x00000000,
    0x00000000, 0x00000000,
};
#endif
