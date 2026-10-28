#ifndef SDK_AUDIO_802C3EA4_2_H
#define SDK_AUDIO_802C3EA4_2_H
#include "COMMON/LLDIVRESULT.H"
#include "COMMON/ALLOADFILTER48_2.H"
extern void Audio_InitTransformTables();
extern s32 Audio_DequantizeTransformCoefficients(f32 *out, s16 *in);
extern FftTables *Audio_InitFftTables(s32 n);
extern void Audio_ComplexFft(f32 *data, s32 count, s32 sign, f32 *cosines, f32 *sines, s32 *reverse);
extern void Audio_DecodeTransformBlock(s16 *out, s16 *input);
#endif
