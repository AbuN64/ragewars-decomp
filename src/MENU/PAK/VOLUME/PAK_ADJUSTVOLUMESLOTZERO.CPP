#include "include_asm.h"

#include "MENU/OPTIONEDITSTATE.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "SYSTEM/SOUND_CONTEXT_MUSIC_AND_VOICE_CONTROL.H"
extern s32 Menu_AdjustValue(void *,s32,s32,s32,s32,s32);

/* Adjusts the volume in steps of eight and starts a sound preview when no preview is playing. */

s32 Pak_AdjustVolumeSlotZero(void *unused, void *menu) {
    s32 volume;
    volume = g_gameSettings.volume[0];
    volume = Menu_AdjustValue(menu, volume, 8, 0, 0xFF, 0);
    if(volume==0xF7)volume=0xF8;
    g_gameSettings.volume[0]=volume;
    if (SoundElement_GetMusicPlaybackEnabled() <= 0) {
        SoundElement_SetMusicPlaybackEnabled(1);
    }
    return 0;
}
