#ifndef RENDER_POOLRECAT28V1_H
#define RENDER_POOLRECAT28V1_H
#include "TYPES.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"

struct func_80285D00_S1;
typedef struct func_80285D00_S1 func_80285D00_S1;


struct func_80285D00_S1;
struct func_80285D00_S1 {
    char pad0[0x14];
    IntrusiveList unk14;
    char pad14[0x28 - 0x14 - sizeof(IntrusiveList)];
    union { s32 unk28; f32 baseLevel; };
};


struct NodeCode8028469C;
struct PoolRecAt28V1;
/* PoolRecAt28V1 is shared with ControllerProfile in ITEMRECAT20V1.H. */

typedef union func_80285D80_S2_U138 func_80285D80_S2_U138;

extern float D_800C4ED0_de;



struct func_80285880_S1;
struct func_80285880_S1 {
    char pad0[4];
    struct func_80285880_S1 *next;
    void * unk8;
    char pad8[0xC - 0x8 - sizeof(void*)];
    union { Triple unkC; CVector3 position; };
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

#endif
