#include "SCENE/802508E0_9.H"
#include "include_asm.h"
#include "COMMON/OBJECTLINKSC_2.H"
#include "GFX/802A8A94.H"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"
#include "abi.h"
struct Node80253610;

/* Draws a text string in the current font style D_801376F8: when centring, measures it through Pak_MeasureLine at the style size scaled by the language-dependent factors for D_80147150, shrinks the scale so it fits 44 pixels inside the screen width D_800E28D0 and shifts x left by half the width; then sets the environment colour from the style with the given alpha and the primitive colour from the style, and draws the string through OnScreen_DrawTextGlyphs, first as a shadow when requested. */

extern Gfx *g_displayListCursor;
extern f32 Pak_MeasureLine(u8 *text, f32 size, f32 spacing);


void OnScreen_DrawText(void * text, s32 x, s32 y, s32 alpha, s32 centred, s32 shadow, f32 scaleX, f32 scaleY) {
    FontStyle *style;
    f32 sizeFactor;
    f32 spacing;
    f32 size;
    f32 width;
    f32 limit;
    f32 ratio;
    f32 fx;
    f32 fy;
    f32 w;
    f32 h;
    s32 language;

    style = &D_801376F8;
    if (centred) {
        switch (D_80147150) {
        case 0:
            sizeFactor = 24.0f;
            break;
        case 1:
            sizeFactor = 12.0f;
            break;
        case 3:
            sizeFactor = 6.0f;
            break;
        case 4:
        case 5:
            sizeFactor = 16.0f;
            break;
        case 2:
        case 6:
            sizeFactor = 8.0f;
            break;
        default:
            sizeFactor = 1.0f;
            break;
        }
        size = style->width * scaleX * sizeFactor;
        switch (D_80147150) {
        case 0:
            spacing = 24.0f;
            break;
        case 1:
            spacing = 12.0f;
            break;
        case 3:
            spacing = 6.0f;
            break;
        case 4:
        case 5:
            spacing = 16.0f;
            break;
        case 2:
        case 6:
            spacing = 8.0f;
            break;
        default:
            spacing = 1.0f;
            break;
        }
        width = Pak_MeasureLine(text, size, spacing);
        limit = D_800E28D0 - 0x2C;
        if (limit < width) {
            ratio = limit / width;
            scaleX *= ratio;
            width *= ratio;
        }
        x -= (s32)(width * 0.5f);
    }
    gDPPipeSync(g_displayListCursor++);
    gDPSetEnvColor(g_displayListCursor++, (u32)((style->envR)), (u32)((style->envG)), (u32)((style->envB)), (u32)((alpha)));
    gDPSetPrimColor(g_displayListCursor++, 0, 0, (u32)((style->primR)), (u32)((style->primG)), (u32)((style->primB)), 255);
    fx = x;
    w = style->width * scaleX;
    h = style->height * scaleY;
    language = D_80147150;
    fy = y;
    if (shadow) {
        OnScreen_DrawTextGlyphs(text, fx, fy, w, h, 1, alpha, language);
    }
    OnScreen_DrawTextGlyphs(text, fx, fy, w, h, 0, alpha, language);
}

/* Emits the render-state display-list prologue for a flat colour pass: pipeline sync, one-cycle
   mode, the two combiner/mode presets through func_80268CE0_de and Geometry_SetModePreset, the environment
   colour from the argument with full alpha bits, texture enable and the texture-filter, colour-dither
   and alpha-dither mode words, the alpha dither chosen by D_800E28D8. */

extern Gfx *g_displayListCursor;

extern void Geometry_SetCombineMode(s32 arg0);
extern void Geometry_SetModePreset(s32 arg0);

void OnScreen_SetupSpriteMode(s32 color) {
    gDPPipeSync(g_displayListCursor++);
    gDPSetCycleType(g_displayListCursor++, G_CYC_2CYCLE);
    Geometry_SetCombineMode(0x1B);
    Geometry_SetModePreset(0x19);
    {
        Gfx *cmd = g_displayListCursor++;
        gDPSetEnvColor(cmd, 255, 255, 255, color);
    }
    gSPTexture(g_displayListCursor++, 32768, 32768, 0, 0, G_ON);
    gDPSetTextureLUT(g_displayListCursor++, G_TT_NONE);
    gDPSetTexturePersp(g_displayListCursor++, G_TP_NONE);
    if (D_800E28D8 == 0) { gDPSetTextureFilter(g_displayListCursor++, G_TF_POINT); } else { gDPSetTextureFilter(g_displayListCursor++, G_TF_BILERP); }
}

extern Gfx *g_displayListCursor;

void OnScreen_DrawTextureWithOpacity(void *pTexture, void *pOpacity, int XPos, int YPos, int TextureWidth, int TextureHeight) {
    { gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)pOpacity); gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(g_displayListCursor++); gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, (u32)((((((TextureWidth*TextureHeight+3)>>2)-1)<2047?(((TextureWidth*TextureHeight+3)>>2)-1):2047))), (u32)((((1<<11)+(1>(TextureWidth/16)?1:(TextureWidth/16))-1)/(1>(TextureWidth/16)?1:(TextureWidth/16))))); gDPPipeSync(g_displayListCursor++); gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)(((((TextureWidth>>1)+7)>>3))), 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    { gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (u32)pTexture); gDPSetTile(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(g_displayListCursor++); gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, (u32)((((TextureWidth*TextureHeight-1)<2047?(TextureWidth*TextureHeight-1):2047))), (u32)((((1<<11)+(1>(TextureWidth*2/8)?1:(TextureWidth*2/8))-1)/(1>(TextureWidth*2/8)?1:(TextureWidth*2/8))))); gDPPipeSync(g_displayListCursor++); gDPSetTile(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (u32)((((TextureWidth*2)+7)>>3)), 0, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)((TextureWidth/16)), 256, 1, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0);
    gDPSetTileSize(g_displayListCursor++, 1, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2)));
    { Gfx *g=g_displayListCursor++; gDPTexRect(g, XPos<<2, YPos<<2, (XPos+TextureWidth)<<2, (YPos+TextureHeight)<<2, 0); gDPHalf1(g_displayListCursor++, 0); gDPHalf2(g_displayListCursor++, (((u32)((1<<10)) & 0xFFFF) << ((16)))|(((u32)((1<<10)) & 0xFFFF) << ((0)))); }
}

extern Gfx *g_displayListCursor;

void OnScreen_DrawScaledMaskedImage(void *pTexture, void *pOpacity, float XPos, float YPos, int TextureWidth, int TextureHeight, float ScaleX, float ScaleY) {
 int dsdx=1024,dtdy; int xl,yl,xh,yh;
 if(ScaleX!=0.0f) dsdx=dsdx/ScaleX;
 dtdy=1024;
 if(ScaleY!=0.0f) dtdy=dtdy/ScaleY;
 xl=XPos*D_800C61B8_de; xh=(XPos+TextureWidth*ScaleX)*D_800C61B8_de;
 yl=YPos*D_800C61B8_de; yh=(YPos+TextureHeight*ScaleY)*D_800C61B8_de;

    { gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)pOpacity); gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(g_displayListCursor++); gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, (u32)((((((TextureWidth*TextureHeight+3)>>2)-1)<2047?(((TextureWidth*TextureHeight+3)>>2)-1):2047))), (u32)((((1<<11)+(1>(TextureWidth/16)?1:(TextureWidth/16))-1)/(1>(TextureWidth/16)?1:(TextureWidth/16))))); gDPPipeSync(g_displayListCursor++); gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)(((((TextureWidth>>1)+7)>>3))), 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    { gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (u32)pTexture); gDPSetTile(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(g_displayListCursor++); gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, (u32)((((TextureWidth*TextureHeight-1)<2047?(TextureWidth*TextureHeight-1):2047))), (u32)((((1<<11)+(1>(TextureWidth*2/8)?1:(TextureWidth*2/8))-1)/(1>(TextureWidth*2/8)?1:(TextureWidth*2/8))))); gDPPipeSync(g_displayListCursor++); gDPSetTile(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (u32)((((TextureWidth*2)+7)>>3)), 0, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)((TextureWidth/16)), 256, 1, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0);
    gDPSetTileSize(g_displayListCursor++, 1, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2)));
    gDPTexRect(g_displayListCursor++,
        (s16)xl > 0 ? (s16)xl : 0, (s16)yl > 0 ? (s16)yl : 0,
        (s16)xh > 0 ? (s16)xh : 0, (s16)yh > 0 ? (s16)yh : 0,
        G_TX_RENDERTILE);
    gDPHalf1(g_displayListCursor++, (((u32)((((short)xl<0 ? ((short)dsdx<0 ? -(((((short)xl*(short)dsdx)>>7))>((0))?((((short)xl*(short)dsdx)>>7)):((0))) : -(((((short)xl*(short)dsdx)>>7))<((0))?((((short)xl*(short)dsdx)>>7)):((0)))) : 0))) & 0xFFFF) << ((16)))
      | (((u32)(((yl<0 ? ((short)dtdy<0 ? -(((((short)yl*(short)dtdy)>>7))>((0))?((((short)yl*(short)dtdy)>>7)):((0))) : -(((((short)yl*(short)dtdy)>>7))<((0))?((((short)yl*(short)dtdy)>>7)):((0)))) : 0))) & 0xFFFF) << ((0))));
    gDPHalf2(g_displayListCursor++, (((u32)((dsdx)) & 0xFFFF) << ((16)))|(((u32)((dtdy)) & 0xFFFF) << ((0))));
}

/* Appends display-list commands to D_80110634 that load a 4-bit texture block of the given size and draw it as a texture rectangle at the given position. Adapted from OnScreen_DrawTextureWithOpacity with the palette block and the second texture block removed and its first block's image pointer taken from the texture argument. */

extern Gfx *g_displayListCursor;

void OnScreen_DrawIntensityTexture(void *pTexture, int XPos, int YPos, int TextureWidth, int TextureHeight) {
    { gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)pTexture); gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(g_displayListCursor++); gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, (u32)((((((TextureWidth*TextureHeight+3)>>2)-1)<2047?(((TextureWidth*TextureHeight+3)>>2)-1):2047))), (u32)((((1<<11)+(1>(TextureWidth/16)?1:(TextureWidth/16))-1)/(1>(TextureWidth/16)?1:(TextureWidth/16))))); gDPPipeSync(g_displayListCursor++); gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)(((((TextureWidth>>1)+7)>>3))), 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    { Gfx *g=g_displayListCursor++; gDPTexRect(g, XPos<<2, YPos<<2, (XPos+TextureWidth)<<2, (YPos+TextureHeight)<<2, 0); gDPHalf1(g_displayListCursor++, 0); gDPHalf2(g_displayListCursor++, (((u32)((1<<10)) & 0xFFFF) << ((16)))|(((u32)((1<<10)) & 0xFFFF) << ((0)))); }
}

/* Appends display-list commands to D_80110634 that load a 4-bit texture block of the given size and draw it as a texture rectangle at a floating-point position, stretched by the given horizontal and vertical scales with the texture steps divided by them. Adapted from OnScreen_DrawIntensityTexture with the position made floating point, the rectangle corners scaled by D_800C61BC_de and the scale factors applied to the extent and the texture step. */

extern Gfx *g_displayListCursor;
void OnScreen_DrawScaledIntensityTexture(void *pTexture, f32 XPos, f32 YPos, int TextureWidth, int TextureHeight, f32 ScaleX, f32 ScaleY) {
    int dsdx;
    int dtdy;
    int xl, yl, xh, yh;

    dsdx = 1 << 10;
    if (ScaleX != 0.0f) {
        dsdx = dsdx / ScaleX;
    }
    dtdy = 1 << 10;
    if (ScaleY != 0.0f) {
        dtdy = dtdy / ScaleY;
    }
    xl = XPos * D_800C61BC_de;
    xh = (XPos + TextureWidth * ScaleX) * D_800C61BC_de;
    yl = YPos * D_800C61BC_de;
    yh = (YPos + TextureHeight * ScaleY) * D_800C61BC_de;
    { gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)pTexture); gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(g_displayListCursor++); gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, (u32)((((((TextureWidth*TextureHeight+3)>>2)-1)<2047?(((TextureWidth*TextureHeight+3)>>2)-1):2047))), (u32)((((1<<11)+(1>(TextureWidth/16)?1:(TextureWidth/16))-1)/(1>(TextureWidth/16)?1:(TextureWidth/16))))); gDPPipeSync(g_displayListCursor++); gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)(((((TextureWidth>>1)+7)>>3))), 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    { Gfx *g=g_displayListCursor++; gDPTexRect(g, xl, yl, xh, yh, 0); gDPHalf1(g_displayListCursor++, 0); gDPHalf2(g_displayListCursor++, (((u32)((dsdx)) & 0xFFFF) << ((16)))|(((u32)((dtdy)) & 0xFFFF) << ((0)))); }
}

