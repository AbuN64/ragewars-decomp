#ifndef COMMON_NODERECAT2A8_H
#define COMMON_NODERECAT2A8_H
#include "TYPES.H"
#include "COMMON/PAK_MENU.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/TEXTLAYERMETRICS.H"

extern int D_800CC37C;

extern int D_800DE898;

struct Shared_PakMenu;


struct Shared_PakMenu;


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


struct ModeRecAt8;
struct ModeRecAt8 {
    int width;
    int height;
    int rest[5];
};

extern int D_800CC378;

struct Shared_PakMenu;

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


extern int D_80141000;

struct Shared_PakMenu;


struct ModeRecAt8;
typedef struct ModeRecAt8 ModeRecAt8;





struct Shared_PakMenu;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8040B444_de(struct LayeredText *field, struct Shared_PakMenu *holder);
#endif
#endif
