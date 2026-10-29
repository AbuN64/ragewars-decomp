#include "include_asm.h"

/* 800C6E84_13.CPP */
#if defined(VERSION_US)
unsigned int k_SetselectedtargetEncodedWords[2] = {
    0x08000000, 0x00001043,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_SetselectedtargetEncodedWordsBlock3[2] = {
    0x3FE52EDF, 0x3FE52EDF,
};
#endif

#if defined(VERSION_EU)
unsigned int k_SetselectedtargetEncodedWordsBlock2[2] = {
    0x00000000, 0x90420000,
};
#endif

#if defined(VERSION_DE)
unsigned int k_SetselectedtargetEncodedWordsBlock1[2] = {
    0x3F800000, 0x42A00000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/g_Target_FindNearestFlaggedTargetLiteralWord.c */
#endif

/* 800C7008.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800C7008 */
unsigned int g_Target_FindNearestFlaggedTargetConstantWords[2] = {
    0x3DCCCCCD, 0x3C8EFA36,
};
#endif
