#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SELF.H"
#include "TYPES.H"
#include "AI/NAV/802106E0_14.H"

#if !(defined(VERSION_DE))
void func_802123FC_eu(void *arg0) {
    CloseAttackActor *actor = arg0;
    CloseAttackActor *level1 = actor->self;
    CloseAttackBrain *inner = level1->brain;
    s32 r1, r2;

    inner->state = 0;
    func_80209988_de(inner);

    r1 = func_802744D4_de();
    inner->timer = r1 % 4 + 0xC;

    r2 = func_802744D4_de();
    inner->pattern = r2 % 2;
}
#endif
