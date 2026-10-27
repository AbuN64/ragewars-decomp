#include "COMMON/S1_2.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "SYSTEM_2/8025E280.H"
#include "TEXTURE/80256220_16.H"
#include "COMMON/AUDIO_CONTEXT.H"
#include "include_asm.h"
#include "SYSTEM_2/8025E280_3.H"

/* 8025E280.CPP */
extern void Audio_SetVoiceMixValue(ContextRecAt2BC0 *arg0, int arg1);
extern void Audio_SetListenerCamera(ContextRecAt2BC0 *object, int value);
extern void Audio_SetMusicGainScalingEnabled(ContextRecAt2BC0 *object, int value);
extern void Audio_FadeOutContextMusic(int arg0);
extern void Audio_SetPeriodicSoundEnabled(char *object, int value);
extern void Audio_StopContextMusic(int arg0);
extern void Audio_EnableContextMusicGainOverride(int arg0);
extern void Audio_DisableContextMusicGainOverride(int arg0);
extern void Audio_ClearContextVoiceFlags(int arg0);

/** Read the global word at VRAM 0x8010DE0C. */

s32 Audio_SetClampedAudioLevel(s32 *, f32);

void func_8025E260_de(int trackId)
{
  int new_var;
  new_var = trackId != 0;
  D_8010C080.track = (s32) trackId;
  if (new_var)
  {
    if (1)
    {
      func_8025E3CC_de();
    }
    return;
  }
  func_8025E3A8_de();
}

void func_8025E29C_de(s32 mixValue) {
    Audio_SetVoiceMixValue(&D_8010C080, mixValue);
}

int func_8025E2C4_de(void) {
    return D_80109E0C;
}

void func_8025E2D4_de(s32 a) {
    if (D_8011FAC0.transitionBlocked == 0) {
        s32 *p = &D_80109E0C;
        if (*p != a) {
            *p = a;
            if (a == 0) {
                func_8025E318_de();
            }
        }
    }
}

void func_8025E318_de(void) {
    Audio_FadeOutContextMusic((s32) &D_8010C080);
}

void func_8025E33C_de(void) {
    Audio_StopContextMusic((s32) &D_8010C080);
}

void func_8025E360_de(void) {
    Audio_EnableContextMusicGainOverride((s32) &D_8010C080);
}

void func_8025E384_de(void) {
    Audio_DisableContextMusicGainOverride((s32) &D_8010C080);
}

void func_8025E3A8_de(void) {
    Audio_SetPeriodicSoundEnabled(&D_8010C080, 0);
}

void func_8025E3CC_de(void) {
    Audio_SetPeriodicSoundEnabled(&D_8010C080, 1);
}

void func_8025E3F0_de(s32 arg0) {
    Audio_SetListenerCamera(&D_8010C080, arg0);
}

void func_8025E418_de(s32 enabled) {
    Audio_SetMusicGainScalingEnabled(&D_8010C080, enabled);
}

void func_8025E440_de(f32 arg0) {
    Audio_SetClampedAudioLevel(&D_8010C080, arg0);
}

void func_8025E468_de(void) {
    Audio_ClearContextVoiceFlags((s32) &D_8010C080);
}

void func_8025E48C_de(void) {
    func_80258740_de(&D_8010C080);
}

/* 8025E280_3.CPP */
s32 func_802585F4_de(struct ContextRecAt2BC0 *, s32);

void func_8025E4B0_de(void) {
    func_802587A4_de(&D_8010C080);
}

struct ContextRecAt2BC0;

s32 func_8025E4D4_de(s32 wantedKey) {
    return func_802585F4_de(&D_8010C080, wantedKey);
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8025E49C[1] = {
    0x74685F74,
};
#endif
