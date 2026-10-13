#include "types.h"
#include "common/types_06e4f7ef1f9e.h"
#include "shared/gameplay_movement.h"
#include "shared/func_80425674_de_layout.h"
extern char D_800CED30;
extern const f32 D_800C2A64_de;
extern const f32 D_800C2A68_de;
s32 func_8024E62C_de(void *);
s32 func_802227F4_de(void *, void *, s32);
s32 func_8025DE54_de(s32, Vec3, s32, s32);
void func_80274870_de(f32 *, f32, f32);
void func_802251DC_de(SharedPlayer *player, SharedPlayer *body) {
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0_4;
    f32 temp_fs0_5;
    f32 temp_fs0_6;
    f32 temp_fv0;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv0f_3;
    f32 temp_fv0f_4;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1f;
    f32 temp_fv1f_2;
    f32 var_a1;
    f32 var_a2;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv0_3;
    f32 var_fv0_4;
    f32 var_fv0_5;
    f32 var_fv0f;
    f32 var_fv0f_2;
    s32 var_a0;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;

    if (!(body->views1C.view38_3.flags & 0x100)) {
        player->views5E8.view724_72.pitch = 0.0f;
        player->turnAccumulator = 0.0f;
        if (func_8024E62C_de(body) == 0) {
            temp_fs0 = D_800C2A58_de;
            player->views5E8.view6E8_79.unk6E8.x -= func_802B7130_de(body->views1C.view6C_5.heading) * temp_fs0;
            player->views5E8.view6E8_79.unk6E8.z -= func_802B6560_de(body->views1C.view6C_5.heading) * temp_fs0;
        }
        func_802227F4_de(player, body, 5);
        return;
    }
    temp_fv0 = player->views5E8.view69C_39.unk69C;
    if ((D_800C2A5C_de < temp_fv0) || (temp_fv0 < D_800C2A5C_de)) {
        player->turnAccumulator += temp_fv0 * D_800C2A60_de;
    }
    temp_fv0 = player->turnAccumulator;
    var_fv0f = D_800C2A64_de;
    if (var_fv0f < temp_fv0) player->turnAccumulator = var_fv0f;
    else if (temp_fv0 < D_800C2A68_de) player->turnAccumulator=D_800C2A68_de;
    func_80274870_de(&player->views5E8.view728_73.unk728, player->turnAccumulator * D_800C2A6C_de, 0.5f);
    var_fv0f_2 = -player->views5E8.view69C_39.pitchInput * D_800C2A70_de;
    var_fv0 = D_800C2A74_de;
    if ((var_fv0f_2 < var_fv0) || (var_fv0 = D_800C2A78_de, (var_fv0 < var_fv0f_2))) {
        var_fv0f_2 = var_fv0;
    }
    func_80274870_de(&player->views5E8.view724_72.pitch, var_fv0f_2 * D_800C2A7C_de, 0.0625f);
    if ((player->views5E8.view7E8_105.unk7E8 == 0) && !(player->views5E8.view6E4_61.unk6E4 > D_800C2A80_de) && !(body->views1C.view38_3.flags & 0xC0000) && (body->views18.view18_2.model->flags & 2) && (player->views5E8.view6B0_46.unk6B0 & 0x10) && (player->views5E8.view11D8_147.unk11D8 <= 0.0f)) { func_802227F4_de(player, body, 5); var_v0 = 1; } else var_v0 = 0;
    if (var_v0 != 0) {
        temp_fv0f = body->views1C.view6C_5.heading + player->views5E8.view728_73.unk728;
        body->views1C.view6C_5.heading = temp_fv0f;
        temp_fv1 = player->views5E8.view728_73.unk728;
        if (D_800C2A84_de <= temp_fv1) {
            var_fv0_2 = temp_fv0f + D_800C2A88_de;
            goto block_25;
        }
        if (temp_fv1 <= D_800C2A8C_de) {
            var_fv0_2 = temp_fv0f - D_800C2A90_de;
block_25:
            body->views1C.view6C_5.heading = var_fv0_2;
        }
        temp_fs0_2 = D_800C2A94_de;
        temp_fs0_3 = func_802B7130_de(body->views1C.view6C_5.heading + temp_fs0_2);
        temp_fv0 = func_802B6560_de(body->views1C.view6C_5.heading + temp_fs0_2);
        body->views1C.view1C_0.localDisplacement.x += temp_fs0_3 * D_800C2A98_de;
        body->views1C.view1C_0.localDisplacement.z += temp_fv0 * D_800C2A98_de;
        temp_fv0f_3 = player->views5E8.view728_73.unk728;
        if (D_800C2A9C_de <= temp_fv0f_3) {
            var_fv0_3 = body->views1C.view6C_5.heading + D_800C2AA0_de;
            goto block_30;
        }
        if (temp_fv0f_3 <= D_800C2AA4_de) {
            var_fv0_3 = body->views1C.view6C_5.heading - D_800C2AA8_de;
block_30:
            body->views1C.view6C_5.heading = var_fv0_3;
        }
        player->views5E8.view728_73.unk728 = 0.0f;
        player->turnAccumulator = 0.0f;
        return;
    }
    temp_fv1_2 = player->views5E8.view6DC_60.strideSign * player->views5E8.view6C0_51.unk6C0 * func_802B7130_de(player->views5E8.view658_23.stride * D_800C2AAC_de);
    temp_fv1f = player->views5E8.view6A8_44.lift;
    if (temp_fv1f > 0.0f || temp_fv1f < 0.0f)
        func_80274870_de(&player->views5E8.view72C_75.unk72C, temp_fv1_2, 0.25f);
    else func_80274870_de(&player->views5E8.view72C_75.unk72C, 0.0f, 0.9f);
    temp_fv1_3 = player->views5E8.view6A8_44.lift;
    var_v1 = temp_fv1_3 > 0.0f;
    var_v0_2 = temp_fv1_3 < 0.0f;
    temp_fs0_4 = player->views5E8.view6C0_51.unk6C0;
    if ((var_v1 != 0) || (var_v0_2 != 0)) {
        var_a1 = temp_fv1_3 * D_800C2AB0_de;
        if (temp_fv1_3 < 0.0f) {
            var_fv0_4 = -temp_fv1_3 * D_800C2AB4_de;
        } else {
            var_fv0_4 = temp_fv1_3 * D_800C2AB8_de;
        }
        player->views5E8.view6C0_51.unk6C0 = func_802746A0_de(player->views5E8.view6C0_51.unk6C0, var_a1, var_fv0_4);
    } else {
        player->views5E8.view6C0_51.unk6C0 = func_802747A0_de(temp_fs0_4, D_800C2ABC_de);
    }
    temp_fv1_4 = player->views5E8.view6A4_42.strafe;
    if (temp_fv1_4 != 0.0f) {
        var_a2 = temp_fv1_4 * D_800C2AC0_de;
        if (temp_fv1_4 < 0.0f) {
            var_fv0_5 = -temp_fv1_4 * D_800C2AC4_de;
        } else {
            var_fv0_5 = temp_fv1_4 * D_800C2AC8_de;
        }
        player->views5E8.view6C4_54.unk6C4 = func_802746A0_de(player->views5E8.view6C4_54.unk6C4, var_a2, var_fv0_5);
    } else {
        player->views5E8.view6C4_54.unk6C4 = func_802747A0_de(player->views5E8.view6C4_54.unk6C4, D_800C2ACC_de);
    }
    if ((player->views5E8.view6C0_51.unk6C0 == 0.0f) && (player->views5E8.view6C4_54.unk6C4 == 0.0f)) {
        player->views5E8.view658_23.stride = 0.0f;
        if (temp_fs0_4 != 0.0f) {
            player->views5E8.view6DC_60.strideSign = -player->views5E8.view6DC_60.strideSign;
        }
    } else {
        temp_fv1f_2 = player->views5E8.view658_23.stride;
        if (D_800C2AD0_de < temp_fv1f_2) {
            player->views5E8.view6DC_60.strideSign = -player->views5E8.view6DC_60.strideSign;
            player->views5E8.view658_23.stride = temp_fv1f_2 - D_800C2AD0_de;
            player->views5E8.view6C0_51.unk6C0 *= D_800C2AD4_de;
            player->views5E8.view6C4_54.unk6C4 *= D_800C2AD4_de;
            if ((D_801462C8.local != 0) && ((player->views5D8.view5D8_9.profile->remote != 1) || (D_801462C8.unk62C == 0))) {
                temp_v1 = player->views1C.view38_3.flags;
                if (temp_v1 & 0x200) {
                    func_8025DE54_de(D_800C9FD6, body->views0.view8_4.position, 0, -1);
                } else if (temp_v1 & 0x400) {
                    func_8025DE54_de(D_800C9FDA, body->views0.view8_4.position, 0, -1);
                } else if (temp_v1 & 0x800) {
                    func_8025DE54_de(D_800C9FDE, body->views0.view8_4.position, 0, -1);
                } else {
                    func_8025DE54_de(strideSound(player->views5DC.view5E0_10.slot), body->views0.view8_4.position, 0, -1);
                }
            }
        }
    }
    temp_fs0_5 = D_800C2AD8_de;
    temp_fs0_6 = func_802B7130_de(body->views1C.view6C_5.heading - temp_fs0_5);
    temp_fv0 = func_802B6560_de(body->views1C.view6C_5.heading - temp_fs0_5);
    player->views5E8.view6E8_79.unk6E8.x += temp_fs0_6 * player->views5E8.view6C4_54.unk6C4 * player->views5E8.view66C_29.unk66C;
    player->views5E8.view6E8_79.unk6E8.z += temp_fv0 * player->views5E8.view6C4_54.unk6C4 * player->views5E8.view66C_29.unk66C;
    player->views5E8.view6E8_79.unk6E8.y += player->views5E8.view6C0_51.unk6C0 * (D_800D2988 * D_800C2ADC_de);
    var_v0_3 = 0xA46;
    if (player->views1C.viewE4_7.kind != D_800CE47C) {
        if (player->views5E8.view6C0_51.unk6C0 > 0.0f) {
            var_v0_3 = 0xA46;
            if (player->views13B4.view13B4_3.character == &D_800CED30) {
                var_v0_3 = 0x5E28;
            }
        } else {
            var_v0_3 = 0xA3C;
            if (player->views13B4.view13B4_3.character == &D_800CED30) {
                var_v0_3 = 0x5E27;
            }
        }
    }
    player->views5E8.view86C_125.unk86C = var_v0_3;
}