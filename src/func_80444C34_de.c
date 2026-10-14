#include "span_16E000/code_80444030.h"
#include "types.h"

/* Toggles the byte at offset 0x82 of the settings the object at offset 0x5D8 of the second
   argument's owner holds, or of the defaults D_80146302 when there is no owner, and returns zero. */






extern struct Settings_func_80444BE8_de D_80146302;

s32 func_80444C34_de(void *unused, struct HolderRecAt1CV2 *holder) {
    struct Settings_func_80444BE8_de *settings = &D_80146302;

    if (holder->owner != 0) {
        settings = holder->owner->settings;
    }
    if (settings->flag == 1) {
        settings->flag = 0;
    } else {
        settings->flag = 1;
    }
    return 0;
}
