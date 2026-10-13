#include "span_1000/code_802591C0.h"
#include "types.h"

/* Moves nodes whose key differs from arg1 (or every node when arg1 is -1) from the active list to the tail of the list rooted at offset 0xD8. Adapted from func_80259988_de, with the match test inverted, a -1 wildcard added, and the tail insertion written as a do-while(0) list macro. */


void func_80259918_de(Owner_func_80259918_de *arg0, s32 arg1) {
    Node_func_80259918_de *node;
    Node_func_80259918_de *next;
    node = arg0->activeNext;
    while (node != (Node_func_80259918_de *) &arg0->activePrev) {
        next = node->next;
        if (arg1 == -1 || node->key != arg1) {
            node->prev->next = next;
            node->next->prev = node->prev;
            do { Node_func_80259918_de *tail_ = (arg0)->otherPrev; (node)->next = (Node_func_80259918_de *) &(arg0)->otherPrev; (node)->prev = tail_; (arg0)->otherPrev->next = (node); (arg0)->otherPrev = (node); } while (0);
        }
        node = next;
    }
}

/* Move nodes with the requested key from the active list to the other list. */
void func_80259988_de(void *arg0, s32 arg1)
{
    Owner_func_80259918_de *owner = arg0;
    Node_func_80259918_de *node = owner->activeNext;
    Node_func_80259918_de *head = (Node_func_80259918_de *)&owner->activePrev;
    Node_func_80259918_de *other = (Node_func_80259918_de *)&owner->otherPrev;

    if (node != head) {
        Node_func_80259918_de *sentinel = head;
        do {
            Node_func_80259918_de *next = node->next;
            if (node->key == arg1) {
                Node_func_80259918_de *tail;
                node->prev->next = next;
                node->next->prev = node->prev;
                tail = owner->otherPrev;
                node->next = other;
                node->prev = tail;
                owner->otherPrev->next = node;
                owner->otherPrev = node;
            }
            node = next;
        } while (node != sentinel);
    }
}

void func_802599EC_de(void *arg0, s32 arg1) {
    ListNode *node;
    ListNode *next;
    ListNode *sentinel;
    ListNode *loop_sentinel;
    ListNode *append_sentinel;
    ListNode *tail;

    node = (ListNode *)((Owner_func_80259918_de *)arg0)->activeNext;
    sentinel = (ListNode *)&((Owner_func_80259918_de *)arg0)->activePrev;
    append_sentinel = (ListNode *)&((Owner_func_80259918_de *)arg0)->otherPrev;
    if (node != sentinel) {
        loop_sentinel = sentinel;
        do {
            next = node->next;
            if (node->valueBC == arg1) {
                node->prev->next = next;
                node->next->prev = node->prev;
                tail = (ListNode *)((Owner_func_80259918_de *)arg0)->otherPrev;
                node->next = append_sentinel;
                node->prev = tail;
                ((ListNode *)((Owner_func_80259918_de *)arg0)->otherPrev)->next = node;
                ((Owner_func_80259918_de *)arg0)->otherPrev = (Node_func_80259918_de *)node;
            }
            node = next;
        } while (node != loop_sentinel);
    }
}

void func_80259A50_de(Lists *arg0, s32 arg1) {
    Node_func_80259A50_de *var_a2;
    Node_func_80259A50_de *temp_a3;
    Node_func_80259A50_de *temp_v0;
    Node_func_80259A50_de *temp_t0;
    Node_func_80259A50_de *temp_t1;

    var_a2 = arg0->first.next;
    temp_v0 = &arg0->first;
    if (var_a2 != temp_v0) {
        temp_t1 = &arg0->second;
        temp_t0 = temp_v0;
        do {
            temp_a3 = var_a2->next;
            if ((var_a2->flags & arg1) != 0) {
                Node_func_80259A50_de *temp_tail;

                var_a2->prev->next = temp_a3;
                var_a2->next->prev = var_a2->prev;
                temp_tail = arg0->second.prev;
                var_a2->next = temp_t1;
                var_a2->prev = temp_tail;
                arg0->second.prev->next = var_a2;
                arg0->second.prev = var_a2;
            }
            var_a2 = temp_a3;
        } while (var_a2 != temp_t0);
    }
}
