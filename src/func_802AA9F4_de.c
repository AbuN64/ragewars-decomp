#include "gfx.h"
#include "span_1000/code_802A8A94.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"



/* Appends a pipe synchronisation and an other-mode setting to the display list D_80110634 points
   into, then calls func_8026925C_de with 0x15 and func_80268CE0_de with 0x19. */

extern Gfx *D_80110634;
extern void func_8026925C_de(u32);
extern void func_80268CE0_de(u32);

void func_802AA9F4_de(void) {
    Gfx *gfx;

    gfx = D_80110634++;
    gDPPipeSync(gfx);
    gfx = D_80110634++;
    gDPSetCycleType(gfx, G_CYC_1CYCLE);
    func_8026925C_de(0x15);
    func_80268CE0_de(0x19);
}
