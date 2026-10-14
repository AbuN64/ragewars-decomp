#include "gfx.h"
#include "span_1000/code_80265370.h"
#include "span_1000/code_80265370.h"
#include "types.h"
#include "gbi.h"
#include "n64sdk.h"

extern void func_802BD320_de(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);

void func_8026593C_de(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    func_802BD320_de(arg0, arg1, arg2, arg3, arg4, arg5);
}

/* Returns the s32 at a byte offset into a resource loaded from the cartridge, then releases it.
   The resource's ROM address is each cartridge's own, because the data before it differs in size. */
extern char D_800C4388_de;
extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern void func_80253754_de(s32, void *);

s32 func_80265964_de(s32 arg0) {
    void **resource;
    s32 result;

#if defined(VERSION_DE)
    resource = func_8025193C_de(0, 0x28BB00, 0x28BB00, 0x20, 0x10, 0, 0, &D_800C4388_de, 1);
#elif defined(VERSION_EU_X)
    resource = func_8025193C_de(0, 0x290384, 0x290384, 0x20, 0x10, 0, 0, &D_800C4388_de, 1);
#else
    resource = func_8025193C_de(0, 0x28B244, 0x28B244, 0x20, 0x10, 0, 0, &D_800C4388_de, 1);
#endif
    result = *(s32 *)((char *)*resource + arg0);
    func_80253754_de(0, resource);
    return result;
}

/* Loads the scene's point lights into the display list: with no light in D_8013B1A8 it clears geometry mode bit 0x80, otherwise it sets it and fills eight light slots from the light list, transforming each active light's position into the view, storing its negated view direction, its colour scaled by its intensity, its falloff and a fixed range, marking unused slots off, and emits the light-move command for each slot, then advances the light buffer. The first direction component is truncated into a local before negating. */
extern Gfx *D_80110634;
extern s32 D_8010C4A0;
extern UnitLight D_8010C0A0[];
extern char D_8013B1A8;

extern LightNode *func_80268CBC_de(void *);
extern LightNode *func_80268CC8_de(void *, LightNode *);
extern void func_80272898_de(char *, f32 *, f32 *);

void func_802659E0_de(char *view) {
    LightNode *node;
    LightData *data;
    f32 position[4];
    f32 out[4];
    s32 i;
    s32 x;

    node = func_80268CBC_de(&D_8013B1A8);
    if (node == 0) {
        Gfx *g = D_80110634++;
        gSPGeometryMode(g, 0x80, 0);
        D_8010C4A0 += 8;
        return;
    }
    gSPGeometryMode(D_80110634++, 0, 0x80);
    for (i = 0; i < 8; i++) {
        if (node != 0 && node->active != 0) {
            data = node->data;
            position[0] = node->position[0];
            position[1] = node->position[1];
            position[2] = node->position[2];
            func_80272898_de(view + 0x220, position, out);
            x = out[0];
            D_8010C0A0[i + D_8010C4A0].dir[0] = -x;
            D_8010C0A0[i + D_8010C4A0].dir[1] = out[1];
            D_8010C0A0[i + D_8010C4A0].dir[2] = -(s32)out[2];
            D_8010C0A0[i + D_8010C4A0].color[3] = data->color[3] * node->intensity;
            D_8010C0A0[i + D_8010C4A0].color[2] = data->color[0] * node->intensity;
            D_8010C0A0[i + D_8010C4A0].color[1] = data->color[1] * node->intensity;
            D_8010C0A0[i + D_8010C4A0].color[0] = data->color[2] * node->intensity;
            D_8010C0A0[i + D_8010C4A0].falloff = data->falloff;
            D_8010C0A0[i + D_8010C4A0].near = data->near;
            D_8010C0A0[i + D_8010C4A0].range = 0x7F80;
        } else {
            D_8010C0A0[i + D_8010C4A0].falloff = -0x8000;
        }
        if (node != 0) {
            node = func_80268CC8_de(&D_8013B1A8, node);
        }
        {
            Gfx *g = D_80110634++;
            gSPMoveMem(g, 10, ((i + 1) * 2 + 10) * 8, 16, &D_8010C0A0[i + D_8010C4A0]);
        }
    }
    D_8010C4A0 += 8;
}
