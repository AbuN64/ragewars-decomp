#include "include_asm.h"

#if defined(VERSION_DE)
extern int D_8013B2BC;
extern int D_801540F4, D_801540F0;
extern int func_802AD2A8_de(int);

void Items_PrepareMenuReturnDe(void) {
    D_801540F4 = func_802AD2A8_de(D_8013B2BC);
    D_801540F0 = 1;
}
#endif
