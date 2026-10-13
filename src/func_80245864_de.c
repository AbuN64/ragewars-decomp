#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80243A80.h"
#include "shared/func_804235A8_eu_layout.h"
/* Calls func_80401980_de when the globally selected record's word at 0x38 is non-zero. */
extern void *D_800E2830;
extern void func_80401980_de(void);




void func_80245864_de(void) {
    Shared_MenuContext *record = D_800E2830;
    if (record->active != 0) {
        func_80401980_de();
    }
}
