#include "COMMON/ITEMRECAT20V1.H"
#include "RENDER_2/OBJECTSTATE8E.H"
#include "COMMON/OBJECTSTATE18.H"
#include "gbi.h"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SESSIONHANDLERROW.H"

/* Draws a player's marker when it is enabled at 0x1214: loads the player's matrix for the current view
   D_800D297C from its table at 0x1500, sets the render and geometry modes, fills the eight vertices of
   a red prism in D_80102A58 (alpha 150 on the upper and 100 on the lower corners), emits them with the
   eight triangles joining them, and passes the same colour and alphas to Fx_DrawRedParticleQuad with the
   matrix from the table at 0x1580 when 0x147C is set. */








extern s32 D_800D297C;

extern void Geometry_SetModePreset(s32);
extern void Geometry_SetCombineMode(s32);
extern void Fx_DrawRedParticleQuad(UnitMtx *, s32, s32, s32);

void func_8021C698_de(PlayerCode802192C0 *player) {
    s32 red;
    s32 low;
    s32 high;

    if (player->marker != 0) {
        gSPMatrix(g_displayListCursor++, &player->views[D_800D297C], G_MTX_LOAD);
        gDPPipeSync(g_displayListCursor++);
        Geometry_InvalidateMaterialKeys();
        Geometry_SetModePreset(0xE);
        Geometry_SetCombineMode(0x1C);
        red = 200;
        low = 100;
        high = 150;
        gSPGeometryMode(g_displayListCursor++, G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | 0x80, 0);
        gSPGeometryMode(g_displayListCursor++, 0, G_SHADE | G_SHADING_SMOOTH);
        D_80102A58[0].x = 0;
        D_80102A58[0].y = 1;
        D_80102A58[0].z = 0;
        D_80102A58[0].flag = 0;
        D_80102A58[0].s = 0;
        D_80102A58[0].t = 0;
        D_80102A58[0].r = red;
        D_80102A58[0].g = 0;
        D_80102A58[0].b = 0;
        D_80102A58[0].a = high;
        D_80102A58[1].x = 1;
        D_80102A58[1].y = 0;
        D_80102A58[1].z = 0;
        D_80102A58[1].flag = 0;
        D_80102A58[1].s = 0;
        D_80102A58[1].t = 0;
        D_80102A58[1].r = red;
        D_80102A58[1].g = 0;
        D_80102A58[1].b = 0;
        D_80102A58[1].a = high;
        D_80102A58[2].x = 0;
        D_80102A58[2].y = -1;
        D_80102A58[2].z = 0;
        D_80102A58[2].flag = 0;
        D_80102A58[2].s = 0;
        D_80102A58[2].t = 0;
        D_80102A58[2].r = red;
        D_80102A58[2].g = 0;
        D_80102A58[2].b = 0;
        D_80102A58[2].a = low;
        D_80102A58[3].x = -1;
        D_80102A58[3].y = -1;
        D_80102A58[3].z = 0;
        D_80102A58[3].flag = 0;
        D_80102A58[3].s = 0;
        D_80102A58[3].t = 0;
        D_80102A58[3].r = red;
        D_80102A58[3].g = 0;
        D_80102A58[3].b = 0;
        D_80102A58[3].a = low;
        D_80102A58[4].x = 0;
        D_80102A58[4].y = 1;
        D_80102A58[4].z = -1;
        D_80102A58[4].flag = 0;
        D_80102A58[4].s = 0;
        D_80102A58[4].t = 0;
        D_80102A58[4].r = red;
        D_80102A58[4].g = 0;
        D_80102A58[4].b = 0;
        D_80102A58[4].a = high;
        D_80102A58[5].x = 1;
        D_80102A58[5].y = 0;
        D_80102A58[5].z = -1;
        D_80102A58[5].flag = 0;
        D_80102A58[5].s = 0;
        D_80102A58[5].t = 0;
        D_80102A58[5].r = red;
        D_80102A58[5].g = 0;
        D_80102A58[5].b = 0;
        D_80102A58[5].a = high;
        D_80102A58[6].x = 0;
        D_80102A58[6].y = -1;
        D_80102A58[6].z = -1;
        D_80102A58[6].flag = 0;
        D_80102A58[6].s = 0;
        D_80102A58[6].t = 0;
        D_80102A58[6].r = red;
        D_80102A58[6].g = 0;
        D_80102A58[6].b = 0;
        D_80102A58[6].a = low;
        D_80102A58[7].x = -1;
        D_80102A58[7].y = -1;
        D_80102A58[7].z = -1;
        D_80102A58[7].flag = 0;
        D_80102A58[7].s = 0;
        D_80102A58[7].t = 0;
        D_80102A58[7].r = red;
        D_80102A58[7].g = 0;
        D_80102A58[7].b = 0;
        D_80102A58[7].a = low;
        gSPVertex(g_displayListCursor++, (u32) D_80102A58, 8, 0);
        gSP1Triangle(g_displayListCursor++, 0, 1, 4, 0);
        gSP1Triangle(g_displayListCursor++, 1, 4, 5, 0);
        gSP1Triangle(g_displayListCursor++, 1, 2, 5, 0);
        gSP1Triangle(g_displayListCursor++, 2, 5, 6, 0);
        gSP1Triangle(g_displayListCursor++, 2, 3, 6, 0);
        gSP1Triangle(g_displayListCursor++, 3, 6, 7, 0);
        gSP1Triangle(g_displayListCursor++, 3, 0, 7, 0);
        gSP1Triangle(g_displayListCursor++, 0, 7, 4, 0);
        if (player->second != 0) {
            Fx_DrawRedParticleQuad(&player->markers[D_800D297C], red, low, high);
        }
    }
}
