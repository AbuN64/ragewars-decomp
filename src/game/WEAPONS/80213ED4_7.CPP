#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"

void Weapons_FillDamagePacket(void *packet, s32 arg1, s32 damage, s32 radius, s32 arg4, s32 shield) {
    (((struct ObjRecAt10V2 *) ((s8 *) packet))->unk0) = arg1;
    (((struct ObjRecAt10V2 *) ((s8 *) packet))->unk4) = damage;
    (((struct ObjRecAt10V2 *) ((s8 *) packet))->unk8) = radius;
    (((struct ObjRecAt10V2 *) ((s8 *) packet))->unkC) = arg4;
    (((struct ObjRecAt10V2 *) ((s8 *) packet))->unk10) = shield;
}
