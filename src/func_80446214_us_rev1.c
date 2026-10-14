#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804453C4.h"
#include "types.h"

/* Flips D_800D2AE0 between zero and one and returns zero. */
extern s32 D_800D2AE0;

s32 func_80446214_us_rev1(void) {
    D_800D2AE0 = D_800D2AE0 == 0;
    return 0;
}

/* Points a field's text at D_800E6058 when the option D_800D2AE0 is set and at D_800E6074 otherwise, and returns
   zero: the label an option menu shows for that option. */


extern s32 D_800D2AE0;
extern char D_800E6058[];
extern char D_800E6074[];

s32 func_80446230_us_rev1(struct FieldRecAt14 *field) {
    if (D_800D2AE0 != 0) {
        field->text = D_800E6058;
    } else {
        field->text = D_800E6074;
    }
    return 0;
}
