#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AFEAC.h"
#include "types.h"

extern s32 func_802BD170_de(s32);
extern void func_802B2450_de(void *arg0);
extern void func_802B2480_de(void *arg0, void *arg1);








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
                func_802B2450_de(cur);
                func_802B2480_de(cur, arg0);
            }
            cur = next;
        } while (cur != 0);
    }
    func_802BD170_de(saved);
}
