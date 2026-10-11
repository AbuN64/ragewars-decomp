/* Handles one held press of the menu "previous item" key: D_auto_800D2AE4 counts the held presses, and on
 * the fourth one the selection index D_8014AEBC is stepped down by one modulo the menu item count,
 * the change flag word at +8 from the index is set, and a negative remainder is folded back to a
 * positive display index. Ported verbatim from the legacy branch source (byte-exact in that build). */
#include "types.h"

extern s32 D_auto_800D2AE4;
extern s32 D_8014AEBC;

void func_802957EC_us_rev1(void) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v1;
    s32 *p;
    s32 old;

    old = D_auto_800D2AE4++;
    if (old >= 3) {
        p = &D_8014AEBC;
        temp_a0 = p[0] - 1;
        temp_v0 = temp_a0 + p[-1];
        var_v1 = temp_v0 % p[-1];
        p[2] = 1;
        *(volatile s32 *)&p[0] = temp_a0;
        p[0] = var_v1;
        if ((f32) var_v1 < 0.0f) {
            var_v1 = -var_v1;
        }
        p[0] = var_v1;
        D_auto_800D2AE4 = 0;
    }
}
