#ifndef UNBAKE_SPAN_16E000_CODE_804366C4_H
#define UNBAKE_SPAN_16E000_CODE_804366C4_H
#include "TYPES.H"
#include "common/types_1dc8418c21db.h"
struct CellRecAt1A;
struct Menu_func_804241BC_de;
struct State_func_80437444_de;
struct State_func_80437444_de {
    struct Menu_func_804241BC_de *menu;
    char pad4[0x8 - 0x4];
    struct CellRecAt1A *list;
    s32 delay;
    s32 target;
    s32 seen;
};

struct Menu_func_80437718_de;
struct Resource_func_80419E54_de;
struct Menu_func_80437718_de {
    void *title;
    void *button;
    struct Resource_func_80419E54_de *item;
    s32 count;
    s32 selection;
};

extern s32 func_80436E04_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct MenuListScreen;
typedef struct MenuListScreen MenuListScreen;

extern s32 func_80437274_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct State_func_80436BF4_de;
struct State_func_80436BF4_de {
    void *first;
    char pad4[0x20 - 4];
    s32 value;
    char pad24[0x28 - 0x24];
    s32 item;
};

struct MenuListScreen;
struct MenuListScreen {
    void *panels[2];
    void *listB;
    void *listA;
    void *listC;
    s32 selection;
    void *window;
};

struct State_func_804368F8_de;
struct State_func_804368F8_de {
    void *c;
    void *d;
    void *b;
    void *a;
    void *e;
};

struct State_func_804366B8_de;
struct State_func_804366B8_de {
    char pad0[8];
    void *c;
    void *d;
    void *b;
    void *a;
    void *e;
};


/* Exact localized menu callbacks, bound to current native/consumer receipts. */
extern s32 func_80437114_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_80436C94_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_80436D4C_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_804371C4_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_80438F0C_de(void);

extern void func_804367A8_de(s32);

void func_804366B8_de(s32);
extern s32 D_800D34C0_de;

extern void func_804368F8_de(s32);

extern void func_804369E8_de(s32);
extern void func_8042E988_de(s32);
void func_804369E8_de(s32);

extern FieldRow D_800F1DA8[];
extern FieldRow D_800F1DAC[];

#endif
