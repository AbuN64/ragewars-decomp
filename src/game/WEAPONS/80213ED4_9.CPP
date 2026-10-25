#include "COMMON/REC.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

extern void Particle_SubtractVectors(CVector3 *arg0, CVector3 *arg1, CVector3 *arg2);
extern f32 Math_Sqrtf(f32);






void func_802165F8_de(Player *player, ActorMotionState *motionState, OffsetResult *result) {
    Particle_SubtractVectors(&result->first, &player->pos,
                  &motionState->position);
    result->first_normalized = result->first;
    Particle_NormalizeVec3(&result->first_normalized.x);
    result->first_length = Math_Sqrtf(
        result->first.x * result->first.x +
        result->first.y * result->first.y +
        result->first.z * result->first.z);
    result->flat.x = result->first.x;
    result->flat.y = 0.0f;
    result->flat.z = result->first.z;
    result->flat_normalized = result->flat;
    Particle_NormalizeVec3(&result->flat_normalized.x);
    result->flat_length = Math_Sqrtf(
        result->flat.x * result->flat.x +
        result->flat.y * result->flat.y +
        result->flat.z * result->flat.z);
    result->height = player->heading -
                     motionState->height;
}
