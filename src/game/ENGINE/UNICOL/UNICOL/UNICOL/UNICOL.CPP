#include "include_asm.h"

/* 800C37E4.CPP */
#if defined(VERSION_DE)
unsigned int g_UnicolEncodedWordsBlock1[3] = {
    0x40400000, 0x3F800000, 0x3C0EFA36,
};
#endif

/* 800C8710_15.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int k_UnicolEncodedWords[9] = {
    0x3F000000, 0x3F000000, 0x3F800000, 0x3EB33333, 0x3F800000, 0x423E0000, 0x3F800000, 0x4123D70A,
    0x3D888889,
};
#endif

#if defined(VERSION_US)
unsigned int k_UnicolEncodedWordsBlock7[3] = {
    0x0F000000, 0x00000F6D, 0x5F4C6967,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_UnicolEncodedWordsBlock11[3] = {
    0x3F800000, 0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_EU)
unsigned int k_UnicolEncodedWordsBlock9[3] = {
    0x00E61023, 0x080AFAA9, 0xACA20004,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int k_UnicolEncodedWordsBlock2[4] = {
    0x3F000000, 0x3F000000, 0x3F800000, 0x3EB33333,
};

/* ROM-grounded data: src/rw_pool_8024570C_C94C0_us_rev1.c */
const unsigned int k_UnicolOneWords[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_802459A0_C94C4_us_rev1.c */
const unsigned int k_UnicolEncodedWordsBlock5[2] = {
    0x423E0000, 0x3F800000,
};

/* ROM-grounded data: src/rw_pool_80245AD8_C94CC_us_rev1.c */
const unsigned int k_UnicolEncodedWordsBlock3[1] = {
    0x4123D70A,
};

/* ROM-grounded data: src/rw_pool_80245C38_C94D0_us_rev1.c */
const unsigned int k_UnicolEncodedWordsBlock4[1] = {
    0x3D888889,
};
#endif

/* 800C88D4.CPP */
#if defined(VERSION_US_REV1)
unsigned int g_UnicolEncodedWordsBlock2[3] = {
    0x3F800000, 0x3F800000, 0x3F800000,
};
#endif
