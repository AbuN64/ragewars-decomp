#include "span_1000/code_80271B18.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "types.h"

extern f32 func_802B72B0_de(f32);

extern f32 D_800C48AC_de;

f32 func_80271C54_de(f32 arg0, f32 arg1) {
    extern f32 D_800C48A8_de;
    f32 var_f0;
    f32 var_f0_2;
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
        var_f0_2 = arg0 - var_f14;
        if (var_f0_2 < *(&D_800C4878_de + 1)) {
            do {
                var_f0_2 += D_800C4880_de;
            } while (var_f0_2 < *(&D_800C4878_de + 1));
        }
        if (*(&D_800C4880_de + 1) < var_f0_2) {
            do {
                var_f0_2 -= D_800C4888_de;
            } while (*(&D_800C4880_de + 1) < var_f0_2);
            return var_f0_2;
        }
        return var_f0_2;
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
void func_80271F00_de(Vec3 *result, Vec3 *left, Vec3 *right) {
    result->x = left->x * right->x;
    result->y = left->y * right->y;
    result->z = left->z * right->z;
}

/** Add two three-component vectors. */
void func_80271F34_de(Vec3 *result, Vec3 *left, Vec3 *right) {
    result->x = left->x + right->x;
    result->y = left->y + right->y;
    result->z = left->z + right->z;
}

/** Subtract the right vector from the left vector. */
void func_80271F68_de(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2) {
    arg0->x = arg1->x - arg2->x;
    arg0->y = arg1->y - arg2->y;
    arg0->z = arg1->z - arg2->z;
}

/** Scale a 3-vector (arg1) by a scalar (arg2), store into arg0. */
void func_80271F9C_de(void *arg0, void *arg1, f32 arg2) {
    ((Vec3 *)(arg0))->x = ((Vec3 *)(arg1))->x * arg2;
    ((Vec3 *)(arg0))->y = ((Vec3 *)(arg1))->y * arg2;
    ((Vec3 *)(arg0))->z = ((Vec3 *)(arg1))->z * arg2;
}

/** Lerp a 3-component vector: out = a + t * (b - a). */
void func_80271FC8_de(void *arg0, f32 t, void *a, void *b) {
    ((Vec3 *)(arg0))->x = ((Vec3 *)(a))->x + (t * (((Vec3 *)(b))->x - ((Vec3 *)(a))->x));
    ((Vec3 *)(arg0))->y = ((Vec3 *)(a))->y + (t * (((Vec3 *)(b))->y - ((Vec3 *)(a))->y));
    ((Vec3 *)(arg0))->z = ((Vec3 *)(a))->z + (t * (((Vec3 *)(b))->z - ((Vec3 *)(a))->z));
}

struct Vec3;

/** Cross product of two vectors, written directly to the output (no aliasing guard). */
void func_80272018_de(Vec3 *out, Vec3 *a, Vec3 *b) {
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
void func_80272104_de(Vec3 *out, Vec3 *a, Vec3 *b, f32 y) {
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

void *func_80272180_de(void *arg0, void *arg1, void *arg2, f32 arg3) {
    Vec3 tmp;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;

    temp_f5 = ((Vec3 *)arg1)->x;
    temp_f4 = ((Vec3 *)arg2)->x;
    temp_f3 = (temp_f5 * temp_f4) + (((Vec3 *)arg1)->y * ((Vec3 *)arg2)->y) + (((Vec3 *)arg1)->z * ((Vec3 *)arg2)->z);
    temp_f2 = (arg3 * temp_f3) + temp_f3;
    tmp.x = temp_f5 - (temp_f2 * temp_f4);
    tmp.y = ((Vec3 *)arg1)->y - (temp_f2 * ((Vec3 *)arg2)->y);
    tmp.z = ((Vec3 *)arg1)->z - (temp_f2 * ((Vec3 *)arg2)->z);
    *(Vec3 *)arg0 = tmp;
    return arg0;
}

void *func_80272214_de(void *arg0, void *arg1, void *arg2) {
    Vec3 tmp;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f5;

    temp_f5 = ((Vec3 *)arg1)->x;
    temp_f4 = ((Vec3 *)arg2)->x;
    temp_f2 = (temp_f5 * temp_f4) + (((Vec3 *)arg1)->y * ((Vec3 *)arg2)->y) + (((Vec3 *)arg1)->z * ((Vec3 *)arg2)->z);
    tmp.x = temp_f5 - (temp_f2 * temp_f4);
    tmp.y = ((Vec3 *)arg1)->y - (temp_f2 * ((Vec3 *)arg2)->y);
    tmp.z = ((Vec3 *)arg1)->z - (temp_f2 * ((Vec3 *)arg2)->z);
    *(Vec3 *)arg0 = tmp;
    return arg0;
}
