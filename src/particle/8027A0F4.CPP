#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/TRIPLE.H"
#include "particle/8027A0F4.H"
#include "FX_2/80271B18.H"
#include "particle/80271B18_3.H"

extern s32 *func_8025CC6C_de(void);
extern s32 func_8025CA24_de(void *,void *);
static inline void makeImpulse(CVector3 *input,f32 scale,CVector3 *out){func_80271F9C_de(out,input,scale);}
static inline void addImpulse(CVector3 *v,CVector3 *impulse){func_80271F34_de(v,v,impulse);}
void func_8027A084_de(void *particle) {
    SteeringParticle *arg0=particle;
    CVector3 sp18;
    CVector3 sp28;
    CVector3 sp38;
    CQuatern sp48;
    CQuatern sp58;
    CQuatern sp68;
    Matrix sp78;
    CVector3 spB8;
    CVector3 spC8;
    CVector3 *temp_s0_3;
    CVector3 *temp_s2;
    CVector3 *temp_s4;
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
    CVector3 *temp_a2;
    SteeringTarget *temp_s0;
    CVector3 *temp_s0_2;
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

INCLUDE_ASM("span_1000", func_8027A4D0_de);

#ifdef NON_MATCHING
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0xc0, 0xc4, 0xc8, 0xcc, 0xd8, 0xdc, 0xe0, 0xe4], gap at: 0xd0. */
void func_8027A948_de(void *arg0, CVector3 *arg1) {
    CVector3 sp10;
    CVector3 sp20;
    CQuatern sp30;
    CQuatern sp40;
    CQuatern sp50;
    f32 sp60[16];
    CVector3 spA0;
    CVector3 spB0;
    CVector3 *temp_s1;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fs0;
    f32 temp_fs0f;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv0f_3;
    f32 var_fv0f;
    f32 var_fv0f_2;
    s32 var_condition_bit;
    void *temp_s0;

    func_80271F68_de(&sp10, arg1, arg0 + 8);
    temp_fv0 = func_802B72B0_de((sp10.x * sp10.x) + (sp10.y * sp10.y) + (sp10.z * sp10.z));
    if (temp_fv0 <= D_800C4BA8_de) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((f32 *) ((u8 *) (arg0) + 8)) = (f32) arg1->x;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((f32 *) ((u8 *) (arg0) + 12)) = (f32) arg1->y;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((f32 *) ((u8 *) (arg0) + 16)) = (f32) arg1->z;
        return;
    }
    func_8027207C_de(&sp10.x);
    func_80271818_de(/* return */ &sp40, &sp10.x);
    func_80271818_de(/* return */ &sp30, arg0 + 0x174);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fv0f = *((f32 *) ((u8 *) (arg0) + 28));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fv0_2 = *((f32 *) ((u8 *) (arg0) + 32));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fa0 = *((f32 *) ((u8 *) (arg0) + 36));
    temp_fs0f = func_802B72B0_de((temp_fv0f * temp_fv0f) + (temp_fv0_2 * temp_fv0_2) + (temp_fa0 * temp_fa0));
    if (temp_fv0 < D_800C4BAC_de) {
        temp_fv0f_2 = temp_fv0 - D_800C4BB0_de;
        if (temp_fv0f_2 < 0.0f) {
            var_fv0f = 0.0f;
        } else {
            var_fv0f = temp_fv0f_2 * D_800C4BB4_de;
        }
        var_fv0f_2 = D_800C4BBC_de - (var_fv0f * D_800C4BB8_de);
    } else {
        var_fv0f_2 = D_800C4BC0_de;
    }
    func_80270CD0_de(&sp50, var_fv0f_2, &sp30, &sp40);
    func_80274244_de(&sp50.x, sp60);
    temp_s0 = arg0 + 0x174;
    sp20.x = 0.0f;
    sp20.y = 0.0f;
    sp20.z = D_800C4BC4_de;
    func_80272898_de(sp60, &sp20, temp_s0);
    temp_s1 = arg0 + 0x1C;
    func_80271F9C_de(temp_s1, temp_s0, temp_fs0f);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fv0_3 = func_802B2350((s32) *((u16 *) ((u8 *) (*((void **) ((u8 *) (*((void **) ((u8 *) (arg0) + 280))) + 48))) + 16)));
    if (temp_fv0_3 != 0.0f) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        spB0.x = *((f32 *) ((u8 *) (arg0) + 372));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        spB0.y = *((f32 *) ((u8 *) (arg0) + 376));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        spB0.z = *((f32 *) ((u8 *) (arg0) + 380));
        func_80271F9C_de(&spA0, &spB0, temp_fv0_3);
        func_80271F34_de(temp_s1, temp_s1, &spA0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv0f_3 = *((f32 *) ((u8 *) (arg0) + 28));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv0_4 = *((f32 *) ((u8 *) (arg0) + 32));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fa0_2 = *((f32 *) ((u8 *) (arg0) + 36));
        temp_fs0 = func_802B72B0_de((temp_fv0f_3 * temp_fv0f_3) + (temp_fv0_4 * temp_fv0_4) + (temp_fa0_2 * temp_fa0_2));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv0_5 = func_802B2350((s32) *((u16 *) ((u8 *) (*((void **) ((u8 *) (*((void **) ((u8 *) (arg0) + 280))) + 48))) + 18)));
        if (temp_fv0_3 > 0.0f) {
            var_condition_bit = temp_fv0_5 < temp_fs0;
        } else {
            var_condition_bit = temp_fs0 < temp_fv0_5;
        }
        if (var_condition_bit) {
            func_80271F9C_de(temp_s1, &spB0, temp_fv0_5);
        }
    }
    func_80279DD0_de(arg0, 1.0f);
}
#else
INCLUDE_ASM("span_1000", func_8027A948_de);
#endif
