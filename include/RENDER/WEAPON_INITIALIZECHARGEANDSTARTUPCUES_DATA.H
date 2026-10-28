#ifndef RENDER_WEAPON_INITIALIZECHARGEANDSTARTUPCUES_DATA_H
#define RENDER_WEAPON_INITIALIZECHARGEANDSTARTUPCUES_DATA_H
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "COMMON/ITEMRECAT20V1.H"
struct ObjectState16DA {
    unsigned char padding_0[5848];
    u16 unk_16D8;
};
struct ObjectState12C4 {
    unsigned char padding_0[1508];
    s32 unk_5E4;
    unsigned char padding_5E8[3288];
    f32 unk_12C0;
};
struct Obj_func_8022B550_de {
    char pad[0x1248];
    Timer timers[5];
};
struct IntegerState1218 {
    unsigned char padding_0[1508];
    s32 unk_5E4;
    unsigned char padding_5E8[3112];
    s32 unk_1210;
    s32 unk_1214;
};
struct ObjectState13E4 {
    char pad0[0x170];
    char unk_170;
    char pad170[0x174 - 0x170 - sizeof(char)];
    s32 unk_174;
    char pad174[0x11E4 - 0x174 - sizeof(s32)];
    f32 unk_11E4;
    char pad11E4[0x13E0 - 0x11E4 - sizeof(f32)];
    s32 unk_13E0;
};
struct ObjRecAt120C {
    char pad0[0x120C];
    s32 unk120C;
};
struct IntegerState16D4 {
    unsigned char padding_0[5840];
    s32 unk_16D0;
};
struct func_8022B08C_S2 {
    char pad0[0x160];
    MatrixF unk160;
};
struct func_8022B08C_S1 {
    char pad0[0x5DC];
    MatrixF * unk5DC;
};
struct IntegerState11C0 {
    unsigned char padding_0[4540];
    s32 unk_11BC;
};
struct IntegerState1250 {
    unsigned char padding_0[4684];
    s32 unk_124C;
};
extern void func_8022AF40_de(void *);
#endif
