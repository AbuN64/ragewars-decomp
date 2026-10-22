#include "include_asm.h"

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/NODERECAT1C.H"
#include "COMMON/CTX.H"

void __osEnqueueThread(ThreadNode **queue, ThreadNode *node) {
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
#else
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/NODERECAT1C.H"
#include "COMMON/CTX.H"

ThreadNode *__osPopThread(ThreadNode **queue) {
    ThreadNode *node;
    ThreadNode *next;

    node = *queue;
    next = node->next;
    node->next = 0;
    *queue = next;
    return node;
}
#else
#endif
