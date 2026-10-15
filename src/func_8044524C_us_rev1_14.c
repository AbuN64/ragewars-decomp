#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80444EC0.h"
#include "types.h"
#include "stddef.h"
#include "common/unused.h"
/* Cycles a menu selection from directional input while skipping reserved entries. */
 /* extern */
s32 func_804453F0_de(s32 arg0, struct RecordRecAt20V1 *arg1) {
    s32 var_a0;
    var_a0 = D_800E63B8;
    if (arg1->inner->unkB0 & 0x20202) {
        var_a0 -= 1;
        if (var_a0 < 0) {
            var_a0 = 0x16;
        } else if (var_a0 == 0xE) {
            var_a0 = 0xB;
        }
    }
    if (arg1->inner->unkB0 & 0x4D101) {
        var_a0 += 1;
        if (var_a0 >= 0x17) {
            var_a0 = 0;
        } else if (var_a0 == 0xC) {
            var_a0 = 0xF;
        }
    }
    D_800E63B8 = var_a0;
    func_8025E2D4_de(var_a0);
    return 0;
}
