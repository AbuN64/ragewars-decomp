#include "COMMON/TEXTURE.H"
#include "abi.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/RECTANGLE_DRAW.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "MENU/GFX/GFX_DRAWTEXTURERECTANGLECHUNKS.H"
#include "MENU/GFX/RECT.H"
#include "MENU/GFX/GFX_DRAWCLIPPEDGRADIENTQUAD.H"

/* Makes palette the current texture lookup table for a texture of the given bit depth: returns 1
   when it already is (g_combineLoadedPalette); otherwise records it, emits one pipeline sync if none is pending
   and, for 4-bit and 8-bit textures, enables the RGBA16 lookup table and loads the 16 or 256
   palette entries (texture image, tile sync, tile, load sync, load TLUT, pipeline sync), or for
   16-bit textures turns the lookup table off; returns 0. */



extern void *g_combineLoadedPalette;


static inline void sync(void) {
    Gfx *cmd;

    if (g_combinePipelineSyncPending == 0) {
        g_combinePipelineSyncPending = 1;
        cmd = g_displayListCursor++;
        gDPPipeSync(cmd);
    }
}

extern s32 Frontend_GetImagePixelType(u8 *);

static inline u32 blockWord16(void) {
   s32 num; s32 count;
   num=(g_combineBoundImage->stride/16>0 ? g_combineBoundImage->stride/16+2047:2048);
   count=((g_combineBoundImage->stride*g_combineBoundImage->rows+3)>>2)-1;
   if(count>=2048) count=2047;
 return _SHIFTL(G_TX_LOADTILE,24,3) | _SHIFTL(count,12,12) | _SHIFTL(g_combineBoundImage->stride/16>0 ? num/(g_combineBoundImage->stride/16):num,0,12);
}

static inline u32 blockWord8(void) {
   s32 num; s32 count;
   num=(g_combineBoundImage->stride/8>0 ? g_combineBoundImage->stride/8+2047:2048);
   count=((g_combineBoundImage->stride*g_combineBoundImage->rows+1)>>1)-1;
   if(count>=2048) count=2047;
 return _SHIFTL(G_TX_LOADTILE,24,3) | _SHIFTL(count,12,12) | _SHIFTL(g_combineBoundImage->stride/8>0 ? num/(g_combineBoundImage->stride/8):num,0,12);
}

static inline u32 blockWord4(void) {
   s32 num; s32 count;
   num=(g_combineBoundImage->stride/4>0 ? g_combineBoundImage->stride/4+2047:2048);
   count=g_combineBoundImage->stride*g_combineBoundImage->rows-1;
   if(count>=2048) count=2047;
 return _SHIFTL(G_TX_LOADTILE,24,3) | _SHIFTL(count,12,12) | _SHIFTL(g_combineBoundImage->stride/4>0 ? num/(g_combineBoundImage->stride/4):num,0,12);
}

static __inline__ void rectangleEmit(u32 w0, u32 w1) { Gfx *cmd = g_displayListCursor++; cmd->words.w0 = w0; cmd->words.w1 = w1; }

static __inline__ void rectangleSync(void) {
 Gfx *cmd;
 if (g_combinePipelineSyncPending == 0) { g_combinePipelineSyncPending = 1; cmd = g_displayListCursor++; gDPPipeSync(cmd); }
}

static inline f32 scaleClip(f32 delta, f32 ratio) { return ratio * delta; }

s32 Combine_LoadPalette(s32 bits, void *palette) {
    s32 result;

    result = 1;
    if (g_combineLoadedPalette != palette) {
        g_combineLoadedPalette = palette;
        sync();
        if (bits == 4) {
            gDPSetTextureLUT(g_displayListCursor++, G_TT_RGBA16);
            gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (unsigned int)palette);
            gDPTileSync(g_displayListCursor++);
            gDPSetTile(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0);
            gDPLoadSync(g_displayListCursor++);
            gDPLoadTLUTCmd(g_displayListCursor++, G_TX_LOADTILE, 15);
            gDPPipeSync(g_displayListCursor++);
        } else if (bits == 8) {
            gDPSetTextureLUT(g_displayListCursor++, G_TT_RGBA16);
            gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (unsigned int)palette);
            gDPTileSync(g_displayListCursor++);
            gDPSetTile(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0);
            gDPLoadSync(g_displayListCursor++);
            gDPLoadTLUTCmd(g_displayListCursor++, G_TX_LOADTILE, 255);
            gDPPipeSync(g_displayListCursor++);
        } else if (bits == 16) gDPSetTextureLUT(g_displayListCursor++, G_TT_NONE);
        result = 0;
    }
    return result;
}

void Combine_BindImageTexture(Texture *image) {
 s32 paletteSame,flags,size;
 Texture *tex=image;
 if (image == 0) {
 g_combineBoundImageWidth=0; g_combineBoundImageHeight=0; g_combineBoundImage=0;
 g_combineImageRequiresChunks=0; g_combineImageChunkState=0; g_combineBoundImageMaskComponent=0;
 } else {
 g_combineBoundImage=tex; g_combineImageChunkState=0;
 g_combineBoundImageWidth=tex->width; g_combineBoundImageHeight=tex->height;
 g_combineBoundImagePixelType=Frontend_GetImagePixelType(&tex->format);
 g_combineBoundImageMaskComponent=Frontend_HasImageFormatMaskComponent(&g_combineBoundImage->format);
 flags=tex->flags;size=tex->size;
 g_combineImageRequiresChunks=0;
 if(flags>0 && size>2048) g_combineImageRequiresChunks=1;
 if(flags==0 && size>4096) g_combineImageRequiresChunks=1;
 paletteSame=Combine_LoadPalette(g_combineBoundImagePixelType,g_combineBoundImage->palette);
 if(g_combineImageRequiresChunks==0) {
  if(g_combineBoundImagePixelType==4) {
   gDPSetTextureImage(g_displayListCursor++,G_IM_FMT_CI,G_IM_SIZ_16b,1,g_combineBoundImage->data);
   gDPSetTile(g_displayListCursor++,G_IM_FMT_CI,G_IM_SIZ_16b,0,0,7,0,2,0,0,2,0,0);
   gDPLoadSync(g_displayListCursor++);
   _GBI_CMD(g_displayListCursor++, _SHIFTL(G_LOADBLOCK,24,8), blockWord16());
   gDPPipeSync(g_displayListCursor++);
   gDPSetTile(g_displayListCursor++,G_IM_FMT_CI,G_IM_SIZ_4b,(((s16)(u16)g_combineBoundImage->stride >> 1)+7)>>3,0,0,0,2,0,0,2,0,0);
   gDPSetTileSize(g_displayListCursor++,0,0,0,(g_combineBoundImage->stride-1)*4,(g_combineBoundImage->rows-1)*4);
  }
  else if(g_combineBoundImagePixelType==8) {
   if(paletteSame==0) {
    gDPSetTile(g_displayListCursor++,G_IM_FMT_CI,G_IM_SIZ_16b,0,0,7,0,2,0,0,2,0,0);
    gDPPipeSync(g_displayListCursor++);
   }
   gDPLoadSync(g_displayListCursor++);
   gDPSetTile(g_displayListCursor++,G_IM_FMT_CI,G_IM_SIZ_8b,(g_combineBoundImage->stride+7)>>3,0,0,0,2,0,0,2,0,0);
   gDPSetTileSize(g_displayListCursor++,0,0,0,(g_combineBoundImage->stride-1)*4,(g_combineBoundImage->rows-1)*4);
   gDPSetTextureImage(g_displayListCursor++,G_IM_FMT_CI,G_IM_SIZ_16b,1,g_combineBoundImage->data);
   _GBI_CMD(g_displayListCursor++, _SHIFTL(G_LOADBLOCK,24,8), blockWord8());
  }
  else if(g_combineBoundImagePixelType==16) {
   gDPSetTextureImage(g_displayListCursor++,G_IM_FMT_RGBA,G_IM_SIZ_16b,1,g_combineBoundImage->data);
   gDPSetTile(g_displayListCursor++,G_IM_FMT_RGBA,G_IM_SIZ_16b,0,0,7,0,2,0,0,2,0,0);
   gDPLoadSync(g_displayListCursor++);
   _GBI_CMD(g_displayListCursor++, _SHIFTL(G_LOADBLOCK,24,8), blockWord4());
   gDPPipeSync(g_displayListCursor++);
   gDPSetTile(g_displayListCursor++,G_IM_FMT_RGBA,G_IM_SIZ_16b,(g_combineBoundImage->stride*2+7)>>3,0,0,0,2,0,0,2,0,0);
   gDPSetTileSize(g_displayListCursor++,0,0,0,(g_combineBoundImage->stride-1)*4,(g_combineBoundImage->rows-1)*4);
  }
 }
 }
}

void Combine_DrawClippedImageRectangle(f32 x, f32 y, f32 unusedDepth, f32 width, f32 height, f32 startU, f32 startV, f32 endU, f32 endV, u32 color) {
    s32 clipLeft;
    s32 clipTop;
    s32 clipRight;
    s32 clipBottom;
    Gfx *unusedDisplayListCursor1;
    Gfx *unusedDisplayListCursor2;
    Gfx *unusedDisplayListCursor3;
    Gfx *unusedDisplayListCursor4;
    Gfx *unusedDisplayListCursor5;
    Gfx *unusedDisplayListCursor6;
    Gfx *unusedDisplayListCursor7;
    Gfx *unusedDisplayListCursor8;
    Gfx *unusedDisplayListCursor9;
    Gfx *unusedDisplayListCursor10;
    f32 rectangleX;
    f32 rectangleY;
    f32 savedLeft;
    f32 savedTop;
    f32 delta;
    f32 horizontalClipDelta;
    f32 rightU;
    f32 bottomV;
    f32 rectangleHeight;
    f32 savedStartU;
    f32 savedStartV;
    s32 defaultMode;
    s32 textureRenderMode;
    s32 mode;
    f32 leftU;
    f32 topV;
    f32 rectangleWidth;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    u32 packedRgbColor;

    rectangleWidth = width;
    rectangleHeight = height;
    leftU = startU;
    topV = startV;
    rightU = endU;
    rectangleX = x;
    bottomV = endV;
    rectangleY = y;
    if ((g_combineRenderSwitches.z == 0) || (g_combineRenderSwitches.y == 0)) {
        g_combineTexturedRectangleState = 0;
        g_combinePipelineSyncPending = 0;
        Combine_SetRenderMode(0xC);
        Combine_SetCombineMode(5);
        if (g_combineTextureTileMode != 7) {
            g_combineTextureTileMode = 7;
            rectangleSync();
            rectangleEmit(0xE3000C00, 0);

        }
        if (g_combineTextureRenderMode != 0xE) {
            g_combineTextureRenderMode = 0xE;
            rectangleSync();
            rectangleEmit(0xD7000000, 0x80008000);

        }
        if (g_combineRenderSwitches.x == 0) {
            Combine_SetPrimitiveVertexMode(9);
            Combine_DrawClippedGradientQuad(rectangleX, rectangleY, rectangleWidth, rectangleHeight, (u32) color, (u32) color, (u32) color, (u32) color);
        }
    } else if (g_combineRenderSwitches.x == 0) {
        g_combinePipelineSyncPending = 0;
        Combine_SetRenderMode(0xC);
        defaultMode = 0xD;
        textureRenderMode = defaultMode;
        if (g_combineTexturingEnabled == 0) {
            textureRenderMode = 0xE;
        }
        if (textureRenderMode != g_combineTextureRenderMode) {
            g_combineTextureRenderMode = textureRenderMode;
            rectangleSync();
            if (textureRenderMode == defaultMode) rectangleEmit(0xD7000002, 0x80008000);
            else if (textureRenderMode == 0xE) rectangleEmit(0xD7000000, 0x80008000);
        }
        if (color != g_combineRectangleColor) {
            g_combineRectangleColor = color;
            packedRgbColor = (((u32) color >> 0x10) << 0x18) | ((color & 0xFF00) << 8) | ((color & 0xFF) << 8);
            rectangleEmit(0xFB000000, packedRgbColor);
            rectangleEmit(0xFA000000, packedRgbColor | ((u32)color >> 0x18));
        }
        if (g_combineTextureTileMode != 7) {
            g_combineTextureTileMode = 7;
            rectangleSync();
            rectangleEmit(0xE3000C00, 0);

        }
        mode = 2;
        if (g_combineBoundImageMaskComponent != 0) {
            mode = 1;
        }
        Combine_SetCombineMode(mode);
        left = (s32) rectangleX;
        top = (s32) rectangleY;
        g_combineTexturedRectangleState = 0x13;
        right = (s32) ((rectangleX + rectangleWidth) - g_textureRectangleInclusivePixelOffset);
        bottom = (s32) ((rectangleY + rectangleHeight) - g_textureRectangleInclusivePixelOffset);
        if (right < left) {
            savedLeft = (f32) left;
            left = right;
            right = (s32) savedLeft;
            savedStartU = leftU;
            leftU = rightU;
            rightU = savedStartU;
            rectangleWidth = -rectangleWidth;
        }
        if (bottom < top) {
            savedTop = (f32) top;
            top = bottom;
            bottom = (s32) savedTop;
            savedStartV = topV;
            topV = bottomV;
            bottomV = savedStartV;
            rectangleHeight = -rectangleHeight;
        }
        N64Eng_GetClipBounds(&clipLeft, &clipTop, &clipRight, &clipBottom);
        if ((clipRight < right) || (left < clipLeft) || (clipBottom < bottom) || (top < clipTop)) {
            if ((clipRight >= left) && (clipBottom >= top) && (right >= clipLeft) && (bottom >= clipTop)) {
                if (top < clipTop) {
                    delta = bottomV - topV;
                    delta=scaleClip(delta, ((f32) (clipTop - top) / rectangleHeight));
                    top = clipTop;
                    rectangleHeight = (f32) ((bottom - top) + 1);
                    topV = (topV + delta);
                }
                if (clipBottom < bottom) {
                    delta = ((f32) (clipBottom - top) / rectangleHeight) * (bottomV - topV);
                    bottom = clipBottom;
                    bottomV = topV + delta;
                }
                if (left < clipLeft) {
                    horizontalClipDelta = rightU - leftU;
                    horizontalClipDelta=scaleClip(horizontalClipDelta, ((f32) (clipLeft - left) / rectangleWidth));
                    left = clipLeft;
                    rectangleWidth = (f32) ((right - left) + 1);
                    leftU = (leftU + horizontalClipDelta);
                }
                if (clipRight < right) {
                    horizontalClipDelta = ((f32) (clipRight - left) / rectangleWidth) * (rightU - leftU);
                    right = clipRight;
                    rightU = leftU + horizontalClipDelta;
                }
                goto block_51;
            }
        } else {
block_51:
            if ((rightU < leftU) || (bottomV < topV) || (g_combineImageRequiresChunks != 0)) {
                Combine_DrawTextureRectangleChunks(left, top, right, bottom, leftU, topV, rightU, bottomV);
            } else {
                Rect_EmitTextureRect(left, top, right, bottom, leftU, topV, rightU, bottomV);
            }
        }
    }
}

void Combine_DrawTextureRectangleChunks(s32 x0, s32 y0, s32 x1, s32 y1, f32 u0, f32 v0, f32 u1, f32 v1) {
    s32 scale;
    s32 dsdx;
    s32 dtdy;
    s32 rowBytes;
    s32 rows;
    s32 sStart;
    s32 vOff;
    s32 started;
    s32 bpp;
    s32 w;
    s32 st4;
    s32 h;
    s32 stride;
    s32 dx;
    s32 dy;
    s32 chunk;
    s32 y;
    s32 yNext;
    s32 yTop;
    s32 yBot;
    s32 tOff;
    u32 data;
    f32 fh;
    s32 intH;

    started = 0;
    if (g_combineBoundImage->width == 0) {
        return;
    }
    if (g_combineBoundImage->height == 0) {
        return;
    }
    if (x0 == x1) {
        return;
    }
    if (y0 == y1) {
        return;
    }
    w = g_combineBoundImage->width;
    dx = x1 - x0 + 1;
    dsdx = (s32)((u1 - u0) * (f32)w * g_textureRectangleDerivativeScale) / dx;
    h = g_combineBoundImage->height;
    fh = (v1 - v0) * (f32)h;
    dy = y1 - y0 + 1;
    intH = (s32)fh;
    dtdy = (s32)(fh * g_textureRectangleDerivativeScale) / dy;
    stride = g_combineBoundImage->stride;
    bpp = g_combineBoundImagePixelType;
    g_combineImageChunkState = 0;
    if (intH == 0) {
        scale = 1000;
    } else {
        scale = (s32)((f32)dy * g_textureRectangleDerivativeScale / fh);
    }
    x0 = x0 << 10;
    y0 = y0 << 10;
    y1 = y1 << 10;
    x1 = x1 << 10;
    vOff = (s32)(v0 * (f32)h * g_textureRectangleCoordinateScales[0]);
    switch (bpp) {
    case 4:
        st4 = (s16)(u16)g_combineBoundImage->stride;
        chunk = (0x1000 / st4) & ~1;
        rowBytes = st4 / 2;
        break;
    case 8:
        chunk = (0x800 / g_combineBoundImage->stride) & ~1;
        rowBytes = g_combineBoundImage->stride;
        break;
    case 16:
        rowBytes = g_combineBoundImage->stride * 2;
        chunk = (0x800 / g_combineBoundImage->stride) & ~1;
        break;
    case 24:
        rowBytes = g_combineBoundImage->stride * 4;
        chunk = (0x400 / g_combineBoundImage->stride) & ~1;
        break;
    default:
        rowBytes = 0;
        chunk = 0;
        break;
    }
    if (g_combineBoundImage->height < chunk) {
        chunk = g_combineBoundImage->height;
    }
    rows = g_combineBoundImage->height;
    sStart = (s32)(u0 * (f32)w * g_textureRectangleCoordinateScales[1]);
    y = 0;
    if (rows >= 0) {
        do {
            yNext = y + chunk;
            yTop = y0 + (scale * (y * 0x400 - vOff) >> 10);
            yBot = y0 + (scale * (yNext * 0x400 - vOff) >> 10) - 0x400;
            data = g_combineBoundImage->data + y * rowBytes;
            y = yNext;
            tOff = 0;
            if (yBot < yTop) {
                tOff = yTop;
                yTop = yBot;
                yBot = tOff;
                tOff = (chunk - 1) * 0x400;
            }
            if (yTop <= y1 && y0 <= yBot) {
                if (yTop < y0) {
                    tOff = tOff + ((s32)((y0 - yTop) * dtdy) >> 10);
                    yTop = y0;
                }
                if (y1 < yBot) {
                    yBot = y1;
                }
                if (g_combineImageRequiresChunks == 0) {
                    switch (bpp) {
                    case 4:
                        gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, data);
                        gDPSetTile(g_displayListCursor++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPLoadSync(g_displayListCursor++);
                        gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, ((((stride * chunk + 3) >> 2) - 1) < 2047 ? (((stride * chunk + 3) >> 2) - 1) : 2047), ((1 << 11) + (1 > stride / 16 ? 1 : stride / 16) - 1) / (1 > stride / 16 ? 1 : stride / 16));
                        gDPPipeSync(g_displayListCursor++);
                        gDPSetTile(g_displayListCursor++, G_IM_FMT_CI, G_IM_SIZ_4b, ((stride >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, (stride - 1) * 4, (chunk - 1) * 4);
                        break;
                    case 8:
                        gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, data);
                        gDPSetTile(g_displayListCursor++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPLoadSync(g_displayListCursor++);
                        gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, ((((stride * chunk + 1) >> 1) - 1) < 2047 ? (((stride * chunk + 1) >> 1) - 1) : 2047), ((1 << 11) + (1 > stride / 8 ? 1 : stride / 8) - 1) / (1 > stride / 8 ? 1 : stride / 8));
                        gDPPipeSync(g_displayListCursor++);
                        gDPSetTile(g_displayListCursor++, G_IM_FMT_CI, G_IM_SIZ_8b, (stride + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, (stride - 1) * 4, (chunk - 1) * 4);
                        break;
                    case 16:
                        gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, data);
                        gDPSetTile(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPLoadSync(g_displayListCursor++);
                        gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, ((stride * chunk - 1) < 2047 ? (stride * chunk - 1) : 2047), ((1 << 11) + (1 > stride / 4 ? 1 : stride / 4) - 1) / (1 > stride / 4 ? 1 : stride / 4));
                        gDPPipeSync(g_displayListCursor++);
                        gDPSetTile(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (stride * 2 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, (stride - 1) * 4, (chunk - 1) * 4);
                        break;
                    }
                } else {
                    switch (bpp) {
                    case 4:
                        gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, data);
                        gDPSetTile(g_displayListCursor++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPLoadSync(g_displayListCursor++);
                        gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, ((((stride * chunk + 3) >> 2) - 1) < 2047 ? (((stride * chunk + 3) >> 2) - 1) : 2047), 0);
                        gDPPipeSync(g_displayListCursor++);
                        gDPSetTile(g_displayListCursor++, G_IM_FMT_CI, G_IM_SIZ_4b, ((stride >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, (stride - 1) * 4, (chunk - 1) * 4);
                        break;
                    case 8:
                        if (!started) {
                            started = 1;
                            gDPSetTile(g_displayListCursor++, G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                            gDPSetTile(g_displayListCursor++, G_IM_FMT_CI, G_IM_SIZ_8b, (stride + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                            gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, (stride - 1) * 4, (chunk - 1) * 4);
                            gDPPipeSync(g_displayListCursor++);
                        }
                        gDPLoadSync(g_displayListCursor++);
                        gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_CI, G_IM_SIZ_16b, 1, data);
                        gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, ((((stride * chunk + 1) >> 1) - 1) < 2047 ? (((stride * chunk + 1) >> 1) - 1) : 2047), 0);
                        break;
                    case 16:
                        gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, data);
                        gDPSetTile(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPLoadSync(g_displayListCursor++);
                        gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, ((stride * chunk - 1) < 2047 ? (stride * chunk - 1) : 2047), 0);
                        gDPPipeSync(g_displayListCursor++);
                        gDPSetTile(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (stride * 2 + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
                        gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, (stride - 1) * 4, (chunk - 1) * 4);
                        break;
                    }
                }
                gSPTextureRectangle(g_displayListCursor++, x0 >> 8, yTop >> 8, (x1 >> 8) + 4, (yBot >> 8) + 4, 0, sStart >> 5, tOff >> 5, dsdx, dtdy);
            }
        } while (y <= rows);
    }
}
