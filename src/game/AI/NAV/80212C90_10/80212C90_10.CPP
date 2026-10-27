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
#include "include_asm.h"

/* 80212C90_10.CPP */
void Nav_InitTimedJumpRoute(Root802131E0 *arg0) {
    Target802131E0 *inner;

    inner = arg0->unk1D8->unk1454;
    inner->unk220 = 0;
    Nav_ResetBehaviorState(inner);
    inner->unk320 = -1;
    inner->unk2FC = 0;
}

extern void Nav_SetBehaviourState(void *arg0, s32 arg1);
extern void Nav_RunBehaviorHandler(void *arg0);
extern f32 Nav_DistanceToNode(void *arg0, s32 arg1);
extern void Nav_SteerAlongRoute(void *);
extern void Nav_UpdatePlayerSteering(void *arg0);

void Nav_UpdateTransientJumpRoute(Root802131E0 *arg0)
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

    Nav_RunBehaviorHandler(state);
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
        random = GraphU64_NextRandom();
        ((Brain_func_80212D78_eu_x *)state)->jumpTimer = ((random % 5) + 3) * 15;
    }

    if (Nav_DistanceToNode(state, ((Brain_func_80212D78_eu_x *)state)->nextNode) < D_800C20F0_de) {
        ((Brain_func_80212D78_eu_x *)state)->player->unk_0x06B0 |= 0x10;
    }
    Nav_SteerAlongRoute(state);
    Nav_UpdatePlayerSteering(state);
}

/* 800C6E84_21.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
const unsigned int D_8021321C_C7DE0[1] = {
    0x42CCCCCC,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C23D4[3] = {
    0x00000000, 0x41F00000, 0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C2394[3] = {
    0x216BFFFF, 0x40021000, 0x04010002,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C20F4[3] = {
    0x43000000, 0x41F00000, 0x00000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8021321C_C7DE0_us_rev1.c */
const unsigned int D_blob_191e35959cee9de3e658[1] = {
    0x42CCCCCC,
};
#endif
