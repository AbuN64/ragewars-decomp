#include "COMMON/TEXTURE.H"
#include "COMMON/UNUSED.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "TYPES.H"
#include "MENU/GFX/80414430_21.H"
#include "COMMON/RECTANGLE_DRAW.H"
#include "include_asm.h"
#include "abi.h"

extern Gfx *g_displayListCursor;

extern void Gfx_SetRenderMode(s32 mode);

extern void Gfx_SetCombineMode(s32 mode);

extern void Gfx_SetPrimitiveVertexMode(s32 mode);

static inline void sync(void) {
    Gfx *cmd;

    if (D_800E32E4 == 0) {
        D_800E32E4 = 1;
        cmd = g_displayListCursor++;
        gDPPipeSync(cmd);
    }
}

static inline void emit(unsigned int w0, unsigned int w1) {
    Gfx *cmd;

    cmd = g_displayListCursor++;
    _GBI_CMD(cmd, w0, w1);
}

extern int D_800DF250, D_800DF270, D_800DF278, D_800E32CC;

extern int D_800DF284, D_800E32D8;

static inline void beginFrame(void) {
    Gfx *g;

    D_800E32E4 = 1;
    g = g_displayListCursor++;
    gDPPipeSync(g);
}

void Gfx_DrawRect(f32 x, f32 y, f32 unused, f32 width, f32 height, u32 color) {
    Gfx_DrawClippedImageRectangle(x, y, unused, width, height, 0.0f, 0.0f, D_800DD410_de, D_800DD410_de, color);
}

void Rect_DrawGradientRectangle(f32 x, f32 y, s32 unused, f32 z, f32 a4, s32 a5, s32 a6, s32 a7, s32 a8) {
    D_800DF290 = 0;
    D_800E32E4 = 0;
    Gfx_SetRenderMode(0xC);
    Gfx_SetCombineMode(5);
    if (D_800DF274 != 7) {
        D_800DF274 = 7;
        sync();
        emit(0xE3000C00, 0);
    }
    if (D_800DF280 != 0xE) {
        D_800DF280 = 0xE;
        sync();
        emit(0xD7000000, 0x80008000);
    }
    if (D_80153F60.x == 0) {
        Gfx_SetPrimitiveVertexMode(9);
        Gfx_DrawClippedGradientQuad(x, y, z, a4, a5, a6, a7, a8);
    }
}

void Rect_ResetRenderState(void) {
    if (D_800DF250 != 0) {
        D_800DF250 = 0;
        D_800DF270 = 0;
        D_800DF274 = 0;
        D_800DF278 = 0;
        D_800E32CC = 0;
        D_800DF280 = 0;
        D_800DF284 = 0;
        D_800E32D8 = 0;
        D_800DF28C = 0;
        D_800DF290 = 0;
    }
}

void Rect_SetTexturePerspectiveMode(s32 mode) {
    if (mode != D_800DF274) {
        D_800DF274 = mode;
        if (D_800E32E4 == 0) {
            beginFrame();
        }
        switch (mode) {
        case 6: {
            Gfx *g = g_displayListCursor++;
            gDPSetTexturePersp(g, G_TP_PERSP);
            break;
        }
        case 7: {
            Gfx *g = g_displayListCursor++;
            gDPSetTexturePersp(g, G_TP_NONE);
            break;
        }
        }
    }
}

/* Switches the texture mode (forced to 14 while D_80153F68 is clear), emitting a full-sync command the first time and a texture-enable command for modes 13 and 14. */

/* Sets the environment and primitive colours from a packed 0xAARRGGBB colour when it differs from
   the last one set, D_800DF28C: appends 0xFB (environment, alpha zero) and 0xFA (primitive, with
   alpha) commands to the display list D_80110634 points into. */

void Rect_SetTextureMode(s32 mode) {
    if (D_80153F60.z == 0) {
        mode = 14;
    }
    if (mode != D_800DF280) {
        D_800DF280 = mode;
        if (D_800E32E4 == 0) {
            beginFrame();
        }
        if (mode == 13) gSPTexture(g_displayListCursor++, 32768, 32768, 0, 0, G_ON) else if (mode == 14) gSPTexture(g_displayListCursor++, 32768, 32768, 0, 0, G_OFF);
    }
}

void Rect_SyncPipeline(void) {
    Gfx *gfx;

    if (D_800E32E4 == 0) {
        D_800E32E4 = 1;
        gDPPipeSync(g_displayListCursor++);
    }
}

void Rect_ResetPipelineSync(void) {
    D_800E32E4 = 0;
}

void Rect_SetPackedColor(u32 color) {
    Gfx *gfx;

    if (color == D_800DF28C) {
        return;
    }
    D_800DF28C = color;
    gfx = g_displayListCursor++;
    gDPSetEnvColor(gfx, color >> 16, (color & 0xFF00) >> 8, color, 0);
    gfx = g_displayListCursor++;
    
    gDPSetPrimColor(gfx, 0, 0, color >> 16, (color & 0xFF00) >> 8, color, color >> 24);
}

void Rect_EmitTextureRect(s32 left, s32 top, s32 right, s32 bottom, f32 u0, f32 v0, f32 u1, f32 v1) {
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
        Gfx *cmd = g_displayListCursor++;
        gDPTexRect(cmd, left * 4, top * 4, (right + 1) * 4, (bottom + 1) * 4, 0);
    }
    startS = u0 * scaleU;
    startT = v0 * scaleV;
    gDPHalf1(g_displayListCursor++, ((startS >> 5) << 16) | ((startT >> 5) & 0xFFFF));
    gDPHalf2(g_displayListCursor++, (dsdx << 16) | (dtdy & 0xFFFF));
}

#if defined(VERSION_US)
char rodata_unresolved_804194A8[8] =
    "_SLOW5_T";
#endif

/* ROM-grounded data: src/rw_pool_80418DA0_E2040_us_rev1.c */
const unsigned int D_blob_4dd9abd2df7b01df530e[1] = {
    0x3F800000,
};

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EDA94[3] = {
    0x0800FF88, 0x011A011F, 0x011B011C,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD414[3] = {
    0x3C23D70A, 0x3F99999A, 0x3D4CCCCD,
};
#endif
