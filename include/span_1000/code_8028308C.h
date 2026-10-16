#ifndef UNBAKE_SPAN_1000_CODE_8028308C_H
#define UNBAKE_SPAN_1000_CODE_8028308C_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
struct Obj_func_80283920_de;
struct Obj_func_80283920_de {
    char pad0[4];
    u16 unk4;
    char pad6[2];
    s32 unk8;
    s32 unkC;
    s32 unk10;
    char pad14[8];
    Vec3 rotation; /* 0x1C */
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

struct func_8028438C_S1;
struct func_8028438C_S1 {
    char pad0[0x8];
    char unk8;
    char pad8[0x1DC - 0x8 - sizeof(char)];
    void * unk1DC;
};

struct RecCode8028308C;
typedef struct RecCode8028308C RecCode8028308C;

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

struct RecCode8028308C;
struct RecCode8028308C {
    char pad0[0x8];
    Triple unk8;
    char pad8[0x1C - 0x8 - sizeof(Triple)];
    Triple unk1C;
    char pad1C[0x5C - 0x1C - sizeof(Triple)];
    int unk5C;
};

struct func_802839F0_S1;
struct func_802839F0_S1 {
    char pad0[0x138];
    s32 unk138;
    char pad138[0x1D9 - 0x138 - sizeof(s32)];
    u8 unk1D9;
};

extern void func_80283BA0_de(void *arg0, s32 arg1);

struct Params_func_80283920_de;
struct Params_func_80283920_de {
    char pad0[6];
    s8 unk6;
    s8 unk7;
    char pad8[4];
    s16 unkC;
};

struct func_80283454_S1;
typedef struct func_80283454_S1 func_80283454_S1;

struct func_802831FC_S2;
typedef struct func_802831FC_S2 func_802831FC_S2;

struct ObjectState60;
struct ObjectState60 {
    unsigned char padding_0[4];
    u16 unk_4;
    unsigned char padding_6[86];
    s32 unk_5C;
};

struct Obj_func_80283920_de;
typedef struct Obj_func_80283920_de Obj_func_80283920_de;

extern void func_80283BCC_de(void *arg0);

struct func_8028324C_S1;
typedef struct func_8028324C_S1 func_8028324C_S1;

struct func_8028438C_S1;
typedef struct func_8028438C_S1 func_8028438C_S1;

struct func_8028324C_S1;
struct func_8028324C_S1 {
    char pad0[0xFC00];
    char unkFC00;
    char padFC00[0xFC14 - 0xFC00 - sizeof(char)];
    char unkFC14;
};

union func_80283D24_S1_U8;
typedef union func_80283D24_S1_U8 func_80283D24_S1_U8;

struct func_80283454_S1;
struct func_80283454_S1 {
    char pad0[0x1C];
    Triple unk1C;
    char pad1C[0x5C - 0x1C - sizeof(Triple)];
    s32 unk5C;
    char pad5C[0x118 - 0x5C - sizeof(s32)];
    s32 * unk118;
    char pad118[0x12C - 0x118 - sizeof(s32*)];
    void * unk12C;
    char pad12C[0x130 - 0x12C - sizeof(void*)];
    s32 unk130;
    char pad130[0x134 - 0x130 - sizeof(s32)];
    s32 unk134;
};

struct func_80283D24_S1;
typedef struct func_80283D24_S1 func_80283D24_S1;

extern s32 func_802833DC_de(void *arg0);

struct ObjectLinks1E8;
typedef struct ObjectLinks1E8 ObjectLinks1E8;

struct func_8028357C_S1;
typedef struct func_8028357C_S1 func_8028357C_S1;

struct func_8028357C_S1;
struct func_8028357C_S1 {
    char pad0[0x1C];
    Vec3 unk1C;
    char pad1C[0x5C - 0x1C - sizeof(Vec3)];
    s32 unk5C;
    char pad5C[0x118 - 0x5C - sizeof(s32)];
    s32 * unk118;
    char pad118[0x12C - 0x118 - sizeof(s32*)];
    void * unk12C;
    char pad12C[0x130 - 0x12C - sizeof(void*)];
    void * unk130;
    char pad130[0x134 - 0x130 - sizeof(void*)];
    s32 unk134;
};

extern s32 func_80283D38_de(s32 arg0);

struct func_8028403C_S1;
typedef struct func_8028403C_S1 func_8028403C_S1;

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

struct IntegerState1E0;
typedef struct IntegerState1E0 IntegerState1E0;

struct EntryRecAt4V1;
struct EntryRecAt4V1 {
    int unk0;
    void *handle;
    char pad8[0xC];
};

struct func_802836A4_S1;
struct func_802836A4_S1 {
    char pad0[0x1C];
    Vec3 unk1C;
    char pad1C[0x5C - 0x1C - sizeof(Vec3)];
    s32 unk5C;
    char pad5C[0x118 - 0x5C - sizeof(s32)];
    s32 * unk118;
    char pad118[0x12C - 0x118 - sizeof(s32*)];
    void * unk12C;
    char pad12C[0x130 - 0x12C - sizeof(void*)];
    s32 unk130;
    char pad130[0x134 - 0x130 - sizeof(s32)];
    s32 unk134;
};

extern void func_80283424_de(void *arg0);

struct func_802839F0_S1;
typedef struct func_802839F0_S1 func_802839F0_S1;

struct func_8028414C_S2;
struct func_8028414C_S2 {
    char pad0[0x8];
    char unk8;
    char pad8[0x5C - 0x8 - sizeof(char)];
    s32 unk5C;
};

struct func_8028308C_S1;
struct func_8028308C_S1 {
    char pad0[0xFC68];
    int unkFC68;
};

struct func_8028403C_S1;
struct func_8028403C_S1 {
    char pad0[0x5C];
    unsigned int unk5C;
};

struct func_8028308C_S1;
typedef struct func_8028308C_S1 func_8028308C_S1;

struct EntryRecAt4V1;
typedef struct EntryRecAt4V1 EntryRecAt4V1;

union func_80283D24_S1_U8;
union func_80283D24_S1_U8 {
    Triple v0;
    s32 v1;
};

struct IntegerState1E0;
struct IntegerState1E0 {
    unsigned char padding_0[476];
    s32 unk_1DC;
};

struct func_802836A4_S1;
typedef struct func_802836A4_S1 func_802836A4_S1;

struct func_8028414C_S2;
typedef struct func_8028414C_S2 func_8028414C_S2;

struct ObjectState60;
typedef struct ObjectState60 ObjectState60;

struct func_80283D24_S1;
struct func_80283D24_S1 {
    char pad0[0x8];
    func_80283D24_S1_U8 unk8;
    char pad8[0x118 - 0x8 - sizeof(func_80283D24_S1_U8)];
    void * unk118;
    char pad118[0x1D0 - 0x118 - sizeof(void*)];
    s8 unk1D0;
};

struct func_802831FC_S2;
struct func_802831FC_S2 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0x12C - 0x4 - sizeof(u16)];
    s32 unk12C;
    char pad12C[0x1EC - 0x12C - sizeof(s32)];
    s8 * unk1EC;
};

extern float func_80284090_de(void * arg0, float arg1, void * arg2);
#endif
