#ifndef AUDIO_ACMD_H
#define AUDIO_ACMD_H
#include "COMMON/AUDIO_CALLBACKS.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "acmd.h"
extern void *_filterBuffer(void *audioLowPassFilter, s32 dmemBuffer, s32 sampleCount, void *awords);

#include "COMMON/ALDELAY28.H"
extern f32 _getDelta(ALDelay28 *d, s32 count);

extern const double g_reverbDelayFloatConversionBias;
extern const float g_reverbGainLengthScale;
extern Acmd *_loadBuffer(ALFx *, s16 *, s32, s32, Acmd *);
#endif
