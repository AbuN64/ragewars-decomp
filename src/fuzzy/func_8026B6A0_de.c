#include "TYPES.H"
#include "gfx.h"
#include "gbi.h"

typedef struct { char pad0[0x80]; s8 kind; u8 variant; char pad82[13]; u8 bonus; char pad90[4]; u8 enabled; } ModelState;
typedef struct { char pad0[0x5D8]; ModelState *state; char pad5DC[0xC10]; f32 glow; char pad11F0[0x3C]; u32 flags; } ModelActor;
typedef struct { char pad0[0x114]; Gfx *commands; } ModelFrame;
typedef struct { char pad0[0x98]; s32 enabled; s32 unk9C; s32 timer; } ModelRules;
typedef struct { char pad0[6]; u8 flags; } ModelMaterial;
extern Gfx *D_80110634;
extern ModelFrame *D_8011BDC0;
extern ModelRules D_801468A0;
extern u32 D_800E28A4;
extern s32 D_80146918, D_801468F4;
extern void func_80253BBC_de(s32, void **);
extern void *func_8028FDB4_de(void *, s32);
extern s32 func_8026B504_de(void *, void *, ModelMaterial *);
extern s32 func_80269A80_de(ModelMaterial *, s32);

void func_8026B6A0_de(void **resource, ModelActor *actor, void *matrix, s32 segment, void *lights, void *textures, s32 pass) {
    s32 special = 0, bonus = 0, glow = 0, count, i;
    s32 *parts;
    void *header, *part;
    ModelMaterial *material;
    u8 mask, wanted;
    if (D_800E28A4 - (((u32)D_80110634 - (u32)D_8011BDC0->commands) >> 3) < 3000) return;
    if (D_801468A0.enabled && actor->state->kind == 11 && actor->state->enabled)
        special = D_801468A0.timer > 0;
    if (actor->flags & 0x8000) special = 1;
    if (actor->glow > 0.0f) glow = 1;
    if (D_80146918 && actor->state->bonus == 1) bonus = 1;
    header = *resource;
    func_80253BBC_de(0, resource);
    if (segment) { gSPSegment(D_80110634++, 1, matrix); }
    else { gSPMatrix(D_80110634++, matrix, G_MTX_LOAD); }
    if (textures == 0) textures = func_8028FDB4_de(header, 0);
    gSPSegment(D_80110634++, 2, textures);
    parts = func_8028FDB4_de(header, 2);
    count = *parts;
    for (i = 0; i < count; i++) {
        part = func_8028FDB4_de(parts, i);
        material = func_8028FDB4_de(part, 0);
        if (i == 0) func_8026B504_de(matrix, lights, material);
        if (actor->state->kind == 18 && (!D_801468F4 || actor->state->bonus == 0)) {
            wanted = 0x28;
            if (actor->state->variant != 0) {
                wanted = 0x18;
                if (actor->state->variant == 1) wanted = 0x20;
            }
            mask = material->flags & 0x38;
            if (mask == wanted || (mask == 0x38 && special) || (mask == 0x30 && bonus)) goto draw;
        } else {
            mask = material->flags & 0x38;
            if ((mask != 0x38 || special) && (mask != 0x30 || bonus) && (mask != 0x10 || glow)) {
draw:
                if (func_80269A80_de(material, pass)) {
                    header = func_8028FDB4_de(part, 1);
                    gSPDisplayList(D_80110634++, header);
                }
            }
        }
    }
}
