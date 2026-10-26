#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802B5288_CD558[2] = {
    0x37800000, 0x3F800000,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int D_802B5300_CD560[10] = {
    0x00000000, 0x00000000, 0x3FF00000, 0x00000000, 0x3FE00000, 0x00000000, 0x3FE00000, 0x00000000,
    0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_800C7658[8] =
    "_t\014m_Gam";
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C8CF8[2] = {
    0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_EU)
char rodata_unresolved_800C8328[8] =
    "D\026\000\000\077333";
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C7738[2] = {
    0x38000000, 0x00000000,
};
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
