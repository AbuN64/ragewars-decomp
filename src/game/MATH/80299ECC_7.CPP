#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CALLBACK.H"
#include "MATH/80299ECC.H"
#include "include_asm.h"

void Smos_DispatchDescendantScreenEvent(NodeRecAt12 *node, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
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
            Smos_DispatchDescendantScreenEvent(node->left, arg1, arg2, arg3, arg4, depth + 1);
        }
        if (context->handled == 0) {
            if (node->right != 0) {
                Smos_DispatchDescendantScreenEvent(node->right, arg1, arg2, arg3, arg4, depth + 1);
            }
            if ((context->handled == 0) && (depth > 0) && (node->value != -1) &&
                (node->type >= 9U)) {
                valid = 1;
                if (((arg1 == 0xE08) && ((node->flags | 2) == 0)) ||
                    ((arg1 == 0xE09) && ((node->flags | 4) == 0))) {
                    valid = 0;
                }
                if (valid != 0) {
                    GetMenuScreenOwner();
                    Smos_RouteElementEvent(node->value, arg1, arg2, arg3, arg4);
                }
            }
        }
        *value = saved;
    }
}

void *Smos_GetScreenManager(void) {
    return D_8014D080;
}

#if defined(VERSION_DE)
unsigned char D_auto_func_80299E74_de_padding_9AA74[12] = { 0xC6, 0x00, 0x00, 0x08, 0x02, 0x00, 0x20, 0x21, 0x0C, 0x09, 0x34, 0x99 };
#endif

