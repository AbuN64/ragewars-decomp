#include "TYPES.H"
#include "gfx.h"
#include "gbi.h"
/* Builds and submits the current frame, records its timing, and advances the fade transition. */
#include "span_1000/code_80291054.h"
#include "common/data.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "shared/func_802453D4_de_closed.h"
#include "shared/func_802BB8B0_de_closed.h"
#include "shared/gameplay_camera.h"
#include "span_1000/code_8022F3E8.h"
#include "span_1000/code_80243A80.h"
#include "span_1000/code_802536F4.h"
#include "span_1000/code_802636D0.h"
#include "span_1000/code_80265370.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_80296014.h"
#include "span_16E000/code_8040B45C.h"
#include "span_C76B0/data.h"
extern void func_80236874_de(RaceViewportState *);
extern void func_8029311C_de(void *, u8 *, s32,s32,s32,s32);
extern void func_80291BE8_de(s32, s32,s32,s32,s32,s32);
extern void func_8029192C_de(TimingWorld *,Frame *);
static __inline__ s32 hasFadeMode(u8 *mode) { return *mode != 0; }
void func_80292308_de(TimingWorld *world) {
    u8 color[4];
    void (*draw)(TimingWorld *);
    f32 updatedFade;
    f32 fadeLimit;
    f32 fade;
    f32 step;
    f32 speed;
    f32 fadeOutSpeed;
    f32 nextFade;
    f32 elapsed;
    s32 alpha;
    u32 previousMode;
    u32 listBytes;
    u32 maxListBytes;
    u64 start;
    u64 end;
    u64 duration;
    u64 startTime;
    u8 fadeMode;

    start = func_802BADC0_de();
    previousMode = (u32) start;
    startTime = start;
    D_80146CD8 = D_8011BDC0;
    func_802539EC_de(0, D_800D297C);
    func_80295FF4_de();
    func_8026D844_de();
    func_802917D8_de(world);
    func_80265DD0_de();
    func_80263C24_de();
    func_80236874_de(&world->viewport);
    func_80293268_de(world);
    draw = D_800CD790[world->unk26DB8].draw;
    if (draw != 0) {
        draw(world);
    }
    if (D_80146CD8->submitted == 0) {
        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        fadeLimit = world->fade;
        alpha = 0xFF;
        if (!(fadeLimit < 0.0f)) {
            alpha = 0;
            if (!(D_800C5448 < fadeLimit)) {
                alpha = 0xFF;
                if (!(fadeLimit < 0.0f)) {
                    alpha = ~(s32) (fadeLimit * D_800C544C);
                }
            }
        }
        color[3] = alpha;
        func_8029311C_de(world, &color[0], 0, 0, D_800E28D0, D_800E28D4);
    }
    if (D_800E28E0 != 0) {
        if (D_800E28E0 == 0x14) {
            func_8040C09C_de();
        }
        func_80291BE8_de((s32)world, 0, 0x1E0, 0, 0x168, 0);
        gDPSetScissorFrac(D_80110634++,0,0,0,0x77C,0x59C);
        gDPSetColorImage(D_80110634++,G_IM_FMT_RGBA,G_IM_SIZ_16b,480,D_80146CD8->colorImage);
        gDPSetCycleType(D_80110634++,G_CYC_FILL);
        gDPSetCombineLERP(D_80110634++,0,0,0,SHADE,0,0,0,SHADE,0,0,0,SHADE,0,0,0,SHADE);
        gDPSetRenderMode(D_80110634++,G_RM_NOOP,G_RM_NOOP2);
        gDPSetFillColor(D_80110634++,0x10001);
        gDPFillRectangle(D_80110634++,0,0,480,360);
        D_800E28E0--;
    }
    gDPFullSync(D_80110634++);
    gSPEndDisplayList(D_80110634++);
    maxListBytes = D_800CD884;
    listBytes = (u8 *)D_80110634 - (u8 *)D_80146CD8->list;
    D_80146CD8->listBytes = listBytes;
    if (maxListBytes < listBytes) {
        maxListBytes = listBytes;
    }
    D_800CD884 = maxListBytes;
    D_80146CD8->submitted = 0;
    D_80146CD8->ticks = (s32) D_801428A8;
    end = func_802BADC0_de();
    duration = ((end - startTime) << 6) / 3;
    elapsed = (f32)duration;
    rwFrameBuildSeconds = elapsed * D_800C5450_de;
    if (func_80253AD4_de(0) != 0) {
        func_8029192C_de(world, D_80146CD8);
    } else {
        func_802BB420_de(D_801428C0, D_80146CD8->taskMessage, 1);
    }
    if (hasFadeMode(&world->unk26DC1)) {
        speed = D_800C5454;
        if(world->fadeFast) speed = D_800C5458_de;
        fadeOutSpeed = speed;
        fadeMode = world->unk26DC1;
        if (fadeMode != 1) {
            if (fadeMode == 2) {
                fade = world->fade;
                step = 0.0f;
                if (fade > step) {
                    speed = D_800D2988;
                    updatedFade = fade - (fadeOutSpeed * speed);
                    world->fade = updatedFade;
                    if (updatedFade < step) {
                        world->fade = 0.0f;
                    }
                } else {
                    world->fade = fade - D_800C545C;
                }
                if (world->fade < D_800C5460) {
                    previousMode = world->unk26DB8;
                    world->unk26DB8 = 0x14;
                    world->fade = 0;
                    world->unk26DC1 = 1;
                    world->previousMode = previousMode;
                }
            }
        } else {
            step = D_800D2988;
            fade = world->fade;
            if (step < D_800C5464_de) {
                nextFade = fade + (speed * D_800C5464_de);
            } else {
                nextFade = fade + (speed * step);
            }
            fadeLimit = D_800C5468;
            world->fade = nextFade;
            if (fadeLimit <= nextFade) {
                world->unk26DC1 = 0;
                world->fade = fadeLimit;
                world->fadeFast = 0;
            }
        }
    }
    func_802450CC_de();
}
