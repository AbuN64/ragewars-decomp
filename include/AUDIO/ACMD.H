#ifndef AUDIO_ACMD_H
#define AUDIO_ACMD_H
#include "COMMON/AUDIO_CALLBACKS.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "acmd.h"
extern void *func_802B625C_de(void *audioLowPassFilter, s32 dmemBuffer, s32 sampleCount, void *awords);

#include "COMMON/ALDELAY28.H"
extern f32 func_802B6300_de(ALDelay28 *d, s32 count);

extern const double D_800C77C0_de;
extern const float D_800C77C8_de;
extern Acmd *func_802B60EC_de(ALFx *, s16 *, s32, s32, Acmd *);
#endif
