#ifndef CAMERA_GAMEOBJECT_MOVETOXZKEEPHEIGHT_H
#define CAMERA_GAMEOBJECT_MOVETOXZKEEPHEIGHT_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
struct Material_func_80245D30_de {
    char pad0[0x52];
    u16 flags;
    char pad54[9];
    u8 strength;
    char pad5e[1];
    s8 x;
    s8 y;
    s8 z;
};
struct Actor_func_80245D30_de {
    u8 kind;
    char pad1[0x1f];
    f32 vertical;
    char pad24[4];
    CVector3 current;
    char pad34[4];
    s32 flags;
    char pad3c[0x30];
    f32 yaw;
};
#endif
