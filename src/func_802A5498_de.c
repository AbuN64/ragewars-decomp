#include "common/draw_matrix_scratch.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_80296014.h"
#include "span_1000/code_802A25C4.h"
#include "abi.h"
#include "types.h"
#include "gbi.h"
#include "n64sdk.h"
extern Gfx *D_80110634;

extern char D_800D14B0;
extern char D_800CDCA8;
extern char D_801469A0;



void func_802A5498_de(u32 arg0) {
    DrawMatrixScratch local;
    Gfx *cmd;

    local.matrix[0] = 0.0f;
    local.matrix[1] = 0.0f;
    local.matrix[2] = 0.0f;
    local.matrix[4] = 0.0f;
    local.matrix[6] = 0.0f;
    local.matrix[5] = D_800C5E90_de;

    cmd = D_80110634++;
    gDPPipeSync(cmd);
    cmd = D_80110634++;
    gDPSetCycleType(cmd, G_CYC_2CYCLE);
    cmd = D_80110634++;
    gDPSetTextureImage(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 1, &D_800D14B0);
    cmd = D_80110634++;
    gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    cmd = D_80110634++;
    gDPLoadSync(cmd);
    cmd = D_80110634++;
    gDPLoadBlock(cmd, G_TX_LOADTILE, 0, 0, 127, 1024);
    cmd = D_80110634++;
    gDPPipeSync(cmd);
    cmd = D_80110634++;
    gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    cmd = D_80110634++;
    gDPSetTileSize(cmd, G_TX_RENDERTILE, 0, 0, 60, 60);
    cmd = D_80110634++;
    gDPSetPrimColor(cmd, 255, 255, 200, 0, 0, 150);
    cmd = D_80110634++;
    gSPDisplayList(cmd, &D_800CDCA8);
    cmd = D_80110634++;
    gSPMatrix(cmd, arg0, G_MTX_LOAD);
    cmd = D_80110634++;
    gSPVertex(cmd, &D_801469A0, 4, 0);
    cmd = D_80110634++;
    gSP2Triangles(cmd, 0, 1, 2, 0, 2, 3, 0, 0);

    func_8026D8F8_de();
    func_80295FF4_de();
}
