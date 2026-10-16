#ifndef UNBAKE_SPAN_1000_CODE_80246E34_H
#define UNBAKE_SPAN_1000_CODE_80246E34_H
#include "TYPES.H"
#include "shared/level_input.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_1000/code_8026E1F8.h"
#include "span_1000/code_802609CC.h"
struct func_8024B8DC_S1;
struct func_8024B8DC_S1 {
    char pad0[0x1];
    s8 unk1;
    char pad1[0x3 - 0x1 - sizeof(s8)];
    s8 unk3;
    char pad3[0xB4 - 0x3 - sizeof(s8)];
    s32 unkB4;
    char padB4[0x17C - 0xB4 - sizeof(s32)];
    s32 unk17C;
};

extern float D_800C8B48;

struct ObjectLinks180_2;
typedef struct ObjectLinks180_2 ObjectLinks180_2;

struct Obj_func_80247004_de;
typedef struct Obj_func_80247004_de Obj_func_80247004_de;

struct func_8024B7D4_S1;
typedef struct func_8024B7D4_S1 func_8024B7D4_S1;

struct func_8024A1C0_S1;
struct func_8024A1C0_S1 {
    char pad0[0x3];
    s8 unk3;
    char pad3[0xB4 - 0x3 - sizeof(s8)];
    s32 unkB4;
};

extern float D_800C3A50_de;

struct func_8024B52C_S1;
struct func_8024B52C_S1 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x50 - 0x10 - sizeof(f32)];
    f32 unk50;
    char pad50[0x54 - 0x50 - sizeof(f32)];
    f32 unk54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk58;
    char pad58[0x5C - 0x58 - sizeof(f32)];
    Vector4f unk5C;
    char pad5C[0x6C - 0x5C - sizeof(Vector4f)];
    f32 unk6C;
    char pad6C[0x74 - 0x6C - sizeof(f32)];
    char unk74;
};

struct func_802472E0_S1;
typedef struct func_802472E0_S1 func_802472E0_S1;

struct ObjectState110;
struct ObjectState110 {
    unsigned char padding_0[256];
    s32 unk_100;
    s32 unk_104;
    unsigned char padding_108[6];
    s8 unk_10E;
    s8 unk_10F;
};

extern int D_800D06BC;

struct SineTable;
struct SineTable {
    f32 count;
    f32 value[120];
};

struct func_8024B2C0_S1;
typedef struct func_8024B2C0_S1 func_8024B2C0_S1;

struct func_80247BA4_S1;
struct func_80247BA4_S1 {
    char pad0[0x8];
    Vec3 unk8;
    char pad8[0x70 - 0x8 - sizeof(Vec3)];
    f32 unk70;
    char pad70[0x100 - 0x70 - sizeof(f32)];
    s32 unk100;
    char pad100[0x174 - 0x100 - sizeof(s32)];
    s32 unk174;
};

extern float D_800C3948_de;

struct func_8024AA08_S1;
typedef struct func_8024AA08_S1 func_8024AA08_S1;

struct Box70;
struct Box70 {
    Vec3 corners[8];
    char pad60[0xC];
    s32 mask;
};

struct ObjectLinks23C;
struct ObjectLinks23C {
    char pad0[0x8];
    Vec3 unk_8;
    char pad8[0x14 - 0x8 - sizeof(Vec3)];
    u16 * unk_14;
    char pad14[0x18 - 0x14 - sizeof(u16*)];
    s32 * unk_18;
    char pad18[0x100 - 0x18 - sizeof(s32*)];
    s32 unk_100;
    char pad100[0x1A0 - 0x100 - sizeof(s32)];
    void * unk_1A0;
    char pad1A0[0x1F4 - 0x1A0 - sizeof(void*)];
    u16 * unk_1F4;
    char pad1F4[0x238 - 0x1F4 - sizeof(u16*)];
    u16 unk_238;
};

struct IntegerState104;
struct IntegerState104 {
    unsigned char padding_0[180];
    s32 unk_B4;
    s32 unk_B8;
    s32 unk_BC;
    s32 unk_C0;
    unsigned char padding_C4[60];
    s32 unk_100;
};

struct Obj_func_80247004_de;
struct Obj_func_80247004_de {
    char pad[0x14];
    ObjRecAt2V2 *unk14;
    char pad18[0x5C - 0x18];
    f32 rotation[4]; /* 0x5C */
    char pad6C[0x100 - 0x6C];
    u32 unk100;
};

struct Lookup;
struct Lookup {
    s32 unk0;
    s32 unk4;
    u32 pad8;
    void **value;
};

struct func_80246FF4_S1;
struct func_80246FF4_S1 {
    char pad0[0x5C];
    char unk5C;
};

struct func_8024B2C0_S1;
struct func_8024B2C0_S1 {
    char pad0[0x18];
    s32 * unk18;
    char pad18[0x100 - 0x18 - sizeof(s32*)];
    u32 unk100;
    char pad100[0x23B - 0x100 - sizeof(u32)];
    u8 unk23B;
};

struct ObjectLinks180_2;
struct ObjectLinks180_2 {
    unsigned char padding_0[1];
    s8 unk_1;
    unsigned char padding_2[178];
    char *unk_B4;
    char *unk_B8;
    unsigned char padding_BC[68];
    s32 unk_100;
    unsigned char padding_104[120];
    s32 unk_17C;
};

struct InputRecAt27;


struct func_8024AA08_S2;
struct func_8024AA08_S2 {
    char pad0[0x8];
    u8 unk8;
    char pad8[0x9 - 0x8 - sizeof(u8)];
    u8 unk9;
    char pad9[0x10 - 0x9 - sizeof(u8)];
    s8 unk10;
    char pad10[0x11 - 0x10 - sizeof(s8)];
    s8 unk11;
    char pad11[0x12 - 0x11 - sizeof(s8)];
    s8 unk12;
};

struct Lookup;
typedef struct Lookup Lookup;

struct func_8024AA08_S1;
struct func_8024AA08_S1 {
    char pad0[0x8];
    f32 unk8;
    char pad8[0xC - 0x8 - sizeof(f32)];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    s32 unk14;
    char pad14[0xBC - 0x14 - sizeof(s32)];
    void * unkBC;
    char padBC[0x100 - 0xBC - sizeof(void*)];
    s32 unk100;
    char pad100[0x13A - 0x100 - sizeof(s32)];
    u8 unk13A;
};

struct Box70;
typedef struct Box70 Box70;

struct BlockRecAt0;
struct BlockRecAt0 {
    u32 words[6];
};

struct IntegerState104;
typedef struct IntegerState104 IntegerState104;

struct TypeEntry;
typedef struct TypeEntry TypeEntry;

struct func_80246FF4_S1;
typedef struct func_80246FF4_S1 func_80246FF4_S1;

struct func_802472E0_S1;
struct func_802472E0_S1 {
    char pad0[8];
    f32 unk8;
    char padC[4];
    f32 unk10;
    char pad14[60];
    f32 unk50;
    char pad54[4];
    f32 unk58;
    char pad5C[16];
    f32 unk6C;
    char pad70[88];
    s32 unkC8;
    char padCC[24];
    u16 unkE4;
    s8 unkE6;
    char padE7[25];
    s32 unk100;
    char unk104;
    char pad105[9];
    s8 unk10E;
    s8 unk10F;
    char pad110[8];
    char unk118;
    char pad119[9];
    s8 unk122;
    s8 unk123;
    char pad124[8];
    union { s16 signedValue; u16 unsignedValue; } unk12C;
    char pad12E[2];
    f32 unk130;
    f32 unk134;
    u8 unk138;
    u8 unk139;
};

extern int D_8011CC18;

struct ObjectState110;
typedef struct ObjectState110 ObjectState110;

struct func_8024B8DC_S1;
typedef struct func_8024B8DC_S1 func_8024B8DC_S1;

extern void func_8024B67C_de(void *arg0);

struct func_80247BA4_S1;
typedef struct func_80247BA4_S1 func_80247BA4_S1;

struct SineTable;
typedef struct SineTable SineTable;

extern float D_800C8B50;

struct func_8024795C_S1;
struct func_8024795C_S1 {
    char pad0[0x18];
    s32 * unk18;
    char pad18[0x5C - 0x18 - sizeof(s32*)];
    Vector4f unk5C;
    char pad5C[0x6C - 0x5C - sizeof(Vector4f)];
    f32 unk6C;
    char pad6C[0x100 - 0x6C - sizeof(f32)];
    s32 unk100;
    char pad100[0x1D8 - 0x100 - sizeof(s32)];
    char * unk1D8;
    char pad1D8[0x294 - 0x1D8 - sizeof(char*)];
    f32 unk294;
};

struct TypeEntry;
struct TypeEntry {
    void *unk0;
    void (*callback)(void *, void *);
};

struct InputRecAt27;


struct func_8024795C_S3;
typedef struct func_8024795C_S3 func_8024795C_S3;

struct ObjectRecAt140;
typedef struct ObjectRecAt140 ObjectRecAt140;

struct BlockRecAt0;
typedef struct BlockRecAt0 BlockRecAt0;

struct func_8024B64C_S1;
struct func_8024B64C_S1 {
    char pad0[0x108];
    s16 unk108;
    char pad108[0x10A - 0x108 - sizeof(s16)];
    s16 unk10A;
    char pad10A[0x10E - 0x10A - sizeof(s16)];
    s8 unk10E;
    char pad10E[0x10F - 0x10E - sizeof(s8)];
    s8 unk10F;
};

struct func_8024AA08_S2;
typedef struct func_8024AA08_S2 func_8024AA08_S2;

struct CallbackState288;
struct CollisionInfo;
struct CallbackState288 {
    unsigned char padding_0[644];
    void (*callback)(void *, void *, struct CollisionInfo *);
};

struct func_8024B52C_S1;
typedef struct func_8024B52C_S1 func_8024B52C_S1;

struct func_8024B64C_S1;
typedef struct func_8024B64C_S1 func_8024B64C_S1;

struct ObjectRecAt140;
struct ObjectRecAt140 {
    char pad[0x140];
    Block24 blocks[2];
};

struct ObjectStateC;
typedef struct ObjectStateC ObjectStateC;

extern float D_800C3924_de;

struct ObjectLinks180;
typedef struct ObjectLinks180 ObjectLinks180;

struct ObjectLinks10;
typedef struct ObjectLinks10 ObjectLinks10;

struct func_8024795C_S3;
struct func_8024795C_S3 {
    char pad0[0x140];
    Vector4f unk140;
};

struct func_802472E0_Entry;
struct func_802472E0_Entry {
    u16 unk0;
    char pad2[3];
    u8 unk5;
    char pad6;
    u8 unk7;
};

struct func_802472E0_Entry;
typedef struct func_802472E0_Entry func_802472E0_Entry;

struct ObjectLinks180;
struct ObjectLinks180 {
    unsigned char padding_0[1];
    s8 unk_1;
    unsigned char padding_2[6];
    Vec3 unk_8;
    unsigned char padding_14[164];
    char *unk_B8;
    unsigned char padding_BC[40];
    u16 unk_E4;
    unsigned char padding_E6[26];
    s32 unk_100;
    unsigned char padding_104[120];
    s32 unk_17C;
};

struct CallbackState288;
typedef struct CallbackState288 CallbackState288;

extern void func_8024B654_de(void);

struct CollisionInfo;
struct ObjectLinks10;
struct ObjectLinks10 {
    char pad0[0xC];
    struct CollisionInfo * unk_C;
};

struct func_8024B7D4_S1;
struct func_8024B7D4_S1 {
    char pad0[0x1];
    s8 unk1;
    char pad1[0xC4 - 0x1 - sizeof(s8)];
    s32 unkC4;
    char padC4[0xD0 - 0xC4 - sizeof(s32)];
    s32 unkD0;
    char padD0[0x100 - 0xD0 - sizeof(s32)];
    s32 unk100;
};

struct ObjectLinks23C;
typedef struct ObjectLinks23C ObjectLinks23C;

struct ObjectStateC;
struct ObjectStateC {
    char pad0[0x8];
    func_80203908_S3_U124 unk_8;
};

struct func_8024A1C0_S1;
typedef struct func_8024A1C0_S1 func_8024A1C0_S1;

struct func_8024795C_S1;
typedef struct func_8024795C_S1 func_8024795C_S1;

struct Actor_func_8024A3B0_de;
struct Actor_func_8024A3B0_de {
    char pad0[3];
    s8 field3;
    u32 pad4;
    Vec3 position0;
    u32 pad14[2];
    Vec3 position1;
    u32 pad28[13];
    Vector4f rotation;
    char pad6C[0xB4 - 0x6C];
    s32 fieldB4;
    char padB8[0x140 - 0xB8];
    BlockRecAt0 blocks[4];
};

struct Actor_func_8024A3B0_de;
typedef struct Actor_func_8024A3B0_de Actor_func_8024A3B0_de;

typedef void (*func_8024B4E4_de_FuncPtr)(void *, void *);
extern void func_8026EE20_de(void *arg0, int arg1, void *arg2);
typedef struct func_8024B4E4_S1 func_8024B4E4_S1;
struct func_8024B4E4_S1 {
    char pad0[0x74];
    char unk74;
    char pad74[0xE8 - 0x74 - sizeof(char)];
    char unkE8[0x170 - 0xE8];
    char unk170[0x28C - 0x170];
    func_8024B4E4_de_FuncPtr unk28C;
};

extern void func_802472F0_de(void *);
extern void func_8024715C_de(char *, Vec3 *);
extern void func_8028A27C_de(void *, void *, Vec3 *, Vec3 *);
extern u8 D_800C38F4_de[];
typedef struct Actor36 {
    u8 pad0[8];
    Vec3 position;
    u8 pad14[4];
    s32 *kind;
    u8 pad1C[0x34];
    f32 scaleX;
    u8 pad54[4];
    f32 scaleZ;
    u8 pad5C[0x10];
    f32 heading;
    u8 pad70[4];
    f32 matrix[4][4];
    u8 padB4[0x10];
    s32 size;
    s32 animationKey;
    u8 padCC[4];
    s32 alignment;
    u8 padD4[0x10];
    u16 ownerId;
    s8 animationCount;
    u8 padE7;
    BoxRecAtC box;
    u32 flags;
    struct Anim currentTrack;
    struct Anim previousTrack;
    s16 blendFrames;
    u8 pad12E[2];
    f32 blend;
    f32 blendTime;
    u8 blendStart;
    u8 blendEnd;
    u8 pad13A[0x36];
    u8 state[0x54];
    Vec3 displacement;
    u8 pad1D0[0xBC];
    void (*update)(void *, void *);
} Actor36;


/* Options passed with an actor render submission. */
typedef struct ActorRenderSettings {
    s32 drawModel;
    s32 drawShadow;
    s32 reserved8;
    s32 view;
    s32 reserved10;
    s32 shadowType;
} ActorRenderSettings;

#endif
