#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_animatedModelText[15] =
    "animated model\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/s_animatedModelResourceTagUsRev1_SAnimatedmodeltext.c */
const unsigned char s_animatedModelResourceTagUsRev1[15] = {
    0x61, 0x6E, 0x69, 0x6D, 0x61, 0x74, 0x65, 0x64, 0x20, 0x6D, 0x6F, 0x64, 0x65, 0x6C, 0x00,
};
#endif
