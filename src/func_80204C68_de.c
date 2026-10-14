#include "shared/level_actor.h"
#include "span_1000/code_80206258.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80203F04.h"
#include "types.h"






extern char D_801379C0;

extern void func_80285DB0_de(void *, void *, s32);
extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);
extern void func_802A5D38_de(void *, s32);
extern void func_80267198_de(void *, void *, s32, Vec3, ResourceManagerState);






void func_80204C68_de(void *arg0, void *arg1) {
    ResourceManagerState local;
    Shared_World *flag;

    local.active = 0;
    flag = &D_8011FE88;
    func_80285DB0_de(flag, arg0, 1);
    func_80278D78_de(arg0, 0x4000, arg0);
    ((ActorMotionState *)arg1)->speed = 0;
    func_802A5D38_de(&D_801379C0, arg0);
    if (flag->mode != 4) {
        func_80267198_de(arg0, arg0, 6,
                      ((LevelActor *)arg0)->position0, local);
        ((LevelActor *)arg0)->flags |= 0x08000000;
    }
}
