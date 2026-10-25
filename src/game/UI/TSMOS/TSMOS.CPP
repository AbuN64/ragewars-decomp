#include "include_asm.h"
#include "COMMON/LONE/D_80106248.H"

#if defined(VERSION_US) || defined(VERSION_US_REV1)
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
extern void Menu_RegisterOverlayClass(void);
extern void Menu_RegisterFrameAnimClass(void);
extern void Menu_RegisterFadeClass(void);
extern void Menu_RegisterButtonClass(void);
extern void Menu_RegisterFlickerClass(void);
extern void Menu_RegisterSliderClass(void);
extern void Menu_RegisterListClass(void);
extern void func_802A1960_de(void);
extern void func_802A2400_de(f32);
extern void func_802A2418_de(s32);
extern void func_802A2360_de(void);

void InitFrontendMenus(void) {
    func_80255228_de(&D_80106248);
    func_80253908_de(0);
    func_80414360_de();
    func_802A16F8_de(0x3000);
    func_80297FA0_de(0x23, (s32)D_0043C500);
    Frontend_OpenResourceArchive(D_800C6080_eu_x);
    Menu_RegisterOverlayClass();
    Menu_RegisterFrameAnimClass();
    Menu_RegisterFadeClass();
    Menu_RegisterButtonClass();
    Menu_RegisterFlickerClass();
    Menu_RegisterSliderClass();
    Menu_RegisterListClass();
    func_802A1960_de();
    D_800CBC14 = 0x3C;
    func_802A2400_de(0.0f);
    func_802A2418_de(1);
    D_800D2C90.z = 1;
    func_802A2360_de();
    D_800D2C90.x = 0;
    func_802A23C4_de(2);
}
#endif
