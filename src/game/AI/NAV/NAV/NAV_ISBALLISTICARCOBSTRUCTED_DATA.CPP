#include "include_asm.h"

const unsigned int k_NavIsballisticarcobstructedEncodedWords[3] = {
    0x3F800000, 0x3FAAAAAB, 0x3F000000,
};

#if defined(VERSION_US)
unsigned int k_NavIsballisticarcobstructedEncodedWordsBlock1[1] = {
    0x52000000,
};
#endif

#if defined(VERSION_DE)
unsigned int k_NavIsballisticarcobstructedEncodedWordsBlock2[1] = {
    0x10400002,
};
#endif
