#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"
#include "COMMON/INTEGERSTATE14_2.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/EXTERNS_4.H"
#include "MATH/8029BBA0_5.H"
#include "MENU/GFX/804143E0.H"
#include "RESMGR/802A0888_8.H"

void func_80414360_de(void) {
    func_802A0D38_de();
    func_8029D8A0_de();
}

/* Calls the per-version setup entry and then func_802A0E34_de. */







void func_80414384_de(void) {
#if defined(VERSION_US)
    
#if defined(VERSION_US)
func_8029D8A8_de
#else
func_8029D7E8_auto
#endif
();
#elif defined(VERSION_DE)
    func_8029D8A8_de();
#elif defined(VERSION_EU)
    func_8029D8A8_de();
#elif defined(VERSION_EU_X)
    func_8029D8A8_de();
#else
    func_8029D8A8_de();
#endif
    func_802A0E34_de();
}

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", rodata_unresolved_80414428);
#endif
