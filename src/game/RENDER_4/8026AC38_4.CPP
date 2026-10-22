#include "COMMON/MODEL_RENDER.H"
#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTSTATE18.H"
#include "abi.h"
#include "gbi.h"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

/* Draws every part of a model resource with the shared material D_8013B2D8 when the frame's command buffer still has 3000 commands free and func_80269A80_de accepts the material: sets the render mode, selects blend 2 through func_80268CE0_de, loads the model matrix (or sets it as segment 1), loads an optional two-light block, registers the resource, sets segment 2 to the given texture base or the model's own and emits each part's display list. Adapted from func_8026DF7C_de with the render mode, blend and light commands added and the per-part lighting call removed. */




extern Gfx *D_80110634;
#include "COMMON/DISPLAY.H"
extern u32 D_800E28A4;
extern char D_8013B2D8;
extern void func_80253BBC_de(s32 heap, void **resource);
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
#include "COMMON/DISPLAY.H"
extern u32 D_800E28A4;

extern s32 D_800D15E0;
extern void func_802A01E8_de(void);
extern void func_80253BBC_de(s32 heap, void **resource);
extern s32 func_80269A80_de(void *material, s32 pass);






void func_8026CBA4_de(void **resource, void *owner, void *matrix, s32 segment, Shared_ParticleLighting *lights, void *textures, s32 pass) {
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
        gSPMoveMem(cmd, G_MV_LIGHT, 48, 16, lights->diffuse);
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

#ifdef NON_MATCHING
#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
extern f32 D_800C46A0_de, D_800C46A4_de;
extern f32 D_800D15E4[4];
extern char D_801468A0[], D_80146918[], D_801468F4[];
/* Draws a character model's parts with the shared material D_8013B2D8, choosing each part by the 0x38 bits of
 * its material byte 6: on the special state 0x12 the part must equal the bits for the variant at 0x81, otherwise
 * the 0x38/0x30/0x10 groups are drawn only when the matching flag (fade, bonus, glow) was computed first. */
void func_8026CE20_de(void **resource, void *owner, void *matrix, s32 segment, void *lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    u8 *material;
    s32 count;
    s32 i;
    s32 hide = 0;
    s32 bonus = 0;
    s32 glow = 0;
    u32 flags;
    u8 *shared;
    if (matrix == 0) {
        return;
    }
    if (FIELD(s32, D_801468A0, 0x98) != 0) {
        void *state = FIELD(void *, owner, 0x5D8);
        if (FIELD(s8, state, 0x80) == 0xB && FIELD(u8, state, 0x94) != 0) {
            hide = 0 < FIELD(s32, D_801468A0, 0xA0);
        }
    }
    if (FIELD(u32, owner, 0x122C) & 0x8000) {
        hide = 1;
    }
    if (0.0f < FIELD(f32, owner, 0x11EC)) {
        glow = 1;
    }
    if (FIELD(s32, D_80146918, 0) != 0 && FIELD(u8, FIELD(void *, owner, 0x5D8), 0x8F) == 1) {
        bonus = 1;
    }
    shared = (u8 *)&D_8013B2D8;
    flags = *(u32 *)shared;
    *(u32 *)shared = flags | 0x400;
    D_800D15E4[2] = D_800C46A0_de;
    D_800D15E4[1] = D_800C46A0_de;
    D_800D15E4[0] = D_800C46A0_de;
    D_800D15E4[3] = D_800C46A4_de;
    *(u32 *)shared = flags | 0x1402;
    D_800D15E0 = 3;
    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    if (func_80269A80_de(shared, pass) != 0) {
        gDPSetRenderMode(D_80110634++, 0x0C184DD8, 0);
        func_80268CE0_de(1);
        if (segment != 0) { gSPSegment(D_80110634++, 1, matrix); } else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
        if (lights != 0) {
            Gfx *cmd = D_80110634++;
            gSPMoveWord(cmd, G_MW_NUMLIGHT, 0, 0x18);
            cmd = D_80110634++;
            gSPMoveMem(cmd, G_MV_LIGHT, 48, 16, (char *)lights + 8);
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
            void *state;
            u32 bits;
            part = func_8028FDB4_de(parts, i);
            material = func_8028FDB4_de(part, 0);
            if (i == 0) {
                func_8026B504_de(matrix, lights, material);
            }
            state = FIELD(void *, owner, 0x5D8);
            if (FIELD(s8, state, 0x80) == 0x12 && (FIELD(s32, D_801468F4, 0) == 0 || FIELD(u8, state, 0x8F) == 0)) {
                u32 want;
                switch (FIELD(s8, state, 0x81)) {
                case 0:
                    want = 0x28;
                    break;
                case 1:
                    want = 0x20;
                    break;
                case 2:
                    want = 0x18;
                    break;
                default:
                    continue;
                }
                if ((material[6] & 0x38) != want) {
                    continue;
                }
            } else {
                bits = material[6] & 0x38;
                if (bits == 0x38 && hide == 0) {
                    continue;
                }
                if (bits == 0x30 && bonus == 0) {
                    continue;
                }
                if (bits == 0x10 && glow == 0) {
                    continue;
                }
            }
            if (func_80269A80_de(material, pass) == 0) {
                continue;
            }
            {
                Gfx *cmd;
                void *list = func_8028FDB4_de(part, 1);
                cmd = D_80110634++;
                gSPDisplayList(cmd, (unsigned int)list);
            }
        }
        D_800D15E0 = 0;
    }
}
#else
INCLUDE_ASM("span_1000", func_8026CE20_de);
#endif

#ifdef NON_MATCHING
extern f32 D_800C46A8_de, D_800D15F0;
extern void func_8026B504_de(void *, void *, void *);
/* Draws every part of a model resource with the shared material D_8013B2D8 after setting its fixed colour
 * bytes (0x10..0x17) and flags 0x1402, when the frame's command buffer still has 3000 commands free; the first
 * part's material is registered through func_8026B504_de with the caller's two inputs. */
void func_8026D280_de(void **resource, void *matrix, s32 segment, void *arg3, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;
    u8 *shared;
    u32 flags;
    if (matrix == 0) {
        return;
    }
    func_802A01E8_de();
    shared = (u8 *)&D_8013B2D8;
    flags = *(u32 *)shared;
    shared[0x14] = 0x80;
    shared[0x15] = 0x5F;
    shared[0x16] = 0x22;
    shared[0x17] = 0xF0;
    shared[0x10] = 0xDB;
    shared[0x11] = 0xB8;
    shared[0x12] = 0x77;
    shared[0x13] = 0x40;
    *(u32 *)shared = flags | 0x400;
    D_800D15F0 = D_800C46A8_de;
    *(u32 *)shared = flags | 0x1402;
    D_800D15E0 = 1;
    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011BDC0->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    if (func_80269A80_de(shared, pass) == 0) {
        return;
    }
    gDPSetRenderMode(D_80110634++, 0x0C184DD8, 0);
    func_80268CE0_de(1);
    if (segment != 0) { gSPSegment(D_80110634++, 1, matrix); } else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
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
        if (i == 0) {
            func_8026B504_de(matrix, arg3, material);
        }
        {
            Gfx *cmd;
            void *list = func_8028FDB4_de(part, 1);
            cmd = D_80110634++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_8026D280_de);
#endif
