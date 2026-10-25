#include "include_asm.h"
#include "COMMON/MTX.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "GAME/CODE_8027302C.H"
#include "FX_2/80271B18.H"
#include "COMMON/POOLED_FLOATS.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/BALLISTICPARAMS.H"

/* Builds an orientation matrix whose third row is the given direction: the first row is the cross product of the up vector D_800C97B4 with it, or the X axis when the direction is within the vertical thresholds, the second row is the cross product of the first row with it, all three rows are normalised and the rest is identity. */





extern CVector3 D_800C46C0_de[2];

extern func_8020CA10_G1 D_800C48E8_de;

extern void Particle_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b);


extern f32 func_802B72B0_de(f32);

/* Copies a 4x4 float matrix while scaling its first three rows by three per-row factors, zeroing their fourth column and setting the last element to the canonical unit constant. Adapted from func_8027302C with the row scaling, the zeroed column and the constant corner changed. */
extern f32 D_800C48F4_de;

/* Expands a 4x4 transform into an affine 4x4 matrix with its second and third rows swapped, a zero last column and the pooled corner D_800C99F0[1]. */



/* Expands a 4x4 transform into an affine 4x4 matrix with its second and third columns swapped, a zero last column and the pooled corner D_800C99F8. Adapted from func_80273DA0_de with the row swap replaced by a column swap and the corner taken from D_800C99F8. */



extern f32 D_800C4928_de;

extern f32 D_800C492C_de;

void func_8027302C(float *arg0, float *arg1) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    arg0[3] = arg1[3];
    arg0[4] = arg1[4];
    arg0[5] = arg1[5];
    arg0[6] = arg1[6];
    arg0[7] = arg1[7];
    arg0[8] = arg1[8];
    arg0[9] = arg1[9];
    arg0[10] = arg1[10];
    arg0[11] = arg1[11];
    arg0[12] = arg1[12];
    arg0[13] = arg1[13];
    arg0[14] = arg1[14];
    arg0[15] = arg1[15];
}

void func_80273040_de(f32 *arg0, f32 *arg1) {
    char *a0;
    char *a2;
    char *v1;
    s32 col;
    s32 row;
    s32 coloff;
    f32 last;

    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    arg0[3] = arg1[3];
    arg0[4] = arg1[4];
    arg0[5] = arg1[5];
    arg0[6] = arg1[6];
    arg0[7] = arg1[7];
    arg0[8] = arg1[8];
    arg0[9] = arg1[9];
    arg0[10] = arg1[10];
    arg0[11] = arg1[11];
    arg0[12] = arg1[12];
    arg0[13] = arg1[13];
    arg0[14] = arg1[14];
    last = arg1[15];
    col = 0;
    arg0[15] = last;

    a0 = (char *)arg0;
    do {
        row = 0;
        coloff = col * 4;
        a2 = a0;
        v1 = (char *)arg1;
        do {
            *(f32 *)a2 = *(f32 *)(coloff + (s32)v1);
            v1 += 0x10;
            row += 1;
            a2 += 4;
        } while (row < 3);
        col += 1;
        a0 += 0x10;
    } while (col < 3);
}

void func_8027310C_de(void *projection, void *arg1, f32 plane) {
    CVector3 *direction = arg1;
    Matrix *o = projection;
    f32 zero = 0.0f;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;

    temp_f0 = D_800C48E0_de;
    o->m[15] = temp_f0;
    o->m[10] = temp_f0;
    o->m[0] = temp_f0;
    o->m[14] = zero;
    o->m[13] = zero;
    o->m[12] = zero;
    o->m[11] = zero;
    o->m[9] = zero;
    o->m[8] = zero;
    o->m[7] = zero;
    o->m[3] = zero;
    o->m[2] = zero;
    o->m[1] = zero;
    temp_f3 = temp_f0 / direction->y;
    temp_f2 = direction->x * temp_f3;
    temp_f1 = direction->z * temp_f3;
    o->m[13] = plane;
    o->m[5] = zero;
    o->m[4] = -temp_f2;
    o->m[6] = -temp_f1;
    o->m[12] = plane * temp_f2;
    o->m[14] = plane * temp_f1;
}

void func_80273198_de(Mtx *m, CVector3 *direction) {
    CVector3 up;
    CVector3 *upVector = (void *)&D_800C46C0_de[0].y;

    up = *upVector;
    if (direction->y < 0.0f ? (&D_800C48E0_de)[1] <= -direction->y : D_800C48E8_de.unk0 <= direction->y) {
        m->right.y = 0;
        m->right.z = 0;
        m->right.x = D_800C48EC_de;
    } else {
        Particle_CrossVectors(&m->right, &up, direction);
    }
    Particle_CrossVectors(&m->up, &m->right, direction);
    m->forward = *direction;
    func_8027207C_de(&m->right);
    func_8027207C_de(&m->up);
    func_8027207C_de(&m->forward);
    m->m03 = m->m13 = m->m23 = m->m30 = m->m31 = m->m32 = 0.0f;
    m->m33 = D_800C48F0_de;
}

/** Copy the three floating components at offset 0x30. */
void func_802732D0_de(char *object, float *output) {
    Matrix *matrix = (void *)object;
    output[0] = matrix->m[12];
    output[1] = matrix->m[13];
    output[2] = matrix->m[14];
}

void func_802732EC_de(void *matrix, f32 *arg1) {
    Matrix *m = matrix;
    CVector3 tmp;

    tmp.x = m->m[0];
    tmp.y = m->m[1];
    tmp.z = m->m[2];
    arg1[0] = func_802B72B0_de((tmp.x * tmp.x) + (tmp.y * tmp.y) + (tmp.z * tmp.z));

    tmp.x = m->m[4];
    tmp.y = m->m[5];
    tmp.z = m->m[6];
    arg1[1] = func_802B72B0_de((tmp.x * tmp.x) + (tmp.y * tmp.y) + (tmp.z * tmp.z));

    tmp.x = m->m[8];
    tmp.y = m->m[9];
    tmp.z = m->m[10];
    arg1[2] = func_802B72B0_de((tmp.x * tmp.x) + (tmp.y * tmp.y) + (tmp.z * tmp.z));
}

void func_802733B4_de(void *matrix, f32 tiltX, f32 lift, f32 arg3) {
    Matrix *o = matrix;

    o->m[12] = o->m[12] + (tiltX * o->m[0] + lift * o->m[4] + arg3 * o->m[8]);
    o->m[13] = o->m[13] + (tiltX * o->m[1] + lift * o->m[5] + arg3 * o->m[9]);
    o->m[14] = o->m[14] + (tiltX * o->m[2] + lift * o->m[6] + arg3 * o->m[10]);
}

/** Add three floating arguments to the vector at offset 0x30. */
void func_80273448_de(char *object, float x, float y, float z) {
    Matrix *matrix = (void *)object;
    matrix->m[12] += x;
    matrix->m[13] += y;
    matrix->m[14] += z;
}

/** Scale the first three rows of a matrix's basis columns by sx, sy, sz. */
void func_8027347C_de(void *matrix, f32 sx, f32 sy, f32 sz) {
    Matrix *o = matrix;

    o->m[0] = o->m[0] * sx;
    o->m[1] = o->m[1] * sx;
    o->m[2] = o->m[2] * sx;
    o->m[4] = o->m[4] * sy;
    o->m[5] = o->m[5] * sy;
    o->m[6] = o->m[6] * sy;
    o->m[8] = o->m[8] * sz;
    o->m[9] = o->m[9] * sz;
    o->m[10] = o->m[10] * sz;
}

void func_802734F8_de(f32 *arg0, f32 *arg1, f32 sx, f32 sy, f32 sz) {
    arg0[0] = arg1[0] * sx;
    arg0[1] = arg1[1] * sx;
    arg0[2] = arg1[2] * sx;
    arg0[4] = arg1[4] * sy;
    arg0[5] = arg1[5] * sy;
    arg0[6] = arg1[6] * sy;
    arg0[8] = arg1[8] * sz;
    arg0[9] = arg1[9] * sz;
    arg0[10] = arg1[10] * sz;
    arg0[12] = arg1[12];
    arg0[13] = arg1[13];
    arg0[14] = arg1[14];
    arg0[3] = arg0[7] = arg0[11] = 0.0f;
    arg0[15] = D_800C48F4_de;
}

/** Scale the xyz columns of a 4-row matrix by sx, sy, sz. */
void func_802735A8_de(void *matrix, f32 sx, f32 sy, f32 sz) {
    Matrix *o = matrix;

    o->m[0] = o->m[0] * sx;
    o->m[4] = o->m[4] * sx;
    o->m[8] = o->m[8] * sx;
    o->m[12] = o->m[12] * sx;
    o->m[1] = o->m[1] * sy;
    o->m[5] = o->m[5] * sy;
    o->m[9] = o->m[9] * sy;
    o->m[13] = o->m[13] * sy;
    o->m[2] = o->m[2] * sz;
    o->m[6] = o->m[6] * sz;
    o->m[10] = o->m[10] * sz;
    o->m[14] = o->m[14] * sz;
}

void func_80273648_de(void *rest, f32 arg1) {
    struct Mtx *m = rest;
    f32 sin_v;
    f32 cos_v;
    f32 zero;
    f32 identity;

    sin_v = func_802B7130_de(arg1);
    zero = 0;
    identity = D_800C48F8_de[0];
    m->forward.y = -sin_v;
    m->up.z = sin_v;
    m->right.y = zero;
    m->up.x = zero;
    m->right.z = zero;
    m->forward.x = zero;
    m->m32 = zero;
    m->m31 = zero;
    m->m30 = zero;
    m->m23 = zero;
    m->m13 = zero;
    m->m03 = zero;
    m->m33 = identity;
    m->right.x = identity;
    cos_v = func_802B6560_de(arg1);
    m->forward.z = cos_v;
    m->up.y = cos_v;
}

void func_802736D4_de(void *arg0, f32 arg1)
{
  struct Mtx *m = (char *) arg0;
  f32 sin_v;
  f32 cos_v;
  f32 zero;
  f32 identity;
  zero = 0;
  sin_v = func_802B7130_de(arg1);
  identity = D_800C48F8_de[1];
  m->forward.x = sin_v;
  m->right.y = zero;
  m->right.z = -sin_v;
  m->up.x = zero;
  m->up.z = zero;
  m->forward.y = zero;
  m->m32 = zero;
  m->m31 = zero;
  m->m30 = zero;
  m->m23 = zero;
  m->m13 = zero;
  m->m03 = zero;
  m->m33 = identity;
  m->up.y = identity;
  cos_v = func_802B6560_de(arg1);
  m->forward.z = cos_v;
  m->right.x = cos_v;
}

void func_80273760_de(void *matrix, f32 arg1) {
    struct Mtx *m = matrix;
    f32 sin_v;
    f32 cos_v;
    f32 zero;
    f32 one;

    sin_v = func_802B7130_de(arg1);
    zero = (f32) 0;
    one = D_800C99F0[0];
    m->right.z = zero;
    m->forward.x = zero;
    m->up.z = zero;
    m->forward.y = zero;
    m->m32 = zero;
    m->m31 = zero;
    m->m30 = zero;
    m->m23 = zero;
    m->m13 = zero;
    m->m03 = zero;
    m->forward.z = one;
    m->m33 = one;
    cos_v = func_802B6560_de(arg1);
    m->up.y = cos_v;
    m->right.x = cos_v;
    m->up.x = -sin_v;
    m->right.y = sin_v;
}

void func_802737F0_de(void *arg0, f32 arg1) {
    struct Mtx *m = (char *) arg0;
    f32 sin_v;
    f32 cos_v;
    f32 neg_sin;
    f32 a;

    sin_v = func_802B7130_de(arg1);
    cos_v = func_802B6560_de(arg1);
    neg_sin = -sin_v;

    a = m->up.x;
    m->up.x = (cos_v * a) + (sin_v * m->forward.x);
    m->forward.x = (neg_sin * a) + (cos_v * m->forward.x);

    a = m->up.y;
    m->up.y = (cos_v * a) + (sin_v * m->forward.y);
    m->forward.y = (neg_sin * a) + (cos_v * m->forward.y);

    a = m->up.z;
    m->up.z = (cos_v * a) + (sin_v * m->forward.z);
    m->forward.z = (neg_sin * a) + (cos_v * m->forward.z);
}

void func_802738C0_de(void *arg0, f32 arg1) {
    struct Mtx *m = (char *) arg0;
    f32 sin_v;
    f32 cos_v;
    f32 neg_sin;
    f32 a;

    sin_v = func_802B7130_de(arg1);
    cos_v = func_802B6560_de(arg1);
    neg_sin = -sin_v;

    a = m->right.y;
    m->right.y = (a * cos_v) + (m->right.z * neg_sin);
    m->right.z = (a * sin_v) + (m->right.z * cos_v);

    a = m->up.y;
    m->up.y = (a * cos_v) + (m->up.z * neg_sin);
    m->up.z = (a * sin_v) + (m->up.z * cos_v);

    a = m->forward.y;
    m->forward.y = (a * cos_v) + (m->forward.z * neg_sin);
    m->forward.z = (a * sin_v) + (m->forward.z * cos_v);

    a = m->m31;
    m->m31 = (a * cos_v) + (m->m32 * neg_sin);
    m->m32 = (a * sin_v) + (m->m32 * cos_v);
}

void func_802739C4_de(void *matrix, f32 arg1) {
    struct Mtx *m = (char *) matrix;
    f32 sin_v;
    f32 cos_v;
    f32 neg_sin;
    f32 a;

    sin_v = func_802B7130_de(arg1);
    cos_v = func_802B6560_de(arg1);
    neg_sin = -sin_v;

    a = m->right.x;
    m->right.x = (cos_v * a) + (neg_sin * m->forward.x);
    m->forward.x = (sin_v * a) + (cos_v * m->forward.x);

    a = m->right.y;
    m->right.y = (cos_v * a) + (neg_sin * m->forward.y);
    m->forward.y = (sin_v * a) + (cos_v * m->forward.y);

    a = m->right.z;
    m->right.z = (cos_v * a) + (neg_sin * m->forward.z);
    m->forward.z = (sin_v * a) + (cos_v * m->forward.z);
}

void func_80273A98_de(void *matrix, f32 arg1) {
    struct Mtx *m = (char *) matrix;
    f32 sin_v;
    f32 cos_v;
    f32 neg_sin;
    f32 a;

    sin_v = func_802B7130_de(arg1);
    cos_v = func_802B6560_de(arg1);
    neg_sin = -sin_v;

    a = m->right.x;
    m->right.x = (a * cos_v) + (m->right.z * sin_v);
    m->right.z = (a * neg_sin) + (m->right.z * cos_v);

    a = m->up.x;
    m->up.x = (a * cos_v) + (m->up.z * sin_v);
    m->up.z = (a * neg_sin) + (m->up.z * cos_v);

    a = m->forward.x;
    m->forward.x = (a * cos_v) + (m->forward.z * sin_v);
    m->forward.z = (a * neg_sin) + (m->forward.z * cos_v);

    a = m->m30;
    m->m30 = (a * cos_v) + (m->m32 * sin_v);
    m->m32 = (a * neg_sin) + (m->m32 * cos_v);
}

void func_80273B98_de(void *matrix, f32 arg1) {
    struct Mtx *m = (char *) matrix;
    f32 sin_v;
    f32 cos_v;
    f32 neg_sin;
    f32 a;

    sin_v = func_802B7130_de(arg1);
    cos_v = func_802B6560_de(arg1);
    neg_sin = -sin_v;

    a = m->right.x;
    m->right.x = (cos_v * a) + (sin_v * m->up.x);
    m->up.x = (neg_sin * a) + (cos_v * m->up.x);

    a = m->right.y;
    m->right.y = (cos_v * a) + (sin_v * m->up.y);
    m->up.y = (neg_sin * a) + (cos_v * m->up.y);

    a = m->right.z;
    m->right.z = (cos_v * a) + (sin_v * m->up.z);
    m->up.z = (neg_sin * a) + (cos_v * m->up.z);
}

void func_80273C68_de(void *arg0, f32 arg1) {
    struct Mtx *m = (char *) arg0;
    f32 sin_v;
    f32 cos_v;
    f32 neg_sin;
    f32 a;

    sin_v = func_802B7130_de(arg1);
    cos_v = func_802B6560_de(arg1);
    neg_sin = -sin_v;

    a = m->right.x;
    m->right.x = (a * cos_v) + (m->right.y * neg_sin);
    m->right.y = (a * sin_v) + (m->right.y * cos_v);

    a = m->up.x;
    m->up.x = (a * cos_v) + (m->up.y * neg_sin);
    m->up.y = (a * sin_v) + (m->up.y * cos_v);

    a = m->forward.x;
    m->forward.x = (a * cos_v) + (m->forward.y * neg_sin);
    m->forward.y = (a * sin_v) + (m->forward.y * cos_v);

    a = m->m30;
    m->m30 = (a * cos_v) + (m->m31 * neg_sin);
    m->m31 = (a * sin_v) + (m->m31 * cos_v);
}

/** Swap the two float-groups at offsets 0x10 and 0x20 (three floats each). */
void func_80273D6C_de(struct Mtx *object) {
    float t;
    t = object->up.x;
    object->up.x = object->forward.x;
    object->forward.x = t;

    t = object->up.y;
    object->up.y = object->forward.y;
    object->forward.y = t;

    t = object->up.z;
    object->up.z = object->forward.z;
    object->forward.z = t;
}

void func_80273DA0_de(f32 *dst, f32 *src) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[4] = src[8];
    dst[5] = src[9];
    dst[6] = src[10];
    dst[8] = src[4];
    dst[9] = src[5];
    dst[10] = src[6];
    dst[12] = src[12];
    dst[13] = src[13];
    dst[14] = src[14];
    dst[3] = dst[7] = dst[11] = 0.0f;
    dst[15] = D_800C99F0[1];
}

/** Swap the two floats within each of the object's four 0x10-byte records. */
void func_80273E20_de(struct Mtx *object) {
    float t;
    t = object->right.y;
    object->right.y = object->right.z;
    object->right.z = t;

    t = object->up.y;
    object->up.y = object->up.z;
    object->up.z = t;

    t = object->forward.y;
    object->forward.y = object->forward.z;
    object->forward.z = t;

    t = object->m31;
    object->m31 = object->m32;
    object->m32 = t;
}

void func_80273E64_de(f32 *dst, f32 *src) {
    dst[0] = src[0];
    dst[1] = src[2];
    dst[2] = src[1];
    dst[4] = src[4];
    dst[5] = src[6];
    dst[6] = src[5];
    dst[8] = src[8];
    dst[9] = src[10];
    dst[10] = src[9];
    dst[12] = src[12];
    dst[13] = src[14];
    dst[14] = src[13];
    dst[3] = dst[7] = dst[11] = 0.0f;
    dst[15] = D_800C99F8[0];
}

f32 func_80273EE4_de(f32 fraction, f32 first, f32 second) {
    f32 var_f3;
    f32 result;

    func_80274020_de(&first);
    func_80274020_de(&second);
    if (first > second) {
        var_f3 = second + D_800C99F8[1];
        if ((var_f3 - first) < (first - second)) {
            second = var_f3;
        }
    } else {
        var_f3 = second - D_800C4910_de;
        if ((first - var_f3) < (second - first)) {
            second = var_f3;
        }
    }
    result = first + (fraction * (second - first));
    func_80274020_de(&result);
    return result;
}

f32 func_80273F94_de(f32 arg0, f32 arg1) {
    f32 var_f3;

    func_80274020_de(&arg0);
    func_80274020_de(&arg1);
    if (arg0 > arg1) {
        var_f3 = arg1 + D_800C4914_de;
        if ((var_f3 - arg0) < (arg0 - arg1)) {
            arg1 = var_f3;
        }
    } else {
        var_f3 = arg1 - D_800C4918_de[0];
        if ((arg0 - var_f3) < (arg1 - arg0)) {
            arg1 = var_f3;
        }
    }
    return arg0 - arg1;
}

void func_80274020_de(f32 *value)
{
    {
        f32 val;
        f32 limit;
        f32 step;

        val = *value;
        limit = D_800C4918_de[1];
        if (val < limit) {
            step = D_800C4920_de;
            do {
                val += step;
                *value = val;
            } while (val < limit);
        }
    }
    {
        f32 val;
        f32 limit;
        f32 step;

        val = *value;
        limit = *(&D_800C4920_de + 1);
        if (limit <= val) {
            step = D_800C4928_de;
            do {
                val -= step;
                *value = val;
            } while (limit <= val);
        }
    }
}

void func_80274098_de(void *arg0, void *arg1, void *arg2) {
    f32 *out = (f32 *)arg0;
    f32 *a = (f32 *)arg1;
    f32 *b = (f32 *)arg2;

    out[0] = ((b[3] * a[0]) - (b[2] * a[1]))
             + (b[1] * a[2]) + (b[0] * a[3]);
    out[1] = ((b[2] * a[0]) + (b[3] * a[1]))
             - (b[0] * a[2]) + (b[1] * a[3]);
    out[2] = (-b[1] * a[0]) + (b[0] * a[1])
             + (b[3] * a[2]) + (b[2] * a[3]);
    out[3] = ((-b[0] * a[0]) - (b[1] * a[1]))
             - (b[2] * a[2]) + (b[3] * a[3]);
}

void func_802741A4_de(f32 *rotation) {
    f32 mag;
    f32 scale;

    mag = func_802B72B0_de((rotation[0] * rotation[0]) + (rotation[1] * rotation[1]) + (rotation[2] * rotation[2]) + (rotation[3] * rotation[3]));
    if (mag != 0.0f) {
        scale = D_800C492C_de / mag;
        rotation[0] = rotation[0] * scale;
        rotation[1] = rotation[1] * scale;
        rotation[2] = rotation[2] * scale;
        rotation[3] = rotation[3] * scale;
    }
}

/* Builds a rotation matrix from a quaternion with zero translation and a unit homogeneous corner. */


void func_80274244_de(f32 *q, f32 *m)
{
  f32 x = q[0];
  f32 xx = x * x;
  f32 y = q[1];
  f32 yy = y * y;
  f32 z = q[2];
  f32 zz = z * z;
  f32 w = q[3];
  f32 ww = w * w;
  f32 x2 = x + x;
  f32 xy = x2 * y;
  f32 w2 = w + w;
  f32 wz = w2 * z;
  f32 xz = x2 * z;
  f32 wy = w2 * y;
  f32 yz = (y + y) * z;
  f32 r0 = ((ww + xx) - yy) - zz;
  f32 r1 = xy + wz;
  f32 r2 = xz - wy;
  f32 r4 = xy - wz;
  f32 r5 = ((ww - xx) + yy) - zz;
  f32 r6 = yz + (w2 * x);
  f32 r8 = xz + wy;
  f32 r9 = yz - (w2 * x);
  f32 r10 = ((ww - xx) - yy) + zz;
  m[3] = 0.0f;
  m[7] = 0.0f;
  m[11] = 0.0f;
  m[12] = 0.0f;
  m[13] = 0.0f;
  m[14] = 0.0f;
  m[15] = D_800C4930_de;
  m[0] = r0;
  m[1] = r1;
  m[2] = r2;
  m[4] = r4;
  m[5] = r5;
  m[6] = r6;
  m[8] = r8;
  m[9] = r9;
  m[10] = r10;
}

/** Lerp a 4-component vector: out = a + t * (b - a). */
void func_80274318_de(void *cQuatern, f32 t, void *a, void *b) {
    CQuatern *out = cQuatern;
    CQuatern *left = a;
    CQuatern *right = b;

    out->x = left->x + (t * (right->x - left->x));
    out->y = left->y + (t * (right->y - left->y));
    out->z = left->z + (t * (right->z - left->z));
    out->w = left->w + (t * (right->w - left->w));
}

void func_80274380_de(CQuatern *rotation, CQuatern *target) {
    CQuatern result;
    f32 angle;
    f32 blend;
    f32 t;

    angle = func_802745D0_de((rotation->x * target->x) + (rotation->y * target->y) + (rotation->z * target->z) + (rotation->w * target->w));
    if (angle != 0.0f) {
        t = 1.0f - ((angle - (((angle * 0.1388889f) + 1.7453293e-4f) * D_800D2988)) / angle);
        if ((1.0f < t) || !(t < 0.0f)) {
            blend = 1.0f;
            if (!(blend < t)) {
                blend = t;
            }
        } else {
            blend = 0.0f;
        }
        func_80270CD0_de(&result, blend, rotation, target);
        *rotation = result;
    }
}
