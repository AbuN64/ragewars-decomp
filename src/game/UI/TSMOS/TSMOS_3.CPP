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
extern void func_802A16F8_de(s32);
extern void func_80297FA0_de(s32, s32);
extern void Frontend_OpenResourceArchive(char *);
extern void SmpOverlay_RegisterOverlayClass(void);
extern void SmpFrameAnim_RegisterFrameAnimClass(void);
extern void SmpFade_RegisterFadeClass(void);
extern void SmpButton_RegisterButtonClass(void);
extern void SmpFlicker_RegisterFlickerClass(void);
extern void SmpSlider_RegisterSliderClass(void);
extern void SmpList_RegisterListClass(void);
extern void func_802A1960_de(void);
extern void func_802A2400_de(f32);
extern void func_802A2418_de(s32);
extern void func_802A2360_de(void);

void func_802A2344_eu(void) {
    s32 *selected;
    func_80255228_de(&D_80106248);
    func_80253908_de(0);
    func_80414360_de();
    func_802A16F8_de(0x3000);
    func_80297FA0_de(0x23, (s32)D_0043C500);
    Frontend_OpenResourceArchive(D_800C6080_eu_x);
    SmpOverlay_RegisterOverlayClass();
    SmpFrameAnim_RegisterFrameAnimClass();
    SmpFade_RegisterFadeClass();
    SmpButton_RegisterButtonClass();
    SmpFlicker_RegisterFlickerClass();
    SmpSlider_RegisterSliderClass();
    SmpList_RegisterListClass();
    func_802A1960_de();
    D_800CBC14 = 0x3C;
    func_802A2400_de(0.0f);
    func_802A2418_de(1);
    selected = &D_800D2C90.z;
    *selected = 1;
    func_802A2360_de();
    D_800D2C90.x = 0;
    func_802A23C4_de(2);
}
#endif
