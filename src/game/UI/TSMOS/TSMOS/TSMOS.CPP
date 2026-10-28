#include "include_asm.h"
#include "COMMON/LONE/D_80106248.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/EXTERNS_4.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "MATH/80297CD0_3.H"
#include "MATH/802A2870.H"
#include "MENU/804196C0_13.H"
#include "MENU/804196C0_20.H"
#include "MENU/804196C0_21.H"
#include "MENU/804196C0_22.H"
#include "RESMGR/802A23A4_6.H"
#include "UI/TSMOS/SMP/SMP_FLICKER.H"
#include "UI/TSMOS/TSMOS.H"

#if defined(VERSION_US) || defined(VERSION_US_REV1) || defined(VERSION_DE) || defined(VERSION_EU_X)
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"

extern s32 D_800CBC14;
extern struct Triple D_800D2C90;
extern s32 func_80255228_de(s32 *);
extern void Cache_DrainAndCompactResources(s32);
extern void Frontend_OpenResourceArchive(char *);
extern void Tsmos_SetIdleTimer(f32);
extern void Tsmos_SetTimerState(s32);
extern void Tsmos_ActivateControllerState(void);
extern void Frontend_LoadLanguageStringsIfAny(s32);

void InitFrontendMenus(void) {
    func_80255228_de(&D_80106248);
    Cache_DrainAndCompactResources(0);
    Gfx_InitializeFrontendServices();
    ESmem_InitializeFrameHeaps(0x3000);
    SmSmngr_InitializeScreenManager(0x23, (s32)D_0043C500);
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
    D_800D2C90.z = 1;
    Tsmos_ActivateControllerState();
    D_800D2C90.x = 0;
    Tsmos_SetModeOneFlag(2);
#if defined(VERSION_DE)
    Frontend_LoadLanguageStringsIfAny(0);
#elif defined(VERSION_EU_X)
    Frontend_LoadLanguageStringsIfAny(g_languageIndex);
#endif
}
#endif
