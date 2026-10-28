#include "COMMON/GFX.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/CHANNEL.H"
#include "gbi.h"
#include "TYPES.H"

extern Gfx *g_displayListCursor;

void Gsky_LoadProjectionMatrix(u32 cameraAddress) {
    Gfx *cmd;
    u32 offset;

    offset = (D_800D297C << 6) + 0x448;
    gSPMatrix(g_displayListCursor++, cameraAddress + offset, G_MTX_LOAD | G_MTX_PROJECTION);
}
