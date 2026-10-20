#include "COMMON/REC.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

extern void func_80271F68_de(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2);
extern f32 func_802B72B0_de(f32);






void func_802165F8_de(Player *arg0, ActorMotionState *arg1, OffsetResult *result) {
    func_80271F68_de(&result->first, &arg0->pos,
                  &arg1->position);
    result->first_normalized = result->first;
    func_8027207C_de(&result->first_normalized.x);
    result->first_length = func_802B72B0_de(
        result->first.x * result->first.x +
        result->first.y * result->first.y +
        result->first.z * result->first.z);
    result->flat.x = result->first.x;
    result->flat.y = 0.0f;
    result->flat.z = result->first.z;
    result->flat_normalized = result->flat;
    func_8027207C_de(&result->flat_normalized.x);
    result->flat_length = func_802B72B0_de(
        result->flat.x * result->flat.x +
        result->flat.y * result->flat.y +
        result->flat.z * result->flat.z);
    result->height = arg0->heading -
                     arg1->height;
}
