#include "COMMON/BOOT_TV_TYPE.H"
#include "acmd.h"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "../../include/os.h"

/* With interrupts disabled, stores a video mode pointer in the next video context, marks the mode updated and copies the mode's control word (libultra osViSetMode). Adapted from __osResetGlobalIntMask with the body changed to the libultra osViSetMode shape. */







extern ViModeContextView *__osViNext;

void osViSetMode(OSViMode *modep) {
    register u32 saveMask = __osDisableInt();

    __osViNext->modep = modep;
    __osViNext->state = 1;
    __osViNext->control = __osViNext->modep->comRegs.w0;
    __osRestoreInt(saveMask);
}
