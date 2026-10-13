#include "types.h"
#include "gfx.h"
#include "gbi.h"
#include "span_16E000/code_8043E9A8.h"
#include "span_16E000/menu_ui_providers.h"
#include "span_1000/code_80291054.h"
void func_802A9234_de(s32 color);
s32 func_802AAC28_de(s32 resource, s32 mode, s16 x, s16 y, f32 scaleX, f32 scaleY, s32 flags);

void func_8043EE5C_de(struct Item_func_8043F048_de *item, MenuOptionBox *box, s32 unused, struct Holder_func_8043F048_de *context) {
    struct ItemDef *def = item->def;
    s32 type = def->type;
    s32 index = def->index;
    struct Player_func_8043F048_de *player = context->player;
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
        func_802A9234_de((s32)(context->fade * (context->alpha * D_800E23A0[0])));
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
