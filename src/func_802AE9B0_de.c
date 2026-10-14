#include "span_1000/code_802AE028.h"
#include "types.h"



s32 func_802AE9B0_de(ValueSet *set, u32 *result) {
    u32 amount;
    u32 minimum;
    u32 i;

    amount = set->amount;
    minimum = -1;
    if (set->mask == 0) {
        return 0;
    }

    for (i = 0; i < 16; i++) {
        if ((set->mask >> i) & 1) {
            if (set->active != 0) {
                set->values[i] -= amount;
            }
            if (set->values[i] < minimum) {
                minimum = set->values[i];
            }
        }
    }

    set->active = 0;
    *result = minimum;
    return 1;
}
