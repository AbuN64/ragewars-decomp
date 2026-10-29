#include "include_asm.h"
#include "../include/libgultra.h"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "../include/os.h"

extern StateosViSetSpecialFeatures *g_nextVideoInterfaceContext;

void osViSwapBuffer(s32 framebuffer) {
    u32 savedMask;

    savedMask = __osDisableInt();
    g_nextVideoInterfaceContext->word4 = framebuffer;
    g_nextVideoInterfaceContext->status |= 0x10;
    __osRestoreInt(savedMask);
}

#if defined(VERSION_US)
char s_ViswapbufCharAnimRText[12] =
    "_CharAnimR\000\000";
#endif
