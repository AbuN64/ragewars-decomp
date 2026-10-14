#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80443868.h"
#include "types.h"

/* Points a field's text at D_800D7BE8 when the option D_801468F4 is set and at D_800D7BE4 otherwise, and returns
   zero: the label an option menu shows for that option. */


extern s32 D_801468F4;
extern char D_800D7BE8[];
extern char D_800D7BE4[];

s32 func_80443964_de(struct FieldRecAt14 *field) {
    if (D_801468F4 != 0) {
        field->text = D_800D7BE8;
    } else {
        field->text = D_800D7BE4;
    }
    return 0;
}
