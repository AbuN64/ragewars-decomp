#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802B0C94_CD310[5] = {
    0x42FE0000, 0x4F000000, 0x3F800000, 0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C73F4[3] = {
    0x74656D54, 0x00008855, 0x02000800,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C8A94[3] = {
    0x002056F0, 0x0027924C, 0x00000000,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_d0_00a0a4ab5b380cf3[3] = {
    0x42FE0000, 0x4F000000, 0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802B1990_CD31C_us_rev1.c */
const unsigned int D_blob_d3d40c49a69ba592f214[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802B1A40_CD320_us_rev1.c */
const unsigned int D_blob_823d3d70d903245f79f8[1] = {
    0x3F800000,
};
#endif
