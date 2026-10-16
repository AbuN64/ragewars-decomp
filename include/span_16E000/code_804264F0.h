#ifndef UNBAKE_SPAN_16E000_CODE_804264F0_H
#define UNBAKE_SPAN_16E000_CODE_804264F0_H
#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
struct State_func_80428214_de;
typedef struct State_func_80428214_de State_func_80428214_de;

struct Resource_func_80419E54_de;
struct ResultsDrawScreen;

struct ResultsOptionsScreen;
struct ResultsOptionsScreen {
    char pad0[0x970];
    union { MenuWidget *root; void *parent; };
    char pad974[0xA44 - 0x974];
    s32 selection;
    char padA48[0x14];
    s32 player;
    char padA60[0x14];
    u8 owned[5];
    u8 pending[5];
};

struct EntryRecAt11C;
struct EntryRecAt11C {
    char pad0[0x11C];
    u8 owned;
};

extern s32 func_80428E78_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct RowRecAt54;
struct RowRecAt54 {
    s32 pad0;
    f32 scale[4];
    f32 distance[4];
    Vec3 position[4];
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

struct Screen_func_80427008_de;
struct Screen_func_80427008_de {
    char pad0[0xA5C];
    s32 record;
    char padA60[0xA74 - 0xA60];
    u8 shown[5];
    u8 marked[5];
};

extern void func_8042840C_de();

struct Screen_func_80426788_de;
struct Screen_func_80426788_de {
    char pad0[0xA58];
    s32 wordA58;
};

extern void func_804279B8_de();

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

extern void func_804273D4_de();

struct Menu_func_80428850_de;
struct Resource_func_80419E54_de;
struct Menu_func_80428850_de {
    char pad0[0xA44];
    s32 current;
    struct Resource_func_80419E54_de *window;
    char padA4C[0xA6C - 0xA4C];
    s32 idle;
    char padA70[0xA74 - 0xA70];
    u8 reachable[5];
    u8 visited[5];
};

extern void func_80427B08_de();

extern int func_8042863C_de(int id);

extern void func_80428700_de();

struct ScreenCode80423280;
struct ScreenCode80423280 {
    char pad0[0x970];
    s32 context;
};

struct func_80428388_S1;
typedef struct func_80428388_S1 func_80428388_S1;

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

extern void func_80427008_de();

extern void func_80428214_de();

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

extern void func_804281A8_de();

struct Resource_func_80419E54_de;
struct func_80428388_S1;
struct func_80428388_S1 {
    char pad0[0xA60];
    struct Resource_func_80419E54_de * unkA60;
    char padA60[0xA64 - 0xA60 - sizeof(struct Resource_func_80419E54_de*)];
    struct Resource_func_80419E54_de * unkA64;
    char padA64[0xA68 - 0xA64 - sizeof(struct Resource_func_80419E54_de*)];
    s32 unkA68;
};

extern void func_804274B0_de();

struct MenuMarker;
struct Screen_func_80426918_de;
struct Screen_func_80426918_de {
    char pad0[0x978];
    struct MenuMarker *left;
    char pad97C[2];
    u16 leftSpeed;
    struct MenuMarker *right;
    char pad984[2];
    u16 rightSpeed;
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

struct State_func_804280BC_de;
struct func_8028469C_S2;
struct State_func_804280BC_de {
    char pad0[0x998];
    struct func_8028469C_S2 *owner;
    char pad99C[0xA04 - 0x99C];
    char text[0x40];
    s32 name;
};

extern void func_804280BC_de();

struct EntryRecAt8V3;
struct EntryRecAt8V3 {
    s32 id;
    s32 first;
    s32 second;
    char pad[28 - 12];
};

extern void func_80428300_de();

struct ResultsDrawScreen;
struct Shape_typemap_21;
struct ResultsDrawScreen {
    char pad0[0x20];
    char panels[2][0x4A8];
    char pad970[0x988 - 0x970];
    s32 state;
    char pad98C[0xA44 - 0x98C];
    s32 soundBase;
    char padA48[0x8];
    struct Resource_func_80419E54_de *item;
    char padA54[0xC];
    struct Shape_typemap_21 *bannerShadow;
    struct Shape_typemap_21 *banner;
    s32 blinking;
    s32 frames;
    s32 blinkDelay;
};

struct Table_func_80427D70_de;
struct Table_func_80427D70_de {
    u8 pad0;
    u8 first;
    u8 items[3];
};

struct State_func_80428E10_de;
struct State_func_80428E10_de {
    char pad[0xA44];
    s32 selection;
};

struct ResultsOptionsScreen;
typedef struct ResultsOptionsScreen ResultsOptionsScreen;

struct ResultsDrawScreen;
typedef struct ResultsDrawScreen ResultsDrawScreen;

struct Record_func_804284C0_de;
struct Record_func_804284C0_de {
    char pad0[6];
    u16 items[8];
};

struct EntryRecAt11C;
typedef struct EntryRecAt11C EntryRecAt11C;

struct Record_func_804284C0_de;
typedef struct Record_func_804284C0_de Record_func_804284C0_de;

extern void func_80427D70_de(void *);

#endif
