#include "shared/player_movement_interfaces.h"
#include "types.h"
#include "common/unused.h"
#include "common/types_06e4f7ef1f9e.h"
extern void func_80274870_de(f32 *,f32,f32);
extern void func_802231D4_de(SharedPlayer *,func_802165F8_S1 *,char *);
extern char D_800CE7E4,D_800CE7FC,D_800CED30;
extern f32 D_800D2988;
extern f32 D_800C29C0_de,D_800C29C4_de,D_800C29C8_de,D_800C29CC_de,D_800C29D0_de,D_800C29D4_de,D_800C29D8_de,D_800C29DC_de,D_800C29E0_de,D_800C29E4_de,D_800C29E8_de,D_800C29EC_de,D_800C29F0_de,D_800C29F4_de,D_800C29F8_de,D_800C29FC_de;
/* State callbacks receive an opaque actor context. */
void func_8022470C_de(void *playerContext, void *bodyContext) {
    SharedPlayer_func_802233F0_de *arg0 = playerContext;
    func_802165F8_S1 *arg1 = bodyContext;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 var_fv0f;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    char *var_a2;
    char *var_a2_2;
    u16 temp_v1;
    s32 nextAnimation;

    func_8022404C_de(playerContext);
    func_80274870_de(&arg0->views5E8.view72C_75.unk72C, 0.0f, 0.25f);
    var_v0 = 1;
    if (!(arg0->views5E8.view718_70.crouch > D_800C29C0_de)) {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        func_802231D4_de(arg0, arg1, &D_800CE7FC);
    } else {
        func_802231D4_de(arg0, arg1, &D_800CE7E4);
    }
    var_v0_2 = 1;
    if (!(arg0->views5E8.view718_70.crouch > D_800C29C4_de)) {
        var_v0_2 = 0;
    }
    if (var_v0_2 != 0) {
        func_802233F0_de(arg0, arg1, &D_800CE7C0);
    } else {
        func_802233F0_de(arg0, arg1, &D_800C94EC_de);
    }
    if ((arg0->views5E8.view7E8_105.unk7E8 == 0) && !(arg0->views5E8.view6E4_61.unk6E4 > D_800C29C8_de) && !(arg1->flags & 0xC0000) && (arg1->model->flags & 2) && (arg0->views5E8.view6B0_46.unk6B0 & 0x10) && (arg0->views5E8.view11D8_147.unk11D8 <= 0.0f)) { func_802227F4_de(arg0, arg1, 5); var_v0_3 = 1; } else var_v0_3 = 0;
    if (var_v0_3 == 0) {
        if ((arg0->views5E8.view6C0_51.unk6C0 == 0.0f) && (arg0->views5E8.view6C4_54.unk6C4 == 0.0f)) {
            func_802227F4_de(arg0, arg1, 2);
        }
        if (((arg1->flags & 0x5000) == 0x4000) && (arg0->views5E8.view6D0_71.onGround != 0)) {
            temp_fv1 = arg0->views5E8.view11C4_144.soundTime + D_800D2988;
            arg0->views5E8.view11C4_144.soundTime = temp_fv1;
            if ((arg0->views5E8.view6C8_56.unk6C8 > D_800C29CC_de) && (D_800C29D0_de <= temp_fv1)) {
                arg0->views5E8.view11C4_144.soundTime = (f32) (temp_fv1 - D_800C29D0_de);
            }
        }
        temp_v1 = arg0->views1C.viewE4_7.kind;
        if (temp_v1 == D_800CE474[2]) {
            if (arg0->views5E8.view86C_125.unk86C == 0x7DA && arg0->views1C.view104_11.idleTime >= D_800C29D4_de) arg0->views5E8.view86C_125.unk86C = 0x7DB; else arg0->views5E8.view86C_125.unk86C = 0x7DA;
            return;
        }
        if (temp_v1 == D_800CE474[0]) {
            temp_v1_2 = arg0->views5E8.view86C_125.unk86C;
            if (temp_v1_2 == 0xFA0 && arg0->views1C.view104_11.idleTime < D_800C29D8_de) return;
            if (temp_v1_2 == 0x1004 && arg0->views1C.view104_11.idleTime < D_800C29DC_de) return;
        }
        if (arg1->flags & 0xC0000) {
            if (arg0->views5E8.view6C0_51.unk6C0 >= 0.0f) arg0->views5E8.view86C_125.unk86C = 0xA32;
            else arg0->views5E8.view86C_125.unk86C = 0xA37;
            return;
        }
        var_fv0f = arg0->views5E8.view6C0_51.unk6C0;
        if (var_fv0f < 0.0f) var_fv0f = -var_fv0f;
        temp_fv0 = arg0->views5E8.view6C4_54.unk6C4;
        if (temp_fv0 < 0.0f) {
            if (var_fv0f < -temp_fv0) goto sideways;
            goto forward;
        }
        if (var_fv0f < temp_fv0) {
sideways:
            if (arg0->views5E8.view6C4_54.unk6C4 < 0.0f) {
                if (arg0->views13B4.view13B4_3.character != &D_800CED30) { arg0->views5E8.view86C_125.unk86C = 0x802; return; }
                temp_v1_3 = arg0->views5E8.view86C_125.unk86C;
                if ((u32)(temp_v1_3 - 0x5E56) < 7U) {
                    if (arg0->views1C.view104_11.idleTime >= D_800C29E0_de) arg0->views5E8.view86C_125.unk86C = 0x5E2B;
                    return;
                }
                if (temp_v1_3 == 0x5E5E) {
                    if (arg0->views1C.view104_11.idleTime >= D_800C29E4_de) arg0->views5E8.view86C_125.unk86C = 0x5E2B;
                    return;
                }
                arg0->views5E8.view86C_125.unk86C = 0x5E2B;
            } else {
                if (arg0->views13B4.view13B4_3.character != &D_800CED30) { arg0->views5E8.view86C_125.unk86C = 0x80C; return; }
                temp_v1_4 = arg0->views5E8.view86C_125.unk86C;
                if ((u32)(temp_v1_4 - 0x5E56) < 7U) {
                    if (arg0->views1C.view104_11.idleTime >= D_800C29E8_de) arg0->views5E8.view86C_125.unk86C = 0x5E2C;
                    return;
                }
                if (temp_v1_4 == 0x5E5E) {
                    if (arg0->views1C.view104_11.idleTime >= D_800C29EC_de) arg0->views5E8.view86C_125.unk86C = 0x5E2C;
                    return;
                }
                arg0->views5E8.view86C_125.unk86C = 0x5E2C;
            }
        } else {
forward:
            if (arg0->views5E8.view6C0_51.unk6C0 >= 0.0f) {
                if (arg0->views13B4.view13B4_3.character != &D_800CED30) { arg0->views5E8.view86C_125.unk86C = 0x7DA; return; }
                temp_v1_5 = arg0->views5E8.view86C_125.unk86C;
                if ((u32)(temp_v1_5 - 0x5E56) < 9U) {
                    if (arg0->views1C.view104_11.idleTime >= D_800C29F0_de) arg0->views5E8.view86C_125.unk86C = 0x5E29;
                    return;
                }
                if (temp_v1_5 == 0x5E5E) {
                    if (arg0->views1C.view104_11.idleTime >= D_800C29F4_de) arg0->views5E8.view86C_125.unk86C = 0x5E29;
                    return;
                }
                arg0->views5E8.view86C_125.unk86C = 0x5E29;
            } else {
                if (arg0->views13B4.view13B4_3.character != &D_800CED30) { arg0->views5E8.view86C_125.unk86C = 0x7DF; return; }
                temp_v1_6 = arg0->views5E8.view86C_125.unk86C;
                if ((u32)(temp_v1_6 - 0x5E56) < 7U) {
                    if (arg0->views1C.view104_11.idleTime >= D_800C29F8_de) arg0->views5E8.view86C_125.unk86C = 0x5E2A;
                    return;
                }
                nextAnimation = 0x5E5E;
                if (temp_v1_6 != nextAnimation) {
                    nextAnimation = 0x5E2A;
                    arg0->views5E8.view86C_125.unk86C = nextAnimation;
                } else {
                    nextAnimation = 0x5E2A;
                    if (arg0->views1C.view104_11.idleTime >= D_800C29FC_de) arg0->views5E8.view86C_125.unk86C = nextAnimation;
                }
            }
        }
    }
}
