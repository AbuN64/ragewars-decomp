#include "include_asm.h"

#if defined(VERSION_US)
unsigned int k_MenuModelPreviewTuningAndFragmentsEncodedWords[2] = {
    0x00000000, 0x00124D55,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_MenuModelPreviewTuningAndFragmentsEncodedWordsBlock2[2] = {
    0x3C8EFA36, 0x3F800000,
};
#endif

#if defined(VERSION_EU)
unsigned int k_MenuModelPreviewTuningAndFragmentsEncodedWordsBlock3[2] = {
    0x013A013B, 0x08000063,
};
#endif

#if defined(VERSION_DE)
unsigned int k_MenuModelPreviewTuningAndFragmentsEncodedWordsBlock1[2] = {
    0x0041D3A0, 0x0041D258,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8041CAD8_E20C0_us_rev1.c */
#endif
