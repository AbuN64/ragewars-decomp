#ifndef UNBAKE_SPAN_1000_CODE_8028567C_H
#define UNBAKE_SPAN_1000_CODE_8028567C_H
#include "types.h"
#include "span_1000/code_802646F4.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
extern float D_800C4EC8_de;

struct func_80285C48_S2;
typedef struct func_80285C48_S2 func_80285C48_S2;

struct func_80285D00_S1;
typedef struct func_80285D00_S1 func_80285D00_S1;

extern void func_802858B0_de(NodeCode8028469C *arg0, Clip *arg1, Vec3 arg2, f32 arg5, f32 arg6, void **arg7);

struct func_80285D00_S1;
struct func_80285D00_S1 {
    char pad0[0x14];
    IntrusiveList unk14;
    char pad14[0x28 - 0x14 - sizeof(IntrusiveList)];
    union { s32 unk28; f32 baseLevel; };
};

extern s32 func_8028597C_de(s32 arg0);

struct NodeCode8028469C;
struct PoolRecAt28V1;
struct PoolRecAt28V1 {
    IntrusiveList free;
    IntrusiveList active;
    s32 baseLevel; /* 0x28 */
};

union func_80285D80_S2_U138;
union func_80285D80_S2_U138 {
    u32 v0;
    char * v1;
};

union func_80285D80_S2_U138;
typedef union func_80285D80_S2_U138 func_80285D80_S2_U138;

struct func_80285D80_S2;
struct func_80285D80_S2 {
    char pad0[0x80];
    void * unk80;
    char pad80[0x138 - 0x80 - sizeof(void*)];
    func_80285D80_S2_U138 unk138;
    char pad138[0x140 - 0x138 - sizeof(func_80285D80_S2_U138)];
    s32 unk140;
    char pad140[0x1B40C - 0x140 - sizeof(s32)];
    s32 unk1B40C;
};

extern float D_800C4ED0_de;

extern void func_80285960_de(char *object);

extern f32 func_802859D0_de(f32 *arg0, u32 arg1, u32 arg2, u32 arg3);

struct func_80285A94_S2;
struct func_80285A94_S2 {
    char pad0[0x3C];
    char unk3C;
};

struct func_80285F28_S2;
typedef struct func_80285F28_S2 func_80285F28_S2;

struct func_80285930_S1;
struct func_80285930_S1 {
    char pad0[0x38];
    int * unk38;
};

struct func_80285A94_S2;
typedef struct func_80285A94_S2 func_80285A94_S2;

struct func_80285C48_S2;
struct func_80285C48_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x38 - 0x4 - sizeof(void*)];
    s32 * unk38;
};

struct func_80285D80_S2;
typedef struct func_80285D80_S2 func_80285D80_S2;

struct func_80285F28_S2;
struct func_80285F28_S2 {
    char pad0[0x80];
    void * unk80;
    char pad80[0x138 - 0x80 - sizeof(void*)];
    u32 unk138;
    char pad138[0x140 - 0x138 - sizeof(u32)];
    s32 unk140;
    char pad140[0x1B40C - 0x140 - sizeof(s32)];
    s32 unk1B40C;
};

struct func_80285880_S1;
struct func_80285880_S1 {
    char pad0[4];
    struct func_80285880_S1 *next;
    void * unk8;
    char pad8[0xC - 0x8 - sizeof(void*)];
    union { Triple unkC; Vec3 position; };
    char padC[0x18 - 0xC - sizeof(Triple)];
    f32 unk18;
    char pad18[0x1C - 0x18 - sizeof(f32)];
    f32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    union {
        struct { unsigned int unk20; char pad20[8]; };
        PlayerRecAt8 amplitudeCurve;
    };
    union {
        struct { unsigned int unk2C; char pad2C[8]; };
        PlayerRecAt8 lifetimeCurve;
    };
    void ** unk38;
};

struct func_80285880_S1;
typedef struct func_80285880_S1 func_80285880_S1;

struct PoolRecAt28V1;
typedef struct PoolRecAt28V1 PoolRecAt28V1;

struct func_80285930_S1;
typedef struct func_80285930_S1 func_80285930_S1;

#endif
