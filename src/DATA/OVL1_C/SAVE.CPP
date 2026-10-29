#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const float k_saveFloatConstantWords[9] = {
    3.0e+01f, 0.0f, 5.7762263e-06f, 32768.0f, 3.0517578e-05f, 1.0f,
    2.0f, 4.0f, 1.0f,
};
#endif

#if defined(VERSION_DE)
char s_SaveAudioSaveCText[12] =
    "audio/save.c";
#endif

#if defined(VERSION_US_REV1)
const float k_saveFloatConstantWordsBlock1[3] = {
    3.0e+01f, 0.0f, 5.7762263e-06f,
};

/* ROM-grounded data: src/k_saveFloatConstantWordsBlock2_Save.c */
const float k_saveFloatConstantWordsBlock2[3] = {
    32768.0f, 3.0517578e-05f, 1.0f,
};

/* ROM-grounded data: src/k_saveFloatConstantWordsBlock3_Save.c */
const float k_saveFloatConstantWordsBlock3[3] = {
    2.0f, 4.0f, 1.0f,
};
#endif
