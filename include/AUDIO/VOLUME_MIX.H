#ifndef AUDIO_VOLUME_MIX_H
#define AUDIO_VOLUME_MIX_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"

typedef struct AudioVolumeMix {
    s32 frame, reserved4;
    s32 left, right;
    u8 reserved10[0xC];
    f32 attenuation, baseAttenuation, spareAfterBaseAttenuation;
    s16 priority, channel;
    u8 reserved2C[8];
    CVector3 position;
    void *tracked;
    s8 curve;
    u8 reserved45[0x1F];
} AudioVolumeMix;
#endif
