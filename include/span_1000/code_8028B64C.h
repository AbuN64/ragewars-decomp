struct LevelBitRecord;
#ifndef UNBAKE_SPAN_1000_CODE_8028B64C_H
#define UNBAKE_SPAN_1000_CODE_8028B64C_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
struct func_8028B64C_S1;
typedef struct func_8028B64C_S1 func_8028B64C_S1;

struct func_8028C34C_S2;
typedef struct func_8028C34C_S2 func_8028C34C_S2;

struct func_8028C5E8_S2;
typedef struct func_8028C5E8_S2 func_8028C5E8_S2;

struct Track_func_8028C6D4_de;
struct Track_func_8028C6D4_de {
    void **nodes;
    s32 pad4[2];
};

extern void func_8028CCA4_de(void *arg0, s32 arg1);

struct func_8028BDE4_S1;
typedef struct func_8028BDE4_S1 func_8028BDE4_S1;

struct func_8028BAF8_S1;
typedef struct func_8028BAF8_S1 func_8028BAF8_S1;

struct func_8028C5E8_S1;
typedef struct func_8028C5E8_S1 func_8028C5E8_S1;

struct Object_func_8028C934_de;
typedef struct Object_func_8028C934_de Object_func_8028C934_de;

struct ObjCode8028B64C;
struct ObjCode8028B64C {
    char pad[0xC50];
    ActorRecAt1D8V1 *actors[0x80];
    int count;
};

struct ObjCode8028B64C;
typedef struct ObjCode8028B64C ObjCode8028B64C;

extern ActorRecAt1D8V1 *func_8028CC34_de(ObjCode8028B64C *obj, int id);

struct func_8028C490_S1;
typedef struct func_8028C490_S1 func_8028C490_S1;

struct WorldRecAt1B6A4;
struct WorldRecAt1B6A4 {
    char pad0[0x1B664];
    Player *objects[16];
    s32 count;
};

struct ObjectRecAtB0;
typedef struct ObjectRecAtB0 ObjectRecAtB0;

extern s32 func_8028B988_de(void *arg0, struct LevelBitRecord *arg1);

struct func_8028C34C_S1;
typedef struct func_8028C34C_S1 func_8028C34C_S1;

struct World;

struct IntegerState54;
typedef struct IntegerState54 IntegerState54;

struct func_8028C1B0_S1;
struct func_8028C1B0_S1 {
    char pad0[0x11C4];
    s32 unk11C4;
    char pad11C4[0x11CC - 0x11C4 - sizeof(s32)];
    s32 unk11CC;
    char pad11CC[0x11D4 - 0x11CC - sizeof(s32)];
    s32 unk11D4;
};

struct Track_func_8028C6D4_de;
typedef struct Track_func_8028C6D4_de Track_func_8028C6D4_de;

struct Owner_func_8028C6D4_de;
struct Owner_func_8028C6D4_de {
    char pad0[0x1504];
    s32 count;
    Track_func_8028C6D4_de tracks[1];
};

extern int D_800D2850;

struct func_8028C248_S2;
struct func_8028C248_S2 {
    char pad0[0x138];
    u32 unk138;
    char pad138[0x140 - 0x138 - sizeof(u32)];
    s32 unk140;
    char pad140[0x11C0 - 0x140 - sizeof(s32)];
    s32 unk11C0;
    char pad11C0[0x11C8 - 0x11C0 - sizeof(s32)];
    s32 unk11C8;
    char pad11C8[0x11D0 - 0x11C8 - sizeof(s32)];
    s32 unk11D0;
};

struct func_8028B64C_S1;
struct func_8028B64C_S1 {
    char pad0[0x80];
    void * unk80;
    char pad80[0x138 - 0x80 - sizeof(void*)];
    char * unk138;
    char pad138[0x1B40C - 0x138 - sizeof(char*)];
    s32 unk1B40C;
};

struct func_8028C02C_S1;
typedef struct func_8028C02C_S1 func_8028C02C_S1;

struct func_8028C400_S2;
typedef struct func_8028C400_S2 func_8028C400_S2;

struct func_8028C248_S2;
typedef struct func_8028C248_S2 func_8028C248_S2;

struct WorldCode8028B64C;
typedef struct WorldCode8028B64C WorldCode8028B64C;

struct ObjectRecAt1A4;
typedef struct ObjectRecAt1A4 ObjectRecAt1A4;

struct ObjectRecAt1A4;
struct ObjectRecAt1A4 {
    u8 pad0[0x8];
    f32 x;
    f32 y;
    f32 z;
    u8 pad14[0x4];
    s32 *kind;
    u8 pad1C[0xC8];
    u16 team;
    u8 padE6[0x8E];
    s32 active;
    u8 pad178[0x2C];
    s8 state; /* 0x1A4 */
    u8 pad1A5[0x2E8 - 0x1A5];
};

struct World_func_8028CAE0_de;
typedef struct World_func_8028CAE0_de World_func_8028CAE0_de;

struct ObjectRecAt1A4;
struct World_func_8028CAE0_de;
struct World_func_8028CAE0_de {
    u8 pad0[0x138];
    struct ObjectRecAt1A4 *objects;
    u8 pad13C[0x4];
    s32 count;
};

extern ObjectRecAt1A4 *func_8028CAE0_de(World_func_8028CAE0_de *world, ObjectRecAt1A4 *self, s32 team, s32 kind, s32 activeOnly);

struct EntryRecAt18V4;
struct EntryRecAt18V4 {
    char pad[0x18];
    ObjRecAtCV1 *def;
};

struct EntryRecAt18V4;
typedef struct EntryRecAt18V4 EntryRecAt18V4;

struct WorldCode8028B64C;
struct WorldCode8028B64C {
    char pad[0x1B664];
    EntryRecAt18V4 *list[16];
    s32 count;
};

extern EntryRecAt18V4 *func_8028C7E0_de(WorldCode8028B64C *world, s32 id);

struct IntegerState54;
struct IntegerState54 {
    unsigned char padding_0[32];
    s32 unk_20;
    unsigned char padding_24[44];
    s32 unk_50;
};

struct func_8028C5E8_S2;
struct func_8028C5E8_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x8 - 0x4 - sizeof(void*)];
    void * unk8;
    char pad8[0xC - 0x8 - sizeof(void*)];
    f32 unkC;
};

struct func_8028C490_S2;
typedef struct func_8028C490_S2 func_8028C490_S2;

struct func_8028C1B0_S1;
typedef struct func_8028C1B0_S1 func_8028C1B0_S1;

struct EntryRecAt10;
struct EntryRecAt10 {
    char pad[8];
    f32 x;
    f32 y;
    f32 z;
};

struct EntryRecAt10;
struct OwnerCode8028B64C;
struct OwnerCode8028B64C {
    char pad[0x1024];
    struct EntryRecAt10 *entries[0x20];
    s32 count;
};

struct EntryRecAt10;
struct OwnerCode8028B64C;
extern struct EntryRecAt10 *func_8028CBB0_de(struct OwnerCode8028B64C *owner, struct EntryRecAt10 *pos);

struct func_8028C34C_S1;
struct func_8028C34C_S1 {
    char pad0[0x11C0];
    s32 unk11C0;
    char pad11C0[0x11C4 - 0x11C0 - sizeof(s32)];
    s32 unk11C4;
    char pad11C4[0x11D0 - 0x11C4 - sizeof(s32)];
    void * unk11D0;
    char pad11D0[0x11D4 - 0x11D0 - sizeof(void*)];
    void * unk11D4;
};

struct func_8028C490_S2;
struct func_8028C490_S2 {
    char pad0[0xF];
    u8 unkF;
};

struct func_8028C5E8_S1;
struct func_8028C5E8_S1 {
    char pad0[0x11D8];
    IntrusiveList unk11D8;
    char pad11D8[0x11EC - 0x11D8 - sizeof(IntrusiveList)];
    char unk11EC;
};

struct World;

extern EntryRecAt18V4 *func_8028C108_de(World *world, s32 id);

struct func_8028C400_S2;
struct func_8028C400_S2 {
    char pad0[0x1];
    u8 unk1;
    char pad1[0xE - 0x1 - sizeof(u8)];
    u8 unkE;
    char padE[0xF - 0xE - sizeof(u8)];
    u8 unkF;
};

struct Sample;
typedef struct Sample Sample;

struct Object_func_8028C934_de;
struct Shape_func_8021A2D4_de_2;
struct Object_func_8028C934_de {
    char pad0[0x18];
    struct Shape_func_8021A2D4_de_2 *descriptor;
    char pad1C[0xE4 - 0x1C];
    u16 model;
    char padE6[0x100 - 0xE6];
    s32 flags;
    char pad104[0x23E - 0x104];
    signed char slot;
};

struct func_8028C34C_S2;
struct func_8028C34C_S2 {
    char pad0[0xF];
    u8 unkF;
    char padF[0x14 - 0xF - sizeof(u8)];
    char unk14;
};

struct func_8028BAF8_S1;
struct func_8028BAF8_S1 {
    char pad0[0x13];
    u8 unk13;
};

struct WorldRecAt10B8;
struct WorldRecAt10B8 {
    char pad0[0x144];
    Object_func_8028C934_de *listA[512];
    s32 countA;
    Object_func_8028C934_de *listB[128];
    s32 countB;
    char padB4C[0xC50 - 0xB4C];
    Object_func_8028C934_de *all[128];
    s32 countAll;
    Object_func_8028C934_de *type1[64];
    s32 countType1;
    s32 padF58;
    Object_func_8028C934_de *flagged[32];
    s32 countFlagged;
    Object_func_8028C934_de *type5[16];
    s32 countType5;
    Object_func_8028C934_de *model64F[32];
    s32 count64F;
    Object_func_8028C934_de *model64D[4];
    s32 count64D;
};

struct func_8028C400_S1;
struct func_8028C400_S1 {
    char pad0[0x11C0];
    s32 unk11C0;
    char pad11C0[0x11C4 - 0x11C0 - sizeof(s32)];
    s32 unk11C4;
    char pad11C4[0x11D0 - 0x11C4 - sizeof(s32)];
    char * unk11D0;
    char pad11D0[0x11D4 - 0x11D0 - sizeof(char*)];
    char * unk11D4;
};

struct func_8028C174_S1;
typedef struct func_8028C174_S1 func_8028C174_S1;

struct func_8028BDE4_S1;
struct func_8028BDE4_S1 {
    char pad0[0x28];
    s32 unk28;
    char pad28[0x58 - 0x28 - sizeof(s32)];
    s32 unk58;
    char pad58[0x98 - 0x58 - sizeof(s32)];
    void * unk98;
};

struct ObjectRecAtB0;
struct ObjectRecAtB0 {
    u8 pad0[0x80];
    void *resource;
    u8 pad84[0x2C];
    Table *list;
};

extern s32 func_8028BCBC_de(ObjectRecAtB0 *arg0, s32 arg1);

struct func_8028CC80_S1;
typedef struct func_8028CC80_S1 func_8028CC80_S1;

struct WorldRecAt10B8;
typedef struct WorldRecAt10B8 WorldRecAt10B8;

struct func_8028CC80_S1;
struct func_8028CC80_S1 {
    char pad0[0xC50];
    void * unkC50;
    char padC50[0xE50 - 0xC50 - sizeof(void*)];
    s32 unkE50;
};

struct func_8028C02C_S1;
struct func_8028C02C_S1 {
    func_80203908_S3_U124 unk0;
    char pad0[0x4 - 0x0 - sizeof(func_80203908_S3_U124)];
    f32 unk4;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    func_80203908_S3_U124 unk8;
};

struct Owner_func_8028C6D4_de;
typedef struct Owner_func_8028C6D4_de Owner_func_8028C6D4_de;

struct func_8028C174_S1;
struct func_8028C174_S1 {
    char pad0[0x24];
    s32 unk24;
    char pad24[0x54 - 0x24 - sizeof(s32)];
    s32 * unk54;
};

struct WorldRecAt1B6A4;
typedef struct WorldRecAt1B6A4 WorldRecAt1B6A4;

extern Player *func_8028C834_de(WorldRecAt1B6A4 *world);




struct func_8028C400_S1;
typedef struct func_8028C400_S1 func_8028C400_S1;

struct func_8028C490_S1;
struct func_8028C490_S1 {
    char pad0[0x11C0];
    s32 unk11C0;
    char pad11C0[0x11C4 - 0x11C0 - sizeof(s32)];
    s32 unk11C4;
    char pad11C4[0x11D0 - 0x11C4 - sizeof(s32)];
    Rec_func_8024C92C_de * unk11D0;
    char pad11D0[0x11D4 - 0x11D0 - sizeof(Rec_func_8024C92C_de*)];
    Rec_func_8024C92C_de * unk11D4;
};




struct Sample;
struct Sample {
    char pad0[0x28];
};

struct ModelDef;
typedef struct ModelDef ModelDef;


/* Shared object layout established by level-bits consumers. */
struct LevelBitRecord {
    u8 padding000[0x19E];
    u16 bitIndex; /* 0x19E */
};

#endif
