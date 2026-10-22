#include "include_asm.h"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
extern char D_80106248[], D_800C6080_eu_x[], D_0043D330_eu_x[];
extern s32 D_800CBC14, D_800D2C90, D_800D2C98;
extern u8 D_80152789;
extern void func_80255228_de(void *), func_80253908_de(s32), func_80414360_de(void), func_802A16F8_de(s32);
extern void func_80297FA0_de(s32, void *), func_8040FB94_de(void *), func_8041B5E0_de(void), func_8041989C_de(void);
extern void func_8041A400_de(void), func_8041B0E0_de(void), func_80419E24_de(void), func_8041A550_de(void);
extern void func_8041AB90_de(void), func_802A1960_de(void), func_802A2400_de(f32), func_802A2418_de(s32);
extern void func_802A2360_de(void), func_802A23C4_de(s32), func_80411DA4_de(s32);
/* Brings the screen layer up: display state, resources, the menu builders, then the language-specific start sound. */
void func_802A2374_eu_x(void) {
    func_80255228_de(D_80106248);
    func_80253908_de(0);
    func_80414360_de();
    func_802A16F8_de(0x3000);
    func_80297FA0_de(0x23, D_0043D330_eu_x);
    func_8040FB94_de(D_800C6080_eu_x);
    func_8041B5E0_de();
    func_8041989C_de();
    func_8041A400_de();
    func_8041B0E0_de();
    func_80419E24_de();
    func_8041A550_de();
    func_8041AB90_de();
    func_802A1960_de();
    D_800CBC14 = 0x3C;
    func_802A2400_de(0.0f);
    func_802A2418_de(1);
    D_800D2C98 = 1;
    func_802A2360_de();
    D_800D2C90 = 0;
    func_802A23C4_de(2);
    func_80411DA4_de(D_80152789);
}
#else
INCLUDE_ASM("span_1000", func_802A2374_eu_x);
#endif
#endif
