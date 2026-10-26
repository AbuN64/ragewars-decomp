#include "include_asm.h"
#include "COMMON/STATEPAIR.H"
#include "COMMON/LONE/D_80152789.H"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
extern char D_80106248[], D_800C6080_eu_x[], D_0043D330_eu_x[];
extern s32 D_800D2C90, D_800D2C98;
extern void func_80255228_de(void *), func_80253908_de(s32), func_80414360_de(void), ESmem_InitializeFrameHeaps(s32);
extern void func_80297FA0_de(s32, void *), Frontend_OpenResourceArchive(void *), SmpOverlay_RegisterOverlayClass(void), SmpFrameAnim_RegisterFrameAnimClass(void);
extern void SmpFade_RegisterFadeClass(void), SmpButton_RegisterButtonClass(void), SmpFlicker_RegisterFlickerClass(void), SmpSlider_RegisterSliderClass(void);
extern void SmpList_RegisterListClass(void), N64Eng_RegisterNumericWidgetClass(void), Tsmos_SetIdleTimer(f32), Tsmos_SetTimerState(s32);
extern void Tsmos_ActivateControllerState(void), Tsmos_SetModeOneFlag(s32), Frontend_LoadLanguageStringsIfAny(s32);
/* Brings the screen layer up: display state, resources, the menu builders, then the language-specific start sound. */
void func_802A2374_eu_x(void) {
    func_80255228_de(D_80106248);
    func_80253908_de(0);
    func_80414360_de();
    ESmem_InitializeFrameHeaps(0x3000);
    func_80297FA0_de(0x23, D_0043D330_eu_x);
    Frontend_OpenResourceArchive(D_800C6080_eu_x);
    SmpOverlay_RegisterOverlayClass();
    SmpFrameAnim_RegisterFrameAnimClass();
    SmpFade_RegisterFadeClass();
    SmpButton_RegisterButtonClass();
    SmpFlicker_RegisterFlickerClass();
    SmpSlider_RegisterSliderClass();
    SmpList_RegisterListClass();
    N64Eng_RegisterNumericWidgetClass();
    D_800CBC14 = 0x3C;
    Tsmos_SetIdleTimer(0.0f);
    Tsmos_SetTimerState(1);
    D_800D2C98 = 1;
    Tsmos_ActivateControllerState();
    D_800D2C90 = 0;
    Tsmos_SetModeOneFlag(2);
    Frontend_LoadLanguageStringsIfAny(g_languageIndex);
}
#else
INCLUDE_ASM("span_1000", func_802A2374_eu_x);
#endif
#endif
