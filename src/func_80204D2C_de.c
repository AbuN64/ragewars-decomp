#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80203F04.h"
#include "types.h"






extern char D_801379C0;

extern void func_80285DB0_de(void *arg0, void *arg1, s32 arg2);
extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);
extern void func_802A5D38_de(void *arg0, void *arg1);
extern void func_80267198_de(void *arg0, void *arg1, s32 arg2,
                          Triple arg3, struct Shape_func_802764D4_de_2 arg4);




void func_80204D2C_de(BreakableHitContext *arg0) {
    struct Shape_func_802764D4_de_2 local;
    Shared_World *flag;

    local.field_0 = 0;
    flag = &D_8011FE88;
    func_80285DB0_de(flag, arg0, 0);
    func_80278D78_de(arg0, 0x8000, arg0);
    func_802A5D38_de(&D_801379C0, arg0);
    if (flag->mode != 4) {
        func_80267198_de(arg0, arg0, 7,
                      arg0->unk_8, local);
        arg0->unk_100 |= 0x08000000;
    }
}
