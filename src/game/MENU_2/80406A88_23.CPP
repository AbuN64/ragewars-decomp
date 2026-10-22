#include "include_asm.h"

#if defined(VERSION_EU_X)
extern int func_802B2378(void);
extern int D_801540F4;
extern int D_801540F0;

void func_80444480_eu_x(void) {
    D_801540F4 = func_802B2378();
    D_801540F0 = 0;
}
#endif
