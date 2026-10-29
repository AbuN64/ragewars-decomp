#ifndef ACTORS_VERTEX_LIGHT_AND_ACTOR_VIEWS_H
#define ACTORS_VERTEX_LIGHT_AND_ACTOR_VIEWS_H
#include "TYPES.H"
struct TriggerSoundIdView {
    char pad0[0x6];
    short soundId;
};
struct TriggerActorTransformView {
    unsigned char padding_0[8];
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    unsigned char padding_14[88];
    f32 unk_6C;
    unsigned char padding_70[144];
    s32 unk_100;
};
struct TriggerTargetTransformView {
    unsigned char padding_0[72];
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    unsigned char padding_54[12];
    f32 unk_60;
};
struct TriggerActivationView {
    char pad0[0xE];
    char enabled;
};
typedef struct Vertex38 { s16 px, py, pz; u16 flags; s16 s, t; s8 x, y, z; u8 alpha; } Vertex38;
typedef struct Vertices38 { s32 stride, count; Vertex38 vertices[1]; } Vertices38;
typedef struct Light38 { u8 pad0[0x11]; s8 x,y,z; } Light38;
#endif
