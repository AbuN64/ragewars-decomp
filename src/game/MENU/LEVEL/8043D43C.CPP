#include "TYPES.H"

#if defined(VERSION_US_REV1)
extern s32 D_801462C8;

/* Toggles bit 0 of the settings flag word D_801462C8 and returns 0. */
s32 Level_ToggleGameFlagOne(void) {
    D_801462C8 ^= 1;
    return 0;
}
#endif
