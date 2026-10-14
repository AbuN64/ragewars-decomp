#include "span_1000/code_80293A04.h"
#include "types.h"

/* Clears D_800D29C8 when func_80293904_de accepts its argument with 4.0 and two fours. */
extern s32 D_800D29C8;
extern s32 func_80293904_de(s32, f32, s32, s32);

void func_802940F8_de(s32 value) {
    if (func_80293904_de(value, 4.0f, 4, 4) != 0) {
        D_800D29C8 = 0;
    }
}
