#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802B5570_CD590[3] = {
    0x3FFFFEB0, 0x47000000, 0x38000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802B5570_CD590_us_rev1.c */
const unsigned int D_blob_b3674e9ebfb193e144c8[3] = {
    0x3FFFFEB0, 0x47000000, 0x38000000,
};
#endif
