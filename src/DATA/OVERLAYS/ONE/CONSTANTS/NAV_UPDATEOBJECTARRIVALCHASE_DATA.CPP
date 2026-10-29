#include "include_asm.h"

/* 800C6E84_20.CPP */
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* ROM-grounded data: src/k_navUpdateobjectarrivalchaseDataFloatConstantWords_NavUpdateobjectarrivalchaseData.c */
const unsigned int k_navUpdateobjectarrivalchaseDataFloatConstantWords[2] = {
    0x42CCCCCC, 0x424CCCCC,
};
#endif

#if defined(VERSION_EU_X)
float k_NavUpdateobjectarrivalchaseEncodedWordsBlock2[2] = {
    48.0f, 255.0f,
};
#endif

#if defined(VERSION_EU)
unsigned int k_NavUpdateobjectarrivalchaseEncodedWordsBlock1[2] = {
    0x000B5842, 0x01646024,
};
#endif

/* 800C71D8.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800C71D8 */
unsigned int g_navUpdateobjectarrivalchaseDataFloatConstantWords[2] = {
    0x41F00000, 0x00000000,
};
#endif
