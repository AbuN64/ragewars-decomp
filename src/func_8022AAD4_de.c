#include "common/types_8fd754e1e915.h"
#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022A274.h"
#include "types.h"

extern void *D_800D052C[];






s16 func_8022AAD4_de(void *arg0, s32 arg1) {
    s16 *var_v0;
    WeaponInfo *temp_a0;

    temp_a0 = D_800D052C[arg1];
    if (((Player *)arg0)->gear == 1) {
        var_v0 = temp_a0->weaponClass;
    } else {
        var_v0 = temp_a0->alternateClass;
    }
    if (var_v0 != 0) {
        return *var_v0;
    }
    return -1;
}
