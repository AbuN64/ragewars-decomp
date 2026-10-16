#ifndef UNBAKE_SPAN_16E000_CODE_80420E90_H
#define UNBAKE_SPAN_16E000_CODE_80420E90_H
#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
extern void func_804210E8_de();

struct CellRecAt1A;

extern float D_800DD600;

extern void func_80422020_de();

extern s32 func_80421A58_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern void func_8042177C_de();

struct Data800E4400Ptr;
typedef struct Data800E4400Ptr Data800E4400Ptr;

extern void func_80421234_de();

extern void func_804217D4_de();

struct MenuWidget;
struct NumberPadScreen;
struct NumberPadScreen {
    char pad0[8];
    void *window;
    char padC[0x20 - 0xC];
    struct MenuWidget *pad;
    char pad24[4];
    s32 length;
    s32 mode;
    s32 value;
    s32 cursor;
    s32 full;
};

struct NumberPadScreen;
typedef struct NumberPadScreen NumberPadScreen;

extern s32 func_80421E60_de(s32 *record);

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
extern s32 func_80421E9C_de(struct Meter *meter, s32 step);

extern s32 func_80421DD0_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

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

struct Screen_func_80421884_de;
struct Screen_func_80421884_de {
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
extern void func_80421E6C_de(struct Triple *timer, s32 mode);

struct Rec_func_8024C92C_de;
extern void func_80421FEC_de(struct Rec_func_8024C92C_de *record, s32 value);

#endif
