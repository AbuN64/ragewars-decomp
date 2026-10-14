#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041B020.h"
#include "types.h"

extern s32 func_8025DF34_de(s32);

s32 func_8041AFA0_de(struct MenuRecAt54 *arg0) {
    struct ItemRecAt10 *p;

    func_8025DF34_de(0xE74);
    p = arg0->items;
    if (p != 0) {
        do {
            if (p->kind != 8) {
                p->alpha = 0x64;
            }
            p = p->next;
        } while (p != 0);
    }
    return 0;
}
