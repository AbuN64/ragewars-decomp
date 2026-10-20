#ifndef COMMON_FRUSTUM_H
#define COMMON_FRUSTUM_H
#include "TYPES.H"

extern f32 func_802969B0_de(f32 *a, f32 *b);

struct Frustum;
struct Frustum {
    f32 planes[6][4];
};

extern f32 func_80296930_de(f32 *arg0, f32 *arg1, f32 *arg2);

struct Frustum;
typedef struct Frustum Frustum;

extern float D_800C5510_de;

extern s32 func_80296C30_de(f32 *arg0, f32 *arg1);

extern void *func_80411DCC_de(s32 index);

s32 func_80411DF0_de(s32);
#endif
