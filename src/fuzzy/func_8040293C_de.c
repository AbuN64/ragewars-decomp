#include "gfx.h"
#include "gbi.h"
#include "shared/func_802453D4_de_closed.h"
#include "span_C76B0/data.h"
extern Gfx *D_80110634;
extern void func_8026925C_de(s32);
extern void func_80268CE0_de(u32);
extern void func_80401D74_de(s32);

void func_8040293C_de(void) {
    f32 fade = 1.0f;
    f32 amount, height, lower;
    s32 width, screenHeight, top;
    if (D_800E2830->time < D_800E2830->start) {
        amount = (D_800E2830->start - D_800E2830->time) / D_800DCC14_de;
        if (D_800DCC18_de < amount) amount = D_800DCC18_de;
        fade = D_800DCC18_de - amount;
    }
    if (D_800E2830->end < D_800E2830->time) {
        amount = (D_800E2830->time - D_800E2830->end) / D_800DCC14_de;
        if (D_800DCC1C < amount) amount = D_800DCC1C;
        fade = D_800DCC1C - amount;
    }
    height = ((f32)D_800E28D4 - (f32)D_800E28D0 / D_800E2830->aspectRatio) * D_800DCC10_de * fade;
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
    func_8026925C_de(0x13);
    func_80268CE0_de(0x19);
    gDPSetPrimColor(D_80110634++, 255, 255, 0, 0, 0, 255);
    width = D_800E28D0;
    if (width < 0) width = 0;
    top = (s32)height;
    if (top < 0) top = 0;
    gDPFillRectangle(D_80110634++, 0, 0, width, top);
    width = D_800E28D0;
    if (width < 0) width = 0;
    screenHeight = D_800E28D4;
    if (screenHeight < 0) screenHeight = 0;
    lower = (f32)D_800E28D4 - height;
    if (!(lower >= 0.0f)) lower = 0.0f;
    gDPFillRectangle(D_80110634++, 0, (u32)lower, width, screenHeight);
    func_80401D74_de((s32)height);
}
