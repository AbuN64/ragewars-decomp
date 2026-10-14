#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE028.h"
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"
#include "types.h"
extern void func_802B2450_de(Node_func_802AFD6C_de *arg0);
extern void func_802B2480_de(Node_func_802AFD6C_de *arg0, Node_func_802AFD6C_de *arg1);
extern void func_802AFD6C_de(void *arg0, Node_func_802AFD6C_de *arg1);
void func_802AFB6C_de(void *arg0, ObjectState10_2 *arg1) {
    s32 padding[4];
    s32 total = 0;
    Node_func_802AFD6C_de *head = 0;
    s32 scale;
    Node_func_802AFD6C_de *node;
    Node_func_802AFD6C_de *next;
    if (arg1->unk_8 == 0xFF) {
        if (arg1->unk_9 != 0x51) {
            return;
        }
        scale = ((ObjectState4C *)(arg0))->unk_24;
        func_802AFDFC_de(arg0,
                      (f32)((arg1->unk_B << 16) | (arg1->unk_C << 8) | arg1->unk_D));
        node = ((struct ObjectLinks54_2 *) ((char *) arg0))->link;
        while (node != 0) {
            next = ((struct ObjectLinks4_5 *) ((char *) node))->link;
            total += node->value;
            if (node->type == 0x15) {
                s32 node_total;
                func_802B2450_de(node);
                if (head != 0) {
                    func_802B2480_de(node, head);
                } else {
                    head = node;
                    node->prev = 0;
                    node->next = 0;
                }
                node_total = total;
                if (next != 0) {
                    total -= node->value;
                    next->value += node->value;
                }
                node->value = node_total;
            }
            node = next;
        }
        node = head;
        while (node != 0) {
            next = node->prev;
            node->value = (node->value / scale) * ((ObjectState4C *)(arg0))->unk_24;
            func_802AFD6C_de(&((ObjectState4C *)(arg0))->unk_48, node);
            node = next;
        }
    }
}
