#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const float k_lookatFloatConstantWords[7] = {
    -1.0f, 1.0f, 1.0f, 65536.0f, 1.0f, 65536.0f,
    1.5258789e-05f,
};
#endif

#if defined(VERSION_EU)
unsigned int k_LookatEncodedWordsBlock2[3] = {
    0x00000000, 0x41F00000, 0x00000000,
};
#endif

#if defined(VERSION_DE)
float k_LookatEncodedWordsBlock1[3] = {
    0.5f, -1.0f, 2.0f,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/k_LookatSignedUnitBoundsWordsVariant1_Lookat.c */
const float k_LookatSignedUnitBoundsWordsVariant1[2] = {
    -1.0f, 1.0f,
};

/* ROM-grounded data: src/k_lookatFloatConstantWordsBlock1_Lookat.c */
const float k_lookatFloatConstantWordsBlock1[2] = {
    1.0f, 65536.0f,
};

/* ROM-grounded data: src/k_LookatOneWords_Lookat.c */
const unsigned int k_LookatOneWords[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/k_lookatFloatConstantWordsBlock2_Lookat.c */
const unsigned int k_lookatFloatConstantWordsBlock2[1] = {
    0x47800000,
};

/* ROM-grounded data: src/k_lookatFloatConstantWordsBlock3_Lookat.c */
const unsigned int k_lookatFloatConstantWordsBlock3[1] = {
    0x37800000,
};
#endif
