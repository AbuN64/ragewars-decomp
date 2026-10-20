#ifndef COMMON_OBJECTLINKSC_2_H
#define COMMON_OBJECTLINKSC_2_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
extern void func_802A8710_de();

struct Table802AB8DC;
typedef struct Table802AB8DC Table802AB8DC;

struct ObjectLinksC_2;
struct ObjectLinksC_2 {
    unsigned char padding_0[4];
    s32 *unk_4;
    s32 unk_8;
};

struct func_802ABC18_S1;
struct func_802ABC18_S1 {
    char pad0[0x114];
    s32 unk114;
};

extern s32 D_80147150;



extern f32 func_802AA864_de();


struct IntegerState48;
struct IntegerState48 {
    unsigned char padding_0[60];
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
};

struct GfxRec;
struct GfxRec {
    struct {
        unsigned int w0;
        unsigned int w1;
    } words;
};

struct FontStyle;
typedef struct FontStyle FontStyle;

struct func_802AB794_S1;
struct func_802AB794_S1 {
    char pad0[0x40];
    int unk40;
    char pad40[0x88 - 0x40 - sizeof(int)];
    int unk88;
};

extern void func_802A8800_de();

struct GfxRec;
typedef struct GfxRec GfxRec;

struct IntegerState90;
struct IntegerState90 {
    unsigned char padding_0[132];
    s32 unk_84;
    s32 unk_88;
    s32 unk_8C;
};

struct func_802AB8DC_S1;
typedef struct func_802AB8DC_S1 func_802AB8DC_S1;

extern float D_800C61B8_de;

struct Mover;
typedef struct Mover Mover;

struct Mover;
struct Mover {
    s32 active;
    s32 *script;
    s32 state;
    s32 wait;
    f32 x;
    f32 y;
    f32 targetX;
    f32 targetY;
    f32 velX;
    f32 velY;
    f32 accelX;
    f32 accelY;
    f32 rate;
    u8 pad34[4];
    s32 handle; /* 0x38: resource handle initialized by the mover constructor */
};

extern float D_800C61F0_de;

struct func_802AB6C0_S1;
typedef struct func_802AB6C0_S1 func_802AB6C0_S1;

struct func_802AB78C_S1;
struct func_802AB78C_S1 {
    char pad0[0x8C];
    int unk8C;
};

struct func_802AB6C0_S1;
struct func_802AB6C0_S1 {
    s32 unk0;
    char pad0[0x8 - 0x0 - sizeof(s32)];
    char unk8;
    char pad8[0x10 - 0x8 - sizeof(char)];
    f32 unk10;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    f32 unk14;
    char pad14[0x38 - 0x14 - sizeof(f32)];
    s32 unk38;
};

extern float D_800C5FB0_de;

struct FontStyle;
struct FontStyle {
    char pad0[0xA0];
    s32 envR;
    s32 envG;
    s32 envB;
    s32 primR;
    s32 primG;
    s32 primB;
    f32 width;
    f32 height;
    s32 shadowX; /* 0xC0 */
    s32 shadowY; /* 0xC4 */
};

struct func_802AB794_S1;
typedef struct func_802AB794_S1 func_802AB794_S1;

struct func_802ABC18_S1;
typedef struct func_802ABC18_S1 func_802ABC18_S1;

struct IntegerState90;
typedef struct IntegerState90 IntegerState90;

struct func_802AB8DC_S1;
struct func_802AB8DC_S1 {
    char pad0[0x8];
    Entry802AB8DC unk8;
};

struct Table802AB8DC;
struct Table802AB8DC {
    s16 count;
    u8 pad2[6];
    Entry802AB8DC entries[1];
};

extern float D_800C6228_de;

struct ObjectLinksC_2;
typedef struct ObjectLinksC_2 ObjectLinksC_2;

struct func_802AB78C_S1;
typedef struct func_802AB78C_S1 func_802AB78C_S1;

extern FontStyle D_801376F8;


struct IntegerState48;
typedef struct IntegerState48 IntegerState48;

extern u8 D_801377C0[];
extern u8 D_801378C0[];
#endif
