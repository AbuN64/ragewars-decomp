#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8026AC38.h"
#include "abi.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"

/* Draws every part of a model resource with the shared material D_8013B2D8 when the frame's command buffer still has 3000 commands free and func_80269A80_de accepts the material: sets the render mode, selects blend 2 through func_80268CE0_de, loads the model matrix (or sets it as segment 1), loads an optional two-light block, registers the resource, sets segment 2 to the given texture base or the model's own and emits each part's display list. Adapted from func_8026DF7C_de with the render mode, blend and light commands added and the per-part lighting call removed. */




extern Gfx *D_80110634;
extern Frame118 *D_8011BDC0;
extern u32 D_800E28A4;
extern char D_8013B2D8;
extern void func_80253BBC_de(s32 heap, void **resource);
extern void *func_8028FDB4_de(void *table, s32 index);
extern s32 func_80269A80_de(void *material, s32 pass);
extern void func_80268CE0_de(s32 mode);

void func_8026C978_de(void **resource, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    s32 count;
    s32 i;

    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    if (func_80269A80_de(&D_8013B2D8, pass) == 0) {
        return;
    }
    gDPSetRenderMode(D_80110634++, 0x0C184F50, 0);
    func_80268CE0_de(2);
    if (segment != 0) { gSPSegment(D_80110634++, 1, matrix); } else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
    if (lights != 0) {
        Gfx *cmd = D_80110634++;
        gSPMoveWord(cmd, G_MW_NUMLIGHT, 0, 0x18);
        cmd = D_80110634++;
        gSPMoveMem(cmd, G_MV_LIGHT, 48, 16, lights + 8);
        cmd = D_80110634++;
        gSPMoveMem(cmd, G_MV_LIGHT, 72, 16, lights);
    }
    func_80253BBC_de(0, resource);
    header = *resource;
    base = textures;
    if (base == 0) {
        base = func_8028FDB4_de(header, 0);
    }
    gSPSegment(D_80110634++, 2, (unsigned int)base);
    parts = func_8028FDB4_de(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = func_8028FDB4_de(parts, i);
        func_8028FDB4_de(part, 0);
        {
            Gfx *cmd;
            void *list = func_8028FDB4_de(part, 1);

            cmd = D_80110634++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}

/* Draws every part of a model resource with the shared material D_80137288 when the frame's command buffer still has 3000 commands free and func_80269A80_de accepts the material: prepares through func_802A01E8_de, flags the material 0x20 and sets D_800D15E0, sets the render mode, loads the model matrix (or sets it as segment 1), loads an optional two-light block, registers the resource, sets segment 2 to the given texture base or the model's own and emits each part's display list, skipping parts whose material blend bits are all set unless the owner's 0x122C flag 0x400 is set. Adapted from func_8026C978_de with the preparation and flag stores added, the blend call removed and the per-part owner test added. */




extern Gfx *D_80110634;
extern Frame118 *D_8011BDC0;
extern u32 D_800E28A4;

extern s32 D_800D15E0;
extern void func_802A01E8_de(void);
extern void func_80253BBC_de(s32 heap, void **resource);
extern void *func_8028FDB4_de(void *table, s32 index);
extern s32 func_80269A80_de(void *material, s32 pass);






void func_8026CBA4_de(void **resource, void *owner, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;
    s32 *shared;
    Gfx **start;
    u32 used;

    func_802A01E8_de();
    start = &D_8011BDC0->commands;
    shared = &D_80137288;
    *shared |= 0x20;
    used = (u32)D_80110634 - (u32)*start;
    D_800D15E0 = 1;
    if (D_800E28A4 - used / sizeof(Gfx) < 3000) {
        return;
    }
    if (func_80269A80_de(shared, pass) == 0) {
        return;
    }
    gDPSetRenderMode(D_80110634++, 0x0C184DD8, 0);
    if (segment != 0) { gSPSegment(D_80110634++, 1, matrix); } else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
    if (lights != 0) {
        Gfx *cmd = D_80110634++;
        gSPMoveWord(cmd, G_MW_NUMLIGHT, 0, 0x18);
        cmd = D_80110634++;
        gSPMoveMem(cmd, G_MV_LIGHT, 48, 16, lights + 8);
        cmd = D_80110634++;
        gSPMoveMem(cmd, G_MV_LIGHT, 72, 16, lights);
    }
    func_80253BBC_de(0, resource);
    header = *resource;
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
        if ((((Material *)material)->flags & 0x38) != 0x38 || (((PlayerRecAt122C *)(owner))->flags & 0x400)) {
            Gfx *cmd;
            void *list = func_8028FDB4_de(part, 1);

            cmd = D_80110634++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}
