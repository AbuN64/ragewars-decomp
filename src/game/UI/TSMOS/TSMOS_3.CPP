#include "include_asm.h"
#include "COMMON/LONE/D_80106248.H"

#if defined(VERSION_EU)
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
extern u8 D_0043C500[];
extern char D_800C6080_eu_x[];
extern s32 D_800CBC14;
extern struct Triple D_800D2C90;
extern s32 func_80255228_de(s32 *);
extern void func_80253908_de(s32);
extern void func_80414360_de(void);
extern void ESmem_InitializeFrameHeaps(s32);
extern void func_80297FA0_de(s32, s32);
extern void Frontend_OpenResourceArchive(char *);
extern void SmpOverlay_RegisterOverlayClass(void);
extern void SmpFrameAnim_RegisterFrameAnimClass(void);
extern void SmpFade_RegisterFadeClass(void);
extern void SmpButton_RegisterButtonClass(void);
extern void SmpFlicker_RegisterFlickerClass(void);
extern void SmpSlider_RegisterSliderClass(void);
extern void SmpList_RegisterListClass(void);
extern void N64Eng_RegisterNumericWidgetClass(void);
extern void Tsmos_SetIdleTimer(f32);
extern void Tsmos_SetTimerState(s32);
extern void Tsmos_ActivateControllerState(void);

void Tsmos_InitializeEuropeanFrontend(void) {
    s32 *selected;
    func_80255228_de(&D_80106248);
    func_80253908_de(0);
    func_80414360_de();
    ESmem_InitializeFrameHeaps(0x3000);
    func_80297FA0_de(0x23, (s32)D_0043C500);
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
    selected = &D_800D2C90.z;
    *selected = 1;
    Tsmos_ActivateControllerState();
    D_800D2C90.x = 0;
    Tsmos_SetModeOneFlag(2);
}
#endif
