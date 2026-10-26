#include <stddef.h>
#include "TYPES.H"
#include "COMMON/OBJECTLINKSC_2.H"
#include "COMMON/GFX.H"
#include "gbi.h"

#if defined(VERSION_US_REV1)
struct Node80253610;
extern void Cache_MarkResourceInUse(s32 heap, struct Node80253610 *resource);
extern Gfx *g_displayListCursor;

void func_802AA8EC_de(Table802AB8DC **handle, s32 index, void **out, u8 *tag);
void func_802A9EE8_de(void *pTexture, f32 XPos, f32 YPos, int TextureWidth, int TextureHeight, f32 ScaleX, f32 ScaleY);
void func_802A9CD0_de(void *pTexture, int XPos, int YPos, int TextureWidth, int TextureHeight);
void OnScreen_DrawScaledMaskedImage(void *pTexture, void *pOpacity, float XPos, float YPos, int TextureWidth, int TextureHeight, float ScaleX, float ScaleY);
void func_802A9364_de(void *pTexture, void *pOpacity, int XPos, int YPos, int TextureWidth, int TextureHeight);
#include "GFX/TEXTURE_TILE_TYPES.H"



void Text_DrawTileGrid(void *handle, s32 index, s32 initialX, s16 initialY, f32 scaleX, f32 scaleY, s32 scaled) {
    void *resource;
    u8 intensity;
    TextureTileGrid *grid;
    gDPPipeSync(g_displayListCursor++);
    if(handle != NULL) {
        func_802AA8EC_de(handle,index,&resource,&intensity);
        grid=resource;
        if(grid != NULL) {
            if(intensity != 0) {
                if(scaled != 0) {
                    TextureTileGrid *branchGrid=grid;
                    TextureTileBlock *tile;
                    u32 width, height;
                    f32 x, y, column, row, startX;
                    y=(f32)initialY;
                    tile=(TextureTileBlock *)branchGrid->blocks;
                    height=0;
                    row=(f32)branchGrid->rows;
                    startX=(f32)(s16)initialX;
                    while(row-- != 0.0f) {
                        column=(f32)branchGrid->columns;
                        x=startX;
                        while(column-- != 0.0f) {
                            height=tile->height;
                            width=tile->width;
                            func_802A9EE8_de(tile->pixels,x,y,width,height,scaleX,scaleY);
                            x+=(f32)width*scaleX;
                            tile=(TextureTileBlock *)((u8 *)tile+((width*height>>1)));
                            tile++;
                        }
                        y+=(f32)height*scaleY;
                    }
                }
                else {
                    TextureTileGrid *branchGrid=grid;
                    TextureTileBlock *tile;
                    u32 width,height;
                    s32 x,column,row;
                    s16 y;
                    y=initialY;
                    tile=(TextureTileBlock *)branchGrid->blocks;
                    height=0;
                    row=branchGrid->rows;
                    row--;
                    while(row != -1) {
                        column=branchGrid->columns;
                        column--;
                        x=(s16)initialX;
                        while(column != -1) {
                            width=tile->width;
                            height=tile->height;
                            func_802A9CD0_de(tile->pixels,x,y,width,height);
                            x+=width;
                            tile=(TextureTileBlock *)((u8 *)tile+((width*height>>1)));
                            tile++;
                            --column;
                        }
                        y=(s16)(y+height);
                        --row;
                    }
                }
            }
            else {
                if(scaled != 0) {
                    TextureTileGrid *branchGrid=grid;
                    TextureTileBlock *tile;
                    u32 width, height;
                    f32 x, y, column, row, startX;
                    y=(f32)initialY;
                    tile=(TextureTileBlock *)branchGrid->blocks;
                    height=0;
                    row=(f32)branchGrid->rows;
                    startX=(f32)(s16)initialX;
                    while(row-- != 0.0f) {
                        column=(f32)branchGrid->columns;
                        x=startX;
                        while(column-- != 0.0f) {
                            height=tile->height;
                            width=tile->width;
                            OnScreen_DrawScaledMaskedImage(tile->pixels,tile->pixels+width*height*2,x,y,width,height,scaleX,scaleY);
                            x+=(f32)width*scaleX;
                            tile=(TextureTileBlock *)((u8 *)tile+(width*height*2+(width*height>>1)));
                            tile++;
                        }
                        y+=(f32)height*scaleY;
                    }
                }
                else {
                    TextureTileGrid *branchGrid=grid;
                    TextureTileBlock *tile;
                    u32 width,height;
                    s32 x,column,row;
                    s16 y;
                    y=initialY;
                    tile=(TextureTileBlock *)branchGrid->blocks;
                    height=0;
                    row=branchGrid->rows;
                    row--;
                    while(row != -1) {
                        column=branchGrid->columns;
                        column--;
                        x=(s16)initialX;
                        while(column != -1) {
                            width=tile->width;
                            height=tile->height;
                            func_802A9364_de(tile->pixels,tile->pixels+width*height*2,x,y,width,height);
                            x+=width;
                            tile=(TextureTileBlock *)((u8 *)tile+(width*height*2+(width*height>>1)));
                            tile++;
                            --column;
                        }
                        y=(s16)(y+height);
                        --row;
                    }
                }
            }
            Cache_MarkResourceInUse(0,handle);
        }
    }
}
#endif
