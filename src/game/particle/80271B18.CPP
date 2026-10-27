#include "include_asm.h"
#include "COMMON/S1_3.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"

#include "COMMON/MATH_HELPERS.H"
extern f32 Math_Sqrtf(f32);
/** Heading of a direction in the XZ plane: acos of the dominant axis, clamped to [-1, 1]. */
f32 GraphU64_GetHorizontalAngle(CVector3 *direction) {
    f32 x = direction->x;
    f32 z = direction->z;
    f32 length = x * x + z * z;
    f32 angle;
    f32 a;
    if (length == 0.0f) {
        return 0.0f;
    }
    length = Math_Sqrtf(length);
    if (length == 0.0f) {
        return 0.0f;
    }
    if (RW_ABS(x) < RW_ABS(z)) {
        x /= length;
        x = RW_MAX_GT(-1.0f, RW_MIN(x, 1.0f));
        a = GraphU64_ArcCos(x);
        angle = -a;
        if (z < 0.0f) {
            angle = a;
        }
        angle -= 1.5707964f;
    } else {
        z /= length;
        z = RW_MAX_GT(-1.0f, RW_MIN(z, 1.0f));
        a = GraphU64_ArcCos(-z);
        angle = -a;
        if (x < 0.0f) {
            angle = a;
        }
    }
    return angle;
}


extern f32 D_800C48AC_de;

/** Wrap an angle into [-pi, pi]. */
static inline f32 WrapAngle(f32 angle) {
    while (angle < -3.1415927f) {
        angle += 6.2831855f;
    }
    while (angle > 3.1415927f) {
        angle -= 6.2831855f;
    }
    return angle;
}
#define ANGLE_ABS(a) (-(a) < 0.0f ? (a) : -(a))
/** Absolute angle between two headings, each wrapped into [-pi, pi]. */
f32 GraphU64_GetAngleDistance(f32 target, f32 current) {
    return ANGLE_ABS(WrapAngle(target - WrapAngle(current)));
}

/** Component-wise multiply two 3-vectors. */
void GraphU64_MultiplyVectorComponents(CVector3 *result, CVector3 *left, CVector3 *right) {
    result->x = left->x * right->x;
    result->y = left->y * right->y;
    result->z = left->z * right->z;
}

/** Add two three-component vectors. */
void GraphU64_AddVec3(CVector3 *result, CVector3 *left, CVector3 *right) {
    result->x = left->x + right->x;
    result->y = left->y + right->y;
    result->z = left->z + right->z;
}

/** Subtract the right vector from the left vector. */
void GraphU64_SubtractVectors(CVector3 *difference, CVector3 *leftVector, CVector3 *rightVector) {
    difference->x = leftVector->x - rightVector->x;
    difference->y = leftVector->y - rightVector->y;
    difference->z = leftVector->z - rightVector->z;
}

/** Scale a 3-vector (arg1) by a scalar (arg2), store into arg0. */
void GraphU64_ScaleVector(void *scaledVector, void *inputVector, f32 scaleFactor) {
    ((CVector3 *)(scaledVector))->x = ((CVector3 *)(inputVector))->x * scaleFactor;
    ((CVector3 *)(scaledVector))->y = ((CVector3 *)(inputVector))->y * scaleFactor;
    ((CVector3 *)(scaledVector))->z = ((CVector3 *)(inputVector))->z * scaleFactor;
}

/** Lerp a 3-component vector: out = a + t * (b - a). */
void GraphU64_InterpolateVector(CVector3 *arg0, f32 t, void *a, void *b) {
    arg0->x = ((CVector3 *)(a))->x + (t * (((CVector3 *)(b))->x - ((CVector3 *)(a))->x));
    arg0->y = ((CVector3 *)(a))->y + (t * (((CVector3 *)(b))->y - ((CVector3 *)(a))->y));
    arg0->z = ((CVector3 *)(a))->z + (t * (((CVector3 *)(b))->z - ((CVector3 *)(a))->z));
}

/** Cross product of two vectors, written directly to the output (no aliasing guard). */
void GraphU64_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b) {
    out->x = (a->y * b->z) - (a->z * b->y);
    out->y = (a->z * b->x) - (a->x * b->z);
    out->z = (a->x * b->y) - (a->y * b->x);
}

void GraphU64_NormalizeVec3(f32 *vectorComponents) {
    f32 mag;
    f32 scale;

    mag = Math_Sqrtf((vectorComponents[0] * vectorComponents[0]) + (vectorComponents[1] * vectorComponents[1]) + (vectorComponents[2] * vectorComponents[2]));
    if (mag != 0.0f) {
        scale = D_800C48AC_de / mag;
        vectorComponents[0] = vectorComponents[0] * scale;
        vectorComponents[1] = vectorComponents[1] * scale;
        vectorComponents[2] = vectorComponents[2] * scale;
    }
}

/** Intersect a line segment with a horizontal plane and write the point. */
void GraphU64_InterpolateAtHeight(CVector3 *out, CVector3 *a, CVector3 *b, f32 y) {
    f32 dy = b->y - a->y;

    if (dy == 0.0f) {
        *out = *a;
        return;
    }

    {
        f32 t = (y - a->y) / dy;
        out->x = a->x + (t * (b->x - a->x));
        out->y = y;
        out->z = a->z + (t * (b->z - a->z));
    }
}

void *GraphU64_ReflectVector(CVector3 *arg0, CVector3 *remaining, CVector3 *arg2, f32 arg3) {
    CVector3 tmp;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;

    temp_f5 = remaining->x;
    temp_f4 = arg2->x;
    temp_f3 = (temp_f5 * temp_f4) + (remaining->y * arg2->y) + (remaining->z * arg2->z);
    temp_f2 = (arg3 * temp_f3) + temp_f3;
    tmp.x = temp_f5 - (temp_f2 * temp_f4);
    tmp.y = remaining->y - (temp_f2 * arg2->y);
    tmp.z = remaining->z - (temp_f2 * arg2->z);
    *arg0 = tmp;
    return arg0;
}

void *GraphU64_ProjectVectorOntoPlane(CVector3 *arg0, CVector3 *remaining, CVector3 *arg2) {
    CVector3 tmp;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f5;

    temp_f5 = remaining->x;
    temp_f4 = arg2->x;
    temp_f2 = (temp_f5 * temp_f4) + (remaining->y * arg2->y) + (remaining->z * arg2->z);
    tmp.x = temp_f5 - (temp_f2 * temp_f4);
    tmp.y = remaining->y - (temp_f2 * arg2->y);
    tmp.z = remaining->z - (temp_f2 * arg2->z);
    *arg0 = tmp;
    return arg0;
}
