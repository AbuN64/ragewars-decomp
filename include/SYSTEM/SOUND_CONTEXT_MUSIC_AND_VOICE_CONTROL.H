#ifndef SYSTEM_SOUND_CONTEXT_MUSIC_AND_VOICE_CONTROL_H
#define SYSTEM_SOUND_CONTEXT_MUSIC_AND_VOICE_CONTROL_H
#include "COMMON/SOUNDINFO.H"
extern void SoundElement_SetTrackAndPeriodicPlayback(int trackId);
extern void SoundElement_EnableMusicGainOverride(void);
extern void SoundElement_FadeOutMusic(void);
extern void SoundElement_StopMusic(void);
extern void SoundElement_DisableMusicGainOverride(void);
extern void SoundElement_ClearVoiceFlags(void);
extern void SoundElement_DisablePeriodicSound(void);
extern void SoundElement_AcquireContextLock(void);
extern void SoundElement_EnablePeriodicSound(void);
extern int func_8025E2C4_de(void);
extern void SoundElement_SetVoiceMixValue(s32 mixValue);
#endif
