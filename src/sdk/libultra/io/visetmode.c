#include "COMMON/EXTERNS_3.H"
#include "acmd.h"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_11.H"
#include "sdk/os.h"

/* With interrupts disabled, stores a video mode pointer in the next video context, marks the mode updated and copies the mode's control word (libultra osViSetMode). Adapted from func_802BB3D0_de with the body changed to the libultra osViSetMode shape. */







extern __OSViContext_func_802BA6B0_de *D_800D4414;

void osViSetMode(OSViMode *modep) {
    register u32 saveMask = __osDisableInt();

    D_800D4414->modep = modep;
    D_800D4414->state = 1;
    D_800D4414->control = D_800D4414->modep->comRegs.w0;
    __osRestoreInt(saveMask);
}
