#include "common/data.h"
/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "common/unused.h"
#include "shared/heap_sorted_list.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"





extern void func_80255B2C_de(void *, s32);
extern s32 func_80255920_de(void *, s32);
extern void func_80265378_de(u32, u32, s32);
extern void func_80255ED8_de(void *, s32);

extern void func_80255D70_de(void *, s32, s32);

extern s32 D_80100568[];
extern s32 D_801051A0[3];





void func_802515F0_de(s32 unused, s32 arg1) {
    IntrusiveList queue;
    Node80254C10 *node;
    Node80254C10 *next;
    Node80254C10 *scan;
    u32 split;
    s32 *arena_end;
    s32 *arena;
    s32 *pool;

    func_80255CA0_de(&queue, 0x20, 0x24);
    if (arg1 != 0 || D_80100568[0] == 0) {
        D_80100568[0] = D_80100568[7];
        if (D_80100568[7] == 0) {
            goto drain;
        }
    }

    pool = D_80100568;
    arena_end = &D_801051A0[2];
    arena = arena_end - 2;
    do {
        node = (Node80254C10 *)pool[0];
        pool[0] = *(s32 *)&node->next;
        if (!(*(s32 *)&node->flags & 0x701) && (u32)(*arena_end + 0x20) < node->start) {
            func_80255B2C_de(arena, node->start);
            split = func_80255920_de(arena, node->end);
            if (split < node->start) {
                func_80265378_de(split, node->start, node->end);
                node->start = split;
                func_80255ED8_de(&pool[7], (s32)node);
                func_80255D14_de(&queue, node);
            }
            if (arg1 == 0) {
                break;
            }
        }
    } while (D_80100568[0] != 0);

drain:
    node = queue.head;
    while (node != 0) {
        next = node->next;
        func_80255F70_de(&queue);
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
        node = next;
    }
}

