#include "gfx.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804143D8.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"


/* Emits the display-list state for the requested flag groups: records which of five two-bit flag pairs are fully set, clears the pending-sync flag and emits one pipe sync through the shared inline helper, then the other-mode and geometry-mode commands (adding the lighting bit for the fifth group) and the render mode chosen by the fourth and fifth groups, then stores the flag record. */




extern Gfx *D_80110634;
extern s32 D_800DF250;
extern s32 D_800E32CC;
extern s32 D_800E32E4;
extern Rec_func_8024C92C_de D_80153F60;


static inline void sync(void) {
    Gfx *cmd;

    if (D_800E32E4 == 0) {
        cmd = D_80110634++;
        D_800E32E4 = 1;
        gDPPipeSync(cmd);
    }
}

void func_80417138_de(s32 flags) {
    s32 plain;
    Rec_func_8024C92C_de groups;
    s32 mode;
    u32 cycle1;
    u32 cycle2;

    groups.x = (flags & 0x5) == 0x5;
    groups.y = (flags & 0x30) == 0x30;
    groups.z = (flags & 0x300) == 0x300;
    groups.pad0 = (flags & 0x3000) == 0x3000;
    groups.pad1 = (flags & 0x30000) == 0x30000;
    func_80418F8C_de();
    D_800E32E4 = 0;
    sync();
    plain = groups.y == 0;
    D_800E32CC = plain ? 11 : 12;
    gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
    gSPGeometryMode(D_80110634++, G_ZBUFFER | G_SHADE | G_CULL_FRONT | G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH, 0);
    gSPGeometryMode(D_80110634++, 0, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    if (groups.pad1) gSPGeometryMode(D_80110634++, 0, G_ZBUFFER);
    cycle1 = 0;
    cycle2 = 0;
    mode = groups.pad0 != 0;
    if (groups.pad1) {
        mode += 2;
    }
    switch (mode) {
        case 0:
            cycle1 = 0xC084000;
            cycle2 = 0x3024000;
            break;
        case 1:
            cycle1 = 0x404240;
            cycle2 = 0x104240;
            break;
        case 2:
            cycle1 = 0x442230;
            cycle2 = 0x112230;
            break;
        case 3:
            cycle1 = 0x404A50;
            cycle2 = 0x104A50;
            break;
    }
    D_800DF250 = 1;
    gDPSetRenderMode(D_80110634++, cycle1, cycle2);
    D_80153F60 = groups;
}
