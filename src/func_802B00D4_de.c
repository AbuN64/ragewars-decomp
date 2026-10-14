#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AFEAC.h"
#include "types.h"
/* alEvtqPostEvent, drafted from ultralib src/audio/event.c: take an item from the free list, copy
   the event into it and link it into the allocated list at its delta time, adjusting the delta of
   the item it is inserted before; AL_EVTQ_END posts at the end with no delta. */









extern s32 func_802BD170_de(s32);                  /* osSetIntMask */
extern void func_802B2450_de(Link_func_802596B4_de *);            /* alUnlink */
extern void func_802B2480_de(Link_func_802596B4_de *, Link_func_802596B4_de *);  /* alLink */
 /* alCopy */

void func_802B00D4_de(ALEventQueue *evtq, Message_func_802AF150_de *evt, s32 delta)
{
    ALEventListItem *item;
    ALEventListItem *nextItem;
    Link_func_802596B4_de *node;
    s32 postAtEnd = 0;
    s32 mask;

    mask = func_802BD170_de(1);

    item = (ALEventListItem *)evtq->freeList.next;
    if (!item) {
        func_802BD170_de(mask);
        return;
    }

    func_802B2450_de((Link_func_802596B4_de *)item);
    ((void (*)(void *, void *, s32))func_802B0310_de)(evt, &item->evt, sizeof(*evt));

    if (delta == 0x7FFFFFFF)
        postAtEnd = -1;

    for (node = &evtq->allocList; node != 0; node = node->next) {
        if (!node->next) {
            if (postAtEnd)
                item->delta = 0;
            else
                item->delta = delta;
            func_802B2480_de((Link_func_802596B4_de *)item, node);
            break;
        } else {
            nextItem = (ALEventListItem *)node->next;

            if (delta < nextItem->delta) {
                item->delta = delta;
                nextItem->delta -= delta;

                func_802B2480_de((Link_func_802596B4_de *)item, node);
                break;
            }

            delta -= nextItem->delta;
        }
    }

    func_802BD170_de(mask);
}
