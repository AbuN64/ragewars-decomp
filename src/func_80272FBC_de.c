#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027302C.h"
#include "types.h"

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

void func_8027310C_de(void *arg0, void *arg1, f32 arg2) {
    Vec3 *direction = arg1;
    Matrix *o = arg0;
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
    o->m[13] = arg2;
    o->m[5] = zero;
    o->m[4] = -temp_f2;
    o->m[6] = -temp_f1;
    o->m[12] = arg2 * temp_f2;
    o->m[14] = arg2 * temp_f1;
}

/* Builds an orientation matrix whose third row is the given direction: the first row is the cross product of the up vector D_800C97B4 with it, or the X axis when the direction is within the vertical thresholds, the second row is the cross product of the first row with it, all three rows are normalised and the rest is identity. */





extern Vec3 D_800C46C0_de[2];


extern func_8020CA10_G1 D_800C48E8_de;


extern void func_80272018_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern void func_8027207C_de(Vec3 *v);




void func_80273198_de(Mtx *m, Vec3 *direction) {
    Vec3 up;
    Vec3 *upVector = (void *)&D_800C46C0_de[0].y;

    up = *upVector;
    if (direction->y < 0.0f ? (&D_800C48E0_de)[1] <= -direction->y : D_800C48E8_de.unk0 <= direction->y) {
        m->right.y = 0;
        m->right.z = 0;
        m->right.x = D_800C48EC_de;
    } else {
        func_80272018_de(&m->right, &up, direction);
    }
    func_80272018_de(&m->up, &m->right, direction);
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

extern f32 func_802B72B0_de(f32);




void func_802732EC_de(void *arg0, f32 *arg1) {
    Matrix *m = arg0;
    Vec3 tmp;

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

void func_802733B4_de(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    Matrix *o = arg0;

    o->m[12] = o->m[12] + (arg1 * o->m[0] + arg2 * o->m[4] + arg3 * o->m[8]);
    o->m[13] = o->m[13] + (arg1 * o->m[1] + arg2 * o->m[5] + arg3 * o->m[9]);
    o->m[14] = o->m[14] + (arg1 * o->m[2] + arg2 * o->m[6] + arg3 * o->m[10]);
}

/** Add three floating arguments to the vector at offset 0x30. */
void func_80273448_de(char *object, float x, float y, float z) {
    Matrix *matrix = (void *)object;
    matrix->m[12] += x;
    matrix->m[13] += y;
    matrix->m[14] += z;
}

/** Scale the first three rows of a matrix's basis columns by sx, sy, sz. */
void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz) {
    Matrix *o = arg0;

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

/* Copies a 4x4 float matrix while scaling its first three rows by three per-row factors, zeroing their fourth column and setting the last element to the canonical unit constant. Adapted from func_8027302C with the row scaling, the zeroed column and the constant corner changed. */
extern f32 D_800C48F4_de;

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
void func_802735A8_de(void *arg0, f32 sx, f32 sy, f32 sz) {
    Matrix *o = arg0;

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
