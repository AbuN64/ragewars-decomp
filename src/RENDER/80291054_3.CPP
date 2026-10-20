#include "include_asm.h"
#include "COMMON/GFX.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "gbi.h"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"

/* Clears the depth buffer over a rectangle: switches the colour image to the depth buffer D_801536E8 in fill mode after setting render mode 0x14 through func_8026925C_de, fills the rectangle with the far depth value (or, for interlaced output, alternate lines with the far value and the remaining lines with 0, by single lines or by line pairs as D_800E28D8 selects), then restores the frame's colour image and one-cycle mode. Written with libultra-style display-list macros. */




extern void func_8026925C_de(s32 mode);










void func_80291BE8_de(s32 unused, s32 ulx, s32 lrx, s32 uly, s32 lry, s32 interlaced) {
    s32 y;

    gDPPipeSync(D_80110634++);
    func_8026925C_de(0x14);
    gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)((D_801536E8)));
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_FILL);
    if (!interlaced) {
        gDPSetFillColor(D_80110634++, ((0xFFFCFFFC)));
        gDPFillRectangle(D_80110634++, (ulx), (uly), (lrx), (lry));
    } else if (D_800E28D8 == 0) {
        gDPSetFillColor(D_80110634++, ((0xFFFCFFFC)));
        for (y = uly; y < lry; y += 2) {
            gDPFillRectangle(D_80110634++, (ulx), (y), (lrx), (y));
        }
        gDPSetFillColor(D_80110634++, ((0)));
        for (y = uly + 1; y < lry; y += 2) {
            gDPFillRectangle(D_80110634++, (ulx), (y), (lrx), (y));
        }
    } else {
        gDPSetFillColor(D_80110634++, ((0xFFFCFFFC)));
        for (y = uly; y < lry; y++) {
            if ((y & 3) < 2) {
                gDPFillRectangle(D_80110634++, (ulx), (y), (lrx), (y));
            }
        }
        gDPSetFillColor(D_80110634++, ((0)));
        for (y = uly; y < lry; y++) {
            if ((y & 3) >= 2) {
                gDPFillRectangle(D_80110634++, (ulx), (y), (lrx), (y));
            }
        }
    }
    gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)((D_8011BDC0->colorImage)));
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
}

#ifndef NON_MATCHING
INCLUDE_ASM("span_1000", func_80291FD8_de);
#endif
#if defined(NON_MATCHING)
extern float D_800C542C;
extern float D_800C5430_de;
extern float D_800C5434;
extern float D_800C5438_de;
extern float D_800C543C;
extern float D_800C5440_de;
extern float D_800C5444_de;
extern void func_802A84F8_de(void);
extern void func_802AAB3C_de(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void func_802AAB68_de(float arg0, float arg1);
extern s32 D_801377B8[2];
/* Draws a NULL-terminated list of strings, one per line, starting at (x, y) where y is given in 240-line
 * screen units. With drawBackdrop set, first clears a full-screen fill with the colour image reset (func_80291BE8_de
 * and a raw fill rectangle over the whole video area). The glyph scale is the caller's scale times the video size,
 * with an extra factor for tall (>= 0xDF lines) video modes; lineStep scales the per-line advance. */
void func_80291FD8_de(s32 state, s32 drawBackdrop, char **lines, s32 x, s32 y, s32 lineStep, f32 scaleX, f32 scaleY) {
    y = y * D_800E28D4 / 240;
    if (drawBackdrop) {
        func_80291BE8_de(state, 0, D_800E28D0, 0, D_800E28D4, 0);
        gDPSetScissor(D_80110634++, G_SC_NON_INTERLACE, 0, 0, D_800E28D0 - 1, D_800E28D4 - 1);
        gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)(D_8011BDC0->colorImage));
        gDPSetCycleType(D_80110634++, G_CYC_FILL);
        gDPSetCombineLERP(D_80110634++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);
        gDPSetRenderMode(D_80110634++, 0, 0);
        gDPSetFillColor(D_80110634++, 0x00010001);
        gDPFillRectangle(D_80110634++, 0, 0, D_800E28D0, D_800E28D4);
    }
    func_802A84F8_de();
    func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    scaleX = scaleX * D_800E28D0 * D_800C5430_de;
    scaleY = scaleY * D_800E28D4 * D_800C5434;
    if (D_800E28D4 < 0xDF) {
        scaleX *= D_800C5438_de;
    } else {
        scaleX *= D_800C543C;
    }
    scaleY *= D_800C5440_de;
    func_802AAB68_de(scaleX, scaleY);
    D_801377B8[0] = 1;
    D_801377B8[1] = 1;
    while (*lines) {
        func_802A8F28_de((s32)*lines, x, y, 0xFF, 1, 1, D_800C5444_de, D_800C5444_de);
        y = y + lineStep * scaleY;
        lines++;
    }
}
#endif

