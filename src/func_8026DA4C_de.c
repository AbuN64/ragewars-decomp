#include "span_1000/code_8026AC38.h"
#include "abi.h"
#include "gbi.h"
#include "types.h"

/* Draws a model resource when the frame's command buffer still has 3000 commands free: registers the resource, loads the model matrix (or sets it as segment 1 when asked), sets segment 2 to the given texture base or the model's own, and for each part sets the lighting on the first part and emits the part's display list when func_80269A80_de accepts its material. */

#include "types.h"
#include "n64sdk.h"



extern Gfx *D_80110634;
extern Frame118 *D_8011BDC0;
extern u32 D_800E28A4;
extern void func_80253BBC_de(s32 heap, void **resource);
extern void *func_8028FDB4_de(void *table, s32 index);
extern s32 func_8026B504_de(s32 matrix, s32 lights, void *material);
extern s32 func_80269A80_de(void *material, s32 pass);

void func_8026DA4C_de(void **resource, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;

    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    header = *resource;
    func_80253BBC_de(0, resource);
    if (segment != 0) { gSPSegment(D_80110634++, 1, matrix); } else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
    base = textures;
    if (base == 0) {
        base = func_8028FDB4_de(header, 0);
    }
    gSPSegment(D_80110634++, 2, (unsigned int)base);
    parts = func_8028FDB4_de(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = func_8028FDB4_de(parts, i);
        material = func_8028FDB4_de(part, 0);
        if (i == 0) {
            func_8026B504_de(matrix, lights, material);
        }
        if (func_80269A80_de(material, pass) != 0) {
            Gfx *cmd;
            void *list = func_8028FDB4_de(part, 1);

            cmd = D_80110634++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}
