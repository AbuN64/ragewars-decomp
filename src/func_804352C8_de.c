#include "span_16E000/code_80434F4C.h"
#include "types.h"

/* Takes a free slot from func_804351E4_de and fills it with two values, marking it set, as
   func_8043599C_de does for an index; returns one, or zero when no slot is free. */




extern struct Table_func_804352C8_de *D_800E54A4;


s32 func_804352C8_de(s32 first, s32 second) {
    s32 result = 0;
    s32 index = func_804351E4_de();
    s32 taken;

    if (index >= 0) {
        taken = 1;
        result = taken;
        D_800E54A4->slots[index].x = first;
        D_800E54A4->slots[index].y = second;
        D_800E54A4->slots[index].z = result;
    }
    taken = result;
    return taken;
}
