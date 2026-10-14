#include "gfx.h"
#include "span_16E000/code_804143D8.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"



/* Appends one pipe synchronisation to the display list D_80110634 points into the first time it
   is called after func_804191E8_de clears the flag D_800E32E4. */

extern s32 D_800E32E4;
extern Gfx *D_80110634;

void func_804191A4_de(void) {
    Gfx *gfx;

    if (D_800E32E4 == 0) {
        D_800E32E4 = 1;
        gDPPipeSync(D_80110634++);
    }
}
