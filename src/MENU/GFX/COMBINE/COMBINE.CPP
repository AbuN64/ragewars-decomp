#include "COMMON/RECTANGLE_DRAW.H"
#include "COMMON/GFX.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TEXTURE.H"
#include "gbi.h"
#include "TYPES.H"
#include "MENU/GFX/COMBINE_CONFIGUREPRIMITIVERENDERFLAGS.H"
#include "MENU/GFX/RECT.H"

/* Emits the display-list state for the requested flag groups: records which of five two-bit flag pairs are fully set, clears the pending-sync flag and emits one pipe sync through the shared inline helper, then the other-mode and geometry-mode commands (adding the lighting bit for the fifth group) and the render mode chosen by the fourth and fifth groups, then stores the flag record. */




extern Gfx *g_displayListCursor;
extern s32 g_combineRenderStateEnabled;
extern s32 g_combineCachedRenderMode;


static inline void sync(void) {
    Gfx *cmd;

    if (g_combinePipelineSyncPending == 0) {
        cmd = g_displayListCursor++;
        g_combinePipelineSyncPending = 1;
        gDPPipeSync(cmd);
    }
}

void Combine_ConfigurePrimitiveRenderFlags(s32 flags) {
    s32 plain;
    RecGobjinstSampleBoneTranslation groups;
    s32 mode;
    u32 cycle1;
    u32 cycle2;

    groups.x = (flags & 0x5) == 0x5;
    groups.y = (flags & 0x30) == 0x30;
    groups.z = (flags & 0x300) == 0x300;
    groups.pad0 = (flags & 0x3000) == 0x3000;
    groups.pad1 = (flags & 0x30000) == 0x30000;
    Rect_ResetRenderState();
    g_combinePipelineSyncPending = 0;
    sync();
    plain = groups.y == 0;
    g_combineCachedRenderMode = plain ? 11 : 12;
    gDPSetCycleType(g_displayListCursor++, G_CYC_1CYCLE);
    gSPGeometryMode(g_displayListCursor++, G_ZBUFFER | G_SHADE | G_CULL_FRONT | G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH, 0);
    gSPGeometryMode(g_displayListCursor++, 0, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    if (groups.pad1) gSPGeometryMode(g_displayListCursor++, 0, G_ZBUFFER);
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
    g_combineRenderStateEnabled = 1;
    gDPSetRenderMode(g_displayListCursor++, cycle1, cycle2);
    g_combineRenderSwitches = groups;
}
