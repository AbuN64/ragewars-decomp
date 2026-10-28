#include "sdk/libgultra.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/BUF16B.H"
#include "sdk/libgultra/alunlink.h"
#include "include_asm.h"

extern s32 func_802BD170_de(s32);

                  /* osSetIntMask */


            /* alUnlink */


void alEvtqNew(void *eventQueue, void *eventStorage, s32 eventCapacity) {
    ALEventQueue *queue = eventQueue;
    s32 i;
    char *p;

    i = 0;
    queue->eventCount = 0;
    queue->allocList.next = 0;
    queue->allocList.prev = 0;
    queue->freeList.next = 0;
    queue->freeList.prev = 0;
    if (eventCapacity > 0) {
        p = (char *)eventStorage;
        do {
            alLink(p, eventQueue);
            i += 1;
            p += 0x1C;
        } while (i < eventCapacity);
    }
}

s32 alEvtqNextEvent(void *eventQueue, s16 *outputEvent) {
    void *node;
    s32 saved;
    s32 result;

    saved = func_802BD170_de(1);
    node = ((ALEventQueue *)eventQueue)->allocList.next;
    if (node != 0) {
        alUnlink(node);
        ((void (*)(void *, void *, s32))alCopy)(&((ALEventListItem *)node)->evt, outputEvent, 0x10);
        alLink(node, eventQueue);
        result = ((ALEventListItem *)node)->delta;
    } else {
        *outputEvent = -1;
        result = 0;
    }
    func_802BD170_de(saved);
    return result;
}

  /* alLink */
 /* alCopy */

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, s32 delta)
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

    alUnlink((ListLink *)item);
    ((void (*)(void *, void *, s32))alCopy)(evt, &item->evt, sizeof(*evt));

    if (delta == 0x7FFFFFFF)
        postAtEnd = -1;

    for (node = &evtq->allocList; node != 0; node = node->next) {
        if (!node->next) {
            if (postAtEnd)
                item->delta = 0;
            else
                item->delta = delta;
            alLink((ListLink *)item, node);
            break;
        } else {
            nextItem = (ALEventListItem *)node->next;

            if (delta < nextItem->delta) {
                item->delta = delta;
                nextItem->delta -= delta;

                alLink((ListLink *)item, node);
                break;
            }

            delta -= nextItem->delta;
        }
    }

    func_802BD170_de(mask);
}

void alEvtqFlush(void *arg0) {
    ALEventQueue *queue = arg0;
    NodeGskyActivateMessagePool *cur;
    NodeGskyActivateMessagePool *next;
    s32 saved;

    saved = func_802BD170_de(1);
    cur = queue->allocList.next;
    if (cur != 0) {
        do {
            next = cur->next;
            alUnlink((ListLink *)cur);
            alLink(cur, arg0);
            cur = next;
        } while (cur != 0);
    }
    func_802BD170_de(saved);
}


void alEvtqFlushType(void *arg0, s16 arg1) {
    s32 saved;
    char *cur;
    char *next;

    saved = func_802BD170_de(1);
    cur = ((ALEventQueue *)arg0)->allocList.next;
    if (cur != 0) {
        do {
            next = ((ALEventListItem *)cur)->node.next;
            if (((ALEventListItem *)cur)->evt.type == arg1) {
                if (next != 0) {
                    ((ALEventListItem *)next)->delta = ((ALEventListItem *)next)->delta + ((ALEventListItem *)cur)->delta;
                }
                alUnlink((ListLink *)cur);
                alLink(cur, arg0);
            }
            cur = next;
        } while (cur != 0);
    }
    func_802BD170_de(saved);
}

#if defined(VERSION_US)
char rodata_unresolved_802B0238[8] =
    "izeBrigh";
#endif
