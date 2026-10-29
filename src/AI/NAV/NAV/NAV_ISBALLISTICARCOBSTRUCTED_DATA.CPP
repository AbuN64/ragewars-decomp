#include "include_asm.h"

const float k_NavIsballisticarcobstructedEncodedWords[3] = {
    1.0f, 1.3333334f, 0.5f,
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
