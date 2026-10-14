#ifndef UNBAKE_SPAN_1000_CODE_8028469C_H
#define UNBAKE_SPAN_1000_CODE_8028469C_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
/* Section zero of packed and expanded mesh resources. */
typedef struct PackedMeshMaterial {
    s32 textureId;
    s32 flags;
    u16 renderMode;
    u8 mode;
    u8 reservedB;
    u8 primaryColor[4];
    u8 secondaryColor[4];
    u16 width;
    u16 height;
} PackedMeshMaterial;
typedef struct MeshMaterial {
    s32 flags;
    s16 renderMode;
    u8 mode;
    u8 reserved7;
    s32 texture;
    u8 reservedC[4];
    u8 primaryColor[4];
    u8 secondaryColor[4];
    u16 width;
    u16 height;
} MeshMaterial;

struct Obj_func_80284DC4_de;
struct Obj_func_80284DC4_de {
    char pad[4];
    unsigned short unk4;
    char pad6[2];
    f32 pos[3];
    char pad14[0x138];
    short unk14C;
};

struct func_8028469C_S1;
struct func_8028469C_S1 {
    char pad0[0xFC28];
    char unkFC28;
};

extern float func_8028489C_de(void *arg0);

struct func_8028469C_S1;
typedef struct func_8028469C_S1 func_8028469C_S1;

struct ObjRecAt12;
typedef struct ObjRecAt12 ObjRecAt12;

struct ObjectLinks188;
struct ObjectLinks188 {
    unsigned char padding_0[280];
    void *unk_118;
    unsigned char padding_11C[104];
    f32 unk_184;
};

struct func_80285540_S1;
typedef struct func_80285540_S1 func_80285540_S1;

struct func_80284870_S1;
struct func_80284870_S1 {
    char pad0[0x118];
    void * unk118;
    char pad118[0x180 - 0x118 - sizeof(void*)];
    float unk180;
};

extern s32 func_8028480C_de(s32 arg0);

struct func_8028472C_S3;
struct func_8028472C_S3 {
    char pad0[0x118];
    s32 unk118;
    char pad118[0x1F4 - 0x118 - sizeof(s32)];
    void * unk1F4;
};

struct func_8028469C_S3;
struct func_8028469C_S3 {
    char pad0[0x8];
    s8 unk8;
};

struct ObjRecAt4V2;
typedef struct ObjRecAt4V2 ObjRecAt4V2;

struct func_8028472C_S2;
typedef struct func_8028472C_S2 func_8028472C_S2;

struct Arg1;
typedef struct Arg1 Arg1;

struct Obj_func_80284DC4_de;
extern void func_80284E9C_de(int context, struct Obj_func_80284DC4_de * * objects, int count);

extern float D_800C4EB8_de;

extern void func_80285100_eu(long long arg1);

struct func_80284870_S1;
typedef struct func_80284870_S1 func_80284870_S1;

struct func_8028469C_S4;
typedef struct func_8028469C_S4 func_8028469C_S4;

extern f32 func_802848BC_de(void *arg0);

struct func_80284AF4_S3;
struct func_80284AF4_S3 {
    char pad0[0x8];
    Vec3 unk8;
    char pad8[0x16E0 - 0x8 - sizeof(Vec3)];
    void * unk16E0;
};

struct func_80284AF4_S3;
typedef struct func_80284AF4_S3 func_80284AF4_S3;

struct func_80284FC8_S3;
struct func_80284FC8_S3 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0x8 - 0x4 - sizeof(u16)];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x5C - 0x10 - sizeof(f32)];
    s32 unk5C;
    char pad5C[0x12C - 0x5C - sizeof(s32)];
    s32 unk12C;
    char pad12C[0x1EC - 0x12C - sizeof(s32)];
    s8 * unk1EC;
};

extern float D_800C4EA0_de;

struct func_80285540_S1;
struct func_80285540_S1 {
    char pad0[0x4];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    u16 unk8;
    char pad8[0xA - 0x8 - sizeof(u16)];
    u8 unkA;
    char padA[0xC - 0xA - sizeof(u8)];
    u8 unkC;
    char padC[0xD - 0xC - sizeof(u8)];
    u8 unkD;
    char padD[0xE - 0xD - sizeof(u8)];
    u8 unkE;
    char padE[0xF - 0xE - sizeof(u8)];
    u8 unkF;
    char padF[0x10 - 0xF - sizeof(u8)];
    u8 unk10;
    char pad10[0x11 - 0x10 - sizeof(u8)];
    u8 unk11;
    char pad11[0x12 - 0x11 - sizeof(u8)];
    u8 unk12;
    char pad12[0x13 - 0x12 - sizeof(u8)];
    u8 unk13;
    char pad13[0x14 - 0x13 - sizeof(u8)];
    u16 unk14;
    char pad14[0x16 - 0x14 - sizeof(u16)];
    u16 unk16;
};

struct func_8028472C_S3;
typedef struct func_8028472C_S3 func_8028472C_S3;

struct func_8028469C_S4;
struct func_8028469C_S4 {
    char pad0[0x118];
    void * unk118;
    char pad118[0x124 - 0x118 - sizeof(void*)];
    s32 unk124;
    char pad124[0x1EC - 0x124 - sizeof(s32)];
    void * unk1EC;
};

struct ObjRecAt4V2;
struct ObjRecAt4V2 {
    void * unk0;
    s32 unk4;
};

struct func_8028509C_S1;
struct func_8028509C_S1 {
    char pad0[0xFC14];
    void * unkFC14;
};

struct func_8028469C_S3;
typedef struct func_8028469C_S3 func_8028469C_S3;

struct func_8028509C_S2;
struct func_8028509C_S2 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0x5C - 0x8 - sizeof(f32)];
    s32 unk5C;
    char pad5C[0x12C - 0x5C - sizeof(s32)];
    void * unk12C;
    char pad12C[0x1F4 - 0x12C - sizeof(void*)];
    void * unk1F4;
};

struct ObjRecAt12;
struct ObjRecAt12 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad8[0x6];
    s8 unk12;
};

struct Arg1;
struct Arg1 {
    char pad0[0x24];
    s32 field24;
    char pad28[0x100];
    Vec3 position128;
};

struct func_80284AF4_S1;
struct func_80284AF4_S1 {
    char pad0[0x4];
    u16 unk4;
    char pad4[0x8 - 0x4 - sizeof(u16)];
    f32 unk8;
    char pad8[0x118 - 0x8 - sizeof(f32)];
    void * unk118;
};

struct func_8028472C_S1;
typedef struct func_8028472C_S1 func_8028472C_S1;

struct func_8028472C_S2;
struct func_8028472C_S2 {
    char pad0[0x5C];
    s32 unk5C;
    char pad5C[0x118 - 0x5C - sizeof(s32)];
    func_8028472C_S2_U118 unk118;
};

struct Obj_func_80284DC4_de;
typedef struct Obj_func_80284DC4_de Obj_func_80284DC4_de;

struct func_80285540_S2;
struct func_80285540_S2 {
    char pad0[0x4];
    s16 unk4;
    char pad4[0x6 - 0x4 - sizeof(s16)];
    u8 unk6;
    char pad6[0x8 - 0x6 - sizeof(u8)];
    s32 unk8;
    char pad8[0x10 - 0x8 - sizeof(s32)];
    u8 unk10;
    char pad10[0x11 - 0x10 - sizeof(u8)];
    u8 unk11;
    char pad11[0x12 - 0x11 - sizeof(u8)];
    u8 unk12;
    char pad12[0x13 - 0x12 - sizeof(u8)];
    u8 unk13;
    char pad13[0x14 - 0x13 - sizeof(u8)];
    u8 unk14;
    char pad14[0x15 - 0x14 - sizeof(u8)];
    u8 unk15;
    char pad15[0x16 - 0x15 - sizeof(u8)];
    u8 unk16;
    char pad16[0x17 - 0x16 - sizeof(u8)];
    u8 unk17;
    char pad17[0x18 - 0x17 - sizeof(u8)];
    u16 unk18;
    char pad18[0x1A - 0x18 - sizeof(u16)];
    u16 unk1A;
};

struct func_80284AF4_S1;
typedef struct func_80284AF4_S1 func_80284AF4_S1;

extern float D_800C4E90_de;

struct func_80284FC8_S3;
typedef struct func_80284FC8_S3 func_80284FC8_S3;

extern void func_80284870_de(f32 arg0);

struct ObjectLinks188;
typedef struct ObjectLinks188 ObjectLinks188;

struct func_8028472C_S1;
struct func_8028472C_S1 {
    char pad0[0xFC14];
    IntrusiveList unkFC14;
};

extern double D_800C4EB0_de;

struct func_8028509C_S1;
typedef struct func_8028509C_S1 func_8028509C_S1;

extern void func_80284DC4_de(s32 unused, Obj_func_80284DC4_de *center, Obj_func_80284DC4_de **objects, s32 count);

struct func_80285540_S2;
typedef struct func_80285540_S2 func_80285540_S2;

struct func_8028509C_S2;
typedef struct func_8028509C_S2 func_8028509C_S2;

#endif
