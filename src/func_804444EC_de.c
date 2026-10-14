#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80444030.h"
#include "types.h"

/* Points a field's text at D_800D75F0 when the byte at offset 0x7C of the settings the second argument's owner holds (or of the defaults D_80146302 without an owner or settings) is zero, at D_800D75EC when it is one, and leaves it otherwise, returning zero. Adapted from func_80444BE8_de with the settings pointer checked for null, the byte offset 0x7C, and a nested test over the texts D_800D75F0 and D_800D75EC changed. */








extern struct Settings_func_80444488_de D_80146302;
extern char D_800D75EC[];
extern char D_800D75F0[];

s32 func_804444EC_de(struct FieldRecAt14 *field, struct Holder_func_80444488_de *holder) {
    s32 result = 0;
    struct Settings_func_80444488_de *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    if (settings->value != 0) {
        if (settings->value == 1) {
            field->text = D_800D75EC;
        }
    } else {
        field->text = D_800D75F0;
    }
    return result;
}
