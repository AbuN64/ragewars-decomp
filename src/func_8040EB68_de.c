#include "span_16E000/code_8040C780.h"
#include "types.h"

/* Returns whether any node in a linked list has bit 3 set in its flag halfword at offset 0x12. */


s32 func_8040EB68_de(struct Node_func_8040EB48_de *node) {
    u32 flags = 0;

    while (node != 0) {
        flags |= node->flags;
        node = node->next;
    }
    return (flags >> 3) & 1;
}
