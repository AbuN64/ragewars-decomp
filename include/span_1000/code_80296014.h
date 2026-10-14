#ifndef UNBAKE_SPAN_1000_CODE_80296014_H
#define UNBAKE_SPAN_1000_CODE_80296014_H
#include "types.h"
extern void func_80295FF4_de();

extern f32 func_802969B0_de(f32 *a, f32 *b);

struct Frustum;
struct Frustum {
    f32 planes[6][4];
};

extern f32 func_80296930_de(f32 *arg0, f32 *arg1, f32 *arg2);

struct Obj5;
typedef struct Obj5 Obj5;

struct Obj5;
struct Obj5 {
    char pad0[4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s16 table[400];
};

struct Frustum;
typedef struct Frustum Frustum;

struct Board;
typedef struct Board Board;

extern float D_800C5510_de;

struct Board;
struct Board {
    s32 unk0;
    s32 unk4;
    s32 originX;
    s32 originY;
    s32 unk10;
    s32 unk14;
    s16 cells[17 * 17];
};

extern s32 func_80296C30_de(f32 *arg0, f32 *arg1);

#endif
