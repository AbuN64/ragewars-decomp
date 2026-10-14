#include "span_16E000/code_8042BD40.h"
#include "types.h"

/* When the fourth argument is one, calls func_8029973C_de and, while the position at offset 0xE8 of
   the object D_800E53C0 points to is more than four below the limit at 0xEC, advances it and calls
   func_8042C018_de. Returns zero. */


extern struct State_func_8042D908_de *D_800E53C0;
extern void func_8029973C_de();
extern void func_8042C018_de();

s32 func_8042D908_de(void *first, void *second, void *third, s32 fourth) {
    struct State_func_8042D908_de *state;
    s32 position;

    if (fourth == 1) {
        func_8029973C_de();
        state = D_800E53C0;
        position = state->position;
        if (position + 4 < state->limit) {
            state->position = position + 1;
            func_8042C018_de();
            return 0;
        }
    }
    return 0;
}
