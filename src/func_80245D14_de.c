#include "shared/func_804235A8_eu_layout.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80245980.h"
/** Read the word at offset 0x38 from the globally selected record. */
extern void *D_800E2830;




int func_80245D14_de(void) {
    Shared_MenuContext *record = D_800E2830;
    return record->active;
}
