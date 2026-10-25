#include "include_asm.h"
#include "COMMON/LONE/D_800CD8D0.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/WORLD.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "GAME/CODE_8027302C.H"
struct StateRecAt10;
extern u32 func_802337D0_de(struct StateRecAt10 *state);

void func_80234DE0_de(char *);
int Camera_IsSequenceInWindow(void);
void func_80245864_de(void *);
f32 func_802459A0_de(void *);
float func_80245AD8_de(void);
void func_8026EF58_de(f32 *, f32 *);
void Rsp_MultiplyAffineMatrices(f32 *, f32 *, f32 *);
void func_8026F898_de(f32 *, f32 *, f32 *);
void func_8026FC9C_de(f32 *, void *);
void func_802727D8_de(void *);
void func_80272828_de(f32 *);
void func_80272CB0_de(void *, f32, f32, f32);
void func_8027302C(float *, float *);
void func_802732D0_de(char *, float *);
void func_802736D4_de(void *, f32);
void func_802738C0_de(void *, f32);
void func_80273A98_de(void *, f32);
void MatrixFromQuaternion(f32 *, f32 *);

extern void Nav_EaseValueToward(f32 *value, f32 target, f32 rate);
f32 Anim_GetPolygonHeight(void *, f32, f32);
int func_802A23B4_de(void);
int func_802A23F0_de(void);

void func_802B6F9C_de(float *, u16 *, float, float, float, float, float);

f32 func_802B72B0_de(f32);
void func_804428F8_de(void *);
s32 func_802343C8_de();                        /* extern */
void func_802349C0_de(void *);                        /* extern */
void Sched_UpdateSceneEffects(void *scene, void *host);                  /* extern */
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
void func_80234FEC_de(GameplayCamera *camera) {
    f32 ground_x;
    func_80234FDC_S8 *temp_s0_2;
    f32 sp28[16];
    f32 sp68[16];
    f32 spA8[16];
    f32 spE8[16];
    f32 sp128[16];
    f32 right[16];
    f32 sp1A8[16];
    f32 matrix[16];
    f32 sp228[16];
    s32 (*temp_v0)(s8 *);
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20_2;
    f32 div_stage; 
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f21;
    f32 temp_f21_3;
    f32 fovy;
    f32 temp_f22_3;
    f32 aspect;
    f32 initial_zoom; 
    f32 temp_f23_3;
    f32 temp_f24;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f0_5;
    f32 var_f0_6;
    f32 var_f0_7;
    f32 var_f1;
    f32 var_f22;
    f32 var_f4;
    s32 temp_f5;
    s32 temp_v0_4;
    s32 captured_state; 
    s32 var_v1_2;
    s8 *temp_s0;
    s8 *var_s1;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 var_v1_3;

    SharedRecAt1A *temp_s4;
    func_80234FDC_S1 *var_s5;
    func_80234FDC_S1 *var_v1;
    SharedRecAt0V2 *state; 

    var_v1 = D_80145060;
    while (var_v1 != 0) {
        if (var_v1->unk5DC == camera) {
            var_s5 = var_v1;
            goto actor_found;
        }
        var_v1 = var_v1->unk16E0;
    }
    var_s5 = 0;
actor_found:
    camera->unk18 = (f32) (camera->unk18 + D_800D2988);
    func_802343C8_de(camera);
    camera->unk7C = 1;
    if (Camera_IsSequenceInWindow() == 0) {
        temp_v0 = D_800CB384_de[camera->unk14].fn;
        if (temp_v0 != 0) {
            temp_v0(camera);
        }
    }
    temp_s4 = &camera->lights[D_800D297C];
    func_802B6900_de(sp28, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
    if ((Camera_IsSequenceInWindow() != 0) && (camera != &D_80141008)) {
        func_80245864_de(camera);
    }
    temp_f24 = camera->unk5C;
    initial_zoom = camera->unk60;
    func_802349C0_de(camera);
    if (Camera_IsSequenceInWindow() == 0) {
        func_802337D0_de(camera->unkB8);
        func_802337D0_de(camera->unkCC);
        func_802337D0_de(camera->unkE0);
    }
    var_s1 = &camera->unk160;
    func_802732D0_de(var_s1, &camera->position.x);
    func_8026EF58_de(&camera->unk1A0, (f32 *) var_s1);
    func_802736D4_de(spA8, 3.1415927f);
    Rsp_MultiplyAffineMatrices(sp68, spA8, (f32 *) var_s1);
    func_8026EF58_de(spE8, sp68);
    Rsp_MultiplyAffineMatrices(sp128, spE8, sp28);
    func_8027302C(&camera->unk220, sp128);
    if ((var_s5 != 0) && (var_s5->unk664 & 0x40) && (camera->unk24 == 0) && (Camera_IsSequenceInWindow() == 0)) {
        f32 temp_f20; 
        var_f1 = (((camera->unk88 * 0.5f * (func_802B7130_de(camera->unk90) + 1.0f)) + 0.8f) > 1.0f) ? 1.0f : ((camera->unk88 * 0.5f * (func_802B7130_de(camera->unk90) + 1.0f)) + 0.8f);
        camera->unk80 = var_f1;
        var_f4 = (((camera->unk8C * 0.5f * (func_802B7130_de(camera->unk94) + 1.0f)) + 0.9f) > 1.0f) ? 1.0f : ((camera->unk8C * 0.5f * (func_802B7130_de(camera->unk94) + 1.0f)) + 0.9f);
        camera->unk84 = var_f4;
        camera->unk90 = (f32) (camera->unk90 + (D_800D2988 * camera->unk98));
        camera->unk94 = (f32) (camera->unk94 + (D_800D2988 * camera->unk9C));
        var_f22 = var_s5->unk6C8 * 2.5f;
        var_f0 = 0.0f;
        if ((var_f22 < 0.0f) || (var_f0 = 1.0f, (var_f22 > 1.0f))) {
            var_f22 = var_f0;
        }
        Nav_EaseValueToward(&camera->unk88, 0.1f, 0.5f);
        Nav_EaseValueToward(&camera->unk8C, 0.05f, 0.5f);
        temp_f20 = 1.0f - var_f22;
        Nav_EaseValueToward(&camera->unk98, (var_f22 * 0.104719765f) + (temp_f20 * 0.06981318f), 0.16666667f);
        Nav_EaseValueToward(&camera->unk9C, (var_f22 * 0.087266475f) + (temp_f20 * 0.03490659f), 0.16666667f);
    } else {
        camera->unk84 = 1.0f;
        camera->unk80 = 1.0f;
    }
    temp_v0_2 = camera->unk124;
    var_v1_2 = 0x32; 
    if (temp_v0_2 != var_v1_2) {
        camera->unk84 = (f32) (((f32) (var_v1_2 - temp_v0_2) * 0.08f) + 1.0f);
        temp_f2 = D_800D2988 * 10.0f;
        if (!(temp_f2 >= 2.1474836e9f)) {
            var_v1_2 = (s32) temp_f2;
        } else {
            var_v1_2 = (s32) (temp_f2 - 2.1474836e9f) | 0x80000000;
        }
        temp_v0_3 = camera->unk124 + var_v1_2;
        var_v1_3 = temp_v0_3;
        camera->unk124 = temp_v0_3;
        if ((u32) (var_v1_3 & 0xFFFF) >= 0x33U) {
            var_v1_3 = 0x32;
        }
        camera->unk124 = var_v1_3;
    }
    if (Camera_IsSequenceInWindow() != 0) {
        fovy = func_802459A0_de(camera);
    } else {
        temp_v0_4 = func_802A23B4_de();
        if ((temp_v0_4 == 1) && (func_802A23F0_de() == temp_v0_4)) {
            fovy = 45.0f;
        } else if (temp_f24 != 0.0f) {
            fovy = (temp_f24 * (initial_zoom - 75.0f)) + 75.0f;
        } else {
            fovy = 75.0f;
        }
    }
    if ((Camera_IsSequenceInWindow() != 0) && (camera != &D_80141008)) {
        aspect = camera->unk29C / camera->unk2A0;
    } else if (D_80140FF8.unk0 == 2) {
        aspect = 0.6666667f;
        if (D_80140FF8.unk122F == 0) {
            aspect = 2.666666f;
        }
    } else {
        aspect = 1.333333f;
    }
    fovy = fovy * 0.017453294f;
    temp_f21 = func_802B7130_de(fovy);
    temp_f21_3 = temp_f21 / func_802B6560_de(fovy);
    temp_f20_2 = temp_f21_3 * 1.2792794f;
    temp_f21_3 = temp_f20_2 / aspect;
    temp_f21_3 = temp_f21_3 / camera->unk84;
    temp_f20_3 = temp_f20_2 / camera->unk80;
    temp_f1 = 1.0f; 
    fovy = Nav_ArcCos(func_802B72B0_de(temp_f1 / ((temp_f21_3 * temp_f21_3) + 1.0f)));
    fovy = fovy * 57.295776f; 
    temp_f0 = camera->unk528;
    aspect = temp_f20_3 / temp_f21_3;
    camera->aspect = aspect;
    camera->fovY = fovy;
    camera->unk74 = (f32) (temp_f0 * temp_f20_3);
    camera->unk78 = (f32) (temp_f0 * temp_f21_3);
    if (Camera_IsSequenceInWindow() != 0) {
        temp_f5 = (s32) func_80245AD8_de();
        if (temp_f5 > 0) {
            camera->unk528 = (f32) temp_f5;
        }
    }
    func_802B6F9C_de(right, &camera->unk68, fovy, aspect, 16.0f, camera->unk528, 1.0f - (temp_f24 * 0.95f));
    func_80272CB0_de(sp1A8, -1.0f, 1.0f, 1.0f);
    func_8026F898_de(sp68, sp128, (f32 *) right);
    temp_s0 = &camera->unk1E0;
    func_8026F898_de((f32 *) temp_s0, sp68, sp1A8);
    func_80272828_de((f32 *) temp_s0);
    func_8026FC9C_de((f32 *) temp_s0, camera->unk380[D_800D297C]);
    func_8027302C(matrix, sp128);
    state = &D_80140FF8.state;
    if (state->unk0 == 4) {
        func_802738C0_de(matrix, camera->unk18 * 0.010908309f);
        func_80273A98_de(matrix, camera->unk18 * 0.008726647f);
    }
    func_80272828_de(matrix);
    var_f0_2 = matrix[0] * 128.0f;
    if (!(var_f0_2 <= 127.0f)) {
        var_f0_2 = 127.0f;
    }
    temp_s4->unk8 = (s8) (s32) var_f0_2;
    var_f0_3 = matrix[4] * 128.0f;
    if (!(var_f0_3 <= 127.0f)) {
        var_f0_3 = 127.0f;
    }
    temp_s4->unk9 = (s8) (s32) var_f0_3;
    var_f0_4 = matrix[8] * 128.0f;
    if (!(var_f0_4 <= 127.0f)) {
        var_f0_4 = 127.0f;
    }
    temp_s4->unkA = (s8) (s32) var_f0_4;
    var_f0_5 = matrix[1] * 128.0f;
    if (!(var_f0_5 <= 127.0f)) {
        var_f0_5 = 127.0f;
    }
    temp_s4->unk18 = (s8) (s32) var_f0_5;
    var_f0_6 = matrix[5] * 128.0f;
    if (!(var_f0_6 <= 127.0f)) {
        var_f0_6 = 127.0f;
    }
    temp_s4->unk19 = (s8) (s32) var_f0_6;
    var_f0_7 = matrix[9] * 128.0f;
    if (!(var_f0_7 <= 127.0f)) {
        var_f0_7 = 127.0f;
    }
    temp_s4->unk1A = (s8) (s32) var_f0_7;
    temp_s4->unk0 = 0;
    temp_s4->unk1 = 0;
    temp_s4->unk2 = 0;
    temp_s4->unk3 = 0;
    temp_s4->unk4 = 0;
    temp_s4->unk5 = 0;
    temp_s4->unk6 = 0;
    temp_s4->unk7 = 0;
    temp_s4->unk10 = 0;
    temp_s4->unk11 = 0x80;
    temp_s4->unk12 = 0;
    temp_s4->unk13 = 0;
    temp_s4->unk14 = 0;
    temp_s4->unk15 = 0x80;
    temp_s4->unk16 = 0;
    temp_s4->unk17 = 0;
    func_80234DE0_de(camera);
    MatrixFromQuaternion(&camera->unk150, &camera->unkE54);
    func_802736D4_de(&camera->unkE94, camera->unk138);
    if (D_80140FF8.unk8 != 0) {
        func_802B6F9C_de(right, &camera->unk440, 47.5f, (f32) ((s32) D_800E28D0 / D_800E28D4), 16.0f, 7168.0f, 1.0f);
        func_802727D8_de(sp128);
        func_8026F898_de(sp68, sp128, (f32 *) right);
        func_80272CB0_de(sp1A8, -1.0f, 1.0f, 1.0f);
        func_8026F898_de(sp228, sp68, sp1A8);
        func_80272828_de(sp228);
        func_8026FC9C_de(sp228, camera->unk448[D_800D297C]);
    }
    Sched_UpdateSceneEffects(&camera->unk570, camera);
    func_804428F8_de(&camera->messageList);
    if (Camera_IsSequenceInWindow() != 0) {
        camera->unk58 = ((void *(*)())Scene_FindFloorPolygon)(&D_8011FE88, &camera->unk38);
    }
    captured_state = D_800CD8D0;
    camera->unk64 = captured_state;
    temp_s0_2 = camera->unk58;
    ground_x = camera->unk38;
    temp_f23_3 = camera->unk3C;
    temp_f20_4 = camera->unk40;
    temp_f22_3 = camera->unk44;
    if ((temp_s0_2 != 0) && (Camera_IsSequenceInWindow() == 0)) {
        temp_f1 = ((temp_f23_3 + temp_f22_3) - Anim_GetPolygonHeight(temp_s0_2, ground_x, temp_f20_4)) * 0.09765625f;
        if ((temp_f1 < 11.0f) && (temp_f1 > 5.0f)) {
            camera->unk64 = (s32) temp_s0_2->unk1C;
        }
    }
    if (Camera_IsSequenceInWindow() != 0) {
        camera->unk64 = (s32) D_800CD8D0;
    }
    if (camera->unk5C > 0.0f) {
        camera->unk64 = (s32) D_800CD8D0;
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
extern Gfx *D_80110634;
#include "COMMON/DISPLAY.H"
extern Shared_func_80234FDC_S4 D_80140FF8;
#include "COMMON/GAME_SESSION.H"
extern void Rsp_SetViewEffect(s32);
extern void System_SetTextureEffect(s32);
extern void Render_SelectEffectModes(void);
extern void System_ResetTextureCache(void);
extern s32 func_802A23B4_de(void), GetMenuScreenOwner(void);
extern s32 Render_SetModePreset(s32);
extern void Render_ClearDepthRect(void *, s32, s32, s32, s32, s32);
extern s32 Camera_IsSequenceInWindow(void);
extern u32 func_80245AF8_de(void);
extern void Render_SetColorDither(s32);
extern void System_SetupPointLights(void *);
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
    Gfx **gfx = &D_80110634;

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
    Rsp_SetViewEffect(view->effect);
    if (view != &D_80140FF8.view) {
        System_SetTextureEffect(view->effect);
    }
    Render_SelectEffectModes();
    System_ResetTextureCache();
    gDPSetTextureFilter(D_80110634++, G_TF_BILERP);
    flag = 0;
    if (func_802A23B4_de() != 0) {
        flag = GetMenuScreenOwner() != 2;
    }
    if (view != &D_80140FF8.view || D_80140FF8.unk0 == 0 || flag != 0) {
        Render_SetModePreset(20);
        gDPPipeSync(D_80110634++);
        Render_ClearDepthRect(&D_8011FAC0, ulx, lrx, uly, lry, view->effect);
        gDPSetCycleType(D_80110634++, G_CYC_FILL);
        if (D_801462C8.flags & 0x4000) {
            red = 0;
            green = 0;
            blue = 0;
        } else {
            red = view->hit & 0xF8;
            green = view->boost & 0xF8;
            blue = view->spin & 0xF8;
        }
        if (Camera_IsSequenceInWindow() != 0) {
            color = func_80245AF8_de();
            if (color != 0xFF00) {
                Camera_UnpackColor(color, &red, &green, &blue);
            }
        }
        gSPGeometryMode(D_80110634++, 0, G_FOG);
        if (view->effect != 0) {
            gDPSetFogColor(D_80110634++, 0, 0, 0, 255);
            gSPFogPosition(D_80110634++, 995, 1000);
        } else {
            gDPSetFogColor(D_80110634++, red, green, blue, 255);
            gSPFogPosition(D_80110634++, (u16)view->fogNear, 1000);
        }
        gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, buffer->colorImage);
        if (view->effect != 0) {
            gDPSetFillColor(D_80110634++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
        } else {
            gDPSetFillColor(D_80110634++, (GPACK_RGBA5551(red, green, blue, 1) << 16) |
                                              GPACK_RGBA5551(red, green, blue, 1));
        }
        if (view != &D_80140FF8.view || D_80140FF8.state.unk0 == 3) {
            gDPFillRectangle(D_80110634++, ulx, uly, lrx, lry);
        }
    }
    gDPPipeSync(D_80110634++);
    Render_SetColorDither(0);
    gDPSetAlphaDither(D_80110634++, G_AD_NOTPATTERN);
    gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
    if (view != &D_80140FF8.view) {
        System_SetupPointLights(view);
    }
    gDPPipeSync(D_80110634++);
}
