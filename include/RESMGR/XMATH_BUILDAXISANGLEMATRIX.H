#ifndef RESMGR_XMATH_BUILDAXISANGLEMATRIX_H
#define RESMGR_XMATH_BUILDAXISANGLEMATRIX_H
#include "COMMON/MATRIXRECORD.H"
#include "RESMGR/8029FA7C.H"
extern void XMath_GetMatrixTranslation(char *object, float *output);
extern void XMath_ResetMatrixRotation(Mtx3x4_8029FD54 *arg0);
extern void XMath_SetMatrixScaleDiagonal(Matrix *arg0, CVector3 *arg1);
extern void XMath_AddMatrixTranslation(Matrix *arg0, void *arg1);
extern void XMath_ClearMatrixTranslation(Matrix *arg0);
extern void XMath_SetUniformMatrixScaleDiagonal(Matrix *arg0, float value);
extern void XMath_TransformPointArray(void *arg0, void *arg1, void *arg2, s32 arg3);
extern void XMath_ScaleMatrixRows(void *arg0, void *arg1);
extern void XMath_GetMatrixColumns(float *arg0, float *arg1, float *arg2, float *arg3);
extern void XMath_PremultiplyMatrix(int arg0, int arg1);
extern void XMath_PostmultiplyMatrix(s32 arg0, s32 arg1);
extern void XMath_PremultiplyEulerRotation(s32 arg0, f32 *angles);
extern void XMath_SetMatrixTranslation(Matrix *arg0, float *arg1);
extern void XMath_SetMatrixRows(float *arg0, float *arg1, float *arg2, float *arg3);
extern void XMath_SetMatrixColumns(float *arg0, float *arg1, float *arg2, float *arg3);
extern void XMath_ScaleMatrixUniformly(void *arg0, f32 arg1);
extern void XMath_SetMatrixElements(MatrixRecord *arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float arg9, float arg10, float arg11, float arg12, float arg13, float arg14, float arg15, float arg16);
extern void XMath_GetMatrixRows(float *arg0, float *arg1, float *arg2, float *arg3);
extern void XMath_TransposeMatrix(f32 *arg0);
#endif
