#ifndef MENU_TRACK_TYPES_H
#define MENU_TRACK_TYPES_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"

typedef struct SharedTrackObjectPrefix {
    u32 unknown0[2];
    CVector3 position;
    u8 unknown14[0x3C];
} SharedTrackObjectPrefix;

typedef struct SharedTrackObject {
    SharedTrackObjectPrefix prefix;
    u8 unknown50[0x1C];
    f32 yaw;
} SharedTrackObject;

typedef struct SharedTrackCamera {
    u8 unknown0[0x28];
    f32 distance;
    f32 pitch;
    u8 unknown30[8];
    CVector3 position;
} SharedTrackCamera;

struct SharedTrackConstants { f32 amplitude; f32 unit; };

#endif
