#ifndef UNBAKE_SPAN_16E000_CODE_8043F69C_H
#define UNBAKE_SPAN_16E000_CODE_8043F69C_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
struct Node_func_804428F8_de;
typedef struct Node_func_804428F8_de Node_func_804428F8_de;

struct Entry_func_80441EB0_de;
struct List_func_80441EB0_de;
struct List_func_80441EB0_de {
    struct Entry_func_80441EB0_de *entries;
    s16 count;
    char pad6[0x1A];
    s32 value;
};

struct func_8043FFAC_S2;
typedef struct func_8043FFAC_S2 func_8043FFAC_S2;

struct TextLayerMetrics;
struct TextLayerMetrics {
    int field0;
    int width;
    int height;
    int rest[7];
};

struct TextLayerMetrics;
typedef struct TextLayerMetrics TextLayerMetrics;

struct StateRecAt47C;
typedef struct StateRecAt47C StateRecAt47C;

struct LayeredText;
typedef struct LayeredText LayeredText;

struct LayeredText;
struct LayeredText {
    int value;
    short mode;
    short reserved;
    int flags;
    int fieldC;
    int field10;
    int *text;
    int field18;
    int spacing;
    int field20;
    int field24;
};

struct func_8043FFAC_S2;
struct func_8043FFAC_S2 {
    s16 unk0;
    s16 x; /* 0x02 */
    s16 y; /* 0x04 */
    char pad6[6];
    struct TextBoundsText *entries; /* 0x0C */
    s32 count; /* 0x10 */
    char pad14[0x1C];
    f32 unk30;
    f32 unk34;
    s32 unk38;
    s32 unk3C;
};

struct StateRecAtBCV1;
struct StateRecAtBCV1 {
    char pad00[0xB0];
    s32 field_B0;
    s32 field_B4;
    char padB8[0xBC - 0xB8];
    s32 field_BC;
};

struct List_func_804428F8_de;
typedef struct List_func_804428F8_de List_func_804428F8_de;

struct List_func_804428F8_de;
struct Node_func_804428F8_de;
struct StateRecAtBCV1;
struct Table_func_804428F8_de;
struct Node_func_804428F8_de {
    char pad00[0x8];
    s32 handle;
    char pad0C[0x14 - 0xC];
    struct Table_func_804428F8_de *table;
    char pad18[0x20 - 0x18];
    struct StateRecAtBCV1 *state;
    char pad24[0x28 - 0x24];
    s16 kind;
    char pad2A[0x1D4 - 0x2A];
    struct Node_func_804428F8_de *next;
};

struct List_func_804428F8_de {
    struct Node_func_804428F8_de *head;
    char pad04[0x10 - 0x4];
    s32 flag;
    s16 rotation; /* 0x14 */
};

struct Table_func_804428F8_de {
    char pad00[0xC];
    void (*handler)(Node_func_804428F8_de *, List_func_804428F8_de *);
};
struct Item_func_80441FE8_de;
typedef struct Item_func_80441FE8_de Item_func_80441FE8_de;

struct Params_func_804427C4_de;
struct Params_func_804427C4_de {
    char pad[0x14];
    s32 a;
    s32 pad18;
    s32 b;
    s32 c;
    s32 d;
};

struct StateRecAtBCV1;
typedef struct StateRecAtBCV1 StateRecAtBCV1;

struct ParamsRecAt24V2;
struct ParamsRecAt24V2 {
    char pad[0x18];
    s32 a;
    s32 b;
    s32 c;
    s32 d;
};

struct ObjRecAt1AV2;
struct ObjRecAt1AV2 {
    s32 unk0;
    char pad0[0x8];
    f32 unkC;
    f32 unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 pad1B;
};

struct MenuRules;
struct Outer;
struct Outer {
    char pad[0x14];
    struct MenuRules *inner;
};

struct Outer;
extern s32 func_804423AC_de(struct Outer *outer);

struct EntryRecAt18V2;
struct MenuRules;
struct EntryRecAt18V2 {
    char pad0[8];
    s32 flags;
    char pad0C[4];
    s8 back[4];
    char pad14[4];
    struct MenuRules *target;
    char pad1C[0xC];
};

struct EntryRecAt18V2;
struct MenuRecAt10;
struct MenuRecAt10 {
    s16 cursor;
    char pad2[0xA];
    struct EntryRecAt18V2 *entries;
    s32 count;
};

struct Model_func_8044214C_de;
typedef struct Model_func_8044214C_de Model_func_8044214C_de;

struct Model_func_8044214C_de;
struct Model_func_8044214C_de {
    float x;
    float y;
    float depth;
    char padc[8];
    float dx;
    float dy;
    float dz;
    char pad20[0xD4];
    float size;
    char padf8[0x90];
};

struct StateRecAt47C;
struct StateRecAt47C {
    int selection;
    Model_func_8044214C_de model;
    char pad18c[0x2EC];
    int active;
    float size;
};

struct StateRecAt47C;
struct WidgetRecAt20;
struct WidgetRecAt20 {
    char pad[0x20];
    struct StateRecAt47C *state;
};

struct NodeRecAt1D0;
struct NodeRecAt1D0 {
    char pad0[0x14];
    void **vtable;
    char pad18[0x1B8];
    struct NodeRecAt1D0 *next;
};

struct WidgetRecAt20;
typedef struct WidgetRecAt20 WidgetRecAt20;


struct NodeRecAt1D0;
struct OwnerRecAt4;
struct OwnerRecAt4 {
    char pad[4];
    struct NodeRecAt1D0 *head;
};

struct func_8043FFAC_S5;
typedef struct func_8043FFAC_S5 func_8043FFAC_S5;

struct Object_func_804420B4_de;
struct Object_func_804420B4_de {
    char pad[0x17];
    u8 character;
};

struct Item_func_80441FE8_de;
struct Item_func_80441FE8_de {
    int unk0;
    short type;
    char pad6[0xE];
    u8 **text;
};

typedef struct Node_func_804428F8_de Node_func_80442A28_de;

struct ObjRecAt1AV2;
typedef struct ObjRecAt1AV2 ObjRecAt1AV2;

extern float func_8044222C_de(int c, unsigned char next, float sx, float sy);

struct List_func_80441EB0_de;
struct ParamsRecAt24V1;
struct ParamsRecAt24V1 {
    char pad[0x18];
    struct List_func_80441EB0_de *list;
    s32 b;
    s32 c;
    s32 d;
};

struct func_8043FFAC_S5;
struct func_8043FFAC_S5 {
    s32 unk0;
    char pad0[0x10];
    s32 unk14;
    char pad14[0x4];
    s32 unk1C;
};

struct ObjRecAt20V2;
extern char *func_80442214_de(struct ObjRecAt20V2 *object);

#endif
