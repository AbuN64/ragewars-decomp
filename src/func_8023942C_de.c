#include "gfx.h"
#include "span_1000/code_802393F4.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"




extern Gfx *D_80110634;
extern s32 D_800D297C;

void func_8023942C_de(u32 arg0) {
    Gfx *cmd;
    u32 offset;

    offset = (D_800D297C << 6) + 0x448;
    gSPMatrix(D_80110634++, arg0 + offset, G_MTX_LOAD | G_MTX_PROJECTION);
}
