#ifndef UNBAKE_SPAN_1000_CODE_8023B9A0_H
#define UNBAKE_SPAN_1000_CODE_8023B9A0_H
#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
extern void func_8023C85C_de(s32 arg0);

struct Node_func_8023CCD4_de;
typedef struct Node_func_8023CCD4_de Node_func_8023CCD4_de;

struct Block_func_8023C85C_de;
typedef struct Block_func_8023C85C_de Block_func_8023C85C_de;

struct OwnerRecAt8V2;
struct OwnerRecAt8V2 {
    s32 unk0;
    u32 handle;
    s32 queue;
};

struct OwnerRecAt8V2;
typedef struct OwnerRecAt8V2 OwnerRecAt8V2;

extern void func_8023CCD4_de(OwnerRecAt8V2 *arg0);

struct Channels;
typedef struct Channels Channels;

struct Mapping;
typedef struct Mapping Mapping;

extern void func_8023CB90_de(Field_void_4 *arg0, Field_void_4 *arg1);

struct Shape_typemap_110;
extern void func_8023C8D4_de(struct Shape_typemap_110 *arg0);

extern void func_8023C6BC_de(void);

struct func_8023D148_S1;
typedef struct func_8023D148_S1 func_8023D148_S1;

struct func_8023C77C_S1;
typedef struct func_8023C77C_S1 func_8023C77C_S1;

struct Node_func_8023CC08_de;
typedef struct Node_func_8023CC08_de Node_func_8023CC08_de;

struct func_8023D148_S2;
struct func_8023D148_S2 {
    char pad0[0x48];
    f32 unk48;
    char pad48[0x4C - 0x48 - sizeof(f32)];
    f32 unk4C;
    char pad4C[0x54 - 0x4C - sizeof(f32)];
    f32 unk54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk58;
    char pad58[0x60 - 0x58 - sizeof(f32)];
    f32 unk60;
    char pad60[0x64 - 0x60 - sizeof(f32)];
    f32 unk64;
};

struct Block10;
typedef struct Block10 Block10;

union ObjectState1000;
union ObjectState1000 {
    u8 marks[4096];
    struct { u8 padding[0x3CF]; u8 indices[96]; } first;
    struct { u8 padding[0x3D0]; u8 indices[96]; } second;
};

struct Link_func_8023CC08_de;
struct Link_func_8023CC08_de {
    struct Link_func_8023CC08_de *next;
    struct Link_func_8023CC08_de *prev;
    u16 id;
    union { u16 padA; struct { u8 index; u8 slot; }; };
    s32 fieldC;
};

extern float D_800C3630_de;

struct Region;
struct Region {
    struct Region *next;
    u16 start;
    u16 pages;
    s32 pad8;
    s32 padC;
    u8 *map;
    s32 pad14;
    u8 data[1];
};

struct Region;
struct RegionDesc;
struct RegionDesc {
    s32 pad0;
    s32 size;
    struct Region *region;
    void *mapping;
};

struct RegionDesc;
typedef struct RegionDesc RegionDesc;

extern void func_8023CDD4_de(RegionDesc *desc);

extern void func_8023D010_eu_x(void);

struct Slot_func_8023B9C0_eu;
typedef struct Slot_func_8023B9C0_eu Slot_func_8023B9C0_eu;

struct Node_func_8023CCD4_de;
struct Node_func_8023CCD4_de {
    struct Node_func_8023CCD4_de *next;
    u16 id;
    u16 count;
    s32 unk8;
    s32 unkC;
    u8 *slots;
};

struct Link_func_8023CC08_de;
typedef struct Link_func_8023CC08_de Link_func_8023CC08_de;

struct Block_func_8023C85C_de;
struct Block_func_8023C85C_de {
    s16 type;
    s16 pad;
    s32 value;
    void *data;
};

struct Channels;
struct Channels {
    char pad0[0x1C];
};

struct Slot_func_8023B9C0_eu;
struct Slot_func_8023B9C0_eu {
    union {
        struct { s32 a; s32 b; char pad8[2]; u8 index; char padB[5]; };
        Link_func_8023CC08_de chain;
    };
};

struct State_func_8023B9C0_eu;
struct State_func_8023B9C0_eu {
    char pad0[0x20];
    s16 f20;
    char pad22[2];
    char list0[0x3C - 0x24];
    char list0Data[0xC0 - 0x3C];
    char queue[0x2F0 - 0xC0];
    char pool[0x4F0 - 0x2F0];
    char queueData[0x920 - 0x4F0];
    Slot_func_8023B9C0_eu slots[24];
    char list1[0xAB8 - 0xAA0];
    char list1Data[0xAD8 - 0xAB8];
    char list2[0xAF0 - 0xAD8];
    char list2Data[0xB10 - 0xAF0];
    Channels channels[8];
    s32 fBF0;
    union { s32 fBF4; Link_func_8023CC08_de *tail; };
    u8 lookup[0x100];
    EntryRecAt3 entries[24];
    s32 fD58;
    s16 fD5C;
    s16 fD5E;
    u32 romAddr;
    char padD64[4];
    u8 *lookupPtr;
    char padD6C[4];
    s16 fD70;
    s16 fD72;
    char padD74[4];
};

extern int func_8023BC74_de();

union ObjectState1000;
typedef union ObjectState1000 ObjectState1000;

struct Slot_func_8023CCD4_de;
typedef struct Slot_func_8023CCD4_de Slot_func_8023CCD4_de;

struct Node_func_8023CBC0_de;
typedef struct Node_func_8023CBC0_de Node_func_8023CBC0_de;

struct Slot_func_8023CCD4_de;
struct Slot_func_8023CCD4_de {
    s32 unk0;
    u16 unk4;
    u16 unk6;
    u16 id;
    u16 unkA;
    s32 unkC;
};

struct Mapping;
struct Mapping {
    char pad0[8];
    u16 flags;
    char padA;
    u8 slot;
};

struct Node_func_8023CBC0_de;
struct Node_func_8023CBC0_de {
    struct Node_func_8023CBC0_de *next;
    u16 f4;
    u16 f6;
};

struct Region;
typedef struct Region Region;

struct State_func_8023B9C0_eu;
typedef struct State_func_8023B9C0_eu State_func_8023B9C0_eu;

struct func_8023D148_S2;
typedef struct func_8023D148_S2 func_8023D148_S2;

struct Block10;
struct Block10 {
    s16 f28;
    s16 pad;
    s32 f2C;
    void *f30;
    void **f34;
};

struct func_8023D148_S1;
struct func_8023D148_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x40 - 0x4 - sizeof(s32)];
    s32 * unk40;
    char pad40[0x44 - 0x40 - sizeof(s32*)];
    func_80234DD0_S1_U260 unk44;
    char pad44[0x50 - 0x44 - sizeof(func_80234DD0_S1_U260)];
    func_80234DD0_S1_U260 unk50;
    char pad50[0x5C - 0x50 - sizeof(func_80234DD0_S1_U260)];
    func_80234DD0_S1_U260 unk5C;
    char pad5C[0x68 - 0x5C - sizeof(func_80234DD0_S1_U260)];
    Vec3 unk68;
    char pad68[0x80 - 0x68 - sizeof(Vec3)];
    f32 unk80;
    char pad80[0x84 - 0x80 - sizeof(f32)];
    f32 unk84;
    char pad84[0x88 - 0x84 - sizeof(f32)];
    f32 unk88;
    char pad88[0x8C - 0x88 - sizeof(f32)];
    f32 unk8C;
    char pad8C[0x90 - 0x8C - sizeof(f32)];
    f32 unk90;
    char pad90[0x94 - 0x90 - sizeof(f32)];
    f32 unk94;
    char pad94[0x98 - 0x94 - sizeof(f32)];
    f32 unk98;
    char pad98[0x9C - 0x98 - sizeof(f32)];
    f32 unk9C;
    char pad9C[0xA0 - 0x9C - sizeof(f32)];
    f32 unkA0;
    char padA0[0xA4 - 0xA0 - sizeof(f32)];
    f32 unkA4;
    char padA4[0xA8 - 0xA4 - sizeof(f32)];
    f32 unkA8;
    char padA8[0xB0 - 0xA8 - sizeof(f32)];
    s32 unkB0;
};

struct Node_func_8023CC08_de;
struct Node_func_8023CC08_de {
    struct Node_func_8023CC08_de *next;
    u16 start;
    u16 size;
    char pad8[8];
    u8 *data;
};

extern void func_8023C750_de();

struct func_8023C77C_S1;
struct func_8023C77C_S1 {
    char pad0[0xC];
    void ** unkC;
};

extern void func_8023CFB0_us(void);
extern void func_8023CFD0_de(void);
extern void func_8023CFD8_eu(void * arg0);
#endif
