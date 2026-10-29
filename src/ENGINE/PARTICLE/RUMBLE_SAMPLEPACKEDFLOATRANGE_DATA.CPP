#include "include_asm.h"

/* ROM-grounded data: src/g_Rumble_SamplePackedFloatRangeConstantsUsRev1_RumbleSamplepackedfloatrangeData.c */
const float g_Rumble_SamplePackedFloatRangeConstantsUsRev1[3] = {
    3.0e+01f, 0.0f, 3.051851e-05f,
};

#if defined(VERSION_US)
unsigned int k_RumbleSamplepackedfloatrangeEncodedWords[1] = {
    0x43414D45,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_RumbleSamplepackedfloatrangeEncodedWordsBlock2[1] = {
    0x20202020,
};
#endif

#if defined(VERSION_EU)
unsigned int k_RumbleSamplepackedfloatrangeEncodedWordsBlock1[1] = {
    0x00021043,
};
#endif

#if defined(VERSION_DE)
unsigned int k_RumbleSamplepackedfloatrangeOneWords[1] = {
    0x3F800000,
};
#endif
