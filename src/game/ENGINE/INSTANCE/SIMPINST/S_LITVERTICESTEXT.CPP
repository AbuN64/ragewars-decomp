#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_litVerticesText[13] =
    "lit vertices\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/simpleObjectLitVerticesTagTextUsRev1.c */
const unsigned char s_simpleObjectLitVerticesTagUsRev1[13] = {
    0x6C, 0x69, 0x74, 0x20, 0x76, 0x65, 0x72, 0x74, 0x69, 0x63, 0x65, 0x73, 0x00,
};
#endif
