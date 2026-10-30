#include "include_asm.h"

/* ROM-grounded data: src/g_InstHdr_GetActorShadowRadiusConstantTailUsRev1_ActorHeaderDefaultConstantsAndFragments.c */
const float g_InstHdr_GetActorShadowRadiusConstantTailUsRev1[3] = {
    256.0f, 81.92f, 61.44f,
};

#if defined(VERSION_US)
char s_ActorHeaderDefaultConstantsAndFragmentsAlTimeTText[8] =
    "alTimeT\000";
#endif

#if defined(VERSION_EU_X)
float k_ActorHeaderDefaultConstantsAndFragmentsEncodedWordsBlock2[2] = {
    128.0f, 255.0f,
};
#endif

#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_ActorHeaderDefaultConstantsAndFragmentsEncodedWordsBlock1AlignmentPad[2] = {
    0x8FB50024, 0x8FB40020,
};
#endif

#if defined(VERSION_DE)
float k_ActorHeaderDefaultConstantsAndFragmentsEncodedWords[2] = {
    0.35f, 0.5f,
};
#endif
