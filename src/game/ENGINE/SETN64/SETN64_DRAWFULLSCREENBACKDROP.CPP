#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#include "COMMON/GAME_SESSION.H"
#include "RENDER/MATERIAL_COLOR_AND_FOG_VIEWS.H"
#include "COMMON/GFX.H"
#include "abi.h"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJRECAT20V1.H"
#include "gbi.h"
#include "TYPES.H"
#include "COMMON/VIDEO_DIMENSIONS.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "RENDER/RECORD_OUTPUT_AND_TIMED_SESSION_VIEWS.H"
#include "RENDER/VIEW_MATRICES.H"
#include "GFX/TEXT/ONSCREEN_DRAWSCALEDMASKEDTILEGRID.H"

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Sets up the loading-screen scene: resets the camera globals, loads the 0xE10 resource, builds a
 * look-at matrix from the state's field at 0x26DB0 scaled by g_backdropYawRate, links it to the active view and
 * draws the backdrop through SetN64_DrawTextLines with half the video height. */
#include "RENDER/SETN64_DRAWTEXTLINES.H"
extern s32 g_lightingBufferIndex;
extern f32 g_backdropModelFillValue, g_backdropYawRate, g_backdropTextScalePair;
extern char g_fallbackScreenMessageEmitter;
#if defined(VERSION_DE)
extern s32 g_backdropTextLinesDe;
#define g_backdropTextLines g_backdropTextLinesDe
#else
extern s32 g_backdropTextLines;
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern s32 *g_backdropTextLinesByLanguage[];
#endif
extern s32 Scene_FindModelIdIndex(void *, s32);
extern s32 Scene_GetIndexedModelResource(void *, s32);
extern void Camera_SetupViewportAndFog(void *);
extern void Graphu64_BuildTranslationMatrix(void *, f32, f32, f32);
extern void YawMatrixLocal(void *, f32);
extern void SwapMatrixUpForward(void *);
extern void Graphu64_ConvertMatrixToFixed(void *, void *);
extern void Geometry_QueueDirectModel(s32, void *, void *, s32, s32);
#if defined(VERSION_EU)
void SetN64_SetupLoadingBackdropEu(TimedSessionTransitionView *state) {
#elif defined(VERSION_EU_X)
void SetN64_SetupLoadingBackdropEuX(TimedSessionTransitionView *state) {
#elif defined(VERSION_DE)
void SetN64_SetupLoadingBackdropDe(TimedSessionTransitionView *state) {
#else
void SetN64_SetupLoadingBackdropRev1(TimedSessionTransitionView *state) {
#endif
    s32 handle, h2;
    u8 matrix[0x40];

    g_geometryFogEffectEnabled = 0;
    handle = Scene_FindModelIdIndex(&g_world, 0xE10);
    g_menuModelFillEnabled = 0;
    g_menuModelFillColor[0] = g_backdropModelFillValue;
    g_menuModelFillColor[1] = g_backdropModelFillValue;
    g_menuModelFillColor[2] = g_backdropModelFillValue;
    g_menuModelFillColor[3] = g_backdropModelFillValue;
    if (handle != -1) {
        Camera_SetupViewportAndFog(&g_fallbackScreenMessageEmitter);
        Graphu64_BuildTranslationMatrix(matrix, 0.0f, -100.0f, -500.0f);
        YawMatrixLocal(matrix, state->transitionTimer * g_backdropYawRate);
        SwapMatrixUpForward(matrix);
        Graphu64_ConvertMatrixToFixed(matrix, VIEW_MATRICES + g_lightingBufferIndex * 64);
        h2 = Scene_GetIndexedModelResource(&g_world, handle);
        Geometry_BeginModelBatch();
        Geometry_QueueDirectModel(h2, VIEW_MATRICES + g_lightingBufferIndex * 64, &g_defaultParticleLighting, 0, -1);
        Geometry_FlushModelBatch();
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        SetN64_DrawTextLines(state, 0, (void *)g_backdropTextLinesByLanguage[g_languageIndex], g_hudReferenceViewportWidth / 2, 0xBE, 0xA, g_backdropTextScalePair, (&g_backdropTextScalePair)[1]);
#else
        SetN64_DrawTextLines(state, 0, (void *)g_backdropTextLines, g_hudReferenceViewportWidth / 2, 0xBE, 0xA, g_backdropTextScalePair, (&g_backdropTextScalePair)[1]);
#endif
    }
}
#endif


#if !(defined(VERSION_US))
/* Clears the screen: clears the depth buffer over the whole screen through SetN64_ClearDepthRect, emits a full-screen scissor, the frame's colour image, fill cycle, combiner, no-op render mode, fill colour 0x10001 and a full-screen fill rectangle, then, when image 0x386 has a size, draws it stretched across the screen through OnScreen_DrawSpriteResource after Onscrn_SetupSpriteMode_Setn64Drawfullscreenbackdrop(255). Written with libultra-style display-list macros and the screen size read from g_hudReferenceViewportWidth and g_hudReferenceViewportHeight. */
#include "COMMON/DISPLAY.H"
extern void SetN64_ClearDepthRect(void *unused, s32 ulx, s32 lrx, s32 uly, s32 lry, s32 interlaced);

extern void Onscrn_SetupSpriteMode(s32 alpha);
void SetN64_DrawFullscreenBackdrop(void *unused) {
    Frame *frame = g_gameSession.ring.current;
    s32 width;
    s32 height;
    SetN64_ClearDepthRect(unused, 0, SCREEN_WD, 0, SCREEN_HT, 0);
    width = 0;
    height = 0;
    gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
    gDPSetColorImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, (u32)((frame->colorImage)));
    gDPSetCycleType(g_displayListCursor++, G_CYC_FILL);
    gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);
    gDPSetRenderMode(g_displayListCursor++, ((0)), 0);
    gDPSetFillColor(g_displayListCursor++, ((0x10001)));
    gDPFillRectangle(g_displayListCursor++, 0, 0, (SCREEN_WD), (SCREEN_HT));
    OnScreen_GetImageDimensions(0x386, 0, &width, &height);
    if (width != 0 && height != 0) {
        Onscrn_SetupSpriteMode(0xFF);
        OnScreen_DrawSpriteResource(0x386, 0, 0, 0, (f32)SCREEN_WD / (f32)width, (f32)SCREEN_HT / (f32)height, 1);
    }
}
#endif
