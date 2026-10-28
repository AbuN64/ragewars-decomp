#ifndef SDK_AUDIO_DECODE_H
#define SDK_AUDIO_DECODE_H
#include "COMMON/LLDIVRESULT.H"
struct DecodeState;
extern u16 Audio_ReadPackedSamples(u16 *, u16, u16, s16, struct DecodeState *);
#endif
