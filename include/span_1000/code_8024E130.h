#ifndef UNBAKE_SPAN_1000_CODE_8024E130_H
#define UNBAKE_SPAN_1000_CODE_8024E130_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
struct func_8024E560_S2;
struct func_8024E560_S2 {
    char pad0[0x3C];
    float unk3C;
};

union func_8024E2EC_S3_U18;
union func_8024E2EC_S3_U18 {
    u16 v0;
    f32 v1;
};

struct TripleRecAt8;
typedef struct TripleRecAt8 TripleRecAt8;

struct ObjectLinks1DC_4;
struct ObjectLinks1DC_4 {
    char pad0[0x18];
    s32 * unk_18;
    char pad18[0x100 - 0x18 - sizeof(s32*)];
    s32 unk_100;
    char pad100[0x1D8 - 0x100 - sizeof(s32)];
    char * unk_1D8;
};

struct func_8024E3B4_S2;
typedef struct func_8024E3B4_S2 func_8024E3B4_S2;

struct FloatState3C;
typedef struct FloatState3C FloatState3C;

struct ObjectLinks18;
typedef struct ObjectLinks18 ObjectLinks18;

struct func_8024E3B4_S2;
struct func_8024E3B4_S2 {
    char pad0[0x34];
    f32 unk34;
    char pad34[0xF8 - 0x34 - sizeof(f32)];
    f32 unkF8;
};

struct func_8024E6C8_S1;
typedef struct func_8024E6C8_S1 func_8024E6C8_S1;

struct ItemCode8024E130;
struct ItemCode8024E130 {
    unsigned char kind;
    char pad[0x33];
    void *value;
    unsigned flags;
};

struct func_8024E1A4_S1;
struct func_8024E1A4_S1 {
    char pad0[0x1C];
    s32 unk1C;
    char pad1C[0x100 - 0x1C - sizeof(s32)];
    s32 unk100;
    char pad100[0x1A0 - 0x100 - sizeof(s32)];
    void * unk1A0;
};

struct IntegerState810;
struct IntegerState810 {
    unsigned char padding_0[2060];
    s32 unk_80C;
};

extern int func_8024E610_de(void *arg0);

struct func_8024E148_S1;
typedef struct func_8024E148_S1 func_8024E148_S1;

struct func_8024E2EC_S3;
typedef struct func_8024E2EC_S3 func_8024E2EC_S3;

extern f32 func_8024E870_de(void *arg0);

union func_8024E2EC_S3_U18;
typedef union func_8024E2EC_S3_U18 func_8024E2EC_S3_U18;

struct func_8024E2EC_S3;
struct func_8024E2EC_S3 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    func_8024E2EC_S3_U18 unk18;
    char pad18[0x1C - 0x18 - sizeof(func_8024E2EC_S3_U18)];
    f32 unk1C;
};

struct ObjectLinks18;
struct ObjectLinks18 {
    unsigned char padding_0[12];
    f32 unk_C;
    unsigned char padding_10[4];
    void *unk_14;
};

struct FloatState3C;
struct FloatState3C {
    unsigned char padding_0[56];
    f32 unk_38;
};

struct func_8024E148_S1;
struct func_8024E148_S1 {
    char pad0[0x18];
    s32 * unk18;
    char pad18[0x100 - 0x18 - sizeof(s32*)];
    u32 unk100;
};

struct func_8024E668_S1;
typedef struct func_8024E668_S1 func_8024E668_S1;

extern f32 func_8024E8B8_de(void *arg0);

struct func_8024E640_S1;
typedef struct func_8024E640_S1 func_8024E640_S1;

struct func_8024E58C_S2;
typedef struct func_8024E58C_S2 func_8024E58C_S2;

struct LevelActor;
extern int func_8024E2B0_de(struct LevelActor *arg0);

struct func_8024E2EC_S2;
typedef struct func_8024E2EC_S2 func_8024E2EC_S2;

struct func_8024E640_S1;
struct func_8024E640_S1 {
    u8 unk0;
    char pad0[0xC - 0x0 - sizeof(u8)];
    f32 unkC;
    char padC[0x40 - 0xC - sizeof(f32)];
    f32 unk40;
};

struct func_8024E410_S1;
struct func_8024E410_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x70 - 0x18 - sizeof(void*)];
    f32 unk70;
};

struct func_8024E534_S2;
struct func_8024E534_S2 {
    char pad0[0x50];
    float unk50;
};

struct func_8024E58C_S2;
struct func_8024E58C_S2 {
    char pad0[0x4];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    s32 unk8;
};

struct IntegerState810;
typedef struct IntegerState810 IntegerState810;

struct func_8024E6C8_S1;
struct func_8024E6C8_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s32 unk8;
};

struct func_8024E534_S2;
typedef struct func_8024E534_S2 func_8024E534_S2;

struct func_8024E2EC_S2;
struct func_8024E2EC_S2 {
    char pad0[0x18];
    f32 unk18;
    char pad18[0x2C - 0x18 - sizeof(f32)];
    f32 unk2C;
    char pad2C[0xEC - 0x2C - sizeof(f32)];
    f32 unkEC;
};

struct func_8024E668_S1;
struct func_8024E668_S1 {
    char pad0[0xC];
    float unkC;
    char padC[0x40 - 0xC - sizeof(float)];
    float unk40;
};

struct TripleRecAt8;
struct TripleRecAt8 {
    f32 a;
    s32 b;
    f32 c;
};

struct Object_func_8024E80C_de;
struct StateFlags;
struct Object_func_8024E80C_de {
    char pad[0x14];
    struct StateFlags *key;
};

struct func_8024E410_S1;
typedef struct func_8024E410_S1 func_8024E410_S1;

struct func_8024E1A4_S1;
typedef struct func_8024E1A4_S1 func_8024E1A4_S1;

struct func_8024E560_S2;
typedef struct func_8024E560_S2 func_8024E560_S2;

extern s32 func_8024E208_de(char *actor);

struct ObjectLinks1DC_4;
typedef struct ObjectLinks1DC_4 ObjectLinks1DC_4;

extern float D_800C3D74_de;

#endif
