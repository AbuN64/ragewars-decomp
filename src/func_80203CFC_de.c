#include "span_1000/code_802022E0.h"
#include "types.h"

extern void func_80202CA0_de(s32 *, f32 *);
extern void func_80274244_de(void *, void *);




void func_80203CFC_de(void *unused0, struct RotationObject *arg1, s32 arg2) {
    s32 sp10[4];
    f32 sp20[3];

    sp20[0] = arg1->angleX;
    sp20[1] = arg1->angleY;
    sp20[2] = arg1->angleZ;
    func_80202CA0_de(sp10, sp20);
    func_80274244_de(sp10, (void *)arg2);
}
