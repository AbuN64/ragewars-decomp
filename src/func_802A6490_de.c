#include "span_1000/code_802A6AC0.h"
#include "types.h"

extern void func_802A354C_de(void *arg0);
extern void func_802A339C_de(void *, void *);
extern void func_802A3718_de(s32, void *, s32);
extern void func_802A3DD4_de(s32, void *, s32);






void func_802A6490_de(void *arg0, void *arg1) {
    State802A6DF8 *node;

    node = ((Owner802A6DF8 *)arg0)->lists.inactive.head;
    while (node != 0) {
        if (node->renderMode < 0) {
            if (node->flags & 8) {
                func_802A354C_de(node);
            }
            if (node->flags & 4) {
                func_802A339C_de(node, arg1);
            }
            if (node->vertexCount >= 2) {
                if (node->renderMode >= 0) {
                    func_802A3718_de(arg0, node, arg1);
                } else {
                    func_802A3DD4_de(arg0, node, arg1);
                }
            }
        }
        node = node->next;
    }

    node = ((Owner802A6DF8 *)arg0)->lists.inactive.head;
    while (node != 0) {
        if (node->renderMode > 0) {
            if (node->flags & 8) {
                func_802A354C_de(node);
            }
            if (node->flags & 4) {
                func_802A339C_de(node, arg1);
            }
            if (node->vertexCount >= 2) {
                if (node->renderMode >= 0) {
                    func_802A3718_de(arg0, node, arg1);
                } else {
                    func_802A3DD4_de(arg0, node, arg1);
                }
            }
        }
        node = node->next;
    }
}
