#ifndef WORLD_INTEGERSTATE170_H
#define WORLD_INTEGERSTATE170_H
#include "TYPES.H"
struct func_80207ABC_S3;
struct func_80207ABC_S3 {
    char pad0[0x24];
    s32 unk24;
    char pad24[0x4C - 0x24 - sizeof(s32)];
    f32 unk4C;
};


struct func_80207C94_S3;
struct func_80207C94_S3 {
    char pad0[0x24];
    s32 unk24;
    char pad24[0x50 - 0x24 - sizeof(s32)];
    f32 unk50;
};

struct func_80207ABC_S4;
typedef struct func_80207ABC_S4 func_80207ABC_S4;


struct func_80207ABC_S3;
typedef struct func_80207ABC_S3 func_80207ABC_S3;

extern float D_800C1BA0_de;


struct func_80207C94_S3;
typedef struct func_80207C94_S3 func_80207C94_S3;


struct func_80207BB8_S3;
struct func_80207BB8_S3 {
    char pad0[0x24];
    s32 unk24;
    char pad24[0x38 - 0x24 - sizeof(s32)];
    f32 unk38;
};

struct IntegerState170;
struct IntegerState170 {
    s32 unk_0;
    unsigned char padding_4[360];
    s32 unk_16C;
};

struct IntegerState170;
typedef struct IntegerState170 IntegerState170;


struct func_80207ABC_S4;
struct func_80207ABC_S4 {
    s32 unk0;
    char pad0[0x40 - 0x0 - sizeof(s32)];
    f32 unk40;
};

struct LevelActor;
struct ActorMotionState;

struct func_80207BB8_S3;
typedef struct func_80207BB8_S3 func_80207BB8_S3;


typedef struct ActorMotionEvent {
    u8 pad0[0x4];
    u16 key; /* 0x4 */
    u8 pad6[0x4];
    u16 id; /* 0xA */
} ActorMotionEvent;
#endif
