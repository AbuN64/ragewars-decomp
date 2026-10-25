#ifndef COMMON_S1_3_H
#define COMMON_S1_3_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
extern void Particle_BuildTranslationMatrix(void *matrix, f32 x, f32 y, f32 z);
extern void func_80272CB0_de(void *matrix, f32 x, f32 y, f32 z);
extern float D_800C48D8_de;







struct func_80272D20_S1;
typedef struct func_80272D20_S1 func_80272D20_S1;

struct func_80272CD0_S1;
struct func_80272CD0_S1 {
    f32 unk0;
    char pad0[0x4 - 0x0 - sizeof(f32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    f32 unk14;
    char pad14[0x18 - 0x14 - sizeof(f32)];
    f32 unk18;
    char pad18[0x1C - 0x18 - sizeof(f32)];
    f32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
    char pad24[0x28 - 0x24 - sizeof(f32)];
    f32 unk28;
    char pad28[0x2C - 0x28 - sizeof(f32)];
    f32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(f32)];
    s32 unk30;
    char pad30[0x34 - 0x30 - sizeof(s32)];
    s32 unk34;
    char pad34[0x38 - 0x34 - sizeof(s32)];
    s32 unk38;
    char pad38[0x3C - 0x38 - sizeof(s32)];
    f32 unk3C;
};

struct func_80272D20_S1;
struct func_80272D20_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    f32 unk18;
    char pad18[0x1C - 0x18 - sizeof(f32)];
    f32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(f32)];
    f32 unk20;
    char pad20[0x24 - 0x20 - sizeof(f32)];
    f32 unk24;
    char pad24[0x28 - 0x24 - sizeof(f32)];
    s32 unk28;
    char pad28[0x2C - 0x28 - sizeof(s32)];
    f32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(f32)];
    f32 unk30;
    char pad30[0x34 - 0x30 - sizeof(f32)];
    f32 unk34;
    char pad34[0x38 - 0x34 - sizeof(f32)];
    f32 unk38;
    char pad38[0x3C - 0x38 - sizeof(f32)];
    f32 unk3C;
};

extern f32 func_802725FC_de(f32 *arg0);




extern f32 Particle_GetAngleDistance(f32 arg0, f32 arg1);

extern void func_80271F00_de(CVector3 *result, CVector3 *left, CVector3 *right);

extern float D_800C48B0_de;

extern float D_800C48DC_de;

extern float D_800C48B8_de;


extern void *func_80272180_de(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2, f32 arg3);

extern void *func_80272214_de(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2);





extern void func_80272104_de(CVector3 *out, CVector3 *a, CVector3 *b, f32 y);

struct func_80272CD0_S1;
typedef struct func_80272CD0_S1 func_80272CD0_S1;




#endif
