#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043DF84.h"
#include "types.h"

/** Runs func_804423BC_de on a byte in arg1->unk1C->unk5D8[0x83] and writes the result back into that byte. */

extern s32 func_804423BC_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);






s32 func_8043E28C_de(void *arg0, void *arg1) {
    Shared_ActorView *p;
    u8 *bytep;
    s32 result;

    p = (void *)((Menu_func_8043E1F8_de *)arg1)->owner;
    bytep = &p->controls->selection;
    result = func_804423BC_de(arg1, *bytep, 1, 0, 0xA, 0);
    *bytep = (u8)result;
    return 0;
}
