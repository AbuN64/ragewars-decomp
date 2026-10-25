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
extern void func_802A16F8_de(s32 a);
extern void func_80297FA0_de(s32 a, void *b);
extern void Frontend_OpenResourceArchive(void *a);
extern void Menu_RegisterOverlayClass(void);
extern void Menu_RegisterFrameAnimClass(void);
extern void Menu_RegisterFadeClass(void);
extern void Menu_RegisterButtonClass(void);
extern void Menu_RegisterFlickerClass(void);
extern void Menu_RegisterSliderClass(void);
extern void Menu_RegisterListClass(void);
extern void func_802A1960_de(void);
extern void func_802A2400_de(f32 a);
extern void func_802A2418_de(s32 a);
extern void func_802A2360_de(void);
extern void func_802A23C4_de(s32 a);
extern void Frontend_LoadLanguageStringsIfAny(s32 a);
/* Start-up sequence for the title mode: initialises the subsystems in a fixed order, sets D_800CBC14 to 0x3C, then D_800D2C98 to 1 and D_800D2C90 to 0 around the final mode calls. */
void func_802A2224_de(void) {
    func_80255228_de(D_80106248);
    func_80253908_de(0);
    func_80414360_de();
    func_802A16F8_de(0x3000);
    func_80297FA0_de(0x23, D_0043C320_de);
    Frontend_OpenResourceArchive(D_auto_rodata_func_802A2224_de_800C5DA0);
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
    D_800D2C98 = 1;
    func_802A2360_de();
    D_800D2C90 = 0;
    func_802A23C4_de(2);
    Frontend_LoadLanguageStringsIfAny(0);
}
#else
INCLUDE_ASM("span_1000", func_802A2224_de);
#endif
#endif
