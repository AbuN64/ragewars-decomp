#include "include_asm.h"

/* 800C6E24.CPP */
/* ROM-grounded data: src/rw_pool_8020AA0C_C7A24_us_rev1.c */
const unsigned int g_Portal_GetEngagementDistanceConstantWords[2] = {
    0x3F800000, 0x3F060A93,
};

#if defined(VERSION_US)
unsigned int k_PortalEngagementAndSearchLiteralEncodedWords[1] = {
    0x5F446973,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_PortalEngagementAndSearchLiteralEncodedWordsBlock2[1] = {
    0xC2480000,
};
#endif

#if defined(VERSION_EU)
unsigned int k_PortalEngagementAndSearchLiteralEncodedWordsBlock1[1] = {
    0x3C04800E,
};
#endif

#if defined(VERSION_DE)
unsigned int k_PortalEngagementAndSearchLiteralNegativeOneWords[1] = {
    0xBF800000,
};
#endif

/* 800C6E2C.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800C6E2C */
unsigned int g_PortalEngagementAndSearchLiteralEncodedWords[1] = {
    0x3FC00000,
};
#endif
