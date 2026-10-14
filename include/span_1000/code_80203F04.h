#ifndef UNBAKE_SPAN_1000_CODE_80203F04_H
#define UNBAKE_SPAN_1000_CODE_80203F04_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
extern void func_80204DFC_de(void *arg0);

struct ObjRecAt30;
struct ObjRecAt30 {
    char pad0[0x30];
    Hook * unk30;
};

struct func_80204620_S2;
typedef struct func_80204620_S2 func_80204620_S2;

extern float D_800C6B74;

extern void func_80204728_de(void *arg0, void *arg1);

struct BreakableHitContext;
struct BreakableHitContext {
    char pad0[0x8];
    Vec3 unk_8;
    char pad8[0x18 - 0x8 - sizeof(Vec3)];
    char * unk_18;
    char pad18[0xE6 - 0x18 - sizeof(char*)];
    s8 unk_E6;
    char padE6[0x100 - 0xE6 - sizeof(s8)];
    s32 unk_100;
    char pad100[0x104 - 0x100 - sizeof(s32)];
    f32 unk_104;
    char pad104[0x108 - 0x104 - sizeof(f32)];
    s16 unk_108;
    char pad108[0x10A - 0x108 - sizeof(s16)];
    s16 unk_10A;
    char pad10A[0x10C - 0x10A - sizeof(s16)];
    s16 unk_10C;
    char pad10C[0x12C - 0x10C - sizeof(s16)];
    s16 unk_12C;
    char pad12C[0x134 - 0x12C - sizeof(s16)];
    f32 unk_134;
};

struct func_80204738_S1;
typedef struct func_80204738_S1 func_80204738_S1;

struct func_80204C68_S2;
typedef struct func_80204C68_S2 func_80204C68_S2;

extern void func_802043E0_de(char *arg0, char *arg1);

struct func_80204468_S1;
struct func_80204468_S1 {
    char pad0[0x2C];
    void * unk2C;
    char pad2C[0x108 - 0x2C - sizeof(void*)];
    void * unk108;
    char pad108[0x124 - 0x108 - sizeof(void*)];
    int unk124;
    char pad124[0x128 - 0x124 - sizeof(int)];
    int unk128;
    char pad128[0x12C - 0x128 - sizeof(int)];
    int unk12C;
};

extern void func_802047D8_de(void *arg0);

struct func_80204728_S1;
struct func_80204728_S1 {
    char pad0[0x10C];
    void * unk10C;
};

extern void func_80204E48_de(void *arg0);

struct ObjectStateCC;
struct ObjectStateCC {
    char pad0[0xCA];
    s8 unk_CA;
    char padCA[0xCB - 0xCA - sizeof(s8)];
    s8 unk_CB;
};

extern void func_80204BB4_de(void *arg0, void *arg1);

struct func_80204468_S1;
typedef struct func_80204468_S1 func_80204468_S1;

extern void func_80204468_de(void *arg0, void *arg1);

extern float D_800C1A70_de;

struct func_80204C68_S1;
struct func_80204C68_S1 {
    char pad0[0x64];
    s32 unk64;
};

struct func_8020459C_S2;
struct func_8020459C_S2 {
    char pad0[0x20];
    s16 unk20;
};

extern s32 func_80204620_de(void *arg0);

extern void func_80204738_de(void *object);

struct ObjRecAt30;
typedef struct ObjRecAt30 ObjRecAt30;

struct ObjectStateCC;
typedef struct ObjectStateCC ObjectStateCC;

struct BreakableHitContext;
typedef struct BreakableHitContext BreakableHitContext;

struct RiderRecAt130V2;
typedef struct RiderRecAt130V2 RiderRecAt130V2;

struct func_80204C68_S2;
struct func_80204C68_S2 {
    char pad0[0x8];
    Triple unk8;
    char pad8[0x100 - 0x8 - sizeof(Triple)];
    s32 unk100;
};

struct func_8020459C_S2;
typedef struct func_8020459C_S2 func_8020459C_S2;

extern void func_8020478C_de(void *arg0);

struct RiderRecAt130V2;
struct RiderRecAt130V2 {
    char pad0[0x130];
    Vec3 aim;
};

struct func_80204728_S1;
typedef struct func_80204728_S1 func_80204728_S1;

struct LevelActor;
extern s32 func_8020459C_de(struct LevelActor *actor);

struct func_80204738_S1;
struct func_80204738_S1 {
    char pad0[0x100];
    int unk100;
    char pad100[0x1B0 - 0x100 - sizeof(int)];
    float unk1B0;
};

struct func_80204C68_S1;
typedef struct func_80204C68_S1 func_80204C68_S1;


struct Actor_func_8024A1D0_de;
struct InputRecAt40;
struct Lookup;
void func_80204808_de(struct Actor_func_8024A1D0_de *actor, struct InputRecAt40 *input, struct Lookup *lookup);

/* Definition fields used by breakable-actor flag setup. */
typedef struct BreakableDefinition {
    u8 reserved0[0x14];
    s32 flags;
    u8 reserved18[8];
    s16 triggerValue; /* 0x20: kind-10 state callback result */
    u8 reserved22[6];
    s16 health; /* 0x28 */
} BreakableDefinition;

#endif
