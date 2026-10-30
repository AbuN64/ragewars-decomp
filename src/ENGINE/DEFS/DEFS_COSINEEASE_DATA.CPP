#include "include_asm.h"

const float g_Defs_CosineEaseConstantWords[4] = {
    1.0f, 3.141593f, 1.0f, 0.5f,
};

#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_DefsCosineeaseEncodedWordsAlignmentPad[2] = {
    0x79520000, 0x29000000,
};
#endif

#if defined(VERSION_EU_X)
float k_DefsCosineeaseEncodedWordsBlock3[2] = {
    7.5f, 34.0f,
};
#endif

#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_DefsCosineeaseEncodedWordsBlock2AlignmentPad[2] = {
    0x24050006, 0x24060010,
};
#endif

#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_DefsCosineeaseEncodedWordsBlock1AlignmentPad[2] = {
    0x24630001, 0x03E00008,
};
#endif
