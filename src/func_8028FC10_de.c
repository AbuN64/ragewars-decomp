#include "span_1000/code_802BB15C.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028DF6C.h"
#include "types.h"



extern void func_802BB5F0_de(void *arg0, s32 arg1);





extern s32 D_800CD704;

extern s32 D_80106248;




void func_8028FC10_de(void *arg0) {
    Node_func_8028FC10_de *node = 0;
    s32 value1 = 0;
    s32 value2 = 0;
    s32 flags;

    while (func_802BB2A0_de(&((View_func_8028FA60_de *)arg0)->messages, &node, 0) != -1) {
        if (node->type == 1 && (node->flags & 0x20) && D_800CD704 == 0) {
            D_800CD704 = 2;
            func_802BB5F0_de(&D_80106248, D_800CD8B8_de);
        }
        func_8028F954_de(arg0, node);
    }

    if (((View_func_8028FA60_de *)arg0)->pending != 0 &&
        ((View_func_8028FA60_de *)arg0)->current != 0) {
        func_8028FBD8_de(arg0);
        return;
    }

    flags = (((View_func_8028FA60_de *)arg0)->current == 0) * 2 |
            (((View_func_8028FA60_de *)arg0)->next == 0);
    if (((s32 (*)(void *, s32 *, s32 *, s32))func_8028F544_de)(arg0, &value1, &value2, flags) != flags) {
        ((void (*)(void *, s32, s32))func_8028FA60_de)(arg0, value1, value2);
    }
}
