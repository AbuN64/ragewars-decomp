#ifndef SDK_AUDIO_802C3EA4_3_H
#define SDK_AUDIO_802C3EA4_3_H
#include "COMMON/LLDIVRESULT.H"
#include "COMMON/AUDIO_LOADDECODEDSAMPLES.H"
extern u32 Audio_DecodeFrameOk(void);
extern void Audio_RotateComplexSamples(float *arg0, float *arg1, float *arg2);
extern void Audio_ReorderTransformSamples(float *arg0, float *arg1);
extern s16 Audio_QuantizeSampleS16(f32 arg0);
extern void Audio_TransformFft(f32 *data, FftTables *tables, s32 sign);
extern void Audio_InitBitReverseOrder(s32 *arg0, s32 arg1);
#endif
