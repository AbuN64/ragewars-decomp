#include "span_1000/code_802AE028.h"
#include "types.h"





extern s32 func_802BD170_de(s32);
extern void func_802B2480_de(void *, void * *);




void func_802AFD6C_de(void *arg0, Node_func_802AFD6C_de *arg1) {
    ObjRecAt8V3 *object = arg0;
    s32 saved;
    Node_func_802AFD6C_de **link;
    Node_func_802AFD6C_de *node;
    s32 value;
    s32 node_value;

    saved = func_802BD170_de(1);
    link = &object->unk8;
    if (link != 0) {
loop:
        node = *link;
        if (node == 0) {
            goto insert;
        }
        value = arg1->value;
        node_value = node->value;
        if (value < node_value) {
            node->value = node_value - value;
insert:
            func_802B2480_de(arg1, link);
            goto done;
        }
        arg1->value = value - node_value;
        link = (Node_func_802AFD6C_de **)*link;
        if (link != 0) {
            goto loop;
        }
    }
done:
    func_802BD170_de(saved);
}
