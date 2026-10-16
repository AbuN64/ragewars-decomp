#include "span_1000/code_802591C0.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "types.h"

extern void func_8025B6F8_de(Header *header, s32 owner, s32 arg2);

static inline void func_802596D4_linkInit(ListLink *link) {
    link->prev = link;
    link->next = link;
}

static inline void func_802596D4_insertAfter(ListLink *at, ListLink *link) {
    link->next = at->next;
    link->prev = at;
    at->next->prev = link;
    at->next = link;
}

static inline void func_802596D4_voiceInit(VoiceRecAt8 *voice, s32 owner) {
    func_802596D4_linkInit(&voice->link);
    func_8025B6F8_de(&voice->header, owner, -1);
}

/* Starts a copy of a sound table entry when that entry is idle: takes the first node of the free list at
 * 0xD8, copies the 0xCC-byte entry into it, sets its owner value and position, clears its timer and
 * inserts it into the active list at 0x4 ahead of the first node with lower priority; the scene's
 * current selection fields are then reset. */













extern void *func_802BD3A0_de(void *destination, const void *source, int count);

/* Initialises a channel set: records the owner, sets up its free and active lists with headers, and appends 32 initialised voices to the active list. */
void func_802596B4_de(ChannelSet *set, s32 owner) {
    s32 i;

    set->owner = owner;
    func_802596D4_linkInit(&set->free);
    func_8025B6F8_de(&set->freeHeader, owner, -1);
    func_802596D4_linkInit(&set->active);
    func_8025B6F8_de(&set->activeHeader, owner, -1);
    for (i = 0; i < 32; i++) {
        func_802596D4_voiceInit(&set->voices[i], owner);
        func_802596D4_insertAfter(set->active.prev, &set->voices[i].link);
    }
}

void func_80259784_de(ManagerRecAtD8V2 *manager, s32 index, s32 owner, Vec3 *position) {
    Entry_func_80259784_de *entry;
    NodeRecAt4C *node;
    NodeRecAt4C *at;
    NodeRecAt4C *first;
    s32 priority;

    entry = &manager->scene->entries[index];
    if (entry->busy != 0) {
        return;
    }
    first = manager->free.next;
    if (first != (NodeRecAt4C *)&manager->free) {
        first->prev->next = first->next;
        first->next->prev = first->prev;
        node = first;
        func_802BD3A0_de(node->pad8, entry, 0xCC);
        node->owner = owner;
        node->position.x = position->x;
        node->position.y = position->y;
        node->position.z = position->z;
        node->timer = 0;
        at = manager->active.next;
        priority = node->priority;
        while (at != (NodeRecAt4C *)&manager->active) {
            if (at->priority < priority) {
                break;
            }
            at = at->next;
        }
        node->prev = at->prev;
        node->next = at;
        at->prev->next = node;
        at->prev = node;
    }
    manager->scene->activeSelection = 0;
    manager->scene->pendingSelection = -1;
    manager->scene->previousSelection = -1;
    manager->scene->selection = -1;
}

void func_802598B4_de(ChannelSet *arg0, s32 arg1) {
    Node_func_802598B4_de *node;
    Node_func_802598B4_de *next;
    Node_func_802598B4_de *end;
    Node_func_802598B4_de *initial_end;
    Node_func_802598B4_de *tail_end;

    node = (Node_func_802598B4_de *)arg0->free.prev;
    tail_end = (Node_func_802598B4_de *)&arg0->active;
    initial_end = (Node_func_802598B4_de *)&arg0->free;
    if (node != initial_end) {
        end = initial_end;
        do {
            next = node->next;
            if (node->value == arg1) {
                node->prev->next = next;
                node->next->prev = node->prev;
                node->prev = (Node_func_802598B4_de *)arg0->active.next;
                node->next = tail_end;
                ((Node_func_802598B4_de *)arg0->active.next)->next = node;
                arg0->active.next = (ListLink *)node;
            }
            node = next;
        } while (node != end);
    }
}

/* Moves nodes whose key differs from arg1 (or every node when arg1 is -1) from the active list to the tail of the list rooted at offset 0xD8. Adapted from func_80259988_de, with the match test inverted, a -1 wildcard added, and the tail insertion written as a do-while(0) list macro. */


void func_80259918_de(OwnerRecAtD8 *arg0, s32 arg1) {
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
    OwnerRecAtD8 *owner = arg0;
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

void func_802599EC_de(OwnerRecAtD8 *arg0, s32 arg1) {
    ListNode *node;
    ListNode *next;
    ListNode *sentinel;
    ListNode *loop_sentinel;
    ListNode *append_sentinel;
    ListNode *tail;

    node = (ListNode *)arg0->activeNext;
    sentinel = (ListNode *)&arg0->activePrev;
    append_sentinel = (ListNode *)&arg0->otherPrev;
    if (node != sentinel) {
        loop_sentinel = sentinel;
        do {
            next = node->next;
            if (node->valueBC == arg1) {
                node->prev->next = next;
                node->next->prev = node->prev;
                tail = (ListNode *)arg0->otherPrev;
                node->next = append_sentinel;
                node->prev = tail;
                ((ListNode *)arg0->otherPrev)->next = node;
                arg0->otherPrev = (Node_func_80259918_de *)node;
            }
            node = next;
        } while (node != loop_sentinel);
    }
}

void func_80259A50_de(Lists *arg0, s32 arg1) {
    NodeRecAtAC *var_a2;
    NodeRecAtAC *temp_a3;
    NodeRecAtAC *temp_v0;
    NodeRecAtAC *temp_t0;
    NodeRecAtAC *temp_t1;

    var_a2 = arg0->first.next;
    temp_v0 = &arg0->first;
    if (var_a2 != temp_v0) {
        temp_t1 = &arg0->second;
        temp_t0 = temp_v0;
        do {
            temp_a3 = var_a2->next;
            if ((var_a2->flags & arg1) != 0) {
                NodeRecAtAC *temp_tail;

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
