#ifndef UNBAKE_SPAN_1000_CODE_8027302C_H
#define UNBAKE_SPAN_1000_CODE_8027302C_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
extern void func_802733B4_de(void *matrix, f32 x, f32 y, f32 z);
extern void func_802736D4_de(void *matrix, f32 angle);

struct Mtx;
struct Mtx {
    Vec3 right;
    f32 m03;
    Vec3 up;
    f32 m13;
    Vec3 forward;
    f32 m23;
    f32 m30;
    f32 m31;
    f32 m32;
    f32 m33;
};

extern float D_800C48E0_de;

extern float D_800C4920_de;

extern float D_800C4930_de;

extern void func_80274380_de(void * arg0, float * arg1);

extern f32 func_80273F94_de(f32 arg0, f32 arg1);

extern void func_80273DA0_de(f32 *dst, f32 *src);

extern float D_800C48EC_de;

extern void func_80273040_de(f32 *arg0, f32 *arg1);

extern void func_802734F8_de(float * arg0, float * arg1, float sx, float sy, float sz);

extern float D_800C4910_de;

struct func_80273208_S1;
typedef struct func_80273208_S1 func_80273208_S1;



struct func_80273208_S1;
struct func_80273208_S1 {
    char pad0[0x4];
    Vec3 unk4;
};

extern float D_800C48F0_de;

extern void func_80274318_de(void *arg0, f32 t, void *a, void *b);

extern void func_80273E20_de(struct Mtx *object);

extern void func_80273E64_de(f32 *dst, f32 *src);

struct Mtx;
typedef struct Mtx Mtx;

extern float D_800C4914_de;

#endif
