#ifndef GAME_8027302C_H
#define GAME_8027302C_H
#include "COMMON/MTX.H"
extern void TranslateMatrixLocal(void *matrix, f32 x, f32 y, f32 z);
extern void BuildYawMatrix(void *matrix, f32 angle);
extern void func_80274380_de(CQuatern *rotation, CQuatern *target);
extern f32 func_80273F94_de(f32 arg0, f32 arg1);
extern void func_80273DA0_de(f32 *dst, f32 *src);
extern void func_80273040_de(f32 *arg0, f32 *arg1);
extern void func_802734F8_de(float * arg0, float * arg1, float sx, float sy, float sz);
extern void func_80274318_de(void *arg0, f32 t, void *a, void *b);
extern void func_80273E20_de(struct Mtx *object);
extern void func_80273E64_de(f32 *dst, f32 *src);
#endif
