#include "common/types_1dc8418c21db.h"
#include "span_166000/code_80426310.h"
#include "types.h"

/* Steps the menu spinner in D_800E5CA0: advances its repeat timer by D_800D2988, wrapping at the second entry of D_800E2280, and while the menu is active (state 2) decrements its value above zero when func_80264388_de reports the decrease input, or else increments it below its maximum when func_802643A0_de reports the increase input, restarting the timer on a change. Returns zero. */




extern Triple_func_802683E0_de D_800E5CA0;
extern f32 D_800D2988;
extern f32 D_800E2280[];




s32 func_8043CB30_de(void *unused, MenuRecAt20V4 *menu) {
    f32 t;

    t = D_800E5CA0.y + D_800D2988;
    D_800E5CA0.y = t;
    if (t >= D_800E2280[1]) {
        D_800E5CA0.y = t - D_800E2280[1];
    }
    if (menu->state == 2) {
        if (((s32 (*)(s32))func_80264388_de)(menu->input) != 0 && D_800E5CA0.x > 0) {
            D_800E5CA0.x--;
            D_800E5CA0.y = 0.0f;
        } else if (((s32 (*)(s32))func_802643A0_de)(menu->input) != 0) {
            if (D_800E5CA0.x < D_800E5CA0.z) {
                D_800E5CA0.x++;
                D_800E5CA0.y = 0.0f;
            }
        }
    }
    return 0;
}
