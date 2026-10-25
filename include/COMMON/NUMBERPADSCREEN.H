#ifndef COMMON_NUMBERPADSCREEN_H
#define COMMON_NUMBERPADSCREEN_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
extern void func_804210E8_de();

struct CellRecAt1A;

extern float D_800DD600;

extern void func_80422020_de();


extern void func_8042177C_de();




struct MenuWidget;
struct NumberPadScreen;

struct NumberPadScreen;
typedef struct NumberPadScreen NumberPadScreen;


extern void func_804213DC_de();

struct Meter;
struct Resource_func_80419E54_de;
struct Meter {
    s32 amount;
    s32 done;
    s32 falling;
    struct Resource_func_80419E54_de *bar;
};

struct Meter;


extern float D_800DD608;


struct NumberPadScreen {
    union { s32 dialog; void *title; };
    void *list;
    void *window;
    void *buttons[4];
    char pad1C[4];
    struct MenuWidget *pad;
    char pad24[4];
    s32 length;
    s32 mode;
    s32 value;
    union { s32 open; s32 cursor; };
    union { s32 confirmed; s32 full; };
};

struct CellRecAt1A;


struct Triple;

struct Rec_func_8024C92C_de;
#endif
