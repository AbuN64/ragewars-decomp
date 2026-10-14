#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80420E90.h"
#include "types.h"

/* Switches a timer record to a new mode: when the mode at offset 8 changes it stores the mode,
   loads the countdown at offset 0 with 1000 for a non-zero mode or zero otherwise, and clears the
   word at offset 4. */


void func_80421E6C_de(struct Triple *timer, s32 mode) {
    if (timer->z != mode) {
        timer->z = mode;
        if (mode == 0) {
            timer->x = 0;
        } else {
            timer->x = 1000;
        }
        timer->y = 0;
    }
}
