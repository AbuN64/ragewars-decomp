#ifndef MATH_8029BBA0_4_H
#define MATH_8029BBA0_4_H
#include "COMMON/OBJRECAT3CV2.H"
#include "MATH/8029BBA0.H"
extern void XMath_BuildYxzRotationMatrix(ObjRecAt3CV2 *arg0, CVector3 *arg1);
extern void XMath_OrthogonalizeMatrixBasis(PlaneEquation *m);
extern void XMath_ExtractYxzAngles(InputRecAt28 *arg0, CVector3 *arg1);
extern void XMath_ExtractZyxAngles(InputRecAt28 *arg0, CVector3 *arg1);
extern s32 XMath_InvertAffineMatrix(f32 *out, f32 *input);
#endif
