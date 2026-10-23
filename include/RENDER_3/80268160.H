#ifndef RENDER_3_80268160_H
#define RENDER_3_80268160_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
struct Field_s32_2E0 {
    char pad[0x2E0];
    s32 value;
};
struct Triple_func_802683E0_de {
    s32 x;
    f32 y;
    s32 z;
};
struct Camera_func_8026851C_de {
    char pad0[0xE4];
    CVector3 position;
    CVector3 offset;
};
struct SourceRecAt1C {
    unsigned char active;
    char pad1[7];
    CVector3 position;
    s32 id;
    char pad18[4];
    CVector3 velocity;
};
struct Spawn {
    CVector3 position;
    s32 kind;
    f32 size;
};
struct ObjRecAt1 {
    char pad0[0x1];
    s8 unk1;
};
#endif
