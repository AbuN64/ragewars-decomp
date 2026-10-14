#ifndef UNBAKE_SPAN_16E000_CODE_8040C780_H
#define UNBAKE_SPAN_16E000_CODE_8040C780_H
#include "types.h"
#include "span_1000/code_80297CD0.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
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

extern void func_8040F044_de(WidgetRecAtE *a, WidgetRecAtE *b);

struct DrawArgs;
typedef struct DrawArgs DrawArgs;

extern int D_800DEA6C;

struct Node_func_8040ED38_de;
struct Node_func_8040ED38_de {
    struct Node_func_8040ED38_de *unk0;
    struct Node_func_8040ED38_de *unk4;
    struct Node_func_8040ED38_de *unk8;
};

extern void func_8040CAB0_de();

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
extern s32 func_8040EBAC_de(struct WidgetNode *node);

struct WidgetNode;
extern s32 func_8040EB48_de(struct WidgetNode *node);

struct SpriteRecAt14;
typedef struct SpriteRecAt14 SpriteRecAt14;

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
extern void func_8040E900_de(struct Widget *record, int enable);

struct Tree_func_8040EEA4_de;
struct Tree_func_8040EEA4_de {
    struct Tree_func_8040EEA4_de *parent;
    struct Tree_func_8040EEA4_de *next;
    struct Tree_func_8040EEA4_de *child;
    short id;
    short pad_0E;
    s32 pad_10;
    short field_14;
    short field_16;
};

struct BatchRec;
typedef struct BatchRec BatchRec;

struct WidgetNode;
extern s32 func_8040EB68_de(struct WidgetNode *node);

struct Node_func_8040ED38_de;
typedef struct Node_func_8040ED38_de Node_func_8040ED38_de;

struct Widget_func_8040CF8C_de;
struct Widget_func_8040CF8C_de {
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
};

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
extern void func_8040EBF4_de(struct NodeRecAt16 *node, s32 *x, s32 *y);

struct DrawArgs;
struct DrawArgs {
    s32 x;
    s32 y;
    s32 flags;
    f32 scaleX;
    f32 scaleY;
    u8 alpha;
    u8 pad15[3];
    s32 v[4];
};

struct WidgetNode;
extern s32 func_8040EB8C_de(struct WidgetNode *node);

struct Pair14;
extern void func_8040E978_de(struct Pair14 *record, s16 first, s16 second);

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

extern void func_8040C950_de(Slider *slider);

struct Widget_func_8040CF8C_de;
typedef struct Widget_func_8040CF8C_de Widget_func_8040CF8C_de;

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

extern void func_8040E984_de(WidgetRecAt1A **hit, WidgetRecAt1A *node, DrawArgs_func_8040E67C_de args, s32 px, s32 py);

extern int D_8014D710;

struct Batch;
typedef struct Batch Batch;

struct SpriteRecAt14;
struct SpriteRecAt14 {
    s32 glyph;
    f32 x;
    f32 y;
    s32 color;
    f32 scale;
    u16 page;
    u16 pad16;
};

struct Batch;
struct SpriteRecAt14;
struct Batch {
    s32 pad0[4];
    struct SpriteRecAt14 *cursor;
    s32 count;
};

extern void func_8040C948_de(void);

extern void func_8040E894_de();

struct MenuWidget;

struct BatchRec;
struct Shape_typemap_165;
struct BatchRec {
    struct Shape_typemap_165 area;
    void *cursor;
    s32 count;
};

extern s32 D_8014D568;
extern s32 D_8014D56C;
char *func_80411D78_de(s32);
s32 D_0040F570(char *, char *);

#endif
