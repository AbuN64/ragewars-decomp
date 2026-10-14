#include "span_16E000/code_80429C10.h"
#include "types.h"

/* Calls func_8029973C_de; when the mode word at offset 0x3DC of the object D_800E4F60 points to is 3,
   sets it to 5 and the word at 0x3E0 to 4. Returns zero. */


extern struct State_func_8042BA54_de *D_800E4F60;
extern void func_8029973C_de();

s32 func_8042BA54_de(void) {
    struct State_func_8042BA54_de *state;

    func_8029973C_de();
    state = D_800E4F60;
    if (state->mode == 3) {
        state->mode = 5;
        state->next = 4;
        return 0;
    }
    return 0;
}
