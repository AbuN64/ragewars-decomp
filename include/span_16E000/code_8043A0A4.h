#ifndef UNBAKE_SPAN_16E000_CODE_8043A0A4_H
#define UNBAKE_SPAN_16E000_CODE_8043A0A4_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_16E000/code_8041B020.h"
#include "span_16E000/code_8041BEA8.h"
#include "types.h"
extern void func_8043B96C_de();

struct Entry_func_8043ACF0_de;
struct Entry_func_8043ACF0_de {
    char pad0[0x4AC];
    s32 column;
    char pad4B0[0x4CC - 0x4B0];
    s32 mode;
};

struct Entry_func_8043ACF0_de;
struct Screen_func_8043ACF0_de;
struct Screen_func_8043ACF0_de {
    void *window;
    s32 pad4;
    struct Entry_func_8043ACF0_de entries[4];
};

struct Entry_func_8043BA5C_de;
struct Entry_func_8043BA5C_de {
    void *window;
    char pad4[0x4B4 - 0x4];
    s32 selection;
    s32 values[6];
    char pad4D0[0x4D0 - 0x4D0];
};

extern s32 func_8043C2D4_de(s32 *record);

struct Entry_func_8043B6E8_de;
struct Entry_func_8043B6E8_de {
    char pad0[0x4B0];
    s32 values[6];
    char pad4C8[0x4CC - 0x4C8];
    s32 mode;
};

struct Entry_func_8043B6E8_de;
struct Screen_func_8043B6E8_de;
struct Screen_func_8043B6E8_de {
    void *window;
    s32 pad4;
    struct Entry_func_8043B6E8_de entries[4];
};

struct EntryRecAt4D4;
struct EntryRecAt4D4 {
    char pad[0x4B0];
    s32 state;
    char pad4B4[0x4D4 - 0x4B4];
    s32 nextActive;
};

struct ResultsPlayerPanel;
struct ResultsPlayerPanel {
    char pad0[0x4A8];
    s32 state;
    char pad4AC[0x4D0 - 0x4AC];
};

struct FourPlayerResultsScreen;
struct ResultsPlayerPanel;
struct FourPlayerResultsScreen {
    char pad0[8];
    struct ResultsPlayerPanel panels[4];
    char pad1348[0x1358 - 0x1348];
    s32 state;
    char pad135C[0x1370 - 0x135C];
    char badges[4][0xC0];
};

struct Entry_func_8043BBB0_de;
struct Entry_func_8043BBB0_de {
    char pad[0x4B0];
    s32 state;
    s32 selection;
    s32 values[6];
};

extern s32 func_8043C2E0_de(s32 *record);

struct Entry_func_8043BA5C_de;
struct Screen_func_8043BA5C_de;
struct Screen_func_8043BA5C_de {
    struct Entry_func_8043BA5C_de entries[4];
};

struct Entry_func_8043B0CC_de;
struct Resource_func_80419E54_de;
struct Entry_func_8043B0CC_de {
    char pad0[0x4A8];
    s32 open;
    s32 column;
    s32 values[6];
    struct Resource_func_80419E54_de *item;
    s32 mode;
};

struct ResultsPlayerPanel;
struct State_func_8043BF28_de;
struct State_func_8043BF28_de {
    void *screen;
    void *menu;
    struct ResultsPlayerPanel players[4];
    char pad1348[0x10];
    int phase;
    int timer;
    char pad1360[8];
    int next;
};

extern s32 func_8043BA24_de();

struct State_func_8043BF28_de;
typedef struct State_func_8043BF28_de State_func_8043BF28_de;

struct Entry_func_8043B0CC_de;
struct Screen_func_8043B0CC_de;
struct Screen_func_8043B0CC_de {
    s32 window;
    s32 unk4;
    struct Entry_func_8043B0CC_de entries[4];
};

extern s32 func_8043BFF0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct EntryRecAt4B0;
struct EntryRecAt4B0 {
    char pad[0x4B0];
    s32 state;
    char pad4B4[0x4D0 - 0x4B4];
};

struct Entry_func_8043BBB0_de;
struct Screen_func_8043BBB0_de;
struct Screen_func_8043BBB0_de {
    struct Entry_func_8043BBB0_de entries[4];
};

extern int func_8043B854_de();

struct Entry42 {
    MenuWidget *window;
    struct SlotsRecAt5CV1 *slots;
    struct Object49C panel;
    char pad4A8[8];
    s32 state;
    s32 selection;
    char pad4B8[0x18];
};
struct Screen42 {
    struct Entry42 entries[4];
    char pad1340[0x18];
    s32 state;
    s32 next;
    char pad1360[8];
    s32 delay;
};
extern s8 D_80142358[];

#endif
