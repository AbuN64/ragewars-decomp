#include "include_asm.h"
#include "COMMON/SCENERECAT10C0.H"
#include "COMMON/EXTERNS_9.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/MENUSELECTIONMESSAGE.H"
#include "TYPES.H"
#include "COMMON/WORLDRECAT1B6A4.H"
#include "TYPES.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/MENULISTSCREEN.H"
#include "ACHIEVE/80437C30_2.H"
#include "RENDER_4/8028FD2C_11.H"
#include "SCENE/80286050.H"
#include "SCENE/80286050_4.H"
#include "SCENE/80286050_5.H"
#include "WEAPONS/80225D10_5.H"
#include "RENDER_4/8028FD2C_6.H"

void func_80286080_de(void *arg0) {
    Shared_World *state;
    Shared_Game *input;
    s32 old_flags;

    state = arg0;
    input = &D_801462C8;
    old_flags = D_800CD3F0;
    D_800CD3F0 = input->buttons;
    if (input->flags & 0x4000) {
        D_800CD3F0 |= 0x100;
    }
    if (input->flags & 0x8000) {
        D_800CD3F0 |= 0x200;
    }
    if (old_flags != D_800CD3F0) {
        D_800CD3F4 = 1;
        func_8025476C_de(8);
    } else {
        D_800CD3F4 = 0;
    }

    Scene_UpdateSelectionTransition(state);
    func_8028D64C_de(state);
    state->counter120 = 0;
    state->counter124 = 0;
    func_80279990_de(state->system128);
    func_80253BBC_de(0, state->resource);
    {
        void *manager;

        manager = &D_801379C0;
        func_802A56FC_de(manager);
        func_8022A170_de(&D_80145040);
        func_80287F18_de(state);
        func_80288470_de(state);
        func_8028D61C_de(state);

        if ((state->frozen == 0) && (D_80146894 == 0)) {
            func_802A5680_de(manager);
            func_80286284_de(state);
            func_80290238_de(&state->system11778);
            state->elapsed += D_800D2988 * D_800C50E4_de;
            func_8028C60C_de(state);
        }
    }

    func_80281CA0_de(state->system1B08);
    if (state->frozen == 0) {
        func_802285E8_de(&D_80145040);
    }

    func_80236F1C_de(&D_80145088, state);
    if ((state->frozen == 0) && (D_80145088.status[7] == 0)) {
        func_8028D67C_de(state);
    }
    func_8028D888_de(state);
    func_8028D108_de(state);
}



extern void func_8024BE3C_de(void *arg0);
extern void func_80246E44_de(char *);
extern s32 func_802934F8_de(void);
extern void func_80226A34_de(void *arg0);
extern s32 func_8022A68C_de(void *arg0);



extern void *func_8025CC6C_de(void);
extern void func_8025CB88_de(void *arg0);









void func_80286284_de(void *arg0) {
    s32 count;
    s32 total;
    u32 skip_mask;
    s32 *objects;
    s32 *objectp;
    void *object;
    f32 saved_delta;
    u32 flags;
    s32 object_type;
    u32 remove_mask;
    u32 remove_value;

    count = 0;
    total = ((SceneRecAt10C0 *)arg0)->count;
    objects = &((SceneRecAt10C0 *)(arg0))->objects[0];
    if (total > 0) {
        object_type = 2;
        skip_mask = 0x40000000;
        remove_mask = 0x40002000;
        remove_value = 0x2000;
        objectp = objects;
        do {
            void *next_object;

            next_object = (void *)*objectp;
            if (*((ObjectRecAt1A4 *)(next_object))->kind != object_type) {
                goto first_pass_done;
            }
            object = next_object;
            objectp++;
            flags = ((Shared_Actor *)object)->weaponFlags;
            saved_delta = D_800D2988;
            count++;
            if (!(flags & skip_mask)) {
                func_8024BE3C_de(object);
            }
            if ((((Shared_Actor *)object)->weaponFlags & remove_mask) == remove_value) {
                func_80246E44_de(object);
            }
            D_800D2988 = saved_delta;
        } while (count < total);
    }

first_pass_done:
    if (func_802934F8_de()) {
        func_80226A34_de(&D_80145040);
    }
    if (func_8022A68C_de(&D_80145040)) {
        func_8025E2D4_de(0x34);
        {
        s32 sw_mode_value = ((GlobalMode *)&D_80145040)->mode;
        if ((unsigned int)sw_mode_value > 4) {
            goto sw_mode_default;
        }
        switch (sw_mode_value) {
        case 0: goto sw_mode_0;
        case 1: goto sw_mode_1;
        case 2: goto sw_mode_0;
        case 3: goto sw_mode_1;
        case 4: goto sw_mode_1;
        }
    }
    do {
        sw_mode_0:
        sw_mode_2:
            func_8042CFB0_de();
            break;
        sw_mode_1:
        sw_mode_3:
        sw_mode_4:
            func_804389C4_de();
            break;
        
    sw_mode_default:;
    } while (0);
    }

    if (count < total) {
        objectp = (s32 *)((count * 4) + (s32)objects);
        do {
            object = (void *)*objectp;
            objectp++;
            saved_delta = D_800D2988;
            func_8024BE3C_de(object);
            count++;
            if (((Shared_Actor *)object)->weaponFlags & 0x2000) {
                func_80246E44_de(object);
            }
            D_800D2988 = saved_delta;
        } while (count < total);
    }
    func_8025CB88_de(func_8025CC6C_de());
}

INCLUDE_ASM("span_1000", func_80286454_de);

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/EXTERNS_14.H"
#include "stddef.h"
#include "TYPES.H"
f32 func_80275DD4_de(Node75 *node, f32 x, f32 z);
f32 func_8027525C_de(Node75 *node, f32 x, f32 z);
extern s32 D_800CD764_de;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x40, 0x44, 0x48, 0x4c], gap at: 0x38. */
s32 func_80286728_de(void *arg0, void *arg1) {
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv0f_3;
    f32 var_fs0f;
    f32 var_fv0;
    s32 temp_fp;
    s32 temp_s7;
    s32 var_s4;
    s32 var_s6;
    s8 *temp_v0;
    u32 var_s2;
    void *var_s0;
    void *var_s5;
    void *var_s1;

    if (D_800CD764_de == 0) {
        return 0;
    }
    var_s4 = 0;
    var_s6 = 0;
    var_fs0f = 0.0f;
    var_s5 = NULL;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fp = func_8028FDB4_de(*((s32 **) ((u8 *) (arg0) + 108)), 2) + 8;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_v0 = func_8028FDB4_de(*((s32 **) ((u8 *) (arg0) + 108)), 3);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_s7 = *((s32 *) ((u8 *) (temp_v0) + 4));
    if (temp_s7 > 0) {
        var_s1 = temp_v0 + 8;
loop_4:
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv0f = *((f32 *) ((u8 *) (arg1) + 0));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        if ((*((f32 *) ((u8 *) (var_s1) + 0)) <= temp_fv0f) && (temp_fv0f <= *((f32 *) ((u8 *) (var_s1) + 8)))) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            temp_fv0f_2 = *((f32 *) ((u8 *) (arg1) + 8));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            if ((*((f32 *) ((u8 *) (var_s1) + 4)) <= temp_fv0f_2) && (temp_fv0f_2 <= *((f32 *) ((u8 *) (var_s1) + 12)))) {
                var_s2 = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                if (*((u32 *) ((u8 *) (var_s1) + 16)) != 0) {
                    var_s0 = (var_s4 << 5) + temp_fp;
loop_10:
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    if (func_80275B10_de(var_s0, *((f32 *) ((u8 *) (arg1) + 0)), *((f32 *) ((u8 *) (arg1) + 8))) != 0) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        temp_fs0 = func_80275DD4_de(var_s0, *((f32 *) ((u8 *) (arg1) + 0)), *((f32 *) ((u8 *) (arg1) + 8)));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        if (*((u16 *) ((u8 *) (var_s0) + 2)) & 0x40) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            temp_fv0 = func_8027525C_de(var_s0, *((f32 *) ((u8 *) (arg1) + 0)), *((f32 *) ((u8 *) (arg1) + 8)));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            temp_fv0f_3 = *((f32 *) ((u8 *) (arg1) + 4));
                            if ((temp_fs0 <= temp_fv0f_3) && (temp_fv0f_3 <= temp_fv0)) {
                                return (s32) var_s0;
                            }
                            goto block_20;
                        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        var_fv0 = *((f32 *) ((u8 *) (arg1) + 4)) - temp_fs0;
                        if (var_fv0 < 0.0f) {
                            var_fv0 = -var_fv0;
                        }
                        if ((var_s5 == NULL) || (var_fv0 < var_fs0f)) {
                            var_s5 = var_s0;
                            var_fs0f = var_fv0;
                        }
                        goto block_20;
                    }
block_20:
                    var_s0 += 0x20;
                    var_s2 += 1;
                    var_s4 += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    if (var_s2 >= (u32) *((u32 *) ((u8 *) (var_s1) + 16))) {
                        var_s1 += 0x14;
                        goto block_24;
                    }
                    goto loop_10;
                }
                goto block_23;
            }
        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        var_s4 += *((u32 *) ((u8 *) (var_s1) + 16));
block_23:
        var_s1 += 0x14;
block_24:
        var_s6 += 1;
        if (var_s6 >= temp_s7) {
            goto block_25;
        }
        goto loop_4;
    }
block_25:
    return (s32) var_s5;
}
#else
INCLUDE_ASM("span_1000", func_80286728_de);
#endif
