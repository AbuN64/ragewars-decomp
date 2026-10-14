#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8020AF9C.h"
#include "types.h"

extern void func_8020C5A0_de(void *arg0, void *node);






/** Find a keyed node in the object's list and pass it to func_8020C5A0_de. */
void func_8020D0CC_de(void *arg0, s32 key) {
    NavigationSearchNode *node = ((NavigationGraph *)arg0)->nodes;

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
