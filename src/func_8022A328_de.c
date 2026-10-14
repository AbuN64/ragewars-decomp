#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"

extern void func_8021CBD0_de(void *arg0, void *arg1);


#if defined(VERSION_US_REV1)
extern s32 D_800D0EBC;
#endif








/* Removes entity from list if owned by specific owner, with version-specific check. */
void func_8022A328_de(void *arg0, void *arg1) {
    func_80228774_S1 *object;
    func_80207B5C_S2 *argument;
    ObjRecAt16E0V3 *var_s0;

#if defined(VERSION_US_REV1)
    if (D_800D0EBC != 0) {
        object = arg0;
        object = arg0;
    var_s0 = object->unk20;
        if (var_s0 != 0) {
            do {
                argument = arg1;
                if (var_s0->unk5DC == arg1 &&
                    argument->unk24 == 0 &&
                    var_s0->unkE4 != D_800CE47C) {
                    func_8021CBD0_de(var_s0, arg1);
                }
                var_s0 = var_s0->unk16E0;
            } while (var_s0 != 0);
        }
    }
#else
    object = arg0;
    var_s0 = object->unk20;
    if (var_s0 != 0) {
        do {
            argument = arg1;
            if (var_s0->unk5DC == arg1 &&
                argument->unk24 == 0 &&
                var_s0->unkE4 != D_800CE47C) {
                func_8021CBD0_de(var_s0, arg1);
            }
            var_s0 = var_s0->unk16E0;
        } while (var_s0 != 0);
    }
#endif
}
