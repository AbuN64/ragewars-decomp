#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040B45C.h"
#include "types.h"

/* Points a field's text at D_800D7970 when the option D_80153734 is set and at D_800D797C otherwise, and returns
   zero: the label an option menu shows for that option. */


extern s32 D_80153734;
extern char D_800D7970[];
extern char D_800D797C[];

s32 func_8040B3DC_de(struct FieldRecAt14 *field) {
    if (D_80153734 != 0) {
        field->text = D_800D7970;
    } else {
        field->text = D_800D797C;
    }
    return 0;
}

/* Points a field's text at D_800D7974 when the option D_80153734 is set and at D_800D7980 otherwise, and returns
   zero: the label an option menu shows for that option. */


extern s32 D_80153734;
extern char D_800D7974[];
extern char D_800D7980[];

s32 func_8040B410_de(struct FieldRecAt14 *field) {
    if (D_80153734 != 0) {
        field->text = D_800D7974;
    } else {
        field->text = D_800D7980;
    }
    return 0;
}
