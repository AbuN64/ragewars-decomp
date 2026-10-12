#include "types.h"
#include "gfx.h"
#include "n64sdk.h"
#include "gbi.h"
typedef struct Texture Texture;
struct Texture {
 u8 unk0; char pad1[3]; s16 width,height,stride,rows;
 s32 size,flags; void *palette; u32 data;
};
extern Texture *D_800DF254;
extern s32 D_800DF258,D_800DF25C,D_800DF260_de,D_800DF264_de,D_800DF268_de,D_800DF26C_de;
extern Gfx *D_80110634;
extern s32 func_80413608_de(u8 *),func_804136D8_de(u8 *),func_8041737C_de(s32,void *);
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
 paletteSame=func_8041737C_de(D_800DF268_de,D_800DF254->palette);
 if(D_800DF260_de==0) {
  if(D_800DF268_de==4) {
   gDPSetTextureImage(D_80110634++,G_IM_FMT_CI,G_IM_SIZ_16b,1,D_800DF254->data);
   gDPSetTile(D_80110634++,G_IM_FMT_CI,G_IM_SIZ_16b,0,0,7,0,2,0,0,2,0,0);
   gDPLoadSync(D_80110634++);
   _GBI_CMD(D_80110634++, _SHIFTL(G_LOADBLOCK,24,8), blockWord16());
   gDPPipeSync(D_80110634++);
   gDPSetTile(D_80110634++,G_IM_FMT_CI,G_IM_SIZ_4b,(((s16)(u16)D_800DF254->stride >> 1)+7)>>3,0,0,0,2,0,0,2,0,0);
   gDPSetTileSize(D_80110634++,0,0,0,(D_800DF254->stride-1)*4,(D_800DF254->rows-1)*4);
  }
  else if(D_800DF268_de==8) {
   if(paletteSame==0) {
    gDPSetTile(D_80110634++,G_IM_FMT_CI,G_IM_SIZ_16b,0,0,7,0,2,0,0,2,0,0);
    gDPPipeSync(D_80110634++);
   }
   gDPLoadSync(D_80110634++);
   gDPSetTile(D_80110634++,G_IM_FMT_CI,G_IM_SIZ_8b,(D_800DF254->stride+7)>>3,0,0,0,2,0,0,2,0,0);
   gDPSetTileSize(D_80110634++,0,0,0,(D_800DF254->stride-1)*4,(D_800DF254->rows-1)*4);
   gDPSetTextureImage(D_80110634++,G_IM_FMT_CI,G_IM_SIZ_16b,1,D_800DF254->data);
   _GBI_CMD(D_80110634++, _SHIFTL(G_LOADBLOCK,24,8), blockWord8());
  }
  else if(D_800DF268_de==16) {
   gDPSetTextureImage(D_80110634++,G_IM_FMT_RGBA,G_IM_SIZ_16b,1,D_800DF254->data);
   gDPSetTile(D_80110634++,G_IM_FMT_RGBA,G_IM_SIZ_16b,0,0,7,0,2,0,0,2,0,0);
   gDPLoadSync(D_80110634++);
   _GBI_CMD(D_80110634++, _SHIFTL(G_LOADBLOCK,24,8), blockWord4());
   gDPPipeSync(D_80110634++);
   gDPSetTile(D_80110634++,G_IM_FMT_RGBA,G_IM_SIZ_16b,(D_800DF254->stride*2+7)>>3,0,0,0,2,0,0,2,0,0);
   gDPSetTileSize(D_80110634++,0,0,0,(D_800DF254->stride-1)*4,(D_800DF254->rows-1)*4);
  }
 }
 }
}
