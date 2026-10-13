#include "shared/gameplay_transition.h"
#include "span_1000/code_8022AE90.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"






s32 func_8022A8F0_de(void *arg0) {
    Shared_ActorView *record = (void *)((struct Context *)arg0)->head;
    s32 count = 0;
    if (record != 0) {
        do {
            if (record->actionEnabled != 0 && record->remote == 0) {
                count += 1;
            }
            record = record->next;
        } while (record != 0);
    }
    return count;
}
