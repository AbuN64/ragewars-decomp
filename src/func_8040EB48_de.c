#include "span_16E000/code_8040C780.h"
#include "types.h"

/* Returns the union of the flag halfwords at offset 0x12 of every node in a linked list. */


s32 func_8040EB48_de(struct Node_func_8040EB48_de *node) {
    s32 flags = 0;

    while (node != 0) {
        flags |= node->flags;
        node = node->next;
    }
    return flags;
}
