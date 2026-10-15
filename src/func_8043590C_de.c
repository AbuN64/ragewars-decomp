#include "span_16E000/code_80434F4C.h"
#include "types.h"
#include "stddef.h"
/* Checks that every active player on the selected team has the configured value. */
  extern State_func_8043590C_de *D_800E54A4; extern s32 D_80102B08[]; extern s8 D_80102B0D[], D_800FEB0E[];
s32 func_8043590C_de(s32 arg0) {
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    var_a3 = 1;
    var_a2 = 0;
    var_a1 = 0;
    do {
        if ((*(D_800FEB0E + var_a1) == 0) && (*(D_80102B0D + var_a1) == arg0) && (*(s32 *)((char *)D_80102B08 + var_a1) != D_800E54A4->players[arg0].value)) {
            var_a3 = 0;
        }
        var_a2 += 1;
        var_a1 += 0x190;
    } while (var_a2 < 4);
    return var_a3;
}
