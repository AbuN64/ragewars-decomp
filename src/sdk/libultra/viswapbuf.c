#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "sdk/os.h"

extern State_func_802BA700_de *D_800D4414;

void osViSwapBuffer(s32 framebuffer) {
    u32 savedMask;

    savedMask = __osDisableInt();
    D_800D4414->word4 = framebuffer;
    D_800D4414->status |= 0x10;
    __osRestoreInt(savedMask);
}

#if defined(VERSION_US)
char rodata_unresolved_802BA834[12] =
    "_CharAnimR\000\000";
#endif
