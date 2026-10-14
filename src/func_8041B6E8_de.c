#include "span_16E000/code_8041B020.h"
#include "types.h"
/* Unless slot index is locked, hides the node shown in that slot, finds node id under the context root through func_8040EC30_de, shows it, and stores it in that slot or, in shared mode, in all four slots; then clears the slot's lock. */







extern void func_802995D4_de(s32 id, s32 command, s32 arg2, s32 arg3, s32 arg4);
extern Node_func_8041B6E8_de *func_8040EC30_de(void *root, s32 id);

void func_8041B6E8_de(OwnerRecAt8V1 *owner, s32 index, s32 id) {
    Context_func_8041B6E8_de *context;
    Node_func_8041B6E8_de *node;
    s32 i;

    context = owner->context;
    if (context->locked[index] == 0) {
        if (context->shown[index] != 0) {
            func_802995D4_de(context->shown[index]->id, 0x10, 0, 0, 0);
        }
        node = func_8040EC30_de(context->root, id & 0xFFFF);
        func_802995D4_de(node->id, 0xF, 0, 0, 0);
        if (context->shared == 0) {
            context->shown[index] = node;
        } else {
            for (i = 3; i >= 0; i--) {
                context->shown[i] = node;
            }
        }
    }
    context->locked[index] = 0;
}
