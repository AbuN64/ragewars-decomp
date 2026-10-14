#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AFEAC.h"
#include "types.h"

extern void func_802B2480_de(void *, void * *);




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
