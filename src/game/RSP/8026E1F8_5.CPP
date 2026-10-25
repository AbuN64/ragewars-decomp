#include "include_asm.h"
#include "COMMON/OBJRECAT4V7.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "RSP/800C97E0.H"
#include "RSP/8026E1F8_5.H"

#if !(defined(VERSION_US_REV1))
void func_8026EE20_de(f32 m[4][4], BoxRecAtC *box, BoxRecAtC *out) {
    f32 min[3];
    f32 max[3];
    f32 newMin[3];
    f32 newMax[3];
    f32 a;
    f32 b;
    s32 i;
    s32 j;

    min[0] = box->min[0];
    min[1] = box->min[1];
    min[2] = box->min[2];
    max[0] = box->max[0];
    max[1] = box->max[1];
    max[2] = box->max[2];
    newMin[0] = newMax[0] = m[3][0];
    newMin[1] = newMax[1] = m[3][1];
    newMin[2] = newMax[2] = m[3][2];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            a = m[j][i] * min[j];
            b = m[j][i] * max[j];
            if (a < b) {
                newMin[i] += a;
                newMax[i] += b;
            } else {
                newMin[i] += b;
                newMax[i] += a;
            }
        }
    }
    out->min[0] = newMin[0];
    out->min[1] = newMin[1];
    out->min[2] = newMin[2];
    out->max[0] = newMax[0];
    out->max[1] = newMax[1];
    out->max[2] = newMax[2];
}
void func_8026EF58_de(f32 *out, f32 *m) {
    f32 determinant;
    f32 reciprocalDeterminant;
    f32 m01TimesM22;
    f32 m00TimesM12;
    f32 inverseTranslationZNumeratorPartial;
    f32 affineHomogeneousOne;

    determinant = m[0] * m[5] * m[10]
                - m[0] * m[9] * m[6]
                - m[4] * m[1] * m[10]
                + m[4] * m[9] * m[2]
                + m[8] * m[1] * m[6]
                - m[8] * m[5] * m[2];

    if (determinant == 0.0f) {
        out[0] = m[0];
        out[1] = m[1];
        out[2] = m[2];
        out[3] = m[3];
        out[4] = m[4];
        out[5] = m[5];
        out[6] = m[6];
        out[7] = m[7];
        out[8] = m[8];
        out[9] = m[9];
        out[10] = m[10];
        out[11] = m[11];
        out[12] = m[12];
        out[13] = m[13];
        out[14] = m[14];
        out[15] = m[15];
        return;
    }

    affineHomogeneousOne = D_800C46C0_de;
    reciprocalDeterminant = affineHomogeneousOne / determinant;
    out[0] = (m[5] * m[10] - m[9] * m[6]) * reciprocalDeterminant;
    m01TimesM22 = m[1] * m[10];
    out[1] = (m[9] * m[2] - m01TimesM22) * reciprocalDeterminant;
    out[2] = (m[1] * m[6] - m[5] * m[2]) * reciprocalDeterminant;
    out[3] = 0.0f;
    out[4] = (-m[4] * m[10] + m[8] * m[6]) * reciprocalDeterminant;
    out[5] = (m[0] * m[10] - m[8] * m[2]) * reciprocalDeterminant;
    m00TimesM12 = m[0] * m[6];
    out[6] = (m[4] * m[2] - m00TimesM12) * reciprocalDeterminant;
    out[7] = 0.0f;
    out[8] = -(-m[4] * m[9] + m[8] * m[5]) * reciprocalDeterminant;
    out[9] = (-m[0] * m[9] + m[8] * m[1]) * reciprocalDeterminant;
    out[10] = -(-m[0] * m[5] + m[4] * m[1]) * reciprocalDeterminant;
    out[11] = 0.0f;
    out[12] = (-m[4] * m[9] * m[14]
             + m[4] * m[10] * m[13]
             + m[8] * m[5] * m[14]
             - m[8] * m[6] * m[13]
             - m[12] * m[5] * m[10]
             + m[12] * m[9] * m[6]) * reciprocalDeterminant;
    out[13] = (m[0] * m[9] * m[14]
             - m[0] * m[10] * m[13]
             - m[8] * m[1] * m[14]
             + m[8] * m[2] * m[13]
             + m[12] * m[1] * m[10]
             - m[12] * m[9] * m[2]) * reciprocalDeterminant;
    inverseTranslationZNumeratorPartial = m[0] * m[5] * m[14]
                                        - m[0] * m[6] * m[13]
                                        - m[4] * m[1] * m[14]
                                        + m[4] * m[2] * m[13]
                                        + m[12] * m[1] * m[6];
    out[14] = (m[12] * m[5] * m[2] - inverseTranslationZNumeratorPartial) * reciprocalDeterminant;
    out[15] = affineHomogeneousOne;
}
#ifdef NON_MATCHING
void func_8026F368_de(MatrixF *mtx, CVector3 *eye, CVector3 *target, CVector3 *up) {
    CVector3 upward;
    CVector3 forward;
    CVector3 right;
    f32 length;

    Particle_SubtractVectors(&forward, target, eye);
    length = func_802B72B0_de(forward.x * forward.x + forward.y * forward.y + forward.z * forward.z);
    if (0.001f < length) {
        length = -1.0f / length;
        forward.x *= length;
        forward.y *= length;
        forward.z *= length;
    } else {
        forward.x = 1.0f;
        forward.y = 0.0f;
        forward.z = 0.0f;
    }

    Particle_CrossVectors(&right, up, &forward);
    length = func_802B72B0_de(right.x * right.x + right.y * right.y + right.z * right.z);
    if (0.001f < length) {
        length = 1.0f / length;
        right.x *= length;
        right.y *= length;
        right.z *= length;
    } else {
        right.x = 1.0f;
        right.y = 0.0f;
        right.z = 0.0f;
    }

    Particle_CrossVectors(&upward, &forward, &right);
    length = 1.0f / func_802B72B0_de(upward.x * upward.x + upward.y * upward.y + upward.z * upward.z);
    upward.x *= length;
    upward.y *= length;
    upward.z *= length;

    mtx->m[0][0] = right.x;
    mtx->m[1][0] = right.y;
    mtx->m[2][0] = right.z;
    mtx->m[3][0] = -(eye->x * right.x + eye->y * right.y + eye->z * right.z);
    mtx->m[0][1] = upward.x;
    mtx->m[1][1] = upward.y;
    mtx->m[2][1] = upward.z;
    mtx->m[3][1] = -(eye->x * upward.x + eye->y * upward.y + eye->z * upward.z);
    mtx->m[0][2] = forward.x;
    mtx->m[1][2] = forward.y;
    mtx->m[2][2] = forward.z;
    mtx->m[3][2] = -(eye->x * forward.x + eye->y * forward.y + eye->z * forward.z);
    mtx->m[0][3] = 0.0f;
    mtx->m[1][3] = 0.0f;
    mtx->m[2][3] = 0.0f;
    mtx->m[3][3] = 1.0f;
}
#else
INCLUDE_ASM("span_1000", func_8026F368_de);
#endif
void Rsp_MultiplyAffineMatrices(f32 *out, f32 *left, f32 *right)
{
    out[0] = (left[0] * right[0]) + (left[1] * right[4]) + (left[2] * right[8]);
    out[1] = (left[0] * right[1]) + (left[1] * right[5]) + (left[2] * right[9]);
    out[2] = (left[0] * right[2]) + (left[1] * right[6]) + (left[2] * right[10]);
    out[4] = (left[4] * right[0]) + (left[5] * right[4]) + (left[6] * right[8]);
    out[5] = (left[4] * right[1]) + (left[5] * right[5]) + (left[6] * right[9]);
    out[6] = (left[4] * right[2]) + (left[5] * right[6]) + (left[6] * right[10]);
    out[8] = (left[8] * right[0]) + (left[9] * right[4]) + (left[10] * right[8]);
    out[9] = (left[8] * right[1]) + (left[9] * right[5]) + (left[10] * right[9]);
    out[10] = (left[8] * right[2]) + (left[9] * right[6]) + (left[10] * right[10]);
    out[12] = (left[12] * right[0]) + (left[13] * right[4]) +
              (left[14] * right[8]) + right[12];
    out[13] = (left[12] * right[1]) + (left[13] * right[5]) +
              (left[14] * right[9]) + right[13];
    out[14] = (left[12] * right[2]) + (left[13] * right[6]) +
              (left[14] * right[10]) + right[14];
    out[3] = out[7] = out[11] = 0.0f;
    out[15] = D_800C46EC_de;
}
void func_8026F898_de(f32 *out, f32 *left, f32 *right)
{
    out[0] = (left[0] * right[0]) + (left[1] * right[4]) + (left[2] * right[8]) + (left[3] * right[12]);
    out[1] = (left[0] * right[1]) + (left[1] * right[5]) + (left[2] * right[9]) + (left[3] * right[13]);
    out[2] = (left[0] * right[2]) + (left[1] * right[6]) + (left[2] * right[10]) + (left[3] * right[14]);
    out[3] = (left[0] * right[3]) + (left[1] * right[7]) + (left[2] * right[11]) + (left[3] * right[15]);
    out[4] = (left[4] * right[0]) + (left[5] * right[4]) + (left[6] * right[8]) + (left[7] * right[12]);
    out[5] = (left[4] * right[1]) + (left[5] * right[5]) + (left[6] * right[9]) + (left[7] * right[13]);
    out[6] = (left[4] * right[2]) + (left[5] * right[6]) + (left[6] * right[10]) + (left[7] * right[14]);
    out[7] = (left[4] * right[3]) + (left[5] * right[7]) + (left[6] * right[11]) + (left[7] * right[15]);
    out[8] = (left[8] * right[0]) + (left[9] * right[4]) + (left[10] * right[8]) + (left[11] * right[12]);
    out[9] = (left[8] * right[1]) + (left[9] * right[5]) + (left[10] * right[9]) + (left[11] * right[13]);
    out[10] = (left[8] * right[2]) + (left[9] * right[6]) + (left[10] * right[10]) + (left[11] * right[14]);
    out[11] = (left[8] * right[3]) + (left[9] * right[7]) + (left[10] * right[11]) + (left[11] * right[15]);
    out[12] = (left[12] * right[0]) + (left[13] * right[4]) + (left[14] * right[8]) + (left[15] * right[12]);
    out[13] = (left[12] * right[1]) + (left[13] * right[5]) + (left[14] * right[9]) + (left[15] * right[13]);
    out[14] = (left[12] * right[2]) + (left[13] * right[6]) + (left[14] * right[10]) + (left[15] * right[14]);
    out[15] = (left[12] * right[3]) + (left[13] * right[7]) + (left[14] * right[11]) + (left[15] * right[15]);
}
#ifdef NON_MATCHING
void func_8026FC9C_de(f32 *src, PackedMatrixWords *dst) {
    u32 *upper = dst->upper;
    u32 *lower = dst->lower;
    f32 value;
    s32 a;
    s32 b;
    value = (src[(0) * 2]) * (D_800C46F0_de); if (!(*(&(D_800C46F0_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C46F0_de) + 1)); (a) |= 0x80000000; }; value = (src[(0) * 2 + 1]) * (D_800C46F8_de); if (!(*(&(D_800C46F8_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C46F8_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(1) * 2]) * (D_800C4700_de); if (!(*(&(D_800C4700_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4700_de) + 1)); (a) |= 0x80000000; }; value = (src[(1) * 2 + 1]) * (D_800C4708_de); if (!(*(&(D_800C4708_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4708_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(2) * 2]) * (D_800C4710_de); if (!(*(&(D_800C4710_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4710_de) + 1)); (a) |= 0x80000000; }; value = (src[(2) * 2 + 1]) * (D_800C4718_de); if (!(*(&(D_800C4718_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4718_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(3) * 2]) * (D_800C4720_de); if (!(*(&(D_800C4720_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4720_de) + 1)); (a) |= 0x80000000; }; value = (src[(3) * 2 + 1]) * (D_800C4728_de); if (!(*(&(D_800C4728_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4728_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(4) * 2]) * (D_800C4730_de); if (!(*(&(D_800C4730_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4730_de) + 1)); (a) |= 0x80000000; }; value = (src[(4) * 2 + 1]) * (D_800C4738_de); if (!(*(&(D_800C4738_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4738_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(5) * 2]) * (D_800C4740_de); if (!(*(&(D_800C4740_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4740_de) + 1)); (a) |= 0x80000000; }; value = (src[(5) * 2 + 1]) * (D_800C4748_de); if (!(*(&(D_800C4748_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4748_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(6) * 2]) * (D_800C4750_de); if (!(*(&(D_800C4750_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4750_de) + 1)); (a) |= 0x80000000; }; value = (src[(6) * 2 + 1]) * (D_800C4758_de); if (!(*(&(D_800C4758_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4758_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(7) * 2]) * (D_800C4760_de); if (!(*(&(D_800C4760_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4760_de) + 1)); (a) |= 0x80000000; }; value = (src[(7) * 2 + 1]) * (D_800C4768_de); if (!(*(&(D_800C4768_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4768_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
}
#else
INCLUDE_ASM("span_1000", func_8026FC9C_de);
#endif
#ifdef NON_MATCHING
void func_8027027C_de(f32 *src, PackedMatrixWords *dst) {
    u32 *upper = dst->upper;
    u32 *lower = dst->lower;
    f32 value;
    s32 a;
    s32 b;
    value = (src[0]) * (D_800C4770_de); if (!(*(&(D_800C4770_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4770_de) + 1)); (a) |= 0x80000000; };
    value = (src[1]) * (D_800C4778_de); if (!(*(&(D_800C4778_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4778_de) + 1)); (b) |= 0x80000000; };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;

    value = (src[2]) * (D_800C4780_de); if (!(*(&(D_800C4780_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4780_de) + 1)); (a) |= 0x80000000; };
    *upper = a & 0xFFFF0000;
    *lower = a << 16;
    upper++;
    lower++;

    value = (src[4]) * (D_800C4788_de); if (!(*(&(D_800C4788_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4788_de) + 1)); (a) |= 0x80000000; };
    value = (src[5]) * (D_800C4790_de); if (!(*(&(D_800C4790_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4790_de) + 1)); (b) |= 0x80000000; };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;

    value = (src[6]) * (D_800C4798_de); if (!(*(&(D_800C4798_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4798_de) + 1)); (a) |= 0x80000000; };
    *upper = a & 0xFFFF0000;
    *lower = a << 16;
    upper++;
    lower++;

    value = (src[8]) * (D_800C47A0_de); if (!(*(&(D_800C47A0_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C47A0_de) + 1)); (a) |= 0x80000000; };
    value = (src[9]) * (D_800C47A8_de); if (!(*(&(D_800C47A8_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C47A8_de) + 1)); (b) |= 0x80000000; };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;

    value = (src[10]) * (D_800C47B0_de); if (!(*(&(D_800C47B0_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C47B0_de) + 1)); (a) |= 0x80000000; };
    *upper = a & 0xFFFF0000;
    *lower = a << 16;
    upper++;
    lower++;

    value = (src[12]) * (D_800C47B8_de); if (!(*(&(D_800C47B8_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C47B8_de) + 1)); (a) |= 0x80000000; };
    value = (src[13]) * (D_800C47C0_de); if (!(*(&(D_800C47C0_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C47C0_de) + 1)); (b) |= 0x80000000; };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;

    value = (src[14]) * (D_800C47C8_de); if (!(*(&(D_800C47C8_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C47C8_de) + 1)); (a) |= 0x80000000; };
    *upper = (a & 0xFFFF0000) | 1;
    *lower = a << 16;
}
#else
INCLUDE_ASM("span_1000", func_8027027C_de);
#endif
void func_80270700_de(f32 *dst, PackedMatrixWords *src) {
    u32 upper;
    u32 lower;
    f32 scale = D_800C47D0_de;

    upper = src->upper[0]; lower = src->lower[0]; dst[(0) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(0) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[1]; lower = src->lower[1]; dst[(1) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(1) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[2]; lower = src->lower[2]; dst[(2) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(2) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[3]; lower = src->lower[3]; dst[(3) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(3) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[4]; lower = src->lower[4]; dst[(4) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(4) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[5]; lower = src->lower[5]; dst[(5) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(5) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[6]; lower = src->lower[6]; dst[(6) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(6) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[7]; lower = src->lower[7]; dst[(7) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(7) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
}
void Rsp_ConvertMatrixToFloat(f32 *dst, PackedMatrixWords *src) {
    u32 upper;
    u32 lower;
    f32 scale = D_800C98C4;
    upper = src->upper[0]; lower = src->lower[0]; dst[(0) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(0) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[1]; lower = src->lower[1]; dst[(1) * 2] = (f32)(s32)(upper | (lower >> 16)) * scale; dst[(1) * 2 + 1] = 0.0f;
    upper = src->upper[2]; lower = src->lower[2]; dst[(2) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(2) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[3]; lower = src->lower[3]; dst[(3) * 2] = (f32)(s32)(upper | (lower >> 16)) * scale; dst[(3) * 2 + 1] = 0.0f;
    upper = src->upper[4]; lower = src->lower[4]; dst[(4) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(4) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[5]; lower = src->lower[5]; dst[(5) * 2] = (f32)(s32)(upper | (lower >> 16)) * scale; dst[(5) * 2 + 1] = 0.0f;
    upper = src->upper[6]; lower = src->lower[6]; dst[(6) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(6) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    {
        f32 last;
        upper = src->upper[7];
        lower = src->lower[7];
        last = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale;
        dst[15] = D_800C98C8;
        dst[14] = last;
    }
}
void func_80270AAC_de(CQuatern *out, f32 amount, CQuatern *a, CQuatern *b) {
    CQuatern negative;
    CQuatern *other;
    f32 dot;
    f32 negativeDot;
    f32 angle;
    f32 sine;
    f32 inverseSine;
    f32 scaleA;
    f32 scaleB;

    other = b;
    negative = *b;
    negative.x = -negative.x;
    negative.y = -negative.y;
    negative.z = -negative.z;
    negative.w = -negative.w;

    dot = (a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w);
    negativeDot = (a->x * negative.x) + (a->y * negative.y) +
                  (a->z * negative.z) + (a->w * negative.w);
    if (dot < negativeDot) {
        dot = negativeDot;
        other = &negative;
    }

    angle = Nav_ArcCos(dot);
    sine = func_802B7130_de(angle);
    if (sine == 0.0f) {
        *out = *a;
        return;
    }

    inverseSine = D_800C47DC_de / sine;
    scaleA = func_802B7130_de((D_800C47DC_de - amount) * angle) * inverseSine;
    scaleB = func_802B7130_de(amount * angle) * inverseSine;
    if (dot < negativeDot) {
        other = &negative;
    }

    out->x = (scaleA * a->x) + (scaleB * other->x);
    out->y = (scaleA * a->y) + (scaleB * other->y);
    out->z = (scaleA * a->z) + (scaleB * other->z);
    out->w = (scaleA * a->w) + (scaleB * other->w);
}
void func_80270CD0_de(CQuatern *out, f32 amount, CQuatern *a, CQuatern *b) {
    CQuatern negative;
    CQuatern *other;
    f32 dot;
    f32 negativeDot;
    f32 angle;
    f32 sine;
    f32 inverseSine;
    f32 scaleA;
    f32 scaleB;

    other = b;
    negative = *b;
    negative.x = -negative.x;
    negative.y = -negative.y;
    negative.z = -negative.z;
    negative.w = -negative.w;

    dot = (a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w);
    negativeDot = (a->x * negative.x) + (a->y * negative.y) +
                  (a->z * negative.z) + (a->w * negative.w);
    if (dot < negativeDot) {
        dot = negativeDot;
        other = &negative;
    }

    if (D_800C47E0_de < dot) {
        f32 magnitude;
        f32 scale;

        out->x = a->x + amount * (other->x - a->x);
        out->y = a->y + amount * (other->y - a->y);
        out->z = a->z + amount * (other->z - a->z);
        out->w = a->w + amount * (other->w - a->w);
        magnitude = func_802B72B0_de((out->x * out->x) + (out->y * out->y) +
                                  (out->z * out->z) + (out->w * out->w));
        if (magnitude != 0.0f) {
            scale = D_800C47E4_de / magnitude;
            out->x *= scale;
            out->y *= scale;
            out->z *= scale;
            out->w *= scale;
        }
    } else {
        angle = Nav_ArcCos(dot);
        sine = func_802B7130_de(angle);
        if (sine == 0.0f) {
            *out = *a;
            return;
        }

        inverseSine = D_800C47E8_de / sine;
        scaleA = func_802B7130_de((D_800C47E8_de - amount) * angle) * inverseSine;
        scaleB = func_802B7130_de(amount * angle) * inverseSine;
    if (dot < negativeDot) {
        other = &negative;
    }

        out->x = (scaleA * a->x) + (scaleB * other->x);
        out->y = (scaleA * a->y) + (scaleB * other->y);
        out->z = (scaleA * a->z) + (scaleB * other->z);
        out->w = (scaleA * a->w) + (scaleB * other->w);
    }
}
CVector3 func_80270FE8_de(CVector3 *in, f32 amount) {
    CVector3 random;
    CVector3 result;
    CVector3 *randomPtr;
    f32 randomMagnitude;
    f32 randomScale;
    f32 inputMagnitude;
    f32 inputScale;

    random.x = (f32)((func_802744D4_de() % 20000) - 0x2710);
    random.y = (f32)((func_802744D4_de() % 20000) - 0x2710);
    random.z = (f32)((func_802744D4_de() % 20000) - 0x2710);
    randomPtr = &random;

    randomMagnitude = func_802B72B0_de((randomPtr->x * randomPtr->x) +
                                    (randomPtr->y * randomPtr->y) +
                                    (randomPtr->z * randomPtr->z));
    if (randomMagnitude != 0.0f) {
        randomScale = D_800C47EC_de / randomMagnitude;
        randomPtr->x *= randomScale;
        randomPtr->y *= randomScale;
        randomPtr->z *= randomScale;
    }

    inputMagnitude = func_802B72B0_de((in->x * in->x) +
                                   (in->y * in->y) +
                                   (in->z * in->z));
    if (inputMagnitude != 0.0f) {
        inputScale = D_800C47F0_de / inputMagnitude;
        in->x *= inputScale;
        in->y *= inputScale;
        in->z *= inputScale;
    }

    result.x = in->x + amount * (randomPtr->x - in->x);
    result.y = in->y + amount * (randomPtr->y - in->y);
    result.z = in->z + amount * (randomPtr->z - in->z);
    return result;
}
extern f32 D_800C47F4_de, D_800C47FC_de, D_800C4804_de, D_800C480C_de, D_800C4814_de, D_800C481C_de;

CVector3 func_80271248_de(CVector3 *in, f32 amount) {
    CVector3 random;
    CVector3 result;
    CVector3 *randomPtr;
    f32 randomMagnitude;
    f32 randomScale;
    f32 inputMagnitude;
    f32 inputScale;

    random.x = (f32)((func_802744D4_de() % 20000) - 0x2710) *
               D_800C47F4_de;
    random.y = in->y;
    random.z = in->z;
    randomPtr = &random;

    randomMagnitude = func_802B72B0_de((randomPtr->x * randomPtr->x) +
                                    (randomPtr->y * randomPtr->y) +
                                    (randomPtr->z * randomPtr->z));
    if (randomMagnitude != 0.0f) {
        randomScale = D_800C47F8_de / randomMagnitude;
        randomPtr->x *= randomScale;
        randomPtr->y *= randomScale;
        randomPtr->z *= randomScale;
    }

    inputMagnitude = func_802B72B0_de((in->x * in->x) +
                                   (in->y * in->y) +
                                   (in->z * in->z));
    if (inputMagnitude != 0.0f) {
        inputScale = D_800C47FC_de / inputMagnitude;
        in->x *= inputScale;
        in->y *= inputScale;
        in->z *= inputScale;
    }

    result.x = in->x + amount * (randomPtr->x - in->x);
    result.y = in->y + amount * (randomPtr->y - in->y);
    result.z = in->z + amount * (randomPtr->z - in->z);
    return result;
}
CVector3 func_80271430_de(CVector3 *in, f32 amount) {
    CVector3 random;
    CVector3 result;
    CVector3 *randomPtr;
    f32 randomMagnitude;
    f32 randomScale;
    f32 inputMagnitude;
    f32 inputScale;

    random.x = in->x;
    random.y = ((f32)(func_802744D4_de() % 20000) - D_800C4800_de) * D_800C4804_de;
    random.z = in->z;
    randomPtr = &random;

    randomMagnitude = func_802B72B0_de((randomPtr->x * randomPtr->x) +
                                    (randomPtr->y * randomPtr->y) +
                                    (randomPtr->z * randomPtr->z));
    if (randomMagnitude != 0.0f) {
        randomScale = D_800C4808_de / randomMagnitude;
        randomPtr->x *= randomScale;
        randomPtr->y *= randomScale;
        randomPtr->z *= randomScale;
    }

    inputMagnitude = func_802B72B0_de((in->x * in->x) +
                                   (in->y * in->y) +
                                   (in->z * in->z));
    if (inputMagnitude != 0.0f) {
        inputScale = D_800C480C_de / inputMagnitude;
        in->x *= inputScale;
        in->y *= inputScale;
        in->z *= inputScale;
    }

    result.x = in->x + amount * (randomPtr->x - in->x);
    result.y = in->y + amount * (randomPtr->y - in->y);
    result.z = in->z + amount * (randomPtr->z - in->z);
    return result;
}
CVector3 *func_80271624_de(CVector3 *out, CVector3 *in, f32 amount) {
    CVector3 random;
    CVector3 result;
    CVector3 *randomPtr;

    random.x = in->x;
    random.y = in->y;
    random.z = ((f32)(func_802744D4_de() % 20000) - D_800C4810_de) *
               D_800C4814_de;

    randomPtr = &random;
    {
        f32 magnitude;
        f32 scale;

        magnitude = func_802B72B0_de((randomPtr->x * randomPtr->x) +
                                  (randomPtr->y * randomPtr->y) +
                                  (randomPtr->z * randomPtr->z));
        if (magnitude != 0.0f) {
            scale = D_800C4818_de / magnitude;
            randomPtr->x *= scale;
            randomPtr->y *= scale;
            randomPtr->z *= scale;
        }
    }
    {
        f32 magnitude;
        f32 scale;

        magnitude = func_802B72B0_de((in->x * in->x) +
                                  (in->y * in->y) +
                                  (in->z * in->z));
        if (magnitude != 0.0f) {
            scale = D_800C481C_de / magnitude;
            in->x *= scale;
            in->y *= scale;
            in->z *= scale;
        }
    }

    result.x = in->x + amount * (randomPtr->x - in->x);
    result.y = in->y + amount * (randomPtr->y - in->y);
    result.z = in->z + amount * (randomPtr->z - in->z);
    *out = result;
    return out;
}
CQuatern func_80271818_de(CVector3 *input) {
    CQuatern result;
    CVector3 normalized;
    CVector3 basis;
    CVector3 axis;
    f32 magnitude;
    f32 angle;
    f32 axisMagnitude;

    magnitude = func_802B72B0_de((input->x * input->x) +
                              (input->y * input->y) +
                              (input->z * input->z));
    if (magnitude == 0.0f) {
        result.z = 0.0f;
        result.y = 0.0f;
        result.x = 0.0f;
        result.w = D_800C4820_de;
    } else {
        f32 normalizationScale;

        normalizationScale = D_800C4824_de / magnitude;
        normalized.x = input->x * normalizationScale;
        normalized.y = input->y * normalizationScale;
        normalized.z = input->z * normalizationScale;

        basis.x = 0.0f;
        basis.y = 0.0f;
        basis.z = D_800C4824_de;

        if (normalized.z < 0.0f) {
            if (D_800C4828_de < -normalized.z) {
                goto pole;
            }
            goto general;
        }
        if (D_800C482C_de < normalized.z) {
pole:
        {
            f32 halfAngle;
            f32 scale;

            halfAngle = 0.0f;
            scale = func_802B7130_de(halfAngle);
            result.z = normalized.z * scale;
            D_80115DEC = scale;
            result.x = halfAngle;
            result.y = halfAngle;
            result.w = func_802B6560_de(halfAngle);
        }
        } else {
general:
        {
            f32 halfAngle;
            f32 scale;

            angle = Nav_ArcCos((normalized.x * basis.x) +
                                  (normalized.y * basis.y) +
                                  (normalized.z * basis.z));
            axis.x = (basis.y * normalized.z) - (basis.z * normalized.y);
            axis.y = (basis.z * normalized.x) - (basis.x * normalized.z);
            axis.z = (basis.x * normalized.y) - (basis.y * normalized.x);

            axisMagnitude = func_802B72B0_de((axis.x * axis.x) +
                                          (axis.y * axis.y) +
                                          (axis.z * axis.z));
            if (axisMagnitude != 0.0f) {
                f32 axisScale;

                axisScale = D_800C4830_de / axisMagnitude;
                axis.x *= axisScale;
                axis.y *= axisScale;
                axis.z *= axisScale;
            }

            halfAngle = angle * D_800C4834_de;
            scale = func_802B7130_de(halfAngle);
            result.x = axis.x * scale;
            result.y = axis.y * scale;
            result.z = axis.z * scale;
            D_80115DEC = scale;
            result.w = func_802B6560_de(halfAngle);
        }
        }
    }
    return result;
}
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int rodata_func_8026EE20_de_800C97C0[7] = {
    0x3A83126F, 0xBF800000, 0x3F800000, 0x3A83126F, 0x3F800000, 0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
/* Transforms an axis-aligned box by a matrix: starts the new minimum and maximum at the matrix translation and, for every matrix entry, adds the smaller of its products with the old minimum and maximum to the new minimum and the larger to the new maximum. */

void func_8026EE20_de(f32 m[4][4], BoxRecAtC *box, BoxRecAtC *out) {
    f32 min[3];
    f32 max[3];
    f32 newMin[3];
    f32 newMax[3];
    f32 a;
    f32 b;
    s32 i;
    s32 j;

    min[0] = box->min[0];
    min[1] = box->min[1];
    min[2] = box->min[2];
    max[0] = box->max[0];
    max[1] = box->max[1];
    max[2] = box->max[2];
    newMin[0] = newMax[0] = m[3][0];
    newMin[1] = newMax[1] = m[3][1];
    newMin[2] = newMax[2] = m[3][2];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            a = m[j][i] * min[j];
            b = m[j][i] * max[j];
            if (a < b) {
                newMin[i] += a;
                newMax[i] += b;
            } else {
                newMin[i] += b;
                newMax[i] += a;
            }
        }
    }
    out->min[0] = newMin[0];
    out->min[1] = newMin[1];
    out->min[2] = newMin[2];
    out->max[0] = newMax[0];
    out->max[1] = newMax[1];
    out->max[2] = newMax[2];
}

extern f32 D_800C46C0_de;

/**
 * Invert a row-major affine 4x4 transform, copying singular inputs unchanged.
 *
 * @name CMtxF__Invert
 * @param out Destination for the 16-float inverse; it must not overlap `m`.
 * @param m Source matrix stored as four contiguous rows. Its last column is
 *          (0, 0, 0, 1), its final row holds translation, and it transforms
 *          row vectors.
 *
 * Computes the determinant and adjugate of the upper-left 3x3 linear block,
 * scales them by the reciprocal determinant, then derives the inverse
 * translation as -translation * inverse_linear. If the determinant is exactly
 * zero, all 16 source elements are copied to `out` instead.
 *
 * Game role: Callers invert model or camera transforms so positions can be
 * moved from world space into object-local or view space for spatial and
 * rendering calculations.
 */
void func_8026EF58_de(f32 *out, f32 *m) {
    f32 determinant;
    f32 reciprocalDeterminant;
    f32 m01TimesM22;
    f32 m00TimesM12;
    f32 inverseTranslationZNumeratorPartial;
    f32 affineHomogeneousOne;

    determinant = m[0] * m[5] * m[10]
                - m[0] * m[9] * m[6]
                - m[4] * m[1] * m[10]
                + m[4] * m[9] * m[2]
                + m[8] * m[1] * m[6]
                - m[8] * m[5] * m[2];

    if (determinant == 0.0f) {
        out[0] = m[0];
        out[1] = m[1];
        out[2] = m[2];
        out[3] = m[3];
        out[4] = m[4];
        out[5] = m[5];
        out[6] = m[6];
        out[7] = m[7];
        out[8] = m[8];
        out[9] = m[9];
        out[10] = m[10];
        out[11] = m[11];
        out[12] = m[12];
        out[13] = m[13];
        out[14] = m[14];
        out[15] = m[15];
        return;
    }

    affineHomogeneousOne = D_800C46C0_de;
    reciprocalDeterminant = affineHomogeneousOne / determinant;
    out[0] = (m[5] * m[10] - m[9] * m[6]) * reciprocalDeterminant;
    m01TimesM22 = m[1] * m[10];
    out[1] = (m[9] * m[2] - m01TimesM22) * reciprocalDeterminant;
    out[2] = (m[1] * m[6] - m[5] * m[2]) * reciprocalDeterminant;
    out[3] = 0.0f;
    out[4] = (-m[4] * m[10] + m[8] * m[6]) * reciprocalDeterminant;
    out[5] = (m[0] * m[10] - m[8] * m[2]) * reciprocalDeterminant;
    m00TimesM12 = m[0] * m[6];
    out[6] = (m[4] * m[2] - m00TimesM12) * reciprocalDeterminant;
    out[7] = 0.0f;
    out[8] = -(-m[4] * m[9] + m[8] * m[5]) * reciprocalDeterminant;
    out[9] = (-m[0] * m[9] + m[8] * m[1]) * reciprocalDeterminant;
    out[10] = -(-m[0] * m[5] + m[4] * m[1]) * reciprocalDeterminant;
    out[11] = 0.0f;
    out[12] = (-m[4] * m[9] * m[14]
             + m[4] * m[10] * m[13]
             + m[8] * m[5] * m[14]
             - m[8] * m[6] * m[13]
             - m[12] * m[5] * m[10]
             + m[12] * m[9] * m[6]) * reciprocalDeterminant;
    out[13] = (m[0] * m[9] * m[14]
             - m[0] * m[10] * m[13]
             - m[8] * m[1] * m[14]
             + m[8] * m[2] * m[13]
             + m[12] * m[1] * m[10]
             - m[12] * m[9] * m[2]) * reciprocalDeterminant;
    inverseTranslationZNumeratorPartial = m[0] * m[5] * m[14]
                                        - m[0] * m[6] * m[13]
                                        - m[4] * m[1] * m[14]
                                        + m[4] * m[2] * m[13]
                                        + m[12] * m[1] * m[6];
    out[14] = (m[12] * m[5] * m[2] - inverseTranslationZNumeratorPartial) * reciprocalDeterminant;
    out[15] = affineHomogeneousOne;
}

/* Builds a look-at view matrix from an eye position, a target and an up vector: the forward axis is the normalised direction from the target back to the eye, the right axis the normalised cross product of up and forward, the true up axis their normalised cross product, each written as a matrix column with the negated eye projections as the translation row, falling back to the x axis when forward or right degenerate. */

extern void Particle_SubtractVectors(CVector3 *out, CVector3 *a, CVector3 *b);
extern void Particle_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b);
extern f32 func_802B72B0_de(f32);

void func_8026F368_de(MatrixF *mtx, CVector3 *eye, CVector3 *target, CVector3 *up) {
    CVector3 upward;
    CVector3 forward;
    CVector3 right;
    f32 length;

    Particle_SubtractVectors(&forward, target, eye);
    length = func_802B72B0_de(forward.x * forward.x + forward.y * forward.y + forward.z * forward.z);
    if (0.001f < length) {
        length = -1.0f / length;
        forward.x *= length;
        forward.y *= length;
        forward.z *= length;
    } else {
        forward.x = 1.0f;
        forward.y = 0.0f;
        forward.z = 0.0f;
    }

    Particle_CrossVectors(&right, up, &forward);
    length = func_802B72B0_de(right.x * right.x + right.y * right.y + right.z * right.z);
    if (0.001f < length) {
        length = 1.0f / length;
        right.x *= length;
        right.y *= length;
        right.z *= length;
    } else {
        right.x = 1.0f;
        right.y = 0.0f;
        right.z = 0.0f;
    }

    Particle_CrossVectors(&upward, &forward, &right);
    length = 1.0f / func_802B72B0_de(upward.x * upward.x + upward.y * upward.y + upward.z * upward.z);
    upward.x *= length;
    upward.y *= length;
    upward.z *= length;

    mtx->m[0][0] = right.x;
    mtx->m[1][0] = right.y;
    mtx->m[2][0] = right.z;
    mtx->m[3][0] = -(eye->x * right.x + eye->y * right.y + eye->z * right.z);
    mtx->m[0][1] = upward.x;
    mtx->m[1][1] = upward.y;
    mtx->m[2][1] = upward.z;
    mtx->m[3][1] = -(eye->x * upward.x + eye->y * upward.y + eye->z * upward.z);
    mtx->m[0][2] = forward.x;
    mtx->m[1][2] = forward.y;
    mtx->m[2][2] = forward.z;
    mtx->m[3][2] = -(eye->x * forward.x + eye->y * forward.y + eye->z * forward.z);
    mtx->m[0][3] = 0.0f;
    mtx->m[1][3] = 0.0f;
    mtx->m[2][3] = 0.0f;
    mtx->m[3][3] = 1.0f;
}

/** Multiply two affine 4x4 matrices into the output matrix. */
void Rsp_MultiplyAffineMatrices(f32 *out, f32 *left, f32 *right)
{
    out[(0) * 4 + (0)] = (left[(0) * 4] * right[(0)]) + (left[(0) * 4 + 1] * right[4 + (0)]) + (left[(0) * 4 + 2] * right[8 + (0)]);
    out[(0) * 4 + (1)] = (left[(0) * 4] * right[(1)]) + (left[(0) * 4 + 1] * right[4 + (1)]) + (left[(0) * 4 + 2] * right[8 + (1)]);
    out[(0) * 4 + (2)] = (left[(0) * 4] * right[(2)]) + (left[(0) * 4 + 1] * right[4 + (2)]) + (left[(0) * 4 + 2] * right[8 + (2)]);
    out[(1) * 4 + (0)] = (left[(1) * 4] * right[(0)]) + (left[(1) * 4 + 1] * right[4 + (0)]) + (left[(1) * 4 + 2] * right[8 + (0)]);
    out[(1) * 4 + (1)] = (left[(1) * 4] * right[(1)]) + (left[(1) * 4 + 1] * right[4 + (1)]) + (left[(1) * 4 + 2] * right[8 + (1)]);
    out[(1) * 4 + (2)] = (left[(1) * 4] * right[(2)]) + (left[(1) * 4 + 1] * right[4 + (2)]) + (left[(1) * 4 + 2] * right[8 + (2)]);
    out[(2) * 4 + (0)] = (left[(2) * 4] * right[(0)]) + (left[(2) * 4 + 1] * right[4 + (0)]) + (left[(2) * 4 + 2] * right[8 + (0)]);
    out[(2) * 4 + (1)] = (left[(2) * 4] * right[(1)]) + (left[(2) * 4 + 1] * right[4 + (1)]) + (left[(2) * 4 + 2] * right[8 + (1)]);
    out[(2) * 4 + (2)] = (left[(2) * 4] * right[(2)]) + (left[(2) * 4 + 1] * right[4 + (2)]) + (left[(2) * 4 + 2] * right[8 + (2)]);
    out[12] = (left[12] * right[0]) + (left[13] * right[4]) +
              (left[14] * right[8]) + right[12];
    out[13] = (left[12] * right[1]) + (left[13] * right[5]) +
              (left[14] * right[9]) + right[13];
    out[14] = (left[12] * right[2]) + (left[13] * right[6]) +
              (left[14] * right[10]) + right[14];
    out[3] = out[7] = out[11] = 0.0f;
    out[15] = D_800C46EC_de;
}
/** Multiply two column-addressed 4x4 matrices into the output matrix. */
void func_8026F898_de(f32 *out, f32 *left, f32 *right)
{
    out[(0) * 4 + (0)] = (left[(0) * 4] * right[(0)]) + (left[(0) * 4 + 1] * right[4 + (0)]) + (left[(0) * 4 + 2] * right[8 + (0)]) + (left[(0) * 4 + 3] * right[12 + (0)]);
    out[(0) * 4 + (1)] = (left[(0) * 4] * right[(1)]) + (left[(0) * 4 + 1] * right[4 + (1)]) + (left[(0) * 4 + 2] * right[8 + (1)]) + (left[(0) * 4 + 3] * right[12 + (1)]);
    out[(0) * 4 + (2)] = (left[(0) * 4] * right[(2)]) + (left[(0) * 4 + 1] * right[4 + (2)]) + (left[(0) * 4 + 2] * right[8 + (2)]) + (left[(0) * 4 + 3] * right[12 + (2)]);
    out[(0) * 4 + (3)] = (left[(0) * 4] * right[(3)]) + (left[(0) * 4 + 1] * right[4 + (3)]) + (left[(0) * 4 + 2] * right[8 + (3)]) + (left[(0) * 4 + 3] * right[12 + (3)]);
    out[(1) * 4 + (0)] = (left[(1) * 4] * right[(0)]) + (left[(1) * 4 + 1] * right[4 + (0)]) + (left[(1) * 4 + 2] * right[8 + (0)]) + (left[(1) * 4 + 3] * right[12 + (0)]);
    out[(1) * 4 + (1)] = (left[(1) * 4] * right[(1)]) + (left[(1) * 4 + 1] * right[4 + (1)]) + (left[(1) * 4 + 2] * right[8 + (1)]) + (left[(1) * 4 + 3] * right[12 + (1)]);
    out[(1) * 4 + (2)] = (left[(1) * 4] * right[(2)]) + (left[(1) * 4 + 1] * right[4 + (2)]) + (left[(1) * 4 + 2] * right[8 + (2)]) + (left[(1) * 4 + 3] * right[12 + (2)]);
    out[(1) * 4 + (3)] = (left[(1) * 4] * right[(3)]) + (left[(1) * 4 + 1] * right[4 + (3)]) + (left[(1) * 4 + 2] * right[8 + (3)]) + (left[(1) * 4 + 3] * right[12 + (3)]);
    out[(2) * 4 + (0)] = (left[(2) * 4] * right[(0)]) + (left[(2) * 4 + 1] * right[4 + (0)]) + (left[(2) * 4 + 2] * right[8 + (0)]) + (left[(2) * 4 + 3] * right[12 + (0)]);
    out[(2) * 4 + (1)] = (left[(2) * 4] * right[(1)]) + (left[(2) * 4 + 1] * right[4 + (1)]) + (left[(2) * 4 + 2] * right[8 + (1)]) + (left[(2) * 4 + 3] * right[12 + (1)]);
    out[(2) * 4 + (2)] = (left[(2) * 4] * right[(2)]) + (left[(2) * 4 + 1] * right[4 + (2)]) + (left[(2) * 4 + 2] * right[8 + (2)]) + (left[(2) * 4 + 3] * right[12 + (2)]);
    out[(2) * 4 + (3)] = (left[(2) * 4] * right[(3)]) + (left[(2) * 4 + 1] * right[4 + (3)]) + (left[(2) * 4 + 2] * right[8 + (3)]) + (left[(2) * 4 + 3] * right[12 + (3)]);
    out[(3) * 4 + (0)] = (left[(3) * 4] * right[(0)]) + (left[(3) * 4 + 1] * right[4 + (0)]) + (left[(3) * 4 + 2] * right[8 + (0)]) + (left[(3) * 4 + 3] * right[12 + (0)]);
    out[(3) * 4 + (1)] = (left[(3) * 4] * right[(1)]) + (left[(3) * 4 + 1] * right[4 + (1)]) + (left[(3) * 4 + 2] * right[8 + (1)]) + (left[(3) * 4 + 3] * right[12 + (1)]);
    out[(3) * 4 + (2)] = (left[(3) * 4] * right[(2)]) + (left[(3) * 4 + 1] * right[4 + (2)]) + (left[(3) * 4 + 2] * right[8 + (2)]) + (left[(3) * 4 + 3] * right[12 + (2)]);
    out[(3) * 4 + (3)] = (left[(3) * 4] * right[(3)]) + (left[(3) * 4 + 1] * right[4 + (3)]) + (left[(3) * 4 + 2] * right[8 + (3)]) + (left[(3) * 4 + 3] * right[12 + (3)]);
}

void func_8026FC9C_de(f32 *src, PackedMatrixWords *dst) {
    u32 *upper = dst->upper;
    u32 *lower = dst->lower;
    f32 value;
    s32 a;
    s32 b;
    value = (src[(0) * 2]) * (D_800C46F0_de); if (!(*(&(D_800C46F0_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C46F0_de) + 1)); (a) |= 0x80000000; }; value = (src[(0) * 2 + 1]) * (D_800C46F8_de); if (!(*(&(D_800C46F8_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C46F8_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(1) * 2]) * (D_800C4700_de); if (!(*(&(D_800C4700_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4700_de) + 1)); (a) |= 0x80000000; }; value = (src[(1) * 2 + 1]) * (D_800C4708_de); if (!(*(&(D_800C4708_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4708_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(2) * 2]) * (D_800C4710_de); if (!(*(&(D_800C4710_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4710_de) + 1)); (a) |= 0x80000000; }; value = (src[(2) * 2 + 1]) * (D_800C4718_de); if (!(*(&(D_800C4718_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4718_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(3) * 2]) * (D_800C4720_de); if (!(*(&(D_800C4720_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4720_de) + 1)); (a) |= 0x80000000; }; value = (src[(3) * 2 + 1]) * (D_800C4728_de); if (!(*(&(D_800C4728_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4728_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(4) * 2]) * (D_800C4730_de); if (!(*(&(D_800C4730_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4730_de) + 1)); (a) |= 0x80000000; }; value = (src[(4) * 2 + 1]) * (D_800C4738_de); if (!(*(&(D_800C4738_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4738_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(5) * 2]) * (D_800C4740_de); if (!(*(&(D_800C4740_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4740_de) + 1)); (a) |= 0x80000000; }; value = (src[(5) * 2 + 1]) * (D_800C4748_de); if (!(*(&(D_800C4748_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4748_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(6) * 2]) * (D_800C4750_de); if (!(*(&(D_800C4750_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4750_de) + 1)); (a) |= 0x80000000; }; value = (src[(6) * 2 + 1]) * (D_800C4758_de); if (!(*(&(D_800C4758_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4758_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
    value = (src[(7) * 2]) * (D_800C4760_de); if (!(*(&(D_800C4760_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4760_de) + 1)); (a) |= 0x80000000; }; value = (src[(7) * 2 + 1]) * (D_800C4768_de); if (!(*(&(D_800C4768_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4768_de) + 1)); (b) |= 0x80000000; }; *upper = (a & 0xFFFF0000) | ((u32)b >> 16); *lower = (a << 16) | (b & 0xFFFF); upper++; lower++;
}

void func_8027027C_de(f32 *src, PackedMatrixWords *dst) {
    u32 *upper = dst->upper;
    u32 *lower = dst->lower;
    f32 value;
    s32 a;
    s32 b;
    value = (src[0]) * (D_800C4770_de); if (!(*(&(D_800C4770_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4770_de) + 1)); (a) |= 0x80000000; };
    value = (src[1]) * (D_800C4778_de); if (!(*(&(D_800C4778_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4778_de) + 1)); (b) |= 0x80000000; };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;

    value = (src[2]) * (D_800C4780_de); if (!(*(&(D_800C4780_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4780_de) + 1)); (a) |= 0x80000000; };
    *upper = a & 0xFFFF0000;
    *lower = a << 16;
    upper++;
    lower++;

    value = (src[4]) * (D_800C4788_de); if (!(*(&(D_800C4788_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4788_de) + 1)); (a) |= 0x80000000; };
    value = (src[5]) * (D_800C4790_de); if (!(*(&(D_800C4790_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C4790_de) + 1)); (b) |= 0x80000000; };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;

    value = (src[6]) * (D_800C4798_de); if (!(*(&(D_800C4798_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C4798_de) + 1)); (a) |= 0x80000000; };
    *upper = a & 0xFFFF0000;
    *lower = a << 16;
    upper++;
    lower++;

    value = (src[8]) * (D_800C47A0_de); if (!(*(&(D_800C47A0_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C47A0_de) + 1)); (a) |= 0x80000000; };
    value = (src[9]) * (D_800C47A8_de); if (!(*(&(D_800C47A8_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C47A8_de) + 1)); (b) |= 0x80000000; };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;

    value = (src[10]) * (D_800C47B0_de); if (!(*(&(D_800C47B0_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C47B0_de) + 1)); (a) |= 0x80000000; };
    *upper = a & 0xFFFF0000;
    *lower = a << 16;
    upper++;
    lower++;

    value = (src[12]) * (D_800C47B8_de); if (!(*(&(D_800C47B8_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C47B8_de) + 1)); (a) |= 0x80000000; };
    value = (src[13]) * (D_800C47C0_de); if (!(*(&(D_800C47C0_de) + 1) <= value)) { (b) = (s32)value; } else { (b) = (s32)(value - *(&(D_800C47C0_de) + 1)); (b) |= 0x80000000; };
    *upper = (a & 0xFFFF0000) | ((u32)b >> 16);
    *lower = (a << 16) | (b & 0xFFFF);
    upper++;
    lower++;

    value = (src[14]) * (D_800C47C8_de); if (!(*(&(D_800C47C8_de) + 1) <= value)) { (a) = (s32)value; } else { (a) = (s32)(value - *(&(D_800C47C8_de) + 1)); (a) |= 0x80000000; };
    *upper = (a & 0xFFFF0000) | 1;
    *lower = a << 16;
}

void func_80270700_de(f32 *dst, PackedMatrixWords *src) {
    u32 upper;
    u32 lower;
    f32 scale = D_800C47D0_de;

    upper = src->upper[0]; lower = src->lower[0]; dst[(0) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(0) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[1]; lower = src->lower[1]; dst[(1) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(1) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[2]; lower = src->lower[2]; dst[(2) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(2) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[3]; lower = src->lower[3]; dst[(3) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(3) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[4]; lower = src->lower[4]; dst[(4) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(4) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[5]; lower = src->lower[5]; dst[(5) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(5) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[6]; lower = src->lower[6]; dst[(6) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(6) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[7]; lower = src->lower[7]; dst[(7) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(7) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
}

/* Unpacks a fixed-point 4x4 matrix held as separate integer and fraction halves into floats scaled by D_800C98C4, zeroing the fourth column and setting the last element to D_800C98C8. Adapted from func_80270700_de with the fourth column replaced by zeros and the constant at D_800C98C8, the third-column integer word used unmasked in the first three rows, the scale constant changed, and the last row computed into a local before the corner store. */

void Rsp_ConvertMatrixToFloat(f32 *dst, PackedMatrixWords *src) {
    u32 upper;
    u32 lower;
    f32 scale = D_800C98C4;
    upper = src->upper[0]; lower = src->lower[0]; dst[(0) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(0) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[1]; lower = src->lower[1]; dst[(1) * 2] = (f32)(s32)(upper | (lower >> 16)) * scale; dst[(1) * 2 + 1] = 0.0f;
    upper = src->upper[2]; lower = src->lower[2]; dst[(2) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(2) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[3]; lower = src->lower[3]; dst[(3) * 2] = (f32)(s32)(upper | (lower >> 16)) * scale; dst[(3) * 2 + 1] = 0.0f;
    upper = src->upper[4]; lower = src->lower[4]; dst[(4) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(4) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    upper = src->upper[5]; lower = src->lower[5]; dst[(5) * 2] = (f32)(s32)(upper | (lower >> 16)) * scale; dst[(5) * 2 + 1] = 0.0f;
    upper = src->upper[6]; lower = src->lower[6]; dst[(6) * 2] = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale; dst[(6) * 2 + 1] = (f32)(s32)((upper << 16) | (lower & 0xFFFF)) * scale;
    {
        f32 last;
        upper = src->upper[7];
        lower = src->lower[7];
        last = (f32)(s32)((upper & 0xFFFF0000) | (lower >> 16)) * scale;
        dst[15] = D_800C98C8;
        dst[14] = last;
    }
}




void func_80270AAC_de(CQuatern *out, f32 amount, CQuatern *a, CQuatern *b) {
    CQuatern negative;
    CQuatern *other;
    f32 dot;
    f32 negativeDot;
    f32 angle;
    f32 sine;
    f32 inverseSine;
    f32 scaleA;
    f32 scaleB;

    other = b;
    negative = *b;
    negative.x = -negative.x;
    negative.y = -negative.y;
    negative.z = -negative.z;
    negative.w = -negative.w;

    dot = (a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w);
    negativeDot = (a->x * negative.x) + (a->y * negative.y) +
                  (a->z * negative.z) + (a->w * negative.w);
    if (dot < negativeDot) {
        dot = negativeDot;
        other = &negative;
    }

    angle = Nav_ArcCos(dot);
    sine = func_802B7130_de(angle);
    if (sine == 0.0f) {
        *out = *a;
        return;
    }

    inverseSine = *(&D_800C98C8 + 1) / sine;
    scaleA = func_802B7130_de((*(&D_800C98C8 + 1) - amount) * angle) * inverseSine;
    scaleB = func_802B7130_de(amount * angle) * inverseSine;
    if (dot < negativeDot) {
        other = &negative;
    }

    out->x = (scaleA * a->x) + (scaleB * other->x);
    out->y = (scaleA * a->y) + (scaleB * other->y);
    out->z = (scaleA * a->z) + (scaleB * other->z);
    out->w = (scaleA * a->w) + (scaleB * other->w);
}



extern f32 func_802B72B0_de(f32);

void func_80270CD0_de(CQuatern *out, f32 amount, CQuatern *a, CQuatern *b) {
    CQuatern negative;
    CQuatern *other;
    f32 dot;
    f32 negativeDot;
    f32 angle;
    f32 sine;
    f32 inverseSine;
    f32 scaleA;
    f32 scaleB;

    other = b;
    negative = *b;
    negative.x = -negative.x;
    negative.y = -negative.y;
    negative.z = -negative.z;
    negative.w = -negative.w;

    dot = (a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w);
    negativeDot = (a->x * negative.x) + (a->y * negative.y) +
                  (a->z * negative.z) + (a->w * negative.w);
    if (dot < negativeDot) {
        dot = negativeDot;
        other = &negative;
    }

    if (D_800C47E0_de < dot) {
        f32 magnitude;
        f32 scale;

        out->x = a->x + amount * (other->x - a->x);
        out->y = a->y + amount * (other->y - a->y);
        out->z = a->z + amount * (other->z - a->z);
        out->w = a->w + amount * (other->w - a->w);
        magnitude = func_802B72B0_de((out->x * out->x) + (out->y * out->y) +
                                  (out->z * out->z) + (out->w * out->w));
        if (magnitude != 0.0f) {
            scale = *(&D_800C47E0_de + 1) / magnitude;
            out->x *= scale;
            out->y *= scale;
            out->z *= scale;
            out->w *= scale;
        }
    } else {
        angle = Nav_ArcCos(dot);
        sine = func_802B7130_de(angle);
        if (sine == 0.0f) {
            *out = *a;
            return;
        }

        inverseSine = D_800C47E8_de / sine;
        scaleA = func_802B7130_de((D_800C47E8_de - amount) * angle) * inverseSine;
        scaleB = func_802B7130_de(amount * angle) * inverseSine;
        if (dot < negativeDot) {
            other = &negative;
        }

        out->x = (scaleA * a->x) + (scaleB * other->x);
        out->y = (scaleA * a->y) + (scaleB * other->y);
        out->z = (scaleA * a->z) + (scaleB * other->z);
        out->w = (scaleA * a->w) + (scaleB * other->w);
    }
}

extern s32 func_802744D4_de(void);
extern f32 func_802B72B0_de(f32);

CVector3 func_80270FE8_de(CVector3 *in, f32 amount) {
    CVector3 random;
    CVector3 result;
    CVector3 *randomPtr;
    f32 randomMagnitude;
    f32 randomScale;
    f32 inputMagnitude;
    f32 inputScale;

    random.x = (f32)((func_802744D4_de() % 20000) - 0x2710);
    random.y = (f32)((func_802744D4_de() % 20000) - 0x2710);
    random.z = (f32)((func_802744D4_de() % 20000) - 0x2710);
    randomPtr = &random;

    randomMagnitude = func_802B72B0_de((randomPtr->x * randomPtr->x) +
                                    (randomPtr->y * randomPtr->y) +
                                    (randomPtr->z * randomPtr->z));
    if (randomMagnitude != 0.0f) {
        randomScale = D_800C47EC_de / randomMagnitude;
        randomPtr->x *= randomScale;
        randomPtr->y *= randomScale;
        randomPtr->z *= randomScale;
    }

    inputMagnitude = func_802B72B0_de((in->x * in->x) +
                                   (in->y * in->y) +
                                   (in->z * in->z));
    if (inputMagnitude != 0.0f) {
        inputScale = D_800C47F0_de / inputMagnitude;
        in->x *= inputScale;
        in->y *= inputScale;
        in->z *= inputScale;
    }

    result.x = in->x + amount * (randomPtr->x - in->x);
    result.y = in->y + amount * (randomPtr->y - in->y);
    result.z = in->z + amount * (randomPtr->z - in->z);
    return result;
}

extern s32 func_802744D4_de(void);
extern f32 func_802B72B0_de(f32);

CVector3 func_80271248_de(CVector3 *in, f32 amount) {
    CVector3 random;
    CVector3 result;
    CVector3 *randomPtr;
    f32 randomMagnitude;
    f32 randomScale;
    f32 inputMagnitude;
    f32 inputScale;

    random.x = (f32)((func_802744D4_de() % 20000) - 0x2710) *
               *(&D_800C47F0_de + 1);
    random.y = in->y;
    random.z = in->z;
    randomPtr = &random;

    randomMagnitude = func_802B72B0_de((randomPtr->x * randomPtr->x) +
                                    (randomPtr->y * randomPtr->y) +
                                    (randomPtr->z * randomPtr->z));
    if (randomMagnitude != 0.0f) {
        randomScale = D_800C47F8_de / randomMagnitude;
        randomPtr->x *= randomScale;
        randomPtr->y *= randomScale;
        randomPtr->z *= randomScale;
    }

    inputMagnitude = func_802B72B0_de((in->x * in->x) +
                                   (in->y * in->y) +
                                   (in->z * in->z));
    if (inputMagnitude != 0.0f) {
        inputScale = *(&D_800C47F8_de + 1) / inputMagnitude;
        in->x *= inputScale;
        in->y *= inputScale;
        in->z *= inputScale;
    }

    result.x = in->x + amount * (randomPtr->x - in->x);
    result.y = in->y + amount * (randomPtr->y - in->y);
    result.z = in->z + amount * (randomPtr->z - in->z);
    return result;
}

extern s32 func_802744D4_de(void);
extern f32 func_802B72B0_de(f32);

CVector3 func_80271430_de(CVector3 *in, f32 amount) {
    CVector3 random;
    CVector3 result;
    CVector3 *randomPtr;
    f32 randomMagnitude;
    f32 randomScale;
    f32 inputMagnitude;
    f32 inputScale;

    random.x = in->x;
    random.y = ((f32)(func_802744D4_de() % 20000) - D_800C4800_de) * *(&D_800C4800_de + 1);
    random.z = in->z;
    randomPtr = &random;

    randomMagnitude = func_802B72B0_de((randomPtr->x * randomPtr->x) +
                                    (randomPtr->y * randomPtr->y) +
                                    (randomPtr->z * randomPtr->z));
    if (randomMagnitude != 0.0f) {
        randomScale = D_800C4808_de / randomMagnitude;
        randomPtr->x *= randomScale;
        randomPtr->y *= randomScale;
        randomPtr->z *= randomScale;
    }

    inputMagnitude = func_802B72B0_de((in->x * in->x) +
                                   (in->y * in->y) +
                                   (in->z * in->z));
    if (inputMagnitude != 0.0f) {
        inputScale = *(&D_800C4808_de + 1) / inputMagnitude;
        in->x *= inputScale;
        in->y *= inputScale;
        in->z *= inputScale;
    }

    result.x = in->x + amount * (randomPtr->x - in->x);
    result.y = in->y + amount * (randomPtr->y - in->y);
    result.z = in->z + amount * (randomPtr->z - in->z);
    return result;
}

extern s32 func_802744D4_de(void);
extern f32 func_802B72B0_de(f32);

CVector3 *func_80271624_de(CVector3 *out, CVector3 *in, f32 amount) {
    CVector3 random;
    CVector3 result;
    CVector3 *randomPtr;

    random.x = in->x;
    random.y = in->y;
    random.z = ((f32)(func_802744D4_de() % 20000) - D_800C4810_de) *
               *(&D_800C4810_de + 1);

    randomPtr = &random;
    {
        f32 magnitude;
        f32 scale;

        magnitude = func_802B72B0_de((randomPtr->x * randomPtr->x) +
                                  (randomPtr->y * randomPtr->y) +
                                  (randomPtr->z * randomPtr->z));
        if (magnitude != 0.0f) {
            scale = D_800C4818_de / magnitude;
            randomPtr->x *= scale;
            randomPtr->y *= scale;
            randomPtr->z *= scale;
        }
    }
    {
        f32 magnitude;
        f32 scale;

        magnitude = func_802B72B0_de((in->x * in->x) +
                                  (in->y * in->y) +
                                  (in->z * in->z));
        if (magnitude != 0.0f) {
            scale = *(&D_800C4818_de + 1) / magnitude;
            in->x *= scale;
            in->y *= scale;
            in->z *= scale;
        }
    }

    result.x = in->x + amount * (randomPtr->x - in->x);
    result.y = in->y + amount * (randomPtr->y - in->y);
    result.z = in->z + amount * (randomPtr->z - in->z);
    *out = result;
    return out;
}

extern f32 D_80115DEC;

extern f32 func_802B72B0_de(f32);




CQuatern func_80271818_de(CVector3 *input) {
    CQuatern result;
    CVector3 normalized;
    CVector3 basis;
    CVector3 axis;
    f32 magnitude;
    f32 angle;
    f32 axisMagnitude;

    magnitude = func_802B72B0_de((input->x * input->x) +
                              (input->y * input->y) +
                              (input->z * input->z));
    if (magnitude == 0.0f) {
        result.z = 0.0f;
        result.y = 0.0f;
        result.x = 0.0f;
        result.w = D_800C4820_de;
    } else {
        f32 normalizationScale;

        normalizationScale = D_800C4824_de / magnitude;
        normalized.x = input->x * normalizationScale;
        normalized.y = input->y * normalizationScale;
        normalized.z = input->z * normalizationScale;

        basis.x = 0.0f;
        basis.y = 0.0f;
        basis.z = D_800C4824_de;

        if (normalized.z < 0.0f) {
            if (D_800C4828_de < -normalized.z) {
                goto pole;
            }
            goto general;
        }
        if (D_800C482C_de < normalized.z) {
pole:
        {
            f32 halfAngle;
            f32 scale;

            halfAngle = 0.0f;
            scale = func_802B7130_de(halfAngle);
            result.z = normalized.z * scale;
            D_80115DEC = scale;
            result.x = halfAngle;
            result.y = halfAngle;
            result.w = func_802B6560_de(halfAngle);
        }
        } else {
general:
        {
            f32 halfAngle;
            f32 scale;

            angle = Nav_ArcCos((normalized.x * basis.x) +
                                  (normalized.y * basis.y) +
                                  (normalized.z * basis.z));
            axis.x = (basis.y * normalized.z) - (basis.z * normalized.y);
            axis.y = (basis.z * normalized.x) - (basis.x * normalized.z);
            axis.z = (basis.x * normalized.y) - (basis.y * normalized.x);

            axisMagnitude = func_802B72B0_de((axis.x * axis.x) +
                                          (axis.y * axis.y) +
                                          (axis.z * axis.z));
            if (axisMagnitude != 0.0f) {
                f32 axisScale;

                axisScale = D_800C4830_de / axisMagnitude;
                axis.x *= axisScale;
                axis.y *= axisScale;
                axis.z *= axisScale;
            }

            halfAngle = angle * D_800C4834_de;
            scale = func_802B7130_de(halfAngle);
            result.x = axis.x * scale;
            result.y = axis.y * scale;
            result.z = axis.z * scale;
            D_80115DEC = scale;
            result.w = func_802B6560_de(halfAngle);
        }
        }
    }
    return result;
}
#endif
