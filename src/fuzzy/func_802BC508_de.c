#include "types.h"
#include "span_1000/code_802BB67C.h"
#include "span_1000/code_802BBC68.h"

void func_802BC508_de(ThreadNode **queue, ThreadNode *node) {
    ThreadNode **link = queue;
    ThreadNode *current = *queue;
    s32 priority = node->priority;

    if (current->priority >= priority) {
        do {
            link = &current->next;
            current = current->next;
        } while (current->priority >= priority);
    }

    current = *link;
    *link = node;
    node->next = current;
    node->queue = queue;
}
