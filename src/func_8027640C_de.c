#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80275E44.h"
#include "types.h"
#include "types.h"
#include "types.h"
void func_8027640C_de(f32 *arg0, s32 arg1, Vec3 *arg2)
{
    s32 i;
    i = 0;
    if (arg1 > 0) {
        do {
            {
                f32 value = arg2[i].x;
                f32 bound = arg0[0];
                if (!(value <= bound)) {
                    value = bound;
                }
                arg0[0] = value;
            }
            {
                f32 value = arg2[i].y;
                f32 bound = arg0[1];
                if (!(value <= bound)) {
                    value = bound;
                }
                arg0[1] = value;
            }
            {
                f32 value = arg2[i].z;
                f32 bound = arg0[2];
                if (!(value <= bound)) {
                    value = bound;
                }
                arg0[2] = value;
            }
            {
                f32 value = arg2[i].x;
                f32 bound = arg0[3];
                if (!(bound <= value)) {
                    value = bound;
                }
                arg0[3] = value;
            }
            {
                f32 value = arg2[i].y;
                f32 bound = arg0[4];
                if (!(bound <= value)) {
                    value = bound;
                }
                arg0[4] = value;
            }
            {
                f32 value = arg2[i].z;
                f32 bound = arg0[5];
                if (!(bound <= value)) {
                    value = bound;
                }
                arg0[5] = value;
            }
            i += 1;
        } while (i < arg1);
    }
}
