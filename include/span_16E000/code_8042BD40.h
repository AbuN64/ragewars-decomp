#ifndef UNBAKE_SPAN_16E000_CODE_8042BD40_H
#define UNBAKE_SPAN_16E000_CODE_8042BD40_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
struct SettingsRecAt24;
struct SettingsRecAt24 {
    char pad0[0x24];
    s8 timeSetting;
};

struct SettingsRecAt24;
typedef struct SettingsRecAt24 SettingsRecAt24;

struct Rules_func_8042D060_de;
typedef struct Rules_func_8042D060_de Rules_func_8042D060_de;

struct Rules_func_8042D060_de;
struct Rules_func_8042D060_de {
    char pad0[0x14];
    f32 timeLeft;
    char pad18[0x98 - 0x18];
    s32 lastStanding;
};

struct Game_func_8042D060_de;
struct Game_func_8042D060_de {
    char pad0[0xCAC];
    SettingsRecAt24 settings;
    char padCD1[0x1284 - 0xCD1];
    Rules_func_8042D060_de rules;
};

extern s32 func_8042D958_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern void func_8042CC74_de();

struct Shared_BigObj;
typedef struct Shared_BigObj Shared_BigObj;

extern void func_8042D1C8_de();

struct Shared_Rec3;
struct Shared_Rec3 {
    char pad0[0x91];
    u8 flag;
    char pad92[0x4];
};

struct Frame_func_804217D4_de;
struct Menu_func_804241BC_de;
struct State_func_8042DAF8_de;
struct State_func_8042DAF8_de {
    struct Menu_func_804241BC_de *menu;
    char pad4[0x8 - 0x4];
    struct Frame_func_804217D4_de *list;
    s32 delay;
    s32 target;
};

struct IntPair;
struct Shared_BigObj;
struct Shared_BigObj {
    char pad0[0xF0];
    s32 slot[8];
    struct IntPair arr2[8];
};

struct SlotRecAt7F;
typedef struct SlotRecAt7F SlotRecAt7F;

extern void func_8042CFDC_de(void);

struct func_8042CE54_S1;
typedef struct func_8042CE54_S1 func_8042CE54_S1;

struct IntegerStateF4;
typedef struct IntegerStateF4 IntegerStateF4;

struct ResourceBank;
typedef struct ResourceBank ResourceBank;

struct ResourceBank;
struct ResourceBank {
    u16 ids[20];
};

struct Screen_func_8042DC04_de;
typedef struct Screen_func_8042DC04_de Screen_func_8042DC04_de;

struct func_8042CE54_S1;
struct func_8042CE54_S1 {
    s32 transition[7];
    s32 active;
    char pad20[0xC0];
    void * unkE0;
    s32 buttonAddress;
    s32 first, count;
    union { s32 players[8]; void *data; };
    s32 icons[8][2];
    char killText[4][25], scoreText[4][25], ratioText[4][25], valueText[4][25];
    char name[0x40];
    s32 phase, mode, dirty, selection;
};

struct State_func_8042D908_de;
struct State_func_8042D908_de {
    char pad[0xE8];
    s32 position;
    s32 limit;
};

struct IntegerState330;
typedef struct IntegerState330 IntegerState330;


struct Shared_Rec3;
typedef struct Shared_Rec3 Shared_Rec3;

extern void func_8042D118_de();

struct Object_func_8042DD00_de;
struct Object_func_8042DD00_de {
    char pad[0x14];
    char text[0xC];
    s32 value;
};

struct Screen_func_8042DC04_de;
struct Screen_func_8042DC04_de {
    int window;
    char pad4[12];
    int state;
    char pad14[12];
    int count;
};

extern void func_8042D034_de(void);

struct Screen_func_8042D690_de;
struct Screen_func_8042D690_de {
    char pad0[0xE4];
    void *object;
    char padE8[0x320 - 0xE8];
    s32 open;
    char pad324[0x328 - 0x324];
    s32 choice;
};

struct Game_func_8042D060_de;
typedef struct Game_func_8042D060_de Game_func_8042D060_de;

struct IntegerState330;
struct IntegerState330 {
    char pad0[0x32C];
    s32 unk_32C;
};

extern s32 func_8042DE10_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern void func_8042D418_de(s32 arg0);

struct State_func_8042CFDC_de;
struct State_func_8042CFDC_de {
    char pad0[0x54];
    s32 first;
    char pad58[0x78 - 0x58];
    s32 second;
};

extern s32 func_8042D060_de();

struct SlotRecAt7F;
struct SlotRecAt7F {
    char pad0[0x78];
    u8 active;
    char pad79[6];
    u8 index;
    char pad80[0x16];
};

struct IntegerStateF4;
struct IntegerStateF4 {
    unsigned char padding_0[240];
    s32 unk_F0;
};

extern void func_8042CFB0_de(void);

/* Results-screen group identifiers from each native menu resource set. */
#if defined(VERSION_DE)
enum { RESULTS_RANK_GROUP = 0x264, RESULTS_SECONDARY_GROUP = 0x269, RESULTS_MENU_SHIFT=-4, RESULTS_RIGHT_ITEM=0x26A };
#elif defined(VERSION_EU_X)
enum { RESULTS_RANK_GROUP = 0x26D, RESULTS_SECONDARY_GROUP = 0x272, RESULTS_MENU_SHIFT=5, RESULTS_RIGHT_ITEM=0x273 };
#else
enum { RESULTS_RANK_GROUP = 0x269, RESULTS_SECONDARY_GROUP = 0x26E, RESULTS_MENU_SHIFT=0, RESULTS_RIGHT_ITEM=0x267 };
#endif
#endif
