#include "span_1000/code_80233920.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802661FC.h"
#include "types.h"







extern void *D_80140FE8_de;
extern s32 func_802393AC_de(Node_func_80267CE4_de *arg0, Triple arg1);

void func_80267CE4_de(s32 arg0, s32 arg1, s32 arg2, Triple arg3, SevenBytes arg6) {
    Node_func_80267CE4_de *node;

    node = D_80140FE8_de;
    while (node != 0) {
        if (func_802393AC_de(node, arg3) != 0) {
            func_802391AC_de(node, arg6.a, arg6.b, arg6.c, arg6.d,
                          arg6.e, arg6.f, arg6.g);
        }
        node = node->next;
    }
}
