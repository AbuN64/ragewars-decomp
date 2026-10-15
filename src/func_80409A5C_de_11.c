#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040A83C.h"
#include "types.h"
#include "common/unused.h"

/* Points a field's text at D_800D7810 when D_80153730 is set, at D_800D7818 when D_80153774 is set instead, and at
   D_800D7814 otherwise. Returns zero. */



s32 func_8040A9F8_de(struct FieldRecAt14 *field) {
    if (D_80153730 != 0) {
        field->text = D_800D7810;
    } else if (D_80153774 != 0) {
        field->text = D_800D7818;
    } else {
        field->text = D_800D7814;
    }
    return 0;
}
