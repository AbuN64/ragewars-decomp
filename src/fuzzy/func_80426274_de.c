#include "span_16E000/code_8041F1FC.h"
#include "span_16E000/code_804251F4.h"
#include "types.h"

extern Match_func_80420618_de D_801462C8;
extern s8 D_8014222C;
extern s8 D_8014222D;
extern s32 D_800FF140_de[];

s32 func_80426274_de(void) {
    s32 i;
    s32 count;
    s32 result;
    RosterSlot *slot;

    result = 1;
    if (D_8014222C <= 0 && D_8014222D <= 0) {
        return 0;
    }
    count = 0;
    slot = D_801462C8.slots;
    for (i = 0; i < 8; i++, slot++) {
        if (slot->active != 1 || slot->locked != 1) {
            if (D_800FF140_de[i] >= 76) {
                count++;
            }
        }
    }
    if (count < 2) {
        result = 0;
    }
    return result;
}
