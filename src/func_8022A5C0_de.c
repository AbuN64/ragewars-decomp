#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"
#include "shared/gameplay_transition.h"
#include "span_1000/code_80225D10.h"






void *func_8022A5C0_de(char *object, s32 arg1) {
    Round *round = (Round *)object;
    Shared_ActorView *record = (Shared_ActorView *)round->players;
    if (record != 0) {
        do {
            if ((s32)record->controller == arg1) {
                return record;
            }
            record = record->next;
        } while (record != 0);
    }
    return 0;
}
