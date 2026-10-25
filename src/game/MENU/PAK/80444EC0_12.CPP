#include "MENU/OPTIONEDITSTATE.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"

#if !(defined(VERSION_US))
/* Replaces the option byte D_801462E1 with what Pak_AdjustValue returns for the second argument, that byte, 8, 0, 0xFF and 0, turning 0xF7 into 0xF8, and returns zero. Adapted from func_80445020_de with the option byte D_801462E1 changed. */

extern s32 Pak_AdjustValue(void *, s32, s32, s32, s32, s32);

s32 func_804452B0_de(void *first, void *second) {
    u8 *option = &D_801462C8.volume[1];
    s32 value = *option;

    value = Pak_AdjustValue(second, value, 8, 0, 0xFF, 0);
    if (value == 0xF7) {
        value = 0xF8;
    }
    *option = value;
    return 0;
}
#endif
