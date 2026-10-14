#include "span_1000/code_8026AC38.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"

/* Draws the parts of a model resource tinted by an RGBA colour through the shared material D_8013B2D8: sets the tint mode D_800D15E0 to 3, clears the material's fog colour and sets its flags, records the colour as floats and its alpha on the material, advances the pass modulo 18, and when the frame's command buffer still has 3000 commands free and func_80269A80_de accepts the material sets the render mode, selects blend 1, registers the resource, loads the matrix (or sets it as segment 1), sets segment 2 to the given texture base or the model's own, sets the lighting on the first part and emits each part whose material blend bits are all set and accepted for the pass, clearing the tint mode afterwards. Adapted from func_8026DD50_de with the tint setup, the render mode and blend commands and the trailing clear added. */






extern Gfx *D_80110634;
extern Frame118 *D_8011BDC0;
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
extern s32 D_800D15E0;
extern f32 D_800D15E4[4];
extern void func_80253BBC_de(s32 heap, void **resource);
extern void *func_8028FDB4_de(void *table, s32 index);
extern s32 func_8026B504_de(s32 matrix, s32 lights, void *material);
extern s32 func_80269A80_de(void *material, s32 pass);
extern void func_80268CE0_de(s32 mode);

void func_8026D4F0_de(void **resource, s32 unused, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass, u8 r, u8 g, u8 b, u8 a) {
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
    if (D_800DE854 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
#elif defined(VERSION_EU)
    if (D_800EEEC4 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
#elif defined(VERSION_EU_X)
    if (D_800EA084 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
#elif defined(VERSION_US)
    if (D_800DD504 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
#elif defined(VERSION_US_REV1)
    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
#endif
        return;
    }
    if (func_80269A80_de(shared, pass) != 0) {
        gDPSetRenderMode(D_80110634++, 0x0C184DD8, 0);
        func_80268CE0_de(1);
        header = *resource;
        func_80253BBC_de(0, resource);
        if (segment != 0) gSPSegment(D_80110634++, 1, matrix) else gSPMatrix(D_80110634++, matrix, G_MTX_LOAD);
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
            if ((((unsigned char *)material)[6] & 0x38) == 0x38 && func_80269A80_de(material, pass) != 0) {
                Gfx *cmd;
                void *list = func_8028FDB4_de(part, 1);

                cmd = D_80110634++;
                gSPDisplayList(cmd, (unsigned int)list);
            }
        }
    }
    D_800D15E0 = 0;
}

extern void func_8026AD8C_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_8026D7D4_de(s32 arg0, s32 arg1) {
    func_8026AD8C_de(arg0, arg1, 0, 0);
}

extern void func_8026AD8C_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_8026D7F4_de(s32 arg0, s32 arg1) {
    func_8026AD8C_de(arg0, arg1, 0, 1);
}

extern void func_8026AD8C_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void func_8026D814_de(s32 arg0, s32 arg1) {
    func_8026AD8C_de(arg0, arg1, 1, 0);
}

void func_8026D834_de(void) {
}
#ifndef VERSION_US_REV1
void func_8026D83C_de(void) {
}
#endif
