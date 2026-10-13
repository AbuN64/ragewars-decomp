#include "span_1000/code_80225D10.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022A274.h"
#include "types.h"







extern GlobalState D_801468A0;

extern struct Shape_func_8021A2D4_de_2 D_801427FC;

extern void func_802227F4_de(Node_func_8022A748_de *arg0, Node_func_8022A748_de *arg1, s32 arg2);




void func_8022A748_de(void *arg0) {
    GlobalState *state;
    Round *round = arg0;
    Node_func_8022A748_de *node;

    state = &D_801468A0;
    if ((state->field1C != 0) || (state->field20 != 0)) {
        return;
    }

    func_80264854_de(0);
    if (state->field24 != 0) {
        if (state->field28 == 0) {
            state->field28 = 1;
            node = (Node_func_8022A748_de *)round->players;
            while (node != 0) {
                func_802227F4_de(node, node, 0x15);
                node = node->next;
            }
        }
    } else {
        state->field1C = 1;
        node = (Node_func_8022A748_de *)round->players;
        while (node != 0) {
            func_802227F4_de(node, node, 0x15);
            node = node->next;
        }
    }

    D_801427FC.field_0 = 1;
    node = (Node_func_8022A748_de *)round->players;
    while (node != 0) {
        node->field85C = 0;
        node->state[0x8E] = 1;
        node = node->next;
    }
}
