#include "span_1000/code_802412C0.h"
#include "types.h"
#include "common/draft_fields_func_802413C8_de.h"




extern void func_80271F68_de(f32 *, void *, void *);

s32 func_80271FC8_de(void *, u32, void *, void *);

s32 func_802413C8_de(void *arg0, void *arg1, void *arg2, void *arg3) {
    f32 sp10[3];
    f32 sp20[3];
    f32 sp30;
    f32 temp_f20;
    s32 var_v0;

    if (((struct MeasuredRecAt8V4 *)(arg0))->value == 0) {
        var_v0 = 0;
    } else {
        func_80271F68_de(sp10, arg2, arg1);
        temp_f20 = (((struct MeasuredRecAt48V2 *)(arg0))->value * sp10[0]) + (((struct Measured_func_802413C8_de_543fa7882177 *)(arg0))->value * sp10[1]) + (((struct Measured_func_802413C8_de_48a8d17d95e2 *)(arg0))->value * sp10[2]);
        var_v0 = 0;
        if (temp_f20 >= (f32)0) {
            sp30 = D_800C3744_de;
        } else {
            func_80271F68_de(sp20, arg1, arg0 + 0x18);
            var_v0 = 1;
            sp30 = -((((struct MeasuredRecAt48V2 *)(arg0))->value * sp20[0]) + (((struct Measured_func_802413C8_de_543fa7882177 *)(arg0))->value * sp20[1]) + (((struct Measured_func_802413C8_de_48a8d17d95e2 *)(arg0))->value * sp20[2])) / temp_f20;
        }
    }
    if (var_v0 != 0) {
        func_80271FC8_de(arg3, *(u32 *)&sp30, arg1, arg2);
        return 1;
    }
    return 0;
}
