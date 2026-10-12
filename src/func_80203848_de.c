#include "span_1000/code_802022E0.h"
#include "types.h"

extern void func_80202CA0_de(s32, f32 *);




s32 func_80203848_de(s32 arg0, s32 arg1, struct RotationObject *arg2) {
    f32 sp10[3];

    sp10[0] = arg2->angleX;
    sp10[1] = arg2->angleY;
    sp10[2] = arg2->angleZ;
    func_80202CA0_de(arg0, sp10);
    return arg0;
}
