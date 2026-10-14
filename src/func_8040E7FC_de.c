#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040C780.h"
#include "types.h"





extern void func_8040DB04_de(Node_func_8040E7FC_de *, NodeEvent);

/* Walks a sibling node list and dispatches the by-value event to every node whose flag bit 3 is set. */
void func_8040E7FC_de(Node_func_8040E7FC_de *node, NodeEvent event) {
    for (; node != 0; node = node->next) {
        if (node->flags & 8) {
            func_8040DB04_de(node, event);
        }
    }
}
