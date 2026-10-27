#include "include_asm.h"

/* ROM-grounded data: src/rw_pool_80403C98_E18B4_us_rev1.c */
const unsigned int D_blob_2f2966fe540613a7b9f9[1] = {
    0x3F800000,
};

#if defined(VERSION_US)
const char rodata_unresolved_800DB938[8] =
    "OSS3equR";
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E84C8[2] = {
    0x004314AC, 0x00431448,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DCC88[2] = {
    0x004040E0, 0x00404120,
};
#endif
