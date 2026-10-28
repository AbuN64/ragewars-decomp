#include "include_asm.h"
#include "MENU/80406A88_6.H"
#include "COMMON/EXTERNS_20.H"
#include "FRONTEND/8040B45C_33.H"

/* 80406A88_6.CPP */
#if defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU_2/SCROLL.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/RECRECAT4.H"
#include "TYPES.H"
struct MenuFadeWidget;
struct MenuResourceWidget;
extern OptionsCommitContext *g_optionsPage;
/* Per-language label pointer tables, indexed by the settings language byte (0x581). */
extern u8 *D_800E1C14[];
extern u8 *D_800D2134[];
extern u8 *D_800D2138[];
extern u8 *D_800D213C[];
extern u8 *D_auto_800DDB08[];
extern void *Cache_AllocateMemory(s32);
extern s32 Defs_GetMemorySize(void);
extern struct MenuFadeWidget *SmpFade_CreateFadeWidget(s32, s32);
extern struct MenuResourceWidget *SmpFlicker_CreateFlickerWidget(s32, s32);
extern MenuListWidget *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(struct MenuListWidget *, u8 *);
extern void SmpButton_SelectListEntry(struct MenuListWidget *, s32);
extern MenuSliderWidget *SmpSlider_CreateSliderWidget(s32, s32, s32);
extern void SmpSlider_SetSliderItem(Scroll *, s32);
extern MenuWidget *Frontend_FindWidgetByResourceId(void *, s32);
/* eu-x Options_CreateOptionsPage: the PAL options page with its own resource ids, plus the caption widget
   0x5E whose text is set from the per-language table D_auto_800DDB08. */
s32 Menu_CreateLocalizedSettingsPage(void *node) {
    Shared_Game *settings;
    void *firstList;
    void *secondList;
    void *thirdList;
    void *title;
    void *slider;
    g_optionsPage = Cache_AllocateMemory(0x28);
    g_optionsPage->menu = SmpFade_CreateFadeWidget(0x4F, 0x50);
    SmpButton_WrapButtonWidget(0x52);
    SmpButton_WrapButtonWidget(0x55);
    firstList = SmpButton_CreateListWidget(0x53, 0x54);
    settings = &D_801462C8;
    g_optionsPage->unk_C = firstList;
    SmpButton_AppendListText(firstList, D_800E1C14[settings->language]);
    SmpButton_AppendListText(g_optionsPage->unk_C, D_800E1C34[settings->language]);
    SmpButton_AppendListText(g_optionsPage->unk_C, D_800E1C44[settings->language]);
    SmpButton_SelectListEntry(g_optionsPage->unk_C, settings->firstListMode);
    secondList = SmpButton_CreateListWidget(0x56, 0x57);
    g_optionsPage->unk_10 = secondList;
    SmpButton_AppendListText(secondList, D_auto_800E1C54[settings->language]);
    SmpButton_AppendListText(g_optionsPage->unk_10, D_auto_800E1C64[settings->language]);
    SmpButton_SelectListEntry(g_optionsPage->unk_10, settings->unknown1F);
    thirdList = SmpButton_CreateListWidget(0x58, 0x59);
    g_optionsPage->unk_14 = thirdList;
    SmpButton_AppendListText(thirdList, D_800D2134[settings->language]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(g_optionsPage->unk_14, D_800D2138[settings->language]);
        SmpButton_AppendListText(g_optionsPage->unk_14, D_800D213C[settings->language]);
    }
    SmpButton_SelectListEntry(g_optionsPage->unk_14, settings->reserved580);
    slider = SmpSlider_CreateSliderWidget(0x5A, 0x5B, 0x80);
    g_optionsPage->unk_8 = slider;
    SmpSlider_SetSliderItem(slider, settings->buttons);
    SmpButton_WrapButtonWidget(0x5D);
    Frontend_FindWidgetByResourceId(node, 0x5E)->text = D_auto_800DDB08[settings->language];
    SmpButton_WrapButtonWidget(0x5C);
    title = SmpFlicker_CreateFlickerWidget(0x51, 0x6E);
    g_optionsPage->state = 3;
    g_optionsPage->title = title;
    g_optionsPage->value = -1;
    return 0;
}
#endif

/* 80408AC4_12.CPP */
#if defined(VERSION_DE)
extern char D_800D7A0C[];
extern char D_800DE7BC[];
typedef struct { char pad0[0x14]; char *text; } Func_8040BB40_Obj;
s32 Menu_SelectPakOperationActionLabel(Func_8040BB40_Obj *arg0) {
    switch (D_80153778) {
    case 0:
    default:
        arg0->text = D_800D7A0C;
        break;
    case 3:
        arg0->text = D_800D7A0C;
        break;
    case 4:
        arg0->text = D_800D7A0C;
        break;
    case 1:
    case 2:
        arg0->text = D_800DE7BC;
        break;
    }
    return 0;
}
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_8040BBAC_de_padding_171BAC[4] = { 0xD3, 0x1F, 0xFF, 0x0D };
#endif

/* 80408CB0_24.CPP */
#if defined(VERSION_EU)
#include "COMMON/REQUESTRECAT10.H"
extern struct CourseOptionsScreen *D_800E39C0;
extern void *Cache_AllocateMemory(s32);
extern s32 SmpOverlay_CreateOverlayNode(void *, s32);
extern void SmpOverlay_ShowSlotById(void *, s32, s32);
extern void Frontend_SetWidgetFlag08(MenuWidget *, s32);
extern void Tsmos_ActivateControllerState(void);

s32 Menu_CreateEuJoinOptions(void *handle) {
    MenuWidget *widget;
    s32 i;
    D_800E39C0 = Cache_AllocateMemory(0x20);
    D_800E39C0->handle = handle;
    D_800E39C0->mode = SmpOverlay_CreateOverlayNode(handle, 4);
    SmpOverlay_ShowSlotById(handle, 0, 0x389);
    SmpOverlay_ShowSlotById(handle, 1, 0x389);
    SmpOverlay_ShowSlotById(handle, 2, 0x389);
    SmpOverlay_ShowSlotById(handle, 3, 0x389);
    widget = Frontend_FindWidgetByResourceId(handle, 0x38B);
    widget->alpha = 0x8C;
    if (Menu_GetPreviousScreenOwner(0) == 0x16) {
        Frontend_SetWidgetFlag08(widget, 0);
    }
    D_800E39C0->timer = 0;
    D_800E39C0->selection = 0;
    D_800E39C0->rows[0] = Frontend_FindWidgetByResourceId(handle, 0x38C);
    D_800E39C0->rows[1] = Frontend_FindWidgetByResourceId(handle, 0x395);
    D_800E39C0->rows[2] = Frontend_FindWidgetByResourceId(handle, 0x396);
    D_800E39C0->step = Join_CountUsedSlots();
    for (i = 0; i < 3; i++) {
        Join_UpdateJoinRequestDisplay(i);
        Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E39C0->rows[i], 0x392), 0);
    }
    Tsmos_ActivateControllerState();
    Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E39C0->rows[D_800E39C0->selection], 0x392), 1);
    return 0;
}
#endif
