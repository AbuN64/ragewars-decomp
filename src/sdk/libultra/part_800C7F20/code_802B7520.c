#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT18V1.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"
#include "sdk/al_globals.h"

void func_802B2450_de(ListLink *node) {
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev != 0) {
        node->prev->next = node->next;
    }
}

void func_802B2480_de(void *node, void **previousNode) {
    void *temp;

    temp = *previousNode;
    ((Field_void_4 *)(node))->value = previousNode;
    *(void **)node = temp;
    temp = *previousNode;
    if (temp != 0) {
        ((Field_void_4 *)(temp))->value = node;
    }
    *previousNode = node;
}

extern void func_802B3770_de(void);

void func_802B24A0_de(void *audioGlobals) {
    void **p;

    p = (void **)&D_800D4070;
    if (*p == 0) {
        *p = audioGlobals;
        func_802B3770_de();
    }
}


void func_802B24D0_de(s32 *audioGlobals) {
    void **p;

    p = (void **)&D_800D4070;
    if (*p != 0) {
        func_802B31F0_de(audioGlobals);
        *p = 0;
    }
}
