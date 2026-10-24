#include "include_asm.h"
#include "COMMON/S1_3.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/S1_3.H"
#include "COMMON/MATH_HELPERS.H"

extern f32 func_802B72B0_de(f32);
extern f32 func_802745D0_de(f32);
extern f32 D_800C4838_de;
extern f32 D_800C483C_de;
extern f32 D_800C4840_de;
extern f32 D_800C4844_de;


static inline f32 clampf(f32 v, f32 lo, f32 hi) { return v < lo ? lo : (v > hi ? hi : v); }
f32 Particle_GetHorizontalAngle(CVector3 *direction) {
    f32 x = direction->x;
    f32 z = direction->z;
    f32 length = x * x + z * z;
    f32 angle;
    f32 a;
    if (length == 0.0f) {
        return 0.0f;
    }
    length = func_802B72B0_de(length);
    if (length == 0.0f) {
        return 0.0f;
    }
    if (RW_ABS(x) < RW_ABS(z)) {
        x /= length;
        x = clampf(x, D_800C483C_de, D_800C4838_de);
        a = func_802745D0_de(x);
        angle = (z < 0.0f ? a : -a) - D_800C4840_de;
    } else {
        z /= length;
        z = clampf(z, D_800C4848_de, D_800C4844_de);
        a = func_802745D0_de(-z);
        angle = x < 0.0f ? a : -a;
    }
    return angle;
}
#else
INCLUDE_ASM("span_1000", Particle_GetHorizontalAngle);
#endif

extern f32 func_802B72B0_de(f32);

extern f32 D_800C48AC_de;

f32 func_80271C54_de(f32 arg0, f32 arg1) {
    extern f32 D_800C48A8_de;
    f32 var_f0;
    f32 result;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f14;

    var_f14 = arg1;
    var_f0_3 = var_f14;
    if (var_f14 < *(&D_800C4848_de + 1)) {
        do {
            var_f0_3 += D_800C4850_de;
        } while (var_f0_3 < *(&D_800C4848_de + 1));
    }
    if (*(&D_800C4850_de + 1) < var_f0_3) {
        do {
            var_f0_3 -= D_800C4858_de;
        } while (*(&D_800C4850_de + 1) < var_f0_3);
    }
    var_f0_4 = arg0 - var_f0_3;
    if (var_f0_4 < *(&D_800C4858_de + 1)) {
        do {
            var_f0_4 += D_800C4860_de;
        } while (var_f0_4 < *(&D_800C4858_de + 1));
    }
    if (*(&D_800C4860_de + 1) < var_f0_4) {
        do {
            var_f0_4 -= D_800C4868_de;
        } while (*(&D_800C4860_de + 1) < var_f0_4);
    }
    if (-var_f0_4 < 0.0f) {
        if (var_f14 < D_800C486C_de) {
            do {
                var_f14 += D_800C4870_de;
            } while (var_f14 < D_800C486C_de);
        }
        if (D_800C4874_de < var_f14) {
            do {
                var_f14 -= D_800C4878_de;
            } while (D_800C4874_de < var_f14);
        }
        result = arg0 - var_f14;
        if (result < *(&D_800C4878_de + 1)) {
            do {
                result += D_800C4880_de;
            } while (result < *(&D_800C4878_de + 1));
        }
        if (*(&D_800C4880_de + 1) < result) {
            do {
                result -= D_800C4888_de;
            } while (*(&D_800C4880_de + 1) < result);
            return result;
        }
        return result;
    }
    if (var_f14 < D_800C488C_de) {
        do {
            var_f14 += D_800C4890_de;
        } while (var_f14 < D_800C488C_de);
    }
    if (D_800C4894_de < var_f14) {
        do {
            var_f14 -= D_800C4898_de;
        } while (D_800C4894_de < var_f14);
    }
    var_f0 = arg0 - var_f14;
    if (var_f0 < *(&D_800C4898_de + 1)) {
        do {
            var_f0 += D_800C48A0_de;
        } while (var_f0 < *(&D_800C4898_de + 1));
    }
    if (*(&D_800C48A0_de + 1) < var_f0) {
        do {
            var_f0 -= D_800C48A8_de;
        } while (*(&D_800C48A0_de + 1) < var_f0);
    }
    return -var_f0;
}

/** Component-wise multiply two 3-vectors. */
void func_80271F00_de(CVector3 *result, CVector3 *left, CVector3 *right) {
    result->x = left->x * right->x;
    result->y = left->y * right->y;
    result->z = left->z * right->z;
}

/** Add two three-component vectors. */
void func_80271F34_de(CVector3 *result, CVector3 *left, CVector3 *right) {
    result->x = left->x + right->x;
    result->y = left->y + right->y;
    result->z = left->z + right->z;
}

/** Subtract the right vector from the left vector. */
void func_80271F68_de(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2) {
    arg0->x = arg1->x - arg2->x;
    arg0->y = arg1->y - arg2->y;
    arg0->z = arg1->z - arg2->z;
}

/** Scale a 3-vector (arg1) by a scalar (arg2), store into arg0. */
void func_80271F9C_de(void *arg0, void *arg1, f32 arg2) {
    ((CVector3 *)(arg0))->x = ((CVector3 *)(arg1))->x * arg2;
    ((CVector3 *)(arg0))->y = ((CVector3 *)(arg1))->y * arg2;
    ((CVector3 *)(arg0))->z = ((CVector3 *)(arg1))->z * arg2;
}

/** Lerp a 3-component vector: out = a + t * (b - a). */
void func_80271FC8_de(CVector3 *arg0, f32 t, void *a, void *b) {
    arg0->x = ((CVector3 *)(a))->x + (t * (((CVector3 *)(b))->x - ((CVector3 *)(a))->x));
    arg0->y = ((CVector3 *)(a))->y + (t * (((CVector3 *)(b))->y - ((CVector3 *)(a))->y));
    arg0->z = ((CVector3 *)(a))->z + (t * (((CVector3 *)(b))->z - ((CVector3 *)(a))->z));
}

struct CVector3_t;

/** Cross product of two vectors, written directly to the output (no aliasing guard). */
void func_80272018_de(CVector3 *out, CVector3 *a, CVector3 *b) {
    out->x = (a->y * b->z) - (a->z * b->y);
    out->y = (a->z * b->x) - (a->x * b->z);
    out->z = (a->x * b->y) - (a->y * b->x);
}

void func_8027207C_de(f32 *arg0) {
    f32 mag;
    f32 scale;

    mag = func_802B72B0_de((arg0[0] * arg0[0]) + (arg0[1] * arg0[1]) + (arg0[2] * arg0[2]));
    if (mag != 0.0f) {
        scale = D_800C48AC_de / mag;
        arg0[0] = arg0[0] * scale;
        arg0[1] = arg0[1] * scale;
        arg0[2] = arg0[2] * scale;
    }
}

/** Intersect a line segment with a horizontal plane and write the point. */
void func_80272104_de(CVector3 *out, CVector3 *a, CVector3 *b, f32 y) {
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

void *func_80272180_de(CVector3 *arg0, CVector3 *remaining, CVector3 *arg2, f32 arg3) {
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

void *func_80272214_de(CVector3 *arg0, CVector3 *remaining, CVector3 *arg2) {
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
