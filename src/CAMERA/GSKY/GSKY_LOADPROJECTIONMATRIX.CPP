#include "COMMON/GFX.H"
#include "COMMON/WEAPON_MARKER_AND_PROFILE_VIEWS.H"
#include "COMMON/CHANNEL.H"
#include "gbi.h"
#include "TYPES.H"

extern Gfx *g_displayListCursor;

void Gsky_LoadProjectionMatrix(u32 cameraAddress) {
    Gfx *cmd;
    u32 offset;

    offset = (g_lightingBufferIndex << 6) + 1096;
    gSPMatrix(g_displayListCursor++, cameraAddress + offset, G_MTX_LOAD | G_MTX_PROJECTION);
}
