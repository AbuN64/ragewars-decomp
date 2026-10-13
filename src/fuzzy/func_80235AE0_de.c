#include "span_1000/code_80233920.h"
#include "gfx.h"
#include "gbi.h"
extern Gfx *D_80110634;
extern Frame *D_8011BDC0;
extern Racer D_80141008;
extern s32 D_800D297C, D_800E28D0, D_800E28D4;
extern s32 D_80140FF8, D_801462C8, D_80146878;
extern char D_800CBCC0, D_800CBCF0_de, D_8011FAC0;
extern f32 D_800C32B8_de, D_800C32BC_de, D_800C32C0_de;
extern void func_8026E330_de(s32);
extern void func_80296004_de(s32);
extern void func_8026D88C_de(void);
extern void func_80295FF4_de(void);
extern s32 func_802A23B4_de(void);
extern s32 func_80299958_de(void);
extern s32 func_8026925C_de(s32);
extern void func_80291BE8_de(void *, s32, s32, s32, s32, s32);
extern s32 func_80245798_de(void);
extern s32 func_80245AF8_de(void);
extern void func_8026D914_de(s32);
extern void func_802659E0_de(Racer *);

/* Configure this view's projection, viewport, scissor, lights and fog,
 * then clear its color rectangle before drawing the scene. */
void func_80235AE0_de(Racer *view)
{
    s16 left, top, right, bottom;
    s32 frame, special, color, denominator;
    u32 packed;
    u8 red, green, blue;
    f32 width, height, sx, sy;
    UnitVp *vp;
    Gfx *dl;
    Frame *buffer;
    frame = D_800D297C;
    buffer = D_8011BDC0;
    dl = D_80110634;
    gDPPipeSync(&dl[0]);
    gSPDisplayList(&dl[1], &D_800CBCC0);
    gSPDisplayList(&dl[2], &D_800CBCF0_de);
    sx = view->viewportScaleX; sy = view->viewportScaleY;
    width = view->viewportWidth; height = view->viewportHeight;
    view->screenScaleX = D_800C32B8_de;
    view->screenScaleY = D_800C32B8_de;
    view->screenScaleX = sx; view->screenScaleY = sy;
    left = (s32)view->viewportX; top = (s32)view->viewportY;
    right = (s32)(view->viewportX + width);
    bottom = (s32)(view->viewportY + height);
    if (right > D_800E28D0 - 1) right = D_800E28D0 - 1;
    if (left < 0) left = 0;
    if (top < 0) top = 0;
    if (bottom > D_800E28D4 - 1) bottom = D_800E28D4 - 1;
    gSPMatrix(&dl[3], view->projectionMatrices[frame], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMoveWord(&dl[4], G_MW_PERSPNORM, 0, view->perspectiveNorm);
    vp = &view->viewports[frame];
    vp->vscale[0] = (s32)((width + width) * sx);
    vp->vscale[1] = (s32)((height + height) * sy);
    vp->vtrans[0] = (s32)((vp->vscale[0] * D_800C32BC_de + view->viewportX) * D_800C32C0_de);
    vp->vtrans[1] = (s32)((vp->vscale[1] * D_800C32BC_de + view->viewportY) * D_800C32C0_de);
    gSPMoveMem(&dl[5], G_MV_VIEWPORT, 0, 16, vp);
    gDPSetScissorFrac(&dl[6], G_SC_NON_INTERLACE, (s32)(left * D_800C32C0_de), (s32)(top * D_800C32C0_de), (s32)(right * D_800C32C0_de), (s32)(bottom * D_800C32C0_de));
    gSPMoveMem(&dl[7], G_MV_LIGHT, 0, 16, &view->lights[frame][0]);
    gSPMoveMem(&dl[8], G_MV_LIGHT, 24, 16, &view->lights[frame][4]);
    D_80110634 = dl + 9;
    func_8026E330_de(view->effect);
    if (view != &D_80141008) func_80296004_de(view->effect);
    special = 0;
    func_8026D88C_de(); func_80295FF4_de();
    dl = D_80110634++;
    gDPSetTextureFilter(dl, G_TF_BILERP);
    if (func_802A23B4_de()) special = func_80299958_de() != 2;
    if (view != &D_80141008 || D_80140FF8 == 0 || special) {
        func_8026925C_de(0x14);
        dl = D_80110634++;
        gDPPipeSync(dl);
        func_80291BE8_de(&D_8011FAC0, left, right, top, bottom, view->effect);
        dl = D_80110634++;
        gDPSetCycleType(dl, G_CYC_FILL);
        if (!(D_801462C8 & 0x4000)) {
            red = view->hit & 0xF8; green = view->boost & 0xF8; blue = view->spin & 0xF8;
        } else { red = green = blue = 0; }
        if (func_80245798_de()) {
            color = func_80245AF8_de();
            if (color != 0xFF00) { red = color; green = color >> 8; blue = color >> 16; }
        }
        dl = D_80110634;
        gSPGeometryMode(&dl[0], 0, G_FOG);
        if (!view->effect) {
            gDPSetFogColor(&dl[1], red, green, blue, 255);
            denominator = 1000 - view->fogNear;
            gSPMoveWord(&dl[2], G_MW_FOG, 0, ((128000 / denominator) << 16) | (((500 - view->fogNear) * 256 / denominator) & 0xFFFF));
        } else {
            gDPSetFogColor(&dl[1], 0, 0, 0, 255);
            gSPMoveWord(&dl[2], G_MW_FOG, 0, 0x64009D00);
        }
        gDPSetColorImage(&dl[3], G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, buffer->colorImage);
        if (!view->effect) {
            packed = ((red & 0xF8) << 8) | ((green & 0xF8) << 3) | ((blue >> 2) & 0x3E);
            gDPSetFillColor(&dl[4], ((packed | 1) << 16) | packed | 1);
        } else { gDPSetFillColor(&dl[4], 0x10001); }
        D_80110634 = dl + 5;
        if (view != &D_80141008 || D_80146878 == 3) {
            dl = D_80110634++;
            gDPFillRectangle(dl, left, top, right, bottom);
        }
    }
    dl = D_80110634++;
    gDPPipeSync(dl);
    func_8026D914_de(0);
    dl = D_80110634;
    gDPSetColorDither(&dl[0], G_CD_BAYER);
    gDPSetCycleType(&dl[1], G_CYC_2CYCLE);
    D_80110634 = dl + 2;
    if (view != &D_80141008) func_802659E0_de(view);
    dl = D_80110634++;
    gDPPipeSync(dl);
}
