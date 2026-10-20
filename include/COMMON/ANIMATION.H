#ifndef COMMON_ANIMATION_H
#define COMMON_ANIMATION_H
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct func_80419D04_S1;
struct func_80419D04_S1 {
    char pad0[0x4];
    u8 unk4;
    char pad4[0x3F];
    s32 unk44;
    s32 unk48;
    s32 unk4C[5];
    s32 unk60[5];
    s32 unk74;
    struct Resource_func_80419E54_de *unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
};

struct MenuFadeWidget;
struct MenuFadeWidget {
    char pad0[0xC];
    s16 field_0C;
    s16 field_0E;
    char pad10[0x12 - 0x10];
    s16 field_12;
    char pad14[0x20 - 0x14];
    union { s32 field_20; f32 progressX; };
    f32 field_24;
    char pad28[0x2C - 0x28];
    u32 colours[4];
    char pad3C[0x44 - 0x3C];
    struct MenuFadeWidget *frame;
    struct MenuFadeWidget *item;
    f32 scaleX;
    f32 scaleY;
    char pad54[4];
    s32 phase;
    s32 running;
    u32 copies[4];
    u32 greenStep;
    u32 redStep;
    s32 active;
};

struct Animation;
typedef struct Animation Animation;

struct ObjectCode804196C0;
struct Resource_func_80419E54_de;
struct ObjectCode804196C0 {
    char pad0[0x44];
    s32 busy;
    char pad48[0x4C - 0x48];
    s32 entries[(0x74 - 0x4C) / 4];
    s32 index;
    struct Resource_func_80419E54_de *target;
};

extern float D_800E1470;

struct FrameSequence;



extern float D_800E1474;

struct Animation;
struct Animation {
    char pad0[0xC];
    s16 kindA;
    s16 kindB;
    char pad10[2];
    s16 flags;
    char pad14[0x30];
    s32 widget;
    s32 *frames;
    char pad4C[4];
    s32 count;
    s32 unk54;
    char pad58[4];
    s32 unk5C;
    char pad60[4];
};

struct ObjectRecAt84;
struct ObjectRecAt84 {
    char pad0[0x44];
    s32 busy;
    char pad48[0x84 - 0x48];
    s32 pending;
};

struct FrameSequence;

struct MenuFadeWidget;
typedef struct MenuFadeWidget MenuFadeWidget;


struct ObjectRecAt84;
extern s32 func_80419F38_de(struct ObjectRecAt84 *object);


struct Triple;

struct FrameSequence;


struct Resource_func_80419E54_de;
struct SourceRecAt84;
struct SourceRecAt84 {
    char pad[0x78];
    struct Resource_func_80419E54_de *target;
    char pad7C[0x83 - 0x7C];
    u8 value;
    s32 pending;
};

struct Triple;

struct MenuResourceWidget;
typedef struct MenuResourceWidget MenuResourceWidget;
extern MenuResourceWidget *func_80419E54_de(s32, s32);

struct SourceRecAt84;
extern void func_80419F24_de(struct SourceRecAt84 *source);

struct func_80419D04_S1;
typedef struct func_80419D04_S1 func_80419D04_S1;

struct FrameSequence;

struct MenuResourceWidget;
struct Resource_func_80419E54_de;
struct MenuResourceWidget {
    char pad0[0xC];
    short a;
    short b;
    short pad1;
    short c;
    char pad2[0x64];
    struct Resource_func_80419E54_de *resource;
    int pad3;
    union
  {
    int value;
    unsigned char bytes[4];
  } owner;
    int pad4;
};

extern void func_80419B18_eu_x(void);

extern f32 D_800E1454;
extern f32 D_800E1460;
extern f32 D_800E146C;
#endif
