#include "span_16E000/code_8040F1E0.h"
#include "types.h"
/* Advances the deferred-release timers: for each of the D_80153C0C slots (all reset first when mode
   is 1) whose owner is not -1, counts the delay down, and once it has run out releases the slot's
   loaded resource data through func_80419624_de, clearing its loaded flag, and clears the owner. */







extern PoolRecAtC D_80153C0C;

extern void func_80419624_de(void *data);

void func_80410E1C_de(s32 mode) {
    s32 i;

    for (i = 0; i < D_80153C0C.count; i++) {
        if (mode == 1) {
            D_80153C0C.timers[i].delay = 0;
            D_80153C0C.timers[i].owner = 0;
        }
        if (D_80153C0C.timers[i].owner != -1) {
            if (D_80153C0C.timers[i].delay > 0) {
                D_80153C0C.timers[i].delay--;
            } else {
                if (D_80153C0C.resources[i].flags & 1) {
                    func_80419624_de(D_80153C0C.resources[i].data);
                    D_80153C0C.resources[i].flags &= ~1;
                }
                D_80153C0C.timers[i].owner = 0;
            }
        }
    }
}
