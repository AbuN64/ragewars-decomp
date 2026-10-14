#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041DF04.h"
#include "types.h"

/* Returns the column of the first of the seventeen eight-byte entries in row r of D_800E381C whose
   identifier matches, or zero when none does. */


extern struct IntPair D_800E381C[][17];

s32 func_8041EC44_de(s32 row, s32 id) {
    s32 i;

    for (i = 0; i < 0x11; i++) {
        if (D_800E381C[row][i].field_0 == id) {
            return i;
        }
    }
    return 0;
}
