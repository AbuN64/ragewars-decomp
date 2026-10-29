#include "../../include/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT18V1.H"
#include "TYPES.H"
#include "../../include/libgultra/alunlink.h"
#include "../../include/al_globals.h"

void alUnlink(ListLink *node) {
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev != 0) {
        node->prev->next = node->next;
    }
}

void alLink(void *node, void **previousNode) {
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

extern void alSynNew(void);

void alInit(void *audioGlobals) {
    void **p;

    p = (void **)&g_audioGlobals;
    if (*p == 0) {
        *p = audioGlobals;
        alSynNew();
    }
}


void alClose(s32 *audioGlobals) {
    void **p;

    p = (void **)&g_audioGlobals;
    if (*p != 0) {
        alSynDelete(audioGlobals);
        *p = 0;
    }
}
