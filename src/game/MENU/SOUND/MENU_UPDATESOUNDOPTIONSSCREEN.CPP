#include "COMMON/MENUSELECTIONMESSAGE.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/SCREEN.H"
#include "TYPES.H"
extern struct SoundOptionsScreen *D_800E58A0;
#include "COMMON/INTEGERSTATE530.H"
#include "SYSTEM/SOUND_CONTEXT_MUSIC_AND_VOICE_CONTROL.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
#include "SCENE/CACHE_FREEMEMORY.H"

/* Releases the object D_800E58A0 holds through Cache_FreeMemory, clears D_800E58A0 and returns zero. */



/* Runs the sound options screen D_800E58A0 each frame: when its menu reports 4 it calls
   MarkMenuEventHandled and leaves through SmXlate_SwitchScreen with the stored target or Menu_ReturnToPreviousScreen when
   that is -1; otherwise it copies the effects slider into option byte D_801462E1, playing sound
   0x460 when it changed, and the music slider into D_801462E0, stopping the music through
   func_8025E2D4_de(0) below 5 or starting track 0x34 when func_8025E2C4_de reports none playing.
   Returns zero. */






extern s32 SmpSlider_GetTransitionMode(void *);

extern s32 SmpSlider_GetSliderItem(void *);


extern void SmXlate_SwitchScreen(s32);




/* Calls MarkMenuEventHandled; when Menu_GetFocusedElementId reports 0x73, sets the word at offset 0x14 of the object
   D_800E58A0 points to to -1 and calls SmpSlider_SetTransitionMode on its first word with 2. Returns zero. */


s32 Menu_FreeSoundOptionsScreen(void) {
    Cache_FreeMemory(D_800E58A0);
    D_800E58A0 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80439010_de(void) {
    return 0;
}

s32 Menu_UpdateSoundOptionsScreen(void) {
    u8 *options;
    s32 value;
    s32 track;

    switch (SmpSlider_GetTransitionMode(D_800E58A0->menu)) {
    case 3:
        break;
    case 4:
        MarkMenuEventHandled();
        if (D_800E58A0->target != -1) {
            SmXlate_SwitchScreen(D_800E58A0->target);
            return 0;
        }
        Menu_ReturnToPreviousScreen();
        return 0;
    }
    value = SmpSlider_GetSliderItem(D_800E58A0->effects);
    options = &D_801462C8.volume[1];
    if (value != options[0]) {
        options[0] = value;
        SoundElement_PlayFlatSound(0x460);
    }
    value = SmpSlider_GetSliderItem(D_800E58A0->music);
    if (value != options[-1]) {
        options[-1] = value;
        track = 0;
        if ((u8)value >= 5) {
            if (func_8025E2C4_de() != 0) {
                return 0;
            }
            track = 0x34;
        }
        func_8025E2D4_de(track);
    }
    return 0;
}

s32 Menu_ConfirmSoundOptionsScreen(void) {
    struct SoundOptionsScreen *state;
    MarkMenuEventHandled();
#if defined(VERSION_DE)
    if (Menu_GetFocusedElementId() == 0x71) {
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    if (Menu_GetFocusedElementId() == 0x73) {
#elif defined(VERSION_EU_X)
    if (Menu_GetFocusedElementId() == 0x77) {
#endif
        state = D_800E58A0;
        state->target = -1;
        SmpSlider_SetTransitionMode((s32)state->menu, 2);
    }
    return 0;
}
