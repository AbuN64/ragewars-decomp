#include "AI/SOURCE.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/SELF.H"
#include "AI/NAV/80212C90_10.H"

void func_802131E0_de(Root802131E0 *arg0) {
    Target802131E0 *inner;

    inner = arg0->unk1D8->unk1454;
    inner->unk220 = 0;
    Nav_ResetBehaviorState(inner);
    inner->unk320 = -1;
    inner->unk2FC = 0;
}

extern void Nav_SetBehaviourState(void *arg0, s32 arg1);
extern void func_80211020_de(void *arg0);
extern f32 Nav_DistanceToNode(void *arg0, s32 arg1);
extern void Nav_SteerAlongRoute(void *);
extern void Nav_UpdatePlayerSteering(void *arg0);












void func_8021321C_de(Root802131E0 *arg0)
{
    void *state;
    s32 random;
    s32 actor_state;
    u32 flags;

    state = arg0->unk1D8->unk1454;
    if (((Shared_ControlView *)((Brain_func_80212D78_eu_x *)state)->player->controls)->transientFlag == 0) {
        Nav_SetBehaviourState(state, 2);
        return;
    }

    func_80211020_de(state);
    if (--((Brain_func_80212D78_eu_x *)state)->jumpTimer == 0) {
        actor_state = ((Brain_func_80212D78_eu_x *)state)->player->action;
        flags = ((Brain_func_80212D78_eu_x *)state)->player->unk_0x0038;
        actor_state ^= 15;
        flags = (flags & 0x3000) != 0;
        if (actor_state != 0 && !flags) {
            ((Brain_func_80212D78_eu_x *)state)->player->unk_0x06B0 |= 0x10;
        }
    }

    if (((Brain_func_80212D78_eu_x *)state)->jumpTimer < 0) {
        random = Nav_NextRandom();
        ((Brain_func_80212D78_eu_x *)state)->jumpTimer = ((random % 5) + 3) * 15;
    }

    if (Nav_DistanceToNode(state, ((Brain_func_80212D78_eu_x *)state)->nextNode) < D_800C20F0_de) {
        ((Brain_func_80212D78_eu_x *)state)->player->unk_0x06B0 |= 0x10;
    }
    Nav_SteerAlongRoute(state);
    Nav_UpdatePlayerSteering(state);
}
