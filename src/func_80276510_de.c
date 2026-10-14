#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80275E44.h"
#include "types.h"
#include "types.h"
#include "types.h"
/** Expand the four-float X/Z bounds in arg0 over arg1 packed vectors. */
void func_80276510_de(f32 *arg0, s32 arg1, Vec3 *arg2)
{
    f32 value;
    f32 bound;
    s32 i;
    i = 0;
    if (arg1 > 0) {
        do {
            value = arg2[i].x;
            bound = arg0[0];
            if (!(value <= bound)) {
                value = bound;
            }
            arg0[0] = value;
            value = arg2[i].z;
            bound = arg0[1];
            if (!(value <= bound)) {
                value = bound;
            }
            arg0[1] = value;
            value = arg2[i].x;
            bound = arg0[2];
            if (!(bound <= value)) {
                value = bound;
            }
            arg0[2] = value;
            value = arg2[i].z;
            bound = arg0[3];
            if (!(bound <= value)) {
                value = bound;
            }
            arg0[3] = value;
            i += 1;
        } while (i < arg1);
    }
}
/** Empty adjacent entry point included in func_80276510_de's Splat span. */
void func_802765A0_de(void)
{
}
