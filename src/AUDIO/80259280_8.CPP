#include "COMMON/LISTNODE.H"

int func_80259AB8_de(void *arg0, int arg1) {
    struct OwnerRecAtD8 *owner = arg0;
    struct Node_func_80259918_de *node = owner->activeNext;
    void *sentinel = &owner->activePrev;
    if (node != sentinel) {
        do {
            int value = node->key;
            node = node->next;
            if (value == arg1) {
                return 1;
            }
        } while (node != sentinel);
    }
    return 0;
}
