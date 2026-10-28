#include "include_asm.h"
#include "COMMON/FONT_STYLE_AND_GLYPH_OPERATIONS.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/GFX.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "gbi.h"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"

/* Clears the depth buffer over a rectangle: switches the colour image to the depth buffer D_801536E8 in fill mode after setting render mode 0x14 through Geometry_SetModePreset, fills the rectangle with the far depth value (or, for interlaced output, alternate lines with the far value and the remaining lines with 0, by single lines or by line pairs as D_800E28D8 selects), then restores the frame's colour image and one-cycle mode. Written with libultra-style display-list macros. */




extern s32 Geometry_SetModePreset(s32 mode);










void SetN64_ClearDepthRect(void *unused, s32 ulx, s32 lrx, s32 uly, s32 lry, s32 interlaced) {
    s32 y;

    gDPPipeSync(g_displayListCursor++);
    Geometry_SetModePreset(0x14);
    gDPSetColorImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)((D_801536E8)));
    gDPPipeSync(g_displayListCursor++);
    gDPSetCycleType(g_displayListCursor++, G_CYC_FILL);
    if (!interlaced) {
        gDPSetFillColor(g_displayListCursor++, ((0xFFFCFFFC)));
        gDPFillRectangle(g_displayListCursor++, (ulx), (uly), (lrx), (lry));
    } else if (D_800E28D8 == 0) {
        gDPSetFillColor(g_displayListCursor++, ((0xFFFCFFFC)));
        for (y = uly; y < lry; y += 2) {
            gDPFillRectangle(g_displayListCursor++, (ulx), (y), (lrx), (y));
        }
        gDPSetFillColor(g_displayListCursor++, ((0)));
        for (y = uly + 1; y < lry; y += 2) {
            gDPFillRectangle(g_displayListCursor++, (ulx), (y), (lrx), (y));
        }
    } else {
        gDPSetFillColor(g_displayListCursor++, ((0xFFFCFFFC)));
        for (y = uly; y < lry; y++) {
            if ((y & 3) < 2) {
                gDPFillRectangle(g_displayListCursor++, (ulx), (y), (lrx), (y));
            }
        }
        gDPSetFillColor(g_displayListCursor++, ((0)));
        for (y = uly; y < lry; y++) {
            if ((y & 3) >= 2) {
                gDPFillRectangle(g_displayListCursor++, (ulx), (y), (lrx), (y));
            }
        }
    }
    gDPSetColorImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)((D_8011FAC0.ring.current->colorImage)));
    gDPPipeSync(g_displayListCursor++);
    gDPSetCycleType(g_displayListCursor++, G_CYC_2CYCLE);
}


/* Draw a null-terminated list of scaled strings, with an optional full-screen backdrop. */
void SetN64_DrawTextLines(void *state, s32 drawBackdrop, char **lines, s32 x, s32 y, s32 lineStep, f32 scaleX, f32 scaleY) {
    Frame *frame = D_8011FAC0.ring.current;
    s32 i;
    char *text;

    y = y * D_800E28D4 / 222;
    if (drawBackdrop) {
        SetN64_ClearDepthRect(state, 0, D_800E28D0, 0, D_800E28D4, 0);
        gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, 0, 0, D_800E28D0 - 1, D_800E28D4 - 1);
        gDPSetColorImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)frame->colorImage);
        gDPSetCycleType(g_displayListCursor++, G_CYC_FILL);
        gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);
        gDPSetRenderMode(g_displayListCursor++, 0, 0);
        gDPSetFillColor(g_displayListCursor++, 0x00010001);
        gDPFillRectangle(g_displayListCursor++, 0, 0, D_800E28D0, D_800E28D4);
    }
    OnScreen_SetupTextRendering();
    OnScreen_SetTextColors(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    scaleX = scaleX * D_800E28D0 * (1.0f / 284.0f);
    scaleY = scaleY * D_800E28D4 * (1.0f / 222.0f);
    scaleX *= (D_800E28D4 >= 0xDF) ? 0.8f : 0.85f;
    scaleY *= 0.5f;
    OnScreen_SetTextScale(scaleX, scaleY);
    D_801376F8.shadowX = 1;
    D_801376F8.shadowY = 1;
    for (i = 0; lines[i] != 0; i++) {
        text = lines[i];
        Onscrn_DrawText(text, x, y, 0xFF, 1, 1, 1.0f, 1.0f);
        y = y + lineStep * scaleY;
    }
}

