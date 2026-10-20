#include "include_asm.h"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "RENDER/80291054_3.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_ASM("span_1000", func_80294158_de);
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
void func_80294158_de(void *arg0) {
    Render_DrawTextLines(arg0, 1, D_800D3038, D_800E28D0 / 2, 5, 0xA, 0.75f, 1.0f);
}
#endif
