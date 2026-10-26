#include "COMMON/TEXTURE.H"
#include "abi.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/RECTANGLE_DRAW.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "MENU/GFX/80414430_20.H"
#include "MENU/GFX/80414430_22.H"
#include "MENU/GFX/80414430_3.H"

/* Makes palette the current texture lookup table for a texture of the given bit depth: returns 1
   when it already is (D_800E32D8); otherwise records it, emits one pipeline sync if none is pending
   and, for 4-bit and 8-bit textures, enables the RGBA16 lookup table and loads the 16 or 256
   palette entries (texture image, tile sync, tile, load sync, load TLUT, pipeline sync), or for
   16-bit textures turns the lookup table off; returns 0. */



extern void *D_800E32D8;


static inline void sync(void) {
    Gfx *cmd;

    if (D_800E32E4 == 0) {
        D_800E32E4 = 1;
        cmd = g_displayListCursor++;
        gDPPipeSync(cmd);
    }
}

extern s32 func_80413608_de(u8 *);

static inline u32 blockWord16(void) {
   s32 num; s32 count;
   num=(D_800DF254->stride/16>0 ? D_800DF254->stride/16+2047:2048);
   count=((D_800DF254->stride*D_800DF254->rows+3)>>2)-1;
   if(count>=2048) count=2047;
 return _SHIFTL(G_TX_LOADTILE,24,3) | _SHIFTL(count,12,12) | _SHIFTL(D_800DF254->stride/16>0 ? num/(D_800DF254->stride/16):num,0,12);
}

static inline u32 blockWord8(void) {
   s32 num; s32 count;
   num=(D_800DF254->stride/8>0 ? D_800DF254->stride/8+2047:2048);
   count=((D_800DF254->stride*D_800DF254->rows+1)>>1)-1;
   if(count>=2048) count=2047;
 return _SHIFTL(G_TX_LOADTILE,24,3) | _SHIFTL(count,12,12) | _SHIFTL(D_800DF254->stride/8>0 ? num/(D_800DF254->stride/8):num,0,12);
}

static inline u32 blockWord4(void) {
   s32 num; s32 count;
   num=(D_800DF254->stride/4>0 ? D_800DF254->stride/4+2047:2048);
   count=D_800DF254->stride*D_800DF254->rows-1;
   if(count>=2048) count=2047;
 return _SHIFTL(G_TX_LOADTILE,24,3) | _SHIFTL(count,12,12) | _SHIFTL(D_800DF254->stride/4>0 ? num/(D_800DF254->stride/4):num,0,12);
}

static __inline__ void rectangleEmit(u32 w0, u32 w1) { Gfx *cmd = g_displayListCursor++; cmd->words.w0 = w0; cmd->words.w1 = w1; }

static __inline__ void rectangleSync(void) {
 Gfx *cmd;
 if (D_800E32E4 == 0) { D_800E32E4 = 1; cmd = g_displayListCursor++; gDPPipeSync(cmd); }
}

static inline f32 scaleClip(f32 delta, f32 ratio) { return ratio * delta; }

s32 Gfx_LoadPalette(s32 bits, void *palette) {
    s32 result;

    result = 1;
    if (D_800E32D8 != palette) {
        D_800E32D8 = palette;
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

void func_804174F4_de(Texture *arg0) {
 s32 paletteSame,flags,size;
 Texture *tex=arg0;
 if (arg0 == 0) {
 D_800DF258=0; D_800DF25C=0; D_800DF254=0;
 D_800DF260_de=0; D_800DF264_de=0; D_800DF26C_de=0;
 } else {
 D_800DF254=tex; D_800DF264_de=0;
 D_800DF258=tex->width; D_800DF25C=tex->height;
 D_800DF268_de=func_80413608_de(&tex->unk0);
 D_800DF26C_de=func_804136D8_de(&D_800DF254->unk0);
 flags=tex->flags;size=tex->size;
 D_800DF260_de=0;
 if(flags>0 && size>2048) D_800DF260_de=1;
 if(flags==0 && size>4096) D_800DF260_de=1;
 paletteSame=Gfx_LoadPalette(D_800DF268_de,D_800DF254->palette);
 if(D_800DF260_de==0) {
  if(D_800DF268_de==4) {
   gDPSetTextureImage(g_displayListCursor++,G_IM_FMT_CI,G_IM_SIZ_16b,1,D_800DF254->data);
   gDPSetTile(g_displayListCursor++,G_IM_FMT_CI,G_IM_SIZ_16b,0,0,7,0,2,0,0,2,0,0);
   gDPLoadSync(g_displayListCursor++);
   _GBI_CMD(g_displayListCursor++, _SHIFTL(G_LOADBLOCK,24,8), blockWord16());
   gDPPipeSync(g_displayListCursor++);
   gDPSetTile(g_displayListCursor++,G_IM_FMT_CI,G_IM_SIZ_4b,(((s16)(u16)D_800DF254->stride >> 1)+7)>>3,0,0,0,2,0,0,2,0,0);
   gDPSetTileSize(g_displayListCursor++,0,0,0,(D_800DF254->stride-1)*4,(D_800DF254->rows-1)*4);
  }
  else if(D_800DF268_de==8) {
   if(paletteSame==0) {
    gDPSetTile(g_displayListCursor++,G_IM_FMT_CI,G_IM_SIZ_16b,0,0,7,0,2,0,0,2,0,0);
    gDPPipeSync(g_displayListCursor++);
   }
   gDPLoadSync(g_displayListCursor++);
   gDPSetTile(g_displayListCursor++,G_IM_FMT_CI,G_IM_SIZ_8b,(D_800DF254->stride+7)>>3,0,0,0,2,0,0,2,0,0);
   gDPSetTileSize(g_displayListCursor++,0,0,0,(D_800DF254->stride-1)*4,(D_800DF254->rows-1)*4);
   gDPSetTextureImage(g_displayListCursor++,G_IM_FMT_CI,G_IM_SIZ_16b,1,D_800DF254->data);
   _GBI_CMD(g_displayListCursor++, _SHIFTL(G_LOADBLOCK,24,8), blockWord8());
  }
  else if(D_800DF268_de==16) {
   gDPSetTextureImage(g_displayListCursor++,G_IM_FMT_RGBA,G_IM_SIZ_16b,1,D_800DF254->data);
   gDPSetTile(g_displayListCursor++,G_IM_FMT_RGBA,G_IM_SIZ_16b,0,0,7,0,2,0,0,2,0,0);
   gDPLoadSync(g_displayListCursor++);
   _GBI_CMD(g_displayListCursor++, _SHIFTL(G_LOADBLOCK,24,8), blockWord4());
   gDPPipeSync(g_displayListCursor++);
   gDPSetTile(g_displayListCursor++,G_IM_FMT_RGBA,G_IM_SIZ_16b,(D_800DF254->stride*2+7)>>3,0,0,0,2,0,0,2,0,0);
   gDPSetTileSize(g_displayListCursor++,0,0,0,(D_800DF254->stride-1)*4,(D_800DF254->rows-1)*4);
  }
 }
 }
}

void func_80417B20_de(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, u32 arg9) {
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    Gfx *temp_a0;
    Gfx *temp_a0_2;
    Gfx *temp_a0_3;
    Gfx *temp_a1;
    Gfx *temp_v1;
    Gfx *temp_v1_2;
    Gfx *temp_v1_3;
    Gfx *temp_v1_4;
    Gfx *temp_v1_6;
    Gfx *var_v1;
    f32 temp_fs3;
    f32 temp_fs3f;
    f32 temp_fv0;
    f32 temp_fv0_3;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 var_fs1;
    f32 var_fs1f;
    f32 var_fs2;
    f32 temp_fv0_2;
    f32 temp_fv0_4;
    s32 defaultMode;
    s32 var_a0;
    s32 var_a0_2;
    f32 var_fs0;
    f32 var_fs0f;
    f32 var_fs2f;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    u32 temp_v1_5;

    var_fs2f = arg3;
    var_fs2 = arg4;
    var_fs0 = arg5;
    var_fs0f = arg6;
    var_fs1 = arg7;
    temp_fs3 = arg0;
    var_fs1f = arg8;
    temp_fs3f = arg1;
    if ((D_80153F60.z == 0) || (D_80153F60.y == 0)) {
        D_800DF290 = 0;
        D_800E32E4 = 0;
        Gfx_SetRenderMode(0xC);
        Gfx_SetCombineMode(5);
        if (D_800DF274 != 7) {
            D_800DF274 = 7;
            rectangleSync();
            rectangleEmit(0xE3000C00, 0);
            
        }
        if (D_800DF280 != 0xE) {
            D_800DF280 = 0xE;
            rectangleSync();
            rectangleEmit(0xD7000000, 0x80008000);
            
        }
        if (D_80153F60.x == 0) {
            func_80416ECC_de(9);
            func_80415C90_de(temp_fs3, temp_fs3f, var_fs2f, var_fs2, (u32) arg9, (u32) arg9, (u32) arg9, (u32) arg9);
        }
    } else if (D_80153F60.x == 0) {
        D_800E32E4 = 0;
        Gfx_SetRenderMode(0xC);
        defaultMode = 0xD;
        var_a0 = defaultMode;
        if (D_80153F68 == 0) {
            var_a0 = 0xE;
        }
        if (var_a0 != D_800DF280) {
            D_800DF280 = var_a0;
            rectangleSync();
            if (var_a0 == defaultMode) rectangleEmit(0xD7000002, 0x80008000);
            else if (var_a0 == 0xE) rectangleEmit(0xD7000000, 0x80008000);
        }
        if (arg9 != D_800DF28C) {
            D_800DF28C = arg9;
            temp_v1_5 = (((u32) arg9 >> 0x10) << 0x18) | ((arg9 & 0xFF00) << 8) | ((arg9 & 0xFF) << 8);
            rectangleEmit(0xFB000000, temp_v1_5);
            rectangleEmit(0xFA000000, temp_v1_5 | ((u32)arg9 >> 0x18));
        }
        if (D_800DF274 != 7) {
            D_800DF274 = 7;
            rectangleSync();
            rectangleEmit(0xE3000C00, 0);
            
        }
        var_a0_2 = 2;
        if (D_800DF26C_de != 0) {
            var_a0_2 = 1;
        }
        Gfx_SetCombineMode(var_a0_2);
        var_s0 = (s32) temp_fs3;
        var_s1 = (s32) temp_fs3f;
        D_800DF290 = 0x13;
        var_s2 = (s32) ((temp_fs3 + var_fs2f) - D_800DD400_de);
        var_s3 = (s32) ((temp_fs3f + var_fs2) - D_800DD400_de);
        if (var_s2 < var_s0) {
            temp_fv0 = (f32) var_s0;
            var_s0 = var_s2;
            var_s2 = (s32) temp_fv0;
            temp_fv0_2 = var_fs0;
            var_fs0 = var_fs1;
            var_fs1 = temp_fv0_2;
            var_fs2f = -var_fs2f;
        }
        if (var_s3 < var_s1) {
            temp_fv0_3 = (f32) var_s1;
            var_s1 = var_s3;
            var_s3 = (s32) temp_fv0_3;
            temp_fv0_4 = var_fs0f;
            var_fs0f = var_fs1f;
            var_fs1f = temp_fv0_4;
            var_fs2 = -var_fs2;
        }
        func_802A1898_de(&sp20, &sp24, &sp28, &sp2C);
        if ((sp28 < var_s2) || (var_s0 < sp20) || (sp2C < var_s3) || (var_s1 < sp24)) {
            if ((sp28 >= var_s0) && (sp2C >= var_s1) && (var_s2 >= sp20) && (var_s3 >= sp24)) {
                if (var_s1 < sp24) {
                    temp_fv0f = var_fs1f - var_fs0f;
                    temp_fv0f=scaleClip(temp_fv0f, ((f32) (sp24 - var_s1) / var_fs2));
                    var_s1 = sp24;
                    var_fs2 = (f32) ((var_s3 - var_s1) + 1);
                    var_fs0f = (var_fs0f + temp_fv0f);
                }
                if (sp2C < var_s3) {
                    temp_fv0f = ((f32) (sp2C - var_s1) / var_fs2) * (var_fs1f - var_fs0f);
                    var_s3 = sp2C;
                    var_fs1f = var_fs0f + temp_fv0f;
                }
                if (var_s0 < sp20) {
                    temp_fv0f_2 = var_fs1 - var_fs0;
                    temp_fv0f_2=scaleClip(temp_fv0f_2, ((f32) (sp20 - var_s0) / var_fs2f));
                    var_s0 = sp20;
                    var_fs2f = (f32) ((var_s2 - var_s0) + 1);
                    var_fs0 = (var_fs0 + temp_fv0f_2);
                }
                if (sp28 < var_s2) {
                    temp_fv0f_2 = ((f32) (sp28 - var_s0) / var_fs2f) * (var_fs1 - var_fs0);
                    var_s2 = sp28;
                    var_fs1 = var_fs0 + temp_fv0f_2;
                }
                goto block_51;
            }
        } else {
block_51:
            if ((var_fs1 < var_fs0) || (var_fs1f < var_fs0f) || (D_800DF260_de != 0)) {
                func_804181A4_de(var_s0, var_s1, var_s2, var_s3, var_fs0, var_fs0f, var_fs1, var_fs1f);
            } else {
                Gfx_EmitTextureRect(var_s0, var_s1, var_s2, var_s3, var_fs0, var_fs0f, var_fs1, var_fs1f);
            }
        }
    }
}

void func_804181A4_de(s32 x0, s32 y0, s32 x1, s32 y1, f32 u0, f32 v0, f32 u1, f32 v1) {
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
    if (D_800DF254->width == 0) {
        return;
    }
    if (D_800DF254->height == 0) {
        return;
    }
    if (x0 == x1) {
        return;
    }
    if (y0 == y1) {
        return;
    }
    w = D_800DF254->width;
    dx = x1 - x0 + 1;
    dsdx = (s32)((u1 - u0) * (f32)w * D_800DD404) / dx;
    h = D_800DF254->height;
    fh = (v1 - v0) * (f32)h;
    dy = y1 - y0 + 1;
    intH = (s32)fh;
    dtdy = (s32)(fh * D_800DD404) / dy;
    stride = D_800DF254->stride;
    bpp = D_800DF268_de;
    D_800DF264_de = 0;
    if (intH == 0) {
        scale = 1000;
    } else {
        scale = (s32)((f32)dy * D_800DD404 / fh);
    }
    x0 = x0 << 10;
    y0 = y0 << 10;
    y1 = y1 << 10;
    x1 = x1 << 10;
    vOff = (s32)(v0 * (f32)h * D_800DD408_de[0]);
    switch (bpp) {
    case 4:
        st4 = (s16)(u16)D_800DF254->stride;
        chunk = (0x1000 / st4) & ~1;
        rowBytes = st4 / 2;
        break;
    case 8:
        chunk = (0x800 / D_800DF254->stride) & ~1;
        rowBytes = D_800DF254->stride;
        break;
    case 16:
        rowBytes = D_800DF254->stride * 2;
        chunk = (0x800 / D_800DF254->stride) & ~1;
        break;
    case 24:
        rowBytes = D_800DF254->stride * 4;
        chunk = (0x400 / D_800DF254->stride) & ~1;
        break;
    default:
        rowBytes = 0;
        chunk = 0;
        break;
    }
    if (D_800DF254->height < chunk) {
        chunk = D_800DF254->height;
    }
    rows = D_800DF254->height;
    sStart = (s32)(u0 * (f32)w * D_800DD408_de[1]);
    y = 0;
    if (rows >= 0) {
        do {
            yNext = y + chunk;
            yTop = y0 + (scale * (y * 0x400 - vOff) >> 10);
            yBot = y0 + (scale * (yNext * 0x400 - vOff) >> 10) - 0x400;
            data = D_800DF254->data + y * rowBytes;
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
                if (D_800DF260_de == 0) {
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
