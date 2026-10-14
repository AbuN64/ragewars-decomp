#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80400000.h"
#include "types.h"
#include "stddef.h"
/* Returns the initial track vector or the configured fallback when no track is active. */
void *func_8028FDB4_de(void *, s32); /* extern */
void func_80400E50_de(Vec3 *, void *, s32, s32); /* extern */
extern State_func_8040385C_de *D_800E2830;
Vec3 func_8040385C_de(void) {
    Vec3 sp10;
    Vec3 sp20;
    StridedTable *temp_v0;
    if (D_800E2830->unk38 == 0) {
        sp20.x = 0;
        sp20.y = 0;
        sp20.z = 0;
        return sp20;
    }
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(D_800E2830->unk4, 0), 0), 0);
    func_80400E50_de(&sp10, temp_v0->data, temp_v0->count, 0);
    return sp10;
}
