#ifndef UNBAKE_SPAN_1000_CODE_80290980_H
#define UNBAKE_SPAN_1000_CODE_80290980_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
extern void func_80290A50_us_rev1(void);

extern void func_80290A60_us_rev1(void);

struct ObjRecAt20V1;
typedef struct ObjRecAt20V1 ObjRecAt20V1;

struct func_802909F4_S1;
typedef struct func_802909F4_S1 func_802909F4_S1;

struct func_802909F4_S1;
struct func_802909F4_S1 {
    char pad0[0x14];
    func_8026E158_S1_U8 unk14;
    char pad14[0x18 - 0x14 - sizeof(func_8026E158_S1_U8)];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk1C;
};

extern void func_80290A14_de(void *arg0, void *arg1);

extern void func_80290A58_us_rev1(void);

struct ObjRecAt20V1;
struct ObjRecAt20V1 {
    char pad0[0x8];
    float unk8;
    char pad8[0xC - 0x8 - sizeof(float)];
    float unkC;
    char padC[0x10 - 0xC - sizeof(float)];
    float unk10;
    char pad10[0x20 - 0x10 - sizeof(float)];
    int unk20;
};

extern void func_80290A0C_de();

extern void func_80290A00_de(void *arg0);

extern void func_80290A48_de(void *source, int *word, float *third, float *fourth, float *second);

extern void func_80290980_us(void);
extern void func_80290988_us(void);
extern void func_80290990_us(void);
extern void func_80290A70_de(void);
extern void func_80290A78_de(void);
extern void func_80290A80_de(void);
extern void func_80290B80_eu(void);
extern void func_80290B88_eu(void);
extern void func_80290B90_eu(void);
extern void func_80290BB0_eu_x(void);
extern void func_80290BB8_eu_x(void);
extern void func_80290BC0_eu_x(void);
#endif
