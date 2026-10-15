#include "span_1000/code_80268160.h"

int func_80268CBC_de(void *arg0) {
    IntrusiveList *list = arg0;
    return (int)list->head;
}

int func_80268CC8_de(void *arg0, void *arg1) {
    RangeNode *node = arg1;
    return (int)node->next;
}
