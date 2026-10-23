#include "include_asm.h"
#include "COMMON/GFX.H"
#include "abi.h"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJRECAT20V1.H"
#include "gbi.h"
#include "TYPES.H"
#include "COMMON/VIDEO_DIMENSIONS.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "RENDER/802909E0.H"
#include "RENDER/802909E0_8.H"
#include "GFX/TEXT/802A8A94_5.H"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted below with the other versions' body. */
#else
INCLUDE_ASM("span_1000", func_80290BD0_eu_x);
#endif
#endif

#if defined(VERSION_EU)
#ifdef NON_MATCHING
/* Drafted below with the other versions' body. */
#else
INCLUDE_ASM("span_1000", func_80290BA0_eu);
#endif
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1) || (defined(NON_MATCHING) && (defined(VERSION_EU) || defined(VERSION_EU_X)))
#if defined(NON_MATCHING) || defined(VERSION_US_REV1) || defined(VERSION_DE)
/* Sets up the loading-screen scene: resets the camera globals, loads the 0xE10 resource, builds a
 * look-at matrix from the state's field at 0x26DB0 scaled by D_800CA4B4, links it to the active view and
 * draws the backdrop through Render_DrawTextLines with half the video height. */
#include "RENDER/80291054_3.H"
extern s32 D_800D15E0, D_800D297C;
extern f32 D_800D15E4[4];
extern f32 D_800CA4B0, D_800CA4B4, D_800CA4B8;
extern char D_80141008;
#if defined(VERSION_DE)
extern s32 D_auto_800D303C;
#define D_auto_800D7068 D_auto_800D303C
#else
extern s32 D_auto_800D7068;
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern f32 D_auto_800C5678[2];
#endif
extern s32 func_8028B21C_de(void *, s32);
extern s32 func_8028C198_de(void *, s32);
extern void Camera_SetupViewportAndFog(void *);
extern void func_80272C60_de(void *, f32, f32, f32);
extern void func_802739C4_de(void *, f32);
extern void func_80273D6C_de(void *);
extern void func_8027027C_de(void *, void *);
extern void func_8026DF30_de(s32, void *, void *, s32, s32);
#undef LOAD_SETUP
#if defined(VERSION_EU)
#define LOAD_SETUP func_80290BA0_eu
#elif defined(VERSION_EU_X)
#define LOAD_SETUP func_80290BD0_eu_x
#elif defined(VERSION_DE)
#define LOAD_SETUP func_80290A90_de
#else
#define LOAD_SETUP func_80290A70_us_rev1
#endif
void LOAD_SETUP(ObjRecAt26DC1 *state) {
    s32 handle, h2;
    u8 matrix[0x40];

    D_800CC380 = 0;
    handle = func_8028B21C_de(&D_8011FE88, 0xE10);
    D_800D15E0 = 0;
    D_800D15E4[0] = D_800CA4B0;
    D_800D15E4[1] = D_800CA4B0;
    D_800D15E4[2] = D_800CA4B0;
    D_800D15E4[3] = D_800CA4B0;
    if (handle != -1) {
        Camera_SetupViewportAndFog(&D_80141008);
        func_80272C60_de(matrix, 0.0f, -100.0f, -500.0f);
        func_802739C4_de(matrix, state->unk26DB0 * D_800CA4B4);
        func_80273D6C_de(matrix);
        func_8027027C_de(matrix, VIEW_MATRICES + D_800D297C * 64);
        h2 = func_8028C198_de(&D_8011FE88, handle);
        func_8026D980_de();
        func_8026DF30_de(h2, VIEW_MATRICES + D_800D297C * 64, &D_800D0EF8, 0, -1);
        func_8026D9D0_de();
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        Render_DrawTextLines(state, 0, (void *)((s32 **)&D_800CA4B8)[D_80152789], D_800E28D0 / 2, 0xBE, 0xA, D_auto_800C5678[0], D_auto_800C5678[1]);
#else
        Render_DrawTextLines(state, 0, (void *)D_auto_800D7068, D_800E28D0 / 2, 0xBE, 0xA, D_800CA4B8, (&D_800CA4B8)[1]);
#endif
    }
}
#endif
#endif


#if !(defined(VERSION_US))
/* Clears the screen: clears the depth buffer over the whole screen through func_80291BE8_de, emits a full-screen scissor, the frame's colour image, fill cycle, combiner, no-op render mode, fill colour 0x10001 and a full-screen fill rectangle, then, when image 0x386 has a size, draws it stretched across the screen through func_802AAC28_de after func_802A9234_de(255). Written with libultra-style display-list macros and the screen size read from D_800E28D0 and D_800E28D4. */
extern Gfx *D_80110634;
#include "COMMON/DISPLAY.H"
extern void func_80291BE8_de(void *arg0, s32 ulx, s32 lrx, s32 uly, s32 lry, s32 interlaced);

extern void func_802A9234_de(s32 alpha);
void func_80290C24_de(void *arg0) {
    Frame *frame = D_8011BDC0;
    s32 width;
    s32 height;
    func_80291BE8_de(arg0, 0, SCREEN_WD, 0, SCREEN_HT, 0);
    width = 0;
    height = 0;
    gDPSetScissorFrac(D_80110634++, G_SC_NON_INTERLACE, (int)((float)((0)) * 4.0F), (int)((float)((0)) * 4.0F), (int)((float)((SCREEN_WD - 1)) * 4.0F), (int)((float)((SCREEN_HT - 1)) * 4.0F));
    gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, (u32)((frame->colorImage)));
    gDPSetCycleType(D_80110634++, G_CYC_FILL);
    gDPSetCombineLERP(D_80110634++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);
    gDPSetRenderMode(D_80110634++, ((0)), 0);
    gDPSetFillColor(D_80110634++, ((0x10001)));
    gDPFillRectangle(D_80110634++, 0, 0, (SCREEN_WD), (SCREEN_HT));
    func_802AA950_de(0x386, 0, &width, &height);
    if (width != 0 && height != 0) {
        func_802A9234_de(0xFF);
        func_802AAC28_de(0x386, 0, 0, 0, (f32)SCREEN_WD / (f32)width, (f32)SCREEN_HT / (f32)height, 1);
    }
}
#endif
