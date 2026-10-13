#include "span_1000/code_80233920.h"
#include "gfx.h"
#include "shared/func_80425674_de_layout.h"
#include "shared/gameplay_camera.h"
#include "gbi.h"

extern char D_800CBCC0, D_800CBCF0_de;
extern s32 D_800D297C, D_800E28D0, D_800E28D4;
extern Gfx *D_80110634;
extern Frame *D_8011BDC0;
extern Shared_func_80234FDC_S4 D_80140FF8;

extern u8 D_8011FAC0[];
extern void func_8026E330_de(s32);
extern void func_80296004_de(s32);
extern void func_8026D88C_de(void);
extern void func_80295FF4_de(void);
extern s32 func_802A23B4_de(void), func_80299958_de(void);
extern void func_8026925C_de(s32);
extern void func_80291BE8_de(void *, s32, s32, s32, s32, s32);
extern s32 func_80245798_de(void);
extern u32 func_80245AF8_de(void);
extern void func_8026D914_de(s32);
extern void func_802659E0_de(void *);
static inline void initScale35AE0(Racer *v) { v->screenScaleX=1.0f; v->screenScaleY=1.0f; }
/* Set projection, viewport and lighting, then draw the view's clear rectangle and fog. */
void func_80235AE0_de(Racer *view) {
    struct { u8 red, green, blue; } rgb;
    s16 ulx, uly, lrx, lry;
    s32 flag, near, far, denom;
    u32 color;
    s16 vx, vy;
    s32 maxx, maxy;
    f32 sx, sy, width, height, x, y;
    Gfx *cmd;
    Gfx **dl = &D_80110634;
    Frame *buffer;
    s32 frame;
    UnitVp *viewport;
    u32 *lights;
    { Gfx **setup = &D_80110634;
    gDPPipeSync((*setup)++);
    gSPDisplayList((*setup)++, &D_800CBCC0);
    gSPDisplayList((*setup)++, &D_800CBCF0_de);
    sx=view->viewportScaleX;
    width=view->viewportWidth;
    vx=(s16)(s32)((width+width)*sx);
    y=view->viewportY;
    uly=(s32)y;
    height=view->viewportHeight;
    x=view->viewportX;
    lrx=(s32)(x+width);
    maxx=(u16)D_800E28D0-1;
    sy=view->viewportScaleY;
    vy=(s16)(s32)((height+height)*sy);
    lry=(s32)(y+height);
    initScale35AE0(view);
    maxy=(u16)D_800E28D4-1;
    ulx=(s32)x;
    view->screenScaleX=sx;
    view->screenScaleY=sy;
    if (D_800E28D0-1 < (s16)lrx) lrx=maxx;
    if ((s16)ulx<0) ulx=0;
    if ((s16)uly<0) uly=0;
    if ((s16)lry > D_800E28D4-1) lry=maxy;
    buffer=D_8011BDC0; frame=D_800D297C;
    gSPMatrix((*setup)++, view->projectionMatrices[frame], G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMoveWord((*setup)++, G_MW_PERSPNORM, 0, view->perspectiveNorm);
    viewport=&view->viewports[frame];
    lights=&view->lights[frame][0];
    viewport->vscale[0]=vx; viewport->vscale[1]=vy;
    viewport->vtrans[0]=(s16)(s32)((vx*0.25f+view->viewportX)*4.0f);
    viewport->vtrans[1]=(s16)(s32)((vy*0.25f+view->viewportY)*4.0f);
    gSPMoveMem((*setup)++, G_MV_VIEWPORT, 0, 16, viewport);
    gDPSetScissorFrac((*setup)++, G_SC_NON_INTERLACE, (s32)((s16)ulx*4.0f), (s32)((s16)uly*4.0f), (s32)((s16)lrx*4.0f), (s32)((s16)lry*4.0f));
    gSPMoveMem((*setup)++, G_MV_LIGHT, 0, 16, lights);
    gSPMoveMem((*setup)++, G_MV_LIGHT, 24, 16, lights+4);
    func_8026E330_de(view->effect);
    if (view!=&D_80140FF8.view) func_80296004_de(view->effect);
    }
    flag=0; func_8026D88C_de(); func_80295FF4_de();
    gDPSetTextureFilter((*dl)++, G_TF_BILERP);
    if(func_802A23B4_de()!=0) flag=func_80299958_de()!=2;
    if(view!=&D_80140FF8.view || D_80140FF8.unk0==0 || flag!=0) {
        Gfx **clearDl = &D_80110634;
        func_8026925C_de(0x14);
        gDPPipeSync((*clearDl)++);
        func_80291BE8_de(D_8011FAC0,(s16)ulx,(s16)lrx,(s16)uly,(s16)lry,view->effect);
        cmd=*clearDl; gDPSetCycleType(cmd++, G_CYC_FILL); *clearDl=cmd;
        if(D_801462C8.flags&0x4000) {rgb.red=0;rgb.green=0;rgb.blue=0;} else {rgb.red=view->hit&0xF8;rgb.green=view->boost&0xF8;rgb.blue=view->spin&0xF8;}
        if(func_80245798_de()!=0) { color=func_80245AF8_de(); if(color!=0xFF00) {rgb.blue=color>>16;rgb.green=color>>8;rgb.red=color;} }
        gSPGeometryMode(D_80110634++, 0, G_FOG);
        if(view->effect!=0) {
            gDPSetFogColor(D_80110634++, 0, 0, 0, 255);
            gSPMoveWord(D_80110634++, G_MW_FOG, 0, 0x64009D00);
        } else {
            gDPSetFogColor(D_80110634++, rgb.red, rgb.green, rgb.blue, 255);
            far=view->fogNear;denom=1000-far;near=(500-far)<<8;
            gSPMoveWord(D_80110634++, G_MW_FOG, 0, ((0x1F400/denom)<<16)|((near/denom)&0xFFFF));
        }
        gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, buffer->colorImage);
        if(view->effect!=0) {gDPSetFillColor(D_80110634++, 0x10001);}
        else {
            gDPSetFillColor(D_80110634++, (color=(((rgb.red<<8)&0xF800)|((rgb.green<<3)&0x7C0)|((rgb.blue>>2)&0x3E)), ((color|1)<<16)|1|(u16)color));
        }
        if(view!=&D_80140FF8.view || D_80140FF8.state.unk0==3) {
            gDPFillRectangle(D_80110634++, ulx, uly, lrx, lry);
        }
    }
    gDPPipeSync(D_80110634++);
    func_8026D914_de(0);
    gDPSetAlphaDither(D_80110634++, G_AD_NOTPATTERN);
    gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
    if(view!=&D_80140FF8.view)func_802659E0_de(view);
    gDPPipeSync(D_80110634++);
}
