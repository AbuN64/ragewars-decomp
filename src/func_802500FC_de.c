#include "shared/gameplay_camera.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024E914.h"
#include "types.h"



extern f32 D_800C3E50_de;
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);







s32 func_802500FC_de(void *arg0, s32 arg1) {
    Owner_func_80250274_de *owner = arg0;
    GameplayCamera *camera = (void *)arg1;
    Vec3 sp10;
    f32 temp_f0;
    f32 threshold;
    s32 var_v1;
    s8 temp_v0;
    s32 var_v1_2;
    u16 temp_v1;
    u16 var_v0;
    u8 next_timer;
    DescriptorRecAt24 *temp_a0;

    func_80271F68_de(&sp10, &camera->position,
                  &owner->position);
    temp_f0 = sp10.x * sp10.x + sp10.y * sp10.y + sp10.z * sp10.z;
    threshold = D_800C3E50_de;
    if (!(threshold <= temp_f0)) {
        var_v1 = (s32)temp_f0;
    } else {
        var_v1 = (s32)(temp_f0 - threshold) | 0x80000000;
    }
    temp_a0 = owner->descriptor;
    owner->timer = var_v1;
    if ((u32)var_v1 >= (u32)(temp_a0->period * 2)) {
        var_v1_2 = temp_a0->key2;
    } else {
        var_v1_2 = temp_a0->key;
    }

    if (var_v1_2 == -1) {
        if (owner->fade <= 0) {
            owner->fade = 0;
            owner->flagsD8 =
                owner->flagsD8 | 4;
            return 0;
        }
        temp_v1 = owner->flagsD8;
        if (temp_v1 & 0x200) {
            owner->flagsD8 = temp_v1 | 4;
            owner->fade = 0;
            return 0;
        }
        temp_v0 = (u8)owner->fade - 1;
        owner->fade = temp_v0;
        if (temp_v0 < 0) {
            owner->fade = 0;
        }
        var_v0 = owner->flagsD8 | 4;
        goto block_20;
    } else if (owner->fade < 8) {
        next_timer = (u8)owner->fade + 1;
        if (owner->flagsD8 & 0x200) {
            owner->fade = 8;
            owner->flagsD8 =
                owner->flagsD8 & 0xFFFB;
        } else {
            owner->fade =
                next_timer;
            var_v0 = owner->flagsD8 | 4;
block_20:
            owner->flagsD8 = var_v0;
        }
    } else {
        owner->fade = 8;
    }
    return 1;
}
