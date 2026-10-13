#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80208000.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022BA90.h"
#include "types.h"
#include "span_1000/code_8026AC38.h"


extern s32 D_80140FF8;
extern s32 D_8014288C;
extern void *D_800D052C[];









void func_8022BC14_de(void *arg0) {
    s32 var_t0;

    if (((Player *)arg0)->computer != 0) {
        if (D_8014288C == 0) {
            var_t0 = 0x17;
            goto after;
        }
    }
    var_t0 = (D_80140FF8 == 1) ? 0 : 0x17;
after:
    ((void (*)(void *, void *, s32, s32))func_8028B274_de)(&D_8011FE88, &((Player *)arg0)->weaponModel,
        ((WeaponInfo *)D_800D052C[((Player *)arg0)->selectedAction])->model + var_t0,
        ((Player *)arg0)->weaponAnimationTable->defaultAnimation);
}
