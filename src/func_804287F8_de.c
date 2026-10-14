#include "span_16E000/code_804264F0.h"
#include "types.h"

/* On event 3 with value 0, calls func_8029973C_de, sets the word at offset 0x988 of the object
   D_800E4690 points to to 8 and the byte at 0x10 of its item at 0xA50 to 0x5A, and plays sound
   0xE7C through func_8025DF34_de. Returns zero. */




extern struct State_func_804287F8_de *D_800E4690;
extern void func_8029973C_de();
extern void func_8025DF34_de(s32);

s32 func_804287F8_de(void *first, void *second, u32 event, s32 value) {
    struct State_func_804287F8_de *state;

    if ((event >> 16) == 3 && value == 0) {
        func_8029973C_de();
        state = D_800E4690;
        state->mode = 8;
        state->item->value = 0x5A;
        func_8025DF34_de(0xE7C);
    }
    return 0;
}
