#ifndef COMMON_MENULISTSCREEN_H
#define COMMON_MENULISTSCREEN_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct CellRecAt1A;
struct MenuFrontendUpdatePlayModeMenu;
struct State_func_80437444_de;
struct State_func_80437444_de {
    struct MenuFrontendUpdatePlayModeMenu *menu;
    char pad4[0x8 - 0x4];
    struct CellRecAt1A *list;
    s32 delay;
    s32 target;
    s32 seen;
};

struct Menu_func_80437718_de;
struct ResourceSmpFlickerCreateFlickerWidget;
struct Menu_func_80437718_de {
    void *title;
    void *button;
    struct ResourceSmpFlickerCreateFlickerWidget *item;
    s32 count;
    s32 selection;
};


struct MenuListScreen;
typedef struct MenuListScreen MenuListScreen;


struct Label;
struct MenuStepState;
struct MenuStepState {
    void *menu;
    char pad4[0x20 - 4];
    s32 value;
    char pad24[0x28 - 0x24];
    s32 item;
    struct Label *label;
    char text[1];
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

struct StateMenuSelectPlayerSettingsEntry;
struct StateMenuSelectPlayerSettingsEntry {
    char pad0[8];
    void *c;
    void *d;
    void *b;
    void *a;
    void *e;
};




extern s32 D_800D34C0_de;


extern void func_8042E988_de(s32);

extern FieldRow D_800F1DA8[];
extern FieldRow D_800F1DAC[];
#endif
