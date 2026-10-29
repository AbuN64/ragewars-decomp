#ifndef MATH_VECTOR3INTERSECTPLANE_H
#define MATH_VECTOR3INTERSECTPLANE_H
#include "MATH/DOUBLEBITS.H"
extern void Vector3AnglesInverse(f32 *vector, f32 *pitchOut, f32 *yawOut);
extern void Vector3ProjectArray(CVector3 *out, CVector3 *in, s32 n, f32 ox, f32 sx, f32 oy, f32 sy);
extern void Vector3IntersectPlane(CVector3 *intersectionOut, CVector3 *lineStart, CVector3 *lineEnd, f32 normalX, f32 normalY, f32 normalZ, f32 planeOffset);
extern void Vector3Angles(f32 *vector, f32 *pitchOut, f32 *yawOut);
extern f32 Vector3Dot(f32 *a, f32 *b);
extern void Vector3Distance(f32 *a, f32 *b);
extern void Vector3Cross(CVector3 *out, CVector3 *a, CVector3 *b);
extern void XMath_EvaluateVectorLength(CVector3 *vector);
extern void Vector3Add(void *destination, void *leftVector, void *rightVector);
extern void Vector3Zero(float *vector);
extern void Vector3Normalize(f32 *vector);
extern void Vector3Copy(Triple *destination, Triple *source);
extern void Vector3Subtract(void *destination, void *leftVector, void *rightVector);
extern void XMath_CopyMatrix(void *destination, void *source);
extern f32 XMath_SubtractAnglesCentered(f32 a, f32 b);
extern void Vector3Set(void *destination, float xValue, float yValue, float zValue);
extern void Vector3Negate(void *destination, void *source);
extern void Vector3Scale(void *destination, void *source, f32 scaleFactor);
extern void Vector3Unpack(float *source, float *xOut, float *yOut, float *zOut);
#endif
