#ifndef RENDER_802909E0_H
#define RENDER_802909E0_H
#include "TYPES.H"
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
typedef struct ObjRecAt26DC1 {
    char pad0[0x26DB0];
    f32 unk26DB0;
    char pad26DB4[0x26DBC - 0x26DB4];
    s32 unk26DBC;
    char pad26DC0[1];
    s8 unk26DC1;
} ObjRecAt26DC1;
#endif
