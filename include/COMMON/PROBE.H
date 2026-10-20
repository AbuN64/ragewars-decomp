#ifndef COMMON_PROBE_H
#define COMMON_PROBE_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
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
    CVector3 position;
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
    CVector3 direction;
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
    CVector3 unk44;
    char pad44[0x6C - 0x44 - sizeof(CVector3)];
    f32 unk6C;
};

struct Probe;
struct Probe {
    char pad0[0x18];
    CVector3 start;
    char pad24[0x24];
    CVector3 dir;
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
    f32 value30; /* 0x30: class-specific height */
    f32 value34; /* 0x34 */
    u8 pad38[4];
    f32 value3C; /* 0x3C */
    u8 pad40[0xC];
    s32 flags4C; /* 0x4C */
    f32 value50; /* 0x50 */
    u8 pad54[0x98];
    f32 valueEC;
    f32 collisionExtent; /* +0xF0: 8024E464 returns this for kind 11 collision queries. */
    f32 valueF4; /* 0xF4: player descriptor height */
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
typedef struct {
    u8 pad0[0x6F4];
    f32 heightDelta; /* 0x6F4: AiProfile.heightDelta */
    u8 pad6F8[0x80C - 0x6F8];
    s32 active; /* 0x80C */
} State_u1;
typedef struct {
    u8 kind;
    u8 pad1[7];
    CVector3 position;
    u32 unknown14;
    Resource_u1 *resource;
    u8 pad1C[0x50];
    f32 yaw;
    u8 pad70[0x90];
    u32 flags;
    u8 pad104[0x174 - 0x104];
    s32 active; /* 0x174 */
    u8 pad178[0x1D8 - 0x178];
    State_u1 *state;
} Actor_u1;
extern f32 D_800C3C7C_de;
extern f32 D_800C3C80_de;
#endif
