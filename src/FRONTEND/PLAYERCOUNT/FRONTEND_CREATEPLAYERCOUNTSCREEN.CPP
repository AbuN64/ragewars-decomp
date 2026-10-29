#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "TYPES.H"
#include "COMMON/SHARED_MENUREPLY.H"

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* Builds screen state g_playerCountScreen: allocates 0x24 bytes, sets up the handle for resources
   0x398/0x399, loads resource 0x39C, wires up windows 0x39A and 0x39D, the 0x39B button and
   the delay, and formats s_playerCountFormat into the state's text buffer through XStdio_FormatBuffer. */

extern struct PlayerCountScreenState *g_playerCountScreen;

extern s32 SmpFade_CreateFadeWidget(s32, s32);
extern void SmpSlider_EnableTransition(s32);
extern void XStdio_FormatBuffer(void *, void *, s32);

s32 Frontend_CreatePlayerCountScreen(s32 screenData) {
    struct PlayerCountScreenState *state;
    s32 handle;
    struct MenuWidget *node;
    void *text;

    /* the hub's allocation helper returns its SelectionScreenState view; this unit keeps its own state type */
    g_playerCountScreen = (struct PlayerCountScreenState *) Cache_AllocateMemory(0x24);
    Tsmos_ActivateControllerState();
    handle = SmpFade_CreateFadeWidget(0x398, 0x399);
    state = g_playerCountScreen;
    state->menu = handle;
    SmpSlider_EnableTransition(handle);
    SmpButton_WrapButtonWidget(0x39C);
    /* the MenuWidget view names the alpha byte at +0x10 and the text pointer at +0x34 that the hub's Item omits */
    node = (struct MenuWidget *) Node_FindWidgetByResourceId((void *) screenData, 0x39A);
    state = g_playerCountScreen;
    state->window = node;
    node->alpha = 0xF;
    handle = SmpFlicker_CreateFlickerWidget(0x39B, 0x6E);
    state = g_playerCountScreen;
    state->button = handle;
    state->delay = 3;
    node = (struct MenuWidget *) Node_FindWidgetByResourceId((void *) screenData, 0x39D);
    state = g_playerCountScreen;
    text = &state->text;
    node->text = text;
    state->value = 1;
    XStdio_FormatBuffer(text, s_playerCountFormat, 1);
    return 0;
}
#endif
