#include "COMMON/EXTERNS_9.H"
#include "COMMON/LONE/D_800CC384.H"
#include "RENDER_4/8026AC38.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "RENDER_3/RANGENODE.H"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"

/* Selects a cached RDP color-combiner mode and emits the corresponding display-list command. */
extern Gfx *g_displayListCursor;
void Render_SetCombineMode(u32 mode) {
 if (D_800CC360 != mode) {
 D_800CC360=mode;
 switch(mode) {
 case 0: gDPSetCombineLERP(g_displayListCursor++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, SHADE, 0, TEXEL0, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED); break;
 case 1: gDPSetCombineLERP(g_displayListCursor++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, SHADE, 0, TEXEL0, 0, 0, 0, 0, COMBINED, COMBINED, 0, ENVIRONMENT, 0); break;
 case 2: gDPSetCombineLERP(g_displayListCursor++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED); break;
 case 3: gDPSetCombineLERP(g_displayListCursor++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, SHADE, 0, TEXEL0, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED); break;
 case 4: gDPSetCombineLERP(g_displayListCursor++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED); break;
 case 5: gDPSetCombineLERP(g_displayListCursor++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 0, 0, 0, COMBINED, 0, 0, 0, SHADE); break;
 case 6: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED); break;
 case 7: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, COMBINED, 0, ENVIRONMENT, 0); break;
 case 8: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, ENVIRONMENT, COMBINED, ENV_ALPHA, COMBINED, 0, 0, 0, COMBINED); break;
 case 9: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, ENVIRONMENT, COMBINED, SHADE, COMBINED, 0, 0, 0, COMBINED); break;
 case 10: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, ENVIRONMENT, COMBINED, 0, ENVIRONMENT, 0); break;
 case 11: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, ENVIRONMENT, COMBINED, ENV_ALPHA, COMBINED, COMBINED, 0, PRIMITIVE, 0); break;
 case 12: gDPSetCombineLERP(g_displayListCursor++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE); break;
 case 13: gDPSetCombineLERP(g_displayListCursor++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED); break;
 case 14: gDPSetCombineLERP(g_displayListCursor++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, COMBINED, 0, ENVIRONMENT, 0); break;
 case 15: gDPSetCombineLERP(g_displayListCursor++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, ENVIRONMENT, COMBINED, ENV_ALPHA, COMBINED, 0, 0, 0, COMBINED); break;
 case 16: gDPSetCombineLERP(g_displayListCursor++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, ENVIRONMENT, COMBINED, 0, ENVIRONMENT, 0); break;
 case 17: gDPSetCombineLERP(g_displayListCursor++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, ENVIRONMENT, COMBINED, ENV_ALPHA, COMBINED, COMBINED, 0, PRIMITIVE, 0); break;
 case 18: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED); break;
 case 19: gDPSetCombineLERP(g_displayListCursor++, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, PRIMITIVE, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED); break;
 case 20: gDPSetCombineLERP(g_displayListCursor++, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, PRIMITIVE, 0, 0, 0, COMBINED, COMBINED, 0, ENVIRONMENT, 0); break;
 case 21: gDPSetCombineLERP(g_displayListCursor++, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, PRIMITIVE, ENVIRONMENT, COMBINED, ENV_ALPHA, COMBINED, 0, 0, 0, COMBINED); break;
 case 22: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, ENVIRONMENT, COMBINED, SHADE, COMBINED, 0, 0, 0, COMBINED); break;
 case 23: gDPSetCombineLERP(g_displayListCursor++, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, PRIMITIVE, 0, 0, 0, ENVIRONMENT, COMBINED, 0, ENVIRONMENT, 0); break;
 case 24: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0); break;
 case 25: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE); break;
 case 26: gDPSetCombineLERP(g_displayListCursor++, ENVIRONMENT, PRIMITIVE, TEXEL1, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED); break;
 case 27: gDPSetCombineLERP(g_displayListCursor++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL1, 0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED); break;
 case 28: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE); break;
 case 29: gDPSetCombineLERP(g_displayListCursor++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0); break;
 case 30: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, PRIMITIVE, 0, 0, 0, 1, 0, 0, 0, PRIMITIVE, 0, 0, 0, 1);
 /* Mode 30 deliberately falls through and emits the mode 31 packet too. */
 case 31: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, 1, 0, 0, 0, ENVIRONMENT, 0, 0, 0, 1); break;
 case 32: gDPSetCombineLERP(g_displayListCursor++, ENVIRONMENT, SHADE, TEXEL0, SHADE, SHADE, 0, TEXEL0, 0, ENVIRONMENT, SHADE, TEXEL0, SHADE, SHADE, 0, TEXEL0, 0); break;
 case 33: gDPSetCombineLERP(g_displayListCursor++, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE); break;
 case 34: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, 0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED); break;
 case 35: gDPSetCombineLERP(g_displayListCursor++, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 0, 0, 0, PRIMITIVE, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED); break;
 case 36: gDPSetCombineLERP(g_displayListCursor++, PRIMITIVE, 0, SHADE, 0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, COMBINED, ENVIRONMENT, COMBINED_ALPHA, ENVIRONMENT, 0, 0, 0, PRIMITIVE); break;
 case 37: gDPSetCombineLERP(g_displayListCursor++, ENVIRONMENT, 0, SHADE, 0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, PRIMITIVE, COMBINED, COMBINED_ALPHA, COMBINED, 0, 0, 0, PRIMITIVE); break;
 case 38: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, 1, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED); break;
 case 39: gDPSetCombineLERP(g_displayListCursor++, 0, 0, 0, 1, TEXEL0, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED); break;
 case 40: gDPSetCombineLERP(g_displayListCursor++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0); break;
 case 41: gDPSetCombineLERP(g_displayListCursor++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, SHADE, 0, TEXEL0, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, SHADE, 0, TEXEL0, 0); break;
 }
 }
}


extern s32 D_800CC364;



extern Gfx *g_displayListCursor;

s32 Render_SetModePreset(s32 tailEnum) {

    if (D_800CC364 == tailEnum) {
        return 0;
    }
    D_800CC364 = tailEnum;

    {
        if ((u32)tailEnum > 30) {
            goto sw_mode_default;
        }
        switch (tailEnum) {
        case 0: goto sw_mode_0;
        case 1: goto sw_mode_1;
        case 2: goto sw_mode_2;
        case 3: goto sw_mode_3;
        case 4: goto sw_mode_4;
        case 5: goto sw_mode_5;
        case 6: goto sw_mode_6;
        case 7: goto sw_mode_7;
        case 8: goto sw_mode_8;
        case 9: goto sw_mode_9;
        case 10: goto sw_mode_10;
        case 11: goto sw_mode_11;
        case 12: goto sw_mode_12;
        case 13: goto sw_mode_13;
        case 14: goto sw_mode_14;
        case 15: goto sw_mode_15;
        case 16: goto sw_mode_16;
        case 17: goto sw_mode_17;
        case 18: goto sw_mode_18;
        case 19: goto sw_mode_19;
        case 20: goto sw_mode_20;
        case 21: goto sw_mode_21;
        case 22: goto sw_mode_22;
        case 23: goto sw_mode_23;
        case 24: goto sw_mode_24;
        case 25: goto sw_mode_25;
        case 26: goto sw_mode_26;
        case 27: goto sw_mode_27;
        case 28: goto sw_mode_28;
        case 29: goto sw_mode_29;
        case 30: goto sw_mode_30;
        }
    }
    switch (tailEnum) {
    case 0: sw_mode_0: {
        if (D_800CC370) gDPSetRenderMode(g_displayListCursor++, 0x0C1849D8, 0) else gDPSetRenderMode(g_displayListCursor++, 0x0C184A50, 0);
        break;
    }
    case 1: sw_mode_1: {
        if (D_800CC370) gDPSetRenderMode(g_displayListCursor++, D_800CC38C, 0x001049D8) else gDPSetRenderMode(g_displayListCursor++, D_800CC38C, 0x00104A50);
        break;
    }
    case 2: sw_mode_2: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, 0x0C184A50, 0);
        break;
    }
    case 3: sw_mode_3: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, 0x0C184B50, 0);
        break;
    }
    case 4: sw_mode_4: {
        if (D_800CC370) gDPSetRenderMode(g_displayListCursor++, D_800CC38C, 0x00104DD8) else gDPSetRenderMode(g_displayListCursor++, D_800CC38C, 0x00104E50);
        break;
    }
    case 5: sw_mode_5: {
        if (D_800CC370) gDPSetRenderMode(g_displayListCursor++, D_800CC38C, 0x001041F8) else gDPSetRenderMode(g_displayListCursor++, D_800CC38C, 0x001041F0);
        break;
    }
    case 6: sw_mode_6: {
        if (D_800CC370) gDPSetRenderMode(g_displayListCursor++, D_800CC38C, 0x00113078) else gDPSetRenderMode(g_displayListCursor++, D_800CC38C, 0x00113078);
        break;
    }
    case 7: sw_mode_7: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, D_800CC38C, 0x00112E10);
        break;
    }
    case 8: sw_mode_8: {
        if (D_800CC370) gDPSetRenderMode(g_displayListCursor++, D_800CC38C, 0x00112478) else gDPSetRenderMode(g_displayListCursor++, D_800CC38C, 0x00112478);
        break;
    }
    case 9: sw_mode_9: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, D_800CC38C, 0x00112438);
        break;
    }
    case 10: sw_mode_10: {
        if (D_800CC370) gDPSetRenderMode(g_displayListCursor++, D_800CC38C, 0x00112078) else gDPSetRenderMode(g_displayListCursor++, D_800CC38C, 0x00112230);
        break;
    }
    case 11: sw_mode_11: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, D_800CC38C, 0x00112038);
        break;
    }
    case 12: sw_mode_12: {
        if (D_800CC370) gDPSetRenderMode(g_displayListCursor++, 0x005045D8, 0) else gDPSetRenderMode(g_displayListCursor++, 0x004045D0, 0);
        break;
    }
    case 13: sw_mode_13: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, 0x00504B50, 0);
        break;
    }
    case 14: sw_mode_14: {
        if (D_800CC370) gDPSetRenderMode(g_displayListCursor++, 0x005049D8, 0) else gDPSetRenderMode(g_displayListCursor++, 0x00504A50, 0);
        break;
    }
    case 15: sw_mode_15: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, 0x00504E50, 0);
        break;
    }
    case 16: sw_mode_16: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, 0x00504B53, 0);
        break;
    }
    case 17: sw_mode_17: {
        if (D_800CC370) gDPSetRenderMode(g_displayListCursor++, 0x00553078, 0) else gDPSetRenderMode(g_displayListCursor++, 0x00553078, 0);
        break;
    }
    case 18: sw_mode_18: {
        if (D_800CC370) gDPSetRenderMode(g_displayListCursor++, 0x00553048, 0) else gDPSetRenderMode(g_displayListCursor++, 0x0F0A7008, 0);
        break;
    }
    case 19: sw_mode_19: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, 0x00504340, 0);
        break;
    }
    case 20: sw_mode_20: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, 0, 0);
        break;
    }
    case 21: sw_mode_21: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, 0x00504240, 0);
        break;
    }
    case 22: sw_mode_22: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, 0x0FA54040, 0);
        break;
    }
    case 23: sw_mode_23: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, D_800CC38C, 0x00104B50);
        break;
    }
    case 24: sw_mode_24: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, D_800CC38C, 0x00104E50);
        break;
    }
    case 25: sw_mode_25: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, 0x0C184240, 0);
        break;
    }
    case 26: sw_mode_26: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, 0x0C184340, 0);
        break;
    }
    case 27: sw_mode_27: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, 0x0F0A4000, 0);
        break;
    }
    case 28: sw_mode_28: {
        if (D_800CC370) gDPSetRenderMode(g_displayListCursor++, 0x00507048, 0) else gDPSetRenderMode(g_displayListCursor++, 0x00507040, 0);
        break;
    }
    case 29: sw_mode_29: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, D_800CC38C, 0x00104F50);
        break;
    }
    case 30: sw_mode_30: {
        Gfx *gfx = g_displayListCursor++;
        gDPSetRenderMode(gfx, D_800CC388, 0x00104F50);
        break;
    }
    }
sw_mode_default:
    return 1;
}

extern Gfx *g_displayListCursor;
extern Gfx D_800CC018_de[], D_800CC0A0[];
extern s32 D_800CC364;
extern void System_ResetTextureCache(void);
/* Emits a 16 by 16 intensity texture, white tint, matrix and the selected pass list. */
void func_8026992C_de(void *matrix, s32 pass, u32 alpha) {
    Gfx *list;
    gDPSetTextureImage(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_16b, 1, D_800D14B0);
    gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    gDPLoadSync(g_displayListCursor++);
    gDPLoadBlock(g_displayListCursor++, G_TX_LOADTILE, 0, 0, 127, 1024);
    gDPPipeSync(g_displayListCursor++);
    gDPSetTile(g_displayListCursor++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    gDPSetTileSize(g_displayListCursor++, G_TX_RENDERTILE, 0, 0, 15 << 2, 15 << 2);
    gDPSetPrimColor(g_displayListCursor++, 0, 0, 255, 255, 255, alpha);
    gSPMatrix(g_displayListCursor++, matrix, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    list = D_800CC018_de;
    gSPDisplayList(g_displayListCursor++, ({ if (pass != 0) list = D_800CC0A0; list; }));
    D_800CC364 = -1;
    D_800CC360 = -1;
    System_ResetTextureCache();
}


struct Shared_AnimFrame {
    u8 kind;
    u8 unknown1;
    u8 shiftS;
    u8 shiftT;
    u8 unk4;
    u8 unk5;
};
struct Shared_AnimInfo {
    s32 count;
    s32 unk4;
    struct Shared_AnimFrame *frame;
};
struct Shared_GfxMaterial {
    u32 flags;
    u8 pad4[3];
    u8 unk7;
    s32 unk8;
    u8 padC[4];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u16 unk18;
    u16 unk1A;
};

extern Gfx *g_displayListCursor;
extern s32 D_80110620;
extern u32 D_800CD730;
extern s32 D_800CC378;
extern s32 D_800CC37C;
extern u8 D_800CC3A8;
extern u8 D_800CC3A9;
extern u8 D_800CC3AA;
extern u8 D_800CC3AB;
extern u8 D_800CC3AC;
extern u8 D_800CC3AD;

void *func_80295F14_de(s32 *, s32);
void func_80295F78_de(void *, struct Shared_AnimInfo *);
#if defined(VERSION_US_REV1)
void func_80295FB4_us_rev1(s32 *, void *, s32, s32, s32, s32, s32, s32, s32);
#else
void func_802950B4_de(s32 *, void *, s32, s32, s32, s32, s32, s32, s32);
#endif
void Render_SetCombineMode(u32);
s32 Render_SetModePreset(s32);
void Scene_UnlockResource(s32, void *);
s32 Nav_NextRandom(void);

s32 Render_SetupMaterial(struct Shared_GfxMaterial *mat, s32 pass) {
    struct Shared_AnimInfo info;
    void *node;
    u32 flags;
    s32 tailEnum;
    s32 a;
    s32 b;
    s32 idx;
    u32 maskS;
    u32 maskT;
    u32 extra;
    u32 extra2;
    u32 mode;

    flags = mat->flags;
    if (D_80110620 != 0 && (flags & 0x8040) != 0x8000) {
        flags |= 2;
    }
    if ((flags & 0x100) && mat->unk13 == 0) {
        return 0;
    }
    tailEnum = -1;
    if (mat->unk8 != 0 && !(D_801462C8.flags & 0x400) && !(D_80110620 != 0 && (flags & 0x8000))) {
        node = func_80295F14_de(&mat->unk8, pass);
        if (node == 0) {
            return 0;
        }
        func_80295F78_de(node, &info);
        switch (pass) {
            case -2:
                if (info.count < 2) {
                    a = 0;
                    b = 0;
                    break;
                }
                idx = (u8)(D_800CD730 / info.frame->unknown1);
                if (mat->unk7 != idx) {
a = Nav_NextRandom() % info.count;
 if (info.unk4 != 0) { b = a; if (b >= info.unk4) { b = 0; } } else { b = 0; }
                    mat->unk7 = idx;
                } else {
                    a = idx % info.count;
                    b = info.unk4 ? idx % info.unk4 : 0;
                }
                break;
            case -1:
                idx = D_800CD730 / info.frame->unknown1;
                a = idx % info.count;
                b = (info.unk4 == 0) ? 0 : idx % info.unk4;
                break;
            default:
                a = pass % info.count;
                if (info.unk4 != 0) {
                    b = pass % info.unk4;
                } else {
                    b = 0;
                }
                break;
        }
        if (flags & 0x10) {
            maskS = 1 << (info.frame->shiftS + 6);
            maskT = 1 << (info.frame->shiftT + 6);
        } else {
            maskS = mat->unk18;
            maskT = mat->unk1A;
        }
        if (flags & 0x20) {
            extra = G_TX_CLAMP;
            extra2 = G_TX_CLAMP;
        } else {
            extra = G_TX_WRAP;
            extra2 = G_TX_WRAP;
        }
        if (flags & 0x800) {
            extra |= G_TX_MIRROR;
            extra2 |= G_TX_MIRROR;
        }
#if defined(VERSION_US_REV1)
        func_80295FB4_us_rev1(&mat->unk8, node, a, b, maskS, maskT, extra, extra2, 0);
    #else
        func_802950B4_de(&mat->unk8, node, a, b, maskS, maskT, extra, extra2, 0);
    #endif
        if (flags & 0x2000) {
            gDPSetTextureLOD(g_displayListCursor++, G_TL_LOD);
        }
        if (D_80110620 != 0) {
            u32 avg = (u32)(mat->unk10 + mat->unk11 + mat->unk12) / 3;
            gDPSetPrimColor(g_displayListCursor++, info.frame->unk4, 0, 0, 0, avg, mat->unk13);
        } else {
            gDPSetPrimColor(g_displayListCursor++, info.frame->unk4, 0, mat->unk10, mat->unk11, mat->unk12, mat->unk13);
        }
        if (flags & 0x400) {
            if (D_80110620 != 0) {
                u32 avg = (u32)(mat->unk14 + mat->unk15 + mat->unk16) / 3;
                gDPSetEnvColor(g_displayListCursor++, 0, 0, avg, D_800D15E0 == 0 ? mat->unk13 : D_800D15E4[3]);
            } else {
                gDPSetEnvColor(g_displayListCursor++, mat->unk14, mat->unk15, mat->unk16, D_800D15E0 == 0 ? mat->unk13 : D_800D15E4[3]);
            }
            if (flags & 2) {
                if (!(flags & 0x1000)) {
                    Render_SetCombineMode(2);
                } else if (D_800D15E0 == 0) {
                    Render_SetCombineMode(0);
                } else {
                    Render_SetCombineMode(1);
                }
            } else if (!(flags & 0x1000)) {
                Render_SetCombineMode(4);
            } else {
                Render_SetCombineMode(3);
            }
            Scene_UnlockResource(0, node);
        } else if (flags & 2) {
            if (flags & 0x2000) {
                switch (info.frame->unk5) {
                    case 4:
                    case 5:
                        gDPSetEnvColor(g_displayListCursor++, mat->unk14, mat->unk15, mat->unk16, mat->unk17);
                        Render_SetCombineMode(0x23);
                        break;
                    default:
                        Render_SetCombineMode(5);
                        break;
                }
            } else if (D_800D15E0 == 0) {
                Render_SetCombineMode(6);
            } else {
                gDPSetEnvColor(g_displayListCursor++, D_800D15E4[0], D_800D15E4[1], D_800D15E4[2], D_800D15E4[3]);
                switch (D_800D15E0) {
                    case 1:
                    case 2:
                        Render_SetCombineMode(7);
                        break;
                    case 3:
                        Render_SetCombineMode(8);
                        break;
                    case 7:
                        Render_SetCombineMode(9);
                        break;
                    case 4:
                    case 5:
                        Render_SetCombineMode(10);
                        break;
                    case 6:
                        gDPSetPrimColor(g_displayListCursor++, 0, 0, mat->unk10, mat->unk11, mat->unk12, D_800D15E4[4]);
                        Render_SetCombineMode(0xB);
                        break;
                    default:
                        break;
                }
            }
            Scene_UnlockResource(0, node);
        } else {
            if (flags & 0x2000) {
                switch (info.frame->unk5) {
                    case 4:
                        gDPSetEnvColor(g_displayListCursor++, mat->unk14, mat->unk15, mat->unk16, mat->unk17);
                        Render_SetCombineMode(0x25);
                        break;
                    case 5:
                        gDPSetEnvColor(g_displayListCursor++, mat->unk14, mat->unk15, mat->unk16, mat->unk17);
                        Render_SetCombineMode(0x24);
                        break;
                    default:
                        Render_SetCombineMode(0xC);
                        break;
                }
            } else if (D_800D15E0 == 0) {
                Render_SetCombineMode(0xD);
            } else {
                gDPSetEnvColor(g_displayListCursor++, D_800D15E4[0], D_800D15E4[1], D_800D15E4[2], D_800D15E4[3]);
                switch (D_800D15E0) {
                    case 1:
                    case 2:
                        Render_SetCombineMode(0xE);
                        break;
                    case 3:
                        Render_SetCombineMode(0xF);
                        break;
                    case 7:
                        Render_SetCombineMode(9);
                        break;
                    case 4:
                    case 5:
                        Render_SetCombineMode(0x10);
                        break;
                    case 6:
                        gDPSetPrimColor(g_displayListCursor++, 0, 0, mat->unk10, mat->unk11, mat->unk12, D_800D15E4[4]);
                        Render_SetCombineMode(0x11);
                        break;
                    default:
                        break;
                }
            }
            Scene_UnlockResource(0, node);
        }
    } else {
        gDPPipeSync(g_displayListCursor++);
        if (D_800CC3A8 != 0) {
            if (D_800CC3AC != 0) {
                gDPSetPrimColor(g_displayListCursor++, 0, 0, D_800CC3A9, D_800CC3AA, D_800CC3AB, D_800CC3AD);
            } else {
                gDPSetPrimColor(g_displayListCursor++, 0, 0, D_800CC3A9, D_800CC3AA, D_800CC3AB, mat->unk13);
            }
        } else if (D_800CC3AC != 0) {
            gDPSetPrimColor(g_displayListCursor++, 0, 0, mat->unk10, mat->unk11, mat->unk12, D_800CC3AD);
        } else if (flags & 0x8000) {
            if (flags & 0x40) {
                gDPSetPrimColor(g_displayListCursor++, 0, 0, 255, 0, 0, mat->unk13);
            } else {
                gDPSetPrimColor(g_displayListCursor++, 0, 0, 255, 255, 0, mat->unk13);
            }
        } else {
            gDPSetPrimColor(g_displayListCursor++, 0, 0, mat->unk10, mat->unk11, mat->unk12, mat->unk13);
        }
        gSPTexture(g_displayListCursor++, 0, 0, 0, 0, 0);
        if (flags & 2) {
            Render_SetCombineMode(0x12);
        } else if (D_800D15E0 == 0) {
            Render_SetCombineMode(0x13);
        } else {
            gDPSetEnvColor(g_displayListCursor++, D_800D15E4[0], D_800D15E4[1], D_800D15E4[2], D_800D15E4[3]);
            switch (D_800D15E0) {
                case 1:
                case 2:
                    Render_SetCombineMode(0x14);
                    break;
                case 3:
                    Render_SetCombineMode(0x15);
                    break;
                case 7:
                    Render_SetCombineMode(0x16);
                    break;
                case 4:
                case 5:
                    Render_SetCombineMode(0x17);
                    break;
                case 6:
                    gDPSetPrimColor(g_displayListCursor++, 0, 0, mat->unk10, mat->unk11, mat->unk12, D_800D15E4[4]);
                    Render_SetCombineMode(0x11);
                    break;
                default:
                    break;
            }
        }
    }
    if ((flags & 0x100) || D_800D15E0 == 1 || D_800D15E0 == 4 || D_800D15E0 == 6) {
        if (D_800D15E0 == 0) {
            tailEnum = 3;
            if (!(flags & 0x1000)) {
                tailEnum = 1;
                if (flags & 0x200) {
                    tailEnum = 4;
                }
            }
        } else {
            tailEnum = 5;
            if (flags & 0x1000) {
                tailEnum = 3;
            }
        }
    } else if (flags & 0x80) {
        Render_SetModePreset(6);
    } else {
        tailEnum = 7;
        if (!(flags & 0x200)) {
            if (D_800CC378 != 0) {
                tailEnum = 9;
                if (D_800CC37C != 0) {
                    tailEnum = 8;
                }
            } else {
                tailEnum = 0xB;
                if (D_800CC37C != 0) {
                    tailEnum = 10;
                }
            }
        }
    }
    if (tailEnum != -1) {
        Render_SetModePreset(tailEnum);
    }
    mode = 0x260404;
    if (flags & 0x1000) {
        mode |= D_800CC384;
    }
    gSPGeometryMode(g_displayListCursor++, mode, 0);
    mode = 0;
    if (!(flags & 0x1000)) {
        mode = D_800CC384;
    }
    if (D_800D15E0 == 7) {
        mode |= 0x20000;
    }
    if (!(flags & 0x42)) {
        mode |= 0x20000;
    }
    mode |= 0x200004;
    if (!(flags & 4)) {
        mode |= 0x400;
    }
    if (flags & 0x10) {
        mode |= 0x60000;
    }
    gSPGeometryMode(g_displayListCursor++, 0, mode);
    return 1;
}
