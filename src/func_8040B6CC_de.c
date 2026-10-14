#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040B45C.h"
#include "types.h"

/* Points a field's text at D_800D7990 when the option D_80153760 is set and at D_800D7994 otherwise, and returns
   zero: the label an option menu shows for that option. */


extern s32 D_80153760;
extern char D_800D7990[];
extern char D_800D7994[];

s32 func_8040B6CC_de(struct FieldRecAt14 *field) {
    if (D_80153760 != 0) {
        field->text = D_800D7990;
    } else {
        field->text = D_800D7994;
    }
    return 0;
}
