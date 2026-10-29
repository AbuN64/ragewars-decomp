#include "include_asm.h"

/* 8040B45C_24.CPP */
#if defined(VERSION_DE)
unsigned char g_FrontendCreatecourseoptionsmenuTrailingBytes[8] = { 0x3C, 0x06, 0xE3, 0x00, 0x46, 0x00, 0x10, 0x01 };
#endif

/* 8041DF04_4.CPP */
#if defined(VERSION_US_REV1)
/* Creates the three-row request screen and shows its selected row. */
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/REQUESTRECAT10.H"
#include "TYPES.H"
#include "COMMON/SHARED_MENUREPLY.H"

extern struct CourseOptionsScreen *g_courseOptionsScreen;

s32 Frontend_CreateCourseOptionsMenu(void *root) {
    SlotSelectionWidget *item;
    s32 row;

    { void *memory = Cache_AllocateMemory(32); g_courseOptionsScreen = memory; }
    g_courseOptionsScreen->handle = root;
    g_courseOptionsScreen->mode = SmpOverlay_CreateOverlayNode((s32) root, 4);
    SmpOverlay_ShowSlotById((s32) root, 0, 905);
    SmpOverlay_ShowSlotById((s32) root, 1, 905);
    SmpOverlay_ShowSlotById((s32) root, 2, 905);
    SmpOverlay_ShowSlotById((s32) root, 3, 905);

    item = Node_FindWidgetByResourceId(root, 907);
    item->alpha = 140;
    if (Menu_GetPreviousScreenOwner(0) == 22) {
        Widget_SetWidgetFlag08(item, 0);
    }

    g_courseOptionsScreen->timer = 0;
    g_courseOptionsScreen->selection = 0;
    item = Node_FindWidgetByResourceId(root, 908);
    g_courseOptionsScreen->rows[0] = item;
    item = Node_FindWidgetByResourceId(root, 917);
    g_courseOptionsScreen->rows[1] = item;
    item = Node_FindWidgetByResourceId(root, 918);
    g_courseOptionsScreen->rows[2] = item;
    g_courseOptionsScreen->step = Join_CountUsedSlots();

    for (row = 0; row < 3; row++) {
        Join_UpdateJoinRequestDisplay(row);
        item = Node_FindWidgetByResourceId(g_courseOptionsScreen->rows[row], 914);
        Widget_SetWidgetFlag08(item, 0);
    }

    Tsmos_ActivateControllerState();

    item = Node_FindWidgetByResourceId(g_courseOptionsScreen->rows[g_courseOptionsScreen->selection], 914);
    Widget_SetWidgetFlag08(item, 1);
    return 0;
}
#endif

/* 80406A88_14.CPP */
#if defined(VERSION_EU_X)
#include "TYPES.H"
typedef struct { void *list; s32 resourceWidget; void *item; s32 scrollDelay; s32 reservedWord10; char text14[12]; s32 playerCount; } SliderPopupEu;
typedef struct { u8 pad0[0x10]; u8 alpha; u8 pad11[0x27]; void *text; } SliderItemEu;
extern SliderPopupEu *g_playerCountScreen;
extern char s_playerCountFormat[];
extern void *Cache_AllocateMemory(s32);
extern void Tsmos_ActivateControllerState(void);
extern void *SmpFade_CreateFadeWidget(s32, s32);
extern void SmpSlider_EnableTransition(void *);
extern void SmpButton_WrapButtonWidget(s32);
extern void *Node_FindWidgetByResourceId(void *, s32);
extern void *SmpFlicker_CreateFlickerWidget(s32, s32);
extern void XStdio_FormatBuffer(char *, char *, ...);
/* Builds a three-row slider popup in its 0x24-byte state g_playerCountScreen: title/list from the ids at 0x39C, the numeric
   readout item at 0x39D showing the text at +0x14 formatted with s_playerCountFormat. Returns 0. */
s32 Frontend_CreatePlayerCountScreenEux(void *window) {
    SliderItemEu *item;
    void *title;

    g_playerCountScreen = Cache_AllocateMemory(36);
    Tsmos_ActivateControllerState();
    title = SmpFade_CreateFadeWidget(924, 925);
    g_playerCountScreen->list = title;
    SmpSlider_EnableTransition(title);
    SmpButton_WrapButtonWidget(928);
    item = Node_FindWidgetByResourceId(window, 926);
    g_playerCountScreen->item = item;
    item->alpha = 15;
    g_playerCountScreen->resourceWidget = SmpFlicker_CreateFlickerWidget(927, 110);
    g_playerCountScreen->scrollDelay = 3;
    item = Node_FindWidgetByResourceId(window, 929);
    item->text = g_playerCountScreen->text14;
    g_playerCountScreen->playerCount = 1;
    XStdio_FormatBuffer(g_playerCountScreen->text14, s_playerCountFormat, 1);
    return 0;
}
#endif
