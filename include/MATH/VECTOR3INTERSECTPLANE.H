#ifndef MATH_VECTOR3INTERSECTPLANE_H
#define MATH_VECTOR3INTERSECTPLANE_H
#include "MATH/DOUBLEBITS.H"
extern void Vector3AnglesInverse(f32 *arg0, f32 *arg1, f32 *arg2);
extern void Vector3ProjectArray(CVector3 *out, CVector3 *in, s32 n, f32 ox, f32 sx, f32 oy, f32 sy);
extern void Vector3IntersectPlane(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
extern void Vector3Angles(f32 *arg0, f32 *arg1, f32 *arg2);
extern f32 Vector3Dot(f32 *a, f32 *b);
extern void Vector3Distance(f32 *a, f32 *b);
extern void Vector3Cross(CVector3 *out, CVector3 *a, CVector3 *b);
extern void XMath_EvaluateVectorLength(CVector3 *arg0);
extern void Vector3Add(void *arg0, void *arg1, void *arg2);
extern void Vector3Zero(float *vector);
extern void Vector3Normalize(f32 *arg0);
extern void Vector3Copy(Triple *arg0, Triple *arg1);
extern void Vector3Subtract(void *arg0, void *arg1, void *arg2);
extern void XMath_CopyMatrix(void *arg0, void *arg1);
extern f32 XMath_SubtractAnglesCentered(f32 a, f32 b);
extern void Vector3Set(void *arg0, float arg1, float arg2, float arg3);
extern void Vector3Negate(void *arg0, void *arg1);
extern void Vector3Scale(void *arg0, void *arg1, f32 arg2);
extern void Vector3Unpack(float *arg0, float *arg1, float *arg2, float *arg3);
#endif
