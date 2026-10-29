#include "MENU/OPTIONEDITSTATE.H"
#include "TYPES.H"
#include "COMMON/SOUNDINFO.H"
#include "MENU/PAK/PAK_RESUMEMENUAUDIO.H"
#include "SYSTEM/SOUND_CONTEXT_MUSIC_AND_VOICE_CONTROL.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/EXTERNS_21.H"

/* 80444EC0_6.CPP */
#if !(defined(VERSION_US))
/* Passes what SoundVoicePool_GetGlobalState returns to SoundVoicePool_Resume, then calls SoundElement_DisableMusicGainOverride and SoundElement_EnablePeriodicSound,
   and returns one. */
extern s32 SoundVoicePool_GetGlobalState();
struct SoundVoicePool;
extern void SoundVoicePool_Resume(struct SoundVoicePool *);

s32 Pak_ResumeMenuAudio(void) {
    SoundVoicePool_Resume(SoundVoicePool_GetGlobalState());
    SoundElement_DisableMusicGainOverride();
    SoundElement_EnablePeriodicSound();
    return 1;
}

/* Returns one. Nothing in the cartridge image calls it or stores its address as a word. */
s32 Pak_ReturnCallbackSuccess(void) {
    return 1;
}
#endif

/* 80444EC0_7.CPP */
#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* Calls Menu_AllocateMenu with the third argument, the second argument and the resource D_4514B4,
   and returns one. */

s32 func_80444EBC_de(void *first, void *second, void *third) {
    Menu_AllocateMenu(third, second, D_00450884);
    return 1;
}

/* Calls Menu_AllocateMenu with the third argument, the second argument and the resource D_451AF0,
   and returns one. */

s32 func_80444EE8_de(void *first, void *second, void *third) {
#if defined(VERSION_EU)
    Menu_AllocateMenu(third, second, D_00451B34);
#elif defined(VERSION_EU_X)
    Menu_AllocateMenu(third, second, D_00451C64);
#else
    Menu_AllocateMenu(third, second, D_00450E9C);
#endif
    return 1;
}

/* Calls Menu_AllocateMenu with the third argument, the second argument and the resource D_4500F4,
   and returns one. */

s32 func_80444F14_de(void *first, void *second, void *third) {
#if defined(VERSION_EU)
    Menu_AllocateMenu(third, second, D_00450E9C);
#elif defined(VERSION_EU_X)
    Menu_AllocateMenu(third, second, D_00450E9C);
#else
    Menu_AllocateMenu(third, second, D_0044F4A4);
#endif
    return 1;
}

/* Calls Menu_AllocateMenu with the third argument, the second argument and the resource D_4503E8,
   and returns one. */

s32 func_80444F40_de(void *first, void *second, void *third) {
#if defined(VERSION_EU)
    Menu_AllocateMenu(third, second, D_0044F4A4);
#elif defined(VERSION_EU_X)
    Menu_AllocateMenu(third, second, D_0044F4A4);
#else
    Menu_AllocateMenu(third, second, D_0044F798);
#endif
    return 1;
}

/* Calls Menu_AllocateMenu with the third argument, the second argument and the resource D_451BD4,
   and returns one. */

s32 func_80444F6C_de(void *first, void *second, void *third) {
#if defined(VERSION_EU)
    Menu_AllocateMenu(third, second, D_0044F798);
#elif defined(VERSION_EU_X)
    Menu_AllocateMenu(third, second, D_0044F798);
#else
    Menu_AllocateMenu(third, second, D_00450F74);
#endif
    return 1;
}
#endif
