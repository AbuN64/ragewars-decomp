#include "COMMON/EXTERNS.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "AUDIO_2/8025D470.H"
#include "COMMON/STATERECAT34.H"
#include "COMMON/OBJECTSTATE10_2.H"
#include "COMMON/TRIPLE.H"
#include "AUDIO_2/8025D470_2.H"

s32 func_802B0340_de(s32 a, s32 b, void *c, s32 d, s32 e);

void func_802AEAB0_de(void *arg0, InitParams *arg1);

extern void func_802AFF90_de(s32 arg0);

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

void func_8025D928_de(void *queue) {
    ObjectState40 *o = queue;
    f32 temp_f1;
    f32 targetGain;
    f32 var_f0;
    s32 temp_f3;

    if (o->flags & 2) {
        func_802AFF60_de(o->unk_14, (s16)o->volume);
        temp_f3 = (s32) ((f32) o->volume - o->fadeStep);
        o->volume = temp_f3;
        if (temp_f3 <= 0) {
            o->volume = 0;
            func_802AFF90_de(o->unk_14);
            o->flags |= 4;
        }
    } else if (o->unk_38 != 0) {
        temp_f1 = o->unk_3C;
        targetGain = o->targetGain;
        if (targetGain < temp_f1) {
            var_f0 = temp_f1 - D_800C4000_de;
            if (targetGain <= var_f0) {
                goto store;
            }
            goto clamp;
        }
        if (temp_f1 < targetGain) {
            var_f0 = temp_f1 + (0.01666666753590107f);
            if (var_f0 <= targetGain) {
                goto store;
            }
clamp:
            var_f0 = targetGain;
store:
            o->unk_3C = var_f0;
        }
    }
}
