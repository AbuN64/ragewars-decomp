#ifndef UNBAKE_SPAN_1000_CODE_8022F3E8_H
#define UNBAKE_SPAN_1000_CODE_8022F3E8_H
#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
struct ObjectLinks14C;
struct ObjectLinks14C {
    char pad0[0x30];
    void * callback_owner;
    char pad30[0x130 - 0x30 - sizeof(void*)];
    f32 unk_130;
    char pad130[0x148 - 0x130 - sizeof(f32)];
    f32 unk_148;
};

struct func_80230BB8_S1;
struct func_80230BB8_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0x5DC - 0x8 - sizeof(s32)];
    char * unk5DC;
    char pad5DC[0x62E - 0x5DC - sizeof(char*)];
    s16 unk62E;
    char pad62E[0x6AC - 0x62E - sizeof(s16)];
    s32 unk6AC;
    char pad6AC[0x11B4 - 0x6AC - sizeof(s32)];
    s32 unk11B4;
    char pad11B4[0x11D8 - 0x11B4 - sizeof(s32)];
    f32 unk11D8;
    char pad11D8[0x1450 - 0x11D8 - sizeof(f32)];
    s32 unk1450;
    char pad1450[0x1454 - 0x1450 - sizeof(s32)];
    char * unk1454;
};

struct func_80230BB8_S5;
typedef struct func_80230BB8_S5 func_80230BB8_S5;

struct ObjectState44;
typedef struct ObjectState44 ObjectState44;

struct Obj_func_8022F3F8_de;
typedef struct Obj_func_8022F3F8_de Obj_func_8022F3F8_de;

union ObjectLinks4;
union ObjectLinks4 {
    s32 v0;
    char * v1;
};

union ObjectLinks4;
typedef union ObjectLinks4 ObjectLinks4;

struct ObjectState630;
struct ObjectState630 {
    char pad0[0x5DC];
    ObjectLinks4 unk_5DC;
    char pad5DC[0x62E - 0x5DC - sizeof(ObjectLinks4)];
    s16 unk_62E;
};

struct func_80230BB8_S2;
typedef struct func_80230BB8_S2 func_80230BB8_S2;

extern float D_800C2F5C_de;

extern float D_800C2FBC_de;

struct Object_func_8022FAF8_de;
typedef struct Object_func_8022FAF8_de Object_func_8022FAF8_de;

struct ObjectLinks1DC_2;
struct ObjectLinks1DC_2 {
    char pad0[0x1];
    u8 unk_1;
    char pad1[0x1D8 - 0x1 - sizeof(u8)];
    void * unk_1D8;
};

extern int D_800CA040_de;

struct func_8022F95C_S2;
struct func_8022F95C_S2 {
    char pad0[0x603];
    s8 unk603;
};

extern float D_800C2E90_de;

struct CallbackState60;
struct CallbackState60 {
    unsigned char padding_0[92];
    void (*callback)(void *, void *);
};

extern void func_8022FF04_de(void *arg0, WeaponFireState *arg1);

extern void func_8022F5E0_de(char *arg0);

struct Object_func_8022FAF8_de;
struct Object_func_8022FAF8_de {
    s8 pad603[0x603];
    s8 values[0x2B];
    s16 selected;
};

struct func_80230BB8_S5;
struct func_80230BB8_S5 {
    char pad0[0x64];
    f32 unk64;
    char pad64[0x128 - 0x64 - sizeof(f32)];
    f32 unk128;
};

struct ObjectState44;
struct ObjectState44 {
    unsigned char padding_0[56];
    Vec3 unk_38;
};

struct ObjectState630;
typedef struct ObjectState630 ObjectState630;

struct func_8022FEF4_S3;
typedef struct func_8022FEF4_S3 func_8022FEF4_S3;

struct ObjectState1230;
typedef struct ObjectState1230 ObjectState1230;

struct ObjectLinks14C;
typedef struct ObjectLinks14C ObjectLinks14C;

struct func_80230620_S2;
struct func_80230620_S2 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
    char pad10[0x5D8 - 0x10 - sizeof(s32)];
    void * unk5D8;
    char pad5D8[0x62E - 0x5D8 - sizeof(void*)];
    s16 unk62E;
    char pad62E[0x650 - 0x62E - sizeof(s16)];
    s16 unk650;
    char pad650[0x698 - 0x650 - sizeof(s16)];
    void * unk698;
    char pad698[0x6B0 - 0x698 - sizeof(void*)];
    s32 unk6B0;
    char pad6B0[0x770 - 0x6B0 - sizeof(s32)];
    s16 unk770;
    char pad770[0x11FC - 0x770 - sizeof(s16)];
    s32 unk11FC;
};

struct ObjectState1230;
struct ObjectState1230 {
    char pad0[0x62E];
    s16 unk_62E;
    char pad62E[0x650 - 0x62E - sizeof(s16)];
    s16 unk_650;
    char pad650[0x770 - 0x650 - sizeof(s16)];
    s16 unk_770;
    char pad770[0x7E8 - 0x770 - sizeof(s16)];
    s32 unk_7E8;
    char pad7E8[0x11D8 - 0x7E8 - sizeof(s32)];
    f32 unk_11D8;
    char pad11D8[0x122C - 0x11D8 - sizeof(f32)];
    s32 unk_122C;
};

extern float D_800C2FB4_de;

struct func_80230BB8_S1;
typedef struct func_80230BB8_S1 func_80230BB8_S1;

struct ObjectLinks1DC_2;
typedef struct ObjectLinks1DC_2 ObjectLinks1DC_2;

extern void func_8022F770_de(void *, void *);

struct func_80230620_S4;
typedef struct func_80230620_S4 func_80230620_S4;

struct WeaponAnimationState;
struct WeaponAnimationState {
    char pad0[0x168];
    f32 speed;
};

extern float D_800C2FC0_de;

extern float D_800C2F20_de;

struct func_8022FEF4_S3;
struct func_8022FEF4_S3 {
    char pad0[0x2C];
    s32 unk2C;
    char pad2C[0x120 - 0x2C - sizeof(s32)];
    s32 unk120;
    char pad120[0x124 - 0x120 - sizeof(s32)];
    s32 unk124;
    char pad124[0x128 - 0x124 - sizeof(s32)];
    s32 unk128;
    char pad128[0x130 - 0x128 - sizeof(s32)];
    s32 unk130;
    char pad130[0x13C - 0x130 - sizeof(s32)];
    s32 unk13C;
    char pad13C[0x144 - 0x13C - sizeof(s32)];
    s32 unk144;
};

struct func_80230620_S3;
struct func_80230620_S3 {
    char pad0[0xCB];
    s8 unkCB;
    char padCB[0x138 - 0xCB - sizeof(s8)];
    s32 unk138;
    char pad138[0x13C - 0x138 - sizeof(s32)];
    s32 unk13C;
};

extern float D_800C2F14_de;

extern float D_800C8008;
extern float D_800C2F1C_de;
extern float D_800C2F24_de;

struct func_80230620_S4;
struct func_80230620_S4 {
    char pad0[0x168];
    s32 unk168;
};

struct func_8022F95C_S2;
typedef struct func_8022F95C_S2 func_8022F95C_S2;

struct func_8022FEF4_S1;
typedef struct func_8022FEF4_S1 func_8022FEF4_S1;

extern float D_800C2F60_de;

struct ObjectLinks1DC;
typedef struct ObjectLinks1DC ObjectLinks1DC;

struct func_80230620_S2;
typedef struct func_80230620_S2 func_80230620_S2;

extern int D_800CA048;

struct CallbackState60;
typedef struct CallbackState60 CallbackState60;

struct WeaponAnimationState;
typedef struct WeaponAnimationState WeaponAnimationState;

struct func_80230620_S3;
typedef struct func_80230620_S3 func_80230620_S3;

struct func_8022F95C_S1;
typedef struct func_8022F95C_S1 func_8022F95C_S1;

struct Obj_func_8022F3F8_de;
struct Obj_func_8022F3F8_de {
    char pad[0x18];
    unsigned char slots[13];
};

extern int D_800CA044;

struct ObjectLinks1DC;
struct ObjectLinks1DC {
    char pad0[0x50];
    Vec3 unk_50;
    char pad50[0x1D8 - 0x50 - sizeof(Vec3)];
    char * unk_1D8;
};

struct func_80230BB8_S2;
struct func_80230BB8_S2 {
    char pad0[0x100];
    s32 unk100;
    char pad100[0x1D8 - 0x100 - sizeof(s32)];
    func_80230BB8_S2_U1D8 unk1D8;
};

extern void func_80230DA4_de(Shared_Actor *actor, WeaponFireState *weapon);

extern float D_800C2FB0_de;

struct func_8022FEF4_S1;
struct func_8022FEF4_S1 {
    char pad0[0x1];
    char unk1;
    char pad1[0x1D8 - 0x1 - sizeof(char)];
    char * unk1D8;
};

struct func_8022F95C_S1;
struct func_8022F95C_S1 {
    char pad0[0x5F4];
    s16 unk5F4;
    char pad5F4[0x62E - 0x5F4 - sizeof(s16)];
    s16 unk62E;
    char pad62E[0x1450 - 0x62E - sizeof(s16)];
    s32 unk1450;
};

typedef struct MarkerNode { u8 pad0[0x1214]; s32 active; u8 pad1218[0x264]; s32 extra; u32 matrices[4][16], extraMatrices[4][16]; } MarkerNode;
typedef struct MarkerActor { u8 pad0[0x1D8]; MarkerNode *node; } MarkerActor;
extern s32 D_800D297C;
extern struct UnitVtx D_800FF1B0_de[];
extern s32 func_8026925C_de(s32);
extern void func_80268CE0_de(u32);
extern void func_802A5498_de(u32);

extern s32 func_802327A0_de(s32);

extern s32 func_80230058_de(void *, void *);

extern void func_8022AF40_de(void *);

extern void func_8022B9C4_de(void *arg0);

#endif
