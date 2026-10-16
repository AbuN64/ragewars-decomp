#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80255BEC.h"
#include "TYPES.H"

/** Initialize a five-word record. */
void func_80255CA0_de(IntrusiveList *list, s32 prevOffset, s32 nextOffset) {
    list->prevOffset = prevOffset;
    list->nextOffset = nextOffset;
    list->tail = 0;
    list->head = 0;
    list->count = 0;
}

s32 func_80255CB8_de(void *arg0, s32 arg1) {
    IntrusiveList *list = arg0;
    s32 temp_v1;
    s32 temp_v0;

    temp_v1 = (s32)list->head;
    if (temp_v1 != 0) {
        *(s32 *)(arg1 + list->nextOffset) = temp_v1;
        *(s32 *)((s32)list->head + list->prevOffset) = arg1;
    } else {
        *(s32 *)(arg1 + list->nextOffset) = 0;
        list->tail = (void *)arg1;
    }
    *(s32 *)(arg1 + list->prevOffset) = 0;
    list->head = (void *)arg1;
    temp_v0 = list->count + 1;
    list->count = temp_v0;
    return temp_v0;
}
