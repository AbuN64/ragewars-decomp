#include "abi.h"
#include "types.h"
#include "gfx.h"
#include "span_1000/code_8026AC38.h"
#include "gbi.h"

extern Frame118 *D_8011BDC0;
extern Gfx *D_80110634;
extern u32 D_800E28A4;

extern s32 D_800CC364;
extern u32 D_800CC384;
extern u32 D_800CC38C;
extern void func_80253BBC_de(s32, void **);
extern void *func_8028FDB4_de(void *, s32);

void func_8026C6D8_de(s32 alpha, s32 resource, s32 matrix,
                     s32 segment, void *textures, s32 arg5, s32 arg6) {
    void *header;
    void *parts;
    void *part;
    void *list;
    Gfx *sync;
    u32 geometry;
    s32 count;
    s32 i;

    if (D_800E28A4 - (((u32)D_80110634 - (u32)D_8011BDC0->commands) >> 3) < 3000U) {
        return;
    }
    header = *(void **)resource;
    func_80253BBC_de(0, (void **)resource);
    if (segment != 0) {
        gSPSegment(D_80110634++, 1, matrix);
    } else {
        gSPMatrix(D_80110634++, matrix, G_MTX_LOAD);
    }
    if (textures == 0) {
        textures = func_8028FDB4_de(header, 0);
    }
    gSPSegment(D_80110634++, 2, (u32)textures);
    parts = func_8028FDB4_de(header, 2);
    geometry = D_800CC384;
    D_800CC360 = -1;
    D_800CC364 = -1;
    sync = D_80110634++;
    count = *(s32 *)parts;
    gDPPipeSync(sync);
    gDPSetTextureLUT(D_80110634++, G_TT_NONE);
    gSPTextureL(D_80110634++, 0x8000, 0x8000, 0, 0xFF, G_TX_RENDERTILE, G_ON);
    gDPSetPrimColor(D_80110634++, 0, 0, 0, 0, 0, alpha & 0xFF);
    gDPSetCombineLERP(D_80110634++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE,
                     0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE);
    gDPSetRenderMode(D_80110634++, D_800CC38C, G_RM_ZB_XLU_DECAL2);
    gSPGeometryMode(D_80110634++, G_SHADE | G_CULL_BACK | G_FOG |
                    G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH, 0);
    gSPGeometryMode(D_80110634++, 0, geometry | G_CULL_BACK);
    for (i = 0; i < count; i++) {
        part = func_8028FDB4_de(parts, i);
        func_8028FDB4_de(part, 0);
        list = func_8028FDB4_de(part, 1);
        gSPDisplayList(D_80110634++, (u32)list);
    }
    D_800CC364 = -1;
    D_800CC360 = -1;
}
