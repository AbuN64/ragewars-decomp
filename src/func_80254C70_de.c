#include "span_1000/code_80255BEC.h"
#include "types.h"
#include "common/unused.h"
#include "shared/heap_sorted_list.h"
#include "types.h"

extern void func_80255D70_de(void *, s32, s32);

void func_80254C70_de(s32 unused, void *object) {
    Node80254C10 *node = object;
    Node80254C10 *scan;

    scan = D_80100584.head;
    while (scan != 0) {
        if (scan->start > node->start) {
            func_80255D70_de(&D_80100584, (s32)scan, (s32)node);
            break;
        }
        scan = scan->next;
    }
    if (scan == 0) {
        func_80255D14_de(&D_80100584, node);
    }
    node->flags |= 0x1000;
}
