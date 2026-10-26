#include "COMMON/MODEL_RENDER.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/OBJECTSTATE18.H"
#include "RENDER_4/8026AC38.H"
#include "gbi.h"
#include "TYPES.H"
#include "RENDER_4/8026AC38_5.H"
#include "RENDER_4/8028FD2C_6.H"

/* Draws the parts of a model resource tinted by an RGBA colour through the shared material D_8013B2D8: sets the tint mode D_800D15E0 to 3, clears the material's fog colour and sets its flags, records the colour as floats and its alpha on the material, advances the pass modulo 18, and when the frame's command buffer still has 3000 commands free and Geometry_SetupMaterial accepts the material sets the render mode, selects blend 1, registers the resource, loads the matrix (or sets it as segment 1), sets segment 2 to the given texture base or the model's own, sets the lighting on the first part and emits each part whose material blend bits are all set and accepted for the pass, clearing the tint mode afterwards. Adapted from Geometry_DrawBlendParts with the tint setup, the render mode and blend commands and the trailing clear added. */






extern Gfx *g_displayListCursor;
#include "COMMON/DISPLAY.H"
#if defined(VERSION_DE)
extern u32 D_800DE854;
#elif defined(VERSION_EU)
extern u32 D_800EEEC4;
#elif defined(VERSION_EU_X)
extern u32 D_800EA084;
#elif defined(VERSION_US)
extern u32 D_800DD504;
#elif defined(VERSION_US_REV1)
extern u32 D_800E28A4;
#endif
extern ObjectState18 D_8013B2D8;
extern void Cache_MarkResourceInUse(s32 heap, void **resource);
extern s32 Geometry_ApplyMaterialLighting(void *matrix, void *lights, void *material);
extern s32 Geometry_SetupMaterial(void *material, s32 pass);
extern void Geometry_SetCombineMode(s32 mode);

void func_8026D4F0_de(void **resource, void *unused, void *matrix, s32 segment, void *lights, void *textures, s32 pass, u8 r, u8 g, u8 b, u8 a) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;
    ObjectState18 *shared;
    f32 *tint;

    shared = &D_8013B2D8;
    D_800D15E0 = 3;
    shared->fog[0] = 0;
    shared->fog[1] = 0;
    shared->fog[2] = 0;
    shared->flags |= 0x1402;
    tint = D_800D15E4;
    tint[0] = r;
    tint[1] = g;
    tint[2] = b;
    tint[3] = a;
    shared->fog[3] = a;
    pass = (pass + 1) % 18;
#if defined(VERSION_DE)
    if (D_800DE854 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
#elif defined(VERSION_EU)
    if (D_800EEEC4 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
#elif defined(VERSION_EU_X)
    if (D_800EA084 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
#elif defined(VERSION_US)
    if (D_800DD504 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
#elif defined(VERSION_US_REV1)
    if (D_800E28A4 - ((u32)g_displayListCursor - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
#endif
        return;
    }
    if (Geometry_SetupMaterial(shared, pass) != 0) {
        gDPSetRenderMode(g_displayListCursor++, 0x0C184DD8, 0);
        Geometry_SetCombineMode(1);
        header = *resource;
        Cache_MarkResourceInUse(0, resource);
        if (segment != 0) gSPSegment(g_displayListCursor++, 1, matrix) else gSPMatrix(g_displayListCursor++, matrix, G_MTX_LOAD);
        base = textures;
        if (base == 0) {
            base = SetN64_GetPackSection(header, 0);
        }
        gSPSegment(g_displayListCursor++, 2, (unsigned int)base);
        parts = SetN64_GetPackSection(header, 2);
        count = *(s32 *)parts;
        for (i = 0; i < count; i++) {
            part = SetN64_GetPackSection(parts, i);
            material = SetN64_GetPackSection(part, 0);
            if (i == 0) {
                Geometry_ApplyMaterialLighting(matrix, lights, material);
            }
            if ((((unsigned char *)material)[6] & 0x38) == 0x38 && Geometry_SetupMaterial(material, pass) != 0) {
                Gfx *cmd;
                void *list = SetN64_GetPackSection(part, 1);

                cmd = g_displayListCursor++;
                gSPDisplayList(cmd, (unsigned int)list);
            }
        }
    }
    D_800D15E0 = 0;
}

extern void Geometry_ExpandModelCommands(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void Geometry_ExpandBasicModel(s32 arg0, s32 arg1) {
    Geometry_ExpandModelCommands(arg0, arg1, 0, 0);
}


void Geometry_ExpandModelWithSentinel(s32 arg0, s32 arg1) {
    Geometry_ExpandModelCommands(arg0, arg1, 0, 1);
}


void Geometry_ExpandExtendedModel(s32 arg0, s32 arg1) {
    Geometry_ExpandModelCommands(arg0, arg1, 1, 0);
}

void func_8026D834_de(void) {
}
#ifndef VERSION_US_REV1
void Geometry_NoOperation(void) {
}
#endif
