#include "COMMON/BOOT_TV_TYPE.H"
#include "acmd.h"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "sdk/AUDIO/visetmode.H"
#include "sdk/os.h"

extern StateosViSetSpecialFeatures *g_nextVideoInterfaceContext;

void osViSetSpecialFeatures(s32 featureCommands) {
    u32 token;

    token = __osDisableInt();
    if (featureCommands & 1) {
        g_nextVideoInterfaceContext->flags |= 8;
    }
    if (featureCommands & 2) {
        g_nextVideoInterfaceContext->flags &= ~8;
    }
    if (featureCommands & 4) {
        g_nextVideoInterfaceContext->flags |= 4;
    }
    if (featureCommands & 8) {
        g_nextVideoInterfaceContext->flags &= ~4;
    }
    if (featureCommands & 0x10) {
        g_nextVideoInterfaceContext->flags |= 0x10;
    }
    if (featureCommands & 0x20) {
        g_nextVideoInterfaceContext->flags &= ~0x10;
    }
    if (featureCommands & 0x40) {
        g_nextVideoInterfaceContext->flags = (g_nextVideoInterfaceContext->flags | 0x10000) & ~0x300;
    }
    if (featureCommands & 0x80) {
        g_nextVideoInterfaceContext->flags &= ~0x10000;
        g_nextVideoInterfaceContext->flags |= g_nextVideoInterfaceContext->inner->w1 & 0x300;
    }
    g_nextVideoInterfaceContext->status |= 8;
    __osRestoreInt(token);
}
