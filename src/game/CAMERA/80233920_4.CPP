#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/STATERECAT10.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/OBJ.H"
#include "COMMON/TRIPLE.H"
#include "CAMERA/80233920.H"
#include "CAMERA/80233920_31.H"
#include "particle/80271B18_3.H"

extern s32 D_80141008;
extern void MultiplyQuaternions(void*,void*,void*);
extern void GraphU64_BuildTranslationMatrix(void *, f32, f32, f32);
extern u32 Weapon_UpdateShakeAxis(CShakeAxis*);
extern void GraphU64_MultiplyAffineMatrices(f32*,f32*,f32*);
/* The camera position is passed as a three-word CVector3 value. */

/* Actor transform and camera-effect subobjects. */
typedef struct TransformActor {
    char pad0[0x28];
    f32 yaw,pitch,extraYaw,roll;
    TransformVector position;
    f32 height;
    Rotation base;
    char pad58[0x7C-0x58];
    s32 enabled;
    char pad80[0xA0-0x80];
    CShake effect;
    char padF4[0x134-0xF4];
    CVector3 cached;
    Rotation rotation,combined;
    f32 matrix[16];
} TransformActor;
typedef struct TransformWorld {
    s32 identifier;
    char pad4[0x11AC-4];
    CShake *effects;
} TransformWorld;

void Camera_BuildShakenViewTransform(void *cameraTransform) {
    TransformActor *actor=cameraTransform;
    Rotation q18,q28,q38,q48,q58;
    f32 m68[16],mA8[16],mE8[16],m128[16],m168[16],m1A8[16];
    CVector3 viewMotionOffsets,result,transformed;
    f32 zero,cosineInput;
    CShake *effect;
    f32 *baseQuaternion;
    f32 *matrix;
    f32 rollHalfAngle;
    f32 pitchHalfAngle;
    f32 sequenceAngleScale;
    f32 gameplayAngleScale;
    f32 rollHalfSine;
    f32 pitchHalfSine;
    f32 yawHalfSine;
    f32 sequenceRollHalfSine;
    f32 sequencePitchHalfSine;
    f32 sequenceYawHalfSine;
    f32 adjustedPitch;
    f32 adjustedRoll;
    void *combinedQuaternion;

    if (actor->enabled != 0) {
        adjustedPitch = actor->pitch;
        adjustedRoll = actor->roll;
        if (Cinema_IsSequenceInWindow() == 0) {
            func_80239EA4_de(cameraTransform, &viewMotionOffsets);
            adjustedRoll += viewMotionOffsets.z;
            gameplayAngleScale = D_800C31F8_de;
            rollHalfAngle = adjustedRoll * gameplayAngleScale;
            adjustedPitch += viewMotionOffsets.x;
            rollHalfSine = Math_Sinf(rollHalfAngle);
            pitchHalfAngle = adjustedPitch * gameplayAngleScale;
            D_80115DEC = rollHalfSine;
            q38.word[0] = 0;
            q38.word[1] = 0;
            q38.f[2] = rollHalfSine;
            q38.f[3] = Math_Cosf(rollHalfAngle);
            pitchHalfSine = Math_Sinf(pitchHalfAngle);
            D_80115DEC = pitchHalfSine;
            q18.f[0] = pitchHalfSine;
            q18.word[1] = 0;
            q18.word[2] = 0;
            q18.f[3] = Math_Cosf(pitchHalfAngle);
            combinedQuaternion = actor->combined.f;
            yawHalfSine = Math_Sinf((actor->yaw + actor->extraYaw) * gameplayAngleScale);
            q28.word[0] = 0;
            q28.f[1] = yawHalfSine;
            q28.word[2] = 0;
            cosineInput = ((actor->yaw + actor->extraYaw) * gameplayAngleScale);
            D_80115DEC = yawHalfSine;
            baseQuaternion = actor->base.f;
            q28.f[3] = Math_Cosf(cosineInput);
            MultiplyQuaternions(q48.f, q18.f, q28.f);
            MultiplyQuaternions(combinedQuaternion, q48.f, baseQuaternion);
            MultiplyQuaternions(actor->rotation.f, q38.f, combinedQuaternion);
            MultiplyQuaternions(q58.f, q38.f, q48.f);
            MatrixFromQuaternion(q58.f, m68);
            zero=0.0f;
            GraphU64_BuildTranslationMatrix(mA8, zero, actor->height, zero);
            MatrixFromQuaternion(baseQuaternion, mE8);
            result.x = zero;
            result.y = zero;
            result.z = zero;
            Camera_AccumulateDistanceScaledShake(&actor->effect, actor->effect.m_vPos, &result);
            Weapon_UpdateShakeAxis(&actor->effect.x);
            Weapon_UpdateShakeAxis(&actor->effect.y);
            Weapon_UpdateShakeAxis(&actor->effect.z);
            if (cameraTransform != &D_80141008) {
                effect = ((TransformWorld*)(void*)&D_80141008)->effects;
                if (effect != 0) {
                    do {
                        Camera_AccumulateDistanceScaledShake(effect, actor->position.value, &result);
                        effect = effect->next;
                    } while (effect != 0);
                }
            }
            GraphU64_MultiplyAffineMatrices(m168, m68, mE8);
            GraphU64_TransformPoint(m168, &result, &transformed);
            GraphU64_MultiplyAffineMatrices(m168, m68, mA8);
            matrix = m1A8;
            GraphU64_MultiplyAffineMatrices(matrix, m168, mE8);
            GraphU64_BuildTranslationMatrix(m128,
                actor->position.value.x + transformed.x,
                actor->position.value.y + viewMotionOffsets.y + transformed.y,
                actor->position.value.z + transformed.z);
            GraphU64_MultiplyAffineMatrices(actor->matrix, matrix, m128);
        } else {
            cosineInput = actor->roll;
            sequenceAngleScale = D_800C31FC_de;
            sequenceRollHalfSine = Math_Sinf(cosineInput * sequenceAngleScale);
            q38.word[0] = 0;
            q38.word[1] = 0;
            q38.f[2] = sequenceRollHalfSine;
            cosineInput = (actor->roll * sequenceAngleScale);
            D_80115DEC = sequenceRollHalfSine;
            q38.f[3] = Math_Cosf(cosineInput);
            sequencePitchHalfSine = Math_Sinf(actor->pitch * sequenceAngleScale);
            q18.f[0] = sequencePitchHalfSine;
            q18.word[1] = 0;
            q18.word[2] = 0;
            cosineInput = (actor->pitch * sequenceAngleScale);
            D_80115DEC = sequencePitchHalfSine;
            q18.f[3] = Math_Cosf(cosineInput);
            sequenceYawHalfSine = Math_Sinf((actor->yaw + actor->extraYaw) * sequenceAngleScale);
            q28.word[0] = 0;
            q28.f[1] = sequenceYawHalfSine;
            q28.word[2] = 0;
            cosineInput = ((actor->yaw + actor->extraYaw) * sequenceAngleScale);
            D_80115DEC = sequenceYawHalfSine;
            q28.f[3] = Math_Cosf(cosineInput);
            MultiplyQuaternions(q48.f, q18.f, q28.f);
            actor->combined=q48;
            MultiplyQuaternions(actor->rotation.f, q38.f, actor->combined.f);
            MatrixFromQuaternion(q48.f, m68);
            GraphU64_BuildTranslationMatrix(m128,actor->position.value.x,actor->position.value.y,actor->position.value.z);
            GraphU64_MultiplyAffineMatrices(actor->matrix, m68, m128);
        }

        actor->cached.x = adjustedPitch;
        actor->cached.z = adjustedRoll;
        actor->cached.y = (f32) actor->yaw;
    }
}
