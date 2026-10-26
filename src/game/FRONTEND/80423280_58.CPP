#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "TYPES.H"
#include "COMMON/SHARED_MENUREPLY.H"

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* Builds screen state D_800E5430: allocates 0x24 bytes, sets up the handle for resources
   0x398/0x399, loads resource 0x39C, wires up windows 0x39A and 0x39D, the 0x39B button and
   the delay, and formats D_800E1B60 into the state's text buffer through XStdio_FormatBuffer. */

extern struct State_func_8042D9E8_de *D_800E5430;

extern s32 SmpFade_CreateFadeWidget(s32, s32);
extern void SmpSlider_EnableTransition(s32);
extern void XStdio_FormatBuffer(void *, void *, s32);

s32 func_8042DBD0_us_rev1(s32 arg0) {
    struct State_func_8042D9E8_de *state;
    s32 handle;
    struct MenuWidget *node;
    void *text;

    /* the hub's allocation helper returns its SelectionScreenState view; this unit keeps its own state type */
    D_800E5430 = (struct State_func_8042D9E8_de *) Cache_AllocateMemory(0x24);
    Tsmos_ActivateControllerState();
    handle = SmpFade_CreateFadeWidget(0x398, 0x399);
    state = D_800E5430;
    state->menu = handle;
    SmpSlider_EnableTransition(handle);
    SmpButton_WrapButtonWidget(0x39C);
    /* the MenuWidget view names the alpha byte at +0x10 and the text pointer at +0x34 that the hub's Item omits */
    node = (struct MenuWidget *) Frontend_FindWidgetByResourceId((void *) arg0, 0x39A);
    state = D_800E5430;
    state->window = node;
    node->alpha = 0xF;
    handle = SmpFlicker_CreateFlickerWidget(0x39B, 0x6E);
    state = D_800E5430;
    state->button = handle;
    state->delay = 3;
    node = (struct MenuWidget *) Frontend_FindWidgetByResourceId((void *) arg0, 0x39D);
    state = D_800E5430;
    text = &state->text;
    node->text = text;
    state->value = 1;
    XStdio_FormatBuffer(text, D_800E1B60, 1);
    return 0;
}
#endif
