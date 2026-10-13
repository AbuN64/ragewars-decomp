#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802A6AC0.h"
#include "types.h"






void *func_802A6450_de(void *arg0, s32 arg1, s32 arg2) {
    State802A6DF8 *node;

    node = ((Owner802A6DF8 *)arg0)->lists.inactive.head;
    if (node != 0) {
        do {
            if ((s32)node->object == arg1) {
                if (node->contextId == arg2) {
                    return node;
                }
            }
            node = node->next;
        } while (node != 0);
    }
    return 0;
}
