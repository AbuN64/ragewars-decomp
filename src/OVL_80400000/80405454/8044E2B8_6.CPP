#include "span_1000/code_80291054.h"
#include "span_1000/code_80293A04.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8044E2B8.h"
#include "TYPES.H"

/* Asks func_8044D220_de about D_8011FE88 with a minus-one selector, clears the words of D_801468A0 and puts the object at arg0 into state 0xC with byte 0x26DC1 set to two and the selector, or zero when the lookup failed, stored at 0x26DD8. Adapted from func_80293284_de with the selector fixed at minus one, the word at 0x26DDC cleared before the last word of D_801468A0 instead of set after the selector, and the state 0xC instead of 0xD changed. */

extern s32 func_8044D220_de(s8 *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4);






void func_8044DDD4_de(GameSession *arg0) {
    s32 sp18[6];
    s32 var_s0;

    var_s0 = -1;
    if (func_8044D220_de((s8 *)&D_8011FE88, var_s0, var_s0, sp18, 1) == 0) {
        var_s0 = 0;
    }
    D_801468A0.unk0 = 0;
    D_801468A0.unk4 = 0;
    D_801468A0.unk8 = 0;
    D_801468A0.unkC = 0;
    arg0->selectionActive = 0;
    D_801468A0.first = 0;
    arg0->phase = 2;
    arg0->selector = var_s0;
    arg0->target = 0xC;
}
