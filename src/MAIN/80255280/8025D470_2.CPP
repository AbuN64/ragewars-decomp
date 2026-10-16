#include "MAIN/80255280.H"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_802AE028.h"
#include "span_C76B0/data.h"
#include "TYPES.H"

s32 func_802B0340_de(s32 a, s32 b, void *c, s32 d, s32 e);
void func_802AEAB0_de(void *arg0, InitParams *arg1);

void func_8025D844_de(struct AudioStateD844 *state, struct AudioRootD844 *root) {
    struct AudioParamsD844 params;
    void *player;
    state->root = root;
    state->mode = 16;
    state->index = -1;
    state->flags = 0;
    params.count38 = 20;
    params.count1C = 192;
    params.kind = 20;
    params.context = &state->root->heap;
    params.value10 = 0;
    params.value14 = 0;
    params.value18 = 0;
    player = func_802B0340_de(0, 0, &state->root->heap, 1, 0x7C);
    state->player = player;
    func_802AEAB0_de(player, &params);
    state->allocation = func_802B0340_de(0, 0, &state->root->heap, 1, 0xF8);
    state->timer = 50;
    state->counter = 0;
    state->first = D_800C3FF8_de;
    state->second = D_800C3FFC_de;
    state->third = D_800C3FF8_de;
    state->fourth = D_800C3FF8_de;
}
