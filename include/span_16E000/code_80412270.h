#ifndef UNBAKE_SPAN_16E000_CODE_80412270_H
#define UNBAKE_SPAN_16E000_CODE_80412270_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80413728.h"
#include "types.h"
struct Record_func_80412710_de;
typedef struct Record_func_80412710_de Record_func_80412710_de;

extern s32 func_804125A4_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern void func_804129F0_de(s32 identifier, s32 first, s32 second, s32 third);

extern s16 func_80413684_de(s16 *record);

extern s16 func_8041366C_de(s16 *record);

struct Layout;
typedef struct Layout Layout;

extern s32 func_80413634_de(u8 *record);

extern u8 func_804135FC_de(u8 *record);

struct GridList;
struct GridList {
    char pad0[0x48];
    u8 columns;
    u8 rows;
};

struct Entry_func_80412898_de;
struct IntPair;
struct Entry_func_80412898_de {
    char pad_00[0x44];
    struct IntPair *cells;
    u8 pad_48[3];
    u8 width;
};

struct Resource_func_80413404_de;
struct Resource_func_80413404_de {
    unsigned char unk0;
    unsigned char flags;
    char pad2[0xE];
    int size;
    void *data;
    void *handle;
};

extern s16 func_80413678_de(s16 *record);

extern void func_80412B18_de(s32 identifier, s32 *first, s32 *second);

struct Object_func_80412CA0_de;
struct Object_func_80412CA0_de {
    char pad[0x44];
    void *child;
};

struct Layout;
struct Layout {
    s32 pad0[5];
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    s32 pad1C[4];
};

extern s16 func_80413690_de(s16 *record);

struct Record_func_80412710_de;
struct Record_func_80412710_de {
    s32 words_00[3];
    s16 field_0C;
    s16 field_0E;
    s32 words_10[13];
    void *field_44;
    u8 field_48;
    u8 field_49;
    u8 field_4A;
    u8 field_4B;
    u8 field_4C;
    u8 field_4D;
    u8 field_4E;
    u8 field_4F;
    u8 field_50;
    u8 field_51;
    u8 pad_52[0xE];
};

struct OwnedImage;
struct OwnedImage {
    u8 unk0;
    u8 flags;
    char pad2[0xE];
    s32 paletteCount;
    void *palette;
    void *pixels;
    s32 unk1C;
};

struct Resource_func_80413404_de;
typedef struct Resource_func_80413404_de Resource_func_80413404_de;

struct Cell_func_804122CC_de;
typedef struct Cell_func_804122CC_de Cell_func_804122CC_de;

struct Cell_func_804122CC_de;
struct Cell_func_804122CC_de {
    Layout layout;
    u8 fg;
    u8 bg;
    u8 selectedFg;
    u8 selectedBg;
    s32 pad30[2];
    s32 content;
};

extern u32 func_80412D94_de(u32 value, s32 from, s32 to);

struct GridList;
typedef struct GridList GridList;

struct Entry_func_80412AC0_de;
struct Entry_func_80412AC0_de {
    char pad[0x58];
    s32 first;
    s32 second;
};

extern void func_80412A58_de(s32 identifier, s32 first, s32 second, s32 third);

struct Entry_func_80412898_de;
typedef struct Entry_func_80412898_de Entry_func_80412898_de;

extern void func_80412AC0_de(s32 identifier, s32 first, s32 second);

extern void func_80412940_de(s32 identifier, s32 row, s32 column, s32 *first, s32 *second);

struct ScrollTable;
struct ScrollTable {
    Layout layout;
    s32 pad2C[6];
    s32 *contents;
    char pad48[3];
    u8 columns;
    u8 selectedRow;
    u8 selectedCol;
    u8 rowScroll;
    u8 colScroll;
    u8 headerRows;
    u8 headerCols;
    u8 headerFg;
    u8 headerBg;
    u8 fg;
    u8 bg;
    u8 selectedFg;
    u8 selectedBg;
    s32 *widths;
    s32 *heights;
};

extern s16 func_80413660_de(s16 *record);

struct OwnedImage;
typedef struct OwnedImage OwnedImage;


extern void func_80412898_de(s32 identifier, s32 row, s32 column, s32 first, s32 second);

struct ScrollTable;
typedef struct ScrollTable ScrollTable;

extern s32 func_80412710_de(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6);

typedef struct ImageDescriptor { u8 format; char pad1[7]; s16 width; char padA[0xA]; void *pixels, *palette; } ImageDescriptor;
extern Format D_8014DA90;
extern Format D_8014DA50;
extern void (*D_80153CD4)(void);
extern void (*D_80153CD0)(void);
extern void (*D_80153CDC)(void);
extern void (*D_80153CD8)(void);
extern void D_0041406C(void);
extern void D_004140BC(void);
extern void D_00414094(void);
extern void D_00414244(void);
extern void D_00414220(void);
extern void D_00413FCC(void);
extern void D_00414024(void);
extern void D_00413FF8(void);
extern void D_00414168(void);
extern void D_00414138(void);
extern void D_004141C0(void);
extern void D_004141E0(void);
extern void D_00414200(void);

#endif
