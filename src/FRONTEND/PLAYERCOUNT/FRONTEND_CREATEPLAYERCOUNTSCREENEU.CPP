#include "include_asm.h"

#if defined(VERSION_EU)
#include "TYPES.H"
typedef struct { void *list; s32 resourceWidget; void *item; s32 playerCount; s32 reservedWord; char text14[12]; s32 selectionChanged; } SliderPopupEu;
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
/* Builds a three-row slider popup in its 0x24-byte state g_playerCountScreen: title/list from the ids at 0x398, the numeric
   readout item at 0x39D showing the text at +0x14 formatted with s_playerCountFormat. Returns 0. */
s32 Frontend_CreatePlayerCountScreenEu(void *window) {
    SliderItemEu *item;
    void *title;

    g_playerCountScreen = Cache_AllocateMemory(0x24);
    Tsmos_ActivateControllerState();
    title = SmpFade_CreateFadeWidget(0x398, 0x399);
    g_playerCountScreen->list = title;
    SmpSlider_EnableTransition(title);
    SmpButton_WrapButtonWidget(0x39C);
    item = Node_FindWidgetByResourceId(window, 0x39A);
    g_playerCountScreen->item = item;
    item->alpha = 0xF;
    g_playerCountScreen->resourceWidget = SmpFlicker_CreateFlickerWidget(0x39B, 0x6E);
    g_playerCountScreen->playerCount = 3;
    item = Node_FindWidgetByResourceId(window, 0x39D);
    item->text = g_playerCountScreen->text14;
    g_playerCountScreen->selectionChanged = 1;
    XStdio_FormatBuffer(g_playerCountScreen->text14, s_playerCountFormat, 1);
    return 0;
}
#endif
