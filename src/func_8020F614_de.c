#include "shared/navigation_graph.h"
#include "shared/level_actor.h"
#include "common/unused.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8020EAE0.h"
#include "types.h"

extern void *func_8020C994_de(void *, s32);
extern void func_8020D220_de(void *, s32);
extern s32 D_8013B364;










s32 func_8020F614_de(void) {
    s32 *base;
    NavigationSearchNode *node;
    void *result;
    s32 count;

    base = &D_8013B364;
    node = ((NavigationGraph *)base)->nodes;
    count = 0;
    if (node != 0) {
        do {
            result = func_8020C994_de(base, node->key);
            if ((((NavigationNode *)result)->flags & 1) &&
                ((NavigationNode *)result)->reservedE == 0x64E &&
                (s8)((LevelActor *)node->object)->pad1A4 == 0) {
                func_8020D220_de(base, node->key);
                count += 1;
            }
            node = node->next;
        } while (node != 0);
    }
    return count;
}
