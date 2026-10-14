#include "shared/func_8041F2A0_us_rev1_closed.h"


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
