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
extern void func_80274098_de(void*,void*,void*);
extern void func_80272C60_de(void *, f32, f32, f32);
extern u32 func_802337D0_de(StateRecAt10*);
extern void func_8026F620_de(f32*,f32*,f32*);
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
    Effect33920 effect;
    char padF4[0x134-0xF4];
    CVector3 cached;
    Rotation rotation,combined;
    f32 matrix[16];
} TransformActor;
typedef struct TransformWorld {
    s32 identifier;
    char pad4[0x11AC-4];
    Effect33920 *effects;
} TransformWorld;

void func_802349C0_de(void *arg0) {
    TransformActor *actor=arg0;
    Rotation q18,q28,q38,q48,q58;
    f32 m68[16],mA8[16],mE8[16],m128[16],m168[16],m1A8[16];
    CVector3 sp1E8,result,transformed;
    f32 zero,cosineInput;
    Effect33920 *effect;
    f32 *temp_s3;
    f32 *matrix;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0f;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0_6;
    f32 var_fs1;
    f32 var_fs1f;
    void *temp_s0;

    if (actor->enabled != 0) {
        var_fs1 = actor->pitch;
        var_fs1f = actor->roll;
        if (func_80245798_de() == 0) {
            func_80239EA4_de(arg0, &sp1E8);
            var_fs1f += sp1E8.z;
            temp_fs0f = D_800C31F8_de;
            temp_fs0 = var_fs1f * temp_fs0f;
            var_fs1 += sp1E8.x;
            temp_fv0 = func_802B7130_de(temp_fs0);
            temp_fs0_2 = var_fs1 * temp_fs0f;
            D_80115DEC = temp_fv0;
            q38.word[0] = 0;
            q38.word[1] = 0;
            q38.f[2] = temp_fv0;
            q38.f[3] = func_802B6560_de(temp_fs0);
            temp_fv0_2 = func_802B7130_de(temp_fs0_2);
            D_80115DEC = temp_fv0_2;
            q18.f[0] = temp_fv0_2;
            q18.word[1] = 0;
            q18.word[2] = 0;
            q18.f[3] = func_802B6560_de(temp_fs0_2);
            temp_s0 = actor->combined.f;
            temp_fv0_3 = func_802B7130_de((actor->yaw + actor->extraYaw) * temp_fs0f);
            q28.word[0] = 0;
            q28.f[1] = temp_fv0_3;
            q28.word[2] = 0;
            cosineInput = ((actor->yaw + actor->extraYaw) * temp_fs0f);
            D_80115DEC = temp_fv0_3;
            temp_s3 = actor->base.f;
            q28.f[3] = func_802B6560_de(cosineInput);
            func_80274098_de(q48.f, q18.f, q28.f);
            func_80274098_de(temp_s0, q48.f, temp_s3);
            func_80274098_de(actor->rotation.f, q38.f, temp_s0);
            func_80274098_de(q58.f, q38.f, q48.f);
            func_80274244_de(q58.f, m68);
            zero=0.0f;
            func_80272C60_de(mA8, zero, actor->height, zero);
            func_80274244_de(temp_s3, mE8);
            result.x = zero;
            result.y = zero;
            result.z = zero;
            func_80233930_de(&actor->effect, actor->effect.origin, &result);
            func_802337D0_de(&actor->effect.x);
            func_802337D0_de(&actor->effect.y);
            func_802337D0_de(&actor->effect.z);
            if (arg0 != &D_80141008) {
                effect = ((TransformWorld*)(void*)&D_80141008)->effects;
                if (effect != 0) {
                    do {
                        func_80233930_de(effect, actor->position.value, &result);
                        effect = effect->next;
                    } while (effect != 0);
                }
            }
            func_8026F620_de(m168, m68, mE8);
            Particle_TransformPoint(m168, &result, &transformed);
            func_8026F620_de(m168, m68, mA8);
            matrix = m1A8;
            func_8026F620_de(matrix, m168, mE8);
            func_80272C60_de(m128,
                actor->position.value.x + transformed.x,
                actor->position.value.y + sp1E8.y + transformed.y,
                actor->position.value.z + transformed.z);
            func_8026F620_de(actor->matrix, matrix, m128);
        } else {
            cosineInput = actor->roll;
            temp_fs0_3 = D_800C31FC_de;
            temp_fv0_4 = func_802B7130_de(cosineInput * temp_fs0_3);
            q38.word[0] = 0;
            q38.word[1] = 0;
            q38.f[2] = temp_fv0_4;
            cosineInput = (actor->roll * temp_fs0_3);
            D_80115DEC = temp_fv0_4;
            q38.f[3] = func_802B6560_de(cosineInput);
            temp_fv0_5 = func_802B7130_de(actor->pitch * temp_fs0_3);
            q18.f[0] = temp_fv0_5;
            q18.word[1] = 0;
            q18.word[2] = 0;
            cosineInput = (actor->pitch * temp_fs0_3);
            D_80115DEC = temp_fv0_5;
            q18.f[3] = func_802B6560_de(cosineInput);
            temp_fv0_6 = func_802B7130_de((actor->yaw + actor->extraYaw) * temp_fs0_3);
            q28.word[0] = 0;
            q28.f[1] = temp_fv0_6;
            q28.word[2] = 0;
            cosineInput = ((actor->yaw + actor->extraYaw) * temp_fs0_3);
            D_80115DEC = temp_fv0_6;
            q28.f[3] = func_802B6560_de(cosineInput);
            func_80274098_de(q48.f, q18.f, q28.f);
            actor->combined=q48;
            func_80274098_de(actor->rotation.f, q38.f, actor->combined.f);
            func_80274244_de(q48.f, m68);
            func_80272C60_de(m128,actor->position.value.x,actor->position.value.y,actor->position.value.z);
            func_8026F620_de(actor->matrix, m68, m128);
        }

        actor->cached.x = var_fs1;
        actor->cached.z = var_fs1f;
        actor->cached.y = (f32) actor->yaw;
    }
}
