#include "span_1000/code_802624A0.h"
#include "span_1000/code_80255BEC.h"
#include "TYPES.H"

extern void func_80255ED8_de(void *, void *);




void func_80263080_de(struct SceneEffectPool *arg0, struct SceneEffect *arg1) {
    s32 *temp_v1;

    temp_v1 = arg1->ref;
    arg1->angle = 0;
    if (temp_v1 != 0) {
        *temp_v1 -= 1;
    }
    func_80255ED8_de(&arg0->activeEffects, arg1);
    func_80255D14_de(&arg0->freeEffects, arg1);
}
