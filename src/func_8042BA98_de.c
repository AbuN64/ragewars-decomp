#include "span_16E000/code_80429C10.h"
#include "types.h"

/* Calls func_8042AAD0_de when the word at offset 0x3DC of the object D_800E4F60 points to is 3, and
   returns zero. */


extern struct State_func_8042BA98_de *D_800E4F60;


s32 func_8042BA98_de(void) {
    if (D_800E4F60->mode == 3) {
        func_8042AAD0_de();
        return 0;
    }
    return 0;
}
