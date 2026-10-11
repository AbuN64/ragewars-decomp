/* Handles one held press of the menu "next page" key: D_800D2AF8 counts the held presses, and on the
 * fourth one the selection index D_8014AEBC is stepped up by five modulo the menu item count; the
 * pre-modulo index store is retained as the original emitted it, and the change flag word at +8 from
 * the index is set. Ported verbatim from the legacy branch source (byte-exact in that build). */
#include "types.h"

extern s32 D_800D2AF8;
extern s32 D_8014AEBC;

void func_80295A60_us_rev1(void) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v1;
    s32 *p;
    s32 old;

    old = D_800D2AF8++;
    if (old >= 3) {
        p = &D_8014AEBC;
        temp_a0 = p[0] + 5;
        temp_v0 = p[-1];
        var_v1 = temp_a0 % temp_v0;
        D_800D2AF8 = 0;
        p[2] = 1;
        *(volatile s32 *)&p[0] = temp_a0;
        p[0] = var_v1;
    }
}
