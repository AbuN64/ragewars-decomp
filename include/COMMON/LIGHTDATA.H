#ifndef COMMON_LIGHTDATA_H
#define COMMON_LIGHTDATA_H
#include "TYPES.H"

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

extern int Defs_IsAddressInBufferRanges(u32 address);

struct UnitLight;
typedef struct UnitLight UnitLight;

extern int Defs_GetBitArrayByteCount(int arg0);


struct UnitLight;
struct UnitLight {
    s16 dir[3];
    u8 color[4];
    s16 falloff;
    u16 near;
    u16 range;
};

extern void Defs_ToggleBit(s32 arg0, s32 arg1);

extern float D_800C4398_de;

struct LightNode;
typedef struct LightNode LightNode;

extern float D_800C43A0_de;

extern f32 Defs_CosineEase(f32 arg0);

extern void Defs_NoOperation(void);
#endif
