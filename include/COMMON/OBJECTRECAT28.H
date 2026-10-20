#ifndef COMMON_OBJECTRECAT28_H
#define COMMON_OBJECTRECAT28_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
struct Tree;

struct State_func_80439B5C_de;
typedef struct State_func_80439B5C_de State_func_80439B5C_de;

struct ObjectRecAt28;
struct Triple;
struct ObjectRecAt28 {
    char pad[0x28];
    struct Triple vector;
};

struct ObjectRecAt10;
struct Triple;
struct ObjectRecAt10 {
    char pad[0x10];
    struct Triple vector;
};

struct ObjectRecAt10;
struct Triple;

struct Shape_func_80299E74_de_2;
struct Shape_func_80299E74_de_2 {
    unsigned char padding_0[16];
    unsigned char field_10;
};
struct Pulse;
struct Shape_func_80299E74_de_2;
struct Pulse {
    union { struct Shape_func_80299E74_de_2 *light; struct MenuWidget *widget; };
    s32 phase;
};

struct MenuModelItem;
struct MenuModelItem {
    s32 unused;
    CVector3 scale;
    CVector3 position;
    CVector3 rotation;
    CVector3 speed;
    s32 model;
    char matrices[128];
    s32 flags;
};

struct State_func_80439B5C_de;
struct State_func_80439B5C_de {
    s32 unk0;
    Triple first;
    Triple second;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
};

struct MenuModelScreen;
struct MenuModelScreen {
    char p0[0x160];
    Matrix camera;
    char p1[0x29C-0x1A0];
    f32 width;
    f32 height;
    char p2[0x380-0x2A4];
    Matrix matrices[2];
};


struct ObjectB8;
struct ObjectB8 {
    char pad[0xB8];
    s32 value;
};

struct Pulse;
typedef struct Pulse Pulse;

struct MenuModelItem;
typedef struct MenuModelItem MenuModelItem;

struct Shared_Body;
typedef struct Shared_Body Shared_Body;

struct MenuModelScreen;
typedef struct MenuModelScreen MenuModelScreen;


typedef s32 (*MenuEventHandler)(void *, s32, s32, s32, s32);
extern MenuEventHandler D_800E595C;
#endif
