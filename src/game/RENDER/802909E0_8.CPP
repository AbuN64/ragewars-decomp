#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/GAME_SESSION.H"
#include "RENDER_4/8026AC38.H"
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
extern s32 D_800D297C;
extern f32 D_800CA4B0, D_800CA4B4, D_800CA4B8;
extern char D_80141008;
#if defined(VERSION_DE)
extern s32 D_auto_800D303C;
#define D_auto_800D7068 D_auto_800D303C
#else
extern s32 D_auto_800D7068;
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern f32 D_auto_800C5678[2];
#endif
extern s32 func_8028B21C_de(void *, s32);
extern s32 func_8028C198_de(void *, s32);
extern void Camera_SetupViewportAndFog(void *);
extern void Particle_BuildTranslationMatrix(void *, f32, f32, f32);
extern void YawMatrixLocal(void *, f32);
extern void SwapMatrixUpForward(void *);
extern void Rsp_ConvertMatrixToFixed(void *, void *);
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
    handle = func_8028B21C_de(&g_world, 0xE10);
    D_800D15E0 = 0;
    D_800D15E4[0] = D_800CA4B0;
    D_800D15E4[1] = D_800CA4B0;
    D_800D15E4[2] = D_800CA4B0;
    D_800D15E4[3] = D_800CA4B0;
    if (handle != -1) {
        Camera_SetupViewportAndFog(&D_80141008);
        Particle_BuildTranslationMatrix(matrix, 0.0f, -100.0f, -500.0f);
        YawMatrixLocal(matrix, state->unk26DB0 * D_800CA4B4);
        SwapMatrixUpForward(matrix);
        Rsp_ConvertMatrixToFixed(matrix, VIEW_MATRICES + D_800D297C * 64);
        h2 = func_8028C198_de(&g_world, handle);
        Render_BeginModelBatch();
        func_8026DF30_de(h2, VIEW_MATRICES + D_800D297C * 64, &D_800D0EF8, 0, -1);
        Render_FlushModelBatch();
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        Render_DrawTextLines(state, 0, (void *)((s32 **)&D_800CA4B8)[g_languageIndex], D_800E28D0 / 2, 0xBE, 0xA, D_auto_800C5678[0], D_auto_800C5678[1]);
#else
        Render_DrawTextLines(state, 0, (void *)D_auto_800D7068, D_800E28D0 / 2, 0xBE, 0xA, D_800CA4B8, (&D_800CA4B8)[1]);
#endif
    }
}
#endif
#endif


#if !(defined(VERSION_US))
/* Clears the screen: clears the depth buffer over the whole screen through Render_ClearDepthRect, emits a full-screen scissor, the frame's colour image, fill cycle, combiner, no-op render mode, fill colour 0x10001 and a full-screen fill rectangle, then, when image 0x386 has a size, draws it stretched across the screen through func_802AAC28_de after func_802A9234_de(255). Written with libultra-style display-list macros and the screen size read from D_800E28D0 and D_800E28D4. */
#include "COMMON/DISPLAY.H"
extern void Render_ClearDepthRect(void *arg0, s32 ulx, s32 lrx, s32 uly, s32 lry, s32 interlaced);

extern void Text_SetupSpriteMode(s32 alpha);
void func_80290C24_de(void *arg0) {
    Frame *frame = D_8011FAC0.ring.current;
    s32 width;
    s32 height;
    Render_ClearDepthRect(arg0, 0, SCREEN_WD, 0, SCREEN_HT, 0);
    width = 0;
    height = 0;
    gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
    gDPSetColorImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, (u32)((frame->colorImage)));
    gDPSetCycleType(g_displayListCursor++, G_CYC_FILL);
    gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);
    gDPSetRenderMode(g_displayListCursor++, ((0)), 0);
    gDPSetFillColor(g_displayListCursor++, ((0x10001)));
    gDPFillRectangle(g_displayListCursor++, 0, 0, (SCREEN_WD), (SCREEN_HT));
    func_802AA950_de(0x386, 0, &width, &height);
    if (width != 0 && height != 0) {
        Text_SetupSpriteMode(0xFF);
        func_802AAC28_de(0x386, 0, 0, 0, (f32)SCREEN_WD / (f32)width, (f32)SCREEN_HT / (f32)height, 1);
    }
}
#endif
