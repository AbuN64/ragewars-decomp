#include "common/types_8fd754e1e915.h"
#include "shared/level_actor.h"
#include "shared/gameplay_transition.h"
#include "span_1000/code_8024D018.h"
#include "span_1000/code_80204E78.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022C894.h"
#include "types.h"
#include "common/unused.h"
#include "span_C76B0/data.h"

extern s32 D_8013B2BC;
extern AudioState D_801468A0;

extern u8 *func_8024E6A0_de(void *arg0);
extern void func_8024E6D8_de(u8 *arg0, Vec3 *arg1);














void func_8022CA14_de(void *arg0, void *arg1) {
    Vec3 vector;
    f32 scale;
    u8 *result;
    u8 state;
    s32 mode;
    AudioState *audio;

    scale = D_800C2D60_de;
    if (D_8013B2BC == 0x1DB1) {
        scale = D_800C2D64_de;
    }
    ((LevelActor *)arg1)->position1.y =
        scale * ((Resource_u1 *)((LevelActor *)arg1)->definition)->value20;
    result = func_8024E6A0_de(arg1);
    if (result != 0) {
        func_8024E6D8_de(result, &vector);
        func_80271F34_de(&((LevelActor *)arg1)->position1,
                      &((LevelActor *)arg1)->position1, &vector);
    }

    state = ((Shared_ControlView *)((Player *)arg0)->profile)->transientFlag;
    if (state == 1) {
        audio = &D_801468A0;
        if (audio->active != 0) {
            mode = audio->mode;
            switch (mode) {
        case 0:
            func_8025DE54_de(0x18A1,
                          ((Player *)arg0)->pos,
                          (s32)&((Player *)arg0)->pos, -1);
            break;
        case 1:
            func_8025DE54_de(0x1969,
                          ((Player *)arg0)->pos,
                          (s32)&((Player *)arg0)->pos, -1);
            break;
        case 2:
            func_8025DE54_de(0x1905,
                          ((Player *)arg0)->pos,
                          (s32)&((Player *)arg0)->pos, -1);
            break;
            }
        }
    }
}

/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */

extern void func_802227F4_de(void *, void *, s32);









extern s32 D_8013B2BC;













void func_8022CB5C_de(void *arg0, void *arg1) {
    f32 scale;

    scale = D_800C2D68_de;
    if (D_8013B2BC == 0x1DB1) {
        scale = D_800C2D6C_de;
    }
    if (((Player *)arg0)->computer != 0) {
        f32 current;

        current = ((Player *)arg0)->poseTimer;
        if (D_800C2D70_de <= current) {
            goto transition;
        }
        goto scale_value;
    }
    if (!(((Player *)arg0)->inputFlags & 0x10)) {
        goto transition;
    } else {
        f32 current;

        current = ((Player *)arg0)->poseTimer;
        if (!(D_800C2D74_de <= current)) {
            goto scale_value;
        }
    }
transition:
    func_802227F4_de(arg0, arg1, 6);
    goto finish;
scale_value:
    ((LevelActor *)arg1)->position1.y =
        scale * ((Resource_u1 *)((LevelActor *)arg1)->definition)->value20;
finish:
    func_8022CC34_de(arg0, arg1);
}

extern void func_80274870_de(f32 *value, f32 target, f32 rate);
extern void func_802231D4_de(s32, s32, void *);
extern void func_802233F0_de(s32 arg0, s32 arg1, void *arg2);
extern s32 func_8024E62C_de(void *arg0);
extern void func_802227F4_de(void *, void *, s32);
extern f32 func_8024E678_de(void *arg0, s32 arg1);
extern s32 D_800CED30;






void func_8022CC34_de(void *arg0, void *arg1) {
    s32 value;

    func_80274870_de(&((Player *)arg0)->lean, 0.0f, 0.25f);
    func_802231D4_de((s32)arg0, (s32)arg1, &D_800CE7E4);
    if (!(((Player *)arg0)->flags660 & 0x8000)) {
        func_802233F0_de((s32)arg0, (s32)arg1, &D_800C94EC_de);
    }
    if (((LevelActor *)arg1)->position1.y <= 0.0f) {
        if (func_8024E62C_de(arg1) != 0) {
            func_802227F4_de(arg0, arg1, 2);
        }
    }
    if (((LevelActor *)arg1)->position1.y <= 0.0f) {
        if (func_8024E678_de(arg1, 0) < 0.0f) {
            if (-func_8024E678_de(arg1, 0) < D_800C2D78_de[0]) {
                goto set_value;
            }
        } else if (func_8024E678_de(arg1, 0) < D_800C2D78_de[1]) {
set_value:
            if (((Player *)arg0)->animationTable == &D_800CED30) {
                ((Player *)arg0)->animation = 0x5E2E;
            } else {
                ((Player *)arg0)->animation = 0x7F8;
            }
        }
    }
}
