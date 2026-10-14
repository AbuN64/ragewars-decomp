#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "packed_float.h"
#include "resident_event_handler.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_1000/code_8027A0F4.h"
#include "span_C76B0/data.h"
extern s32 *func_8025CC6C_de(void);
extern s32 func_8025CA24_de(void *,void *);
static inline void makeImpulse(Vec3 *input,f32 scale,Vec3 *out){func_80271F9C_de(out,input,scale);}
static inline void addImpulse(Vec3 *v,Vec3 *impulse){func_80271F34_de(v,v,impulse);}
void func_8027A084_de(void *particle) {
    SteeringParticle *arg0=particle;
    Vec3 sp18;
    Vec3 sp28;
    Vec3 sp38;
    Vector4f sp48;
    Vector4f sp58;
    Vector4f sp68;
    Matrix sp78;
    Vec3 spB8;
    Vec3 spC8;
    Vec3 *temp_s0_3;
    Vec3 *temp_s2;
    Vec3 *temp_s4;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv0f_3;
    f32 var_fs0;
    
    s32 var_condition_bit;s32 id;
    Vec3 *temp_a2;
    SteeringTarget *temp_s0;
    Vec3 *temp_s0_2;
    SteeringSound *temp_v1;

    if (arg0->flags & 0x10000) {
        if (arg0->sound != 0) {
            func_8025CA24_de(func_8025CC6C_de(), arg0->sound);
            arg0->sound = 0;
        }
    } else {
        id=0x730;temp_v1 = arg0->sound;
        if (temp_v1 != 0) {
            if ((temp_v1->id != id) || (temp_v1->handle == -1)) {
                func_80284434_de(arg0);
                goto block_7;
            }
        } else {
block_7:
            arg0->sound = func_8025C95C_de(func_8025CC6C_de(), 0x730, &arg0->position, &arg0->position, -1);
        }
        temp_s0 = arg0->target;
        if ((temp_s0 != 0) && (arg0->time > D_800C4B4C_de)) {
            temp_s2 = &arg0->direction;
            func_80271818_de(&sp48, temp_s2);
            temp_fv0f = arg0->velocity.x;
            temp_fv0 = arg0->velocity.y;
            temp_fa0 = arg0->velocity.z;
            temp_fv0_2 = func_802B72B0_de((temp_fv0f * temp_fv0f) + (temp_fv0 * temp_fv0) + (temp_fa0 * temp_fa0));
            
            sp18 = temp_s0->position;
            func_80271F68_de(&sp28, &sp18, &arg0->position);
            var_fs0 = func_802B72B0_de((sp28.x * sp28.x) + (sp28.y * sp28.y) + (sp28.z * sp28.z));
            if (var_fs0 < D_800C4B50_de) {
                func_80271818_de(&sp68, &sp28);
                func_80274244_de(&sp68.x, sp78.m);
                sp38.x = 0;
                sp38.y = 0;
                sp38.z = D_800C4B54_de;
                func_80272898_de(&sp78, &sp38, temp_s2);
                func_80271F9C_de(&arg0->velocity, temp_s2, temp_fv0_2);
                return;
            }
            if (D_800C4B58_de < var_fs0) {
                sp18.y += D_800C4B50_de;
                func_80271F68_de(&sp28, &sp18, &arg0->position);
                var_fs0 = func_802B72B0_de((sp28.x * sp28.x) + (sp28.y * sp28.y) + (sp28.z * sp28.z));
            }
            func_8027207C_de(&sp28.x);
            func_80271818_de(&sp58, &sp28);
            if (var_fs0 < D_800C4B5C_de) {
                temp_fv0f_2 = var_fs0 - D_800C4B60_de;
                if (temp_fv0f_2 < 0.0f) {
                    var_fs0 = 0.0f;
                } else {
                    var_fs0 = temp_fv0f_2 * D_800C4B64_de;
                }
                var_fs0 = D_800C4B6C_de - (var_fs0 * D_800C4B68_de);
            } else {
                var_fs0 = D_800C4B70_de;
            }
            func_802741A4_de(&sp58.x);
            func_802741A4_de(&sp48.x);
            func_80270CD0_de(&sp68, var_fs0, &sp48, &sp58);
            func_80274244_de(&sp68.x, sp78.m);
            temp_s0_2 = &arg0->direction;
            sp38.x = 0;
            sp38.y = 0;
            sp38.z = D_800C4B74_de;
            func_80272898_de(&sp78, &sp38, temp_s0_2);
            func_80271F9C_de(&arg0->velocity, temp_s0_2, temp_fv0_2);
            goto block_21;
        }
block_21:
        temp_fv0_3 = func_802B2350((s32) arg0->descriptor->motion->acceleration);
        if (temp_fv0_3 != 0.0f) {
            spC8 = arg0->direction;
            makeImpulse(&spC8,temp_fv0_3,&spB8);
            addImpulse(&arg0->velocity,&spB8);
            temp_s0_3=&arg0->velocity;
            temp_fv0f_3 = arg0->velocity.x;
            temp_fv0_4 = arg0->velocity.y;
            temp_fa0_2 = arg0->velocity.z;
            temp_fs0 = func_802B72B0_de((temp_fv0f_3 * temp_fv0f_3) + (temp_fv0_4 * temp_fv0_4) + (temp_fa0_2 * temp_fa0_2));
            temp_fv0_5 = func_802B2350((s32) arg0->descriptor->motion->speed);
            if (temp_fv0_3 > 0.0f) {if (!(temp_fv0_5 < temp_fs0)) goto after_clamp;} else {if (!(temp_fs0 < temp_fv0_5)) goto after_clamp;}
            func_80271F9C_de(temp_s0_3, &spC8, temp_fv0_5);
            after_clamp:;
        }
        func_80279DD0_de(arg0, 1.0f);
    }
}
