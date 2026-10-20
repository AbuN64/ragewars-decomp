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










void func_80291BE8_de(void *unused, s32 ulx, s32 lrx, s32 uly, s32 lry, s32 interlaced) {
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

extern void func_802A84F8_de(void);
extern void func_802AAB3C_de(s32, s32, s32, s32, s32, s32);
extern void func_802AAB68_de(f32, f32);
extern s32 D_801377B8[2];

/* Draw a null-terminated list of scaled strings, with an optional full-screen backdrop. */
void Render_DrawTextLines(void *state, s32 drawBackdrop, char **lines, s32 x, s32 y, s32 lineStep, f32 scaleX, f32 scaleY) {
    Frame *frame = D_8011BDC0;
    s32 i;
    char *text;

    y = y * D_800E28D4 / 222;
    if (drawBackdrop) {
        func_80291BE8_de(state, 0, D_800E28D0, 0, D_800E28D4, 0);
        gDPSetScissor(D_80110634++, G_SC_NON_INTERLACE, 0, 0, D_800E28D0 - 1, D_800E28D4 - 1);
        gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)frame->colorImage);
        gDPSetCycleType(D_80110634++, G_CYC_FILL);
        gDPSetCombineLERP(D_80110634++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);
        gDPSetRenderMode(D_80110634++, 0, 0);
        gDPSetFillColor(D_80110634++, 0x00010001);
        gDPFillRectangle(D_80110634++, 0, 0, D_800E28D0, D_800E28D4);
    }
    func_802A84F8_de();
    func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    scaleX = scaleX * D_800E28D0 * (1.0f / 284.0f);
    scaleY = scaleY * D_800E28D4 * (1.0f / 222.0f);
    scaleX *= (D_800E28D4 >= 0xDF) ? 0.8f : 0.85f;
    scaleY *= 0.5f;
    func_802AAB68_de(scaleX, scaleY);
    D_801377B8[0] = 1;
    D_801377B8[1] = 1;
    for (i = 0; lines[i] != 0; i++) {
        text = lines[i];
        func_802A8F28_de(text, x, y, 0xFF, 1, 1, 1.0f, 1.0f);
        y = y + lineStep * scaleY;
    }
}

