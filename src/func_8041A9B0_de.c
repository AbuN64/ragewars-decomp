#include "span_1000/code_802A208C.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Sets the word at 0x54 of arg0 to 2, calls func_8025DF34_de with 0xE74, and sets the byte at 0x10 of every child in the list at 0x8 whose halfword at 0xE is not 8 to 100, returning zero. Adapted from func_802A1E5C_de with the two stores to 0x5C and 0x48 replaced by a single store of 2 to 0x54. */

extern s32 func_8025DF34_de(s32);






s32 func_8041A9B0_de(struct CommandListMenu *arg0) {
    struct LinkedCommandEntry *p;

    arg0->state = 2;
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
