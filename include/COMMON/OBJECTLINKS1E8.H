#ifndef COMMON_OBJECTLINKS1E8_H
#define COMMON_OBJECTLINKS1E8_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
struct Obj_func_80283920_de;
struct Obj_func_80283920_de {
    char pad0[4];
    u16 unk4;
    char pad6[2];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    char pad14[8];
    CVector3 rotation; /* 0x1C */
    char pad28[0x34];
    u32 unk5C;
    char pad60[0xB8];
    s32 *effectFlags; /* 0x118 */
    char pad11C[0x10];
    void *effectResource; /* 0x12C */
    s32 effectIndex; /* 0x130 */
    s32 effectCount; /* 0x134 */
    s32 unk138;
    char pad13C[0x1D9 - 0x13C];
    u8 active1D9;
};



struct D801041F8_Layout;
struct D801041F8_Layout {
    Triple first;
    char pad[0xD0 - 0xC];
    Triple second;
};

struct D801041F8_Layout;
typedef struct D801041F8_Layout D801041F8_Layout;

struct ObjectLinks1E8;
struct ObjectLinks1E8 {
    s8 unk_0;
    unsigned char padding_1[23];
    s32 *unk_18;
    unsigned char padding_1C[64];
    s32 unk_5C;
    unsigned char padding_60[380];
    s32 unk_1DC;
    unsigned char padding_1E0[4];
    s32 unk_1E4;
};

struct TrailActor;
typedef struct TrailActor TrailActor;




struct Params_func_80283920_de;
struct Params_func_80283920_de {
    char pad0[6];
    s8 unk6;
    s8 unk7;
    char pad8[4];
    s16 unkC;
};



struct ObjectState60;
struct ObjectState60 {
    unsigned char padding_0[4];
    u16 unk_4;
    unsigned char padding_6[86];
    s32 unk_5C;
};

struct Obj_func_80283920_de;
typedef struct Obj_func_80283920_de Obj_func_80283920_de;





union func_80283D24_S1_U8;
typedef union func_80283D24_S1_U8 func_80283D24_S1_U8;




struct ObjectLinks1E8;
typedef struct ObjectLinks1E8 ObjectLinks1E8;





struct Params_func_80283920_de;
typedef struct Params_func_80283920_de Params_func_80283920_de;

struct TrailState;
struct TrailState {
    char pad0[0xC];
    s8 count;
};
struct TrailNode;
struct TrailState;
struct TrailNode {
    char pad0[0x38];
    struct TrailState *state;
};
struct TrailActor;
struct TrailNode;
struct TrailActor {
    char pad0[4];
    u16 model;
    char pad6[2];
    Triple origin;
    char pad14[8];
    Triple position;
    char pad28[0x118 - 0x28];
    struct TrailNode *node;
    char pad11C[0x12C - 0x11C];
    void *owner;
    s32 property;
    s32 type;
    char pad138[0x168 - 0x138];
    Triple end;
};

extern float D_800C4E88_de;


struct EntryRecAt4V1;
struct EntryRecAt4V1 {
    int unk0;
    void *handle;
    char pad8[0xC];
};








struct EntryRecAt4V1;
typedef struct EntryRecAt4V1 EntryRecAt4V1;

union func_80283D24_S1_U8;
union func_80283D24_S1_U8 {
    Triple v0;
    s32 v1;
};




struct ObjectState60;
typedef struct ObjectState60 ObjectState60;


#endif
