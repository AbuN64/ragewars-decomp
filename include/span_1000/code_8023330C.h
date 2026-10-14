#ifndef UNBAKE_SPAN_1000_CODE_8023330C_H
#define UNBAKE_SPAN_1000_CODE_8023330C_H
#include "types.h"
struct StateRecAt10;
typedef struct StateRecAt10 StateRecAt10;

extern void func_8023378C_de(void *arg0, void *arg1);

struct func_80233588_S2;
typedef struct func_80233588_S2 func_80233588_S2;

extern float D_800C3080_de;

extern float D_800C3084_de;

extern float D_800C3060_de;

extern float D_800C3078_de;

struct func_80233588_S2;
struct func_80233588_S2 {
    char pad0[0xCB];
    s8 unkCB;
    char padCB[0x13C - 0xCB - sizeof(s8)];
    s32 unk13C;
};

extern float D_800C3050_de;

struct ObjectLinks11DC;
typedef struct ObjectLinks11DC ObjectLinks11DC;

struct StateRecAt10;
struct StateRecAt10 {
    s32 mode;
    f32 value;
    f32 limit;
    f32 rate;
    f32 accumulator;
};

extern float D_800C3074_de;

extern void func_80233344_de(void);

extern float D_800C3054_de;

struct func_8023333C_S1;
typedef struct func_8023333C_S1 func_8023333C_S1;

extern float D_800C3088_de;

extern float D_800C3064_de;

extern void func_802335EC_de(void *arg0, void *arg1);

extern float D_800C3058_de;

extern float D_800C3070_de;

extern float D_800C308C_de;

struct func_8023333C_S1;
struct func_8023333C_S1 {
    char pad0[0x104];
    f32 unk104;
    char pad104[0x1D8 - 0x104 - sizeof(f32)];
    void * unk1D8;
};

extern float D_800C305C_de;

struct ObjectLinks11DC;
struct ObjectLinks11DC {
    char pad0[0x5D8];
    char * unk_5D8;
    char pad5D8[0x62E - 0x5D8 - sizeof(char*)];
    s16 unk_62E;
    char pad62E[0x650 - 0x62E - sizeof(s16)];
    s16 unk_650;
    char pad650[0x6AC - 0x650 - sizeof(s16)];
    s32 unk_6AC;
    char pad6AC[0x770 - 0x6AC - sizeof(s32)];
    s16 unk_770;
    char pad770[0x11D8 - 0x770 - sizeof(s16)];
    f32 unk_11D8;
};

extern void func_8023356C_de(void *arg0);

#endif
