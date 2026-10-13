#include "span_1000/code_802591C0.h"





int func_80259AB8_de(void *arg0, int arg1) {
    struct Owner_func_80259918_de *owner = arg0;
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
