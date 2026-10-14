#include "span_16E000/code_8041B020.h"
#include "types.h"
/* Unless slot index is locked, hides the node in that slot and shows the given node through func_8040E928_de, storing it in that slot or, in shared mode, in all four slots. */





extern void func_8040E928_de(Node_func_8041B6E8_de *node, s32 visible);

void func_8041B8DC_de(Context_func_8041B6E8_de *context, s32 index, Node_func_8041B6E8_de *node) {
    s32 i;

    if (context->locked[index] == 0) {
        if (context->shown[index] != 0) {
            func_8040E928_de(context->shown[index], 0);
        }
        func_8040E928_de(node, 1);
        if (context->shared == 0) {
            context->shown[index] = node;
        } else {
            for (i = 3; i >= 0; i--) {
                context->shown[i] = node;
            }
        }
    }
}
