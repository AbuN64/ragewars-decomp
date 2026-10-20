#include "include_asm.h"
#include "COMMON/MENURECAT20V1.H"
#include "TYPES.H"

#if !(defined(VERSION_US_REV1))
extern s32 D_801462C8;

/* Toggles bit 0 of the settings flag word D_801462C8 and returns 0. */
s32 func_8043D25C_de(void) {
    D_801462C8 ^= 1;
    return 0;
}
#endif

#if defined(VERSION_US_REV1)
extern s32 D_800E63AC;

s32 func_8043D25C_de(void) {
    D_800E63AC ^= 1;
    return 0;
}
#endif
