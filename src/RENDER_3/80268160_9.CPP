#include "RENDER_3/RANGENODE.H"

int func_80268CBC_de(void *arg0) {
    IntrusiveList *list = arg0;
    return (int)list->head;
}

int func_80268CC8_de(void *arg0, void *arg1) {
    RangeNode *node = arg1;
    return (int)node->next;
}
