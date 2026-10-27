#include "include_asm.h"

#if defined(VERSION_US)
char s_attackText[8] =
    "ATTACK_W";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: s_attackText */
unsigned int D_blob_phase2_dc24061a52efe51fb5fd[2] = {
    0x27BD0018, 0x27BDFFE8,
};
#endif
