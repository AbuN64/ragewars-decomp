#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802A208C.h"
#include "types.h"

extern s32 func_8025DF34_de(s32);






s32 func_802A1E5C_de(struct CommandListController *arg0) {
    struct LinkedCommandEntry *p;

    arg0->state = 2;
    arg0->progress = 0;
    func_8025DF34_de(0xE74);
    p = arg0->entries;
    if (p != 0) {
        do {
            if (p->kind != 8) {
                p->command = 0x64;
            }
            p = p->next;
        } while (p != 0);
    }
    return 0;
}
