#include "include_asm.h"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
typedef struct EuOptsPage_eux { void *title; void *list; void *bar; void *rowC; void *row10; void *row14; s32 pad18, pad1C, sel, count; } EuOptsPage_eux;
extern EuOptsPage_eux *g_optionsPage;
extern char *D_800E1C14[], *D_800E1C34[], *D_800E1C44[], *D_auto_800E1C54[], *D_auto_800E1C64[], *D_800D2134[], *D_800D2138[], *D_800D213C[];
extern void *Cache_AllocateMemory(); extern void *SmpFade_CreateFadeWidget(); extern void SmpButton_WrapButtonWidget(); extern void *SmpButton_CreateListWidget();
extern void SmpButton_AppendListText(); extern void SmpButton_SelectListEntry(); extern u32 Defs_GetMemorySize(); extern void *SmpSlider_CreateSliderWidget();
extern void SmpSlider_SetSliderItem(); extern void *SmpFlicker_CreateFlickerWidget(); extern void *Frontend_FindWidgetByResourceId();
extern char *D_auto_800DDB08[];
/* Builds the options page (0x28-byte state g_optionsPage): title, the three toggle rows (ids 0x53/0x56/0x58) labelled in the
   current language and set from the option bytes 0x1B, 0x1F and 0x580 of D_801462C8, the volume bar 0x5A and its list. Returns 0. */
s32 func_804229E0_eu_x(void *window) {
    u8 lang = D_801462C8.language;
    g_optionsPage = Cache_AllocateMemory(0x28);
    g_optionsPage->title = SmpFade_CreateFadeWidget(0x4F, 0x50);
    SmpButton_WrapButtonWidget(0x52);
    SmpButton_WrapButtonWidget(0x55);
    g_optionsPage->rowC = SmpButton_CreateListWidget(0x53, 0x54);
    SmpButton_AppendListText(g_optionsPage->rowC, D_800E1C14[lang]);
    SmpButton_AppendListText(g_optionsPage->rowC, D_800E1C34[lang]);
    SmpButton_AppendListText(g_optionsPage->rowC, D_800E1C44[lang]);
    SmpButton_SelectListEntry(g_optionsPage->rowC, *((u8 *)&D_801462C8 + 0x1B));
    g_optionsPage->row10 = SmpButton_CreateListWidget(0x56, 0x57);
    SmpButton_AppendListText(g_optionsPage->row10, D_auto_800E1C54[lang]);
    SmpButton_AppendListText(g_optionsPage->row10, D_auto_800E1C64[lang]);
    SmpButton_SelectListEntry(g_optionsPage->row10, *((u8 *)&D_801462C8 + 0x1F));
    g_optionsPage->row14 = SmpButton_CreateListWidget(0x58, 0x59);
    SmpButton_AppendListText(g_optionsPage->row14, D_800D2134[lang]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(g_optionsPage->row14, D_800D2138[lang]);
        SmpButton_AppendListText(g_optionsPage->row14, D_800D213C[lang]);
        SmpButton_SelectListEntry(g_optionsPage->row14, *((u8 *)&D_801462C8 + 0x580));
    }
    g_optionsPage->bar = SmpSlider_CreateSliderWidget(0x5A, 0x5B, 0x80);
    SmpSlider_SetSliderItem(g_optionsPage->bar, *(s32 *)((u8 *)&D_801462C8 + 0x10));
    SmpButton_WrapButtonWidget(0x5D);
    ((u8 **)Frontend_FindWidgetByResourceId(window, 0x5E))[0x38 / 4] = (u8 *)D_auto_800DDB08[lang];
    SmpButton_WrapButtonWidget(0x5C);
    g_optionsPage->list = SmpFlicker_CreateFlickerWidget(0x51, 0x6E);
    g_optionsPage->count = 3;
    g_optionsPage->sel = -1;
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_804229E0_eu_x);
#endif
#endif
