#include "span_1000/code_8022AE90.h"
#include "shared/gameplay_transition.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"

extern void func_80285D30_de(s32 *);






void func_8022A880_de(void *object) {
    Shared_ActorView *record = (void *)((struct Context *)object)->head;
    if (record != 0) {
        do {
            func_80285D30_de((char *)record->controller + 0x140);
            ((struct IntegerStateD4 *)record->controller)->unk_D0 = 0;
            record = record->next;
        } while (record != 0);
    }
}
