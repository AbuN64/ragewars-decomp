#include "include_asm.h"
#include "COMMON/LEVEL_GOAL.H"
#include "TYPES.H"
#include "FRONTEND/OPTIONS.H"
#include "FRONTEND/80423280_9.H"
#include "COMMON/SHARED_GAMESLOT.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char *D_auto_800E1CA4[];
extern char *D_auto_800E1CB4[];
extern char *D_auto_800E1CC4[];
extern char *D_auto_800E1CD4[];
extern char *D_800E1CE4[];
extern char *D_auto_800E1CF4[];
extern char *D_auto_800E1D04[];
#define MO_TEXT(i, fixed, eu) ((eu)[settings->language])
#else
#define MO_TEXT(i, fixed, eu) (fixed)
#endif

#if defined(VERSION_DE)
enum { OPTIONS_TEXT = 0x35B };
#else
#if defined(VERSION_EU_X)
enum { OPTIONS_TEXT = 0x363 };
#else
enum { OPTIONS_TEXT = 0x35F };
#endif
#endif

extern struct MatchOptionsScreen *D_800E4EF0;
extern char *D_800D3494, *D_800D3498, *D_800D349C, *D_800D34A0, *D_800D34A4, *D_800D34A8, *D_800D34AC;
extern void *Cache_AllocateMemory(s32 size);
extern void Frontend_InitMenuImage(void *, s32, s32, s32, s32);
extern s32 Join_CountOpenPlayerSlots(void);
extern void *Node_FindWidgetByResourceId(void *root, s32 identifier);
extern void Widget_SetWidgetFlag100(void *record, s32 enable);
extern void *N64Eng_CreateNumericWidget(s32, s32, s32, s32, s32);
extern void *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(void *, char *);
extern void SmpButton_WrapButtonWidget(s32);

s32 Frontend_CreateMatchOptions(void *root) {
    struct MatchOptionsScreen *screen;
    Shared_Game *settings;
    void *selectList;
    void *cursorList;

    screen = Cache_AllocateMemory(0x40);
    D_800E4EF0 = screen;
    Frontend_InitMenuImage(screen->transition, 0x67, 0, 0, 0);
    D_800E4EF0->countCap = Join_CountOpenPlayerSlots();
    switch (D_8014DD98.kind) {
    case 1:
        Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(root, OPTIONS_TEXT + 0), 1);
        Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(root, OPTIONS_TEXT + 4), 1);
        break;
    case 0:
        Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(root, OPTIONS_TEXT + 6), 1);
        Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(root, OPTIONS_TEXT + 4), 1);
        break;
    case 2:
    case 3:
        Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(root, OPTIONS_TEXT + 0), 1);
        Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(root, OPTIONS_TEXT + 6), 1);
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
    selectList = SmpButton_CreateListWidget(OPTIONS_TEXT + 8, OPTIONS_TEXT + 9);
    {void **slot = &D_800E4EF0->selectWidget; *slot = selectList;}
    settings = &D_801462C8;
    SmpButton_AppendListText(selectList, MO_TEXT(0, D_800D3494, D_auto_800E1CA4));
    SmpButton_AppendListText(D_800E4EF0->selectWidget, MO_TEXT(1, D_800D3498, D_auto_800E1CB4));
    cursorList = SmpButton_CreateListWidget(OPTIONS_TEXT + 15, OPTIONS_TEXT + 16);
    {void **slot = &D_800E4EF0->cursorWidget; *slot = cursorList;}
    SmpButton_AppendListText(cursorList, MO_TEXT(2, D_800D349C, D_auto_800E1CC4));
    SmpButton_AppendListText(D_800E4EF0->cursorWidget, MO_TEXT(3, D_800D34A0, D_auto_800E1CD4));
    SmpButton_AppendListText(D_800E4EF0->cursorWidget, MO_TEXT(4, D_800D34A4, D_800E1CE4));
    SmpButton_AppendListText(D_800E4EF0->cursorWidget, MO_TEXT(5, D_800D34A8, D_auto_800E1CF4));
    SmpButton_AppendListText(D_800E4EF0->cursorWidget, MO_TEXT(6, D_800D34AC, D_auto_800E1D04));
    SmpButton_WrapButtonWidget(OPTIONS_TEXT + 10);
    SmpButton_WrapButtonWidget(OPTIONS_TEXT + 11);
    SmpButton_WrapButtonWidget(OPTIONS_TEXT + 12);
    Frontend_LoadMatchOptionWidgets();
    Frontend_SyncMatchJoinSlots(0);
    Frontend_LoadMatchOptionWidgets();
    return 0;
}
