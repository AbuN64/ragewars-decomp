#include "include_asm.h"

/* ROM-grounded data: src/g_InstHdr_GetActorShadowRadiusConstantTailUsRev1_ActorHeaderDefaultConstantsAndFragments.c */
const unsigned int g_InstHdr_GetActorShadowRadiusConstantTailUsRev1[3] = {
    0x43800000, 0x42A3D70A, 0x4275C28F,
};

#if defined(VERSION_US)
char s_ActorHeaderDefaultConstantsAndFragmentsAlTimeTText[8] =
    "alTimeT\000";
#endif

#if defined(VERSION_EU_X)
unsigned int k_ActorHeaderDefaultConstantsAndFragmentsEncodedWordsBlock2[2] = {
    0x43000000, 0x437F0000,
};
#endif

#if defined(VERSION_EU)
unsigned int k_ActorHeaderDefaultConstantsAndFragmentsEncodedWordsBlock1[2] = {
    0x8FB50024, 0x8FB40020,
};
#endif

#if defined(VERSION_DE)
unsigned int k_ActorHeaderDefaultConstantsAndFragmentsEncodedWords[2] = {
    0x3EB33333, 0x3F000000,
};
#endif
