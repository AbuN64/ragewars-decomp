#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAME_SESSION.H"
#include "MENU/80408AC4_26.H"

#if defined(VERSION_DE)
#include "SYSTEM_2/8025E280.H"
#include "MENU_2/SCROLL.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/RECRECAT4.H"
#include "TYPES.H"
struct MenuFadeWidget;
struct MenuResourceWidget;
extern struct MenuResourceWidget *SmpFlicker_CreateFlickerWidget(s32, s32);
extern OptionsCommitContext *g_optionsPage;
/* Localized label pointers for the two option lists (rev1 D_auto_800D74AC..B0, D_800D2134..213C). */
extern u8 *D_auto_800D3488[1];
extern u8 *D_auto_800D348C;
extern u8 *D_auto_800D3490;
extern void *Cache_AllocateMemory(s32);
extern struct MenuFadeWidget *SmpFade_CreateFadeWidget(s32, s32);
extern s32 Defs_GetMemorySize(void);
extern MenuListWidget *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(struct MenuListWidget *, u8 *);
extern void SmpButton_SelectListEntry(struct MenuListWidget *, s32);
extern MenuSliderWidget *SmpSlider_CreateSliderWidget(s32, s32, s32);
extern void SmpSlider_SetSliderItem(Scroll *, s32);
/* German Menu_CreateOptionsPage: the same options-commit page without the first (language) list, so the
   lists 0x51/0x52 and 0x53/0x54 fill unk_10 and unk_14 and the slider is 0x55/0x56. */
s32 Menu_CreateSettingsPage(void) {
    Shared_Game *settings;
    void *secondList;
    void *thirdList;
    void *title;
    void *slider;
    g_optionsPage = Cache_AllocateMemory(0x28);
    g_optionsPage->menu = SmpFade_CreateFadeWidget(0x4D, 0x4E);
    SmpButton_WrapButtonWidget(0x57);
    SmpButton_WrapButtonWidget(0x58);
    secondList = SmpButton_CreateListWidget(0x51, 0x52);
    g_optionsPage->unk_10 = secondList;
    SmpButton_AppendListText(secondList, D_auto_800D3480[0]);
    SmpButton_AppendListText(g_optionsPage->unk_10, D_auto_800D3484);
    settings = &D_801462C8;
    SmpButton_SelectListEntry(g_optionsPage->unk_10, settings->unknown1F);
    thirdList = SmpButton_CreateListWidget(0x53, 0x54);
    g_optionsPage->unk_14 = thirdList;
    SmpButton_AppendListText(thirdList, D_auto_800D3488[0]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(g_optionsPage->unk_14, D_auto_800D348C);
        SmpButton_AppendListText(g_optionsPage->unk_14, D_auto_800D3490);
    }
    SmpButton_SelectListEntry(g_optionsPage->unk_14, settings->reserved580);
    slider = SmpSlider_CreateSliderWidget(0x55, 0x56, 0x80);
    g_optionsPage->unk_8 = slider;
    SmpSlider_SetSliderItem(slider, settings->buttons);
    SmpButton_WrapButtonWidget(0x50);
    title = SmpFlicker_CreateFlickerWidget(0x4F, 0x6E);
    g_optionsPage->state = 3;
    g_optionsPage->title = title;
    g_optionsPage->value = -1;
    return 0;
}
#endif
