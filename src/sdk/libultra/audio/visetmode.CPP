#include "COMMON/EXTERNS_3.H"
#include "acmd.h"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "sdk/AUDIO/visetmode.H"
#include "sdk/os.h"

extern StateosViSetSpecialFeatures *D_800D4414;

void osViSetSpecialFeatures(s32 featureCommands) {
    u32 token;

    token = __osDisableInt();
    if (featureCommands & 1) {
        D_800D4414->flags |= 8;
    }
    if (featureCommands & 2) {
        D_800D4414->flags &= ~8;
    }
    if (featureCommands & 4) {
        D_800D4414->flags |= 4;
    }
    if (featureCommands & 8) {
        D_800D4414->flags &= ~4;
    }
    if (featureCommands & 0x10) {
        D_800D4414->flags |= 0x10;
    }
    if (featureCommands & 0x20) {
        D_800D4414->flags &= ~0x10;
    }
    if (featureCommands & 0x40) {
        D_800D4414->flags = (D_800D4414->flags | 0x10000) & ~0x300;
    }
    if (featureCommands & 0x80) {
        D_800D4414->flags &= ~0x10000;
        D_800D4414->flags |= D_800D4414->inner->w1 & 0x300;
    }
    D_800D4414->status |= 8;
    __osRestoreInt(token);
}
