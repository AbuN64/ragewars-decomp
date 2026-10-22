#include "COMMON/NODERECAT2A8.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "stddef.h"
#include "TYPES.H"

MenuWidget *func_8040EC30_de(void *root, s32 identifier) {
    MenuWidget *node = root;
    u16 id = identifier;
    MenuWidget *found = 0;

    while (node != 0 && found == 0) {
        if (node->resource == id) {
            found = node;
        }
        if (found == 0 && node->child != 0) {
            found = func_8040EC30_de(node->child, id);
        }
        node = node->sibling;
    }
    return found;
}

/* Searches the sibling list starting at node, descending depth first into each node's child list, for the first node whose next sibling carries the given id, and returns that predecessor or null. Adapted from func_8040EC30_de with the id test moved from the node to its next sibling and the id taken as an int narrowed to unsigned short at each use, the recursive call reading a copy of it taken after the result is cleared. */



struct Tree *func_8040ECA8_de(struct Tree *node, s32 id) {
    s32 childId;
    struct Tree *found = 0;

    childId = id;
    while (node != 0 && found == 0) {
        if (node->next != 0 && node->next->id == (u16)id) {
            found = node;
        }
        if (found == 0 && node->child != 0) {
            found = func_8040ECA8_de(node->child, (u16)childId);
        }
        node = node->next;
    }
    return found;
}

/* Recursively replaces a node reference throughout a linked hierarchy and copies the old node links into its replacement. */
void func_8040ED38_de(Node_func_8040ED38_de *arg0, Node_func_8040ED38_de *arg1, Node_func_8040ED38_de *arg2, Node_func_8040ED38_de *arg3) {
    Node_func_8040ED38_de *temp_a0;
    Node_func_8040ED38_de *temp_a0_2;
    if (arg0 != NULL) {
        temp_a0 = arg0->unk4;
        if (temp_a0 != NULL) {
            func_8040ED38_de(temp_a0,arg1,arg2,arg3);
        }
        temp_a0_2 = arg0->unk8;
        if (temp_a0_2 != NULL) {
            func_8040ED38_de(temp_a0_2, arg0, arg2, arg3);
        }
        if (arg0->unk0 == arg2) {
            arg0->unk0 = arg3;
        }
        if (arg0->unk4 == arg2) {
            arg0->unk4 = arg3;
        }
        if (arg0->unk8 == arg2) {
            arg0->unk8 = arg3;
        }
        if (arg0 == arg2) {
            arg3->unk0 = (Node_func_8040ED38_de *) arg0->unk0;
            arg3->unk4 = (Node_func_8040ED38_de *) arg0->unk4;
            arg3->unk8 = (Node_func_8040ED38_de *) arg0->unk8;
        }
    }
}
