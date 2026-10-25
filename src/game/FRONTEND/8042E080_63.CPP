#include "COMMON/ENTRYRECAT6C.H"
#include "FRONTEND/PAKMENU.H"
#include "TYPES.H"
#include "stddef.h"
#include "FRONTEND/8042E080_63.H"

/* Checks that every active player on the selected team has the configured value. */
  extern s32 D_80102B08[]; extern s8 D_80102B0D[], D_800FEB0E[];
s32 func_8043590C_de(s32 player) {
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    var_a3 = 1;
    var_a2 = 0;
    var_a1 = 0;
    do {
        if ((*(D_800FEB0E + var_a1) == 0) && (*(D_80102B0D + var_a1) == player) && (*(s32 *)((char *)D_80102B08 + var_a1) != D_800E54A4->players[player].profile)) {
            var_a3 = 0;
        }
        var_a2 += 1;
        var_a1 += 0x190;
    } while (var_a2 < 4);
    return var_a3;
}
