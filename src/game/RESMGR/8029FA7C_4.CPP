#include "COMMON/MATRIXRECORD.H"
#include "RESMGR/8029FA7C.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "RESMGR/8029FA7C_4.H"
#include "RESMGR/resmgr_string_memory.H"
extern void MatrixFromAngles(f32 *matrix, f32 *angles);


void func_8029EA7C_de(MatrixRecord *arg0, float arg1, float arg2, float arg3,
                    float arg4, float arg5, float arg6, float arg7,
                    float arg8, float arg9, float arg10, float arg11,
                    float arg12, float arg13, float arg14, float arg15, float arg16) {
    arg0->matrix.m[0] = arg1;
    arg0->matrix.m[4] = arg2;
    arg0->matrix.m[8] = arg3;
    arg0->matrix.m[12] = arg4;
    arg0->matrix.m[1] = arg5;
    arg0->matrix.m[5] = arg6;
    arg0->matrix.m[9] = arg7;
    arg0->matrix.m[13] = arg8;
    arg0->matrix.m[2] = arg9;
    arg0->matrix.m[6] = arg10;
    arg0->matrix.m[10] = arg11;
    arg0->matrix.m[14] = arg12;
    arg0->matrix.m[3] = arg13;
    arg0->matrix.m[7] = arg14;
    arg0->matrix.m[11] = arg15;
    arg0->matrix.m[15] = arg16;
}

void func_8029EAF4_de(s32 arg0) {
    Resmgr_FillBytes(arg0, 0, 0x40);
}

void func_8029EB14_de(s32 arg0)
{
  Resmgr_FillBytes(arg0, 0, 0x40);
  ((Matrix *)(arg0))->m[15] = (((Matrix *)(arg0))->m[10] = (((Matrix *)(arg0))->m[5] = (((Matrix *)(arg0))->m[0] = (f32) D_800C5CB8_de)));
}

void func_8029EB58_de(f32 *arg0) {
    s32 i;
    s32 j;
    s32 offset1;
    s32 offset2;
    f32 temp;

    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            offset2 = j * 16 + i * 4;
            offset1 = i * 16 + j * 4;
            temp = *(f32 *)((u8 *)arg0 + offset2);
            *(f32 *)((u8 *)arg0 + offset2) =
                *(f32 *)((u8 *)arg0 + offset1);
            *(f32 *)((u8 *)arg0 + offset1) = temp;
        }
    }
}

/** Scatter three floats from arg1 into arg0's fields. */
void func_8029EBC8_de(Matrix *matrix, CVector3 *arg1) {
    matrix->m[0] = arg1->x;
    matrix->m[5] = arg1->y;
    matrix->m[10] = arg1->z;
}

void func_8029EBE4_de(void *arg0, void *arg1) {
    char *m = (char *) arg0;
    char *v = (char *) arg1;

    ((Matrix *)(m))->m[0] = ((Matrix *)(m))->m[0] * ((CVector3 *)(v))->x;
    ((Matrix *)(m))->m[4] = ((Matrix *)(m))->m[4] * ((CVector3 *)(v))->x;
    ((Matrix *)(m))->m[8] = ((Matrix *)(m))->m[8] * ((CVector3 *)(v))->x;
    ((Matrix *)(m))->m[1] = ((Matrix *)(m))->m[1] * ((CVector3 *)(v))->y;
    ((Matrix *)(m))->m[5] = ((Matrix *)(m))->m[5] * ((CVector3 *)(v))->y;
    ((Matrix *)(m))->m[9] = ((Matrix *)(m))->m[9] * ((CVector3 *)(v))->y;
    ((Matrix *)(m))->m[2] = ((Matrix *)(m))->m[2] * ((CVector3 *)(v))->z;
    ((Matrix *)(m))->m[6] = ((Matrix *)(m))->m[6] * ((CVector3 *)(v))->z;
    ((Matrix *)(m))->m[10] = ((Matrix *)(m))->m[10] * ((CVector3 *)(v))->z;
    ((Matrix *)(m))->m[12] = ((Matrix *)(m))->m[12] * ((CVector3 *)(v))->x;
    ((Matrix *)(m))->m[13] = ((Matrix *)(m))->m[13] * ((CVector3 *)(v))->y;
    ((Matrix *)(m))->m[14] = ((Matrix *)(m))->m[14] * ((CVector3 *)(v))->z;
}

/** Broadcast a float value into three fields of the object. */
void func_8029ECA8_de(Matrix *matrix, float value) {
    matrix->m[0] = value;
    matrix->m[5] = value;
    matrix->m[10] = value;
}

void func_8029ECBC_de(void *arg0, f32 arg1) {
    u8 *o = (u8 *)arg0;

    ((Matrix *)(o))->m[0] = ((Matrix *)(o))->m[0] * arg1;
    ((Matrix *)(o))->m[4] = ((Matrix *)(o))->m[4] * arg1;
    ((Matrix *)(o))->m[8] = ((Matrix *)(o))->m[8] * arg1;
    ((Matrix *)(o))->m[1] = ((Matrix *)(o))->m[1] * arg1;
    ((Matrix *)(o))->m[5] = ((Matrix *)(o))->m[5] * arg1;
    ((Matrix *)(o))->m[9] = ((Matrix *)(o))->m[9] * arg1;
    ((Matrix *)(o))->m[2] = ((Matrix *)(o))->m[2] * arg1;
    ((Matrix *)(o))->m[6] = ((Matrix *)(o))->m[6] * arg1;
    ((Matrix *)(o))->m[10] = ((Matrix *)(o))->m[10] * arg1;
    ((Matrix *)(o))->m[12] = ((Matrix *)(o))->m[12] * arg1;
    ((Matrix *)(o))->m[13] = ((Matrix *)(o))->m[13] * arg1;
    ((Matrix *)(o))->m[14] = ((Matrix *)(o))->m[14] * arg1;
}

void func_8029ED54_de(Mtx3x4_8029FD54 *arg0) {
    s32 col;
    s32 row;

    col = 0;
    row = 0;
    do {
        row = 0;
        do {
            arg0->m[row][col] = 0;
            row += 1;
        } while (row < 3);
        col += 1;
    } while (col < 3);
    arg0->m[0][0] = D_800C5CBC_de;
    arg0->m[1][1] = D_800C5CBC_de;
    arg0->m[2][2] = D_800C5CBC_de;
}

void func_8029EDA0_de(s32 arg0, f32 *angles) {
    f32 buf[16];
    MatrixFromAngles(buf, angles);
    func_8029CE3C_de(arg0, buf, arg0);
}

void func_8029EDD8_de(s32 arg0, f32 arg1) {
    Matrix matrix;
    f32 sp50;
    f32 sp54;
    Matrix *p;

    if (arg1 != 0.0f) {
        func_8029BBB0_de(arg1, &sp50, &sp54);
        p = &matrix;
        Resmgr_FillBytes(p, 0, 0x40);
        ((Matrix *)(p))->m[0] = D_800C5CC0_de;
        {
            f32 t54 = sp54;
            f32 t50 = sp50;
            ((Matrix *)(p))->m[5] = D_800C5CC0_de;
            ((Matrix *)(p))->m[10] = D_800C5CC0_de;
            ((Matrix *)(p))->m[15] = D_800C5CC0_de;
            matrix.m[5] = t54;
            matrix.m[9] = -t50;
            matrix.m[6] = t50;
            matrix.m[10] = t54;
        }
        func_8029CE3C_de(arg0, (s32) p, arg0);
    }
}

void func_8029EE78_de(s32 arg0, f32 arg1) {
    Matrix matrix;
    f32 sp50;
    f32 sp54;
    Matrix *p;

    if (arg1 != 0.0f) {
        func_8029BBB0_de(arg1, &sp50, &sp54);
        p = &matrix;
        Resmgr_FillBytes(p, 0, 0x40);
        ((Matrix *)(p))->m[0] = D_800C5CC4_de;
        {
            f32 t54 = sp54;
            f32 t50 = sp50;
            f32 t50n;
            ((Matrix *)(p))->m[5] = D_800C5CC4_de;
            ((Matrix *)(p))->m[10] = D_800C5CC4_de;
            ((Matrix *)(p))->m[15] = D_800C5CC4_de;
            t50n = -t50;
            matrix.m[8] = t50;
            matrix.m[0] = t54;
            matrix.m[2] = t50n;
            matrix.m[10] = t54;
        }
        func_8029CE3C_de(arg0, (s32) p, arg0);
    }
}

void func_8029EF18_de(s32 arg0, f32 arg1) {
    Matrix matrix;
    f32 sp50;
    f32 sp54;
    Matrix *p;

    if (arg1 != 0.0f) {
        func_8029BBB0_de(arg1, &sp50, &sp54);
        p = &matrix;
        Resmgr_FillBytes(p, 0, 0x40);
        ((Matrix *)(p))->m[0] = D_800C5CC8_de;
        {
            f32 t54 = sp54;
            f32 t50 = sp50;
            f32 t50n;
            ((Matrix *)(p))->m[5] = D_800C5CC8_de;
            ((Matrix *)(p))->m[10] = D_800C5CC8_de;
            ((Matrix *)(p))->m[15] = D_800C5CC8_de;
            t50n = -t50;
            matrix.m[0] = t54;
            matrix.m[4] = t50n;
            matrix.m[1] = t50;
            matrix.m[5] = t54;
        }
        func_8029CE3C_de(arg0, (s32) p, arg0);
    }
}

/** Clear the three words at object offsets 0x30 through 0x38. */
void func_8029EFB8_de(Matrix *matrix) {
    matrix->m[12] = 0;
    matrix->m[13] = 0;
    matrix->m[14] = 0;
}

/** Copy a three-float vector into object offsets 0x30 through 0x38. */
void func_8029EFC8_de(Matrix *matrix, float *arg1) {
    matrix->m[12] = arg1[0];
    matrix->m[13] = arg1[1];
    matrix->m[14] = arg1[2];
}

/** Copy the three floating components at offset 0x30. */
void func_8029EFE4_de(char *object, float *output) {
    output[0] = ((Matrix *)(object))->m[12];
    output[1] = ((Matrix *)(object))->m[13];
    output[2] = ((Matrix *)(object))->m[14];
}

void func_8029F000_de(Matrix *matrix, void *arg1) {
    (matrix->m[12]) = (f32) ((matrix->m[12]) + (((struct CVector3_t *) ((s8 *) arg1))->x));
    (matrix->m[13]) = (f32) ((matrix->m[13]) + (((struct CVector3_t *) ((s8 *) arg1))->y));
    (matrix->m[14]) = (f32) ((matrix->m[14]) + (((struct CVector3_t *) ((s8 *) arg1))->z));
}

/** Combine three column vectors into the first three matrix columns. */
void func_8029F034_de(float *arg0, float *arg1, float *arg2, float *arg3) {
    arg0[0] = arg1[0];
    arg0[4] = arg1[1];
    arg0[8] = arg1[2];
    arg0[1] = arg2[0];
    arg0[5] = arg2[1];
    arg0[9] = arg2[2];
    arg0[2] = arg3[0];
    arg0[6] = arg3[1];
    arg0[10] = arg3[2];
}

/** Split the first three matrix columns into three vectors. */
void func_8029F080_de(float *arg0, float *arg1, float *arg2, float *arg3) {
    arg1[0] = arg0[0];
    arg1[1] = arg0[4];
    arg1[2] = arg0[8];
    arg2[0] = arg0[1];
    arg2[1] = arg0[5];
    arg2[2] = arg0[9];
    arg3[0] = arg0[2];
    arg3[1] = arg0[6];
    arg3[2] = arg0[10];
}

/** Write three row vectors into the first three matrix rows. */
void func_8029F0CC_de(float *arg0, float *arg1, float *arg2, float *arg3) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    arg0[4] = arg2[0];
    arg0[5] = arg2[1];
    arg0[6] = arg2[2];
    arg0[8] = arg3[0];
    arg0[9] = arg3[1];
    arg0[10] = arg3[2];
}

/** Split the first three matrix rows into three row vectors. */
void func_8029F118_de(float *arg0, float *arg1, float *arg2, float *arg3) {
    arg1[0] = arg0[0];
    arg1[1] = arg0[1];
    arg1[2] = arg0[2];
    arg2[0] = arg0[4];
    arg2[1] = arg0[5];
    arg2[2] = arg0[6];
    arg3[0] = arg0[8];
    arg3[1] = arg0[9];
    arg3[2] = arg0[10];
}

/** Thin wrapper forwarding arg0 twice (as first and third args) to func_8029CE3C_de. */
void func_8029F164_de(int arg0, int arg1) {
    func_8029CE3C_de(arg0, arg1, arg0);
}

void func_8029F180_de(s32 arg0, s32 arg1) {
    func_8029CE3C_de(arg0, arg0, arg1);
}

void func_8029F1A0_de(void *arg0, void *arg1, void *arg2, s32 arg3) {
    u8 *m = (u8 *) arg0;
    s32 i;
    f32 vx, vy, vz;

    i = 0;
    if (arg3 > 0) {
        do {
            u8 *v = (u8 *) arg2 + i * 0xC;
            u8 *out = (u8 *) arg1 + i * 0xC;

            vx = ((CVector3 *)(v))->x;
            vy = ((CVector3 *)(v))->y;
            vz = ((CVector3 *)(v))->z;
            ((CVector3 *)(out))->x = (((Matrix *)(m))->m[0] * vx) + (((Matrix *)(m))->m[4] * vy) + (((Matrix *)(m))->m[8] * vz) + ((Matrix *)(m))->m[12];
            ((CVector3 *)(out))->y = (((Matrix *)(m))->m[1] * vx) + (((Matrix *)(m))->m[5] * vy) + (((Matrix *)(m))->m[9] * vz) + ((Matrix *)(m))->m[13];
            ((CVector3 *)(out))->z = (((Matrix *)(m))->m[2] * vx) + (((Matrix *)(m))->m[6] * vy) + (((Matrix *)(m))->m[10] * vz) + ((Matrix *)(m))->m[14];
            i += 1;
        } while (i < arg3);
    }
}

void func_8029F254_de(struct MatrixF *matrixF, CVector3 *arg1, f32 arg2) {
    f32 sine;
    f32 cosine;
    f32 cosine_value;
    f32 one;
    f32 one_minus_cosine;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 txx;
    f32 txy;
    f32 txz;
    f32 tyy;
    f32 tyz;
    f32 tzz;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 zero;

    func_8029BBB0_de(arg2, &sine, &cosine);
    cosine_value = cosine;
    one = D_800C5CCC_de;
    one_minus_cosine = one - cosine_value;
    tx = one_minus_cosine * arg1->x;
    ty = one_minus_cosine * arg1->y;
    tz = one_minus_cosine * arg1->z;
    txx = tx * arg1->x;
    txy = tx * arg1->y;
    txz = tx * arg1->z;
    tyy = ty * arg1->y;
    tyz = ty * arg1->z;
    tzz = tz * arg1->z;
    sx = sine * arg1->x;
    sy = sine * arg1->y;
    sz = sine * arg1->z;
    zero = 0.0f;
    matrixF->m[3][2] = zero;
    matrixF->m[3][1] = zero;
    matrixF->m[3][0] = zero;
    matrixF->m[2][3] = zero;
    matrixF->m[1][3] = zero;
    matrixF->m[0][3] = zero;
    matrixF->m[3][3] = one;
    matrixF->m[0][0] = txx + cosine_value;
    matrixF->m[0][1] = txy + sz;
    matrixF->m[0][2] = txz - sy;
    matrixF->m[1][0] = txy - sz;
    matrixF->m[1][1] = tyy + cosine_value;
    matrixF->m[1][2] = tyz + sx;
    matrixF->m[2][0] = txz + sy;
    matrixF->m[2][1] = tyz - sx;
    matrixF->m[2][2] = tzz + cosine_value;
}

void func_8029F368_de(void *matrix, CVector3 *arg1, void *angles, CVector3 *arg3) {
    Matrix *m = matrix;

    MatrixFromAngles(matrix, angles);

    m->m[0] = m->m[0] * arg1->x;
    m->m[1] = m->m[1] * arg1->x;
    m->m[2] = m->m[2] * arg1->x;
    m->m[4] = m->m[4] * arg1->y;
    m->m[5] = m->m[5] * arg1->y;
    m->m[6] = m->m[6] * arg1->y;
    m->m[8] = m->m[8] * arg1->z;
    m->m[9] = m->m[9] * arg1->z;
    m->m[10] = m->m[10] * arg1->z;
    m->m[12] = m->m[12] + arg3->x;
    m->m[13] = m->m[13] + arg3->y;
    m->m[14] = m->m[14] + arg3->z;
}
