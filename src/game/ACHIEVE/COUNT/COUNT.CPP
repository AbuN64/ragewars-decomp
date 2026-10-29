#include "include_asm.h"

/* CountEncodedWordsBlock1.CPP */
#if defined(VERSION_US)
unsigned int k_CountEncodedWordsBlock1[1] = {
    0x00000010,
};
#endif

#if defined(NON_MATCHING) && defined(VERSION_US)
unsigned int k_CountEncodedWords[16] = {
    0x00000010, 0x00426BB0, 0x00426C38, 0x00426CA0, 0x00426CD0, 0x00426D4C, 0x00426DF8, 0x00426DF8,
    0x00426DC0, 0x00426DE4, 0x3BA3D70A, 0x42C80000, 0x43160000, 0x4F000000, 0x437F0000, 0x40800000,
};
#endif

/* 800E19AC.CPP */
#if defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/unresolved/800E19AC */
unsigned int g_CountEncodedWords[1] = {
    0x00000037,
};
#endif
