#include "shared/world.h"
#include "gfx.h"
#include "span_1000/code_802A8A94.h"
#include "types.h"
#include "abi.h"
#include "n64sdk.h"
#include "gbi.h"

/* Draws a signed integer of up to four digits with the font sprite set from func_8028BEAC_de: splits the magnitude into thousands, hundreds, tens and ones, draws a leading minus sign through func_802AAC28_de when negative, then draws at least minDigits digits through func_802AA1AC_de, advancing 13 units per digit (0.7 of that for a one) scaled by the size, laid out right to left when rightAlign is set, and releases the sprite set. */



extern s32 func_8028BEAC_de(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_802AA1AC_de(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6);
extern s32 func_802AAC28_de(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6);
extern void func_80253754_de(s32 arg0, s32 arg1);

void func_802A822C_de(s32 value, f32 x, f32 y, f32 size, f32 arg4, s32 arg5, s32 rightAlign, s32 minDigits) {
    s32 sprites;
    s32 negative;
    s32 thousands;
    s32 hundreds;
    s32 tens;
    s32 ones;
    s32 rest;
    s32 last;
    s32 i;
    s32 place;
    s32 digit;
    f32 width;
    f32 scale;

    sprites = func_8028BEAC_de(&D_8011FE88, 4, 0x10, 1);
    if (sprites == 0) {
        return;
    }
    negative = 0;
    if (value < 0) {
        value = -value;
        negative = 1;
        if (value < 0) {
            goto release;
        }
    }
    thousands = value * 0.001f;
    rest = value - thousands * 1000;
    hundreds = rest * 0.01f;
    rest -= hundreds * 100;
    tens = rest * 0.1f;
    ones = rest - tens * 10;
    last = 3;
    if (thousands == 0) {
        last = 2;
        if (hundreds == 0) {
            last = tens != 0;
        }
    }
    if (last < minDigits - 1) {
        last = minDigits - 1;
    }
    if (negative) {
        func_802AAC28_de(4, 10, x, y, size, arg4, arg5);
        x += size * 13.0f;
    }
    for (i = last; i >= 0; i--) {
        place = i;
        if (rightAlign) {
            place = last - i;
        }
        switch (place) {
        case 3:
            digit = thousands;
            break;
        case 2:
            digit = hundreds;
            break;
        case 1:
            digit = tens;
            break;
        case 0:
        default:
            digit = ones;
            break;
        }
        scale = 1.0f;
        if (digit == 1) {
            scale = 0.7f;
        }
        width = scale * (size * 13.0f);
        if (rightAlign) {
            x -= width;
        }
        if ((u32)digit < 10) {
            func_802AA1AC_de(sprites, digit, x, y, size, arg4, arg5);
        }
        if (!rightAlign) {
            x += width;
        }
    }
release:
    func_80253754_de(0, sprites);
}

extern Gfx *D_80110634;
extern s32 D_801377B8[2];


extern s32 func_802AADBC_de(void);
extern void func_80268CE0_de(s32 arg0);
extern s32 func_8026925C_de(s32);




void func_802A84F8_de(void) {
    s32 texture;

    texture = func_802AADBC_de();
    if (texture != 0) {

        {
            Gfx *cmd;
            cmd = D_80110634++;
            gDPPipeSync(cmd);
            cmd = D_80110634++;
            gDPSetCycleType(cmd, G_CYC_2CYCLE);
        }

        func_80268CE0_de(0x1A);
        func_8026925C_de(0x15);

        D_80147150 = 0;
        {
        Gfx *cmd;
        cmd = D_80110634++;
        gSPTexture(cmd, 32768, 32768, 0, 0, G_ON);
        cmd = D_80110634++;
        gDPSetTextureLUT(cmd, G_TT_NONE);
        cmd = D_80110634++;
        gDPSetTexturePersp(cmd, G_TP_NONE);
        cmd = D_80110634++;
        gDPSetTextureFilter(cmd, G_TF_BILERP);
        cmd = D_80110634++;
        gDPSetTextureImage(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)texture);
        cmd = D_80110634++;
        gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0);
        cmd = D_80110634++;
        gDPLoadSync(cmd);
        cmd = D_80110634++;
        gDPLoadBlock(cmd, G_TX_LOADTILE, 0, 0, 143, 2048);
        cmd = D_80110634++;
        gDPPipeSync(cmd);
        cmd = D_80110634++;
        gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_4b, 2, 0, G_TX_RENDERTILE, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0);
        cmd = D_80110634++;
        gDPSetTileSize(cmd, G_TX_RENDERTILE, 0, 0, 92, 92);
        cmd = D_80110634++;
        gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_4b, 0, 0, 1, 0, G_TX_WRAP, 0, 0, G_TX_WRAP, 0, 0);
        cmd = D_80110634++;
        gDPSetTileSize(cmd, 1, 0, 0, 60, 60);
        }

        func_802AAB3C_de(0x8C, 0x8C, 0x8C, 0x8C, 0x8C, 0x8C);
        func_802AAB68_de(D_800C5FB0_de, D_800C5FB0_de);
        D_801377B8[0] = 2;
        D_801377B8[1] = 2;
    }
}

extern Gfx *D_80110634;

extern s32 func_802AADBC_de(void);

void func_802A8710_de(void) {
    Gfx *cmd;
    s32 v0;

    v0 = func_802AADBC_de();
    if (v0 != 0) {
        D_80147150 = 1;
        cmd = D_80110634++;
        gDPSetTextureImage(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32) v0);
        cmd = D_80110634++;
        gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 3, 0, G_TX_WRAP, 4, 0);
        cmd = D_80110634++;
        gDPLoadSync(cmd);
        cmd = D_80110634++;
        gDPLoadBlock(cmd, G_TX_LOADTILE, 0, 0, 31, 2048);
        cmd = D_80110634++;
        gDPPipeSync(cmd);
        cmd = D_80110634++;
        gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_4b, 1, 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 3, 0, G_TX_WRAP, 4, 0);
        cmd = D_80110634++;
        gDPSetTileSize(cmd, G_TX_RENDERTILE, 0, 0, 60, 28);
    }
}

extern Gfx *D_80110634;

extern s32 func_802AADBC_de(void);

void func_802A8800_de(void) {
    Gfx *cmd;
    s32 v0;

    v0 = func_802AADBC_de();
    if (v0 != 0) {
        D_80147150 = 2;
        cmd = D_80110634++;
        gDPSetTextureImage(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32) v0);
        cmd = D_80110634++;
        gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 0, 256, G_TX_LOADTILE, 0, G_TX_WRAP, 3, 0, G_TX_WRAP, 4, 0);
        cmd = D_80110634++;
        gDPLoadSync(cmd);
        cmd = D_80110634++;
        gDPLoadBlock(cmd, G_TX_LOADTILE, 0, 0, 31, 2048);
        cmd = D_80110634++;
        gDPPipeSync(cmd);
        cmd = D_80110634++;
        gDPSetTile(cmd, G_IM_FMT_I, G_IM_SIZ_4b, 1, 256, G_TX_RENDERTILE, 0, G_TX_WRAP, 3, 0, G_TX_WRAP, 4, 0);
        cmd = D_80110634++;
        gDPSetTileSize(cmd, G_TX_RENDERTILE, 0, 0, 60, 28);
    }
}
