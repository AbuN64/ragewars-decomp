#include "gfx.h"
#include "span_16E000/code_804143D8.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"



/* Sets the environment and primitive colours from a packed 0xAARRGGBB colour when it differs from
   the last one set, D_800DF28C: appends 0xFB (environment, alpha zero) and 0xFA (primitive, with
   alpha) commands to the display list D_80110634 points into. */

extern u32 D_800DF28C;
extern Gfx *D_80110634;

void func_804191F8_de(u32 color) {
    Gfx *gfx;

    if (color == D_800DF28C) {
        return;
    }
    D_800DF28C = color;
    gfx = D_80110634++;
    gDPSetEnvColor(gfx, color >> 16, (color & 0xFF00) >> 8, color, 0);
    gfx = D_80110634++;
    
    gDPSetPrimColor(gfx, 0, 0, color >> 16, (color & 0xFF00) >> 8, color, color >> 24);
}
