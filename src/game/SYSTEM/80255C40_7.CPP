#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "SYSTEM/80255C40_7.H"

s32 func_80255D14_de(IntrusiveList *list, void *node) {
    void **prevLink;
    void **tailLink;
    void **nextLink;
    void *tail;
    s32 count;

    tail = list->tail;
    if (tail != 0) {
        prevLink = node + list->prevOffset;
        *prevLink = tail;
        tailLink = list->tail + list->nextOffset;
        *tailLink = node;
    } else {
        prevLink = node + list->prevOffset;
        *prevLink = 0;
        list->head = node;
    }
    nextLink = node + list->nextOffset;
    *nextLink = 0;
    list->tail = node;
    count = list->count + 1;
    list->count = count;
    return count;
}

void func_80255D70_de(void *arg0, s32 arg1, s32 arg2) {
    char *o = (char *) arg0;
    s32 next = *(s32 *) (arg1 + ((IntrusiveList *)o)->prevOffset);
    s32 v0;

    if (next != 0) {
        s32 off8;
        *(s32 *) (next + ((IntrusiveList *)o)->nextOffset) = arg2;
        off8 = ((IntrusiveList *)o)->prevOffset;
        *(s32 *) (arg2 + off8) = *(s32 *) (arg1 + off8);
        *(s32 *) (arg1 + ((IntrusiveList *)o)->prevOffset) = arg2;
        *(s32 *) (arg2 + ((IntrusiveList *)o)->nextOffset) = arg1;
        v0 = ((IntrusiveList *)o)->count + 1;
    } else {
        s32 tail = ((IntrusiveList *)o)->head;
        if (tail != 0) {
            *(s32 *) (arg2 + ((IntrusiveList *)o)->nextOffset) = tail;
            *(s32 *) (((IntrusiveList *)o)->head + ((IntrusiveList *)o)->prevOffset) = arg2;
        } else {
            *(s32 *) (arg2 + ((IntrusiveList *)o)->nextOffset) = 0;
            ((IntrusiveList *)o)->tail = arg2;
        }
        *(s32 *) (arg2 + ((IntrusiveList *)o)->prevOffset) = 0;
        ((IntrusiveList *)o)->head = arg2;
        v0 = ((IntrusiveList *)o)->count + 1;
    }
    ((IntrusiveList *)o)->count = v0;
}

void func_80255E24_de(void *arg0, s32 arg1, s32 arg2) {
    char *o = (char *) arg0;
    s32 next = *(s32 *) (arg1 + ((IntrusiveList *)o)->nextOffset);
    s32 v0;

    if (next != 0) {
        s32 offC;
        *(s32 *) (next + ((IntrusiveList *)o)->prevOffset) = arg2;
        offC = ((IntrusiveList *)o)->nextOffset;
        *(s32 *) (arg2 + offC) = *(s32 *) (arg1 + offC);
        *(s32 *) (arg1 + ((IntrusiveList *)o)->nextOffset) = arg2;
        *(s32 *) (arg2 + ((IntrusiveList *)o)->prevOffset) = arg1;
        v0 = ((IntrusiveList *)o)->count + 1;
    } else {
        s32 head = ((IntrusiveList *)o)->tail;
        if (head != 0) {
            *(s32 *) (arg2 + ((IntrusiveList *)o)->prevOffset) = head;
            *(s32 *) (((IntrusiveList *)o)->tail + ((IntrusiveList *)o)->nextOffset) = arg2;
        } else {
            *(s32 *) (arg2 + ((IntrusiveList *)o)->prevOffset) = 0;
            ((IntrusiveList *)o)->head = arg2;
        }
        *(s32 *) (arg2 + ((IntrusiveList *)o)->nextOffset) = 0;
        ((IntrusiveList *)o)->tail = arg2;
        v0 = ((IntrusiveList *)o)->count + 1;
    }
    ((IntrusiveList *)o)->count = v0;
}

void func_80255ED8_de(void *list, void *node) {
    IntrusiveList *owner = list;
    char *next;
    char *prev;
    next = *(char **)((char *)node + owner->prevOffset);
    if (next != 0) {
        s32 off = owner->nextOffset;
        *(char **)(next + off) = *(char **)((char *)node + off);
    }
    prev = *(char **)((char *)node + owner->nextOffset);
    if (prev != 0) {
        s32 off = owner->prevOffset;
        *(char **)(prev + off) = *(char **)((char *)node + off);
    }
    if (owner->head == node) {
        owner->head = *(void **)((char *)node + owner->nextOffset);
    }
    if (owner->tail == node) {
        owner->tail = *(void **)((char *)node + owner->prevOffset);
    }
    owner->count = owner->count - 1;
}

/** Advance the cursor by its stride and decrement its remaining count. */
void func_80255F70_de(IntrusiveList *arg0) {
    char *cursor = arg0->head;
    int stride = arg0->nextOffset;
    int value = *(int *)(cursor + stride);
    int count = arg0->count - 1;
    arg0->count = count;
    arg0->head = value;
}

/** Advance the cursor by its stride and decrement its remaining count. */
void func_80255F94_de(IntrusiveList *arg0) {
    char *cursor = arg0->tail;
    int stride = arg0->prevOffset;
    int value = *(int *)(cursor + stride);
    int count = arg0->count - 1;
    arg0->count = count;
    arg0->tail = value;
}

void func_80255FB8_de(void *arg0, s32 arg1) {
    char *o = (char *)arg0;
    s32 next;
    s32 prev;
    s32 head;

    next = *(s32 *)(arg1 + ((IntrusiveList *)o)->prevOffset);
    if (next != 0) {
        s32 off = ((IntrusiveList *)o)->nextOffset;
        *(s32 *)(next + off) = *(s32 *)(arg1 + off);
    }
    prev = *(s32 *)(arg1 + ((IntrusiveList *)o)->nextOffset);
    if (prev != 0) {
        s32 off = ((IntrusiveList *)o)->prevOffset;
        *(s32 *)(prev + off) = *(s32 *)(arg1 + off);
    }
    if (((IntrusiveList *)o)->head == arg1) {
        ((IntrusiveList *)o)->head = *(s32 *)(arg1 + ((IntrusiveList *)o)->nextOffset);
    }
    if (((IntrusiveList *)o)->tail == arg1) {
        ((IntrusiveList *)o)->tail = *(s32 *)(arg1 + ((IntrusiveList *)o)->prevOffset);
    }
    ((IntrusiveList *)o)->count = ((IntrusiveList *)o)->count - 1;

    head = ((IntrusiveList *)o)->head;
    if (head != 0) {
        *(s32 *)(arg1 + ((IntrusiveList *)o)->nextOffset) = head;
        *(s32 *)(((IntrusiveList *)o)->head + ((IntrusiveList *)o)->prevOffset) = arg1;
    } else {
        *(s32 *)(arg1 + ((IntrusiveList *)o)->nextOffset) = 0;
        ((IntrusiveList *)o)->tail = arg1;
    }
    *(s32 *)(arg1 + ((IntrusiveList *)o)->prevOffset) = 0;
    ((IntrusiveList *)o)->head = arg1;
    ((IntrusiveList *)o)->count = ((IntrusiveList *)o)->count + 1;
}

void func_802560A4_de(void *arg0, s32 arg1) {
    char *o = (char *)arg0;
    s32 next;
    s32 prev;
    s32 tail;

    next = *(s32 *)(arg1 + ((IntrusiveList *)o)->prevOffset);
    if (next != 0) {
        s32 off = ((IntrusiveList *)o)->nextOffset;
        *(s32 *)(next + off) = *(s32 *)(arg1 + off);
    }
    prev = *(s32 *)(arg1 + ((IntrusiveList *)o)->nextOffset);
    if (prev != 0) {
        s32 off = ((IntrusiveList *)o)->prevOffset;
        *(s32 *)(prev + off) = *(s32 *)(arg1 + off);
    }
    if (((IntrusiveList *)o)->head == arg1) {
        ((IntrusiveList *)o)->head = *(s32 *)(arg1 + ((IntrusiveList *)o)->nextOffset);
    }
    if (((IntrusiveList *)o)->tail == arg1) {
        ((IntrusiveList *)o)->tail = *(s32 *)(arg1 + ((IntrusiveList *)o)->prevOffset);
    }
    ((IntrusiveList *)o)->count = ((IntrusiveList *)o)->count - 1;

    tail = ((IntrusiveList *)o)->tail;
    if (tail != 0) {
        *(s32 *)(arg1 + ((IntrusiveList *)o)->prevOffset) = tail;
        *(s32 *)(((IntrusiveList *)o)->tail + ((IntrusiveList *)o)->nextOffset) = arg1;
    } else {
        *(s32 *)(arg1 + ((IntrusiveList *)o)->prevOffset) = 0;
        ((IntrusiveList *)o)->head = arg1;
    }
    *(s32 *)(arg1 + ((IntrusiveList *)o)->nextOffset) = 0;
    ((IntrusiveList *)o)->tail = arg1;
    ((IntrusiveList *)o)->count = ((IntrusiveList *)o)->count + 1;
}

extern s32 func_802744D4_de(void);




void *func_80256190_de(void *intrusiveList) {
    s32 index;
    s32 offset;
    void *node;

    node = ((IntrusiveList *)intrusiveList)->head;
    if (node == 0) {
        return 0;
    }
    index = func_802744D4_de() % (u32)((IntrusiveList *)intrusiveList)->count;
    index--;
    if (index != -1) {
        offset = ((IntrusiveList *)intrusiveList)->nextOffset;
        do {
            { u8 *cursor = (u8 *)node; cursor += offset; node = *(void **)cursor; }
            index--;
        } while (index != -1);
    }
    return node;
}

void func_80256214_de(IntrusiveList *arg0) {
    s32 node = arg0->head;
    if (node != 0) {
        s32 offset = arg0->nextOffset;
        node = *(s32 *)(node + offset);
        while (node != 0) {
            node = *(s32 *)(node + offset);
        }
    }
}

int func_8025623C_de(IntrusiveList *arg0, int arg1) {
    int node = arg0->head;
    if (node != 0) {
        do {
            if (node == arg1) {
                return 1;
            }
            node = *(int *)(node + arg0->nextOffset);
        } while (node != 0);
    }
    return 0;
}
