#include "include_asm.h"

/* ROM-grounded data: src/rw_pool_802625F0_C9F48_us_rev1.c */
const unsigned int g_animationFrameAngleScale_StorageWords[1] = {
    0x38C9116D,
};

#if defined(VERSION_US)
unsigned int k_AnimstatePrepareanimationframesEncodedWords[1] = {
    0x6E546578,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_AnimstatePrepareanimationframesTwoHundredFiftyFiveWords[1] = {
    0x437F0000,
};
#endif

#if defined(VERSION_EU)
unsigned int k_AnimstatePrepareanimationframesEncodedWordsBlock2[1] = {
    0x080AFD7E,
};
#endif

#if defined(VERSION_DE)
unsigned int k_AnimstatePrepareanimationframesEncodedWordsBlock1[1] = {
    0x696E6465,
};
#endif
