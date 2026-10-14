#include "span_1000/code_8028FC98.h"




extern ListNode80290528 *D_80131140;
extern ListNode80290528 *D_80131144;
extern ListNode80290528 *D_80131148;

/** Unlink an active node and return it to the global free list. */
void func_80290548_de(ListNode80290528 *node) {
    ListNode80290528 *oldHead;

    if (node->flags & 1) {
        node->flags &= ~1;
        if (node->reference_count != 0) {
            (*node->reference_count)--;
        }
        if (node->previous != 0) {
            node->previous->next = node->next;
        }
        if (node->next != 0) {
            node->next->previous = node->previous;
        }
        if (D_80131144 == node) {
            D_80131144 = node->next;
        }
        if (D_80131148 == node) {
            D_80131148 = node->previous;
        }
        oldHead = D_80131140;
        node->previous = 0;
        *(ListNode80290528 *volatile *) &node->next = oldHead;
        D_80131140 = node;
    }
}
