#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "sdk/os.h"

extern State_func_802BA700_de *D_800D4414;
extern u32 func_802BCF30_de(void);

void osViSwapBuffer(s32 arg0) {
    u32 savedMask;

    savedMask = func_802BCF30_de();
    D_800D4414->word4 = arg0;
    D_800D4414->status |= 0x10;
    __osRestoreInt(savedMask);
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802BA834);
#endif
