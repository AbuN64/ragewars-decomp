#include "audio_callbacks.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "gfx.h"
#include "resident_event_handler.h"
#include "shared/gbi.h"
#include "span_1000/code_80291054.h"
#include "span_1000/code_802A8A94.h"
#include "span_C76B0/data.h"
#include "stddef.h"
#include "types.h"
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
