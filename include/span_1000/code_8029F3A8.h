#ifndef UNBAKE_SPAN_1000_CODE_8029F3A8_H
#define UNBAKE_SPAN_1000_CODE_8029F3A8_H
#include "types.h"
#include "common/types_8a8189af7b05.h"

/* Matrix constructor record: four header words precede the 4x4 matrix. */
typedef struct MatrixRecord {
    u32 header[4];
    Matrix matrix;
} MatrixRecord;
extern float D_800C5CC0_de;

struct FloatState18;
struct FloatState18 {
    f32 unk_0;
    f32 unk_4;
    unsigned char padding_8[8];
    f32 unk_10;
    f32 unk_14;
};

extern void func_8029EFE4_de(char *object, float *output);

struct Mtx3x4_8029FD54;
typedef struct Mtx3x4_8029FD54 Mtx3x4_8029FD54;

struct func_8029FFB8_S1;
struct func_8029FFB8_S1 {
    char pad0[0x30];
    int unk30;
    char pad30[0x34 - 0x30 - sizeof(int)];
    int unk34;
    char pad34[0x38 - 0x34 - sizeof(int)];
    int unk38;
};

extern double D_800C5D00_de;

struct Mtx3x4_8029FD54;
struct Mtx3x4_8029FD54 {
    f32 m[3][4];
};

extern void func_8029ED54_de(Mtx3x4_8029FD54 *arg0);

extern void func_8029EBC8_de(void *arg0, void *arg1);

extern float D_800C5CC4_de;

extern void func_8029F000_de(void *arg0, void *arg1);

extern void func_8029EFB8_de(void *arg0);

extern f64 func_8029F5E0_de(u8 *arg0);

extern void func_8029ECA8_de(void *arg0, float value);

struct func_8029FB14_S1;
typedef struct func_8029FB14_S1 func_8029FB14_S1;

extern double D_800C5D18_de;

extern double D_800C5D40_de;

extern void func_8029F1A0_de(void *arg0, void *arg1, void *arg2, s32 arg3);

extern double D_800C5D20_de;

struct FloatState2C;
typedef struct FloatState2C FloatState2C;

struct FloatState2C;
struct FloatState2C {
    unsigned char padding_0[20];
    f32 unk_14;
    f32 unk_18;
    unsigned char padding_1C[8];
    f32 unk_24;
    f32 unk_28;
};

extern double D_800C5CE8_de;

extern void func_8029EBE4_de(void *arg0, void *arg1);

extern double D_800C5D28_de;

extern void func_8029F118_de(float *arg0, float *arg1, float *arg2, float *arg3);

extern double D_800C5CE0_de;

struct FloatState2C_2;
struct FloatState2C_2 {
    f32 unk_0;
    unsigned char padding_4[4];
    f32 unk_8;
    unsigned char padding_C[20];
    f32 unk_20;
    unsigned char padding_24[4];
    f32 unk_28;
};

struct func_8029FA7C_S1;
typedef struct func_8029FA7C_S1 func_8029FA7C_S1;

struct func_8029FFB8_S1;
typedef struct func_8029FFB8_S1 func_8029FFB8_S1;

extern double D_800C5D08_de;

extern double D_800C5D38_de;

struct func_8029FB14_S1;
struct func_8029FB14_S1 {
    f32 unk0;
    char pad0[0x14 - 0x0 - sizeof(f32)];
    f32 unk14;
    char pad14[0x28 - 0x14 - sizeof(f32)];
    f32 unk28;
    char pad28[0x3C - 0x28 - sizeof(f32)];
    f32 unk3C;
};

extern double D_800C5CD0_de;

extern void func_8029F164_de(int arg0, int arg1);

extern void func_8029F180_de(s32 arg0, s32 arg1);

extern float D_800C5CC8_de;

extern double D_800C5CF8_de;

extern float D_800C5CBC_de;

extern void func_8029EDA0_de(s32 arg0);

extern float D_800C5CB8_de;

extern void func_8029EFC8_de(void *arg0, float *arg1);

struct func_8029FBC8_S1;
struct func_8029FBC8_S1 {
    float unk0;
    char pad0[0x14 - 0x0 - sizeof(float)];
    float unk14;
    char pad14[0x28 - 0x14 - sizeof(float)];
    float unk28;
};

extern double D_800C5D50_de;

extern double D_800C5CD8_de;

struct func_8029FBC8_S1;
typedef struct func_8029FBC8_S1 func_8029FBC8_S1;

struct FloatState2C_2;
typedef struct FloatState2C_2 FloatState2C_2;

extern double D_800C5CF0_de;

struct func_8029FA7C_S1;
struct func_8029FA7C_S1 {
    char pad0[0x10];
    int unk10;
    char pad10[0x14 - 0x10 - sizeof(int)];
    float unk14;
    char pad14[0x18 - 0x14 - sizeof(float)];
    float unk18;
    char pad18[0x1C - 0x18 - sizeof(float)];
    float unk1C;
    char pad1C[0x20 - 0x1C - sizeof(float)];
    int unk20;
    char pad20[0x24 - 0x20 - sizeof(int)];
    float unk24;
    char pad24[0x28 - 0x24 - sizeof(float)];
    float unk28;
    char pad28[0x2C - 0x28 - sizeof(float)];
    float unk2C;
    char pad2C[0x30 - 0x2C - sizeof(float)];
    int unk30;
    char pad30[0x34 - 0x30 - sizeof(int)];
    float unk34;
    char pad34[0x38 - 0x34 - sizeof(float)];
    float unk38;
    char pad38[0x3C - 0x38 - sizeof(float)];
    float unk3C;
    char pad3C[0x40 - 0x3C - sizeof(float)];
    float unk40;
    char pad40[0x44 - 0x40 - sizeof(float)];
    float unk44;
    char pad44[0x48 - 0x44 - sizeof(float)];
    float unk48;
    char pad48[0x4C - 0x48 - sizeof(float)];
    float unk4C;
};

extern void func_8029F034_de(float *arg0, float *arg1, float *arg2, float *arg3);

extern double D_800C5D48_de;

struct FloatState18;
typedef struct FloatState18 FloatState18;

extern void func_8029F0CC_de(float *arg0, float *arg1, float *arg2, float *arg3);

extern double D_800C5D10_de;

extern void func_8029ECBC_de(void *arg0, f32 arg1);

extern double D_800C5D30_de;

extern void func_8029EA7C_de(void *arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float arg9, float arg10, float arg11, float arg12, float arg13, float arg14, float arg15, float arg16);

extern void func_8029F080_de(float *arg0, float *arg1, float *arg2, float *arg3);

extern void func_8029EB58_de(f32 *arg0);

#endif
