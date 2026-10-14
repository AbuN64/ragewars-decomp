#include "span_1000/code_8022AE90.h"
#include "shared/gameplay_transition.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"







/** Find the first linked record whose nested flags include either type marker. */
void *func_8022A83C_de(char *object) {
    Shared_ActorView *record = (void *)((struct Context *)object)->head;
    while (record != 0) {
        Shared_ControlView *nested = record->controls;
        if (nested->transientFlag == 1 ||
            (u8)nested->resetFlag == 1) {
            return record;
        }
        record = record->next;
    }
    return record;
}
