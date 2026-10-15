#include "span_1000/code_80212C90.h"
#include "shared/func_802131E0_de_closed.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "types.h"
#include "common/unused.h"
#include "span_1000/code_8022C894.h"
#include "shared/gameplay_transition.h"
#include "span_1000/code_802106E0.h"

void func_802131E0_de(Root802131E0 *arg0) {
    Target802131E0 *inner;

    inner = arg0->unk1D8->unk1454;
    inner->unk220 = 0;
    func_80209988_de(inner);
    inner->unk320 = -1;
    inner->unk2FC = 0;
}

extern void func_80209874_de(void *arg0, s32 arg1);
extern void func_80211020_de(void *arg0);
extern f32 func_80209948_de(void *arg0, s32 arg1);
extern void func_80208410_de(void *);
extern void func_80208AAC_de(void *arg0);












void func_8021321C_de(void *arg0)
{
    void *state;
    s32 random;
    s32 actor_state;
    u32 flags;

    state = ((Root802131E0 *)arg0)->unk1D8->unk1454;
    if (((Shared_ControlView *)((Brain_func_80212D78_eu_x *)state)->player->unk_0x05D8)->transientFlag == 0) {
        func_80209874_de(state, 2);
        return;
    }

    func_80211020_de(state);
    if (--((Brain_func_80212D78_eu_x *)state)->jumpTimer == 0) {
        actor_state = ((Brain_func_80212D78_eu_x *)state)->player->unk_0x0650;
        flags = ((Brain_func_80212D78_eu_x *)state)->player->unk_0x0038;
        actor_state ^= 15;
        flags = (flags & 0x3000) != 0;
        if (actor_state != 0 && !flags) {
            ((Brain_func_80212D78_eu_x *)state)->player->unk_0x06B0 |= 0x10;
        }
    }

    if (((Brain_func_80212D78_eu_x *)state)->jumpTimer < 0) {
        random = func_802744D4_de();
        ((Brain_func_80212D78_eu_x *)state)->jumpTimer = ((random % 5) + 3) * 15;
    }

    if (func_80209948_de(state, ((Brain_func_80212D78_eu_x *)state)->nextNode) < D_800C20F0_de) {
        ((Brain_func_80212D78_eu_x *)state)->player->unk_0x06B0 |= 0x10;
    }
    func_80208410_de(state);
    func_80208AAC_de(state);
}
