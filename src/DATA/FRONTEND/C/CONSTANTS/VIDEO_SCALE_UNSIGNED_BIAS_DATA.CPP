#include "include_asm.h"

/* ROM-grounded data: src/g_videoScaleUnsignedBias_StorageWords_VideoScaleUnsignedBiasData.c */
const unsigned int g_videoScaleUnsignedBias_StorageWords[3] = {
    0x41F00000, 0x00000000, 0x4F000000,
};

#if defined(VERSION_US)
unsigned int k_VideoScaleUnsignedBiasEncodedWords[1] = {
    0x000F534D,
};
#endif

#if defined(VERSION_EU)
unsigned int k_VideoScaleUnsignedBiasThirtyWords[1] = {
    0x41F00000,
};
#endif

#if defined(VERSION_DE)
unsigned int k_VideoScaleUnsignedBiasEncodedWordsBlock1[1] = {
    0x72656164,
};
#endif
