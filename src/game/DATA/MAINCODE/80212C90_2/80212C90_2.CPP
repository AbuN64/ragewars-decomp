#include "include_asm.h"

#if defined(VERSION_US)
char s_shotgunText[8] =
    "SHOTGUN_";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: s_shotgunText */
unsigned int D_blob_phase2_575ad44837ccab744bd2[2] = {
    0xAFAA0030, 0x0C0939B2,
};
#endif
