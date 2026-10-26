#include "include_asm.h"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"
#include "COMMON/TRIPLE.H"

/* Draw the inset viewport border with black bands and a one-pixel outline. */
void func_8026D8F8_de(void);
extern Gfx *g_displayListCursor;

void func_80401D74_de(s32 inset) {
    f32 left;
    f32 top;
    f32 width;
    f32 height;
    func_8026D8F8_de();
    left = 0.0f;
    top = (f32)inset;
    gDPPipeSync(g_displayListCursor++);
    gDPSetCycleType(g_displayListCursor++, G_CYC_1CYCLE);
    gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(g_displayListCursor++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    width = (f32)D_800E28D0;
    gDPSetPrimColor(g_displayListCursor++, 0, 0, 0, 0, 0, 0);
    height = (f32)(D_800E28D4 - inset * 2);
    gDPFillRectangle(g_displayListCursor++, left, top, (width - 1.0f), (top + (2.0f)));
    gDPFillRectangle(g_displayListCursor++, left, ((top + height) - (2.0f)), ((left + width) - (1.0f)), ((top + height) - (1.0f)));
    gDPFillRectangle(g_displayListCursor++, left, top, (left + (2.0f)), ((top + height) - 1.0f));
    gDPFillRectangle(g_displayListCursor++, ((left + width) - (2.0f)), top, ((left + width) - (1.0f)), ((top + height) - (1.0f)));
    gDPPipeSync(g_displayListCursor++);
    gDPSetCycleType(g_displayListCursor++, G_CYC_FILL);
    gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);
    gDPSetRenderMode(g_displayListCursor++, 0, 0);
    gDPSetFillColor(g_displayListCursor++, 0x10001);
    gDPFillRectangle(g_displayListCursor++, left, top, ((left + width) - 1.0f), top);
    gDPFillRectangle(g_displayListCursor++, left, ((top + height) - (1.0f)), ((left + width) - (1.0f)), ((top + height) - (1.0f)));
    gDPFillRectangle(g_displayListCursor++, left, top, left, ((top + height) - (1.0f)));
    gDPFillRectangle(g_displayListCursor++, ((left + width) - (1.0f)), top, (left + width), ((top + height) - (1.0f)));
}

#include "COMMON/GFX.H"
#include "gbi.h"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/OBJECTLINKS14C.H"

#define MENU_CLAMP_PIXEL(value) \
    ({ s32 edge = (value); if (edge < 0) edge = 0; edge; })
#define MENU_CLAMP_HEIGHT(value) \
    ({ f32 edge = (value); if (!(edge >= 0.0f)) edge = 0.0f; edge; })

/* Fade letterbox bands around the active track and draw the viewport border. */
void Menu_DrawLetterboxBands(void) {
    f32 fade = 1.0f;
    f32 height, span;
    height = ((f32)D_800E28D4 - (f32)D_800E28D0 / D_800E2830->spec.aspectRatio) * 0.5f;
    span = 0.3f;
    if (D_800E2830->time < D_800E2830->start) {
        fade = D_800E2830->start - D_800E2830->time;
        fade /= span;
        if (1.0f < fade) fade = 1.0f;
        fade = 1.0f - fade;
    }
    if (D_800E2830->time > D_800E2830->end) {
        fade = D_800E2830->time - D_800E2830->end;
        fade /= span;
        if (1.0f < fade) fade = 1.0f;
        fade = 1.0f - fade;
    }
    height = height * fade;
    gDPPipeSync(g_displayListCursor++);
    gDPSetCycleType(g_displayListCursor++, G_CYC_1CYCLE);
    Geometry_SetModePreset(0x13);
    Geometry_SetCombineMode(0x19);
    gDPSetPrimColor(g_displayListCursor++, 255, 255, 0, 0, 0, 255);
    gDPFillRectangle(g_displayListCursor++, 0, 0, MENU_CLAMP_PIXEL(D_800E28D0), MENU_CLAMP_PIXEL((s32)height));
    gDPFillRectangle(g_displayListCursor++, 0, (u32)MENU_CLAMP_HEIGHT((f32)D_800E28D4 - height), MENU_CLAMP_PIXEL(D_800E28D0), MENU_CLAMP_PIXEL(D_800E28D4));
    func_80401D74_de((s32)height);
}

#undef MENU_CLAMP_PIXEL
#undef MENU_CLAMP_HEIGHT
