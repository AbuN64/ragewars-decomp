#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"
#include "COMMON/TRIPLE.H"

/* Draw the inset viewport border with black bands and a one-pixel outline. */
void func_8026D8F8_de(void);
extern Gfx *D_80110634;
extern s32 D_800E28D0;
extern s32 D_800E28D4;

void func_80401D74_de(s32 inset) {
    f32 left;
    f32 top;
    f32 width;
    f32 height;
    func_8026D8F8_de();
    left = 0.0f;
    top = (f32)inset;
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
    gDPSetCombineLERP(D_80110634++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(D_80110634++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    width = (f32)D_800E28D0;
    gDPSetPrimColor(D_80110634++, 0, 0, 0, 0, 0, 0);
    height = (f32)(D_800E28D4 - inset * 2);
    gDPFillRectangle(D_80110634++, left, top, (width - 1.0f), (top + (2.0f)));
    gDPFillRectangle(D_80110634++, left, ((top + height) - (2.0f)), ((left + width) - (1.0f)), ((top + height) - (1.0f)));
    gDPFillRectangle(D_80110634++, left, top, (left + (2.0f)), ((top + height) - 1.0f));
    gDPFillRectangle(D_80110634++, ((left + width) - (2.0f)), top, ((left + width) - (1.0f)), ((top + height) - (1.0f)));
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_FILL);
    gDPSetCombineLERP(D_80110634++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);
    gDPSetRenderMode(D_80110634++, 0, 0);
    gDPSetFillColor(D_80110634++, 0x10001);
    gDPFillRectangle(D_80110634++, left, top, ((left + width) - 1.0f), top);
    gDPFillRectangle(D_80110634++, left, ((top + height) - (1.0f)), ((left + width) - (1.0f)), ((top + height) - (1.0f)));
    gDPFillRectangle(D_80110634++, left, top, left, ((top + height) - (1.0f)));
    gDPFillRectangle(D_80110634++, ((left + width) - (1.0f)), top, (left + width), ((top + height) - (1.0f)));
}

#ifdef NON_MATCHING
#include "COMMON/GFX.H"
#include "gbi.h"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/OBJECTLINKS14C.H"

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
    height = ((f32)D_800E28D4 - (f32)D_800E28D0 / D_800E2830->spec.aspectRatio) * D_800DCC10_de * fade;
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
#else
INCLUDE_ASM("ovl_80400000", func_8040293C_de);
#endif
