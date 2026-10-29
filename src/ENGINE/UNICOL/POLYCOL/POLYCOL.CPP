#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char k_PolycolEncodedBytes[8] =
    "\077333\077333";
#endif

#if defined(VERSION_US)
unsigned int k_PolycolEncodedWordsBlock1[1] = {
    0x73520000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_PolycolEncodedWordsBlock3[1] = {
    0x4F000000,
};
#endif

#if defined(VERSION_EU)
unsigned int k_PolycolEncodedWordsBlock2[1] = {
    0x50400027,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/k_PolycolEncodedWords_Polycol.c */
const unsigned int k_PolycolEncodedWords[2] = {
    0x3F333333, 0x3F333333,
};
#endif
