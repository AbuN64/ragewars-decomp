#include "span_1000/code_80286050.h"
#include "shared/func_80286080_de_closed.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042BD40.h"
#include "span_16E000/code_804379C8.h"
#include "types.h"
#include "span_1000/code_8028B64C.h"

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

    func_8028A698_de(state);
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
    total = ((Scene_func_8028B028_de *)arg0)->count;
    objects = &((Scene_func_8028B028_de *)(arg0))->objects[0];
    if (total > 0) {
        object_type = 2;
        skip_mask = 0x40000000;
        remove_mask = 0x40002000;
        remove_value = 0x2000;
        objectp = objects;
        do {
            void *next_object;

            next_object = (void *)*objectp;
            if (*((Object_func_8028CAE0_de *)(next_object))->kind != object_type) {
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
