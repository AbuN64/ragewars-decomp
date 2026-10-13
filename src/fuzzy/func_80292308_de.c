#include "types.h"
#include "gfx.h"
#include "gbi.h"
/* Builds and submits the current frame, records its timing, and advances the fade transition. */
#include "span_1000/code_80291054.h"
extern FrameCallback D_800CD790[];
extern s32 D_800D297C,D_800E28D0,D_800E28D4,D_800E28E0,D_801428A8;
extern u32 D_800CD884;
extern f32 rwFrameBuildSeconds,D_800D2988;
extern f32 D_800C5448,D_800C544C,D_800C5450_de,D_800C5454,D_800C5458_de,D_800C545C,D_800C5460,D_800C5464_de,D_800C5468;
extern u64 func_802C0DA0_de(u64,u64);
extern void func_802539EC_de(s32,s32);
extern void func_80295FF4_de(void),func_8026D844_de(void),func_80265DD0_de(void),func_80263C24_de(void),func_802450CC_de(void);
extern void func_80293268_de(TimingWorld *),func_8040C09C_de(void);
extern void func_80236874_de(void *);
extern void func_8029311C_de(TimingWorld *, u8 *, s32,s32,s32,s32);
extern void func_80291BE8_de(TimingWorld *, s32,s32,s32,s32,s32);
extern s32 func_80253AD4_de(s32);
extern void func_8029192C_de(TimingWorld *,Frame *);
extern s32 func_802BB420_de(void *,void *,s32);
static __inline__ s32 hasFadeMode(u8 *mode) { return *mode != 0; }
void func_80292308_de(TimingWorld *arg0) {
    u8 color[4];
    Gfx *temp_a0;
    Gfx *temp_a1;
    Gfx *temp_a2;
    Gfx *temp_a3;
    Gfx *temp_t0;
    Gfx *temp_t1;
    Gfx *temp_t2;
    Gfx *temp_v0_2;
    Gfx *temp_v1_2;
    void (*temp_v0)(TimingWorld *);
    f32 temp_fv0;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv0f_3;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv0f;
    s32 temp_a2_2;
    s32 temp_v0_3;
    s32 var_t0;
    u32 temp_a1_2;
    u32 temp_v1;
    u32 temp_v1_3;
    u32 temp_v1_4;
    u32 temp_v1_5;
    u32 var_a0;
    u64 temp_ret;
    u64 temp_ret_2;
    u64 temp_ret_3;
    u64 temp_s4;
    u8 temp_v1_6;

    temp_ret = func_802BADC0_de();
    temp_v1 = (u32) temp_ret;
    temp_s4 = temp_ret;
    D_80146CD8 = D_8011BDC0;
    func_802539EC_de(0, D_800D297C);
    func_80295FF4_de();
    func_8026D844_de();
    func_802917D8_de(arg0);
    func_80265DD0_de();
    func_80263C24_de();
    func_80236874_de(&arg0->viewportData);
    func_80293268_de(arg0);
    temp_v0 = D_800CD790[arg0->unk26DB8].draw;
    if (temp_v0 != 0) {
        temp_v0(arg0);
    }
    if (D_80146CD8->submitted == 0) {
        color[0] = 0;
        color[1] = 0;
        color[2] = 0;
        temp_fv0f = arg0->fade;
        var_t0 = 0xFF;
        if (!(temp_fv0f < 0.0f)) {
            var_t0 = 0;
            if (!(D_800C5448 < temp_fv0f)) {
                var_t0 = 0xFF;
                if (!(temp_fv0f < 0.0f)) {
                    var_t0 = ~(s32) (temp_fv0f * D_800C544C);
                }
            }
        }
        color[3] = var_t0;
        func_8029311C_de(arg0, &color[0], 0, 0, D_800E28D0, D_800E28D4);
    }
    if (D_800E28E0 != 0) {
        if (D_800E28E0 == 0x14) {
            func_8040C09C_de();
        }
        func_80291BE8_de(arg0, 0, 0x1E0, 0, 0x168, 0);
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
    var_a0 = D_800CD884;
    temp_v1_3 = (u8 *)D_80110634 - (u8 *)D_80146CD8->list;
    D_80146CD8->listBytes = temp_v1_3;
    if (var_a0 < temp_v1_3) {
        var_a0 = temp_v1_3;
    }
    D_800CD884 = var_a0;
    D_80146CD8->submitted = 0;
    D_80146CD8->ticks = (s32) D_801428A8;
    temp_ret_2 = func_802BADC0_de();
    temp_ret_3 = ((temp_ret_2 - temp_s4) << 6) / 3;
    var_fv0f = (f32)temp_ret_3;
    rwFrameBuildSeconds = var_fv0f * D_800C5450_de;
    if (func_80253AD4_de(0) != 0) {
        func_8029192C_de(arg0, D_80146CD8);
    } else {
        func_802BB420_de(D_801428C0, D_80146CD8->taskMessage, 1);
    }
    if (hasFadeMode(&arg0->unk26DC1)) {
        var_fv0 = D_800C5454;
        if (arg0->fadeFast != 0) {
            var_fv0 = D_800C5458_de;
        }
        temp_v1_6 = arg0->unk26DC1;
        if (temp_v1_6 != 1) {
            if (temp_v1_6 == 2) {
                temp_fv0f_2 = arg0->fade;
                if (temp_fv0f_2 > 0.0f) {
                    temp_fv0 = temp_fv0f_2 - (var_fv0 * D_800D2988);
                    arg0->fade = temp_fv0;
                    if (temp_fv0 < 0.0f) {
                        arg0->fade = 0.0f;
                    }
                } else {
                    arg0->fade = temp_fv0f_2 - D_800C545C;
                }
                if (arg0->fade < D_800C5460) {
                    temp_v1 = arg0->unk26DB8;
                    arg0->unk26DB8 = 0x14;
                    arg0->fade = 0;
                    arg0->unk26DC1 = 1;
                    arg0->previousMode = temp_v1;
                }
            }
        } else {
            temp_fv0f_3 = arg0->fade;
            if (D_800D2988 < D_800C5464_de) {
                var_fv0_2 = temp_fv0f_3 + (var_fv0 * D_800C5464_de);
            } else {
                var_fv0_2 = temp_fv0f_3 + (var_fv0 * D_800D2988);
            }
            temp_fv0f = D_800C5468;
            arg0->fade = var_fv0_2;
            if (temp_fv0f <= var_fv0_2) {
                arg0->unk26DC1 = 0;
                arg0->fade = temp_fv0f;
                arg0->fadeFast = 0;
            }
        }
    }
    func_802450CC_de();
}
