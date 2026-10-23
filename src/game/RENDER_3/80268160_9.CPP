#include "RENDER_3/RANGENODE.H"

int func_80268CBC_de(void *intrusiveList) {
    IntrusiveList *list = intrusiveList;
    return (int)list->head;
}

int func_80268CC8_de(void *unused0, void *rangeNode) {
    RangeNode *node = rangeNode;
    return (int)node->next;
}
