#include "include_asm.h"
#include "COMMON/UNUSED.H"

#if defined(VERSION_EU_X)
extern int func_802B2378(void);

void Items_PrepareControllerReturnEuX(void) {
    D_801540F4 = func_802B2378();
    D_801540F0 = 0;
}
#endif
