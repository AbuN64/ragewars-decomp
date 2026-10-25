#include "COMMON/GFX.H"
#include "COMMON/CHANNEL.H"
#include "gbi.h"
#include "TYPES.H"

extern Gfx *g_displayListCursor;
extern s32 D_800D297C;

void Camera_LoadProjectionMatrix(u32 arg0) {
    Gfx *cmd;
    u32 offset;

    offset = (D_800D297C << 6) + 0x448;
    gSPMatrix(g_displayListCursor++, arg0 + offset, G_MTX_LOAD | G_MTX_PROJECTION);
}
