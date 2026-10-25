#include "COMMON/S1_3.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "particle/80271B18_3.H"
#include "COMMON/POOLED_FLOATS.H"

extern f32 Math_Sqrtf(f32);

static __inline__ CVector3 project(CVector3 *arg0, CVector3 *arg1) {
    CVector3 projected;
    f32 dot;

    dot = (arg0->x * arg1->x) + (arg0->y * arg1->y) + (arg0->z * arg1->z);
    projected.x = arg0->x - (dot * arg1->x);
    projected.y = arg0->y - (dot * arg1->y);
    projected.z = arg0->z - (dot * arg1->z);
    return projected;
}

extern f32 Math_Sqrtf(f32 arg0);

CVector3 func_802723FC_de(CVector3 *remaining, CVector3 *arg1) {
    CVector3 projected;
    f32 projectedMagnitude;
    f32 magnitudeRatio;

    projected = project(remaining, arg1);

    projectedMagnitude = Math_Sqrtf((projected.x * projected.x) +
                                       (projected.y * projected.y) +
                                       (projected.z * projected.z));
    if (projectedMagnitude != 0.0f) {
        magnitudeRatio = Math_Sqrtf((remaining->x * remaining->x) +
                                       (remaining->y * remaining->y) +
                                       (remaining->z * remaining->z)) / projectedMagnitude;

        projected.x *= magnitudeRatio;
        projected.y *= magnitudeRatio;
        projected.z *= magnitudeRatio;
    }

    return projected;
}

s32 func_8027254C_de(f32 *arg0, f32 arg1) {
    f32 magSq;
    f32 mag;
    f32 scale;

    magSq = (arg0[0] * arg0[0]) + (arg0[1] * arg0[1]) + (arg0[2] * arg0[2]);
    if ((arg1 * arg1) < magSq) {
        mag = Math_Sqrtf(magSq);
        if (mag == 0.0f) {
            return 0;
        }
        scale = arg1 / mag;
        arg0[0] = arg0[0] * scale;
        arg0[1] = arg0[1] * scale;
        arg0[2] = arg0[2] * scale;
        return 1;
    }
    return 0;
}

void func_802725F4_de(void) {
}

f32 Particle_GetVerticalAngle(f32 *delta) {
    f32 y;
    f32 zero;
    f32 x;
    f32 z;
    f32 magnitude_squared;
    f32 ratio;

    y = delta[1];
    zero = 0.0f;
    x = delta[0];
    z = delta[2];
    if (y == zero) {
        return zero;
    }
    magnitude_squared = (x * x) + (y * y) + (z * z);
    if (magnitude_squared == zero) {
        return zero;
    }
    ratio = y / Math_Sqrtf(magnitude_squared);
    if (ratio < *(&D_800C48B0_de + 1)) {
        return zero;
    }
    if (D_800C48B8_de < ratio) {
        goto return_zero;
    }
    return Nav_ArcCos(ratio) - *(&D_800C48B8_de + 1);

return_zero:
    return zero;
}

f32 func_802726BC_de(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    return (dx * dx) + (dy * dy) + (dz * dz);
}

f32 Particle_GetPointDistance(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    return Math_Sqrtf((dx * dx) + (dy * dy) + (dz * dz));
}

void func_80272748_de(CVector3 *motion, f32 arg1) {
    f32 magSq;
    f32 mag;
    f32 scale;

    magSq = (motion->x * motion->x) + (motion->y * motion->y) + (motion->z * motion->z);
    if ((arg1 * arg1) < magSq) {
        mag = Math_Sqrtf(magSq);
        scale = arg1 / mag;
        motion->x = motion->x * scale;
        motion->y = motion->y * scale;
        motion->z = motion->z * scale;
    }
}

/** Reset the matrix to identity-diagonal * D_800C99B0, zeroing the rest. */
void func_802727D8_de(void *arg0) {
    Matrix *matrix = arg0;
    f32 zero = 0.0f;

    matrix->m[15] = D_800C99B0;
    matrix->m[10] = D_800C99B0;
    matrix->m[5] = D_800C99B0;
    matrix->m[0] = D_800C99B0;
    matrix->m[14] = zero;
    matrix->m[13] = zero;
    matrix->m[12] = zero;
    matrix->m[11] = zero;
    matrix->m[9] = zero;
    matrix->m[8] = zero;
    matrix->m[7] = zero;
    matrix->m[6] = zero;
    matrix->m[4] = zero;
    matrix->m[3] = zero;
    matrix->m[2] = zero;
    matrix->m[1] = zero;
}

void func_80272828_de(f32 *arg0) {
    f32 *var_a0;
    f32 *var_v1;
    f32 temp_f0;
    s32 i;
    s32 j;
    f32 maxVal;
    f32 minVal;

    maxVal = *(&D_800C99B0 + 1);
    minVal = D_800C48C8_de;
    var_a0 = arg0;
    j = 0;
    do {
        i = 0;
        var_v1 = var_a0;
        do {
            temp_f0 = *var_v1;
            if (maxVal < temp_f0) {
                *var_v1 = maxVal;
            } else if (temp_f0 < minVal) {
                *var_v1 = minVal;
            }
            i += 1;
            var_v1 += 1;
        } while (i < 4);
        j += 1;
        var_a0 += 4;
    } while (j < 4);
}

void Particle_TransformPoint(void *matrix, void *arg1, void *arg2) {
    Matrix *m = matrix;
    CVector3 *v = arg1;
    CVector3 *out = arg2;

    out->x = (m->m[0] * v->x)
           + (m->m[4] * v->y)
           + (m->m[8] * v->z)
           + m->m[12];
    out->y = (m->m[1] * v->x)
           + (m->m[5] * v->y)
           + (m->m[9] * v->z)
           + m->m[13];
    out->z = (m->m[2] * v->x)
           + (m->m[6] * v->y)
           + (m->m[10] * v->z)
           + m->m[14];
}

/* Transforms a count of points by the affine part of a 4x4 matrix, writing each transformed point to an output array. Adapted from func_8029F1A0_de with the input and output arguments swapped and the indexed loop replaced by a loop counting down an unsigned count while advancing an input and an output pointer. */
void func_80272944_de(f32 *m, f32 *in, f32 *out, u32 count) {
    f32 vx, vy, vz;

    while (count-- != 0) {
        vx = in[0];
        vy = in[1];
        vz = in[2];
        out[0] = (m[0] * vx) + (m[4] * vy) + (m[8] * vz) + m[12];
        out[1] = (m[1] * vx) + (m[5] * vy) + (m[9] * vz) + m[13];
        out[2] = (m[2] * vx) + (m[6] * vy) + (m[10] * vz) + m[14];
        in += 3;
        out += 3;
    }
}

void Particle_ProjectPoint(void *matrix, void *arg1, CVector3 *localDirection) {
    Matrix *m = matrix;
    CVector3 *v = arg1;
    f32 w;
    f32 scale;

    localDirection->x = (m->m[0] * v->x)
                       + (m->m[4] * v->y)
                       + (m->m[8] * v->z)
                       + m->m[12];
    localDirection->y = (m->m[1] * v->x)
                       + (m->m[5] * v->y)
                       + (m->m[9] * v->z)
                       + m->m[13];
    localDirection->z = (m->m[2] * v->x)
                       + (m->m[6] * v->y)
                       + (m->m[10] * v->z)
                       + m->m[14];
    w = (m->m[3] * v->x)
        + (m->m[7] * v->y)
        + (m->m[11] * v->z)
        + m->m[15];
    if (w != 0.0f) {
        scale = *(&D_800C48C8_de + 1) / w;
        localDirection->x = localDirection->x * scale;
        localDirection->y = localDirection->y * scale;
        localDirection->z = localDirection->z * scale;
    }
}

void func_80272B38_de(void *matrix, void *arg1, void *arg2) {
    Matrix *m = matrix;
    CVector3 *v = arg1;
    CVector3 *out = arg2;

    out->x = (m->m[0] * v->x)
                       + (m->m[4] * v->y)
                       + (m->m[8] * v->z);
    out->y = (m->m[1] * v->x)
                       + (m->m[5] * v->y)
                       + (m->m[9] * v->z);
    out->z = (m->m[2] * v->x)
                       + (m->m[6] * v->y)
                       + (m->m[10] * v->z);
}

void func_80272BCC_de(void *matrix, void *arg1, void *arg2) {
    Matrix *m = matrix;
    CVector3 *v = arg1;
    CVector3 *out = arg2;

    out->x = (m->m[0] * v->x)
                       + (m->m[1] * v->y)
                       + (m->m[2] * v->z);
    out->y = (m->m[4] * v->x)
                       + (m->m[5] * v->y)
                       + (m->m[6] * v->z);
    out->z = (m->m[8] * v->x)
                       + (m->m[9] * v->y)
                       + (m->m[10] * v->z);
}

void Particle_BuildTranslationMatrix(void *matrix, f32 arg1, f32 arg2, f32 arg3) {
    Matrix *o = matrix;
    f32 val = D_800C48D0_de;
    f32 zero = 0.0f;

    o->m[12] = arg1;
    o->m[13] = arg2;
    o->m[14] = arg3;
    o->m[15] = val;
    o->m[10] = val;
    o->m[5] = val;
    o->m[0] = val;
    o->m[11] = zero;
    o->m[9] = zero;
    o->m[8] = zero;
    o->m[7] = zero;
    o->m[6] = zero;
    o->m[4] = zero;
    o->m[3] = zero;
    o->m[2] = zero;
    o->m[1] = zero;
}

void func_80272CB0_de(void *matrix, f32 arg1, f32 arg2, f32 arg3) {
    Matrix *o = matrix;
    f32 val = *(&D_800C48D0_de + 1);
    f32 zero = 0.0f;

    o->m[0] = arg1;
    o->m[5] = arg2;
    o->m[10] = arg3;
    o->m[15] = val;
    o->m[14] = zero;
    o->m[13] = zero;
    o->m[12] = zero;
    o->m[11] = zero;
    o->m[9] = zero;
    o->m[8] = zero;
    o->m[7] = zero;
    o->m[6] = zero;
    o->m[4] = zero;
    o->m[3] = zero;
    o->m[2] = zero;
    o->m[1] = zero;
}

void func_80272D00_de(f32 (*mfThis)[4], f32 Theta, f32 X, f32 Y, f32 Z) {
    f32 sine;
    f32 cosine;
    f32 ab, bc, ca, t, one;

    sine = Math_Sinf(Theta);
    cosine = Math_Cosf(Theta);

    one = D_800C48D8_de;
    t = one - cosine;
    ab = X * Y * t;
    bc = Y * Z * t;
    ca = Z * X * t;

    mfThis[0][3] = mfThis[1][3] = mfThis[2][3] =
    mfThis[3][0] = mfThis[3][1] = mfThis[3][2] = 0.0f;
    mfThis[3][3] = one;

    t = X * X;
    X *= sine;
    mfThis[0][0] = t + cosine * (one - t);
    mfThis[2][1] = bc - X;
    mfThis[1][2] = bc + X;

    t = Y * Y;
    Y *= sine;
    mfThis[1][1] = t + cosine * (one - t);
    mfThis[2][0] = ca + Y;
    mfThis[0][2] = ca - Y;

    t = Z * Z;
    Z *= sine;
    mfThis[2][2] = t + cosine * (one - t);
    mfThis[1][0] = ab - Z;
    mfThis[0][1] = ab + Z;
}

void func_80272E3C_de(f32 *m, f32 x, f32 y, f32 z)
{
  f32 zero;
  f32 ax = Math_Sinf(x);
  f32 bx = Math_Cosf(x);
  f32 ay = Math_Sinf(y);
  f32 by = Math_Cosf(y);
  int new_var;
  f32 az = Math_Sinf(z);
  f32 bz = Math_Cosf(z);
  new_var = 0;
  m[new_var] = by * bz;
  m[1] = by * az;
  m[2] = -ay;
  zero = 0.0f;
  m[14] = zero;
  m[13] = zero;
  m[12] = zero;
  m[11] = zero;
  m[7] = zero;
  m[3] = zero;
  m[4] = ((ax * ay) * bz) - (bx * az);
  m[5] = ((ax * ay) * az) + (bx * bz);
  m[6] = ax * by;
  m[8] = ((bx * ay) * bz) + (ax * az);
  m[9] = ((bx * ay) * az) - (ax * bz);
  m[10] = bx * by;
  m[15] = D_800C48DC_de;
}

/** Trivial busy-wait delay loop (no side effects). */
void func_80272FA4_de(void) {
    s32 count;

    count = 3;
    do {
        count -= 1;
    } while (count >= 0);
}
