#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int k_CcollisionIntegrategravityanddragEncodedWords[11] = {
    0x3D888889, 0x41700000, 0x3F800000, 0x3F000000, 0x3F800000, 0x4123D70A, 0x41F5C28F, 0x3E51B717,
    0x3F800000, 0x4083126F, 0x3F8637BE,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int k_CcollisionIntegrategravityanddragEncodedWordsBlock1[4] = {
    0x3D888889, 0x41700000, 0x3F800000, 0x3F000000,
};

/* ROM-grounded data: src/rw_pool_8023D158_C9320_us_rev1.c */
const unsigned int k_CcollisionIntegrategravityanddragOneWords[1] = {
    0x3F800000,
};

const unsigned int k_CcollisionIntegrategravityanddragEncodedWordsBlock2[6] = {
    0x4123D70A, 0x41F5C28F, 0x3E51B717, 0x3F800000, 0x4083126F, 0x3F8637BE,
};
#endif
