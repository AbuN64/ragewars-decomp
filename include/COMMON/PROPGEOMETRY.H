#ifndef COMMON_PROPGEOMETRY_H
#define COMMON_PROPGEOMETRY_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/GFX.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/MANAGER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PROBE.H"
struct StaticObject;

struct func_8024F490_Inner;
struct func_8024F490_Inner {
    char pad[0x12];
    u8 value;
};

union func_802500A4_S1_UE0;
typedef union func_802500A4_S1_UE0 func_802500A4_S1_UE0;

union func_802500A4_S1_UE0;
union func_802500A4_S1_UE0 {
    s8 v0;
    u8 v1;
};

struct func_802500A4_S1;
struct func_802500A4_S1 {
    char pad0[0x8];
    CVector3 unk8;
    char pad8[0x18 - 0x8 - sizeof(CVector3)];
    void * unk18;
    char pad18[0xD8 - 0x18 - sizeof(void*)];
    u16 unkD8;
    char padD8[0xDC - 0xD8 - sizeof(u16)];
    s32 unkDC;
    char padDC[0xE0 - 0xDC - sizeof(s32)];
    func_802500A4_S1_UE0 unkE0;
};

extern float D_800C3DF0_de;

struct func_802500A4_S2;
struct func_802500A4_S2 {
    char pad0[0xE];
    s8 unkE;
    char padE[0xF - 0xE - sizeof(s8)];
    s8 unkF;
    char padF[0x24 - 0xF - sizeof(s8)];
    s32 unk24;
};

extern float D_800C3E0C_de;


struct func_8024E914_S1;
typedef struct func_8024E914_S1 func_8024E914_S1;


struct func_8024F624_S1;
struct func_8024F624_S1 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x18 - 0x10 - sizeof(f32)];
    s32 * unk18;
    char pad18[0x174 - 0x18 - sizeof(s32*)];
    s32 unk174;
    char pad174[0x194 - 0x174 - sizeof(s32)];
    f32 unk194;
    char pad194[0x198 - 0x194 - sizeof(f32)];
    f32 unk198;
};

struct Actor_func_8024ED90_de;
typedef struct Actor_func_8024ED90_de Actor_func_8024ED90_de;

struct func_8024F460_S1;
typedef struct func_8024F460_S1 func_8024F460_S1;

struct PropGeometry;
typedef struct PropGeometry PropGeometry;


struct func_8024F490_S1;
typedef struct func_8024F490_S1 func_8024F490_S1;

struct RecordRecAt1A;
struct RecordRecAt1A {
    s32 value;
    f32 scale;
    u16 id;
    u16 segment;
    u16 flags;
    u16 model;
    s16 height;
    s8 extents[6];
    u8 placement;
    u8 cellX;
    u8 cellZ;
};

struct ModelOwner;
typedef struct ModelOwner ModelOwner;

struct func_8024F490_Inner;
typedef struct func_8024F490_Inner func_8024F490_Inner;

struct PlacedPropRecord;
struct PlacedPropRecord {
    s32 value;
    CVector3 position;
    CVector3 scale;
    char pad1C[0];
    u16 extents[6];
    u16 id;
    u16 segment;
    u16 model;
    u8 flags;
    s8 rotation[4];
};

struct PropGeometry;
struct PropGeometry {
    s32 kind;
    char pad4[4];
    f32 radius;
    char padC[2];
    s8 variant;
    char padF[3];
    u8 material;
    char pad13[0xD];
    f32 speed;
    u32 radiusSquared;
};

struct PlacedProp;
struct PropGeometry;
struct PlacedProp {
    u8 state;
    char pad1[3];
    u16 id;
    char pad6[2];
    CVector3 position;
    void *segment;
    struct PropGeometry *model;
    s32 owner;
    char pad20[8];
    char transform[0x40];
    char matrix[0x40];
    s32 fieldA8;
    s32 fieldAC;
    s32 fieldB0;
    s32 fieldB4;
    CVector3 min;
    CVector3 max;
    s32 key;
    s32 fieldD4;
    u16 flags;
    u8 colorFrame;
    char padDB;
    s32 fieldDC;
    u8 fade;
    char padE1[0xE8 - 0xE1];
};

struct PlacedProp;
typedef struct PlacedProp PlacedProp;

struct DescriptorRecAt24;
typedef struct DescriptorRecAt24 DescriptorRecAt24;


struct DescriptorRecAt24;
struct DescriptorRecAt24 {
    char pad0[0xE];
    s8 key;
    s8 key2;
    char pad10[2];
    s8 argument;
    char pad13[0x24 - 0x13];
    s32 period;
};

struct DescriptorRecAt24;
struct Owner_func_80250274_de;

struct func_802500A4_S2;
typedef struct func_802500A4_S2 func_802500A4_S2;

struct func_8024F848_S1;
struct func_8024F848_S1 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0x18 - 0x4 - sizeof(u16)];
    void * unk18;
};

struct func_8024E914_S1;
struct func_8024E914_S1 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0xE4 - 0x4 - sizeof(u16)];
    u16 unkE4;
};

extern float D_800C3D98_de;

struct func_8024F608_S1;
typedef struct func_8024F608_S1 func_8024F608_S1;

struct func_802500A4_S1;
typedef struct func_802500A4_S1 func_802500A4_S1;

struct GlobalStateRecAt1C;
typedef struct GlobalStateRecAt1C GlobalStateRecAt1C;

struct GlobalStateRecAt1C;

struct func_8024F590_S1;
struct func_8024F590_S1 {
    char pad0[0x194];
    f32 unk194;
    char pad194[0x19C - 0x194 - sizeof(f32)];
    u16 unk19C;
    char pad19C[0x1A0 - 0x19C - sizeof(u16)];
    f32 unk1A0;
};

struct func_8024F624_S1;
typedef struct func_8024F624_S1 func_8024F624_S1;

struct StaticObject;

struct Descriptor_func_802504B0_de;
struct Descriptor_func_802504B0_de {
    char pad0[0xE];
    s8 key;
    char padF[3];
    s8 argument;
};
struct Descriptor_func_802504B0_de;
struct ModelOwner;

struct func_8024F590_S1;
typedef struct func_8024F590_S1 func_8024F590_S1;

struct StaticObject;
typedef struct StaticObject StaticObject;

extern f32 D_8013B190;

struct Actor_func_8024ED90_de;

struct PlacedPropRecord;
typedef struct PlacedPropRecord PlacedPropRecord;

extern float D_800C3E08_de;

struct func_8024F460_S1;
struct func_8024F460_S1 {
    char pad0[0x1C4];
    int unk1C4;
};

struct func_8024F848_S1;
typedef struct func_8024F848_S1 func_8024F848_S1;

struct func_8024F608_S1;
struct func_8024F608_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x1A4 - 0x18 - sizeof(void*)];
    float unk1A4;
};

struct RecordRecAt1A;
typedef struct RecordRecAt1A RecordRecAt1A;

extern float D_800C3E00_de;

struct func_8024F8CC_S1;
typedef struct func_8024F8CC_S1 func_8024F8CC_S1;

struct Owner_func_80250274_de;
typedef struct Owner_func_80250274_de Owner_func_80250274_de;

struct func_8024EF18_S1;
struct func_8024EF18_S1 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x40 - 0x10 - sizeof(f32)];
    f32 unk40;
};

struct func_8024F490_S1;
struct func_8024F490_S1 {
    char pad0[0x1];
    u8 unk1;
    char pad1[0x3 - 0x1 - sizeof(u8)];
    u8 unk3;
    char pad3[0x14 - 0x3 - sizeof(u8)];
    void * unk14;
    char pad14[0x18 - 0x14 - sizeof(void*)];
    char * unk18;
    char pad18[0x194 - 0x18 - sizeof(char*)];
    f32 unk194;
    char pad194[0x19C - 0x194 - sizeof(f32)];
    u16 unk19C;
    char pad19C[0x1A0 - 0x19C - sizeof(u16)];
    f32 unk1A0;
    char pad1A0[0x1A4 - 0x1A0 - sizeof(f32)];
    f32 unk1A4;
    char pad1A4[0x1C0 - 0x1A4 - sizeof(f32)];
    s32 unk1C0;
};

struct func_8024F8CC_S1;
struct func_8024F8CC_S1 {
    char pad0[0x60];
    s32 * unk60;
    char pad60[0x17C - 0x60 - sizeof(s32*)];
    char unk17C;
};

struct func_8024EF18_S1;
typedef struct func_8024EF18_S1 func_8024EF18_S1;

extern char D_0024F8DC;
extern char D_800C3DAC_de[];
extern char D_800C8ED0;

typedef struct ResourceOwner { u8 pad0[0x1c]; s32 key; u8 pad20[0x88]; s32 index; s32 selected; s32 size; void *resource; } ResourceOwner;
extern char D_800C8F70[];
extern char D_800C3E94_de[];
extern char D_0026D7D4_de[];

extern char D_800C3E70[];

extern s32 func_8026E340_de(void);
#endif
