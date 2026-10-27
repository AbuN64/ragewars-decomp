#include "include_asm.h"

/* 8040B45C_24.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_80414358_de_padding_17A358[8] = { 0x3C, 0x06, 0xE3, 0x00, 0x46, 0x00, 0x10, 0x01 };
#endif

/* 8041DF04_4.CPP */
#if defined(VERSION_US_REV1)
/* Creates the three-row request screen and shows its selected row. */
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/REQUESTRECAT10.H"
#include "TYPES.H"
#include "COMMON/SHARED_MENUREPLY.H"

extern struct CourseOptionsScreen *D_800E39C0;

s32 Frontend_CreateCourseOptionsMenu(void *root) {
    func_8041F2A0_Item *item;
    s32 row;

    { void *memory = Cache_AllocateMemory(0x20); D_800E39C0 = memory; }
    D_800E39C0->handle = root;
    D_800E39C0->mode = SmpOverlay_CreateOverlayNode((s32) root, 4);
    SmpOverlay_ShowSlotById((s32) root, 0, 0x389);
    SmpOverlay_ShowSlotById((s32) root, 1, 0x389);
    SmpOverlay_ShowSlotById((s32) root, 2, 0x389);
    SmpOverlay_ShowSlotById((s32) root, 3, 0x389);

    item = Frontend_FindWidgetByResourceId(root, 0x38B);
    item->alpha = 0x8C;
    if (Smos_GetPreviousScreenOwner(0) == 22) {
        Frontend_SetWidgetFlag08(item, 0);
    }

    D_800E39C0->timer = 0;
    D_800E39C0->selection = 0;
    item = Frontend_FindWidgetByResourceId(root, 0x38C);
    D_800E39C0->rows[0] = item;
    item = Frontend_FindWidgetByResourceId(root, 0x395);
    D_800E39C0->rows[1] = item;
    item = Frontend_FindWidgetByResourceId(root, 0x396);
    D_800E39C0->rows[2] = item;
    D_800E39C0->step = Frontend_CountUsedSlots();

    for (row = 0; row < 3; row++) {
        Frontend_UpdateJoinRequestDisplay(row);
        item = Frontend_FindWidgetByResourceId(D_800E39C0->rows[row], 0x392);
        Frontend_SetWidgetFlag08(item, 0);
    }

    Tsmos_ActivateControllerState();

    item = Frontend_FindWidgetByResourceId(D_800E39C0->rows[D_800E39C0->selection], 0x392);
    Frontend_SetWidgetFlag08(item, 1);
    return 0;
}
#endif

/* 80406A88_14.CPP */
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
