#include "COMMON/SOUNDINFO.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "SYSTEM/SOUND_CONTEXT_MUSIC_AND_VOICE_CONTROL.H"
#include "TEXTURE/SOUND_UPDATEAUDIOCONTEXT.H"
#include "COMMON/AUDIO_CONTEXT.H"
#include "include_asm.h"
#include "SYSTEM/SOUND_CONTEXT_LOCK_AND_ACTIVITY.H"

/* 8025E280.CPP */
extern void Audio_SetVoiceMixValue(ContextRecAt2BC0 *context, int arg1);
extern void Audio_SetListenerCamera(ContextRecAt2BC0 *object, int value);
extern void Audio_SetMusicGainScalingEnabled(ContextRecAt2BC0 *object, int value);
extern void Audio_FadeOutContextMusic(int contextAddress);
extern void Audio_SetPeriodicSoundEnabled(char *object, int value);
extern void Audio_StopContextMusic(int contextAddress);
extern void Audio_EnableContextMusicGainOverride(int contextAddress);
extern void Audio_DisableContextMusicGainOverride(int contextAddress);
extern void Audio_ClearContextVoiceFlags(int contextAddress);

/** Read the global word at VRAM 0x8010DE0C. */

s32 Audio_SetClampedAudioLevel(s32 *, f32);

void SoundElement_SetTrackAndPeriodicPlayback(int trackId)
{
  int new_var;
  new_var = trackId != 0;
  D_8010C080.track = (s32) trackId;
  if (new_var)
  {
    if (1)
    {
      SoundElement_EnablePeriodicSound();
    }
    return;
  }
  SoundElement_DisablePeriodicSound();
}

void SoundElement_SetVoiceMixValue(s32 mixValue) {
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
                SoundElement_FadeOutMusic();
            }
        }
    }
}

void SoundElement_FadeOutMusic(void) {
    Audio_FadeOutContextMusic((s32) &D_8010C080);
}

void SoundElement_StopMusic(void) {
    Audio_StopContextMusic((s32) &D_8010C080);
}

void SoundElement_EnableMusicGainOverride(void) {
    Audio_EnableContextMusicGainOverride((s32) &D_8010C080);
}

void SoundElement_DisableMusicGainOverride(void) {
    Audio_DisableContextMusicGainOverride((s32) &D_8010C080);
}

void SoundElement_DisablePeriodicSound(void) {
    Audio_SetPeriodicSoundEnabled(&D_8010C080, 0);
}

void SoundElement_EnablePeriodicSound(void) {
    Audio_SetPeriodicSoundEnabled(&D_8010C080, 1);
}

void SoundElement_SetListenerCamera(s32 arg0) {
    Audio_SetListenerCamera(&D_8010C080, arg0);
}

void SoundElement_SetMusicGainScalingEnabled(s32 enabled) {
    Audio_SetMusicGainScalingEnabled(&D_8010C080, enabled);
}

void SoundElement_SetClampedAudioLevel(f32 arg0) {
    Audio_SetClampedAudioLevel(&D_8010C080, arg0);
}

void SoundElement_ClearVoiceFlags(void) {
    Audio_ClearContextVoiceFlags((s32) &D_8010C080);
}

void SoundElement_AcquireContextLock(void) {
    Sound_AcquireContextLock(&D_8010C080);
}

/* 8025E280_3.CPP */
s32 Sound_HasActiveOrPendingSound(struct ContextRecAt2BC0 *, s32);

void SoundElement_ReleaseContextLock(void) {
    Sound_ReleaseContextLock(&D_8010C080);
}

struct ContextRecAt2BC0;

s32 SoundElement_HasActiveOrPendingSound(s32 wantedKey) {
    return Sound_HasActiveOrPendingSound(&D_8010C080, wantedKey);
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8025E49C[1] = {
    0x74685F74,
};
#endif
