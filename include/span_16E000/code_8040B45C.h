#ifndef UNBAKE_SPAN_16E000_CODE_8040B45C_H
#define UNBAKE_SPAN_16E000_CODE_8040B45C_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8043F69C.h"
extern void func_8040B7E0_de(void);

extern int D_800CC37C;

extern int D_800DE898;

struct Record_func_8040B58C_de;
typedef struct Record_func_8040B58C_de Record_func_8040B58C_de;

extern void func_8040C09C_de();

struct Action_func_8040B4E0_de;
struct Action_func_8040B4E0_de {
    char pad0[0x1C];
    void *unk1C;
    func_80242278_S1 *unk20;
    void *unk24;
};

extern void func_8040B830_de(void);

struct NodeRecAt2A8;
typedef struct NodeRecAt2A8 NodeRecAt2A8;

struct ActionRecAt24;
typedef struct ActionRecAt24 ActionRecAt24;

struct ShapeRecAt18V2;
struct ShapeRecAt18V2 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
};

extern int D_800DE8A0[];

extern void func_8040B814_de(void);

struct ModeRecAt8;
struct ModeRecAt8 {
    int width;
    int height;
    int rest[5];
};

extern int D_800CC378;

struct Record_func_8040B58C_de;
struct Record_func_8040B58C_de {
    char pad0[0x1C];
    ObjRecAt5DC *player;
    func_80242278_S1 *inner;
    void *unk24;
};

struct NodeRecAt2A8;
struct NodeRecAt2A8 {
    int unused;
    struct NodeRecAt2A8 *next;
    char pad[0x294];
    float width;
    float height;
    int x;
    int y;
};

struct ActionRecAt24;
struct ActionRecAt24 {
    char a[0x1C];
    ObjRecAt5DC *unk1C;
    s32 unk20;
    s32 unk24;
};

extern s32 func_8040B648_de(s32 arg0, ActionRecAt24 *arg1);

extern int D_80141000;

struct Action_func_8040B4E0_de;
typedef struct Action_func_8040B4E0_de Action_func_8040B4E0_de;

extern void func_8040C2F8_de();

struct ModeRecAt8;
typedef struct ModeRecAt8 ModeRecAt8;

extern void func_8040C318_de();

extern void func_8040B7F8_de(void);

extern void func_8040BBB0_de();

extern void func_8040B84C_de(void);

struct Record_func_80409BDC_de;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8040B444_de(struct LayeredText *field, struct Record_func_80409BDC_de *holder);
#endif

#endif
