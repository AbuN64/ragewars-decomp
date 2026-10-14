#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80444030.h"
#include "types.h"

/* Points an option field at the text D_800D7600 when the byte at offset 0x7E of the second argument's owner settings (or the defaults D_80146302) is zero and at D_800D75FC when it is one, returning zero. Adapted from func_804445AC_de with the settings byte 0x7E and the texts D_800D7600 and D_800D75FC changed. */









extern struct Settings_func_80444610_de D_80146302;
extern char *D_800D75FC;
extern char *D_800D7600;

s32 func_80444674_de(struct Field *field, struct Holder_func_80444610_de *holder) {
    struct Settings_func_80444610_de *settings = &D_80146302;

    if (holder->owner != 0 && holder->owner->settings != 0) {
        settings = holder->owner->settings;
    }
    switch (settings->value) {
    case 0:
        field->text = &D_800D7600;
        break;
    case 1:
        field->text = &D_800D75FC;
        break;
    }
    return 0;
}
