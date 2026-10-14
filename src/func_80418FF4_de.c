#include "gfx.h"
#include "span_16E000/code_804143D8.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"


/* Switches the render mode, emitting a full-sync command the first time and a cycle-type other-mode command for modes 6 and 7. */


extern s32 D_800DF274;
extern s32 D_800E32E4;
extern Gfx *D_80110634;

static inline void beginFrame(void) {
    Gfx *g;

    D_800E32E4 = 1;
    g = D_80110634++;
    gDPPipeSync(g);
}

void func_80418FF4_de(s32 mode) {
    if (mode != D_800DF274) {
        D_800DF274 = mode;
        if (D_800E32E4 == 0) {
            beginFrame();
        }
        switch (mode) {
        case 6: {
            Gfx *g = D_80110634++;
            gDPSetTexturePersp(g, G_TP_PERSP);
            break;
        }
        case 7: {
            Gfx *g = D_80110634++;
            gDPSetTexturePersp(g, G_TP_NONE);
            break;
        }
        }
    }
}
