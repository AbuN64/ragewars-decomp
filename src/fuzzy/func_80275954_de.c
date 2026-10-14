#include "types.h"

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

void func_80275954_de(f32 *arg0, s32 arg1, Vec3 *arg2)
{
    s32 i;

    i = 0;
    if (arg1 != 0) {
        arg0[0] = arg2->x;
        arg0[1] = arg2->y;
        arg0[2] = arg2->z;
        arg0[3] = arg2->x;
        arg0[4] = arg2->y;
        arg1 -= 1;
        arg0[5] = arg2->z;
        arg2 += 1;

        if (arg1 > 0) {
            do {
                {
                    f32 value = arg2->x;
                    f32 bound = arg0[0];
                    if (!(value <= bound)) {
                        value = bound;
                    }
                    arg0[0] = value;
                }

                {
                    f32 value = arg2->y;
                    f32 bound = arg0[1];
                    if (!(value <= bound)) {
                        value = bound;
                    }
                    arg0[1] = value;
                }

                {
                    f32 value = arg2->z;
                    f32 bound = arg0[2];
                    if (!(value <= bound)) {
                        value = bound;
                    }
                    arg0[2] = value;
                }

                {
                    f32 value = arg2->x;
                    f32 bound = arg0[3];
                    if (!(bound <= value)) {
                        value = bound;
                    }
                    arg0[3] = value;
                }

                {
                    f32 value = arg2->y;
                    f32 bound = arg0[4];
                    if (!(bound <= value)) {
                        value = bound;
                    }
                    arg0[4] = value;
                }

                {
                    f32 value = arg2->z;
                    f32 bound = arg0[5];
                    if (!(bound <= value)) {
                        value = bound;
                    }
                    arg0[5] = value;
                }

                i += 1;
                arg2 += 1;
            } while (i < arg1);
        }
    }
}
