#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8029F3A8.h"
#include "types.h"

void func_8029EA7C_de(void *arg0, float arg1, float arg2, float arg3,
                    float arg4, float arg5, float arg6, float arg7,
                    float arg8, float arg9, float arg10, float arg11,
                    float arg12, float arg13, float arg14, float arg15, float arg16) {
    ((MatrixRecord *)(arg0))->matrix.m[0] = arg1;
    ((MatrixRecord *)(arg0))->matrix.m[4] = arg2;
    ((MatrixRecord *)(arg0))->matrix.m[8] = arg3;
    ((MatrixRecord *)(arg0))->matrix.m[12] = arg4;
    ((MatrixRecord *)(arg0))->matrix.m[1] = arg5;
    ((MatrixRecord *)(arg0))->matrix.m[5] = arg6;
    ((MatrixRecord *)(arg0))->matrix.m[9] = arg7;
    ((MatrixRecord *)(arg0))->matrix.m[13] = arg8;
    ((MatrixRecord *)(arg0))->matrix.m[2] = arg9;
    ((MatrixRecord *)(arg0))->matrix.m[6] = arg10;
    ((MatrixRecord *)(arg0))->matrix.m[10] = arg11;
    ((MatrixRecord *)(arg0))->matrix.m[14] = arg12;
    ((MatrixRecord *)(arg0))->matrix.m[3] = arg13;
    ((MatrixRecord *)(arg0))->matrix.m[7] = arg14;
    ((MatrixRecord *)(arg0))->matrix.m[11] = arg15;
    ((MatrixRecord *)(arg0))->matrix.m[15] = arg16;
}

void func_8029EAF4_de(s32 arg0) {
    func_802A0748_de(arg0, 0, 0x40);
}

void func_8029EB14_de(s32 arg0)
{
  func_802A0748_de(arg0, 0, 0x40);
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
void func_8029EBC8_de(void *arg0, void *arg1) {
    ((Matrix *)(arg0))->m[0] = ((Vec3 *)(arg1))->x;
    ((Matrix *)(arg0))->m[5] = ((Vec3 *)(arg1))->y;
    ((Matrix *)(arg0))->m[10] = ((Vec3 *)(arg1))->z;
}

void func_8029EBE4_de(void *arg0, void *arg1) {
    char *m = (char *) arg0;
    char *v = (char *) arg1;

    ((Matrix *)(m))->m[0] = ((Matrix *)(m))->m[0] * ((Vec3 *)(v))->x;
    ((Matrix *)(m))->m[4] = ((Matrix *)(m))->m[4] * ((Vec3 *)(v))->x;
    ((Matrix *)(m))->m[8] = ((Matrix *)(m))->m[8] * ((Vec3 *)(v))->x;
    ((Matrix *)(m))->m[1] = ((Matrix *)(m))->m[1] * ((Vec3 *)(v))->y;
    ((Matrix *)(m))->m[5] = ((Matrix *)(m))->m[5] * ((Vec3 *)(v))->y;
    ((Matrix *)(m))->m[9] = ((Matrix *)(m))->m[9] * ((Vec3 *)(v))->y;
    ((Matrix *)(m))->m[2] = ((Matrix *)(m))->m[2] * ((Vec3 *)(v))->z;
    ((Matrix *)(m))->m[6] = ((Matrix *)(m))->m[6] * ((Vec3 *)(v))->z;
    ((Matrix *)(m))->m[10] = ((Matrix *)(m))->m[10] * ((Vec3 *)(v))->z;
    ((Matrix *)(m))->m[12] = ((Matrix *)(m))->m[12] * ((Vec3 *)(v))->x;
    ((Matrix *)(m))->m[13] = ((Matrix *)(m))->m[13] * ((Vec3 *)(v))->y;
    ((Matrix *)(m))->m[14] = ((Matrix *)(m))->m[14] * ((Vec3 *)(v))->z;
}

/** Broadcast a float value into three fields of the object. */
void func_8029ECA8_de(void *arg0, float value) {
    ((Matrix *)(arg0))->m[0] = value;
    ((Matrix *)(arg0))->m[5] = value;
    ((Matrix *)(arg0))->m[10] = value;
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

extern void func_8029C6A8_de(void *);


void func_8029EDA0_de(s32 arg0) {
    char buf[0x40];
    func_8029C6A8_de(buf);
    func_8029CE3C_de(arg0, buf, arg0);
}


extern void func_802A0748_de(s32, s32, s32);


void func_8029EDD8_de(s32 arg0, f32 arg1) {
    Matrix sp10;
    f32 sp50;
    f32 sp54;
    Matrix *p;

    if (arg1 != 0.0f) {
        func_8029BBB0_de(arg1, &sp50, &sp54);
        p = &sp10;
        func_802A0748_de((s32) p, 0, 0x40);
        ((Matrix *)(p))->m[0] = D_800C5CC0_de;
        {
            f32 t54 = sp54;
            f32 t50 = sp50;
            ((Matrix *)(p))->m[5] = D_800C5CC0_de;
            ((Matrix *)(p))->m[10] = D_800C5CC0_de;
            ((Matrix *)(p))->m[15] = D_800C5CC0_de;
            sp10.m[5] = t54;
            sp10.m[9] = -t50;
            sp10.m[6] = t50;
            sp10.m[10] = t54;
        }
        func_8029CE3C_de(arg0, (s32) p, arg0);
    }
}


extern void func_802A0748_de(s32, s32, s32);


void func_8029EE78_de(s32 arg0, f32 arg1) {
    Matrix sp10;
    f32 sp50;
    f32 sp54;
    Matrix *p;

    if (arg1 != 0.0f) {
        func_8029BBB0_de(arg1, &sp50, &sp54);
        p = &sp10;
        func_802A0748_de((s32) p, 0, 0x40);
        ((Matrix *)(p))->m[0] = D_800C5CC4_de;
        {
            f32 t54 = sp54;
            f32 t50 = sp50;
            f32 t50n;
            ((Matrix *)(p))->m[5] = D_800C5CC4_de;
            ((Matrix *)(p))->m[10] = D_800C5CC4_de;
            ((Matrix *)(p))->m[15] = D_800C5CC4_de;
            t50n = -t50;
            sp10.m[8] = t50;
            sp10.m[0] = t54;
            sp10.m[2] = t50n;
            sp10.m[10] = t54;
        }
        func_8029CE3C_de(arg0, (s32) p, arg0);
    }
}


extern void func_802A0748_de(s32, s32, s32);


void func_8029EF18_de(s32 arg0, f32 arg1) {
    Matrix sp10;
    f32 sp50;
    f32 sp54;
    Matrix *p;

    if (arg1 != 0.0f) {
        func_8029BBB0_de(arg1, &sp50, &sp54);
        p = &sp10;
        func_802A0748_de((s32) p, 0, 0x40);
        ((Matrix *)(p))->m[0] = D_800C5CC8_de;
        {
            f32 t54 = sp54;
            f32 t50 = sp50;
            f32 t50n;
            ((Matrix *)(p))->m[5] = D_800C5CC8_de;
            ((Matrix *)(p))->m[10] = D_800C5CC8_de;
            ((Matrix *)(p))->m[15] = D_800C5CC8_de;
            t50n = -t50;
            sp10.m[0] = t54;
            sp10.m[4] = t50n;
            sp10.m[1] = t50;
            sp10.m[5] = t54;
        }
        func_8029CE3C_de(arg0, (s32) p, arg0);
    }
}

/** Clear the three words at object offsets 0x30 through 0x38. */
void func_8029EFB8_de(void *arg0) {
    ((Matrix *)(arg0))->m[12] = 0;
    ((Matrix *)(arg0))->m[13] = 0;
    ((Matrix *)(arg0))->m[14] = 0;
}

/** Copy a three-float vector into object offsets 0x30 through 0x38. */
void func_8029EFC8_de(void *arg0, float *arg1) {
    ((Matrix *)(arg0))->m[12] = arg1[0];
    ((Matrix *)(arg0))->m[13] = arg1[1];
    ((Matrix *)(arg0))->m[14] = arg1[2];
}

/** Copy the three floating components at offset 0x30. */
void func_8029EFE4_de(char *object, float *output) {
    output[0] = ((Matrix *)(object))->m[12];
    output[1] = ((Matrix *)(object))->m[13];
    output[2] = ((Matrix *)(object))->m[14];
}

void func_8029F000_de(void *arg0, void *arg1) {
    (((Matrix *)arg0)->m[12]) = (f32) ((((Matrix *)arg0)->m[12]) + (((struct Vec3 *) ((s8 *) arg1))->x));
    (((Matrix *)arg0)->m[13]) = (f32) ((((Matrix *)arg0)->m[13]) + (((struct Vec3 *) ((s8 *) arg1))->y));
    (((Matrix *)arg0)->m[14]) = (f32) ((((Matrix *)arg0)->m[14]) + (((struct Vec3 *) ((s8 *) arg1))->z));
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

            vx = ((Vec3 *)(v))->x;
            vy = ((Vec3 *)(v))->y;
            vz = ((Vec3 *)(v))->z;
            ((Vec3 *)(out))->x = (((Matrix *)(m))->m[0] * vx) + (((Matrix *)(m))->m[4] * vy) + (((Matrix *)(m))->m[8] * vz) + ((Matrix *)(m))->m[12];
            ((Vec3 *)(out))->y = (((Matrix *)(m))->m[1] * vx) + (((Matrix *)(m))->m[5] * vy) + (((Matrix *)(m))->m[9] * vz) + ((Matrix *)(m))->m[13];
            ((Vec3 *)(out))->z = (((Matrix *)(m))->m[2] * vx) + (((Matrix *)(m))->m[6] * vy) + (((Matrix *)(m))->m[10] * vz) + ((Matrix *)(m))->m[14];
            i += 1;
        } while (i < arg3);
    }
}
