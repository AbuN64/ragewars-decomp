#ifndef RESMGR_XMATH_BUILDAXISANGLEMATRIX_H
#define RESMGR_XMATH_BUILDAXISANGLEMATRIX_H
#include "COMMON/MATRIXRECORD.H"
#include "RESMGR/MATRIX_RECORD_VIEWS.H"
extern void XMath_GetMatrixTranslation(char *object, float *output);
extern void XMath_ResetMatrixRotation(Mtx3x4_8029FD54 *matrix);
extern void XMath_SetMatrixScaleDiagonal(Matrix *matrix, CVector3 *scale);
extern void XMath_AddMatrixTranslation(Matrix *matrix, void *translation);
extern void XMath_ClearMatrixTranslation(Matrix *matrix);
extern void XMath_SetUniformMatrixScaleDiagonal(Matrix *matrix, float value);
extern void XMath_TransformPointArray(void *matrix, void *destination, void *source, s32 pointCount);
extern void XMath_ScaleMatrixRows(void *matrix, void *scale);
extern void XMath_GetMatrixColumns(float *matrix, float *columnX, float *columnY, float *columnZ);
extern void XMath_PremultiplyMatrix(int destinationMatrix, int leftMatrix);
extern void XMath_PostmultiplyMatrix(s32 destinationMatrix, s32 rightMatrix);
extern void XMath_PremultiplyEulerRotation(s32 matrix, f32 *angles);
extern void XMath_SetMatrixTranslation(Matrix *matrix, float *translation);
extern void XMath_SetMatrixRows(float *matrix, float *rowX, float *rowY, float *rowZ);
extern void XMath_SetMatrixColumns(float *matrix, float *columnX, float *columnY, float *columnZ);
extern void XMath_ScaleMatrixUniformly(void *matrix, f32 scale);
extern void XMath_SetMatrixElements(MatrixRecord *matrix, float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);
extern void XMath_GetMatrixRows(float *matrix, float *rowX, float *rowY, float *rowZ);
extern void XMath_TransposeMatrix(f32 *matrix);
#endif
