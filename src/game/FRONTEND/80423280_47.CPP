#include "include_asm.h"
#include "COMMON/LEVEL_GOAL.H"
#include "TYPES.H"
#include "FRONTEND/OPTIONS.H"
#include "FRONTEND/80423280_9.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted below with the other versions' body. */
#else
INCLUDE_ASM("ovl_80400000", Frontend_CreateMatchOptions);
#endif
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || defined(NON_MATCHING)
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char *D_auto_800E1CA4[];
extern char *D_auto_800E1CB4[];
extern char *D_auto_800E1CC4[];
extern char *D_auto_800E1CD4[];
extern char *D_800E1CE4[];
extern char *D_auto_800E1CF4[];
extern char *D_auto_800E1D04[];
#include "COMMON/SHARED_GAMESLOT.H"
#define MO_TEXT(i, fixed, eu) ((eu)[D_801462C8.language])
#else
#define MO_TEXT(i, fixed, eu) (fixed)
#endif

#if defined(VERSION_DE)
enum { OPTIONS_TEXT = 0x35B };
#else
enum { OPTIONS_TEXT = 0x35F };
#endif

extern struct MatchOptionsScreen *D_800E4EF0;
extern char *D_800D3494, *D_800D3498, *D_800D349C, *D_800D34A0, *D_800D34A4, *D_800D34A8, *D_800D34AC;
extern void *Cache_AllocateMemory(s32 size);
extern void func_8043C210_de(void *, s32, s32, s32, s32);
extern s32 Frontend_CountOpenPlayerSlots(void);
extern void *Frontend_FindWidgetByResourceId(void *root, s32 identifier);
extern void Frontend_SetWidgetFlag100(void *record, s32 enable);
extern void *N64Eng_CreateNumericWidget(s32, s32, s32, s32, s32);
extern void *func_8041ABC0_de(s32, s32);
extern void SmpButton_AppendListText(void *, char *);
extern void func_8041B110_de(s32);

s32 Frontend_CreateMatchOptions(void *root) {
    struct MatchOptionsScreen *screen;
    void *widget;
    void **slot;

    screen = Cache_AllocateMemory(0x40);
    D_800E4EF0 = screen;
    func_8043C210_de(screen->transition, 0x67, 0, 0, 0);
    D_800E4EF0->countCap = Frontend_CountOpenPlayerSlots();
    switch (D_8014DD98.kind) {
    case 1:
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(root, OPTIONS_TEXT + 0), 1);
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(root, OPTIONS_TEXT + 4), 1);
        break;
    case 0:
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(root, OPTIONS_TEXT + 6), 1);
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(root, OPTIONS_TEXT + 4), 1);
        break;
    case 2:
    case 3:
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(root, OPTIONS_TEXT + 0), 1);
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(root, OPTIONS_TEXT + 6), 1);
        break;
    }
    D_800E4EF0->widget24 = N64Eng_CreateNumericWidget(OPTIONS_TEXT + 4, OPTIONS_TEXT + 5, 0, 100, 1);
    D_800E4EF0->widget28 = N64Eng_CreateNumericWidget(OPTIONS_TEXT + 2, OPTIONS_TEXT + 3, 0, 100, 1);
    D_800E4EF0->widget2C = N64Eng_CreateNumericWidget(OPTIONS_TEXT + 0, OPTIONS_TEXT + 1, 0, 100, 1);
    D_800E4EF0->widget30 = N64Eng_CreateNumericWidget(OPTIONS_TEXT + 6, OPTIONS_TEXT + 7, 0, 100, 1);
    D_800E4EF0->countDefault = 0;
    if (D_800E4EF0->countCap == 3) {
        D_800E4EF0->countDefault = 1;
    }
    D_800E4EF0->widget34 = N64Eng_CreateNumericWidget(OPTIONS_TEXT + 13, OPTIONS_TEXT + 14, D_800E4EF0->countDefault,
                                            D_800E4EF0->countCap, 1);
    widget = func_8041ABC0_de(OPTIONS_TEXT + 8, OPTIONS_TEXT + 9);
    slot = &D_800E4EF0->selectWidget;
    *slot = widget;
    SmpButton_AppendListText(widget, MO_TEXT(0, D_800D3494, D_auto_800E1CA4));
    SmpButton_AppendListText(D_800E4EF0->selectWidget, MO_TEXT(1, D_800D3498, D_auto_800E1CB4));
    widget = func_8041ABC0_de(OPTIONS_TEXT + 15, OPTIONS_TEXT + 16);
    slot = &D_800E4EF0->cursorWidget;
    *slot = widget;
    SmpButton_AppendListText(widget, MO_TEXT(2, D_800D349C, D_auto_800E1CC4));
    SmpButton_AppendListText(D_800E4EF0->cursorWidget, MO_TEXT(3, D_800D34A0, D_auto_800E1CD4));
    SmpButton_AppendListText(D_800E4EF0->cursorWidget, MO_TEXT(4, D_800D34A4, D_800E1CE4));
    SmpButton_AppendListText(D_800E4EF0->cursorWidget, MO_TEXT(5, D_800D34A8, D_auto_800E1CF4));
    SmpButton_AppendListText(D_800E4EF0->cursorWidget, MO_TEXT(6, D_800D34AC, D_auto_800E1D04));
    func_8041B110_de(OPTIONS_TEXT + 10);
    func_8041B110_de(OPTIONS_TEXT + 11);
    func_8041B110_de(OPTIONS_TEXT + 12);
    func_80429560_de();
    func_80429654_de(0);
    func_80429560_de();
    return 0;
}
#endif
