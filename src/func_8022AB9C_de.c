#include "common/types_8fd754e1e915.h"
#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022A274.h"
#include "types.h"

extern void *D_800D052C[];
extern s16 D_800CB348_de[];






s32 func_8022AB9C_de(void *arg0) {
    s16 *var_v0;
    s32 temp_v1;
    WeaponInfo *temp_v0;

    temp_v0 = D_800D052C[((Shared_ActorView *)arg0)->selectedAction];
    if (((Player *)arg0)->gear == 1) {
        var_v0 = temp_v0->weaponClass;
    } else {
        var_v0 = temp_v0->alternateClass;
    }
    if (var_v0 != 0) {
        temp_v1 = *var_v0;
    } else {
        temp_v1 = -1;
    }
    if (temp_v1 != -1) {
        return D_800CB348_de[temp_v1];
    }
    return -1;
}
