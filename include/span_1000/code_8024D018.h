#ifndef UNBAKE_SPAN_1000_CODE_8024D018_H
#define UNBAKE_SPAN_1000_CODE_8024D018_H
#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "resident_event_handler.h"
struct func_8024DEF8_S1;
struct func_8024DEF8_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x174 - 0x18 - sizeof(void*)];
    s32 unk174;
};

struct func_8024D860_S1;
struct func_8024D860_S1 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    s32 unk14;
    char pad14[0x38 - 0x14 - sizeof(s32)];
    s32 unk38;
    char pad38[0x100 - 0x38 - sizeof(s32)];
    s32 unk100;
};

struct func_8024DD48_S1;
struct func_8024DD48_S1 {
    s32 unk0;
    char pad0[0x14 - 0x0 - sizeof(s32)];
    char unk14;
};

extern float D_800C3C98_de;

extern float D_800C3CA0_de;

struct func_8024D0F8_S1;
typedef struct func_8024D0F8_S1 func_8024D0F8_S1;

struct func_8024E090_S2;
typedef struct func_8024E090_S2 func_8024E090_S2;

struct func_8024D860_S2;
typedef struct func_8024D860_S2 func_8024D860_S2;

struct func_8024DD48_S1;
typedef struct func_8024DD48_S1 func_8024DD48_S1;

extern float D_800C8CA0;

struct func_8024DEF8_S1;
typedef struct func_8024DEF8_S1 func_8024DEF8_S1;

struct Probe;
typedef struct Probe Probe;

struct SoundRequest;
struct SoundRequest {
    s32 kind;
    Vec3 position;
    char pad[0x148];
    s32 owner;
    s32 flags;
};

extern float D_800C3C9C_de;

struct func_8024D860_S1;
typedef struct func_8024D860_S1 func_8024D860_S1;

struct func_8024D49C_S1;
typedef struct func_8024D49C_S1 func_8024D49C_S1;

struct func_8024E090_S2;
struct func_8024E090_S2 {
    s32 unk0;
    char pad0[0x4C - 0x0 - sizeof(s32)];
    s32 unk4C;
};

extern void func_8024D028_de(f32 *m, f32 *q, f32 *t);

struct func_8024D49C_S1;
struct func_8024D49C_S1 {
    char pad0[0x1F0];
    char * unk1F0;
};

struct func_8024D0F8_S1;
struct func_8024D0F8_S1 {
    char pad0[0xB4];
    int unkB4;
    char padB4[0xE8 - 0xB4 - sizeof(int)];
    char unkE8;
};

struct InputRecAt44;
typedef struct InputRecAt44 InputRecAt44;

struct InputRecAt44;
struct InputRecAt44 {
    u8 state;
    u8 pad[0x43];
    Vec3 direction;
};

struct func_8024D860_S2;
struct func_8024D860_S2 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x10 - 0x8 - sizeof(f32)];
    f32 unk10;
    char pad10[0x40 - 0x10 - sizeof(f32)];
    f32 unk40;
    char pad40[0x44 - 0x40 - sizeof(f32)];
    Vec3 unk44;
    char pad44[0x6C - 0x44 - sizeof(Vec3)];
    f32 unk6C;
};

struct Probe;
struct Probe {
    char pad0[0x18];
    Vec3 start;
    char pad24[0x24];
    Vec3 dir;
    char pad54[0x8C];
};

struct SoundRequest;
typedef struct SoundRequest SoundRequest;

extern int func_8024D264_de(void * arg0);

typedef struct {
    s32 kind;
    u8 pad4[0x10];
    s32 flags14; /* 0x14 */
    f32 radius; /* 0x18: scalar-radius resource kinds */
    f32 value1C;
    f32 value20;
    u8 pad24[4];
    f32 value28;
    f32 value2C; /* 0x2C */
    u8 pad30[4];
    f32 value34; /* 0x34 */
    u8 pad38[4];
    f32 value3C; /* 0x3C */
    u8 pad40[0xC];
    s32 flags4C; /* 0x4C */
    f32 value50; /* 0x50 */
    u8 pad54[0x98];
    f32 valueEC;
    u8 padF0[8];
    f32 valueF8; /* 0xF8 */
} Resource_u1;

/* Kind 2 uses a collision-mode halfword followed by three shape dimensions. */
typedef struct CollisionShapeResource {
    s32 kind;
    u8 pad4[0x14];
    u16 mode; /* 0x18 */
    u8 pad1A[2];
    f32 height; /* 0x1C */
    f32 width; /* 0x20 */
    u8 pad24[4];
    f32 depth; /* 0x28 */
} CollisionShapeResource;
typedef struct { u8 pad0[0x80C]; s32 active; } State_u1;
typedef struct {
    u8 kind;
    u8 pad1[7];
    Vec3 position;
    u32 unknown14;
    Resource_u1 *resource;
    u8 pad1C[0x50];
    f32 yaw;
    u8 pad70[0x90];
    u32 flags;
    u8 pad104[0xD4];
    State_u1 *state;
} Actor_u1;
extern f32 D_800C3C7C_de;
extern f32 D_800C3C80_de;

extern void func_8024DBC0_de(void *actor, Vec3 position, s32 sound, f32 volume);
#endif
