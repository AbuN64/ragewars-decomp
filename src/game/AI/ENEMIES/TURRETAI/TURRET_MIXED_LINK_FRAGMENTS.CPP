#include "include_asm.h"

/* DATA_800C6AB0.CPP */
#if defined(VERSION_US)
const char k_TurretMixedLinkFragmentsEncodedBytes[20] =
    "RGBR\000\000\000\000\000\000\000\000\077\200\000\000\000\000\000\000";
#endif

#if defined(VERSION_EU)
const unsigned int k_TurretMixedLinkFragmentsEncodedWords[5] = {
    0x8E02000C, 0x3C060500, 0x00000000, 0x3F800000, 0x00000000,
};
#endif

/* 800C6DB0.CPP */
#if defined(VERSION_DE) || defined(VERSION_EU_X)
#if defined(VERSION_DE)
unsigned int k_TurretMixedLinkFragmentsEncodedWordsBlock1[2] = {
    0x00209EF4, 0x00209EF4,
};
#endif
#if defined(VERSION_EU_X)
unsigned int k_TurretMixedLinkFragmentsEncodedWordsBlock1[5] = {
    0x41000000, 0x41B80000, 0x00000000, 0x3F800000, 0x00000000,
};
#endif
#endif
