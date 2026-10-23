#ifndef COMMON_RESULTSOPTIONSSCREEN_H
#define COMMON_RESULTSOPTIONSSCREEN_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct State_func_80428214_de;
typedef struct State_func_80428214_de State_func_80428214_de;

struct Resource_func_80419E54_de;

struct ResultsOptionsScreen;
struct func_8028469C_S2;
struct ResultsOptionsScreen {
    char pad0[0x20];
    char panels[2][0x4A8];
    union { MenuWidget *root; void *parent; };
    char pad974[0x988 - 0x974];
    s32 state;
    char pad98C[0x998 - 0x98C];
    struct func_8028469C_S2 *owner;
    char pad99C[0xA04 - 0x99C];
    char text[0x40];
    s32 selection;
    MenuWidget *window;
    char padA4C[0x4];
    MenuWidget *item;
    char padA54[0xA5C - 0xA54];
    s32 player;
    MenuWidget *bannerShadow;
    MenuWidget *banner;
    s32 blinking;
    s32 frames;
    s32 blinkDelay;
    u8 owned[5];
    u8 pending[5];
};

struct EntryRecAt11C;
struct EntryRecAt11C {
    char pad0[0x11C];
    u8 owned;
};


struct RowRecAt54;
struct RowRecAt54 {
    s32 portrait; /* character portrait image id shown in result and selection rows */
    f32 scale[4];
    f32 distance[4];
    CVector3 position[4];
    s32 light[4];
    char pad64[0x70 - 0x64];
};

struct SlotCode80423280;
typedef struct SlotCode80423280 SlotCode80423280;

struct SlotCode80423280;
struct SlotCode80423280 {
    u8 flags[0x16];
    u8 unk16[0x16];
    u8 ready;
    u8 pad2D[0x96 - 0x2D];
};

struct State_func_80428214_de;
struct State_func_80428214_de {
    u8 pad0[0x11C];
    SlotCode80423280 slots[4];
};

extern u8 D_801462D5;



struct Screen_func_80426788_de;
struct Screen_func_80426788_de {
    char pad0[0xA58];
    s32 wordA58;
};


struct Screen_func_80427D70_de;
struct Screen_func_80427D70_de {
    char pad0[0xA5C];
    s32 player;
    char padA60[0xA74 - 0xA60];
    u8 owned[0xA79 - 0xA74];
    u8 unlocked[1];
};

struct RecordRecAt8D;
struct RecordRecAt8D {
    char pad0[0x7E];
    u8 single[5];
    u8 versus[5];
    u8 three[5];
    u8 four[5];
    char pad92[0x190 - 0x92];
};

struct ResultsOptionsScreen;


struct Resource_func_80419E54_de;




struct ScreenCode80423280;
struct ScreenCode80423280 {
    char pad0[0x970];
    s32 context;
};


struct Pair;
struct Pair {
    s32 a;
    s32 b;
    union {
        s32 id;
        struct {
            u16 high;
            u16 low;
        } half;
    } c;
};



struct Entry_func_804279B8_de;
struct Entry_func_804279B8_de {
    char pad[0x80];
    s8 kind;
    char tail[0x15];
};

struct Entry_func_804279B8_de;
struct Data801462C8;
struct Data801462C8 {
    char pad0[0xD];
    u8 mode;
    char padE[0xD0 - 0xE];
    struct Entry_func_804279B8_de status[8];
};


struct Resource_func_80419E54_de;


struct MenuMarker;
struct Screen_func_80426918_de;
struct Screen_func_80426918_de {
    char pad0[0x978];
    struct MenuMarker *left;
    s32 leftSpeed; /* slide step, stored as a word and read back as its low half */
    struct MenuMarker *right;
    s32 rightSpeed; /* slide step, stored as a word and read back as its low half */
    s32 state;
    s32 timer;
    void *prompt;
    void *button;
    char pad998[0xA48 - 0x998];
    struct MenuMarker *pulse;
    char padA4C[4];
    struct MenuMarker *banner;
    s32 clock;
    s32 requested;
};

struct func_8028469C_S2;


struct EntryRecAt8V3;
struct EntryRecAt8V3 {
    s32 id;
    s32 first;
    s32 second;
    char pad[28 - 12];
};


struct Shape_typemap_21;

struct Table_func_80427D70_de;
struct Table_func_80427D70_de {
    u8 pad0;
    u8 first;
    u8 items[3];
};


struct ResultsOptionsScreen;
typedef struct ResultsOptionsScreen ResultsOptionsScreen;


struct Record_func_804284C0_de;
struct Record_func_804284C0_de {
    char pad0[6];
    u16 items[8];
};

struct EntryRecAt11C;
typedef struct EntryRecAt11C EntryRecAt11C;

struct Record_func_804284C0_de;
typedef struct Record_func_804284C0_de Record_func_804284C0_de;
#endif
