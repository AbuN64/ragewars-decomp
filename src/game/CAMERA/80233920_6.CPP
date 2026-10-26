#include "include_asm.h"
#include "COMMON/LONE/D_800CD8D0.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/WORLD.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "GAME/CODE_8027302C.H"
struct CShakeAxis_t;
extern u32 Weapon_UpdateShakeAxis(struct CShakeAxis_t *state);

void Camera_UpdateFrustumBounds(char *);
int Cinema_IsSequenceInWindow(void);
void Cinema_UpdateSequenceTrack(void *);
f32 func_802459A0_de(void *);
float func_80245AD8_de(void);
void GraphU64_InvertAffineMatrix(f32 *, f32 *);
void GraphU64_MultiplyAffineMatrices(f32 *, f32 *, f32 *);
void GraphU64_MultiplyMatrices(f32 *, f32 *, f32 *);
void GraphU64_PackFixedMatrix(f32 *, void *);
void GraphU64_IdentityMatrix(void *);
void GraphU64_ClampMatrixToFixedRange(f32 *);
void GraphU64_BuildScaleMatrix(void *, f32, f32, f32);
void CopyMatrix(float *, float *);
void GraphU64_GetMatrixTranslation(char *, float *);
void BuildYawMatrix(void *, f32);
void PitchMatrix(void *, f32);
void YawMatrix(void *, f32);
void MatrixFromQuaternion(f32 *, f32 *);

extern void GraphU64_EaseValueToward(f32 *value, f32 target, f32 rate);
f32 Region_GetPolygonHeight(void *, f32, f32);
int Tsmos_IsFrontendActive(void);
int Tsmos_GetModeOneFlag(void);

void func_802B6F9C_de(float *, u16 *, float, float, float, float, float);

f32 Math_Sqrtf(f32);
void Pak_UpdateDialogList(void *);
s32 Camera_BlendEnvironmentColors();                        /* extern */
void Camera_BuildShakenViewTransform(void *);                        /* extern */
void Sky_UpdateSceneEffects(void *scene, void *host);                  /* extern */
               /* extern */
s32 func_802B6900_de(f32 *, f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */

extern void *D_80145060;
extern s32 D_80141008;
extern s32 D_800D297C;
extern f32 D_800D2988;
extern s32 D_800E28D0;
typedef struct Shared_func_80234FDC_S1 func_80234FDC_S1;
typedef struct GameplayCamera func_80234FDC_S2;
typedef struct Shared_func_80234FDC_S3 SharedRecV11;
typedef struct Shared_func_80234FDC_S4 func_80234FDC_S4;
typedef struct Shared_func_80234FDC_S5 SharedRecAt0V2;
typedef struct Lights SharedRecAt1A;
typedef struct Shared_func_80234FDC_S7 SharedRecV9;
typedef struct Shared_func_80234FDC_S8 func_80234FDC_S8;







typedef struct Shared_Func_80234FDC_Callback Func_80234FDC_Callback;
extern Func_80234FDC_Callback D_800CB384_de[];
extern func_80234FDC_S4 D_80140FF8;


/* unable to generate initializer: unknown type; const */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x268, 0x26c, 0x270, 0x274, 0x278, 0x27c, 0x280, 0x284, 0x288, 0x298, 0x29c, 0x2a8, 0x2ac, 0x2b0, 0x2b4], gap at: 0x28c. */
/* Updates the actor view and projection matrices and applies camera effects. */
void Camera_UpdateViewProjectionAndEffects(GameplayCamera *camera) {
    f32 ground_x;
    func_80234FDC_S8 *floorPolygon;
    f32 referenceViewMatrix[16];
    f32 composedViewMatrix[16];
    f32 halfTurnMatrix[16];
    f32 inverseRotatedView[16];
    f32 worldToViewMatrix[16];
    f32 right[16];
    f32 horizontalFlipMatrix[16];
    f32 matrix[16];
    f32 hudProjectionMatrix[16];
    s32 (*temp_v0)(s8 *);
    f32 farPlaneDistance;
    f32 projectionOrFloorScale;
    f32 baseHorizontalSlope;
    f32 div_stage; 
    f32 horizontalSlope;
    f32 floorSampleZ;
    f32 fovSine;
    f32 verticalSlope;
    f32 fovy;
    f32 floorHeightOffset;
    f32 aspect;
    f32 initial_zoom; 
    f32 floorSampleY;
    f32 temp_f24;
    f32 kickStepDelta;
    f32 bobBlendLimit;
    f32 lightZeroDirectionX;
    f32 lightZeroDirectionY;
    f32 lightZeroDirectionZ;
    f32 lightOneDirectionX;
    f32 lightOneDirectionY;
    f32 lightOneDirectionZ;
    f32 horizontalStretch;
    f32 bobRateBlend;
    f32 verticalStretch;
    s32 sequenceFarPlane;
    s32 fovOverrideState;
    s32 captured_state; 
    s32 kickStepOperand;
    s8 *viewProjectionMatrix;
    s8 *viewOrientationMatrix;
    u16 previousKickStep;
    u16 advancedKickStep;
    u16 clampedKickStep;

    SharedRecAt1A *frameLights;
    func_80234FDC_S1 *cameraOwner;
    func_80234FDC_S1 *actorCursor;
    SharedRecAt0V2 *state; 

    actorCursor = D_80145060;
    while (actorCursor != 0) {
        if (actorCursor->unk5DC == camera) {
            cameraOwner = actorCursor;
            goto actor_found;
        }
        actorCursor = actorCursor->unk16E0;
    }
    cameraOwner = 0;
actor_found:
    camera->elapsed = (f32) (camera->elapsed + D_800D2988);
    Camera_BlendEnvironmentColors(camera);
    camera->dirty = 1;
    if (Cinema_IsSequenceInWindow() == 0) {
        temp_v0 = D_800CB384_de[camera->mode].fn;
        if (temp_v0 != 0) {
            temp_v0(camera);
        }
    }
    frameLights = &camera->lights[D_800D297C];
    func_802B6900_de(referenceViewMatrix, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
    if ((Cinema_IsSequenceInWindow() != 0) && (camera != &D_80141008)) {
        Cinema_UpdateSequenceTrack(camera);
    }
    temp_f24 = camera->zoomBlend;
    initial_zoom = camera->zoomFov;
    Camera_BuildShakenViewTransform(camera);
    if (Cinema_IsSequenceInWindow() == 0) {
        Weapon_UpdateShakeAxis(camera->unkB8);
        Weapon_UpdateShakeAxis(camera->unkCC);
        Weapon_UpdateShakeAxis(camera->unkE0);
    }
    viewOrientationMatrix = (s8 *)camera->viewOrient;
    GraphU64_GetMatrixTranslation(viewOrientationMatrix, &camera->position.x);
    GraphU64_InvertAffineMatrix(camera->inverseViewOrient, (f32 *) viewOrientationMatrix);
    BuildYawMatrix(halfTurnMatrix, 3.1415927f);
    GraphU64_MultiplyAffineMatrices(composedViewMatrix, halfTurnMatrix, (f32 *) viewOrientationMatrix);
    GraphU64_InvertAffineMatrix(inverseRotatedView, composedViewMatrix);
    GraphU64_MultiplyAffineMatrices(worldToViewMatrix, inverseRotatedView, referenceViewMatrix);
    CopyMatrix(camera->worldToView, worldToViewMatrix);
    if ((cameraOwner != 0) && (cameraOwner->unk664 & 0x40) && (camera->unk24 == 0) && (Cinema_IsSequenceInWindow() == 0)) {
        f32 inverseBobRateBlend; 
        horizontalStretch = (((camera->bobAmplitudeX * 0.5f * (Math_Sinf(camera->bobPhaseX) + 1.0f)) + 0.8f) > 1.0f) ? 1.0f : ((camera->bobAmplitudeX * 0.5f * (Math_Sinf(camera->bobPhaseX) + 1.0f)) + 0.8f);
        camera->stretchX = horizontalStretch;
        verticalStretch = (((camera->bobAmplitudeY * 0.5f * (Math_Sinf(camera->bobPhaseY) + 1.0f)) + 0.9f) > 1.0f) ? 1.0f : ((camera->bobAmplitudeY * 0.5f * (Math_Sinf(camera->bobPhaseY) + 1.0f)) + 0.9f);
        camera->stretchY = verticalStretch;
        camera->bobPhaseX = (f32) (camera->bobPhaseX + (D_800D2988 * camera->bobRateX));
        camera->bobPhaseY = (f32) (camera->bobPhaseY + (D_800D2988 * camera->bobRateY));
        bobRateBlend = cameraOwner->unk6C8 * 2.5f;
        bobBlendLimit = 0.0f;
        if ((bobRateBlend < 0.0f) || (bobBlendLimit = 1.0f, (bobRateBlend > 1.0f))) {
            bobRateBlend = bobBlendLimit;
        }
        GraphU64_EaseValueToward(&camera->bobAmplitudeX, 0.1f, 0.5f);
        GraphU64_EaseValueToward(&camera->bobAmplitudeY, 0.05f, 0.5f);
        inverseBobRateBlend = 1.0f - bobRateBlend;
        GraphU64_EaseValueToward(&camera->bobRateX, (bobRateBlend * 0.104719765f) + (inverseBobRateBlend * 0.06981318f), 0.16666667f);
        GraphU64_EaseValueToward(&camera->bobRateY, (bobRateBlend * 0.087266475f) + (inverseBobRateBlend * 0.03490659f), 0.16666667f);
    } else {
        camera->stretchY = 1.0f;
        camera->stretchX = 1.0f;
    }
    previousKickStep = camera->kickStep;
    kickStepOperand = 0x32; 
    if (previousKickStep != kickStepOperand) {
        camera->stretchY = (f32) (((f32) (kickStepOperand - previousKickStep) * 0.08f) + 1.0f);
        kickStepDelta = D_800D2988 * 10.0f;
        if (!(kickStepDelta >= 2.1474836e9f)) {
            kickStepOperand = (s32) kickStepDelta;
        } else {
            kickStepOperand = (s32) (kickStepDelta - 2.1474836e9f) | 0x80000000;
        }
        advancedKickStep = camera->kickStep + kickStepOperand;
        clampedKickStep = advancedKickStep;
        camera->kickStep = advancedKickStep;
        if ((u32) (clampedKickStep & 0xFFFF) >= 0x33U) {
            clampedKickStep = 0x32;
        }
        camera->kickStep = clampedKickStep;
    }
    if (Cinema_IsSequenceInWindow() != 0) {
        fovy = func_802459A0_de(camera);
    } else {
        fovOverrideState = Tsmos_IsFrontendActive();
        if ((fovOverrideState == 1) && (Tsmos_GetModeOneFlag() == fovOverrideState)) {
            fovy = 45.0f;
        } else if (temp_f24 != 0.0f) {
            fovy = (temp_f24 * (initial_zoom - 75.0f)) + 75.0f;
        } else {
            fovy = 75.0f;
        }
    }
    if ((Cinema_IsSequenceInWindow() != 0) && (camera != &D_80141008)) {
        aspect = camera->viewWidth / camera->viewHeight;
    } else if (D_80140FF8.unk0 == 2) {
        aspect = 0.6666667f;
        if (D_80140FF8.unk122F == 0) {
            aspect = 2.666666f;
        }
    } else {
        aspect = 1.333333f;
    }
    fovy = fovy * 0.017453294f;
    fovSine = Math_Sinf(fovy);
    verticalSlope = fovSine / Math_Cosf(fovy);
    baseHorizontalSlope = verticalSlope * 1.2792794f;
    verticalSlope = baseHorizontalSlope / aspect;
    verticalSlope = verticalSlope / camera->stretchY;
    horizontalSlope = baseHorizontalSlope / camera->stretchX;
    projectionOrFloorScale = 1.0f; 
    fovy = GraphU64_ArcCos(Math_Sqrtf(projectionOrFloorScale / ((verticalSlope * verticalSlope) + 1.0f)));
    fovy = fovy * 57.295776f; 
    farPlaneDistance = camera->farPlane;
    aspect = horizontalSlope / verticalSlope;
    camera->aspect = aspect;
    camera->fovY = fovy;
    camera->farHalfWidth = (f32) (farPlaneDistance * horizontalSlope);
    camera->farHalfHeight = (f32) (farPlaneDistance * verticalSlope);
    if (Cinema_IsSequenceInWindow() != 0) {
        sequenceFarPlane = (s32) func_80245AD8_de();
        if (sequenceFarPlane > 0) {
            camera->farPlane = (f32) sequenceFarPlane;
        }
    }
    func_802B6F9C_de(right, &camera->perspNorm, fovy, aspect, 16.0f, camera->farPlane, 1.0f - (temp_f24 * 0.95f));
    GraphU64_BuildScaleMatrix(horizontalFlipMatrix, -1.0f, 1.0f, 1.0f);
    GraphU64_MultiplyMatrices(composedViewMatrix, worldToViewMatrix, (f32 *) right);
    viewProjectionMatrix = (s8 *)camera->viewProjection;
    GraphU64_MultiplyMatrices((f32 *) viewProjectionMatrix, composedViewMatrix, horizontalFlipMatrix);
    GraphU64_ClampMatrixToFixedRange((f32 *) viewProjectionMatrix);
    GraphU64_PackFixedMatrix((f32 *) viewProjectionMatrix, camera->projection[D_800D297C]);
    CopyMatrix(matrix, worldToViewMatrix);
    state = &D_80140FF8.state;
    if (state->unk0 == 4) {
        PitchMatrix(matrix, camera->elapsed * 0.010908309f);
        YawMatrix(matrix, camera->elapsed * 0.008726647f);
    }
    GraphU64_ClampMatrixToFixedRange(matrix);
    lightZeroDirectionX = matrix[0] * 128.0f;
    if (!(lightZeroDirectionX <= 127.0f)) {
        lightZeroDirectionX = 127.0f;
    }
    frameLights->light0DirX = (s8) (s32) lightZeroDirectionX;
    lightZeroDirectionY = matrix[4] * 128.0f;
    if (!(lightZeroDirectionY <= 127.0f)) {
        lightZeroDirectionY = 127.0f;
    }
    frameLights->light0DirY = (s8) (s32) lightZeroDirectionY;
    lightZeroDirectionZ = matrix[8] * 128.0f;
    if (!(lightZeroDirectionZ <= 127.0f)) {
        lightZeroDirectionZ = 127.0f;
    }
    frameLights->light0DirZ = (s8) (s32) lightZeroDirectionZ;
    lightOneDirectionX = matrix[1] * 128.0f;
    if (!(lightOneDirectionX <= 127.0f)) {
        lightOneDirectionX = 127.0f;
    }
    frameLights->light1DirX = (s8) (s32) lightOneDirectionX;
    lightOneDirectionY = matrix[5] * 128.0f;
    if (!(lightOneDirectionY <= 127.0f)) {
        lightOneDirectionY = 127.0f;
    }
    frameLights->light1DirY = (s8) (s32) lightOneDirectionY;
    lightOneDirectionZ = matrix[9] * 128.0f;
    if (!(lightOneDirectionZ <= 127.0f)) {
        lightOneDirectionZ = 127.0f;
    }
    frameLights->light1DirZ = (s8) (s32) lightOneDirectionZ;
    frameLights->light0R = 0;
    frameLights->light0G = 0;
    frameLights->light0B = 0;
    frameLights->light0PadA = 0;
    frameLights->light0CopyR = 0;
    frameLights->light0CopyG = 0;
    frameLights->light0CopyB = 0;
    frameLights->light0PadB = 0;
    frameLights->light1R = 0;
    frameLights->light1G = 0x80;
    frameLights->light1B = 0;
    frameLights->light1PadA = 0;
    frameLights->light1CopyR = 0;
    frameLights->light1CopyG = 0x80;
    frameLights->light1CopyB = 0;
    frameLights->light1PadB = 0;
    Camera_UpdateFrustumBounds(camera);
    MatrixFromQuaternion(&camera->unk150, camera->faceScreen);
    BuildYawMatrix(camera->faceScreenUpright, camera->roll);
    if (D_80140FF8.unk8 != 0) {
        func_802B6F9C_de(right, &camera->hudPerspNorm, 47.5f, (f32) ((s32) D_800E28D0 / D_800E28D4), 16.0f, 7168.0f, 1.0f);
        GraphU64_IdentityMatrix(worldToViewMatrix);
        GraphU64_MultiplyMatrices(composedViewMatrix, worldToViewMatrix, (f32 *) right);
        GraphU64_BuildScaleMatrix(horizontalFlipMatrix, -1.0f, 1.0f, 1.0f);
        GraphU64_MultiplyMatrices(hudProjectionMatrix, composedViewMatrix, horizontalFlipMatrix);
        GraphU64_ClampMatrixToFixedRange(hudProjectionMatrix);
        GraphU64_PackFixedMatrix(hudProjectionMatrix, camera->hudProjection[D_800D297C]);
    }
    Sky_UpdateSceneEffects(&camera->sceneEffects, camera);
    Pak_UpdateDialogList(&camera->messageList);
    if (Cinema_IsSequenceInWindow() != 0) {
        camera->floorPoly = ((void *(*)())Scene_FindFloorPolygon)(&g_world, &camera->unk38);
    }
    captured_state = D_800CD8D0;
    camera->floorSurface = captured_state;
    floorPolygon = camera->floorPoly;
    ground_x = camera->unk38;
    floorSampleY = camera->unk3C;
    floorSampleZ = camera->unk40;
    floorHeightOffset = camera->unk44;
    if ((floorPolygon != 0) && (Cinema_IsSequenceInWindow() == 0)) {
        projectionOrFloorScale = ((floorSampleY + floorHeightOffset) - Region_GetPolygonHeight(floorPolygon, ground_x, floorSampleZ)) * 0.09765625f;
        if ((projectionOrFloorScale < 11.0f) && (projectionOrFloorScale > 5.0f)) {
            camera->floorSurface = (s32) floorPolygon->unk1C;
        }
    }
    if (Cinema_IsSequenceInWindow() != 0) {
        camera->floorSurface = (s32) D_800CD8D0;
    }
    if (camera->zoomBlend > 0.0f) {
        camera->floorSurface = (s32) D_800CD8D0;
    }
}

#include "COMMON/VIEWFLAGS.H"
#include "COMMON/GFX.H"
#include "COMMON/VIDEO_DIMENSIONS.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "gbi.h"
extern Gfx D_800CBCC0[], D_800CBCF0_de[];
extern s32 D_800D297C, D_800E28D0;
extern Gfx *g_displayListCursor;
#include "COMMON/DISPLAY.H"
extern Shared_func_80234FDC_S4 D_80140FF8;
#include "COMMON/GAME_SESSION.H"
extern void Geometry_SetViewEffect(s32);
extern void TextLoad_SetTextureEffect(s32);
extern void Geometry_SelectEffectModes(void);
extern void TextLoad_ResetTextureCache(void);
extern s32 Tsmos_IsFrontendActive(void), GetMenuScreenOwner(void);
extern s32 Geometry_SetModePreset(s32);
extern void SetN64_ClearDepthRect(void *, s32, s32, s32, s32, s32);
extern s32 Cinema_IsSequenceInWindow(void);
extern u32 func_80245AF8_de(void);
extern void Geometry_SetColorDither(s32);
extern void Defs_SetupPointLights(void *);
/* Splits a 0x00BBGGRR fade color into its three fog/fill channels. */
static inline void Camera_UnpackColor(u32 color, u8 *red, u8 *green, u8 *blue) {
    *blue = color >> 16;
    *green = color >> 8;
    *red = color;
}

/* Set projection, viewport and look-at, then draw the view's clear rectangle and fog. */
void Camera_SetupViewportAndFog(Racer *view) {
    u8 red, green, blue;
    s16 uly, ulx, lrx, lry;
    s32 flag;
    u32 color;
    s16 vx, vy;
    s16 maxx, maxy;
    f32 width, height, x, y;
    Frame *buffer;
    s32 frame;
    Gfx **gfx = &g_displayListCursor;

    gDPPipeSync((*gfx)++);
    gSPDisplayList((*gfx)++, D_800CBCC0);
    gSPDisplayList((*gfx)++, D_800CBCF0_de);
    view->screenScaleX = 1.0f;
    view->screenScaleY = 1.0f;
    view->screenScaleX = view->viewportScaleX;
    view->screenScaleY = view->viewportScaleY;
    x = view->viewportX;
    y = view->viewportY;
    width = view->viewportWidth;
    maxx = SCREEN_WD - 1;
    height = view->viewportHeight;
    ulx = x;
    maxy = SCREEN_HT - 1;
    vx = (width + width) * view->screenScaleX;
    vy = (height + height) * view->screenScaleY;
    uly = y;
    lrx = x + width;
    lry = y + height;
    if (lrx > SCREEN_WD - 1) {
        lrx = maxx;
    }
    if (ulx < 0) {
        ulx = 0;
    }
    if (uly < 0) {
        uly = 0;
    }
    if (lry > SCREEN_HT - 1) {
        lry = maxy;
    }
    buffer = D_8011FAC0.ring.current;
    frame = D_800D297C;
    gSPMatrix((*gfx)++, view->projectionMatrices[frame], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPPerspNormalize((*gfx)++, view->perspectiveNorm);
    view->viewports[frame].vscale[0] = vx;
    view->viewports[frame].vscale[1] = vy;
    view->viewports[frame].vtrans[0] = (vx * 0.25f + view->viewportX) * 4.0f;
    view->viewports[frame].vtrans[1] = (vy * 0.25f + view->viewportY) * 4.0f;
    gSPViewport((*gfx)++, &view->viewports[frame]);
    gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, ulx, uly, lrx, lry);
    gSPLookAtX((*gfx)++, &view->lights[frame][0]);
    gSPLookAtY((*gfx)++, &view->lights[frame][4]);
    Geometry_SetViewEffect(view->effect);
    if (view != &D_80140FF8.view) {
        TextLoad_SetTextureEffect(view->effect);
    }
    Geometry_SelectEffectModes();
    TextLoad_ResetTextureCache();
    gDPSetTextureFilter(g_displayListCursor++, G_TF_BILERP);
    flag = 0;
    if (Tsmos_IsFrontendActive() != 0) {
        flag = GetMenuScreenOwner() != 2;
    }
    if (view != &D_80140FF8.view || D_80140FF8.unk0 == 0 || flag != 0) {
        Geometry_SetModePreset(20);
        gDPPipeSync(g_displayListCursor++);
        SetN64_ClearDepthRect(&D_8011FAC0, ulx, lrx, uly, lry, view->effect);
        gDPSetCycleType(g_displayListCursor++, G_CYC_FILL);
        if (D_801462C8.flags & 0x4000) {
            red = 0;
            green = 0;
            blue = 0;
        } else {
            red = view->hit & 0xF8;
            green = view->boost & 0xF8;
            blue = view->spin & 0xF8;
        }
        if (Cinema_IsSequenceInWindow() != 0) {
            color = func_80245AF8_de();
            if (color != 0xFF00) {
                Camera_UnpackColor(color, &red, &green, &blue);
            }
        }
        gSPGeometryMode(g_displayListCursor++, 0, G_FOG);
        if (view->effect != 0) {
            gDPSetFogColor(g_displayListCursor++, 0, 0, 0, 255);
            gSPFogPosition(g_displayListCursor++, 995, 1000);
        } else {
            gDPSetFogColor(g_displayListCursor++, red, green, blue, 255);
            gSPFogPosition(g_displayListCursor++, (u16)view->fogNear, 1000);
        }
        gDPSetColorImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, buffer->colorImage);
        if (view->effect != 0) {
            gDPSetFillColor(g_displayListCursor++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
        } else {
            gDPSetFillColor(g_displayListCursor++, (GPACK_RGBA5551(red, green, blue, 1) << 16) |
                                              GPACK_RGBA5551(red, green, blue, 1));
        }
        if (view != &D_80140FF8.view || D_80140FF8.state.unk0 == 3) {
            gDPFillRectangle(g_displayListCursor++, ulx, uly, lrx, lry);
        }
    }
    gDPPipeSync(g_displayListCursor++);
    Geometry_SetColorDither(0);
    gDPSetAlphaDither(g_displayListCursor++, G_AD_NOTPATTERN);
    gDPSetCycleType(g_displayListCursor++, G_CYC_2CYCLE);
    if (view != &D_80140FF8.view) {
        Defs_SetupPointLights(view);
    }
    gDPPipeSync(g_displayListCursor++);
}
