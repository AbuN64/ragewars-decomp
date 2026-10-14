#include "common/types_8fd754e1e915.h"
#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022D944.h"
#include "types.h"

extern void *D_800D052C[];
extern s32 D_80140FF8;








s32 func_8022E3C4_de(void *arg0, s32 arg1, s32 arg2) {
    s16 **entry;
    s16 **scan;
    WeaponInfo *resource;
    s16 *item;
    s32 i;

    resource = D_800D052C[arg1];
    if (((Player *)arg0)->computer != 0) {
        entry = resource->computerClasses;
        goto scan_setup;
    }
    if (D_80140FF8 != 1) {
        entry = resource->computerClasses;
        goto scan_setup;
    }
    entry = &resource->weaponClass;

scan_setup:
    i = 0;
    scan = entry;
loop:
    item = *scan;
    if (item == 0) {
        goto null_item;
    }
    if (item[2] != arg2) {
        goto mismatch;
    }
    return 1;
null_item:
    return 0;
mismatch:
    i += 1;
    if (i < 3) {
        scan += 1;
        goto loop;
    }
    return 0;
}
