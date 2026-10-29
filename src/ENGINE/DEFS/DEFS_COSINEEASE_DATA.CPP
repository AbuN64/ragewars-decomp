#include "include_asm.h"

const unsigned int g_Defs_CosineEaseConstantWords[4] = {
    0x3F800000, 0x40490FDC, 0x3F800000, 0x3F000000,
};

#if defined(VERSION_US)
unsigned int k_DefsCosineeaseEncodedWords[2] = {
    0x79520000, 0x29000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_DefsCosineeaseEncodedWordsBlock3[2] = {
    0x40F00000, 0x42080000,
};
#endif

#if defined(VERSION_EU)
unsigned int k_DefsCosineeaseEncodedWordsBlock2[2] = {
    0x24050006, 0x24060010,
};
#endif

#if defined(VERSION_DE)
unsigned int k_DefsCosineeaseEncodedWordsBlock1[2] = {
    0x24630001, 0x03E00008,
};
#endif
