#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024E130.h"
#include "types.h"



extern void func_8024E79C_de(void *arg0, Triple_func_8024E59C_de t, void *arg4, s32 *arg5, s32 arg6, s32 arg7);
extern f32 func_80275DD4_de(struct Node75 *node, f32 x, f32 z);






void func_8024E59C_de(void *arg0, void *arg1, void *arg2) {
    Vec3 *source = arg1;
    Vec3 *output = arg2;
    Triple_func_8024E59C_de t;
    s32 sp30;

    t.a = source->x;
    t.b = 0;
    t.c = source->z;
    func_8024E79C_de(arg0, t, arg2, &sp30, 0, 0);
    output->y = func_80275DD4_de((struct Node75 *)sp30, output->x, output->z);
}
