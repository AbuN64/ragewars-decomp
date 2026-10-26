#include "COMMON/LISTNODE.H"

int func_80259AB8_de(void *channelOwner, int wantedKey) {
    struct OwnerRecAtD8 *owner = channelOwner;
    struct Node_func_80259918_de *node = owner->activeNext;
    void *sentinel = &owner->activePrev;
    if (node != sentinel) {
        do {
            int value = node->key;
            node = node->next;
            if (value == wantedKey) {
                return 1;
            }
        } while (node != sentinel);
    }
    return 0;
}
