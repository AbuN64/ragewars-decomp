#include "span_1000/code_80245980.h"
#include "shared/func_804235A8_eu_layout.h"
/* Returns the globally selected record's float at 0xA0 scaled by D_800C88CC. */
extern void *D_800E2830;





float func_80245AD8_de(void) {
    Shared_MenuContext *record = D_800E2830;
    return (record->scaleA0) * (D_800C88CC);
}
