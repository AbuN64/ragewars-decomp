#ifndef MATH_INVERTMATRIX_H
#define MATH_INVERTMATRIX_H
#include "COMMON/OBJRECAT3CV2.H"
#include "MATH/ROTATION_MATRIX_ELEMENT_VIEWS.H"
extern void XMath_BuildYxzRotationMatrix(RotationMatrixWords *matrixOut, CVector3 *angles);
extern void XMath_OrthogonalizeMatrixBasis(PlaneEquation *m);
extern void XMath_ExtractYxzAngles(RotationMatrixElementsView *matrix, CVector3 *anglesOut);
extern void XMath_ExtractZyxAngles(RotationMatrixElementsView *matrix, CVector3 *anglesOut);
extern s32 XMath_InvertAffineMatrix(f32 *out, f32 *input);
#endif
