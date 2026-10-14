#include "shared/navigation_graph.h"
#include "span_1000/code_8020AF9C.h"
#include "types.h"








void func_8020D114_de(char *owner, s32 *output, s32 count) {
    s32 i;
    s32 done;
    s32 value;
    NavigationSearchNode *node;

    for (i = 0; i < count; i++) {
        output[i] = -1;
    }

    node = ((NavigationGraph *)owner)->nodes;
    value = ((NavigationGraph *)owner)->result;
    done = 0;
    if (node == 0) {
        goto not_found;
    }
    do {
        if (node->key == value) {
            owner = (char *)node;
            goto found;
        }
        node = node->next;
    } while (node != 0);
not_found:
    owner = 0;
found:
    if (((NavigationSearchNode *)owner)->parent == 0) {
        output[0] = ((NavigationSearchNode *)owner)->key;
        return;
    }

    while (done == 0) {
        for (i = count - 1; i > 0; i--) {
            output[i] = output[i - 1];
        }
        output[0] = ((NavigationSearchNode *)owner)->key;
        owner = (char *)((NavigationSearchNode *)owner)->parent;
        if (((NavigationSearchNode *)owner)->parent == 0) {
            done = 1;
        }
    }
}
