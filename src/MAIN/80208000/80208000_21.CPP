#include "shared/gameplay_reaction_rules.h"
#include "shared/gameplay_transition.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8020D370.h"
#include "TYPES.H"
#include "span_1000/code_80208000.h"
#include "span_C76B0/data.h"

extern f32 func_80209B64_de(void *arg0);

extern s32 D_801468A0;












s32 func_8020EA10_de(void **arg0) {
    char *base;
    f32 temp_f20;

    base = (char *)&D_801468A0;
    if (((Shared_MatchRules *)base)->squads == 0) {
        return 0;
    }
    if (((Shared_ActorView *)*arg0)->controls->transientFlag != 0) {
        return 0;
    }
    if (func_8022A83C_de(base - 0x1860) != 0) {
        return 0;
    }
    temp_f20 = func_80209B64_de(arg0) * D_800C1E50_de + D_800C1E54_de;
    if (temp_f20 < func_80274A90_de(0.0f, D_800C1E58_de)) {
        return 1;
    }
    return 0;
}
