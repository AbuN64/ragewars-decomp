#ifndef AUDIO_8025A3EC_4_H
#define AUDIO_8025A3EC_4_H
#include "COMMON/OBJRECAT4V6.H"
extern f32 Audio_InterpolatePitchTable(f32 arg0);
extern f32 Audio_RandomizeScaledByteRange(u8 arg0, u8 arg1);
extern void Audio_SetScaledVoiceVolume(void *arg0, s32 arg1);
extern void Audio_SetScaledVoicePitch(void *arg0, f32 arg1);
extern s16 Audio_RandomizeSignedRange(s16 arg0, s16 arg1);
extern void Audio_UpdateVoicePool(void **arg0);
extern void Audio_ClearVoiceFlags(s32 a);
#endif
