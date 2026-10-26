#ifndef FRONTEND_LAYOUT_H
#define FRONTEND_LAYOUT_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/FORMAT.H"
struct MenuWidget;

extern s32 Frontend_DispatchTypedWidgetEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);




struct Layout;
typedef struct Layout Layout;



struct GridList;
struct GridList {
    char pad0[0x48];
    u8 columns;
    u8 rows;
};

struct EntryFrontendSetGridCellValues;
struct IntPair;
struct EntryFrontendSetGridCellValues {
    char pad_00[0x44];
    struct IntPair *cells;
    u8 pad_48[3];
    u8 width;
};

struct OwnedImage;



struct ObjectFrontendDestroyGridList;
struct ObjectFrontendDestroyGridList {
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


struct MenuWidget;

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

struct OwnedImage;

struct t_dltext;
typedef struct t_dltext sm_dltext;

struct t_dltext;
struct t_dltext {
    Layout Hdr;
    u8 Font;
    u8 FontClut;
    u8 FontHighlighted;
    u8 FontHighlightedClut;
    s32 pad30[2];
    s32 pString;
};


struct GridList;
typedef struct GridList GridList;

struct EntryFrontendSetGridDimensionArrays;
struct EntryFrontendSetGridDimensionArrays {
    char pad[0x58];
    s32 first;
    s32 second;
};


struct EntryFrontendSetGridCellValues;
typedef struct EntryFrontendSetGridCellValues EntryFrontendSetGridCellValues;



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


struct OwnedImage;
typedef struct OwnedImage OwnedImage;



struct ScrollTable;
typedef struct ScrollTable ScrollTable;


typedef struct ImageDescriptor { u8 format; char pad1[7]; s16 width; char padA[0xA]; void *pixels, *palette; } ImageDescriptor;
extern Format g_destinationPixelFormat;
extern Format g_sourcePixelFormat;
extern void (*g_writeDestinationColor)(void);
extern void (*g_readSourceColor)(void);
extern void (*g_writeDestinationIndex)(void);
extern void (*g_readSourceIndex)(void);
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
