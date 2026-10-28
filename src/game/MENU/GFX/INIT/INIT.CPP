#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"
#include "COMMON/INTEGERSTATE14_2.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/GFX_INITIALIZEFRONTENDSERVICES.H"
#include "MATH/XMATH_EVALUATEEXPONENTIALDOUBLE.H"
#include "MENU/GFX/GFX_SHUTDOWNFRONTENDSERVICES.H"
#include "RESMGR/resmgr_stream_io.H"

void Gfx_InitializeFrontendServices(void) {
    XStdio_InitializeStreams();
    XMath_InitializeMath();
}

/* Calls the per-version setup entry and then XStdio_ShutdownStreams. */







void Gfx_ShutdownFrontendServices(void) {
#if defined(VERSION_US)
    
#if defined(VERSION_US)
XMath_ShutdownMath
#else
func_8029D7E8_auto
#endif
();
#elif defined(VERSION_DE)
    XMath_ShutdownMath();
#elif defined(VERSION_EU)
    XMath_ShutdownMath();
#elif defined(VERSION_EU_X)
    XMath_ShutdownMath();
#else
    XMath_ShutdownMath();
#endif
    XStdio_ShutdownStreams();
}

#if defined(VERSION_US)
char rodata_unresolved_80414428[8] =
    "OUNDequ\202";
#endif
