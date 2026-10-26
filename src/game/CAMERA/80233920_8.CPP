#include "TYPES.H"
#include "COMMON/LONE/D_800CD8D0.H"
#include "COMMON/GFX.H"
#include "COMMON/STATERECAT10.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/EXTERNS_10.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/VIEWFLAGS.H"
#include "CAMERA/80233920.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/OBJB.H"
#include "COMMON/TRIPLE.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_3.H"

extern ViewFlags D_80103220;
extern u32 Weapon_UpdateShakeAxis(CShakeAxis *);
extern void Camera_UpdateViewProjectionAndEffects(GameplayCamera *camera);
/* Update split-screen rectangles, advance transient effects, and merge visible bounds. */
void Camera_UpdateViewportLayoutAndBounds(RaceViewportState *state) {
    f32 halfWidth;
    f32 halfHeight;
    f32 width;
    f32 height;
    f32 top;
    f32 left;
    f32 splitY;
    f32 volumeMinZ;
    f32 volumeMaxX;
    f32 volumeMaxY;
    f32 volumeMaxZ;
    f32 clipMinX;
    f32 clipMinY;
    f32 clipMinZ;
    f32 clipMaxX;
    f32 clipMaxY;
    f32 clipMaxZ;
    f32 volumeMinX;
    f32 volumeMinY;
    f32 right;
    f32 splitX;
    f32 bottom;
    CShake *nextEffect;
    s32 timer;
    CShake *effect;
    s32 finished;
    u32 xDone;
    u32 yDone;
    u32 zDone;
    u32 mode;
    ViewFlags *flags;
    Shared_Game *settings;
    CGameStatus *layout;
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
            xDone = Weapon_UpdateShakeAxis(&effect->x);
            yDone = Weapon_UpdateShakeAxis(&effect->y);
            zDone = Weapon_UpdateShakeAxis(&effect->z);
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
    view->viewWidth = (f32) D_800E28D0;
    view->viewHeight = (f32) D_800E28D4;
    view->viewLeft = 0;
    view->viewTop = 0;
    if ((Cinema_IsSequenceInWindow() == 0) && (Cinema_IsSequenceActive() == 0)) {
        mode = (u32) state->header.views.count;
        view = state->header.views.head;
        switch (mode) {
        case 1:
            view->viewWidth = width;
            view->viewHeight = height;
            view->viewLeft = 0;
            view->viewTop = 0;
            break;
        case 2:
            if (D_801462C8.unknown1F == 0) {
                view->viewWidth = width;
                view->viewHeight = halfHeight;
                view->viewLeft = left;
                view->viewTop = top;
                view = view->next;
                view->viewWidth = width;
                view->viewHeight = halfHeight;
                view->viewLeft = left;
                view->viewTop = top + halfHeight;
                break;
            } else {
                view->viewWidth = halfWidth;
                view->viewHeight = height;
                view->viewLeft = left;
                view->viewTop = top;
                view = view->next;
                view->viewWidth = halfWidth;
                view->viewHeight = height;
                    view->viewTop = top;
                view->viewLeft = (f32) (left + halfWidth);
            }
            break;
        case 3:
            layout = &D_801462C8.counters;
            if (layout->transitionActive == 0) {
            settings = &D_801462C8;
            if (settings->slots[0].enabled == 1) {
                view->viewWidth = halfWidth;
                view->viewHeight = halfHeight;
                view->viewLeft = left;
                view->viewTop = top;
                view = view->next;
            }
            if (settings->slots[1].enabled == 1) {
                view->viewWidth = halfWidth;
                view->viewHeight = halfHeight;
                    view->viewTop = top;
                view->viewLeft = (f32) (left + halfWidth);
                view = view->next;
            }
            if (settings->slots[2].enabled == 1) {
                view->viewWidth = halfWidth;
                view->viewHeight = halfHeight;
                view->viewLeft = left;
                view->viewTop = (f32) (top + halfHeight);
                view = view->next;
            }
            if (settings->slots[3].enabled == 1) {
                splitX = left + halfWidth;
                splitY = top + halfHeight;
                view->viewWidth = halfWidth;
                view->viewHeight = halfHeight;
                view->viewLeft = splitX;
                view->viewTop = splitY;
                break;
            }

            } else {
                view->viewWidth = halfWidth;
                view->viewHeight = halfHeight;
                view->viewLeft = left;
                view->viewTop = top;
                view = view->next;
                view->viewWidth = halfWidth;
                view->viewHeight = halfHeight;
                    view->viewTop = top;
                view->viewLeft = (f32) (left + halfWidth);
                view = view->next;
                splitY = top + halfHeight;
                view->viewWidth = halfWidth;
                view->viewHeight = halfHeight;
                view->viewLeft = left;
                view->viewTop = splitY;
                break;
            }
            break;
        case 4:
            view->viewWidth = halfWidth;
            view->viewHeight = halfHeight;
            view->viewLeft = left;
                view->viewTop = top;
            view = view->next;
            splitX = left + halfWidth;
            view->viewWidth = halfWidth;
            view->viewHeight = halfHeight;
                view->viewTop = top;
            view->viewLeft = splitX;
            view = view->next;
            splitY = top + halfHeight;
            view->viewWidth = halfWidth;
            view->viewHeight = halfHeight;
            view->viewLeft = left;
            view->viewTop = splitY;
            view = view->next;
            view->viewWidth = halfWidth;
            view->viewHeight = halfHeight;
            view->viewLeft = splitX;
            view->viewTop = splitY;
            break;

        }
    }
    memcpy(&D_800FF208, state->self.clipBounds, sizeof(D_800FF208));
    memcpy(&D_801031F0, state->self.volumeBounds, sizeof(D_801031F0));
    D_80103220.flags = D_800CD8D0;
    Camera_UpdateViewProjectionAndEffects(&state->self);
    view = state->header.views.head;
    if (view != 0) {
        if ((D_80145088.status[7] != 0) || (func_80245850_de() != 0)) {
            Camera_UpdateViewProjectionAndEffects(view);
        }
        if ((Cinema_IsSequenceInWindow() != 0) || (Cinema_IsSequenceActive() != 0)) {
            Camera_UpdateViewProjectionAndEffects(view);
        }
        memcpy(&D_800FF208, view->clipBounds, sizeof(D_800FF208));
        memcpy(&D_801031F0, view->volumeBounds, sizeof(D_801031F0));
        initialFlags.flags = view->floorSurface;
        D_80103220 = initialFlags;
        view = view->next;
        if (view != 0) {
            clip = &D_800FF208;
            bounds = &D_801031F0;
            flags = &D_80103220;
            do {
                if ((D_80145088.status[7] != 0) || (func_80245850_de() != 0)) {
                    Camera_UpdateViewProjectionAndEffects(view);
                }
                clipMinX = view->clipBounds[0].x;
                if (!(clipMinX <= clip->min.x)) {
                    clipMinX = clip->min.x;
                }
                clip->min.x = clipMinX;
                clipMinY = view->clipBounds[0].y;
                if (!(clipMinY <= clip->min.y)) {
                    clipMinY = clip->min.y;
                }
                clip->min.y = clipMinY;
                clipMinZ = view->clipBounds[0].z;
                if (!(clipMinZ <= clip->min.z)) {
                    clipMinZ = clip->min.z;
                }
                clip->min.z = clipMinZ;
                clipMaxX = view->clipBounds[1].x;
                if (!(clip->max.x <= clipMaxX)) {
                    clipMaxX = clip->max.x;
                }
                clip->max.x = clipMaxX;
                clipMaxY = view->clipBounds[1].y;
                if (!(clip->max.y <= clipMaxY)) {
                    clipMaxY = clip->max.y;
                }
                clip->max.y = clipMaxY;
                clipMaxZ = view->clipBounds[1].z;
                if (!(clip->max.z <= clipMaxZ)) {
                    clipMaxZ = clip->max.z;
                }
                clip->max.z = clipMaxZ;
                volumeMinX = view->volumeBounds[0].x;
                if (!(volumeMinX <= bounds->min.x)) {
                    volumeMinX = bounds->min.x;
                }
                bounds->min.x = volumeMinX;
                volumeMinY = view->volumeBounds[0].y;
                if (!(volumeMinY <= bounds->min.y)) {
                    volumeMinY = bounds->min.y;
                }
                bounds->min.y = volumeMinY;
                volumeMinZ = view->volumeBounds[0].z;
                if (!(volumeMinZ <= bounds->min.z)) {
                    volumeMinZ = bounds->min.z;
                }
                bounds->min.z = volumeMinZ;
                volumeMaxX = view->volumeBounds[1].x;
                if (!(bounds->max.x <= volumeMaxX)) {
                    volumeMaxX = bounds->max.x;
                }
                bounds->max.x = volumeMaxX;
                volumeMaxY = view->volumeBounds[1].y;
                if (!(bounds->max.y <= volumeMaxY)) {
                    volumeMaxY = bounds->max.y;
                }
                bounds->max.y = volumeMaxY;
                volumeMaxZ = view->volumeBounds[1].z;
                if (!(bounds->max.z <= volumeMaxZ)) {
                    volumeMaxZ = bounds->max.z;
                }
                bounds->max.z = volumeMaxZ;
                flags->flags |= view->floorSurface;
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
