#include "include_asm.h"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "RENDER/80291054_3.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern void *D_800E0B34[];
extern u8 D_80152789;
/* The EU builds pick the text for the current menu language. */
#define LINES_TEXT D_800E0B34[D_80152789]
#else
#define LINES_TEXT D_800D3038
#endif
void func_80294158_de(void *arg0) {
    Render_DrawTextLines(arg0, 1, LINES_TEXT, D_800E28D0 / 2, 5, 0xA, 0.75f, 1.0f);
}
