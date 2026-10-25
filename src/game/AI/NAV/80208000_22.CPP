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

extern f32 func_80209B64_de(void *arg0);

extern s32 D_801468A0;












s32 func_8020EA10_de(void **controller) {
    char *base;
    f32 temp_f20;

    base = (char *)&D_801468A0;
    if (((Shared_MatchRules *)base)->squads == 0) {
        return 0;
    }
    if (((Shared_ActorView *)*controller)->controls->transientFlag != 0) {
        return 0;
    }
    if (func_8022A83C_de(base - 0x1860) != 0) {
        return 0;
    }
    temp_f20 = func_80209B64_de(controller) * D_800C1E50_de + D_800C1E54_de;
    if (temp_f20 < Nav_RandomBetween(0.0f, D_800C1E58_de)) {
        return 1;
    }
    return 0;
}
