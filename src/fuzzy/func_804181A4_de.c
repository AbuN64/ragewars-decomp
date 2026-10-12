#include "gfx.h"
#include "span_16E000/code_804143D8.h"
#include "abi.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"

/* Draws the current texture D_800DF254 over the screen rectangle (x0, y0)-(x1, y1) mapping the
   normalised window (u0, v0)-(u1, v1): splits the texture into horizontal strips that fit texture
   memory for the pixel size in D_800DF268_de (4, 8, 16 or 24 bits), loads each visible strip with a
   load block and tile setup (D_800DF260_de reuses the tile setup after the first strip for 8 bits)
   and emits a texture rectangle for it. */
extern Gfx *D_80110634;
extern Texture *D_800DF254;
extern s32 D_800DF268_de;
extern float D_800DD404;
extern float D_800DD408_de;


void func_804181A4_de(s32 x0, s32 y0, s32 x1, s32 y1, f32 u0, f32 v0, f32 u1, f32 v1) {
    s32 bpp;
    s32 w;
    s32 lrs;
    s32 st4;
    s32 h;
    s32 stride;
    s32 dsdx;
    s32 dtdy;
    s32 rows;
    s32 dx;
    s32 dy;
    s32 vOff;
    s32 rowBytes;
    s32 chunk;
    s32 y;
    s32 yNext;
    s32 started;
    s32 scale;
    s32 yTop;
    s32 yBot;
    s32 tOff;
    u32 data;
    f32 fh;
    s32 sStart;

    started = 0;
    w = D_800DF254->width;
    if (w == 0) {
        return;
    }
    h = D_800DF254->height;
    if (h == 0) {
        return;
    }
    if (x0 == x1) {
        return;
    }
    if (y0 == y1) {
        return;
    }
    dx = x1 - x0 + 1;
    dsdx = (s32)((u1 - u0) * (f32)w * D_800DD404) / dx;
    fh = (v1 - v0) * (f32)h;
    dy = y1 - y0 + 1;
    dtdy = (s32)(fh * D_800DD404) / dy;
    stride = D_800DF254->stride;
    D_800DF264_de = 0;
    if ((s32)fh == 0) {
        scale = 1000;
    } else {
        scale = (s32)((f32)dy * D_800DD404 / fh);
    }
    x0 = x0 << 10;
    y0 = y0 << 10;
    vOff = (s32)(v0 * (f32)h * D_800DD408_de);
    x1 = x1 << 10;
    y1 = y1 << 10;
    bpp = D_800DF268_de;
    switch (bpp) {
    case 8:
        rowBytes = D_800DF254->stride;
        chunk = 0x800 / rowBytes;
        chunk &= ~1;
        break;
    case 4:
        st4 = (s16)(u16)D_800DF254->stride;
        chunk = 0x1000 / st4;
        rowBytes = st4 / 2;
        chunk &= ~1;
        break;
    case 16:
        rowBytes = D_800DF254->stride * 2;
        chunk = 0x800 / D_800DF254->stride;
        chunk &= ~1;
        break;
    case 24:
        rowBytes = D_800DF254->stride * 4;
        chunk = 0x400 / D_800DF254->stride;
        chunk &= ~1;
        break;
    default:
        rowBytes = 0;
        chunk = 0;
        break;
    }
    rows = D_800DF254->height;
    if (rows < chunk) {
        chunk = rows;
    }
    sStart = (s32)(u0 * (f32)w * (&D_800DD408_de)[1]);
    y = 0;
    if (rows >= 0) {
        do {
            yNext = y + chunk;
            yTop = y0 + (scale * (y * 0x400 - vOff) >> 10);
            yBot = y0 + (scale * (yNext * 0x400 - vOff) >> 10) - 0x400;
            data = D_800DF254->data + y * rowBytes;
            tOff = 0;
            if (yBot < yTop) {
                s32 t;
                tOff = (chunk - 1) * 0x400;
                t = yBot;
                yBot = yTop;
                yTop = t;
            }
            if (yTop <= y1 && y0 <= yBot) {
                if (yTop < y0) {
                    tOff = tOff + ((s32)((y0 - yTop) * dtdy) >> 10);
                    yTop = y0;
                }
                if (y1 < yBot) {
                    yBot = y1;
                }
                if (D_800DF260_de == 0) {
                    switch (bpp) {
                    case 8:
                        gDPSetTextureImage(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, data);
                        gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPLoadSync(D_80110634++);
                        lrs = ((stride * chunk + 1) >> 1) - 1;
                        if (lrs > 2047) {
                            lrs = 2047;
                        }
                        gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, lrs, ((1 << 11) + (1 > stride / 8 ? 1 : stride / 8) - 1) / (1 > stride / 8 ? 1 : stride / 8));
                        gDPPipeSync(D_80110634++);
                        gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_8b, (stride + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (stride - 1) * 4, (chunk - 1) * 4);
                        break;
                    case 4:
                        gDPSetTextureImage(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, data);
                        gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPLoadSync(D_80110634++);
                        lrs = ((stride * chunk + 3) >> 2) - 1;
                        if (lrs > 2047) {
                            lrs = 2047;
                        }
                        gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, lrs, ((1 << 11) + (1 > stride / 16 ? 1 : stride / 16) - 1) / (1 > stride / 16 ? 1 : stride / 16));
                        gDPPipeSync(D_80110634++);
                        gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_4b, ((stride >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (stride - 1) * 4, (chunk - 1) * 4);
                        break;
                    case 16:
                        gDPSetTextureImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, data);
                        gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPLoadSync(D_80110634++);
                        lrs = stride * chunk - 1;
                        if (lrs > 2047) {
                            lrs = 2047;
                        }
                        gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, lrs, ((1 << 11) + (1 > stride / 4 ? 1 : stride / 4) - 1) / (1 > stride / 4 ? 1 : stride / 4));
                        gDPPipeSync(D_80110634++);
                        gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (stride * 2 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (stride - 1) * 4, (chunk - 1) * 4);
                        break;
                    }
                } else {
                    switch (bpp) {
                    case 8:
                        if (!started) {
                            started = 1;
                            gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                            gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_8b, (stride + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                            gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (stride - 1) * 4, (chunk - 1) * 4);
                            gDPPipeSync(D_80110634++);
                        }
                        gDPLoadSync(D_80110634++);
                        gDPSetTextureImage(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, data);
                        lrs = ((stride * chunk + 1) >> 1) - 1;
                        if (lrs > 2047) {
                            lrs = 2047;
                        }
                        gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, lrs, 0);
                        break;
                    case 4:
                        gDPSetTextureImage(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, data);
                        gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPLoadSync(D_80110634++);
                        lrs = ((stride * chunk + 3) >> 2) - 1;
                        if (lrs > 2047) {
                            lrs = 2047;
                        }
                        gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, lrs, 0);
                        gDPPipeSync(D_80110634++);
                        gDPSetTile(D_80110634++, G_IM_FMT_CI, G_IM_SIZ_4b, ((stride >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (stride - 1) * 4, (chunk - 1) * 4);
                        break;
                    case 16:
                        gDPSetTextureImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, data);
                        gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPLoadSync(D_80110634++);
                        lrs = stride * chunk - 1;
                        if (lrs > 2047) {
                            lrs = 2047;
                        }
                        gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, lrs, 0);
                        gDPPipeSync(D_80110634++);
                        gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (stride * 2 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (stride - 1) * 4, (chunk - 1) * 4);
                        break;
                    }
                }
                gSPTextureRectangle(D_80110634++, x0 >> 8, yTop >> 8, (x1 >> 8) + 4, (yBot >> 8) + 4, 0, sStart >> 5, tOff >> 5, dsdx, dtdy);
            }
            y = yNext;
        } while (yNext <= rows);
    }
}
