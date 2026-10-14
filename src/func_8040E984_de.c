#include "span_1000/code_80297CD0.h"
#include "span_16E000/code_8040C780.h"
#include "types.h"
/* Hit-tests a widget tree at point (px, py): unless a hit is already recorded it searches the
   node's later siblings first, then offsets the origin by the node's position and searches its
   children, and finally records the node itself when it has an id, its rectangle contains the
   point and func_802997E4_de accepts its selector. */








void func_8040E984_de(WidgetRecAt1A **hit, WidgetRecAt1A *node, DrawArgs_func_8040E67C_de args, s32 px, s32 py) {
    if (*hit != 0) {
        return;
    }
    if (node->next != 0) {
        func_8040E984_de(hit, node->next, args, px, py);
    }
    if (*hit != 0) {
        return;
    }
    args.x += node->x;
    args.y += node->y;
    if (node->child != 0) {
        func_8040E984_de(hit, node->child, args, px, py);
    }
    if (*hit != 0) {
        return;
    }
    if (node->id == -1) {
        return;
    }
    if (px < args.x || args.x + node->width < px || py < args.y ||
        args.y + node->height < py) {
        return;
    }
    if (func_802997E4_de(node->selector) != 0) {
        *hit = node;
    }
}
