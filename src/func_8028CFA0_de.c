#include "span_1000/code_8021CD70.h"
#include "shared/world.h"
#include "span_1000/code_80277444.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);






void *func_8028CFA0_de(void *arg0, s32 arg1, s32 arg2) {
    s32 *descriptor;
    s32 count;
    s32 i;
    ActorDefinitionHeader *entry;

    descriptor = ((Shared_World *)arg0)->actorDefinitions;
    count = *descriptor;
    for (i = 0; i < count; i++) {
        entry = func_8028FDB4_de(((Shared_World *)arg0)->actorDefinitions, i);
        if (arg1 != -1 && entry->kind != arg1) {
            continue;
        }
        if (arg2 == -1) {
            return entry;
        }
        if (entry->character != arg2) {
            continue;
        }
        return entry;
    }
    return 0;
}
