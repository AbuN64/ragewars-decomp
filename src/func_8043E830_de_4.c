#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043E9A8.h"
#include "types.h"

/* When the timer D_801468B0 has run out, calls func_8044DD50_de on D_8011FAC0 and returns one;
   otherwise returns zero. */
extern f32 D_801468B0;
extern char D_8011FAC0[];
extern void func_8044DD50_de(void *);

s32 func_8043EDDC_de(void) {
    if (D_801468B0 <= 0.0f) {
        func_8044DD50_de(D_8011FAC0);
        return 1;
    }
    return 0;
}

/* Counts the timer at offset 0x10 of D_801468A0 down by D_800D2988, stopping at zero, and returns
   zero. */


extern struct Field_f32_10 D_801468A0;
extern f32 D_800D2988;

s32 func_8043EE24_de(void) {
    struct Field_f32_10 *state = &D_801468A0;
    f32 timer = state->value - D_800D2988;

    state->value = timer;
    if (timer < 0.0f) {
        state->value = 0.0f;
    }
    return 0;
}
