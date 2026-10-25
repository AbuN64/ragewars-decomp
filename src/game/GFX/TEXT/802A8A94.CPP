#include "COMMON/OBJECTLINKSC_2.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "GFX/802A8A94.H"
#include "TYPES.H"
#include "abi.h"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/WORLD.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "GFX/TEXT/802A8A94_5.H"
#include "SCENE/802508E0_9.H"

extern s32 D_800E28D0;


static inline void rectangle(s32 x0,s32 y0,s32 x1,s32 y1,s32 r,s32 g,s32 b,s32 a) {
    gDPPipeSync(D_80110634++);
    gDPSetPrimColor(D_80110634++,255,255,r,g,b,a);
    gDPFillRectangle(D_80110634++, x0>0?x0:0,y0>0?y0:0,x1>0?x1:0,y1>0?y1:0);
}

/* Draws a signed integer of up to four digits with the font sprite set from Render_StartWorldEffect: splits the magnitude into thousands, hundreds, tens and ones, draws a leading minus sign through func_802AAC28_de when negative, then draws at least minDigits digits through Text_DrawTileGrid, advancing 13 units per digit (0.7 of that for a one) scaled by the size, laid out right to left when rightAlign is set, and releases the sprite set. */



extern s32 Render_StartWorldEffect(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern void Text_DrawTileGrid(s32 arg0, s32 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, s32 arg6);


extern Gfx *D_80110634;


#include "GFX/TEXT/802A8A94_6.H"

extern void func_80268CE0_de(s32 arg0);

extern s32 Render_SetModePreset(s32);

void func_802A7AA4_de(Mover *m) {
    s32 next;
    f32 dx;
    f32 dy;
    s32 bottom;
    s32 right;

    bottom = D_800E28D4 + 0x60;
    right = D_800E28D0 + 0x60;
    do {
        next = 0;
        switch (m->state) {
        case 0:
        case 1:
            break;
        case 2:
            if (m->script != 0) {
                switch (*m->script++) {
                case 6:
                    m->state = 0;
                    m->script = 0;
                    break;
                case 1:
                    next = 1;
                    m->x = *m->script++;
                    m->y = *m->script++;
                    break;
                case 2:
                    m->state = 3;
                    m->wait = *m->script++;
                    break;
                case 3:
                    m->active = 1;
                    m->state = 4;
                    m->targetX = *m->script++;
                    m->targetY = *m->script++;
                    m->rate = 1.0f / *m->script++;
                    break;
                case 4:
                    m->active = 1;
                    m->state = 5;
                    m->velY = 0.0f;
                    m->accelY = *m->script++ * (1.0f / 65536.0f);
                    break;
                case 5:
                    m->active = 1;
                    m->state = 6;
                    m->velX = 0.0f;
                    m->accelX = *m->script++ * (1.0f / 65536.0f);
                    break;
                default:
                    m->state = 1;
                    m->script = 0;
                    break;
                }
            } else {
                m->state = 1;
            }
            break;
        case 3:
            if (m->wait-- <= 0) {
                next = 1;
            }
            break;
        case 4:
            dx = (m->targetX - m->x) * m->rate;
            dy = (m->targetY - m->y) * m->rate;
            m->x += dx;
            m->y += dy;
            if ((dx < 0.0f ? -dx < 0.25f : dx < 0.25f) && (dy < 0.0f ? -dy < 0.25f : dy < 0.25f)) {
                m->x = m->targetX;
                m->y = m->targetY;
                next = 1;
            }
            break;
        case 5:
            m->y += m->velY;
            m->velY += m->accelY;
            if ((f32)bottom < m->y || m->y < -90.0f) {
                m->active = 0;
                next = 1;
            }
            break;
        case 6:
            m->x += m->velX;
            m->velX += m->accelX;
            if ((f32)right < m->x || m->x < -90.0f) {
                m->active = 0;
                next = 1;
            }
            break;
        }
        if (next) {
            m->state = 2;
        }
    } while (next);
}

void func_802A7DE4_de(s32 x0,s32 y0,s32 x1,s32 y1,s32 border,s32 invert,s32 red,s32 green,s32 blue,s32 alpha) {
    u8 r=red,g=green,b=blue,a=alpha;
    s32 lightR,lightG,lightB,darkR,darkG,darkB;
    lightR=invert ? r>>1 : r<<1;
    lightG=invert ? g>>1 : g<<1;
    lightB=invert ? b>>1 : b<<1;
    darkR=invert ? r<<1 : r>>1;
    darkG=invert ? g<<1 : g>>1;
    darkB=invert ? b<<1 : b>>1;
    rectangle(x0,y0,x1,y1,r,g,b,a);
    rectangle(x0,y0,x1,y0+border,lightR,lightG,lightB,a);
    rectangle(x1-border,y0,x1,y1,lightR,lightG,lightB,a);
    rectangle(x0,y1-border,x1,y1,darkR,darkG,darkB,a);
    rectangle(x0,y0,x0+border,y1,darkR,darkG,darkB,a);
}

void func_802A822C_de(s32 value, f32 x, f32 y, f32 size, f32 scaleY, s32 arg5, s32 rightAlign, s32 minDigits) {
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

    sprites = Render_StartWorldEffect(&D_8011FE88, 4, 0x10, 1);
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
        func_802AAC28_de(4, 10, x, y, size, scaleY, arg5);
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
            Text_DrawTileGrid(sprites, digit, x, y, size, scaleY, arg5);
        }
        if (!rightAlign) {
            x += width;
        }
    }
release:
    Scene_UnlockResource(0, (struct Node80253610 *)sprites);
}

void func_802A84F8_de(void) {
    u8 *texture;

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
        Render_SetModePreset(0x15);

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
        gDPSetTextureImage(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 1, texture);
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
        D_801376F8.shadowX = 2;
        D_801376F8.shadowY = 2;
    }
}

void func_802A8710_de(void) {
    Gfx *cmd;
    u8 *v0;

    v0 = func_802AADBC_de();
    if (v0 != 0) {
        D_80147150 = 1;
        cmd = D_80110634++;
        gDPSetTextureImage(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 1, v0);
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

void func_802A8800_de(void) {
    Gfx *cmd;
    u8 *v0;

    v0 = func_802AADBC_de();
    if (v0 != 0) {
        D_80147150 = 2;
        cmd = D_80110634++;
        gDPSetTextureImage(cmd, G_IM_FMT_I, G_IM_SIZ_16b, 1, v0);
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
