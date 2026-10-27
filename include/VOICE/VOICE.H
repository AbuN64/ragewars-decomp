#ifndef VOICE_VOICE_H
#define VOICE_VOICE_H
#include "COMMON/OBJRECAT4V6.H"
#include "AUDIO/8025A3EC.H"
extern void Audio_InitializeVoiceRecord(void *, int owner, int);
extern s32 Audio_GetVoiceSoundState(SlotRecAtB8 *voicePool, s16 slotIndex);
extern void Audio_PlayVoiceSound(SlotRecAtB8 *base, s16 index);
extern s32 Audio_ReleaseMatchingExclusiveVoice(RecordD90 *record, s16 value, s16 id);
extern void Audio_ClearVoiceFlags(s32 a);
extern void Audio_SetVoiceTrackId(void *, int newTrackId);
extern void Audio_UpdateVoicePool(void * *);
extern f32 Audio_InterpolatePitchTable(f32);
extern s16 Audio_RandomizeSignedRange(s16, s16);
extern f32 Audio_RandomizeScaledByteRange(u8, u8);
extern f32 Audio_ComputeSpatialAttenuationCurve(char *source, char *listener);
extern void Audio_SetScaledVoiceVolume(void *, s32);
extern void Audio_SetScaledVoicePitch(void *, f32);
extern void func_8025C524_de(SlotRecAtB4V2 *voiceRecord, s32 panValue);
extern void func_8025C578_de(SlotRecAtB4V2 *voiceRecord);
extern void func_8025C5BC_de(SlotRecAtB4V2 *voiceRecord);
extern void func_8025C5DC_de(SlotRecAtB4V2 *voiceRecord);
extern void func_8025C65C_de(SlotRecAtB4V2 *voiceRecord);
extern void func_8025C8C0_de(void *cLoopingSoundData);
extern void func_8025C8D0_de(void);
extern void *func_8025C95C_de(void *voicePool, s32 soundId, CVector3 *soundPosition, void *position, s32 fallback);
extern void func_8025CAB0_de(void *voicePool);
extern void func_8025CB88_de(void *soundVoicePool);
extern void func_8025CBEC_de(void *soundVoicePool);
extern void func_8025CC7C_de(void);
#endif
