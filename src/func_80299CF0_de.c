#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80299DB4.h"
#include "types.h"





extern s32 D_8014D080;
extern s32 func_80299958_de(void);
extern s32 func_802995D4_de(s32, s32, s32, s32, s32);

void func_80299CF0_de(NodeRecAt12 *node, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 depth) {
    func_8029A73C_S1 *context;
    s32 saved;
    s32 valid;
    s32 *value;

    if (node != 0) {
        context = D_8014D080;
        saved = context->unk520;
        context->unk520 = 0;
        value = &context->unk520;
        if (node->left != 0) {
            func_80299CF0_de(node->left, arg1, arg2, arg3, arg4, depth + 1);
        }
        if (context->unk520 == 0) {
            if (node->right != 0) {
                func_80299CF0_de(node->right, arg1, arg2, arg3, arg4, depth + 1);
            }
            if ((context->unk520 == 0) && (depth > 0) && (node->value != -1) &&
                (node->type >= 9U)) {
                valid = 1;
                if (((arg1 == 0xE08) && ((node->flags | 2) == 0)) ||
                    ((arg1 == 0xE09) && ((node->flags | 4) == 0))) {
                    valid = 0;
                }
                if (valid != 0) {
                    func_80299958_de();
                    func_802995D4_de(node->value, arg1, arg2, arg3, arg4);
                }
            }
        }
        *value = saved;
    }
}
