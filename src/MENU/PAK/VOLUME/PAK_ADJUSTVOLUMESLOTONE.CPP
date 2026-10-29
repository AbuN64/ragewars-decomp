#include "include_asm.h"

#include "MENU/OPTIONEDITSTATE.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"

/* Replaces the option byte g_soundEffectsVolumeOption with what Menu_AdjustValue returns for the second argument, that byte, 8, 0, 0xFF and 0, turning 0xF7 into 0xF8, and returns zero. Adapted from Pak_AdjustVolumeSlotTwo with the option byte g_soundEffectsVolumeOption changed. */

extern s32 Menu_AdjustValue(void *, s32, s32, s32, s32, s32);

s32 Pak_AdjustVolumeSlotOne(void *first, void *second) {
    u8 *option = &g_gameSettings.volume[1];
    s32 value = *option;

    value = Menu_AdjustValue(second, value, 8, 0, 0xFF, 0);
    if (value == 0xF7) {
        value = 0xF8;
    }
    *option = value;
    return 0;
}
