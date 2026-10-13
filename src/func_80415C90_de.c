#include "span_16E000/code_804143D8.h"
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_804143D8.h"
#include "gfx.h"
#include "gbi.h"
#include "decomp/argb_color.h"
#include "abi.h"
#include "span_C76B0/data.h"
#include "common/unused.h"
#include "n64sdk.h"

extern Gfx *D_80110634;
extern Triple D_80153F60;
extern void func_802A1898_de(s32 *, s32 *, s32 *, s32 *);

/* Clips a screen rectangle to the viewport func_802A1898_de reports, interpolating the four corner
   colours along each clipped edge, then writes the corners into vertices 0-3 with gSPModifyVertex
   (screen position, colour rotated to RGBA, texture coordinates 0) and draws them as an outline of
   four lines, or as two triangles when D_80153F60.y is set. */
/* Sets vertex index's screen position, colour and texture coordinates. */
static inline void put_vertex(s32 index, s32 x, s32 y, u32 color) {
    Gfx *g;

    g = D_80110634++;
    gSPModifyVertex(g, index, G_MWO_POINT_XYSCREEN, (x << 18) | ((y & 0xFFFF) << 2));
    g = D_80110634++;
    gSPModifyVertex(g, index, G_MWO_POINT_RGBA, (color << 8) | (color >> 24));
    g = D_80110634++;
    gSPModifyVertex(g, index, G_MWO_POINT_ST, 0);
}

void func_80415C90_de(f32 x, f32 y, f32 w, f32 h, u32 col0, u32 col1, u32 col2, u32 col3) {
    s32 left;
    s32 top;
    s32 right_edge;
    s32 bottom_edge;
    f32 right;
    f32 bottom;
    f32 t;
    f32 edge;
    ArgbColor *c0 = (ArgbColor *)&col0;
    ArgbColor *c1 = (ArgbColor *)&col1;
    ArgbColor *c2 = (ArgbColor *)&col2;
    ArgbColor *c3 = (ArgbColor *)&col3;

    right = (x + w) - 1.0f;
    bottom = (y + h) - 1.0f;
    func_802A1898_de(&left, &top, &right_edge, &bottom_edge);
    if ((f32)right_edge < x || (f32)bottom_edge < y || right < (f32)left || bottom < (edge = (f32)top)) {
        return;
    }
    if (y < edge) {
        t = (bottom - edge) / h;
        y = edge;
        c0->r = (u32)(c2->r - (c2->r - c0->r) * t);
        c0->g = (u32)(c2->g - (c2->g - c0->g) * t);
        c0->b = (u32)(c2->b - (c2->b - c0->b) * t);
        c0->a = (u32)(c2->a - (c2->a - c0->a) * t);
        c1->r = (u32)(c3->r - (c3->r - c1->r) * t);
        c1->g = (u32)(c3->g - (c3->g - c1->g) * t);
        c1->b = (u32)(c3->b - (c3->b - c1->b) * t);
        c1->a = (u32)(c3->a - (c3->a - c1->a) * t);
    }
    edge = (f32)bottom_edge;
    if (edge < bottom) {
        t = (edge - y) / h;
        bottom = edge;
        c2->r = (u32)(c0->r + (c2->r - c0->r) * t);
        c2->g = (u32)(c0->g + (c2->g - c0->g) * t);
        c2->b = (u32)(c0->b + (c2->b - c0->b) * t);
        c2->a = (u32)(c0->a + (c2->a - c0->a) * t);
        c3->r = (u32)(c1->r + (c3->r - c1->r) * t);
        c3->g = (u32)(c1->g + (c3->g - c1->g) * t);
        c3->b = (u32)(c1->b + (c3->b - c1->b) * t);
        c3->a = (u32)(c1->a + (c3->a - c1->a) * t);
    }
    edge = (f32)left;
    if (x < edge) {
        t = (right - edge) / w;
        x = edge;
        c0->r = (u32)(c1->r - (c1->r - c0->r) * t);
        c0->g = (u32)(c1->g - (c1->g - c0->g) * t);
        c0->b = (u32)(c1->b - (c1->b - c0->b) * t);
        c0->a = (u32)(c1->a - (c1->a - c0->a) * t);
        c2->r = (u32)(c3->r - (c3->r - c2->r) * t);
        c2->g = (u32)(c3->g - (c3->g - c2->g) * t);
        c2->b = (u32)(c3->b - (c3->b - c2->b) * t);
        c2->a = (u32)(c3->a - (c3->a - c2->a) * t);
    }
    edge = (f32)right_edge;
    if (edge < right) {
        t = (edge - x) / w;
        right = edge;
        c1->r = (u32)(c0->r + (c1->r - c0->r) * t);
        c1->g = (u32)(c0->g + (c1->g - c0->g) * t);
        c1->b = (u32)(c0->b + (c1->b - c0->b) * t);
        c1->a = (u32)(c0->a + (c1->a - c0->a) * t);
        c3->r = (u32)(c2->r + (c3->r - c2->r) * t);
        c3->g = (u32)(c2->g + (c3->g - c2->g) * t);
        c3->b = (u32)(c2->b + (c3->b - c2->b) * t);
        c3->a = (u32)(c2->a + (c3->a - c2->a) * t);
    }
    right += 1.0f;
    bottom += 1.0f;
    put_vertex(0, x, y, col0);
    put_vertex(1, x, bottom, col2);
    put_vertex(2, right, bottom, col3);
    put_vertex(3, right, y, col1);
    if (D_80153F60.y == 0) {
        gSPLine3D(D_80110634++, 0, 1, 0);
        gSPLine3D(D_80110634++, 1, 2, 0);
        gSPLine3D(D_80110634++, 2, 3, 0);
        gSPLine3D(D_80110634++, 3, 0, 0);
    } else {
        gSP2Triangles(D_80110634++, 0, 1, 2, 0, 2, 3, 0, 0);
    }
}

/* Switches the graphics combiner and emits a pipeline sync once per frame. */
extern int D_800DF270,D_800E32E4,D_8014DCDC;
extern Gfx *D_80110634;
static inline void sync(void){D_800E32E4=1;gDPPipeSync(D_80110634++);}

void func_80416CF4_de(int mode){
 if(mode!=D_800DF270){
 D_800DF270=mode;
 if(!D_800E32E4)sync();
 gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
 switch(mode){
 case 1: if(D_8014DCDC){gDPSetCombineLERP(D_80110634++, TEXEL0, 0, ENVIRONMENT, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, ENVIRONMENT, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT);}else{gDPSetCombineLERP(D_80110634++, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, 1, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, 1);}break;
 case 2: if(D_8014DCDC){gDPSetCombineLERP(D_80110634++, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, PRIMITIVE);}else{gDPSetCombineLERP(D_80110634++, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, 1, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, 1);}break;
 case 3: gDPSetCombineLERP(D_80110634++, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, 1, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, 1);break;
 case 4: if(D_8014DCDC){gDPSetCombineLERP(D_80110634++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0);}else{gDPSetCombineLERP(D_80110634++, TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, TEXEL0, 0, SHADE, 0, 0, 0, 0, 1);}break;
 case 5: if(D_8014DCDC){gDPSetCombineLERP(D_80110634++, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE);}else{gDPSetCombineLERP(D_80110634++, 0, 0, 0, SHADE, 0, 0, 0, 1, 0, 0, 0, SHADE, 0, 0, 0, 1);}break;
 }
 }
}

/* Selects vertex mode when it differs from D_800DF278: mode 9 loads an identity model matrix
   through func_8029EB14_de and func_80419430_de, transforms the point (0, 0, D_800DD3FC) by the view
   D_80141168, loads four white vertices at that point and marks each vertex's screen position for
   modification. */

extern Gfx *D_80110634;
extern s32 D_800DF278;

extern char D_80141168;

extern void func_8029EB14_de(Matrix *m);
extern Vtx10 *func_802A15E4_de(s32 size);

void func_80416ECC_de(s32 mode) {
    Vec3 point;
    Vec3 projected;
    Matrix identity;
    Vtx10 *vertices;
    s32 count;
    s32 i;

    if (mode == D_800DF278) {
        return;
    }
    if (mode == 9) {
        func_8029EB14_de(&identity);
        func_80419430_de(&identity);
        point.x = 0.0f;
        point.y = 0.0f;
        point.z = D_800DD3FC;
        func_80272898_de(&D_80141168, &point, &projected);
        count = 4;
        vertices = func_802A15E4_de(0x40);
        for (i = 0; i < count; i++) {
            vertices[i].v.ob[0] = projected.x;
            vertices[i].v.ob[1] = projected.y;
            vertices[i].v.ob[2] = projected.z;
            vertices[i].v.tc[0] = 0;
            vertices[i].v.tc[1] = 0;
            vertices[i].v.cn[0] = 0xFF;
            vertices[i].v.cn[1] = 0xFF;
            vertices[i].v.cn[2] = 0xFF;
            vertices[i].v.cn[3] = 0xFF;
        }
        {
            Gfx *cmd = D_80110634++;
            gSPVertex(cmd, (u32)vertices, count, 0);
        }
        for (i = 0; i < count; i++) {
            Gfx *cmd = D_80110634++;
            gSPModifyVertex(cmd, i, G_MWO_POINT_ZSCREEN, 0);
        }
    }
    D_800DF278 = mode;
}

/* Selects render mode 11 or 12 (always 11 while D_80153F60's enable word is clear) when it differs
   from the cached mode D_800E32CC: flushes through func_80418F8C_de and applies the mode word built
   from the mode's base bits (0x53 or 0x33, with bit 2 when the first switch is set), then 0x300 or
   0x500, 0x3000 or 0x5000 and 0x30000 or 0x50000 chosen by the three further switches, through
   func_80417138_de. */

extern Triple D_80153F60;

extern s32 D_800E32CC;

void func_80417034_de(s32 mode) {
    s32 bits;

    if (D_80153F60.y == 0) {
        mode = 11;
    }
    if (mode == D_800E32CC) {
        return;
    }
    D_800E32CC = mode;
    if (mode == 11) {
        func_80418F8C_de();
        bits = D_80153F60.x ? 0x55 : 0x53;
        bits |= D_80153F60.z ? 0x300 : 0x500;
        func_80417138_de(bits | (D_8014DCDC ? 0x3000 : 0x5000) | (D_8014DCE0 ? 0x30000 : 0x50000));
    } else if (mode == 12) {
        func_80418F8C_de();
        bits = D_80153F60.x ? 0x35 : 0x33;
        bits |= D_80153F60.z ? 0x300 : 0x500;
        func_80417138_de(bits | (D_8014DCDC ? 0x3000 : 0x5000) | (D_8014DCE0 ? 0x30000 : 0x50000));
    }
}
