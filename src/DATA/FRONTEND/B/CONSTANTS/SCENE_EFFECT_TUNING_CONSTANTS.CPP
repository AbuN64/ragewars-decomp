#include "include_asm.h"

/* ROM-grounded data: src/g_Events_IncrementNearbyPlayerCounterConstantsUsRev1_SceneEffectTuningConstants.c */
const unsigned int g_Events_IncrementNearbyPlayerCounterConstantsUsRev1[1] = {
    0x4123D70A,
};

#if defined(VERSION_US)
unsigned int k_SceneEffectTuningConstantsEncodedWords[2] = {
    0x00000000, 0x0B43536B,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_SceneEffectTuningConstantsEncodedWordsBlock3[2] = {
    0xC0800000, 0x3F000000,
};
#endif

#if defined(VERSION_EU)
unsigned int k_SceneEffectTuningConstantsEncodedWordsBlock2[2] = {
    0x000423C3, 0x00882821,
};
#endif

#if defined(VERSION_DE)
unsigned int k_SceneEffectTuningConstantsEncodedWordsBlock1[2] = {
    0x3F800000, 0xACA40000,
};
#endif
