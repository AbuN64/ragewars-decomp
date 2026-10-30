#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const float g_actorMotionResetUnitConstants[2] = {
    1.0f, 0.8f,
};
#endif

#if defined(VERSION_US)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_GameobjectResetactormotionEncodedWordsAlignmentPad[1] = {
    0x63697479,
};
#endif

#if defined(VERSION_EU_X)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_GameobjectResetactormotionEncodedWordsBlock3AlignmentPad[1] = {
    0x3F7FFF58,
};
#endif

#if defined(VERSION_EU)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_GameobjectResetactormotionEncodedWordsBlock2AlignmentPad[1] = {
    0x00002821,
};
#endif

#if defined(VERSION_DE)
/* Alignment fill to the next 16-byte object boundary. */
unsigned int k_GameobjectResetactormotionEncodedWordsBlock1AlignmentPad[1] = {
    0x6E737461,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/GameObject_ResetActorMotionConstantsUsRev1.c */
const float g_GameObject_ResetActorMotionConstantsUsRev1[1] = {
    1.0f,
};

/* ROM-grounded data: src/Gobjinst_HasClearPathToActorConstantsUsRev1.c */
const float g_Gobjinst_HasClearPathToActorConstantsUsRev1[1] = {
    0.8f,
};
#endif
