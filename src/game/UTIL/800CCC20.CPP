#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802BA910_CD820[3] = {
    0x41F00000, 0x00000000, 0x4F000000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C78FC[1] = {
    0x000F534D,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C8F9C[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C85CC[1] = {
    0x41F00000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C79DC[1] = {
    0x72656164,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802BA910_CD820_us_rev1.c */
const unsigned int D_blob_df5debf5dbbca8f7ddf8[3] = {
    0x41F00000, 0x00000000, 0x4F000000,
};
#endif
