#include "include_asm.h"
#include "sdk/libgultra.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/BUF16B.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"

extern s32 func_802BD170_de(s32);

void func_802B0258_de(void *arg0, s16 arg1) {
    s32 saved;
    char *cur;
    char *next;

    saved = func_802BD170_de(1);
    cur = ((ALEventQueue *)arg0)->allocList.next;
    if (cur != 0) {
        do {
            next = ((ALEventListItem *)cur)->node.next;
            if (((ALEventListItem *)cur)->evt.type == arg1) {
                if (next != 0) {
                    ((ALEventListItem *)next)->delta = ((ALEventListItem *)next)->delta + ((ALEventListItem *)cur)->delta;
                }
                func_802B2450_de((ListLink *)cur);
                func_802B2480_de(cur, arg0);
            }
            cur = next;
        } while (cur != 0);
    }
    func_802BD170_de(saved);
}

#if defined(VERSION_US)
char rodata_unresolved_802B0238[8] =
    "izeBrigh";
#endif
