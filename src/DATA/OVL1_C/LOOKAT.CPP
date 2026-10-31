#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const float k_lookatFloatConstantWords[7] = {
    -1.0f, 1.0f, 1.0f, 65536.0f, 1.0f, 65536.0f,
    1.5258789e-05f,
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
const float k_LookatOneWords[1] = {
    1.0f,
};

/* ROM-grounded data: src/k_lookatFloatConstantWordsBlock2_Lookat.c */
const RestLinkerAlignmentFill4 g_lookatFloatConstantBlock2LinkerAlignmentFill631 = {
    { 71, 128, 0, 0 },
};

/* ROM-grounded data: src/k_lookatFloatConstantWordsBlock3_Lookat.c */
const float k_lookatFloatConstantWordsBlock3[1] = {
    1.5258789e-05f,
};
#endif
