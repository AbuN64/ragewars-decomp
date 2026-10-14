#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80268160.h"
#include "types.h"

/* Plays an effect at a position through func_8025DEC0_de unless the global D_80146894 is set, selecting the target from the given object's type and team masks and choosing the scale from the global option flags. Adapted from func_8026730C_de with the null object test and case 2 removed, a team test for case 0, a mask test for case 1, and the scale constants changed. */








extern f32 D_800C4460_de[];


extern s32 D_80146894;

extern s32 func_8025DEC0_de(s32 arg0, Vec3 arg1, s32 arg4, s32 arg5,
                         f32 arg6);

void func_8026826C_de(ObjectRecAt17C *arg0, ObjectRecAt17C *arg1, s32 arg2, Vec3 arg3,
                   ParamsRecAt4 arg6) {
    s32 *global = &D_80146894;
    s32 selected;
    f32 scale;

    scale = D_800C4460_de[1];
    selected = -1;
    if (global[0] != 0) {
        return;
    }

    switch (arg1->type) {
    case 0:
        if (arg0->kind->team != arg6.team) {
            return;
        }
        selected = arg1->value;
        break;
    case 1:
        if (arg1->kind->value == arg1->type) {
            if (global[-371] & 0x40) {
                scale = D_800C4468_de;
            } else if (global[-371] & 0x20) {
                scale = D_800C446C_de;
            }
        }
        if ((arg1->mask & (1 << arg6.team)) == 0) {
            return;
        }
        break;
    }

    func_8025DEC0_de(arg6.value, arg3, 0, selected, scale);
}
