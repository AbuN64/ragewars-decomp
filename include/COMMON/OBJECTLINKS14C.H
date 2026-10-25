#ifndef COMMON_OBJECTLINKS14C_H
#define COMMON_OBJECTLINKS14C_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
struct ObjectLinks14C;
struct ObjectLinks14C {
    char pad0[0x30];
    void * callback_owner;
    char pad30[0x130 - 0x30 - sizeof(void*)];
    f32 unk_130;
    char pad130[0x148 - 0x130 - sizeof(f32)];
    f32 unk_148;
};



struct ObjectState44;
typedef struct ObjectState44 ObjectState44;


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


extern float D_800C2F5C_de;

extern float D_800C2FBC_de;

struct ObjectWeaponsNextAvailableWeapon;
typedef struct ObjectWeaponsNextAvailableWeapon ObjectWeaponsNextAvailableWeapon;

struct ObjectLinks1DC_2;
struct ObjectLinks1DC_2 {
    char pad0[0x1];
    u8 unk_1;
    char pad1[0x1D8 - 0x1 - sizeof(u8)];
    void * unk_1D8;
};

extern int D_800CA040_de;


extern float D_800C2E90_de;

struct CallbackState60;
struct CallbackState60 {
    unsigned char padding_0[92];
    void (*callback)(void *, void *);
};

extern void func_8022FF04_de(void *arg0, WeaponFireState *arg1);


struct ObjectWeaponsNextAvailableWeapon;
struct ObjectWeaponsNextAvailableWeapon {
    s8 pad603[0x603];
    s8 values[0x2B];
    s16 selected;
};


struct ObjectState44;
struct ObjectState44 {
    unsigned char padding_0[56];
    CVector3 unk_38;
};

struct ObjectState630;
typedef struct ObjectState630 ObjectState630;


struct ObjectState1230;
typedef struct ObjectState1230 ObjectState1230;

struct ObjectLinks14C;
typedef struct ObjectLinks14C ObjectLinks14C;


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


struct ObjectLinks1DC_2;
typedef struct ObjectLinks1DC_2 ObjectLinks1DC_2;



struct WeaponAnimationState;
struct WeaponAnimationState {
    char pad0[0x168];
    f32 speed;
};

extern float D_800C2FC0_de;

extern float D_800C2F20_de;



extern float D_800C2F14_de;

extern float D_800C8008;
extern float D_800C2F1C_de;
extern float D_800C2F24_de;




extern float D_800C2F60_de;

struct ObjectLinks1DC;
typedef struct ObjectLinks1DC ObjectLinks1DC;


extern int D_800CA048;

struct CallbackState60;
typedef struct CallbackState60 CallbackState60;

struct WeaponAnimationState;
typedef struct WeaponAnimationState WeaponAnimationState;




extern int D_800CA044;

struct ObjectLinks1DC;
struct ObjectLinks1DC {
    char pad0[0x50];
    CVector3 unk_50;
    char pad50[0x1D8 - 0x50 - sizeof(CVector3)];
    char * unk_1D8;
};



extern float D_800C2FB0_de;



typedef struct MarkerNode { u8 pad0[0x1214]; s32 active; u8 pad1218[0x264]; s32 extra; u32 matrices[4][16], extraMatrices[4][16]; } MarkerNode;
typedef struct MarkerActor { u8 pad0[0x1D8]; MarkerNode *node; } MarkerActor;
extern s32 D_800D297C;
extern struct UnitVtx D_800FF1B0_de[];
extern s32 Render_SetModePreset(s32);
extern void Render_SetCombineMode(u32);
extern void func_802A5498_de(u32);

extern s32 func_802327A0_de(s32);

extern s32 func_80230058_de(void *, void *);


extern void func_8022B9C4_de(void *arg0);
#endif
