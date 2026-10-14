#include "span_1000/code_802BA23C.h"
#include "acmd.h"
#include "types.h"
/* With interrupts disabled, stores a video mode pointer in the next video context, marks the mode updated and copies the mode's control word (libultra osViSetMode). Adapted from func_802BB3D0_de with the body changed to the libultra osViSetMode shape. */







extern __OSViContext_func_802BA6B0_de *D_800D4414;
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);

void func_802BA6B0_de(OSViMode *modep) {
    register u32 saveMask = func_802BCF30_de();

    D_800D4414->modep = modep;
    D_800D4414->state = 1;
    D_800D4414->control = D_800D4414->modep->comRegs.w0;
    func_802BCF50_de(saveMask);
}
