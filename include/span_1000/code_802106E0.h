#ifndef UNBAKE_SPAN_1000_CODE_802106E0_H
#define UNBAKE_SPAN_1000_CODE_802106E0_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
extern float D_800C1FD8_de;

struct func_80211020_S1;
struct func_80211020_S1 {
    char pad0[0x21C];
    s32 unk21C;
    char pad21C[0x220 - 0x21C - sizeof(s32)];
    s32 unk220;
};

extern void func_80212948_de(void *arg0);

struct Self;
struct Brain_func_802120A8_eu;
struct Self {
    char pad0[8];
    Vec3 pos;
    char pad14[0x24];
    s32 flags;
    char pad3C[0x30];
    f32 yaw;
    char pad70[0x168];
    struct Self *self;
    char pad1DC[0x3F8];
    s32 slot;
    char pad5D8[0xCC];
    f32 strafe;
    char pad6A8[0xDAC];
    struct Brain_func_802120A8_eu *brain;
};

struct Brain_func_802120A8_eu {
    struct Self *player;
    s32 route;
    char pad8[8];
    s32 node;
    s32 routeNodes[4]; /* 0x14 */
    char pad24[0x40];
    struct Self *target;
    struct Player *routeObject; /* 0x68 */
    char pad6C[0x50];
    s32 routeState; /* 0xBC */
    char padC0[0x130];
    f32 walk[8];
    char pad210[0x20];
    s32 combat;
    char pad234[0xA4];
    s32 timer;
    s32 pattern;
    char pad2E0[0x38];
    s32 frames;
    s32 visible;
};

struct func_8021290C_S3;
struct func_8021290C_S3 {
    char pad0[0xC];
    int unkC;
    char padC[0x220 - 0xC - sizeof(int)];
    int unk220;
    char pad220[0x2FC - 0x220 - sizeof(int)];
    int unk2FC;
};

struct CloseAttackActor;
extern void func_80212470_eu(struct CloseAttackActor *arg0);

struct ObjectState3C;
struct ObjectState3C {
    char pad0[0x8];
    f32 unk_8;
    char pad8[0x38 - 0x8 - sizeof(f32)];
    u32 unk_38;
};

struct CloseAttackBrain;
typedef struct CloseAttackBrain CloseAttackBrain;

struct func_802123DC_S3;
typedef struct func_802123DC_S3 func_802123DC_S3;

extern float D_800C1FE8_de;

struct CloseAttackActor;
typedef struct CloseAttackActor CloseAttackActor;

struct CloseAttackActor;
struct CloseAttackBrain;
struct CloseAttackActor {
    char pad0[8];
    Vec3 pos;
    char pad14[0x24];
    s32 flags;
    char pad3C[0x30];
    f32 yaw;
    char pad70[0x168];
    struct CloseAttackActor *self;
    char pad1DC[0x3F8];
    s32 slot;
    char pad5D8[0xCC];
    f32 strafe;
    f32 forward;
    s32 w6AC;
    s32 buttons;
    char pad6B4[0xDA0];
    struct CloseAttackBrain *brain;
};

struct CloseAttackBrain {
    CloseAttackActor *player;
    s32 route;
    s32 w8;
    s32 destination;
    s32 node;
    s32 routeNodes[4]; /* 0x14 */
    char pad24[0x40];
    CloseAttackActor *target;
    struct Player *routeObject; /* 0x68 */
    char pad6C[0x50];
    s32 routeState; /* 0xBC */
    char padC0[0x130];
    f32 walk[8];
    char pad210[0x10];
    s32 state; /* 0x220 */
    char pad224[0xC];
    s32 combat;
    char pad234[0xA4];
    s32 timer;
    s32 pattern;
    s32 distance;
    char pad2E4[0x18];
    s32 reset2FC; /* 0x2FC: reset after route initialization */
    char pad300[0x18];
    s32 frames;
    s32 visible;
    s32 fireTimer;
};

extern void func_80211490_eu(CloseAttackActor *actor);

struct Brain_func_802120A8_eu;
typedef struct Brain_func_802120A8_eu Brain_func_802120A8_eu;

struct IntegerState1C;
struct IntegerState1C {
    char pad0[0x4];
    s32 unk_4;
    char pad4[0x18 - 0x4 - sizeof(s32)];
    s32 unk_18;
};

extern void func_802127F4_de(void *arg0);

struct IntegerState1C;
typedef struct IntegerState1C IntegerState1C;

struct PlayerRecAt288;
struct PlayerRecAt288 {
    s32 active;
    char pad4[0x1CC - 4];
    s32 timer;
    f32 first[8];
    f32 second[8];
    f32 level;
    char pad214[0x288 - 0x214];
    s32 ready;
};

struct Hit_func_802106E0_de;
struct Hit_func_802106E0_de {
    char pad0[0xE4];
    Vec3 pos;
};

extern int func_80211000_de(int arg0);

struct PlayerRecAt1CC;
struct PlayerRecAt1CC {
    void *clip;
    char pad4[0x1C8];
    int frame;
};

struct PlayerRecAt1CC;
typedef struct PlayerRecAt1CC PlayerRecAt1CC;

extern int func_80210E88_de(PlayerRecAt1CC *p);

extern void func_80212C04_de(void *arg0);

extern float D_800C1FF0_de;

struct func_80212828_S3;
typedef struct func_80212828_S3 func_80212828_S3;

extern float D_800C1FDC_de;

extern float D_800C1FE4_de;

struct func_80212450_S3;
struct func_80212450_S3 {
    char pad0[0x220];
    s32 unk220;
    char pad220[0x2D8 - 0x220 - sizeof(s32)];
    s32 unk2D8;
    char pad2D8[0x2DC - 0x2D8 - sizeof(s32)];
    s32 unk2DC;
    char pad2DC[0x2E0 - 0x2DC - sizeof(s32)];
    s32 unk2E0;
    char pad2E0[0x318 - 0x2E0 - sizeof(s32)];
    s32 unk318;
    char pad318[0x31C - 0x318 - sizeof(s32)];
    s32 unk31C;
    char pad31C[0x320 - 0x31C - sizeof(s32)];
    s32 unk320;
};

struct Shared_Actor;
extern void func_80212A7C_de(struct Shared_Actor *arg0);

extern int func_80210FE8_de(int arg0);

struct func_80211020_S1;
typedef struct func_80211020_S1 func_80211020_S1;

struct func_80212948_S3;
typedef struct func_80212948_S3 func_80212948_S3;

struct func_80212828_S3;
struct func_80212828_S3 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x64 - 0x10 - sizeof(s32)];
    void * unk64;
    char pad64[0x230 - 0x64 - sizeof(void*)];
    s32 unk230;
};

struct ObjectState2C;
typedef struct ObjectState2C ObjectState2C;

struct func_80212948_S3;
struct func_80212948_S3 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unkC;
    char padC[0x64 - 0xC - sizeof(s32)];
    void * unk64;
    char pad64[0x230 - 0x64 - sizeof(void*)];
    s32 unk230;
};

struct Hit_func_802106E0_de;
typedef struct Hit_func_802106E0_de Hit_func_802106E0_de;

struct ObjectState3C;
typedef struct ObjectState3C ObjectState3C;

extern void func_80211A9C_eu(CloseAttackActor *actor);

struct Vehicle;
typedef struct Vehicle Vehicle;

extern float D_800C1FEC_de;

extern void func_80212828_de(CloseAttackActor *arg0);

struct Self;
typedef struct Self Self;

struct Wheels;
struct Wheels {
    char pad0[0x1D0];
    f32 reach[8];
    char pad1F0[0x20];
    f32 length;
};
struct Vehicle;
struct Wheels;
struct Vehicle {
    char pad0[8];
    Vec3 pos;
    char pad14[0x1440];
    struct Wheels *wheels;
};

extern float D_800C1FE0_de;

struct LevelActor;
extern void func_8021290C_de(struct LevelActor *arg0);

struct func_80212828_S5;
struct func_80212828_S5 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x1454 - 0x8 - sizeof(f32)];
    void * unk1454;
};

extern void func_802123FC_eu(void *arg0);

struct func_8021290C_S3;
typedef struct func_8021290C_S3 func_8021290C_S3;

extern void func_80212A40_de(struct LevelActor *arg0);

struct ObjectState2C;
struct ObjectState2C {
    char pad0[0x4];
    s32 unk_4;
    char pad4[0xC - 0x4 - sizeof(s32)];
    s32 unk_C;
    char padC[0x14 - 0xC - sizeof(s32)];
    char unk_14;
    char pad14[0x28 - 0x14 - sizeof(char)];
    s32 unk_28;
};

struct func_80212450_S3;
typedef struct func_80212450_S3 func_80212450_S3;

extern float D_800C70F4;

extern float D_800C70F0;

struct func_80212828_S5;
typedef struct func_80212828_S5 func_80212828_S5;

extern void func_80212BD0_de(void *arg0);

struct func_802123DC_S3;
struct func_802123DC_S3 {
    char pad0[0x220];
    s32 unk220;
    char pad220[0x2D8 - 0x220 - sizeof(s32)];
    s32 unk2D8;
    char pad2D8[0x2DC - 0x2D8 - sizeof(s32)];
    s32 unk2DC;
};

extern void func_802120A8_eu(Self *actor);

extern int func_80212610_eu(CloseAttackActor *arg0);

extern s32 func_802744D4_de(void);
typedef struct func_802125F0_S1 func_802125F0_S1;
typedef struct func_802125F0_S2 func_802125F0_S2;
typedef struct func_802125F0_S3 func_802125F0_S3;
struct func_802125F0_S1 {
    char pad0[0x1D8];
    void* unk1D8;
};
struct func_802125F0_S2 {
    char pad0[0x1454];
    void* unk1454;
};
struct func_802125F0_S3 {
    char pad0[0x220];
    s32 unk220;
    char pad220[0x2D8 - 0x220 - sizeof(s32)];
    s32 unk2D8;
    char pad2D8[0x2DC - 0x2D8 - sizeof(s32)];
    s32 unk2DC;
};

#endif
