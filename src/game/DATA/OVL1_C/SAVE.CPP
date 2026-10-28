#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802B5B94_CD610[9] = {
    0x41F00000, 0x00000000, 0x36C1D168, 0x47000000, 0x38000000, 0x3F800000, 0x40000000, 0x40800000,
    0x3F800000,
};
#endif

#if defined(VERSION_DE)
char rodata_unresolved_800C77E4[12] =
    "audio/save.c";
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_d0_467a973914627cab[3] = {
    0x41F00000, 0x00000000, 0x36C1D168,
};

/* ROM-grounded data: src/rw_pool_802B5D70_CD61C_us_rev1.c */
const unsigned int D_blob_d0c5b5842a3473725d51[3] = {
    0x47000000, 0x38000000, 0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802B6300_CD628_us_rev1.c */
const unsigned int D_blob_fe9cdb16e830c8daa646[3] = {
    0x40000000, 0x40800000, 0x3F800000,
};
#endif
