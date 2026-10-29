#include "include_asm.h"

/* ROM-grounded data: src/g_Rumble_SamplePackedFloatRangeConstantsUsRev1_RumbleSamplepackedfloatrangeData.c */
const unsigned int g_Rumble_SamplePackedFloatRangeConstantsUsRev1[3] = {
    0x41F00000, 0x00000000, 0x38000100,
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
