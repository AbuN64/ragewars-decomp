#include "shared/navigation_graph.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8020EAE0.h"
#include "types.h"

extern void *func_8020C994_de(void *, s32);


extern s32 D_8013B364;









void func_8020EEA4_de(void) {
    NavigationGraph *base;
    NavigationSearchNode *node;
    NavigationPoint *result;
    f32 addVal;
    u16 field0E;

    base = (NavigationGraph *)&D_8013B364;
    node = base->nodes;
    if (node != 0) {
        addVal = D_800C1EE4_de;
        do {
            result = func_8020C994_de(base, node->key);
            if (result->flags & 1) {
                field0E = result->objectId;
                if (func_8020F55C_de(field0E) != 0 || func_8020F57C_de(result->objectId) != 0) {
                    node->extra = node->extra + addVal;
                }
            }
            node = node->next;
        } while (node != 0);
    }
}
