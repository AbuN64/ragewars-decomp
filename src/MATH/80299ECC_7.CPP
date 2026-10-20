#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CALLBACK.H"
#include "MATH/80299ECC.H"

extern s32 func_80299958_de(void);


void func_80299CF0_de(NodeRecAt12 *node, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 depth) {
    ScreenManager *context;
    s32 saved;
    s32 valid;
    s32 *value;

    if (node != 0) {
        context = D_8014D080;
        saved = context->handled;
        context->handled = 0;
        value = &context->handled;
        if (node->left != 0) {
            func_80299CF0_de(node->left, arg1, arg2, arg3, arg4, depth + 1);
        }
        if (context->handled == 0) {
            if (node->right != 0) {
                func_80299CF0_de(node->right, arg1, arg2, arg3, arg4, depth + 1);
            }
            if ((context->handled == 0) && (depth > 0) && (node->value != -1) &&
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
