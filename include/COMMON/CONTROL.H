#ifndef COMMON_CONTROL_H
#define COMMON_CONTROL_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"



struct MenuMarker;
struct Screen_func_8042B78C_de;
struct Screen_func_8042B78C_de {
    char pad0[0x308];
    char view[0x434 - 0x308];
    s32 category;
    s32 selection;
    struct MenuMarker *item;
    char pad440[0x448 - 0x440];
    struct MenuMarker *marker;
    char pad44C[0x45C - 0x44C];
    s32 word45C;
    char pad460[0x464 - 0x460];
    s32 word464;
};

extern void ScenarioSetup_ClearFlagBits();

struct Label;
struct Screen_func_8042AFE0_de;
struct Screen_func_8042AFE0_de {
    s32 field0;
    char pad4[0x3EC - 4];
    struct Label *widget;
    char pad3F0[0x3F4 - 0x3F0];
    char label[0x40];
    s32 list;
    s32 entry;
};


struct G;
struct G {
    char pad0[0x3DC];
    s32 unk3DC;
    char pad3E0[0x3EC - 0x3E0];
    s32 unk3EC;
    s32 unk3F0;
    char pad3F4[0x440 - 0x3F4];
    s32 unk440;
    s32 unk444;
    s32 unk448;
    Resource_func_80419E54_de *unk44C;
};

struct Resource_func_80419E54_de;
struct VersusResultsScreen;
struct VersusResultsScreen {
    char pad0[0x8];
    char panels[4][0xC0];
    char tie[0x3DC - 0x308];
    s32 state;
    char pad3E0[0x434 - 0x3E0];
    s32 winnerSlot;
    s32 winner;
    char pad43C[0x450 - 0x43C];
    struct Resource_func_80419E54_de *bannerShadow;
    struct Resource_func_80419E54_de *banner;
    char pad458[0x464 - 0x458];
    s32 frames;
    s32 blinkDelay;
    s32 blinking;
};

struct Resource_func_80419E54_de;

struct MenuMarker;
struct Screen_func_8042B4D4_de;
struct Screen_func_8042B4D4_de {
    char pad0[0x308];
    char view[0x434 - 0x308];
    s32 category;
    s32 selection;
    struct MenuMarker *item;
    struct MenuMarker *left;
    struct MenuMarker *right;
    struct MenuMarker *marker;
    char pad44C[0x45C - 0x44C];
    s32 word45C;
    char pad460[0x464 - 0x460];
    s32 word464;
};

struct Cup;
struct Cup {
    s32 index;
    s32 stages;
    u8 played[4];
};

/* The cup being played. */
extern struct Cup D_80154010;



struct G;
typedef struct G G;

struct Resource_func_80419E54_de;



struct RecordRecAtCV2;
struct RecordRecAtCV2 {
    s32 key;
    char pad4[0x8];
    s32 value;
};

struct Label;
struct Screen_func_8042A990_de;
struct Screen_func_8042A990_de {
    void *window;
    char pad4[0x3EC - 0x4];
    struct Label *label;
    void *widgetB;
    char text[0x434 - 0x3F4];
    s32 category;
    s32 selection;
    void *item;
    void *widgetC;
    void *widgetD;
    void *widgetE;
};

extern void func_8042B2E4_de();

struct MenuRenderFill;
struct MenuRenderFill {
    s32 mode;
    f32 color[4];
};


extern s32 func_8042BAD0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);


struct Icon;
struct Icon {
    s32 key;
    s32 other;
    char pad8[0x10 - 0x8];
};



struct RecordRecAtCV2;
typedef struct RecordRecAtCV2 RecordRecAtCV2;
#endif
