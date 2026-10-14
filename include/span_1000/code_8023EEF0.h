#ifndef UNBAKE_SPAN_1000_CODE_8023EEF0_H
#define UNBAKE_SPAN_1000_CODE_8023EEF0_H
#include "types.h"

/* Sortable render item, moved as an eight-byte record. */
typedef struct RenderSortRecord {
    s32 index;
    f32 depth;
} RenderSortRecord;
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "types.h"
#include "shared/box_contact.h"
extern int func_80240638_de(void *left, void *right);

struct ObjRecAtCC;
struct ObjRecAtCC {
    s32 unk0;
    char pad0[0x54 - 0x0 - sizeof(s32)];
    s32 unk54;
    char pad54[0x58 - 0x54 - sizeof(s32)];
    s32 unk58;
    char pad58[0xCC - 0x58 - sizeof(s32)];
    f32 unkCC;
};

extern s32 func_80240698_de(void *arg0, s32 arg1, Vec3 t, s32 arg5, s32 arg6, void *arg7);

struct Plane;
typedef struct Plane Plane;

struct func_80240C9C_S1;
struct func_80240C9C_S1 {
    char pad0[0x18];
    Vec3 unk18;
    char pad18[0x24 - 0x18 - sizeof(Vec3)];
    Vec3 unk24;
    char pad24[0x30 - 0x24 - sizeof(Vec3)];
    Vec3 unk30;
    char pad30[0x48 - 0x30 - sizeof(Vec3)];
    Vec3 unk48;
};

struct EntityTable;
struct EntityTable {
    char pad0[0x144];
    u8 *entities[0x200];
    s32 count;
};

struct func_8023F634_S1;
typedef struct func_8023F634_S1 func_8023F634_S1;

extern void func_80240538_de(float *s, float *d);

struct Shape;
struct func_8023F42C_S1;
struct func_8023F42C_S1 {
    char pad0[0xC];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    f32 unk14;
    char pad14[0x40 - 0x14 - sizeof(f32)];
    struct Shape * unk40;
    char pad40[0x44 - 0x40 - sizeof(Shape*)];
    f32 unk44;
    char pad44[0x48 - 0x44 - sizeof(f32)];
    f32 unk48;
    char pad48[0x4C - 0x48 - sizeof(f32)];
    f32 unk4C;
    char pad4C[0x50 - 0x4C - sizeof(f32)];
    f32 unk50;
    char pad50[0x54 - 0x50 - sizeof(f32)];
    f32 unk54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk58;
};

struct func_8023F42C_S2;
struct func_8023F42C_S2 {
    char pad0[0x174];
    s32 unk174;
};

struct func_8023F42C_S2;
typedef struct func_8023F42C_S2 func_8023F42C_S2;

extern float D_800C373C_de;

struct func_8023F634_S1;
struct func_8023F634_S1 {
    char pad0[0xC];
    f32 unkC;
    char padC[0x10 - 0xC - sizeof(f32)];
    char unk10;
    char pad10[0x14 - 0x10 - sizeof(char)];
    f32 unk14;
    char pad14[0x40 - 0x14 - sizeof(f32)];
    s32 * unk40;
    char pad40[0x44 - 0x40 - sizeof(s32*)];
    f32 unk44;
    char pad44[0x48 - 0x44 - sizeof(f32)];
    f32 unk48;
    char pad48[0x4C - 0x48 - sizeof(f32)];
    f32 unk4C;
    char pad4C[0x50 - 0x4C - sizeof(f32)];
    f32 unk50;
    char pad50[0x54 - 0x50 - sizeof(f32)];
    f32 unk54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk58;
};

struct ObjRecAtCC;
typedef struct ObjRecAtCC ObjRecAtCC;

struct EntityTable;
typedef struct EntityTable EntityTable;

struct func_80241250_S1;
typedef struct func_80241250_S1 func_80241250_S1;

struct Quad;
struct Quad {
    char pad0[0x14];
    s32 kind;
    Vec3 corner[4];
    Vec3 normal;
};

struct func_80240C9C_S1;
typedef struct func_80240C9C_S1 func_80240C9C_S1;

struct func_80241250_S1;
struct func_80241250_S1 {
    char pad0[0x18];
    Vec3 unk18;
    char pad18[0x48 - 0x18 - sizeof(Vec3)];
    f32 unk48;
    char pad48[0x4C - 0x48 - sizeof(f32)];
    f32 unk4C;
    char pad4C[0x50 - 0x4C - sizeof(f32)];
    f32 unk50;
};

struct Shape_func_802764D4_de_2;
extern void func_802405FC_de(RenderSortRecord *left, RenderSortRecord *right);

struct Plane;
struct Plane {
    char pad[0x18];
    Vec3 pos;
    char pad24[0x24];
    Vec3 normal;
};

struct func_8023F42C_S1;
typedef struct func_8023F42C_S1 func_8023F42C_S1;

extern void func_80240C8C_de(void *arg0);

s32 func_8024E2C4_de(void *);
void func_8022B730_de(void *, f32);

extern s32 func_8023F750_de(BoxContactRay *, void *, BoxContactActor *, Vec3 *, Vec3 *, BoxContactTransform *, s32);

#endif
