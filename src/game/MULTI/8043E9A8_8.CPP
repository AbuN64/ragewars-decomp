#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"
#include "COMMON/PLAYERRECAT64E.H"
#include "MULTI/8043E9A8.H"
#include "COMMON/MENU_UI_PROVIDERS.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/EXTERNS_6.H"
#include "GFX/TEXT/802A8A94_5.H"

#if (!(defined(VERSION_US) || defined(VERSION_US_REV1))) && !defined(NON_MATCHING)
INCLUDE_ASM("ovl_80400000", func_8043EE5C_de);
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1) || defined(NON_MATCHING)
/* Fuzzy draft: the other versions' body, not diffed against this version's asm. */

void func_8043EE5C_de(struct ItemRecAt18V2 *item, MenuOptionBox *box, s32 unused, struct Holder_func_8043F048_de *context) {
    struct ItemDef *def = item->def;
    s32 type = def->type;
    s32 index = def->index;
    struct PlayerRecAt64E *player = context->player;
    s32 available = 0;
    switch (type) {
    case 0x10FE:
        if (index >= 0) {
            if (index < 3) goto low;
            if (index < 6) goto high;
            break;
        low:
            available = index < player->count64D;
            break;
        high:
            available = index - 3;
            available = available < player->count64E;
        }
        break;
    case 0x1194:
        available = player->flags[index] != 0;
        break;
    }
    if (D_800E1E20 != 5) {
        D_800E1E20 = 5;
        Text_SetupSpriteMode((s32)(context->fade * (context->alpha * D_800E23A0[0])));
    }
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
    if (available) {
        gDPSetEnvColor(D_80110634++, 255, 255, 255, (s32)(context->fade * (context->alpha * D_800E23A0[1])));
    } else {
        gDPSetEnvColor(D_80110634++, 50, 50, 50, (s32)(context->fade * (context->alpha * D_800E23A8)));
    }
    func_802AAC28_de(item->resource, 0, box->left, box->top, box->scaleX, box->scaleY, 1);
}
#endif
