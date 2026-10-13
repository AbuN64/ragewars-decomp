#ifndef RAGEWARS_SHARED_RECTANGLE_DRAW_H
#define RAGEWARS_SHARED_RECTANGLE_DRAW_H
#include "types.h"
#include "common/types_1dc8418c21db.h"

/* Five cached flag groups written together by func_80417138_de. */
extern Rec_func_8024C92C_de D_80153F60;
extern s32 D_800DF274;
extern s32 D_800DF280;
extern s32 D_800DF28C;
extern s32 D_800DF290;

void func_80417034_de(s32 mode);
void func_80416CF4_de(s32 mode);
void func_80416ECC_de(s32 mode);
void func_80415C90_de(f32 x, f32 y, f32 width, f32 height, u32 c0, u32 c1, u32 c2, u32 c3);
void func_802A1898_de(s32 *left, s32 *top, s32 *right, s32 *bottom);
void func_804181A4_de(s32 x0, s32 y0, s32 x1, s32 y1, f32 u0, f32 v0, f32 u1, f32 v1);
void func_80417B20_de(f32 x, f32 y, s32 unused, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, u32 color);
#endif
