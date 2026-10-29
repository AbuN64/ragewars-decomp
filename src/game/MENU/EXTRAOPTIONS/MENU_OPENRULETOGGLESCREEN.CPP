#include "include_asm.h"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "TYPES.H"
#include "MENU/MENU_REFRESHEXTRAOPTIONLOCKS.H"

#if (defined(VERSION_EU) || defined(VERSION_EU_X)) && !defined(NON_MATCHING)
INCLUDE_ASM("ovl_frontendMenu", Menu_OpenRuleToggleScreen);
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || defined(NON_MATCHING)
/* Fuzzy draft in EU and EU-X: their body differs. */
/* Opens the options screen: allocates its 0x3C-byte state into g_extraOptionsScreen for window window, builds
   its title, heading and the four toggle buttons 0x3B4, 0x3B1, 0x3AD and 0x3AF set from bits of
   g_gameSettings, creates the item list and refreshes the limit markers through Menu_RefreshExtraOptionLocks. */

extern struct OptionsOpenScreen *g_extraOptionsScreen;
extern s32 g_gameSettings;

/* The hub spells the allocator, the window item lookup and the list builder; these helpers stay. */
extern void *SmpFade_CreateFadeWidget(s32, s32);
extern void *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(void *, void *);
extern void SmpButton_SelectListEntry(void *, s32);

#if defined(VERSION_DE)
#define ID(n) ((n) - 6)
#define COLOR 0x86
#else
#define ID(n) (n)
#define COLOR 0x88
#endif
s32 Menu_OpenRuleToggleScreen(void *window) {
    struct OptionsOpenScreen *screen;
    void *button;

    screen = (struct OptionsOpenScreen *) Cache_AllocateMemory(0x3C);
    g_extraOptionsScreen = screen;
    screen->window = window;
    screen->full = 0;
    /* the hub's item type carries no color; this unit's options view names the byte at +0x1A */
    ((OptionsOpenItem *) Node_FindWidgetByResourceId(window, ID(0x3A8)))->color = COLOR;
    g_extraOptionsScreen->title = SmpFade_CreateFadeWidget(ID(0x3A8), ID(0x3A9));
    SmpButton_WrapButtonWidget(ID(0x3B6));

    button = SmpButton_CreateListWidget(ID(0x3B4), ID(0x3B5));
    g_extraOptionsScreen->buttons[0] = button;
    SmpButton_AppendListText(button, g_toggleListClearLabel[0]);
    SmpButton_AppendListText(g_extraOptionsScreen->buttons[0], g_toggleListSetLabel[0]);
    if (g_gameSettings & 0x8000000) {
        SmpButton_SelectListEntry(g_extraOptionsScreen->buttons[0], 1);
    } else {
        SmpButton_SelectListEntry(g_extraOptionsScreen->buttons[0], 0);
    }

    button = SmpButton_CreateListWidget(ID(0x3B1), ID(0x3B2));
    g_extraOptionsScreen->buttons[1] = button;
    SmpButton_AppendListText(button, g_toggleListClearLabel[0]);
    SmpButton_AppendListText(g_extraOptionsScreen->buttons[1], g_toggleListSetLabel[0]);
    if (g_gameSettings & 0x10000000) {
        SmpButton_SelectListEntry(g_extraOptionsScreen->buttons[1], 1);
    } else {
        SmpButton_SelectListEntry(g_extraOptionsScreen->buttons[1], 0);
    }

    button = SmpButton_CreateListWidget(ID(0x3AD), ID(0x3AE));
    g_extraOptionsScreen->buttons[2] = button;
    SmpButton_AppendListText(button, g_toggleListClearLabel[0]);
    SmpButton_AppendListText(g_extraOptionsScreen->buttons[2], g_toggleListSetLabel[0]);
    if (g_gameSettings & 0x8) {
        SmpButton_SelectListEntry(g_extraOptionsScreen->buttons[2], 1);
    } else {
        SmpButton_SelectListEntry(g_extraOptionsScreen->buttons[2], 0);
    }

    button = SmpButton_CreateListWidget(ID(0x3AF), ID(0x3B0));
    g_extraOptionsScreen->buttons[3] = button;
    SmpButton_AppendListText(button, g_toggleListClearLabel[0]);
    SmpButton_AppendListText(g_extraOptionsScreen->buttons[3], g_toggleListSetLabel[0]);
    if (g_gameSettings & 0x20000000) {
        SmpButton_SelectListEntry(g_extraOptionsScreen->buttons[3], 1);
    } else {
        SmpButton_SelectListEntry(g_extraOptionsScreen->buttons[3], 0);
    }

    SmpButton_WrapButtonWidget(ID(0x3AC));
    g_extraOptionsScreen->cursor = (OptionsOpenItem *) Node_FindWidgetByResourceId(window, ID(0x3B7));
    g_extraOptionsScreen->length = 0;
    g_extraOptionsScreen->mode = 0;
    g_extraOptionsScreen->open = 1;
    /* the hub publishes the list builder as returning the word naming the list; the member stores it */
    g_extraOptionsScreen->list = (void *) SmpFlicker_CreateFlickerWidget(ID(0x3AA), 0x6E);
    Menu_RefreshExtraOptionLocks();
    return 0;
}
#endif
