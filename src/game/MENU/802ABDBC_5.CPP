#include "include_asm.h"
#include "COMMON/ENTRYRECATE.H"
#include "TYPES.H"
#include "MENU/802ABDBC_5.H"

/* Draws a grid of 16-bit image tiles with a 4-bit mask: the header holds the column and row counts,
   each tile holds its width, height, two bytes per pixel and then half a byte per pixel of mask,
   and every tile goes to func_802A9364_de at the running position, advancing x by the tile width and
   y by the last tile height per row. Adapted from func_802AB0B0_de with the mask pointer added. */

extern void func_802A9364_de(s32 *pixels, char *mask, s32 x, s16 y, s32 w, s32 h);

void func_802AADCC_de(u16 *grid, s16 x0, s32 y) {
    s32 *tile;
    s32 rows;
    s32 cols;
    s32 x;
    s32 w;
    s32 h;
    u32 area;

    tile = (s32 *)(grid + 4);
    h = 0;
    rows = grid[1];
    while (--rows != -1) {
        x = x0;
        cols = grid[0];
        while (--cols != -1) {
            w = tile[0];
            h = tile[1];
            area = w * h;
            func_802A9364_de(tile + 2, (char *)tile + (area * 2 + 8), x, y, w, h);
            x += w;
            tile = (s32 *)((char *)tile + (area * 2 + (area >> 1)));
            tile += 2;
        }
        y += h;
    }
}

#ifdef NON_MATCHING
void func_802A9734_de(void *pTexture, void *pOpacity, float XPos, float YPos, int TextureWidth, int TextureHeight, float ScaleX, float ScaleY);
/* 115/115 words; remaining: literal pool slot (the pool shares its first word with the tail of func_802AA864_de) */
void func_802AAEE4_de(u16 *grid, f32 x0, f32 y, f32 sx, f32 sy) {
    u32 *tile;
    f32 rows;
    f32 cols;
    f32 x;
    u32 w;
    u32 h;
    u32 area;

    tile = (u32 *)(grid + 4);
    h = 0;
    rows = grid[1];
    while (rows-- != 0.0f) {
        x = x0;
        cols = grid[0];
        while (cols-- != 0.0f) {
            w = tile[0];
            h = tile[1];
            area = w * h;
            func_802A9734_de(tile + 2, (char *)tile + (area * 2 + 8), x, y, w, h, sx, sy);
            x += w * sx;
            tile = (u32 *)((char *)tile + (area * 2 + (area >> 1)));
            tile += 2;
        }
        y += h * sy;
    }
}
#else
INCLUDE_ASM("span_1000", func_802AAEE4_de);
#endif
