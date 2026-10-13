#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023330C.h"
#include "types.h"

extern void func_8022B190_de(s32);

extern s32 func_80283228_de(void *, s32);
extern s16 func_8022F96C_de(void *arg0);
extern s32 func_802301F4_de(void *, void *);
extern s32 func_80214178_de(void *, void *, s32);


extern WeaponActionRecord D_800CE8DC[];
extern char D_8011D8D0;
extern s32 D_801468F4;






void func_80233438_de(void *arg0, void *arg1) {
    void *actor;
    s16 idx;
    s32 value;

    actor = ((func_80232FE8_S1 *)(arg0))->unk1D8;
    idx = ((ObjectLinks11DC *)(actor))->unk_650;
    value = D_800CE8DC[idx].action;

    if (((ObjectLinks11DC *)(actor))->unk_11D8 <= 0.0f) {
        if ((((struct func_8020EA10_S3 *) ((ObjectLinks11DC *) actor)->unk_5D8)->unk8F == 0 ||
             D_801468F4 == 0) &&
            (((ObjectLinks11DC *)(actor))->unk_6AC & 0x4000)) {
            func_8022B190_de(actor);
        }
    }

    if (func_80222AA4_de(actor, ((ObjectLinks11DC *)(actor))->unk_62E) == 0) {
        if (func_80283228_de(&D_8011D8D0, actor) == 0) {
            ((ObjectLinks11DC *)(actor))->unk_770 = func_8022F96C_de(actor);
        }
    } else if (func_802301F4_de(arg0, arg1) == 0 &&
               !(((func_80232FE8_S1 *)(arg0))->unk100 & 0x400)) {
        func_80214178_de(arg0, arg1, value);
    }
}
