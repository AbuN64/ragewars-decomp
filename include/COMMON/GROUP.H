#ifndef COMMON_GROUP_H
#define COMMON_GROUP_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Work80244494;
typedef struct Work80244494 Work80244494;

struct func_80245958_S1;
struct func_80245958_S1 {
    char pad0[0x38];
    int unk38;
    char pad38[0xA8 - 0x38 - sizeof(int)];
    int unkA8;
};

struct Group;

extern void func_802458D8_de();

extern void func_8024570C_de();


extern void func_802458F8_de(void);

extern int func_8024576C_de();

struct Record_func_80244FB4_de;
struct Record_func_80244FB4_de {
    char pad0[0x1C];
    f32 value;
    f32 previous;
    char pad24[8];
    f32 limit;
    f32 threshold;
    char pad34[8];
    s32 done;
    char pad40[0x74];
    s32 active;
    char padB8[0x24];
    s32 resource;
    char padE0[0x24];
    s32 mode;
};

struct func_80245788_S1;
typedef struct func_80245788_S1 func_80245788_S1;

struct Record_func_80244FB4_de;
typedef struct Record_func_80244FB4_de Record_func_80244FB4_de;

struct VectorPair;

struct Group;
typedef struct Group Group;

struct func_80245958_S1;
typedef struct func_80245958_S1 func_80245958_S1;

extern int D_800CB418_de;

extern float D_800C37B0_de;

struct func_80245930_S1;
struct func_80245930_S1 {
    char pad0[0x38];
    int unk38;
    char pad38[0xAC - 0x38 - sizeof(int)];
    int unkAC;
};

struct func_802458F8_S1;
struct func_802458F8_S1 {
    char pad0[0x74];
    int unk74;
};

struct func_802456FC_S1;
struct func_802456FC_S1 {
    char pad0[0x60];
    s32 unk60;
    char pad60[0x64 - 0x60 - sizeof(s32)];
    f32 unk64;
};

struct func_80244494_S1;
struct func_80244494_S1 {
    char * unk0;
    char pad0[0x4 - 0x0 - sizeof(char*)];
    s32 unk4;
    char pad4[0x1C - 0x4 - sizeof(s32)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
    s32 unk28;
    char pad28[0x2C - 0x28 - sizeof(s32)];
    s32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(s32)];
    s32 unk30;
    char pad30[0x34 - 0x30 - sizeof(s32)];
    s32 unk34;
    char pad34[0x40 - 0x34 - sizeof(s32)];
    s32 unk40;
    char pad40[0x44 - 0x40 - sizeof(s32)];
    CVector3 unk44;
    char pad44[0x50 - 0x44 - sizeof(CVector3)];
    CVector3 unk50;
    char pad50[0x74 - 0x50 - sizeof(CVector3)];
    CVector3 unk74;
    char pad74[0xAC - 0x74 - sizeof(CVector3)];
    s32 unkAC;
    char padAC[0x180 - 0xAC - sizeof(s32)];
    CVector3 unk180;
    char pad180[0x198 - 0x180 - sizeof(CVector3)];
    CVector3 unk198;
    char pad198[0x1A4 - 0x198 - sizeof(CVector3)];
    CVector3 unk1A4;
};


struct VectorPair;
typedef struct VectorPair VectorPair;

struct func_80245788_S1;
struct func_80245788_S1 {
    char pad0[0x1C];
    float unk1C;
    char pad1C[0x30 - 0x1C - sizeof(float)];
    float unk30;
    char pad30[0x34 - 0x30 - sizeof(float)];
    float unk34;
    char pad34[0x38 - 0x34 - sizeof(float)];
    int unk38;
};

struct func_80244E48_S2;
struct func_80244E48_S2 {
    char pad0[0x57C];
    s32 unk57C;
    char pad57C[0x580 - 0x57C - sizeof(s32)];
    s32 unk580;
    char pad580[0x590 - 0x580 - sizeof(s32)];
    s32 unk590;
};

struct Work80244494;

struct func_802456FC_S1;
typedef struct func_802456FC_S1 func_802456FC_S1;

struct func_80244E48_S1;
typedef struct func_80244E48_S1 func_80244E48_S1;


struct func_802457D0_S1;
typedef struct func_802457D0_S1 func_802457D0_S1;

struct Record108;
struct Record108 {
    s32 sound;
    s32 unk_4;
    char pad8[0x4];
    VoidCallback onEnd;
    VoidCallback onCue;
    char pad14[0x8];
    f32 value;
    f32 previous;
    char pad24[8];
    f32 limit;
    f32 threshold;
    f32 cue;
    s32 playing;
    s32 done;
    char pad40[0x4];
    s32 cueFired;
    s32 endFired;
    char pad4C[0x14];
    s32 fading;
    f32 fade;
    char pad68[0x4C];
    s32 active;
    char padB8[0x4C];
    s32 mode;
};

struct MotionSurface;

extern s32 func_802457E0_de(void);

struct func_80245930_S1;
typedef struct func_80245930_S1 func_80245930_S1;

struct func_80244E48_S2;
typedef struct func_80244E48_S2 func_80244E48_S2;

struct GameState;
struct GameState {
    s32 busy;
    char pad4[0x18B0];
    s32 paused;
};

extern int func_80245908_de();

struct func_80244E48_S1;
struct func_80244E48_S1 {
    char pad0[0x40];
    s32 unk40;
    char pad40[0x50 - 0x40 - sizeof(s32)];
    s32 unk50;
    char pad50[0x54 - 0x50 - sizeof(s32)];
    s32 unk54;
    char pad54[0x5C - 0x54 - sizeof(s32)];
    s32 unk5C;
    char pad5C[0xD8 - 0x5C - sizeof(s32)];
    s32 unkD8;
    char padD8[0x108 - 0xD8 - sizeof(s32)];
    s32 unk108;
    char pad108[0x10C - 0x108 - sizeof(s32)];
    s32 unk10C;
    char pad10C[0x110 - 0x10C - sizeof(s32)];
    s32 unk110;
    char pad110[0x114 - 0x110 - sizeof(s32)];
    s32 unk114;
};

struct GameState;
typedef struct GameState GameState;

struct func_802457D0_S1;
struct func_802457D0_S1 {
    char pad0[0x1C];
    f32 unk1C;
    char pad1C[0x34 - 0x1C - sizeof(f32)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    s32 unk38;
};

extern int func_80245764_de();

extern void func_802456A0_de();


struct func_802458F8_S1;
typedef struct func_802458F8_S1 func_802458F8_S1;

extern int D_800CB420_de;

struct func_80244494_S1;
typedef struct func_80244494_S1 func_80244494_S1;

extern void func_802458C4_de();

extern int D_800CB41C_de;

struct Record108;
typedef struct Record108 Record108;
#endif
