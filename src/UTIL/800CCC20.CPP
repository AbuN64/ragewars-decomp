#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802BA910_CD820);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C78FC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8F9C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C85CC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C79DC);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802BA910_CD820_us_rev1.c */
const unsigned int D_blob_df5debf5dbbca8f7ddf8[3] = {
    0x41F00000, 0x00000000, 0x4F000000,
};
#endif
