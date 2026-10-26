#include "include_asm.h"

#if defined(VERSION_EU_X)
#include "TYPES.H"
typedef struct { void *list; s32 resourceWidget; void *item; s32 unkC; s32 unk10; char text14[12]; s32 unk20; } SliderPopupEu;
typedef struct { u8 pad0[0x10]; u8 alpha; u8 pad11[0x27]; void *text; } SliderItemEu;
extern SliderPopupEu *D_800E5430;
extern char D_800E1B60[];
extern void *Cache_AllocateMemory(s32);
extern void Tsmos_ActivateControllerState(void);
extern void *SmpFade_CreateFadeWidget(s32, s32);
extern void SmpSlider_EnableTransition(void *);
extern void SmpButton_WrapButtonWidget(s32);
extern void *Frontend_FindWidgetByResourceId(void *, s32);
extern void *SmpFlicker_CreateFlickerWidget(s32, s32);
extern void XStdio_FormatBuffer(char *, char *, ...);
/* Builds a three-row slider popup in its 0x24-byte state D_800E5430: title/list from the ids at 0x39C, the numeric
   readout item at 0x39D showing the text at +0x14 formatted with D_800E1B60. Returns 0. */
s32 Frontend_CreatePlayerCountScreenEux(void *window) {
    SliderItemEu *item;
    void *title;

    D_800E5430 = Cache_AllocateMemory(0x24);
    Tsmos_ActivateControllerState();
    title = SmpFade_CreateFadeWidget(0x39C, 0x39D);
    D_800E5430->list = title;
    SmpSlider_EnableTransition(title);
    SmpButton_WrapButtonWidget(0x3A0);
    item = Frontend_FindWidgetByResourceId(window, 0x39E);
    D_800E5430->item = item;
    item->alpha = 0xF;
    D_800E5430->resourceWidget = SmpFlicker_CreateFlickerWidget(0x39F, 0x6E);
    D_800E5430->unkC = 3;
    item = Frontend_FindWidgetByResourceId(window, 0x3A1);
    item->text = D_800E5430->text14;
    D_800E5430->unk20 = 1;
    XStdio_FormatBuffer(D_800E5430->text14, D_800E1B60, 1);
    return 0;
}
#endif
