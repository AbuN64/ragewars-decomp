#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B3F10_CD418);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8BA4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C81D4);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C75E4);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_802B3F10_CD418_us_rev1[6] = {
    0x41F00000, 0x00000000, 0x36C1D168, 0x3F800000, 0x3F100000, 0x00000000,
};

/* ROM-grounded data: src/rw_pool_802B450C_CD430_us_rev1.c */
const unsigned int D_blob_6fbe661482a5ca2e700d[1] = {
    0x3F800000,
};
#endif
