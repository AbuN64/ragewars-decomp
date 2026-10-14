#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041B020.h"
#include "types.h"
/* Allocates and zeroes a 0x70-byte overlay node, copies the 0x2C-byte header of the owner's tree root into it, tags it 0x7A51 with kind 0x7D5 and flags 8, links it to its owner and the given value, inserts it under the root through func_8040EDE4_de and records it as the owner's overlay. */









extern Node_func_8041B610_de *func_8025305C_de(s32 size);
extern void func_802A0748_de(Node_func_8041B610_de *node, s32 value, s32 size);
extern void func_8040EDE4_de(Node_func_8041B610_de *parent, Node_func_8041B610_de *node);

Node_func_8041B610_de *func_8041B610_de(OwnerRecAt44 *owner, s32 value) {
    Node_func_8041B610_de *node;

    node = func_8025305C_de(0x70);
    func_802A0748_de(node, 0, 0x70);
    *(Header44 *)node = *(Header44 *)owner->root;
    node->kind = 0x7D5;
    node->flags = 8;
    node->value = value;
    node->owner = owner;
    node->tag = 0x7A51;
    node->field_6C = 0;
    func_8040EDE4_de(owner->root, node);
    return owner->overlay = node;
}
