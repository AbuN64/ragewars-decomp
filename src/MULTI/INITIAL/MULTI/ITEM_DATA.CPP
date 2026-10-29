#include "include_asm.h"

#if !(defined(VERSION_US))
const unsigned int k_ItemEncodedWords[3] = {
    0x437F0000, 0x437F0000, 0x437F0000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_ItemEncodedWordsBlock2[1] = {
    0x00007530,
};
#endif

#if defined(VERSION_EU)
unsigned int k_ItemEncodedWordsBlock3[1] = {
    0xE9F71877,
};
#endif

#if defined(VERSION_DE)
unsigned int k_ItemEncodedWordsBlock1[1] = {
    0x73000000,
};
#endif
