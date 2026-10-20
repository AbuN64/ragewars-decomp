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

struct Data800E4400Ptr;
typedef struct Data800E4400Ptr Data800E4400Ptr;



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

struct State_func_8042177C_de;
struct State_func_8042177C_de {
    char pad0[8];
    void *list;
    char padC[0x20 - 0xC];
    void *object;
    char pad24[0x34 - 0x24];
    s32 ready;
};

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
struct Data800E4400Ptr;
struct Data800E4400Ptr {
    char a[8];
    s32 unk8;
    char b[0x14];
    struct CellRecAt1A *unk20;
    char c[8];
    s32 unk2C;
};

struct Screen_func_804210E8_de;
struct Screen_func_804210E8_de {
    char pad0[0xC];
    void *boxes[4];
};

struct Triple;

struct Rec_func_8024C92C_de;
#endif
