#include "shared/gameplay_transition.h"
#include "span_1000/code_8022AE90.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"

extern GlobalState D_801468A0;








void *func_8022A420_de(void *arg0) {
    GlobalState *base = &D_801468A0;
    Shared_ActorView *record;

    if (base->restricted != 0 && base->restrictionActive != 0) {
        return 0;
    }
    record = (void *)((struct Context *)arg0)->head;
    if (record != 0) {
        do {
            if (record->controls->transientFlag == 1) {
                return record;
            }
            record = record->next;
        } while (record != 0);
    }
    return 0;
}
