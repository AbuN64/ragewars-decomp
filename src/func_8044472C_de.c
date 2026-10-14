#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80444030.h"
#include "types.h"

/* Points a field's text at one of the three labels D_800D7604, D_800D7608 or D_800D760C chosen by the option byte D_801462E3 and returns zero.
   Adapted from func_8040BBC0_us with the jump-table state word changed to a three-case switch on an option byte. */



extern u8 D_801462E3;
extern char D_800D7604[];
extern char D_800D7608[];
extern char D_800D760C[];

s32 func_8044472C_de(struct FieldRecAt14 *field) {
    switch (D_801462E3) {
    case 0:
        field->text = D_800D7604;
        break;
    case 1:
        field->text = D_800D7608;
        break;
    case 2:
        field->text = D_800D760C;
        break;
    default:
        return 0;
    }
    return 0;
}
