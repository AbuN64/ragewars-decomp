#include "sdk/libgultra.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/BUF16B.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"

extern s32 func_802BD170_de(s32);

                  /* osSetIntMask */


            /* alUnlink */


void func_802AFFC0_de(void *arg0, void *arg1, s32 arg2) {
    ALEventQueue *queue = arg0;
    s32 i;
    char *p;

    i = 0;
    queue->eventCount = 0;
    queue->allocList.next = 0;
    queue->allocList.prev = 0;
    queue->freeList.next = 0;
    queue->freeList.prev = 0;
    if (arg2 > 0) {
        p = (char *)arg1;
        do {
            func_802B2480_de(p, arg0);
            i += 1;
            p += 0x1C;
        } while (i < arg2);
    }
}

s32 func_802B003C_de(void *arg0, s16 *arg1) {
    void *node;
    s32 saved;
    s32 result;

    saved = func_802BD170_de(1);
    node = ((ALEventQueue *)arg0)->allocList.next;
    if (node != 0) {
        func_802B2450_de(node);
        ((void (*)(void *, void *, s32))alCopy)(&((ALEventListItem *)node)->evt, arg1, 0x10);
        func_802B2480_de(node, arg0);
        result = ((ALEventListItem *)node)->delta;
    } else {
        *arg1 = -1;
        result = 0;
    }
    func_802BD170_de(saved);
    return result;
}

  /* alLink */
 /* alCopy */

void func_802B00D4_de(ALEventQueue *evtq, ALEvent *evt, s32 delta)
{
    ALEventListItem *item;
    ALEventListItem *nextItem;
    ListLink *node;
    s32 postAtEnd = 0;
    s32 mask;

    mask = func_802BD170_de(1);

    item = (ALEventListItem *)evtq->freeList.next;
    if (!item) {
        func_802BD170_de(mask);
        return;
    }

    func_802B2450_de((ListLink *)item);
    ((void (*)(void *, void *, s32))alCopy)(evt, &item->evt, sizeof(*evt));

    if (delta == 0x7FFFFFFF)
        postAtEnd = -1;

    for (node = &evtq->allocList; node != 0; node = node->next) {
        if (!node->next) {
            if (postAtEnd)
                item->delta = 0;
            else
                item->delta = delta;
            func_802B2480_de((ListLink *)item, node);
            break;
        } else {
            nextItem = (ALEventListItem *)node->next;

            if (delta < nextItem->delta) {
                item->delta = delta;
                nextItem->delta -= delta;

                func_802B2480_de((ListLink *)item, node);
                break;
            }

            delta -= nextItem->delta;
        }
    }

    func_802BD170_de(mask);
}

void alEvtqFlush(void *arg0) {
    ALEventQueue *queue = arg0;
    Node_func_80239AF4_de *cur;
    Node_func_80239AF4_de *next;
    s32 saved;

    saved = func_802BD170_de(1);
    cur = queue->allocList.next;
    if (cur != 0) {
        do {
            next = cur->next;
            func_802B2450_de((ListLink *)cur);
            func_802B2480_de(cur, arg0);
            cur = next;
        } while (cur != 0);
    }
    func_802BD170_de(saved);
}
