#ifndef COMMON_OBJRECAT20V1_H
#define COMMON_OBJRECAT20V1_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"


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

extern void func_80290A0C_de(void *schedule);

extern void func_80290A00_de(void *arg0);


extern void func_80290988_us(void);
extern void func_80290A78_de(void);
extern void func_80290B88_eu(void);
extern void func_80290BB8_eu_x(void);
#endif
