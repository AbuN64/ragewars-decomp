#include "COMMON/GAMEPLAY_REACTION_RULES.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ACTORREC.H"
#include "TYPES.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "AI/NAV/80208000_24.H"
#include "include_asm.h"

extern f32 Scaled_GetScaledAggression(void *arg0);

extern s32 D_801468A0;

s32 Nav_ShouldSeekUnclaimedTeamMarker(void **controller) {
    char *base;
    f32 temp_f20;

    base = (char *)&D_801468A0;
    if (((Shared_MatchRules *)base)->squads == 0) {
        return 0;
    }
    if (((Shared_ActorView *)*controller)->controls->transientFlag != 0) {
        return 0;
    }
    if (Playerai_FindPlayerWithMarker(base - 0x1860) != 0) {
        return 0;
    }
    temp_f20 = Scaled_GetScaledAggression(controller) * D_800C1E50_de + D_800C1E54_de;
    if (temp_f20 < GraphU64_RandomBetween(0.0f, D_800C1E58_de)) {
        return 1;
    }
    return 0;
}

s32 Nav_ShouldSeekUnclaimedTeamMarker(void **controller);
s32 Nav_EvaluateCaptureFlagMarkerSearch(void **controller) {
    if (D_801462C8.counters.m_bCTFOn != 0) {
        Nav_ShouldSeekUnclaimedTeamMarker(controller);
    }
    return 1;
}

/* ROM-grounded data: src/rw_pool_8020EA10_C7B40_us_rev1.c */
const unsigned int D_blob_e2105c22ed856e4916b8[3] = {
    0x3F19999A, 0x3E4CCCCD, 0x3F800000,
};

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C1D8C[1] = {
    0x4353776F,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C213C[1] = {
    0x0022EC68,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C1E5C[1] = {
    0x0020ED00,
};
#endif
