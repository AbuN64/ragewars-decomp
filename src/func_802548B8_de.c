#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802536F4.h"
#include "types.h"



extern struct Shape_typemap_165 *func_802514A8_de(s32 arg0, u32 arg1);

extern void func_80254C70_de(s32 arg0, void *arg1);
extern void func_80254AD0_de(s32 arg0, void *arg1);

struct Shape_typemap_165 *func_802548B8_de(s32 arg0_unused, s32 arg1, u32 arg2) {
    struct Shape_typemap_165 *node;
    s32 result;

    node = func_802514A8_de(0, arg2);
    if (node != 0) {
        node->field_8++;
        node->field_C |= 0x100;
        result = ((s32 (*)(s32, s32, s32, u32))func_80254B8C_de)(0, arg1, (arg2 >> 5) & 1, arg2);
        node->field_0 = result;
        if (result != 0) {
            node->field_4 = arg1;
            node->field_C |= arg2;
            func_80254C70_de(0, node);
            return node;
        }
        node->field_8--;
        if (node->field_8 == 0) {
            node->field_C &= ~0x100;
        }
        func_80254AD0_de(0, node);
        node = 0;
    }
    return node;
}
