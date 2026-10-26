#ifndef GAME_8027302C_H
#define GAME_8027302C_H
#include "COMMON/MTX.H"
extern void TranslateMatrixLocal(void *matrix, f32 x, f32 y, f32 z);
extern void BuildYawMatrix(void *matrix, f32 angle);
extern void GraphU64_ApproachQuaternion(CQuatern *rotation, CQuatern *target);
extern f32 GraphU64_GetWrappedDifference(f32 arg0, f32 arg1);
extern void GraphU64_CopySwappedMatrixBasis(f32 *dst, f32 *src);
extern void GraphU64_TransposeMatrixBasis(f32 *arg0, f32 *arg1);
extern void GraphU64_CopyScaledMatrix(float * arg0, float * arg1, float sx, float sy, float sz);
extern void GraphU64_InterpolateQuaternionComponents(void *arg0, f32 t, void *a, void *b);
extern void GraphU64_SwapMatrixCoordinates(struct Mtx *object);
extern void GraphU64_CopySwappedMatrixCoordinates(f32 *dst, f32 *src);
#endif
