#include "span_1000/code_80243A80.h"
#include "shared/func_804235A8_eu_layout.h"
/* Reports whether func_80245798_de accepts the globally selected record and bit 2 of its word at 0x74
   is set. */
extern int func_80245798_de(void);

extern void *D_800E2830;




int func_80245908_de(void) {
    Shared_MenuContext *record;
    if (func_80245798_de() == 0) {
        return 0;
    }
    record = D_800E2830;
    if ((record->flags & 2) != 0) {
        return 1;
    }
    return 0;
}
