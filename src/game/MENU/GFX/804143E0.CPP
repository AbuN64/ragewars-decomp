#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"
#include "COMMON/INTEGERSTATE14_2.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/EXTERNS_4.H"
#include "MATH/8029BBA0_5.H"
#include "MENU/GFX/804143E0.H"
#include "RESMGR/resmgr_stream_io.H"

void func_80414360_de(void) {
    Resmgr_InitializeStreams();
    func_8029D8A0_de();
}

/* Calls the per-version setup entry and then Resmgr_ShutdownStreams. */







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
    Resmgr_ShutdownStreams();
}

#if defined(VERSION_US)
char rodata_unresolved_80414428[8] =
    "OUNDequ\202";
#endif
