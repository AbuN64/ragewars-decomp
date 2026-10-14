#include "span_1000/code_8022AE90.h"
#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"






void *func_8022A5F4_de(void *arg0, u32 arg1) {
    Shared_ActorView *var_v1;
    s32 var_a2;

    var_v1 = 0;
    var_a2 = 0;
    if (arg1 < 8U) {
        var_v1 = ((struct Context *)arg0)->head;
        if (var_v1 != 0) {
            do {
                if (var_a2 == (s32)arg1) {
                    return var_v1;
                }
                var_v1 = var_v1->next;
                var_a2 += 1;
            } while (var_v1 != 0);
        }
    }
    return var_v1;
}
