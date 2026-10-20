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
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
void func_802A9734_de(void *pTexture, void *pOpacity, float XPos, float YPos, int TextureWidth, int TextureHeight, float ScaleX, float ScaleY);
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x48, 0x4c, 0x58, 0x5c, 0x68, 0x6c, 0x78, 0x7c, 0x88, 0x8c], gap at: 0x3c. */
void func_802AAEE4_de(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs3;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 var_fs0;
    f32 var_fs0f;
    f32 var_fs1;
    f32 var_fs1f;
    f32 var_fv1f;
    f64 temp_fs2;
    f64 var_fv0;
    f64 var_fv0_2;
    s32 temp_s0;
    s32 temp_s1;
    s32 var_s4;
    u32 temp_lo;
    void *var_s2;

    var_fs1f = arg2;
    var_s2 = arg0 + 8;
    var_s4 = 0;
    var_fv1f = D_800C622C_de;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fs1 = (f32) *((u16 *) ((u8 *) (arg0) + 2));
    var_fs1 = temp_fs1 - var_fv1f;
    if (temp_fs1 != 0.0f) {
        temp_fs2 = D_800C6230_de;
        do {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            temp_fs0 = (f32) *((u16 *) ((u8 *) (arg0) + 0));
            var_fs0 = temp_fs0 - var_fv1f;
            var_fs0f = arg1;
            if (temp_fs0 != 0.0f) {
                temp_fs3 = D_800C6238_de;
                do {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    var_s4 = *((s32 *) ((u8 *) (var_s2) + 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    temp_s0 = *((s32 *) ((u8 *) (var_s2) + 0));
                    temp_lo = temp_s0 * var_s4;
                    temp_s1 = temp_lo * 2;
                    func_802A9734_de(var_s2 + 8, var_s2 + (temp_s1 + 8), var_fs0f, var_fs1f, temp_s0, var_s4, arg3, arg4);
                    var_fv0 = (f64) temp_s0;
                    if (temp_s0 < 0) {
                        var_fv0 += temp_fs2;
                    }
                    temp_fv0f_2 = var_fs0;
                    var_fs0 -= temp_fs3;
                    var_s2 = var_s2 + (temp_s1 + (temp_lo >> 1)) + 8;
                    var_fs0f += (f32) var_fv0 * arg3;
                } while (temp_fv0f_2 != 0.0f);
            }
            var_fv0_2 = (f64) var_s4;
            if (var_s4 < 0) {
                var_fv0_2 += temp_fs2;
            }
            var_fv1f = D_800C623C_de;
            temp_fv0f = var_fs1;
            var_fs1 -= var_fv1f;
            var_fs1f += (f32) var_fv0_2 * arg4;
        } while (temp_fv0f != 0.0f);
    }
}
#else
INCLUDE_ASM("span_1000", func_802AAEE4_de);
#endif
