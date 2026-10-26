#ifndef COMMON_RECTANGLE_DRAW_H
#define COMMON_RECTANGLE_DRAW_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

/* Five cached flag groups written together by func_80417138_de. */
extern Rec_func_8024C92C_de D_80153F60;
extern s32 D_800DF274;
extern s32 D_800DF280;
extern s32 D_800DF28C;
extern s32 D_800DF290;

void func_80415C90_de(f32 x, f32 y, f32 width, f32 height, u32 c0, u32 c1, u32 c2, u32 c3);
void N64Eng_GetClipBounds(s32 *left, s32 *top, s32 *right, s32 *bottom);
void func_80417B20_de(f32 x, f32 y, f32 unused, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, u32 color);
void Gfx_DrawRect(f32 x, f32 y, f32 unused, f32 width, f32 height, u32 color);
#endif
