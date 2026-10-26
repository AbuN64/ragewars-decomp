#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "WEAPONS/80213ED4_19.H"

void Barrel_AddActorYaw(void *arg0, f32 arg1) {
    (((struct func_80203908_S4 *) ((s8 *) arg0))->unk6C) = (f32) ((((struct func_80203908_S4 *) ((s8 *) arg0))->unk6C) + arg1);
    ((s32 (*)(void *))func_80274020_de)(arg0 + 0x6C);
}
