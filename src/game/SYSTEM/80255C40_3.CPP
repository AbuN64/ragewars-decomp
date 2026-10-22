#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "SYSTEM/80255C40_3.H"

/** Initialize a five-word record. */
void func_80255CA0_de(IntrusiveList *list, s32 prevOffset, s32 nextOffset) {
    list->prevOffset = prevOffset;
    list->nextOffset = nextOffset;
    list->tail = 0;
    list->head = 0;
    list->count = 0;
}

void func_80255CB8_de(void *list, void *node) {
    IntrusiveList *owner = list;
    char *head;
    head = owner->head;
    if (head != 0) {
        *(char **)((char *)node + owner->nextOffset) = head;
        *(void **)((char *)owner->head + owner->prevOffset) = node;
    } else {
        *(void **)((char *)node + owner->nextOffset) = 0;
        owner->tail = node;
    }
    *(void **)((char *)node + owner->prevOffset) = 0;
    owner->head = node;
    owner->count = owner->count + 1;
}
