#ifndef COMMON_WIDGETRECAT1A_H
#define COMMON_WIDGETRECAT1A_H
#include "TYPES.H"
#include "COMMON/LONE/D_8014D56C.H"
#include "COMMON/LONE/D_8014D568.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
struct WidgetRecAt1A;
struct WidgetRecAt1A {
    char pad0[4];
    struct WidgetRecAt1A *next;
    struct WidgetRecAt1A *child;
    s16 id;
    u16 selector;
    char pad10[4];
    s16 x;
    s16 y;
    s16 width;
    s16 height;
};


struct Widget;

struct WidgetRecAtE;
typedef struct WidgetRecAtE WidgetRecAtE;

struct WidgetRecAtE;
struct WidgetRecAtE {
    struct WidgetRecAtE *parent;
    struct WidgetRecAtE *next;
    struct WidgetRecAtE *child;
    char padC[2];
    u16 type;
    char pad10[0x1C];
};


struct t_dldc;
typedef struct t_dldc sm_dldc;

extern int D_800DEA6C;

struct Node_func_8040ED38_de;
struct Node_func_8040ED38_de {
    struct Node_func_8040ED38_de *unk0;
    struct Node_func_8040ED38_de *unk4;
    struct Node_func_8040ED38_de *unk8;
};


struct WidgetNode;
struct WidgetNode {
    struct WidgetNode *next;
    char pad4[0xC - 4];
    s16 resource; /* +0x0C: selected resource identifier */
    char padE[0x12 - 0xE];
    unsigned short flags;
    s16 x; /* +0x14: widget position */
    s16 y; /* +0x16 */
};

struct WidgetNode;

struct WidgetNode;


struct NodeRecAt44;
typedef struct NodeRecAt44 NodeRecAt44;

struct Widget_func_8040CD50_de;
struct Widget_func_8040CD50_de {
    char pad0[0x12];
    u16 flags;
    char pad14[0x18];
    s32 image;
};

struct Widget_func_8040CD50_de;
typedef struct Widget_func_8040CD50_de Widget_func_8040CD50_de;

struct Widget;

struct Widget;

struct Tree;

struct BatchRec;
typedef struct BatchRec BatchRec;

struct WidgetNode;

struct Node_func_8040ED38_de;
typedef struct Node_func_8040ED38_de Node_func_8040ED38_de;

struct WidgetLayout;
struct WidgetLayout {
    char pad0[0x10];
    u8 alpha;
    char pad11;
    u16 flags;
    s16 x, y;
    s16 width, height;
    s16 offsetX, offsetY;
    f32 scaleX, scaleY;
    s32 unknown28;
    u32 colors[4];
};

struct MenuWidget;

struct Tree;
struct Tree {
    struct Tree *parent;
    struct Tree *next;
    struct Tree *child;
    short id;
    char pad0E[0x6];
    short field_14;
    short field_16;
};
typedef struct Tree Tree;

struct DrawArgs_func_8040E67C_de;
struct DrawArgs_func_8040E67C_de {
    s32 x;
    s32 y;
    s32 flags;
    f32 scaleX;
    f32 scaleY;
    s32 v[5];
};

struct NodeRecAt16;
struct NodeRecAt16 {
    struct NodeRecAt16 *next;
    char pad4[0x14 - 4];
    s16 x;
    s16 y;
};

struct NodeRecAt16;

struct t_dldc;
struct t_dldc {
    s32 x;
    s32 y;
    s32 flags;
    f32 XScale;
    f32 YScale;
    u8 alpha;
    u8 pad15[3];
    struct Shape_typemap_165 Rgn;
};

struct WidgetNode;

struct Pair14;

struct Widget_func_8040C950_de;
struct Widget_func_8040C950_de {
    char pad0[0x14];
    s16 x;
    s16 y;
    s16 width;
    s16 height;
};
struct Slider;
struct Widget_func_8040C950_de;
struct Slider {
    char pad0[0xC];
    s16 parentId;
    char padE[0x36];
    s32 min;
    s32 max;
    s32 step;
    s32 value;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    struct Widget_func_8040C950_de *thumb;
    struct Widget_func_8040C950_de *fill;
    s32 flags;
};

struct Slider;
typedef struct Slider Slider;


struct WidgetLayout;
typedef struct WidgetLayout WidgetLayout;

struct NodeRecAt44;
struct NodeRecAt44 {
    char pad0[4];
    struct NodeRecAt44 *left;
    struct NodeRecAt44 *right;
    char padC[2];
    u16 kind;
    char pad10[2];
    u16 flags;
    char pad14[0x18];
    void *ref2C;
    void *ref30;
    void *ref34;
    void *ref38;
    char pad3C[8];
    void *ref44;
};

struct DrawArgs_func_8040E67C_de;
typedef struct DrawArgs_func_8040E67C_de DrawArgs_func_8040E67C_de;

struct WidgetRecAt1A;
typedef struct WidgetRecAt1A WidgetRecAt1A;


extern int D_8014D710;






struct MenuWidget;

struct BatchRec;
struct Shape_typemap_165;
struct TextSprite;
struct BatchRec {
    struct Shape_typemap_165 area;
    struct TextSprite *cursor;
    s32 count;
};

char *func_80411D78_de(s32);
s32 D_0040F570(char *, char *);
#endif
