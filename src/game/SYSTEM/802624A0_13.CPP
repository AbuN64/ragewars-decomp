#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "SYSTEM/80255C40_7.H"





void AnimPool_ReleasePooledEffect(struct SceneEffectPool *arg0, struct SceneEffect *arg1) {
    s32 *temp_v1;

    temp_v1 = arg1->ref;
    arg1->angle = 0;
    if (temp_v1 != 0) {
        *temp_v1 -= 1;
    }
    func_80255ED8_de(&arg0->UsedList, arg1);
    func_80255D14_de(&arg0->FreeList, arg1);
}
