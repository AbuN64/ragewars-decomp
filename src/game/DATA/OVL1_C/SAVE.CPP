#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const unsigned int k_saveFloatConstantWords[9] = {
    0x41F00000, 0x00000000, 0x36C1D168, 0x47000000, 0x38000000, 0x3F800000, 0x40000000, 0x40800000,
    0x3F800000,
};
#endif

#if defined(VERSION_DE)
char s_SaveAudioSaveCText[12] =
    "audio/save.c";
#endif

#if defined(VERSION_US_REV1)
const unsigned int k_saveFloatConstantWordsBlock1[3] = {
    0x41F00000, 0x00000000, 0x36C1D168,
};

/* ROM-grounded data: src/k_saveFloatConstantWordsBlock2_Save.c */
const unsigned int k_saveFloatConstantWordsBlock2[3] = {
    0x47000000, 0x38000000, 0x3F800000,
};

/* ROM-grounded data: src/k_saveFloatConstantWordsBlock3_Save.c */
const unsigned int k_saveFloatConstantWordsBlock3[3] = {
    0x40000000, 0x40800000, 0x3F800000,
};
#endif
