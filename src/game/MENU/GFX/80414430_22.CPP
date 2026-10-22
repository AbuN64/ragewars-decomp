#include "include_asm.h"
#include "COMMON/TEXTURE.H"
#include "abi.h"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "TYPES.H"
#include "MENU/GFX/80414430_22.H"

/* Switches the texture mode (forced to 14 while D_80153F68 is clear), emitting a full-sync command the first time and a texture-enable command for modes 13 and 14. */



extern s32 D_800DF280;

extern s32 D_800E32E4;

extern Gfx *D_80110634;

static inline void beginFrame(void) {
    Gfx *g;

    D_800E32E4 = 1;
    g = D_80110634++;
    gDPPipeSync(g);
}

/* Sets the environment and primitive colours from a packed 0xAARRGGBB colour when it differs from
   the last one set, D_800DF28C: appends 0xFB (environment, alpha zero) and 0xFA (primitive, with
   alpha) commands to the display list D_80110634 points into. */

extern u32 D_800DF28C;

extern Texture *D_800DF254;

void func_804190C4_de(s32 mode) {
    if (D_80153F68 == 0) {
        mode = 14;
    }
    if (mode != D_800DF280) {
        D_800DF280 = mode;
        if (D_800E32E4 == 0) {
            beginFrame();
        }
        if (mode == 13) gSPTexture(D_80110634++, 32768, 32768, 0, 0, G_ON) else if (mode == 14) gSPTexture(D_80110634++, 32768, 32768, 0, 0, G_OFF);
    }
}

void func_804191A4_de(void) {
    Gfx *gfx;

    if (D_800E32E4 == 0) {
        D_800E32E4 = 1;
        gDPPipeSync(D_80110634++);
    }
}

void func_804191E8_de(void) {
    D_800E32E4 = 0;
}

void func_804191F8_de(u32 color) {
    Gfx *gfx;

    if (color == D_800DF28C) {
        return;
    }
    D_800DF28C = color;
    gfx = D_80110634++;
    gDPSetEnvColor(gfx, color >> 16, (color & 0xFF00) >> 8, color, 0);
    gfx = D_80110634++;
    
    gDPSetPrimColor(gfx, 0, 0, color >> 16, (color & 0xFF00) >> 8, color, color >> 24);
}

void func_80419278_de(s32 left, s32 top, s32 right, s32 bottom, f32 u0, f32 v0, f32 u1, f32 v1) {
    f32 scaleU;
    f32 scaleV;
    s32 dsdx;
    s32 dtdy;
    s32 startS;
    s32 startT;

    if (D_800DF254->width == 0 || D_800DF254->height == 0 || left == right || top == bottom) {
        return;
    }
    scaleU = D_800DF254->width << 10;
    dsdx = (s32)((u1 - u0) * scaleU) / (right - left + 1);
    scaleV = D_800DF254->height << 10;
    dtdy = (s32)((v1 - v0) * scaleV) / (bottom - top + 1);
    {
        Gfx *cmd = D_80110634++;
        gDPTexRect(cmd, left * 4, top * 4, (right + 1) * 4, (bottom + 1) * 4, 0);
    }
    startS = u0 * scaleU;
    startT = v0 * scaleV;
    gDPHalf1(D_80110634++, ((startS >> 5) << 16) | ((startT >> 5) & 0xFFFF));
    gDPHalf2(D_80110634++, (dsdx << 16) | (dtdy & 0xFFFF));
}

#if defined(VERSION_US)
INCLUDE_DATA("ovl_80400000", rodata_unresolved_804194A8);
#endif
