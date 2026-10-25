#include "COMMON/PACKEDMESHMATERIAL.H"
#include "COMMON/MODEL_RENDER.H"
#include "include_asm.h"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTSTATE18.H"
#include "RENDER_4/8026AC38.H"
#include "abi.h"
#include "gbi.h"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

/* Draws every part of a model resource with the shared material D_8013B2D8 when the frame's command buffer still has 3000 commands free and Render_SetupMaterial accepts the material: sets the render mode, selects blend 2 through func_80268CE0_de, loads the model matrix (or sets it as segment 1), loads an optional two-light block, registers the resource, sets segment 2 to the given texture base or the model's own and emits each part's display list. Adapted from func_8026DF7C_de with the render mode, blend and light commands added and the per-part lighting call removed. */




extern Gfx *D_80110634;
#include "COMMON/DISPLAY.H"
extern u32 D_800E28A4;
extern char D_8013B2D8;
extern void Scene_MarkResourceInUse(s32 heap, void **resource);
extern s32 Render_SetupMaterial(void *material, s32 pass);
extern void Render_SetCombineMode(s32 mode);

void func_8026C978_de(void **resource, s32 matrix, s32 segment, s32 lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    s32 count;
    s32 i;

    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    if (Render_SetupMaterial(&D_8013B2D8, pass) == 0) {
        return;
    }
    gDPSetRenderMode(D_80110634++, 0x0C184F50, 0);
    Render_SetCombineMode(2);
    if (segment != 0) { gSPSegment(D_80110634++, 1, matrix); } else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
    if (lights != 0) {
        Gfx *cmd = D_80110634++;
        gSPMoveWord(cmd, G_MW_NUMLIGHT, 0, 0x18);
        cmd = D_80110634++;
        gSPMoveMem(cmd, G_MV_LIGHT, 48, 16, lights + 8);
        cmd = D_80110634++;
        gSPMoveMem(cmd, G_MV_LIGHT, 72, 16, lights);
    }
    Scene_MarkResourceInUse(0, resource);
    header = *resource;
    base = textures;
    if (base == 0) {
        base = Render_GetPackSection(header, 0);
    }
    gSPSegment(D_80110634++, 2, (unsigned int)base);
    parts = Render_GetPackSection(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = Render_GetPackSection(parts, i);
        Render_GetPackSection(part, 0);
        {
            Gfx *cmd;
            void *list = Render_GetPackSection(part, 1);

            cmd = D_80110634++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}

/* Draws every part of a model resource with the shared material D_80137288 when the frame's command buffer still has 3000 commands free and Render_SetupMaterial accepts the material: prepares through func_802A01E8_de, flags the material 0x20 and sets D_800D15E0, sets the render mode, loads the model matrix (or sets it as segment 1), loads an optional two-light block, registers the resource, sets segment 2 to the given texture base or the model's own and emits each part's display list, skipping parts whose material blend bits are all set unless the owner's 0x122C flag 0x400 is set. Adapted from func_8026C978_de with the preparation and flag stores added, the blend call removed and the per-part owner test added. */




extern Gfx *D_80110634;
#include "COMMON/DISPLAY.H"
extern u32 D_800E28A4;

extern void func_802A01E8_de(void);
extern void Scene_MarkResourceInUse(s32 heap, void **resource);
extern s32 Render_SetupMaterial(void *material, s32 pass);






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
    start = &D_8011FAC0.ring.current->commands;
    shared = &D_80137288;
    *shared |= 0x20;
    used = (u32)D_80110634 - (u32)*start;
    D_800D15E0 = 1;
    if (D_800E28A4 - used / sizeof(Gfx) < 3000) {
        return;
    }
    if (Render_SetupMaterial(shared, pass) == 0) {
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
    Scene_MarkResourceInUse(0, resource);
    header = *resource;
    base = textures;
    if (base == 0) {
        base = Render_GetPackSection(header, 0);
    }
    gSPSegment(D_80110634++, 2, (unsigned int)base);
    parts = Render_GetPackSection(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = Render_GetPackSection(parts, i);
        material = Render_GetPackSection(part, 0);
        if ((((Material *)material)->flags & 0x38) != 0x38 || (((PlayerRecAt122C *)(owner))->flags & 0x400)) {
            Gfx *cmd;
            void *list = Render_GetPackSection(part, 1);

            cmd = D_80110634++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}

#include "COMMON/AIPROFILE.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/PACKEDMESHMATERIAL.H"
extern f32 D_800C46A0_de, D_800C46A4_de;
extern CGameStatus D_801468A0;
/* Draws a character model's parts with the shared material D_8013B2D8, choosing each part by the 0x38 bits of
 * its material byte 6: on the special state 0x12 the part must equal the bits for the variant at 0x81, otherwise
 * the 0x38/0x30/0x10 groups are drawn only when the matching flag (fade, bonus, glow) was computed first. */
void Render_DrawCharacterEffectParts(void **resource, struct Player *owner, void *matrix, s32 segment, Shared_ParticleLighting *lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    MeshMaterial *material;
    s32 count;
    s32 i;
    s32 hide = 0;
    s32 bonus = 0;
    s32 glow = 0;
    s32 flags;
    MeshMaterial *shared;
    CGameStatus *settings;

    if (matrix == 0) {
        return;
    }
    settings = &D_801468A0;
    if (settings->enabled != 0) {
        AiProfile *state = owner->profile;
        if (state->character == 0xB && state->enabled != 0) {
            hide = 0 < settings->m_nBastilleShield;
        }
    }
    if (owner->reactionFlags & 0x8000) {
        hide = 1;
    }
    if (0.0f < owner->glow) {
        glow = 1;
    }
    if (D_801468A0.m_bCTFOn != 0 && owner->profile->bonus == 1) {
        bonus = 1;
    }
    shared = (MeshMaterial *)&D_8013B2D8;
    flags = shared->flags;
    shared->flags = flags | 0x400;
    D_800D15E4[0] = D_800D15E4[1] = D_800D15E4[2] = D_800C46A0_de;
    D_800D15E4[3] = D_800C46A4_de;
    shared->flags = flags | 0x1402;
    D_800D15E0 = 3;
    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    if (Render_SetupMaterial(shared, pass) != 0) {
        gDPSetRenderMode(D_80110634++, 0x0C184DD8, 0);
        Render_SetCombineMode(1);
        if (segment != 0) {
            gSPSegment(D_80110634++, 1, matrix);
        } else {
            gSPMatrix(D_80110634++, matrix, G_MTX_LOAD);
        }
        if (lights != 0) {
            Gfx *cmd = D_80110634++;
            gSPMoveWord(cmd, G_MW_NUMLIGHT, 0, 0x18);
            cmd = D_80110634++;
            gSPMoveMem(cmd, G_MV_LIGHT, 48, 16, lights->diffuse);
            cmd = D_80110634++;
            gSPMoveMem(cmd, G_MV_LIGHT, 72, 16, lights);
        }
        Scene_MarkResourceInUse(0, resource);
        header = *resource;
        base = textures;
        if (base == 0) {
            base = Render_GetPackSection(header, 0);
        }
        gSPSegment(D_80110634++, 2, (unsigned int)base);
        parts = Render_GetPackSection(header, 2);
        count = *(s32 *)parts;
        for (i = 0; i < count; i++) {
            AiProfile *state;
            u32 bits;
            part = Render_GetPackSection(parts, i);
            material = Render_GetPackSection(part, 0);
            if (i == 0) {
                Render_ApplyMaterialLighting(matrix, lights, material);
            }
            state = owner->profile;
            if (state->character == 0x12 && (D_801468A0.m_bFragTagOn == 0 || state->bonus == 0)) {
                switch (state->variant) {
                case 0:
                    if ((material->mode & 0x38) == 0x28) {
                        if (Render_SetupMaterial(material, pass) != 0) {
                            void *list = Render_GetPackSection(part, 1);
                            Gfx *cmd = D_80110634++;
                            gSPDisplayList(cmd, (unsigned int)list);
                        }
                    }
                    break;
                case 1:
                    if ((material->mode & 0x38) == 0x20) {
                        if (Render_SetupMaterial(material, pass) != 0) {
                            void *list = Render_GetPackSection(part, 1);
                            Gfx *cmd = D_80110634++;
                            gSPDisplayList(cmd, (unsigned int)list);
                        }
                    }
                    break;
                case 2:
                    if ((material->mode & 0x38) == 0x18) {
                        if (Render_SetupMaterial(material, pass) != 0) {
                            void *list = Render_GetPackSection(part, 1);
                            Gfx *cmd = D_80110634++;
                            gSPDisplayList(cmd, (unsigned int)list);
                        }
                    }
                    break;
                }
            } else {
                bits = material->mode & 0x38;
                if (bits == 0x38 && hide == 0) continue;
                if (bits == 0x30 && bonus == 0) continue;
                if (bits == 0x10 && glow == 0) continue;
                if (Render_SetupMaterial(material, pass) != 0) {
                    void *list = Render_GetPackSection(part, 1);
                    Gfx *cmd = D_80110634++;
                    gSPDisplayList(cmd, (unsigned int)list);
                }
            }
        }
    }
    D_800D15E0 = 0;
}

#include "COMMON/GAME_SESSION.H"
extern const f32 D_800C46A8_de;
extern void Render_ApplyMaterialLighting(void *, void *, void *);
/* Draws every part of a model resource with the shared material D_8013B2D8 after setting its fixed colour
 * bytes (0x10..0x17) and flags 0x1402, when the frame's command buffer still has 3000 commands free; the first
 * part's material is registered through Render_ApplyMaterialLighting with the caller's two inputs. */
void Render_DrawModelWithSharedMaterial(void **resource, void *matrix, s32 segment, void *lights, void *textures, s32 pass) {
    void *header;
    void *base;
    void **parts;
    void *part;
    void *material;
    s32 count;
    s32 i;
    MeshMaterial *shared;
    u32 flags;
    if (matrix == 0) {
        return;
    }
    func_802A01E8_de();
    shared = (MeshMaterial *)&D_8013B2D8;
    flags = shared->flags;
    shared->secondaryColor[0] = 0x80;
    shared->secondaryColor[1] = 0x5F;
    shared->secondaryColor[2] = 0x22;
    shared->secondaryColor[3] = 0xF0;
    shared->primaryColor[0] = 0xDB;
    shared->primaryColor[1] = 0xB8;
    shared->primaryColor[2] = 0x77;
    shared->primaryColor[3] = 0x40;
    shared->flags = flags | 0x400;
    D_800D15E4[3] = D_800C46A8_de;
    shared->flags = flags | 0x1402;
    D_800D15E0 = 1;
    if (D_800E28A4 - ((u32)D_80110634 - (u32)D_8011FAC0.ring.current->commands) / sizeof(Gfx) < 3000) {
        return;
    }
    if (Render_SetupMaterial(shared, pass) == 0) {
        return;
    }
    gDPSetRenderMode(D_80110634++, 0x0C184DD8, 0);
    Render_SetCombineMode(1);
    if (segment != 0) { gSPSegment(D_80110634++, 1, matrix); } else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
    Scene_MarkResourceInUse(0, resource);
    header = *resource;
    base = textures;
    if (base == 0) {
        base = Render_GetPackSection(header, 0);
    }
    gSPSegment(D_80110634++, 2, (unsigned int)base);
    parts = Render_GetPackSection(header, 2);
    count = *(s32 *)parts;
    for (i = 0; i < count; i++) {
        part = Render_GetPackSection(parts, i);
        material = Render_GetPackSection(part, 0);
        if (i == 0) {
            Render_ApplyMaterialLighting(matrix, lights, material);
        }
        {
            Gfx *cmd;
            void *list = Render_GetPackSection(part, 1);
            cmd = D_80110634++;
            gSPDisplayList(cmd, (unsigned int)list);
        }
    }
}
