#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80420E90.h"
#include "types.h"
/* Advances a filling or draining bar by the step and writes its level byte at 0x10 of the bar at
   0xC: while rising it scales the amount for the display and, at or above the wrap point, stores
   the remainder with the high bit set, and it finishes at 1000 by storing 0xFF, marking 0x4 and
   calling func_802A2360_de; while falling it does the same from the other pair of constants and
   finishes at zero. Returns the finished flag. */







extern void func_802A2360_de();

s32 func_80421E9C_de(struct Meter *meter, s32 step) {
    struct Resource_func_80419E54_de *bar;
    s32 level;
    f32 value;

    if (meter->done == 0) {
        if (meter->falling == 0) {
            if (meter->amount < 0x3E8) {
                value = (f32)meter->amount * D_800DD600;
                bar = meter->bar;
                if (!(value >= *(&D_800DD600 + 1))) {
                    level = (s32)value;
                } else {
                    level = (s32)(value - *(&D_800DD600 + 1)) | 0x80000000;
                }
                bar->value = level;
            } else {
                meter->bar->value = 0xFF;
                meter->done = 1;
                func_802A2360_de();
            }
            meter->amount = meter->amount + step;
        } else {
            if (meter->amount > 0) {
                value = (f32)meter->amount * D_800DD608;
                bar = meter->bar;
                if (!(value >= *(&D_800DD608 + 1))) {
                    level = (s32)value;
                } else {
                    level = (s32)(value - *(&D_800DD608 + 1)) | 0x80000000;
                }
                bar->value = level;
            } else {
                meter->bar->value = 0;
                meter->done = 1;
                func_802A2360_de();
            }
            meter->amount = meter->amount - step;
        }
    }
    return meter->done;
}
