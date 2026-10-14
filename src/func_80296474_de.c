#include "span_1000/code_80296014.h"
#include "types.h"
#include "math_helpers.h"
/* Looks up the neighbour cell for (x,y) in the object's inline grid when both axes are within 9, and sets its state from the sentinel found (or starts a placement for a normal cell). */
extern s32 func_80263154_de(Obj5 *arg0, s32 a1, s32 a2);
void func_80296474_de(Obj5 *arg0, s32 x, s32 y)
{
    if (RW_ABS(x - arg0->unk8) >= 9) {
        return;
    }
    if (RW_ABS(y - arg0->unkC) >= 9) {
        return;
    }
    {
        s32 ddx = x - arg0->unk8;
        s32 ddy = y - arg0->unkC;
        s32 t = (ddy + 8) * 17 + 8;
        s16 val;
        ddx = ddx + t;
        val = arg0->table[ddx];
        if (val == -2) {
            arg0->unk10 = 1;
            return;
        }
        if (val == -3) {
            arg0->unk10 = 0;
            return;
        }
        if (val == -1) {
            arg0->unk10 = 3;
            return;
        }
        arg0->unk10 = 2;
        arg0->unk4 = val;
        arg0->unk14 = func_80263154_de(arg0, 9, y);
    }
}
