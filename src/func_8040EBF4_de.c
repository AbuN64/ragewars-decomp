#include "span_16E000/code_8040C780.h"
#include "types.h"

/* Sums the halfword positions at offsets 0x14 and 0x16 along a linked list starting at a node and
   reports the totals through the two pointers. */


void func_8040EBF4_de(struct NodeRecAt16 *node, s32 *x, s32 *y) {
    s32 sumX = node->x;
    s32 sumY = node->y;

    while (node->next != 0) {
        node = node->next;
        sumX += node->x;
        sumY += node->y;
    }
    *x = sumX;
    *y = sumY;
}
