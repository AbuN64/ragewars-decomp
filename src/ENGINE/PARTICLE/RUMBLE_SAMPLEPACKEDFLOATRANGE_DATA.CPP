#include "include_asm.h"

/* ROM-grounded data: src/g_Rumble_SamplePackedFloatRangeConstantsUsRev1_RumbleSamplepackedfloatrangeData.c */
const float g_Rumble_SamplePackedFloatRangeConstantsUsRev1[3] = {
    3.0e+01f, 0.0f, 3.051851e-05f,
};

#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_RumbleSamplepackedfloatrangeEncodedWordsAlignmentPad[1] = {
    0x43414D45,
};
#endif

#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_RumbleSamplepackedfloatrangeEncodedWordsBlock2AlignmentPad[1] = {
    0x20202020,
};
#endif

#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_RumbleSamplepackedfloatrangeEncodedWordsBlock1AlignmentPad[1] = {
    0x00021043,
};
#endif

#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_RumbleSamplepackedfloatrangeOneWordsAlignmentPad[1] = {
    0x3F800000,
};
#endif
