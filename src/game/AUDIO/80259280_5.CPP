#include "COMMON/LISTNODE.H"
#include "AUDIO/80259280.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "AUDIO/80259280_5.H"

extern void Audio_InitializeVoiceRecord(Header *header, s32 owner, s32 arg2);

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
    Audio_InitializeVoiceRecord(&voice->header, owner, -1);
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
    Audio_InitializeVoiceRecord(&set->freeHeader, owner, -1);
    func_802596D4_linkInit(&set->active);
    Audio_InitializeVoiceRecord(&set->activeHeader, owner, -1);
    for (i = 0; i < 32; i++) {
        func_802596D4_voiceInit(&set->voices[i], owner);
        func_802596D4_insertAfter(set->active.prev, &set->voices[i].link);
    }
}

void Audio_StartSpatialVoice(ManagerRecAtD8V2 *manager, s32 index, s32 owner, CVector3 *position) {
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

void func_802598B4_de(ChannelSet *channelSet, s32 soundId) {
    Node_func_802598B4_de *node;
    Node_func_802598B4_de *next;
    Node_func_802598B4_de *end;
    Node_func_802598B4_de *initial_end;
    Node_func_802598B4_de *tail_end;

    node = (Node_func_802598B4_de *)channelSet->free.prev;
    tail_end = (Node_func_802598B4_de *)&channelSet->active;
    initial_end = (Node_func_802598B4_de *)&channelSet->free;
    if (node != initial_end) {
        end = initial_end;
        do {
            next = node->next;
            if (node->value == soundId) {
                node->prev->next = next;
                node->next->prev = node->prev;
                node->prev = (Node_func_802598B4_de *)channelSet->active.next;
                node->next = tail_end;
                ((Node_func_802598B4_de *)channelSet->active.next)->next = node;
                channelSet->active.next = (ListLink *)node;
            }
            node = next;
        } while (node != end);
    }
}

/* Moves nodes whose key differs from arg1 (or every node when arg1 is -1) from the active list to the tail of the list rooted at offset 0xD8. Adapted from func_80259988_de, with the match test inverted, a -1 wildcard added, and the tail insertion written as a do-while(0) list macro. */


void func_80259918_de(OwnerRecAtD8 *channelOwner, s32 retainedKey) {
    Node_func_80259918_de *node;
    Node_func_80259918_de *next;
    node = channelOwner->activeNext;
    while (node != (Node_func_80259918_de *) &channelOwner->activePrev) {
        next = node->next;
        if (retainedKey == -1 || node->key != retainedKey) {
            node->prev->next = next;
            node->next->prev = node->prev;
            do { Node_func_80259918_de *tail_ = (channelOwner)->otherPrev; (node)->next = (Node_func_80259918_de *) &(channelOwner)->otherPrev; (node)->prev = tail_; (channelOwner)->otherPrev->next = (node); (channelOwner)->otherPrev = (node); } while (0);
        }
        node = next;
    }
}

/* Move nodes with the requested key from the active list to the other list. */
void func_80259988_de(void *channelOwner, s32 matchingKey)
{
    OwnerRecAtD8 *owner = channelOwner;
    Node_func_80259918_de *node = owner->activeNext;
    Node_func_80259918_de *head = (Node_func_80259918_de *)&owner->activePrev;
    Node_func_80259918_de *other = (Node_func_80259918_de *)&owner->otherPrev;

    if (node != head) {
        Node_func_80259918_de *sentinel = head;
        do {
            Node_func_80259918_de *next = node->next;
            if (node->key == matchingKey) {
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

void func_802599EC_de(OwnerRecAtD8 *listNode, s32 matchingValue) {
    ListNode *node;
    ListNode *next;
    ListNode *sentinel;
    ListNode *loop_sentinel;
    ListNode *append_sentinel;
    ListNode *tail;

    node = (ListNode *)listNode->activeNext;
    sentinel = (ListNode *)&listNode->activePrev;
    append_sentinel = (ListNode *)&listNode->otherPrev;
    if (node != sentinel) {
        loop_sentinel = sentinel;
        do {
            next = node->next;
            if (node->valueBC == matchingValue) {
                node->prev->next = next;
                node->next->prev = node->prev;
                tail = (ListNode *)listNode->otherPrev;
                node->next = append_sentinel;
                node->prev = tail;
                ((ListNode *)listNode->otherPrev)->next = node;
                listNode->otherPrev = (Node_func_80259918_de *)node;
            }
            node = next;
        } while (node != loop_sentinel);
    }
}

void func_80259A50_de(Lists *lists, s32 matchingFlags) {
    NodeRecAtAC *channelCursor;
    NodeRecAtAC *next;
    NodeRecAtAC *sourceSentinel;
    NodeRecAtAC *iterationSentinel;
    NodeRecAtAC *destinationSentinel;

    channelCursor = lists->first.next;
    sourceSentinel = &lists->first;
    if (channelCursor != sourceSentinel) {
        destinationSentinel = &lists->second;
        iterationSentinel = sourceSentinel;
        do {
            next = channelCursor->next;
            if ((channelCursor->flags & matchingFlags) != 0) {
                NodeRecAtAC *prev;

                channelCursor->prev->next = next;
                channelCursor->next->prev = channelCursor->prev;
                prev = lists->second.prev;
                channelCursor->next = destinationSentinel;
                channelCursor->prev = prev;
                lists->second.prev->next = channelCursor;
                lists->second.prev = channelCursor;
            }
            channelCursor = next;
        } while (channelCursor != iterationSentinel);
    }
}
