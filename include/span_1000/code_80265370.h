#ifndef UNBAKE_SPAN_1000_CODE_80265370_H
#define UNBAKE_SPAN_1000_CODE_80265370_H
#include "TYPES.H"
extern void func_80265DD0_de();

extern float D_800C439C_de;

struct LightData;
struct LightData {
    u16 falloff;
    u16 near;
    u8 color[4];
};

struct LightData;
typedef struct LightData LightData;

struct LightNode;
struct LightNode {
    char pad0[8];
    LightData *data;
    f32 intensity;
    s16 position[3];
    s16 active;
};

extern int func_8026581C_de(u32 address);

struct UnitLight;
typedef struct UnitLight UnitLight;

extern int func_8026563C_de(int arg0);

extern void func_80265900_de(void);

struct UnitLight;
struct UnitLight {
    s16 dir[3];
    u8 color[4];
    s16 falloff;
    u16 near;
    u16 range;
};

extern void func_802656DC_de(s32 arg0, s32 arg1);

extern float D_800C4398_de;

struct LightNode;
typedef struct LightNode LightNode;

extern float D_800C43A0_de;

extern f32 func_80265714_de(f32 arg0);

extern void func_802658DC_de(void);
#endif
