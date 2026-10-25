#ifndef COMMON_TEXTLAYERMETRICS_H
#define COMMON_TEXTLAYERMETRICS_H
#include "TYPES.H"
#include "COMMON/LEVEL_ACTOR.H"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800EED80[];
#endif
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
struct CMenu_t;
typedef struct CMenu_t CMenu;

struct Entry_func_80441EB0_de;

struct func_8043FFAC_S2;
typedef struct func_8043FFAC_S2 func_8043FFAC_S2;

struct TextLayerMetrics;

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
    f32 alpha; /* 0x30 */
    f32 fade; /* 0x34 */
    s32 unk38;
    s32 unk3C;
    struct TextBoundsData *data; /* 0x40 */
};

struct StateRecAtBCV1;
struct StateRecAtBCV1 {
    char pad00[0xB0];
    s32 field_B0;
    s32 field_B4;
    char padB8[0xBC - 0xB8];
    s32 field_BC;
};

struct MessageList;
typedef struct MessageList MessageList;

struct MessageList;
struct CMenu_t;
struct StateRecAtBCV1;
struct Table_func_804428F8_de;
struct CMenu_t {
    char pad00[0x8];
    s32 handle;
    char pad0C[0x14 - 0xC];
    struct Table_func_804428F8_de *table;
    char pad18[0x20 - 0x18];
    struct StateRecAtBCV1 *state;
    char pad24[0x28 - 0x24];
    s16 kind;
    char pad2A[0x1D4 - 0x2A];
    struct CMenu_t *next;
};

struct MessageList {
    struct CMenu_t *head;
    char pad04[0x10 - 0x4];
    s32 flag;
    s16 rotation; /* 0x14 */
};

struct Table_func_804428F8_de {
    char pad00[0xC];
    void (*handler)(CMenu *, MessageList *);
};

struct Params_func_804427C4_de;

struct StateRecAtBCV1;
typedef struct StateRecAtBCV1 StateRecAtBCV1;

struct ParamsRecAt24V2;

struct CMenuFontInfo_t;

struct MenuRules;
struct Outer;

struct Outer;

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

struct PreviewWidget;
typedef struct PreviewWidget PreviewWidget;

struct PreviewWidget;
struct PreviewWidget {
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
    PreviewWidget model;
    s32 reserved18C;
    LevelActor actor; /* 0x190 */
    int active;
    float size;
};

struct StateRecAt47C;
struct WidgetRecAt20;

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

struct func_8043FFAC_S5;
typedef struct func_8043FFAC_S5 func_8043FFAC_S5;

struct Object_func_804420B4_de;


typedef struct CMenu_t Node_Pak_CountLiveNodes;

struct CMenuFontInfo_t;
typedef struct CMenuFontInfo_t CMenuFontInfo;


struct ParamsRecAt24V1;

struct func_8043FFAC_S5;

struct ObjRecAt20V2;
#endif
