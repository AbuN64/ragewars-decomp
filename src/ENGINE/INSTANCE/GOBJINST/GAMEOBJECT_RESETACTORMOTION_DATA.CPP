#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const float g_actorMotionResetUnitConstants[2] = {
    1.0f, 0.8f,
};
#endif

#if defined(VERSION_US)
unsigned int k_GameobjectResetactormotionEncodedWords[1] = {
    0x63697479,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_GameobjectResetactormotionEncodedWordsBlock3[1] = {
    0x3F7FFF58,
};
#endif

#if defined(VERSION_EU)
unsigned int k_GameobjectResetactormotionEncodedWordsBlock2[1] = {
    0x00002821,
};
#endif

#if defined(VERSION_DE)
unsigned int k_GameobjectResetactormotionEncodedWordsBlock1[1] = {
    0x6E737461,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/GameObject_ResetActorMotionConstantsUsRev1.c */
const unsigned int g_GameObject_ResetActorMotionConstantsUsRev1[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/Gobjinst_HasClearPathToActorConstantsUsRev1.c */
const unsigned int g_Gobjinst_HasClearPathToActorConstantsUsRev1[1] = {
    0x3F4CCCCD,
};
#endif
