#include "include_asm.h"
#include "COMMON/LONE/D_80106248.H"
#include "COMMON/GFX_INITIALIZEFRONTENDSERVICES.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "MATH/SMSMNGR_INITIALIZESCREENMANAGER.H"
#include "MATH/N64_ENG.H"
#include "MENU/SMPFRAMEANIM_REGISTERFRAMEANIMCLASS.H"
#include "MENU/SMPFADE_REGISTERFADECLASS.H"
#include "MENU/SMP_SLIDER.H"
#include "MENU/SMPLIST_REGISTERLISTCLASS.H"
#include "RESMGR/802A23A4_6.H"
#include "UI/TSMOS/SMP/SMP_FLICKER.H"
#include "UI/TSMOS/TSMOS.H"

#if defined(VERSION_EU)
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
extern s32 D_800CBC14;
extern struct Triple D_800D2C90;
extern s32 func_80255228_de(s32 *);
extern void Cache_DrainAndCompactResources(s32);
extern void Node_OpenResourceArchive(char *);
extern void Tsmos_SetIdleTimer(f32);
extern void Tsmos_SetTimerState(s32);
extern void Tsmos_ActivateControllerState(void);

void Tsmos_InitializeEuropeanFrontend(void) {
    s32 *selected;
    func_80255228_de(&D_80106248);
    Cache_DrainAndCompactResources(0);
    Gfx_InitializeFrontendServices();
    ESmem_InitializeFrameHeaps(0x3000);
    SmSmngr_InitializeScreenManager(0x23, (s32)D_0043C500);
    Node_OpenResourceArchive(D_800C6080_eu_x);
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
