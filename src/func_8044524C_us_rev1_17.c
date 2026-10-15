#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80444EC0.h"
#include "types.h"
#include "common/unused.h"

/* Toggles the owner at offset 0x1C of the second argument between states 1 and 2 through its word
   at 0x5D0, leaving any other state alone; returns zero. */




s32 func_80445FC8_us_rev1(void *unused, struct Holder *holder) {
    struct OwnerRecAt5D0 *owner = holder->owner;

    if (owner == 0) {
        return 0;
    }
    if (owner->value == 1) {
        owner->value = 2;
    } else if (owner->value == 2) {
        owner->value = 1;
    }
    return 0;
}

/* Points a field's text at D_800E6090 when the owner at offset 0x1C of the second argument has its
   word at 0x5D0 equal to one, and at D_800E60AC otherwise; returns zero, doing nothing without an
   owner. */







s32 func_80446000_us_rev1(struct FieldRecAt14 *field, struct Holder *holder) {
    if (holder->owner == 0) {
        return 0;
    }
    if (holder->owner->value == 1) {
        field->text = D_800E6090;
    } else {
        field->text = D_800E60AC;
    }
    return 0;
}

/* Replaces D_800D0EBC with what func_804423BC_de returns for the second argument, D_800D0EBC, 1, 0, 1 and 1,
   and returns zero. */
extern s32 func_804423BC_de(void *, s32, s32, s32, s32, s32);

s32 func_80446048_us_rev1(void *first, void *second) {
    D_800D0EBC = func_804423BC_de(second, D_800D0EBC, 1, 0, 1, 1);
    return 0;
}
