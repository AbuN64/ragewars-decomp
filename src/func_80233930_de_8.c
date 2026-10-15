#include "types.h"
#include "gfx.h"
#include "span_1000/code_8023330C.h"
#include "shared/gameplay_camera.h"
#include "shared/func_80425674_de_layout.h"
#include "common/data.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "resident_event_handler.h"
#include "shared/func_802453D4_de_closed.h"
#include "shared/func_8028C568_de_closed.h"
#include "shared/func_804235A8_eu_closed.h"
#include "span_1000/code_80233920.h"
#include "span_1000/code_80291054.h"
#include "span_16E000/code_8044ACCC.h"
#include "span_C76B0/data.h"
extern s32 D_800CD8D0;
extern ViewFlags D_80103220;
extern u32 func_802337D0_de(StateRecAt10 *);
extern void func_80234FEC_de(GameplayCamera *camera);
/* Update split-screen rectangles, advance transient effects, and merge visible bounds. */
void func_80236874_de(RaceViewportState *state) {
    f32 halfWidth;
    f32 halfHeight;
    f32 width;
    f32 height;
    f32 top;
    f32 left;
    f32 splitY;
    f32 var_fv0_10;
    f32 var_fv0_11;
    f32 var_fv0_12;
    f32 var_fv0_13;
    f32 var_fv0_2;
    f32 var_fv0_3;
    f32 var_fv0_4;
    f32 var_fv0_5;
    f32 var_fv0_6;
    f32 var_fv0_7;
    f32 var_fv0_8;
    f32 var_fv0_9;
    f32 right;
    f32 splitX;
    f32 bottom;
    Effect33920 *nextEffect;
    s32 timer;
    Effect33920 *effect;
    s32 finished;
    u32 xDone;
    u32 yDone;
    u32 zDone;
    u32 mode;
    ViewFlags *flags;
    Shared_Game *settings;
    ViewportLayoutRules *layout;
    GameplayCamera *view;
    Box *clip, *bounds;
    ViewFlags initialFlags;

    right = (f32) D_800E28D0;
    top = 0.0f;
    bottom = (f32) D_800E28D4;
    left = 0.0f;
    if ((u32) state->header.views.count >= 2U) {
        top = D_800CB38C_de;
        bottom -= D_800CB388;
        left = D_800D05D0;
        right -= D_800CB394;
    }
    width = right - left;
    halfWidth = width * D_800C3320_de;
    height = bottom - top;
    halfHeight = height * D_800C3320_de;
    effect = D_801421B4;
    view = &state->self;
    if (effect != 0) {
        do {
            nextEffect = effect->next;
            xDone = func_802337D0_de(&effect->x);
            yDone = func_802337D0_de(&effect->y);
            zDone = func_802337D0_de(&effect->z);
            finished = 0;
            if ((xDone != 0) && (yDone != 0)) {
                finished = zDone > 0U;
            }
            if (finished != 0) {
                func_80255ED8_de(&state->activeEffects, effect);
                func_80255CB8_de(&state->freeEffects, effect);
            }
            effect = nextEffect;
            view = &state->self;
        } while (effect != 0);
    }
    view->unk29C = (f32) D_800E28D0;
    view->unk2A0 = (f32) D_800E28D4;
    view->unk2A4 = 0;
    view->unk2A8 = 0;
    if ((func_80245798_de() == 0) && (func_80245784_de() == 0)) {
        mode = (u32) state->header.views.count;
        view = state->header.views.head;
        switch (mode) {
        case 1:
            view->unk29C = width;
            view->unk2A0 = height;
            view->unk2A4 = 0;
            view->unk2A8 = 0;
            break;
        case 2:
            if (D_801462E7 == 0) {
                view->unk29C = width;
                view->unk2A0 = halfHeight;
                view->unk2A4 = left;
                view->unk2A8 = top;
                view = view->next;
                view->unk29C = width;
                view->unk2A0 = halfHeight;
                view->unk2A4 = left;
                view->unk2A8 = top + halfHeight;
                break;
            } else {
                view->unk29C = halfWidth;
                view->unk2A0 = height;
                view->unk2A4 = left;
                view->unk2A8 = top;
                view = view->next;
                view->unk29C = halfWidth;
                view->unk2A0 = height;
                    view->unk2A8 = top;
                view->unk2A4 = (f32) (left + halfWidth);
            }
            break;
        case 3:
            layout = &D_801462C8.viewportLayout;
            if (layout->threePlayerLayout == 0) {
            settings = &D_801462C8;
            if (settings->slots[0].enabled == 1) {
                view->unk29C = halfWidth;
                view->unk2A0 = halfHeight;
                view->unk2A4 = left;
                view->unk2A8 = top;
                view = view->next;
            }
            if (settings->slots[1].enabled == 1) {
                view->unk29C = halfWidth;
                view->unk2A0 = halfHeight;
                    view->unk2A8 = top;
                view->unk2A4 = (f32) (left + halfWidth);
                view = view->next;
            }
            if (settings->slots[2].enabled == 1) {
                view->unk29C = halfWidth;
                view->unk2A0 = halfHeight;
                view->unk2A4 = left;
                view->unk2A8 = (f32) (top + halfHeight);
                view = view->next;
            }
            if (settings->slots[3].enabled == 1) {
                splitX = left + halfWidth;
                splitY = top + halfHeight;
                view->unk29C = halfWidth;
                view->unk2A0 = halfHeight;
                view->unk2A4 = splitX;
                view->unk2A8 = splitY;
                break;
            }

            } else {
                view->unk29C = halfWidth;
                view->unk2A0 = halfHeight;
                view->unk2A4 = left;
                view->unk2A8 = top;
                view = view->next;
                view->unk29C = halfWidth;
                view->unk2A0 = halfHeight;
                    view->unk2A8 = top;
                view->unk2A4 = (f32) (left + halfWidth);
                view = view->next;
                splitY = top + halfHeight;
                view->unk29C = halfWidth;
                view->unk2A0 = halfHeight;
                view->unk2A4 = left;
                view->unk2A8 = splitY;
                break;
            }
            break;
        case 4:
            view->unk29C = halfWidth;
            view->unk2A0 = halfHeight;
            view->unk2A4 = left;
                view->unk2A8 = top;
            view = view->next;
            splitX = left + halfWidth;
            view->unk29C = halfWidth;
            view->unk2A0 = halfHeight;
                view->unk2A8 = top;
            view->unk2A4 = splitX;
            view = view->next;
            splitY = top + halfHeight;
            view->unk29C = halfWidth;
            view->unk2A0 = halfHeight;
            view->unk2A4 = left;
            view->unk2A8 = splitY;
            view = view->next;
            view->unk29C = halfWidth;
            view->unk2A0 = halfHeight;
            view->unk2A4 = splitX;
            view->unk2A8 = splitY;
            break;

        }
    }
    memcpy(&D_800FF208, state->self.clipBounds, sizeof(D_800FF208));
    memcpy(&D_801031F0, state->self.volumeBounds, sizeof(D_801031F0));
    D_80103220.flags = D_800CD8D0;
    func_80234FEC_de(&state->self);
    view = state->header.views.head;
    if (view != 0) {
        if ((D_80145088.status[7] != 0) || (func_80245850_de() != 0)) {
            func_80234FEC_de(view);
        }
        if ((func_80245798_de() != 0) || (func_80245784_de() != 0)) {
            func_80234FEC_de(view);
        }
        memcpy(&D_800FF208, view->clipBounds, sizeof(D_800FF208));
        memcpy(&D_801031F0, view->volumeBounds, sizeof(D_801031F0));
        initialFlags.flags = view->unk64;
        D_80103220 = initialFlags;
        view = view->next;
        if (view != 0) {
            clip = &D_800FF208;
            bounds = &D_801031F0;
            flags = &D_80103220;
            do {
                if ((D_80145088.status[7] != 0) || (func_80245850_de() != 0)) {
                    func_80234FEC_de(view);
                }
                var_fv0_2 = view->clipBounds[0].x;
                if (!(var_fv0_2 <= clip->min.x)) {
                    var_fv0_2 = clip->min.x;
                }
                clip->min.x = var_fv0_2;
                var_fv0_3 = view->clipBounds[0].y;
                if (!(var_fv0_3 <= clip->min.y)) {
                    var_fv0_3 = clip->min.y;
                }
                clip->min.y = var_fv0_3;
                var_fv0_4 = view->clipBounds[0].z;
                if (!(var_fv0_4 <= clip->min.z)) {
                    var_fv0_4 = clip->min.z;
                }
                clip->min.z = var_fv0_4;
                var_fv0_5 = view->clipBounds[1].x;
                if (!(clip->max.x <= var_fv0_5)) {
                    var_fv0_5 = clip->max.x;
                }
                clip->max.x = var_fv0_5;
                var_fv0_6 = view->clipBounds[1].y;
                if (!(clip->max.y <= var_fv0_6)) {
                    var_fv0_6 = clip->max.y;
                }
                clip->max.y = var_fv0_6;
                var_fv0_7 = view->clipBounds[1].z;
                if (!(clip->max.z <= var_fv0_7)) {
                    var_fv0_7 = clip->max.z;
                }
                clip->max.z = var_fv0_7;
                var_fv0_8 = view->volumeBounds[0].x;
                if (!(var_fv0_8 <= bounds->min.x)) {
                    var_fv0_8 = bounds->min.x;
                }
                bounds->min.x = var_fv0_8;
                var_fv0_9 = view->volumeBounds[0].y;
                if (!(var_fv0_9 <= bounds->min.y)) {
                    var_fv0_9 = bounds->min.y;
                }
                bounds->min.y = var_fv0_9;
                var_fv0_10 = view->volumeBounds[0].z;
                if (!(var_fv0_10 <= bounds->min.z)) {
                    var_fv0_10 = bounds->min.z;
                }
                bounds->min.z = var_fv0_10;
                var_fv0_11 = view->volumeBounds[1].x;
                if (!(bounds->max.x <= var_fv0_11)) {
                    var_fv0_11 = bounds->max.x;
                }
                bounds->max.x = var_fv0_11;
                var_fv0_12 = view->volumeBounds[1].y;
                if (!(bounds->max.y <= var_fv0_12)) {
                    var_fv0_12 = bounds->max.y;
                }
                bounds->max.y = var_fv0_12;
                var_fv0_13 = view->volumeBounds[1].z;
                if (!(bounds->max.z <= var_fv0_13)) {
                    var_fv0_13 = bounds->max.z;
                }
                bounds->max.z = var_fv0_13;
                flags->flags |= view->unk64;
                view = view->next;
            } while (view != 0);
        }
    }

    if (state->header.lastMode != state->header.views.count) {
        state->header.layoutTimer = 2;
        state->header.lastMode = state->header.views.count;
        return;
    }
    timer = state->header.layoutTimer;
    if (timer != 0) {
        state->header.layoutTimer = (s32) (timer - 1);
    }
}
