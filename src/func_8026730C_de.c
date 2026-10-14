#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802661FC.h"
#include "types.h"










extern s32 D_80146894;

extern s32 func_8025DEC0_de(s32 arg0, Vec3 arg1, s32 arg4, s32 arg5,
                         f32 arg6);

void func_8026730C_de(s32 arg0, ObjectRecAtD0 *arg1, s32 arg2, Vec3 arg3,
                   Clip arg6) {
    s32 *global = &D_80146894;
    s32 selected;
    f32 scale;

    scale = D_800C4424_de;
    selected = -1;
    if (global[0] != 0) {
        return;
    }

    if (arg1 != 0) {
        switch (arg1->type) {
        case 1:
            if (*arg1->kind == arg1->type) {
                if (global[-371] & 0x40) {
                    scale = D_800C4428_de;
                } else if (global[-371] & 0x20) {
                    scale = D_800C442C_de;
                }
            }
            selected = (s32)arg1;
            break;
        case 0:
            selected = arg1->value;
            break;
        case 2:
            selected = (s32)arg1;
            break;
        }
    }

    func_8025DEC0_de(arg6.frames, arg3, 0, selected, scale);
}
