#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const unsigned int k_lookatFloatConstantWords[7] = {
    0xBF800000, 0x3F800000, 0x3F800000, 0x47800000, 0x3F800000, 0x47800000, 0x37800000,
};
#endif

#if defined(VERSION_EU)
unsigned int k_LookatEncodedWordsBlock2[3] = {
    0x00000000, 0x41F00000, 0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int k_LookatEncodedWordsBlock1[3] = {
    0x3F000000, 0xBF800000, 0x40000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802B6900_CD6C8_us_rev1.c */
const unsigned int k_LookatSignedUnitBoundsWordsVariant1[2] = {
    0xBF800000, 0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802B6B80_CD6D0_us_rev1.c */
const unsigned int k_lookatFloatConstantWordsBlock1[2] = {
    0x3F800000, 0x47800000,
};

/* ROM-grounded data: src/rw_pool_802B6C6C_CD6D8_us_rev1.c */
const unsigned int k_LookatOneWords[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802B6CBC_CD6DC_us_rev1.c */
const unsigned int k_lookatFloatConstantWordsBlock2[1] = {
    0x47800000,
};

/* ROM-grounded data: src/rw_pool_802B6D54_CD6E0_us_rev1.c */
const unsigned int k_lookatFloatConstantWordsBlock3[1] = {
    0x37800000,
};
#endif
