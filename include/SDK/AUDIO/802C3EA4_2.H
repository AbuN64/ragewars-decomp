#ifndef SDK_AUDIO_802C3EA4_2_H
#define SDK_AUDIO_802C3EA4_2_H
#include "COMMON/LLDIVRESULT.H"
#include "COMMON/ALLOADFILTER48_2.H"
extern void func_802BF514_de();
extern s32 func_802BF804_de(f32 *out, s16 *in);
extern FftTables *func_802BF67C_de(s32 n);
extern void Audio_ComplexFft(f32 *data, s32 count, s32 sign, f32 *cosines, f32 *sines, s32 *reverse);
extern void func_802BFAAC_de(s16 *out, s16 *input);
#endif
