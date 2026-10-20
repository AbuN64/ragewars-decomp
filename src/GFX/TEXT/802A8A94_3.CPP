#include "include_asm.h"
#include "COMMON/OBJECTLINKSC_2.H"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"
#include "abi.h"
struct Node80253610;
extern void func_80253BBC_de(s32 heap, struct Node80253610 *resource);

/* Draws a text string in the current font style D_801376F8: when centring, measures it through func_804422F0_de at the style size scaled by the language-dependent factors for D_80147150, shrinks the scale so it fits 44 pixels inside the screen width D_800E28D0 and shifts x left by half the width; then sets the environment colour from the style with the given alpha and the primitive colour from the style, and draws the string through func_802A88F0_de, first as a shadow when requested. */

extern s32 D_800E28D0;
extern Gfx *D_80110634;
extern f32 func_804422F0_de(u8 *text, f32 size, f32 spacing);


void func_802A8F28_de(void * text, s32 x, s32 y, s32 alpha, s32 centred, s32 shadow, f32 scaleX, f32 scaleY) {
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
        width = func_804422F0_de(text, size, spacing);
        limit = D_800E28D0 - 0x2C;
        if (limit < width) {
            ratio = limit / width;
            scaleX *= ratio;
            width *= ratio;
        }
        x -= (s32)(width * 0.5f);
    }
    gDPPipeSync(D_80110634++);
    gDPSetEnvColor(D_80110634++, (u32)((style->envR)), (u32)((style->envG)), (u32)((style->envB)), (u32)((alpha)));
    gDPSetPrimColor(D_80110634++, 0, 0, (u32)((style->primR)), (u32)((style->primG)), (u32)((style->primB)), 255);
    fx = x;
    w = style->width * scaleX;
    h = style->height * scaleY;
    language = D_80147150;
    fy = y;
    if (shadow) {
        func_802A88F0_de(text, fx, fy, w, h, 1, alpha, language);
    }
    func_802A88F0_de(text, fx, fy, w, h, 0, alpha, language);
}

/* Emits the render-state display-list prologue for a flat colour pass: pipeline sync, one-cycle
   mode, the two combiner/mode presets through func_80268CE0_de and func_8026925C_de, the environment
   colour from the argument with full alpha bits, texture enable and the texture-filter, colour-dither
   and alpha-dither mode words, the alpha dither chosen by D_800E28D8. */

extern Gfx *D_80110634;
extern s32 D_800E28D8;

extern void func_80268CE0_de(s32 arg0);
extern void func_8026925C_de(s32 arg0);

void func_802A9234_de(s32 color) {
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
    func_80268CE0_de(0x1B);
    func_8026925C_de(0x19);
    {
        Gfx *cmd = D_80110634++;
        gDPSetEnvColor(cmd, 255, 255, 255, color);
    }
    gSPTexture(D_80110634++, 32768, 32768, 0, 0, G_ON);
    gDPSetTextureLUT(D_80110634++, G_TT_NONE);
    gDPSetTexturePersp(D_80110634++, G_TP_NONE);
    if (D_800E28D8 == 0) { gDPSetTextureFilter(D_80110634++, G_TF_POINT); } else { gDPSetTextureFilter(D_80110634++, G_TF_BILERP); }
}

extern Gfx *D_80110634;

void func_802A9364_de(void *pTexture, void *pOpacity, int XPos, int YPos, int TextureWidth, int TextureHeight) {
    { gDPSetTextureImage(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)pOpacity); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(D_80110634++); gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (u32)((((((TextureWidth*TextureHeight+3)>>2)-1)<2047?(((TextureWidth*TextureHeight+3)>>2)-1):2047))), (u32)((((1<<11)+(1>(TextureWidth/16)?1:(TextureWidth/16))-1)/(1>(TextureWidth/16)?1:(TextureWidth/16))))); gDPPipeSync(D_80110634++); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)(((((TextureWidth>>1)+7)>>3))), 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    { gDPSetTextureImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (u32)pTexture); gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(D_80110634++); gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (u32)((((TextureWidth*TextureHeight-1)<2047?(TextureWidth*TextureHeight-1):2047))), (u32)((((1<<11)+(1>(TextureWidth*2/8)?1:(TextureWidth*2/8))-1)/(1>(TextureWidth*2/8)?1:(TextureWidth*2/8))))); gDPPipeSync(D_80110634++); gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (u32)((((TextureWidth*2)+7)>>3)), 0, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)((TextureWidth/16)), 256, 1, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0);
    gDPSetTileSize(D_80110634++, 1, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2)));
    { Gfx *g=D_80110634++; gDPTexRect(g, XPos<<2, YPos<<2, (XPos+TextureWidth)<<2, (YPos+TextureHeight)<<2, 0); gDPHalf1(D_80110634++, 0); gDPHalf2(D_80110634++, (((u32)((1<<10)) & 0xFFFF) << ((16)))|(((u32)((1<<10)) & 0xFFFF) << ((0)))); }
}

extern Gfx *D_80110634;

void func_802A9734_de(void *pTexture, void *pOpacity, float XPos, float YPos, int TextureWidth, int TextureHeight, float ScaleX, float ScaleY) {
 int dsdx=1024,dtdy; int xl,yl,xh,yh;
 if(ScaleX!=0.0f) dsdx=dsdx/ScaleX;
 dtdy=1024;
 if(ScaleY!=0.0f) dtdy=dtdy/ScaleY;
 xl=XPos*D_800C61B8_de; xh=(XPos+TextureWidth*ScaleX)*D_800C61B8_de;
 yl=YPos*D_800C61B8_de; yh=(YPos+TextureHeight*ScaleY)*D_800C61B8_de;

    { gDPSetTextureImage(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)pOpacity); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(D_80110634++); gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (u32)((((((TextureWidth*TextureHeight+3)>>2)-1)<2047?(((TextureWidth*TextureHeight+3)>>2)-1):2047))), (u32)((((1<<11)+(1>(TextureWidth/16)?1:(TextureWidth/16))-1)/(1>(TextureWidth/16)?1:(TextureWidth/16))))); gDPPipeSync(D_80110634++); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)(((((TextureWidth>>1)+7)>>3))), 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    { gDPSetTextureImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (u32)pTexture); gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(D_80110634++); gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (u32)((((TextureWidth*TextureHeight-1)<2047?(TextureWidth*TextureHeight-1):2047))), (u32)((((1<<11)+(1>(TextureWidth*2/8)?1:(TextureWidth*2/8))-1)/(1>(TextureWidth*2/8)?1:(TextureWidth*2/8))))); gDPPipeSync(D_80110634++); gDPSetTile(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, (u32)((((TextureWidth*2)+7)>>3)), 0, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)((TextureWidth/16)), 256, 1, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0);
    gDPSetTileSize(D_80110634++, 1, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2)));
    gDPTexRect(D_80110634++,
        (s16)xl > 0 ? (s16)xl : 0, (s16)yl > 0 ? (s16)yl : 0,
        (s16)xh > 0 ? (s16)xh : 0, (s16)yh > 0 ? (s16)yh : 0,
        G_TX_RENDERTILE);
    gDPHalf1(D_80110634++, (((u32)((((short)xl<0 ? ((short)dsdx<0 ? -(((((short)xl*(short)dsdx)>>7))>((0))?((((short)xl*(short)dsdx)>>7)):((0))) : -(((((short)xl*(short)dsdx)>>7))<((0))?((((short)xl*(short)dsdx)>>7)):((0)))) : 0))) & 0xFFFF) << ((16)))
      | (((u32)(((yl<0 ? ((short)dtdy<0 ? -(((((short)yl*(short)dtdy)>>7))>((0))?((((short)yl*(short)dtdy)>>7)):((0))) : -(((((short)yl*(short)dtdy)>>7))<((0))?((((short)yl*(short)dtdy)>>7)):((0)))) : 0))) & 0xFFFF) << ((0))));
    gDPHalf2(D_80110634++, (((u32)((dsdx)) & 0xFFFF) << ((16)))|(((u32)((dtdy)) & 0xFFFF) << ((0))));
}

/* Appends display-list commands to D_80110634 that load a 4-bit texture block of the given size and draw it as a texture rectangle at the given position. Adapted from func_802A9364_de with the palette block and the second texture block removed and its first block's image pointer taken from the texture argument. */

extern Gfx *D_80110634;

void func_802A9CD0_de(void *pTexture, int XPos, int YPos, int TextureWidth, int TextureHeight) {
    { gDPSetTextureImage(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)pTexture); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(D_80110634++); gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (u32)((((((TextureWidth*TextureHeight+3)>>2)-1)<2047?(((TextureWidth*TextureHeight+3)>>2)-1):2047))), (u32)((((1<<11)+(1>(TextureWidth/16)?1:(TextureWidth/16))-1)/(1>(TextureWidth/16)?1:(TextureWidth/16))))); gDPPipeSync(D_80110634++); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)(((((TextureWidth>>1)+7)>>3))), 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    { Gfx *g=D_80110634++; gDPTexRect(g, XPos<<2, YPos<<2, (XPos+TextureWidth)<<2, (YPos+TextureHeight)<<2, 0); gDPHalf1(D_80110634++, 0); gDPHalf2(D_80110634++, (((u32)((1<<10)) & 0xFFFF) << ((16)))|(((u32)((1<<10)) & 0xFFFF) << ((0)))); }
}

/* Appends display-list commands to D_80110634 that load a 4-bit texture block of the given size and draw it as a texture rectangle at a floating-point position, stretched by the given horizontal and vertical scales with the texture steps divided by them. Adapted from func_802A9CD0_de with the position made floating point, the rectangle corners scaled by D_800C61BC_de and the scale factors applied to the extent and the texture step. */

extern Gfx *D_80110634;
extern f32 D_800C61BC_de;
void func_802A9EE8_de(void *pTexture, f32 XPos, f32 YPos, int TextureWidth, int TextureHeight, f32 ScaleX, f32 ScaleY) {
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
    { gDPSetTextureImage(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)pTexture); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPLoadSync(D_80110634++); gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, (u32)((((((TextureWidth*TextureHeight+3)>>2)-1)<2047?(((TextureWidth*TextureHeight+3)>>2)-1):2047))), (u32)((((1<<11)+(1>(TextureWidth/16)?1:(TextureWidth/16))-1)/(1>(TextureWidth/16)?1:(TextureWidth/16))))); gDPPipeSync(D_80110634++); gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_4b, (u32)(((((TextureWidth>>1)+7)>>3))), 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0); gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, (u32)(((TextureWidth-1)<<2)), (u32)(((TextureHeight-1)<<2))); }
    { Gfx *g=D_80110634++; gDPTexRect(g, xl, yl, xh, yh, 0); gDPHalf1(D_80110634++, 0); gDPHalf2(D_80110634++, (((u32)((dsdx)) & 0xFFFF) << ((16)))|(((u32)((dtdy)) & 0xFFFF) << ((0)))); }
}

#ifdef NON_MATCHING
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GFX.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "gbi.h"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/OBJECTLINKSC_2.H"
#include "COMMON/TRIPLE.H"
#include "stddef.h"
#include "TYPES.H"
void func_802AA8EC_de(Table802AB8DC **handle, s32 index, void **out, u8 *tag);
void func_802A9EE8_de(void *pTexture, f32 XPos, f32 YPos, int TextureWidth, int TextureHeight, f32 ScaleX, f32 ScaleY);
void func_802A9CD0_de(void *pTexture, int XPos, int YPos, int TextureWidth, int TextureHeight);
void func_802A9734_de(void *pTexture, void *pOpacity, float XPos, float YPos, int TextureWidth, int TextureHeight, float ScaleX, float ScaleY);
void func_802A9364_de(void *pTexture, void *pOpacity, int XPos, int YPos, int TextureWidth, int TextureHeight);
extern f64 D_800CB358;
typedef struct TextureTileBlock {
    u32 width;
    u32 height;
    u8 pixels[1];
} TextureTileBlock;
typedef struct TextureTileGrid {
    u16 columns;
    u16 rows;
    u32 reserved;
    u8 blocks[1];
} TextureTileGrid;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x48, 0x4c, 0x50, 0x54, 0x58, 0x5c, 0x60, 0x64, 0x68, 0x6c, 0x78, 0x7c, 0x88, 0x8c, 0x98, 0x9c, 0xa8, 0xac, 0xb8, 0xbc], gap at: 0x70. */
void func_802AA1AC_de(void *arg0, s32 arg1, s32 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6) {
    void *sp20;
    u8 sp24;
    TextureTileGrid *sp28;
    s32 sp2C;
    s32 sp30;
    TextureTileGrid *sp38;
    s32 sp3C;
    s32 sp40;
    Gfx *temp_a0;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs1;
    f32 temp_fs1_2;
    f32 temp_fs3;
    f32 temp_fs3_2;
    f32 temp_fv0;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv0f_3;
    f32 var_fs0;
    f32 var_fs0_2;
    f32 var_fs0f;
    f32 var_fs0f_2;
    f32 var_fs1;
    f32 var_fs1_2;
    f32 var_fs1f;
    f32 var_fs1f_2;
    f32 var_fv1f;
    f32 var_fv1f_2;
    f64 temp_fs2;
    f64 temp_fs2_2;
    f64 var_fv0;
    f64 var_fv0_2;
    f64 var_fv0_3;
    f64 var_fv0f;
    s16 var_fp;
    s16 var_s7;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s1;
    s32 temp_v0;
    s32 var_s1_2;
    s32 var_s2;
    s32 var_s3;
    s32 var_s3_3;
    s32 var_s4;
    s32 var_s4_2;
    s32 var_s4_3;
    s32 var_s5;
    s32 var_s5_2;
    s32 var_s6;
    s32 var_t0;
    s32 var_t1;
    u32 temp_lo;
    u32 temp_lo_2;
    TextureTileBlock *var_s1;
    TextureTileBlock *var_s2_2;
    TextureTileBlock *var_s2_3;
    TextureTileBlock *var_s3_2;
    TextureTileGrid *var_v1;
    s32 var_v1_2;

    temp_a0 = D_80110634;
    D_80110634 = (Gfx *)D_80110634 + 1;
    gDPPipeSync(temp_a0);
    
    if (arg0 != NULL) {
        sp3C = arg2;
        func_802AA8EC_de(arg0, arg1, &sp20, &sp24);
        var_v1 = sp20;
        if (var_v1 != NULL) {
            if (sp24 != 0) {
                if (arg6 != 0) {
                    var_fs1f = (f32) arg3;
                    var_s1 = (TextureTileBlock *)var_v1->blocks;
                    var_s2 = 0;
                    var_fv1f = D_800C61C0_de;
                    temp_fs1 = (f32) var_v1->rows;
                    var_fs1 = temp_fs1 - var_fv1f;
                    if (temp_fs1 != 0.0f) {
                        temp_fs2 = D_800CB358;
                        do {
                            temp_fs0 = (f32) var_v1->columns;
                            var_fs0 = temp_fs0 - var_fv1f;
                            var_fs0f = (f32) (s16) sp3C;
                            if (temp_fs0 != 0.0f) {
                                temp_fs3 = D_800C61D0_de;
                                do {
                                    var_s2 = var_s1->height;
                                    temp_s0 = var_s1->width;
                                    func_802A9EE8_de(var_s1->pixels, var_fs0f, var_fs1f, temp_s0, var_s2, arg4, arg5);
                                    var_fv0f = (f64) temp_s0;
                                    if (temp_s0 < 0) {
                                        var_fv0f += temp_fs2;
                                    }
                                    temp_fv0 = var_fs0;
                                    var_fs0 -= temp_fs3;
                                    var_s1 = (TextureTileBlock *)(var_s1->pixels + ((u32) (temp_s0 * var_s2) >> 1));
                                    var_fs0f += (f32) var_fv0f * arg4;
                                } while (temp_fv0 != 0.0f);
                            }
                            var_fv0 = (f64) var_s2;
                            if (var_s2 < 0) {
                                var_fv0 += temp_fs2;
                            }
                            var_fv1f = D_800C61D4_de;
                            temp_fv0f = var_fs1;
                            var_fs1 -= var_fv1f;
                            var_fs1f += (f32) var_fv0 * arg5;
                        } while (temp_fv0f != 0.0f);
                    }
                } else {
                    var_s7 = arg3;
                    var_s2_2 = (TextureTileBlock *)var_v1->blocks;
                    var_s4 = 0;
                    var_s5 = var_v1->rows - 1;
                    sp28 = var_v1;
                    if (var_s5 != -1) {
                        sp2C = sp3C << 0x10;
                        var_v1_2 = -1;
                        do {
                            var_s1_2 = sp28->columns - 1;
                            var_s3 = sp2C >> 0x10;
                            if (var_s1_2 != var_v1_2) {
                                do {
                                    temp_s0_2 = var_s2_2->width;
                                    var_s4 = var_s2_2->height;
                                    sp38 = var_v1_2;
                                    func_802A9CD0_de(var_s2_2->pixels, var_s3, (s32) var_s7, temp_s0_2, var_s4);
                                    var_s1_2 -= 1;
                                    var_s3 += temp_s0_2;
                                    var_s2_2 = (TextureTileBlock *)(var_s2_2->pixels + ((u32) (temp_s0_2 * var_s4) >> 1));
                                } while (var_s1_2 != -1);
                            }
                            var_s5 -= 1;
                            var_s7 += var_s4;
                        } while (var_s5 != var_v1_2);
                    }
                }
            } else if (arg6 != 0) {
                var_fs1f_2 = (f32) arg3;
                var_s3_2 = (TextureTileBlock *)var_v1->blocks;
                var_s4_2 = 0;
                var_fv1f_2 = D_800C61D8_de;
                temp_fs1_2 = (f32) var_v1->rows;
                var_fs1_2 = temp_fs1_2 - var_fv1f_2;
                if (temp_fs1_2 != 0.0f) {
                    temp_fs2_2 = D_800C61E0_de;
                    do {
                        temp_fs0_2 = (f32) var_v1->columns;
                        var_fs0_2 = temp_fs0_2 - var_fv1f_2;
                        var_fs0f_2 = (f32) (s16) sp3C;
                        if (temp_fs0_2 != 0.0f) {
                            temp_fs3_2 = D_800C61E8_de;
                            do {
                                var_s4_2 = var_s3_2->height;
                                temp_s0_3 = var_s3_2->width;
                                temp_lo = temp_s0_3 * var_s4_2;
                                temp_s1 = temp_lo * 2;
                                func_802A9734_de(var_s3_2->pixels, var_s3_2->pixels + temp_s1, var_fs0f_2, var_fs1f_2, temp_s0_3, var_s4_2, arg4, arg5);
                                var_fv0_2 = (f64) temp_s0_3;
                                if (temp_s0_3 < 0) {
                                    var_fv0_2 += temp_fs2_2;
                                }
                                temp_fv0f_3 = var_fs0_2;
                                var_fs0_2 -= temp_fs3_2;
                                var_s3_2 = (TextureTileBlock *)(var_s3_2->pixels + temp_s1 + (temp_lo >> 1));
                                var_fs0f_2 += (f32) var_fv0_2 * arg4;
                            } while (temp_fv0f_3 != 0.0f);
                        }
                        var_fv0_3 = (f64) var_s4_2;
                        if (var_s4_2 < 0) {
                            var_fv0_3 += temp_fs2_2;
                        }
                        var_fv1f_2 = D_800C61EC_de;
                        temp_fv0f_2 = var_fs1_2;
                        var_fs1_2 -= var_fv1f_2;
                        var_fs1f_2 += (f32) var_fv0_3 * arg5;
                    } while (temp_fv0f_2 != 0.0f);
                }
            } else {
                var_fp = arg3;
                var_s2_3 = (TextureTileBlock *)var_v1->blocks;
                var_s6 = var_v1->rows - 1;
                var_s5_2 = 0;
                if (var_s6 != -1) {
                    sp30 = sp3C << 0x10;
                    var_t1 = -1;
                    do {
                        var_s3_3 = var_v1->columns - 1;
                        var_s4_3 = sp30 >> 0x10;
                        if (var_s3_3 != var_t1) {
                            var_t0 = -1;
                            do {
                                temp_a2 = var_s4_3;
                                var_s5_2 = var_s2_3->height;
                                temp_v0 = var_s2_3->width;
                                var_s3_3 -= 1;
                                sp38 = var_v1;
                                sp3C = var_t0;
                                temp_lo_2 = temp_v0 * var_s5_2;
                                sp40 = var_t1;
                                var_s4_3 += temp_v0;
                                temp_s0_4 = temp_lo_2 * 2;
                                func_802A9364_de(var_s2_3->pixels, var_s2_3->pixels + temp_s0_4, temp_a2, (s32) var_fp, temp_v0, var_s5_2);
                                var_s2_3 = (TextureTileBlock *)(var_s2_3->pixels + temp_s0_4 + (temp_lo_2 >> 1));
                            } while (var_s3_3 != var_t0);
                        }
                        var_s6 -= 1;
                        var_fp += var_s5_2;
                    } while (var_s6 != var_t1);
                }
            }
            func_80253BBC_de(0, arg0);
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_802AA1AC_de);
#endif
