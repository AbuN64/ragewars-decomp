#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AFEAC.h"
#include "types.h"

extern s32 func_802BD170_de(s32);
extern void func_802B2450_de(void *arg0);

extern void func_802B2480_de(void *arg0, void *arg1);






s32 func_802B003C_de(void *arg0, s16 *arg1) {
    void *node;
    s32 saved;
    s32 result;

    saved = func_802BD170_de(1);
    node = ((ALEventQueue *)arg0)->allocList.next;
    if (node != 0) {
        func_802B2450_de(node);
        ((void (*)(void *, void *, s32))func_802B0310_de)(&((ALEventListItem *)node)->evt, arg1, 0x10);
        func_802B2480_de(node, arg0);
        result = ((ALEventListItem *)node)->delta;
    } else {
        *arg1 = -1;
        result = 0;
    }
    func_802BD170_de(saved);
    return result;
}
