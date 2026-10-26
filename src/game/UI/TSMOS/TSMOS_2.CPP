#include "include_asm.h"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
extern char D_80106248[];
extern char D_0043C320_de[];
extern char D_auto_rodata_func_802A2224_de_800C5DA0[];
extern s32 D_800CBC14;
extern s32 D_800D2C98;
extern s32 D_800D2C90;
extern void func_80255228_de(void *a);
extern void func_80253908_de(s32 a);
extern void func_80414360_de(void);
extern void ESmem_InitializeFrameHeaps(s32 a);
extern void func_80297FA0_de(s32 a, void *b);
extern void Frontend_OpenResourceArchive(void *a);
extern void SmpOverlay_RegisterOverlayClass(void);
extern void SmpFrameAnim_RegisterFrameAnimClass(void);
extern void SmpFade_RegisterFadeClass(void);
extern void SmpButton_RegisterButtonClass(void);
extern void SmpFlicker_RegisterFlickerClass(void);
extern void SmpSlider_RegisterSliderClass(void);
extern void SmpList_RegisterListClass(void);
extern void N64Eng_RegisterNumericWidgetClass(void);
extern void Tsmos_SetIdleTimer(f32 a);
extern void Tsmos_SetTimerState(s32 a);
extern void Tsmos_ActivateControllerState(void);
extern void Tsmos_SetModeOneFlag(s32 a);
extern void Frontend_LoadLanguageStringsIfAny(s32 a);
/* Start-up sequence for the title mode: initialises the subsystems in a fixed order, sets D_800CBC14 to 0x3C, then D_800D2C98 to 1 and D_800D2C90 to 0 around the final mode calls. */
void func_802A2224_de(void) {
    func_80255228_de(D_80106248);
    func_80253908_de(0);
    func_80414360_de();
    ESmem_InitializeFrameHeaps(0x3000);
    func_80297FA0_de(0x23, D_0043C320_de);
    Frontend_OpenResourceArchive(D_auto_rodata_func_802A2224_de_800C5DA0);
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
    Frontend_LoadLanguageStringsIfAny(0);
}
#else
INCLUDE_ASM("span_1000", func_802A2224_de);
#endif
#endif
