#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "MATH/8029BBA0.H"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/TRIPLE.H"
#include "MATH/8029BBA0_4.H"

/* The values func_8029C984_de loads by address:
 * 0x800CAC34 = 1.0 (float, D_800CAC34 in this cartridge's tables)
 */

/* Build a rotation matrix from the three Euler angles in arg1. */
void func_8029C984_de(ObjRecAt3CV2 *arg0, CVector3 *arg1) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
    f32 p0;
    f32 p1;
    f32 p2;
    f32 p3;
    f32 p4;
    f32 p5;
    f32 p6;
    f32 p7;
    f32 p8;
    float temp;
    f32 p9;
    f32 p10;
    f32 p11;
    float temp_2;
    f32 p12;
    f32 p13;
    func_8029BBB0_de(arg1->x, &sp10, &sp14);
    func_8029BBB0_de(arg1->y, &sp18, &sp1C);
    func_8029BBB0_de(arg1->z, &sp20, &sp24);
    p0 = sp10 * sp20;
    p1 = sp10 * sp24;
    temp_2 = sp18 * p0;
    p2 = sp1C * sp24;
    p3 = sp20 * sp1C;
    p4 = sp14 * sp18;
    temp = sp18 * p1;
    p5 = sp14 * sp20;
    p6 = sp14 * sp24;
    p7 = sp18 * sp24;
    p8 = sp14 * sp1C;
    p9 = temp_2;
    p10 = temp;
    p11 = sp1C * p0;
    p12 = sp18 * sp20;
    p13 = sp1C * sp20;
    arg0->unk24 = -sp10;
    arg0->unk20 = p4;
    arg0->unk4 = p5;
    arg0->unk14 = p6;
    arg0->unkC = arg0->unk1C = arg0->unk2C = arg0->unk30 = arg0->unk34 = arg0->unk38 = 0.0f;
    arg0->unk28 = p8;
    arg0->unk3C = D_800CAC34;
    arg0->unk0 = p2 + p9;
    arg0->unk10 = p10 - p3;
    arg0->unk8 = p11 - p7;
    arg0->unk18 = p12 + p1 * sp1C;
}


void func_8029CAB4_de(InputRecAt28 *arg0, CVector3 *arg1) {
    f32 clamped;
    f32 magnitude;
    f32 polynomial;
    f32 root;
    f32 delta;
    f32 test;
    f32 angle;
    f32 angle_temp;
    f32 out2;
    s32 negative;
    clamped = arg0->f24;
    if (D_800C5AA8_de < clamped) {
        clamped = D_800C5AA8_de;
    }
    if (clamped < *(&D_800C5AA8_de + 1)) {
        clamped = *(&D_800C5AA8_de + 1);
    }
    magnitude = -clamped;
    if (D_800C5AA8_de < magnitude) {
        magnitude = D_800C5AA8_de;
    }
    if (magnitude < *(&D_800C5AA8_de + 1)) {
        magnitude = *(&D_800C5AA8_de + 1);
    }
    negative = 0;
    if (magnitude < 0.0f) {
        negative = 1;
        magnitude = -magnitude;
    }
    polynomial = (((((((((magnitude * D_800C5AB0_de) + *(&D_800C5AB0_de + 1)) * magnitude)
        - D_800C5AB8_de) * magnitude) + *(&D_800C5AB8_de + 1)) * magnitude)
        - D_800C5AC0_de) * magnitude) + *(&D_800C5AC0_de + 1);
    delta = D_800C5AA8_de - magnitude;
    if (delta <= 0.0f) {
        root = 0.0f;
    } else {
        root = func_802B72B0_de(delta);
    }
    angle_temp = D_800C5AC8_de - (root * polynomial);
    if (negative != 0) {
        angle_temp = -angle_temp;
    }
    angle = angle_temp;
    test = func_8029B9FC_de(angle + D_800C5AC8_de);
    if ((*(&D_800C5AC8_de + 1) < test) || (test < *(&D_800C5AC8_de + 1))) {
        polynomial = func_8029C044_de(arg0->f20, arg0->f28);
        out2 = func_8029C044_de(arg0->f04, arg0->f14);
    } else {
        polynomial = 0.0f;
        out2 = func_8029C044_de(arg0->f08, arg0->f00);
    }
    arg1->x = angle;
    arg1->y = polynomial;
    arg1->z = out2;
}
/* Computes an arcsine-style angle from a clamped matrix element by polynomial approximation, then derives the other two Euler angles with atan2-style calls and writes the triple. Adapted from func_8029CAB4_de, with the source element, the zero test, the branch operands, and the stored order changed. */


void func_8029CC70_de(InputRecAt28 *arg0, CVector3 *arg1) {
    f32 clamped;
    f32 magnitude;
    f32 polynomial;
    f32 root;
    f32 delta;
    f32 test;
    f32 angle;
    f32 angle_temp;
    f32 out2;
    s32 negative;
    clamped = arg0->f08;
    if (D_800C5AD0_de < clamped) {
        clamped = D_800C5AD0_de;
    }
    if (clamped < *(&D_800C5AD0_de + 1)) {
        clamped = *(&D_800C5AD0_de + 1);
    }
    magnitude = -clamped;
    if (D_800C5AD0_de < magnitude) {
        magnitude = D_800C5AD0_de;
    }
    if (magnitude < *(&D_800C5AD0_de + 1)) {
        magnitude = *(&D_800C5AD0_de + 1);
    }
    negative = 0;
    if (magnitude < 0.0f) {
        negative = 1;
        magnitude = -magnitude;
    }
    polynomial = (((((((((magnitude * D_800C5AD8_de) + *(&D_800C5AD8_de + 1)) * magnitude)
        - D_800C5AE0_de) * magnitude) + *(&D_800C5AE0_de + 1)) * magnitude)
        - D_800C5AE8_de) * magnitude) + *(&D_800C5AE8_de + 1);
    delta = D_800C5AD0_de - magnitude;
    if (delta <= 0.0f) {
        root = 0.0f;
    } else {
        root = func_802B72B0_de(delta);
    }
    angle_temp = D_800C5AF0_de - (root * polynomial);
    if (negative != 0) {
        angle_temp = -angle_temp;
    }
    angle = angle_temp;
    test = func_8029B9FC_de(angle + D_800C5AF0_de);
    if ((0.0f < test) || (test < 0.0f)) {
        polynomial = func_8029C044_de(arg0->pad18, arg0->f28);
        out2 = func_8029C044_de(arg0->f04, arg0->f00);
    } else {
        polynomial = func_8029C044_de(-arg0->f24, arg0->f14);
        out2 = 0.0f;
    }
    arg1->x = polynomial;
    arg1->y = angle;
    arg1->z = out2;
}

void func_8029CE3C_de(s32 arg0, s32 arg1, s32 arg2) {
    Matrix temporary;
    Matrix *out = (Matrix *)arg0;
    Matrix *a = (Matrix *)arg1;
    Matrix *b = (Matrix *)arg2;
    s32 row;

    if (out == a) {
        temporary = *a;
        if (a == b) {
            b = &temporary;
        }
        a = &temporary;
    } else if (out == b) {
        temporary = *b;
        b = &temporary;
    }

    {
        f32 *destination = out->m;
        f32 *left = a->m;
        f32 *right = b->m;
        row = 0;
        do {
            destination[0] = left[0] * right[0] +
                left[4] * right[1] +
                left[8] * right[2] +
                left[12] * right[3];
            destination[1] = left[1] * right[0] +
                left[5] * right[1] +
                left[9] * right[2] +
                left[13] * right[3];
            destination[2] = left[2] * right[0] +
                left[6] * right[1] +
                left[10] * right[2] +
                left[14] * right[3];
            destination[3] = left[3] * right[0] +
                left[7] * right[1] +
                left[11] * right[2] +
                left[15] * right[3];
            destination += 4;
            right += 4;
        } while (++row < 4);
    }
}

/* Re-orthonormalises the rotation rows of a matrix: normalises the first and second rows (a zero length is left to divide by zero), rebuilds the third row as their cross product and the second as the cross product of the third and first, and writes the three rows back. */






static inline f32 safe_sqrt(f32 x) {
    if (x <= 0.0f) {
        return 0.0f;
    }
    return func_802B72B0_de(x);
}

static inline void normalize_x(CVector3 *v) {
    f32 scale;

    scale = D_800C5AF4 / safe_sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
    v->x *= scale;
    v->y *= scale;
    v->z *= scale;
}

static inline void normalize_y(CVector3 *v) {
    f32 scale;

    scale = D_800C5AF8_de / safe_sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
    v->x *= scale;
    v->y *= scale;
    v->z *= scale;
}

static inline CVector3 cross(CVector3 *a, CVector3 *b) {
    CVector3 r;

    r.x = a->y * b->z - a->z * b->y;
    r.y = a->z * b->x - a->x * b->z;
    r.z = a->x * b->y - a->y * b->x;
    return r;
}

void func_8029D000_de(PlaneEquation *m) {
    CVector3 x;
    CVector3 y;
    CVector3 z;

    x.x = m[0].normal.x;
    x.y = m[0].normal.y;
    x.z = m[0].normal.z;
    y.x = m[1].normal.x;
    y.y = m[1].normal.y;
    y.z = m[1].normal.z;
    normalize_x(&x);
    normalize_y(&y);
    z = cross(&x, &y);
    y = cross(&z, &x);
    {
        CVector3 *p = &x;

        m[0].normal.x = p->x;
        m[0].normal.y = p->y;
        m[0].normal.z = p->z;
    }
    m[1].normal.x = y.x;
    m[1].normal.y = y.y;
    m[1].normal.z = y.z;
    m[2].normal.x = z.x;
    m[2].normal.y = z.y;
    m[2].normal.z = z.z;
}

s32 func_8029D248_de(f32 *out, f32 *input)
{
  struct Shape_typemap_165 copy[4];
  f32 *m;
  f32 determinant;
  f32 absoluteDeterminant;
  f32 reciprocal;
  f32 negativeReciprocal;
  f32 m5;
  f32 m10;
  f32 m6;
  f32 m9;
  f32 m4;
  f32 m8;
  f32 minor0;
  f32 affineOne;
  s32 result;
  m = input;
  if (input == out)
  {
    struct Shape_typemap_165 *dst = copy;
    struct Shape_typemap_165 *src = (struct Shape_typemap_165 *) out;
    struct Shape_typemap_165 *end = src + 4;
    do
    {
      *dst = *src;
      src++;
      dst++;
    }
    while (src != end);
    m = (f32 *) copy;
  }
  m5 = m[5];
  m10 = m[10];
  m6 = m[6];
  m9 = m[9];
  minor0 = (m5 * m10) - (m6 * m9);
  m4 = m[4];
  m8 = m[8];
  determinant = ((m[0] * minor0) - (m[1] * ((m4 * m10) - (m6 * m8)))) + (m[2] * ((m4 * m9) - (m5 * m8)));
  reciprocal = determinant;
  absoluteDeterminant = reciprocal;
  if (!(reciprocal >= 0.0f))
  {
    absoluteDeterminant = -determinant;
  }
  result = 1;
  if (!(absoluteDeterminant < D_800C5AFC))
  {
    affineOne = D_800C5B00_de;
    reciprocal = affineOne / determinant;
    out[0] = reciprocal * minor0;
    negativeReciprocal = -reciprocal;
    out[1] = negativeReciprocal * ((m[1] * m[10]) - (m[2] * m[9]));
    out[2] = reciprocal * ((m[1] * m[6]) - (m[2] * m[5]));
    out[3] = 0.0f;
    out[4] = negativeReciprocal * ((m[4] * m[10]) - (m[6] * m[8]));
    out[5] = reciprocal * ((m[0] * m[10]) - (m[2] * m[8]));
    out[6] = negativeReciprocal * ((m[0] * m[6]) - (m[2] * m[4]));
    out[7] = 0.0f;
    out[8] = reciprocal * ((m[4] * m[9]) - (m[5] * m[8]));
    out[9] = negativeReciprocal * ((m[0] * m[9]) - (m[1] * m[8]));
    out[10] = reciprocal * ((m[0] * m[5]) - (m[1] * m[4]));
    out[11] = 0.0f;
    out[12] = -(((m[12] * out[0]) + (m[13] * out[4])) + (m[14] * out[8]));
    out[13] = -(((m[12] * out[1]) + (m[13] * out[5])) + (m[14] * out[9]));
    out[14] = -(((m[12] * out[2]) + (m[13] * out[6])) + (m[14] * out[10]));
    result = 0;
    out[15] = affineOne;
  }
  return result;
}

#ifdef NON_MATCHING
#include "TYPES.H"
extern f32 D_800C5B04_de;
extern f32 D_800C5B08_de;

/* Invert a 4x4 matrix with partial pivoting. Return one for a singular
 * matrix, leaving the destination untouched until elimination succeeds. */
s32 func_8029D510_de(f32 output[4][4], f32 input[4][4])
{
    f32 rows[4][8];
    s32 order[4];
    s32 i, j, k, pivot, row, other;
    f32 largest, magnitude, value, factor;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            rows[i][j] = input[i][j];
            rows[i][j + 4] = 0.0f;
        }
        rows[i][i + 4] = D_800C5B04_de;
        order[i] = i;
    }
    for (i = 0; i < 4; i++) {
        largest = rows[order[i]][i];
        if (largest < 0.0f) largest = -largest;
        pivot = i;
        for (j = i + 1; j < 4; j++) {
            magnitude = rows[order[j]][i];
            if (magnitude < 0.0f) magnitude = -magnitude;
            if (largest < magnitude) {
                pivot = j;
                largest = magnitude;
            }
        }
        row = order[pivot];
        order[pivot] = order[i];
        order[i] = row;
        value = rows[row][i];
        if (value == 0.0f) return 1;
        rows[row][i] = D_800C5B08_de;
        for (j = i + 1; j < 8; j++) rows[row][j] /= value;
        for (j = i + 1; j < 4; j++) {
            other = order[j];
            factor = -rows[other][i];
            if (factor != 0.0f) {
                rows[other][i] = 0.0f;
                for (k = i + 1; k < 8; k++) rows[other][k] += factor * rows[row][k];
            }
        }
    }
    for (i = 3; i > 0; i--) {
        row = order[i];
        for (j = i - 1; j >= 0; j--) {
            other = order[j];
            factor = rows[other][i];
            for (k = i; k < 8; k++) rows[other][k] -= factor * rows[row][k];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) output[i][j] = rows[order[i]][j + 4];
    }
    return 0;
}
#else
INCLUDE_ASM("span_1000", func_8029D510_de);
#endif
