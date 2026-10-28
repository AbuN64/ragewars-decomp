#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/S1.H"
#include "TYPES.H"
#include "SYSTEM/80255C40_3.H"





void AnimPool_ReleasePooledEffect(struct CAnimPool *arg0, struct SceneEffect *effectNode) {
    s32 *temp_v1;

    temp_v1 = effectNode->ref;
    effectNode->angle = 0;
    if (temp_v1 != 0) {
        *temp_v1 -= 1;
    }
    func_80255ED8_de(&arg0->UsedList, effectNode);
    func_80255D14_de(&arg0->FreeList, effectNode);
}
