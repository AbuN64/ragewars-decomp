#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/NAVIGATION_GRAPH.H"
#include "AI/ROUTE_RELATION_GRID.H"
#include "COMMON/OBJECTLINKS14.H"
#include "TYPES.H"

extern void func_8020D014_de(void *arg0);

extern void func_8020D1FC_de(s32);

extern void func_8020D220_de(void *, s32);

extern void func_8020D0CC_de(void *arg0, s32 arg1);

extern void func_8020C5A0_de(void *arg0, void *node);

void func_8020D070_de(void *arg0, s32 arg1, s32 arg2) {
    func_8020D014_de(arg0);
    func_8020D1FC_de((s32) arg0);
    func_8020D220_de(arg0, arg2);
    func_8020D0CC_de(arg0, arg1);
}

/** Find a keyed node in the object's list and pass it to func_8020C5A0_de. */
void func_8020D0CC_de(void *arg0, s32 key) {
    NavigationSearchNode *node = ((CNavData *)arg0)->nodes;

    if (node == 0) {
        goto not_found;
    }
loop:
    if (node->key == key) {
        goto found;
    }
    node = node->next;
    if (node != 0) {
        goto loop;
    }
not_found:
    node = 0;
found:
    func_8020C5A0_de(arg0, node);
}

void func_8020D114_de(char *owner, s32 *output, s32 count) {
    s32 i;
    s32 done;
    s32 value;
    NavigationSearchNode *node;

    for (i = 0; i < count; i++) {
        output[i] = -1;
    }

    node = ((CNavData *)owner)->nodes;
    value = ((CNavData *)owner)->result;
    done = 0;
    if (node == 0) {
        goto not_found;
    }
    do {
        if (node->key == value) {
            owner = (char *)node;
            goto found;
        }
        node = node->next;
    } while (node != 0);
not_found:
    owner = 0;
found:
    if (((NavigationSearchNode *)owner)->parent == 0) {
        output[0] = ((NavigationSearchNode *)owner)->key;
        return;
    }

    while (done == 0) {
        for (i = count - 1; i > 0; i--) {
            output[i] = output[i - 1];
        }
        output[0] = ((NavigationSearchNode *)owner)->key;
        owner = (char *)((NavigationSearchNode *)owner)->parent;
        if (((NavigationSearchNode *)owner)->parent == 0) {
            done = 1;
        }
    }
}

s32 func_8020D1CC_de(void *arg0, s32 arg1, s32 arg2) {
    ObjectLinks14 *table = arg0;
    RouteRelationBytes *bytes = (RouteRelationBytes *)table->unk_10;
    s32 index = (arg1 * table->unk_4 + arg2) * bytes->stride;
    return *(index + bytes->entries);
}

void func_8020D1FC_de(s32 arg0) {
    CNavData *graph = (CNavData *)arg0;
    s32 i;
    s32 value = -1;
    for (i = 63; i >= 0; i--) {
        graph->m_nGoalList[i] = value;
    }
}
