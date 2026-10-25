#include "include_asm.h"
#include "COMMON/RENDERSORTRECORD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BOX_CONTACT.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/TEXTURE_REQUEST.H"
#include "COMMON/OUTPUT.H"
#include "TYPES.H"
#include "ANIM/8023EEF0_3.H"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"

/* Tests a ray against an actor's collision boxes: an animated actor tests each of its parts in its
 * part mask whose bone sphere overlaps the ray bounds and is hit by the ray, enlarging the parts flagged
 * as soft for driven vehicles; other actors test the box of their shape bank resource, or their own box. */

s32 func_8023DAA0_de(Ray *ray, Box *box, f32 *out);

void **func_8024BFD4_de(MenuPanelRoot *arg0, s32 arg1);

void Rsp_ConvertMatrixToFloat(f32 *dst, PackedMatrixWords *src);

void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);

void func_80272944_de(f32 *m, f32 *in, f32 *out, u32 count);

void Scene_UnlockResource(void *arg0, Node80253610 *arg1);

void func_8023FD18_de(BoxContactRay *ray, BoxContactActor *actor, CVector3 *origin, Box *bounds) {
    CVector3 vertices[8];
    CVector3 corners[8];
    CVector3 center;
    f32 matrix[4][4];
    Box box;
    f32 t;
    s32 count;
    s32 driven;
    void **resource;
    void **shape;
    Box *own;
    CVector3 *corner;
    BoxContactPartTable *table;
    BoxContactTransform *part;
    f32 *extent;
    f32 size;
    f32 big;
    f32 radius;
    s32 soft;
    s32 i;
    s32 flags;
    BoxContactBone *bone;

    driven = 0;
    if (ray->material->flags & 0x20000) {
        if (*actor->kind == 1 || *actor->kind == 4) {
            driven = 1;
        }
    }
    soft = 0;
    if (actor->bones != 0) {
        resource = func_8024BFD4_de(actor, actor->animation);
    } else {
        resource = 0;
    }
    if (resource != 0) {
        big = actor->scale.y;
        if (!(actor->scale.x <= big)) {
            big = actor->scale.x;
        }
        size = actor->scale.z;
        if (!(big <= size)) {
            size = big;
        }
        table = Render_GetPackSection(*resource, 5);
        count = table->count;
        for (i = 0; i < count; i++) {
            part = (BoxContactTransform *)((char *)table + (i * table->stride + 8));
            if (!(part->mask & actor->partMask)) {
                continue;
            }
            if (driven) {
                flags = part->flags & 3;
                soft = 0;
                if (flags < 4) {
                    soft = flags >= 0;
                }
            }
            bone = &actor->bones[i];
            center.x = bone->whole[3][0];
            center.y = bone->whole[3][1];
            center.z = bone->whole[3][2];
            radius = part->radius * size + 1.0f;
            if (soft) {
                radius *= 1.5f;
            }
            box.min.x = center.x - radius;
            box.min.y = center.y - radius;
            box.min.z = center.z - radius;
            box.max.x = center.x + radius;
            box.max.y = center.y + radius;
            box.max.z = center.z + radius;
            if (bounds->min.x < box.max.x && box.min.x < bounds->max.x && bounds->min.z < box.max.z &&
                box.min.z < bounds->max.z && bounds->min.y < box.max.y && box.min.y < bounds->max.y &&
                func_8023DAA0_de(ray, &box, &t)) {
                Rsp_ConvertMatrixToFloat(matrix, &actor->bones[i]);
                if (soft) {
                    func_8027347C_de(matrix, 1.5f, 1.5f, 1.5f);
                }
                func_80272944_de(matrix, part->corners, vertices, 8);
                func_8023F750_de(ray, bounds, actor, origin, vertices, part, i);
            }
        }
        Scene_UnlockResource(0, resource);
        return;
    }
    shape = Scene_RequestResource(0, actor->shapeId, actor->shapeId, actor->shapeBank, 4, 0, 0, "anim object info", 1);
    if (shape != 0) {
        extent = Render_GetPackSection(*shape, 0);
        corners[0].x = extent[0];
        corners[0].y = extent[1];
        corners[0].z = extent[2];
        corners[1].x = extent[3];
        corners[1].y = extent[1];
        corners[1].z = extent[2];
        corners[2].x = extent[3];
        corners[2].y = extent[1];
        corners[2].z = extent[5];
        corners[3].x = extent[0];
        corners[3].y = extent[1];
        corners[3].z = extent[5];
        corners[4].x = extent[0];
        corners[4].y = extent[4];
        corners[4].z = extent[2];
        corners[5].x = extent[3];
        corners[5].y = extent[4];
        corners[5].z = extent[2];
        corners[6].x = extent[3];
        corners[6].y = extent[4];
        corners[6].z = extent[5];
        corners[7].x = extent[0];
        corners[7].y = extent[4];
        corners[7].z = extent[5];
        func_80272944_de(actor->transform, corners, vertices, 8);
        Scene_UnlockResource(0, shape);
    } else {
        own = &actor->box;
        corner = vertices;
        corner[0].x = own->min.x;
        corner[0].y = own->min.y;
        corner[0].z = own->min.z;
        corner[1].x = own->max.x;
        corner[1].y = own->min.y;
        corner[1].z = own->min.z;
        corner[2].x = own->max.x;
        corner[2].y = own->min.y;
        corner[2].z = own->max.z;
        corner[3].x = own->min.x;
        corner[3].y = own->min.y;
        corner[3].z = own->max.z;
        corner[4].x = own->min.x;
        corner[4].y = own->max.y;
        corner[4].z = own->min.z;
        corner[5].x = own->max.x;
        corner[5].y = own->max.y;
        corner[5].z = own->min.z;
        corner[6].x = own->max.x;
        corner[6].y = own->max.y;
        corner[6].z = own->max.z;
        corner[7].x = own->min.x;
        corner[7].y = own->max.y;
        corner[7].z = own->max.z;
    }
    func_8023F750_de(ray, bounds, actor, origin, vertices, 0, -1);
}

/* Collect overlapping actors, sort their contact distances, and dispatch each contact within range. */
#include "COMMON/WORLD.H"
#include "COMMON/LEVEL_ACTOR.H"
typedef struct SortedCandidate { LevelActor *object; f32 distance; } SortedCandidate;
typedef struct HitState {
    u32 flags;
    s8 mode;
} HitState;
typedef struct HitOwner {
    u8 kind;
    u8 pad1[0x117];
    u32 *rules; /* 0x118 */
    u8 pad11C[0x10];
    LevelActor *target; /* 0x12C */
} HitOwner;
typedef struct HitSelf {
    HitOwner *owner; /* 0 */
    u8 pad4[0x3C];
    HitState *state; /* 0x40 */
    u8 pad44[0x40];
    Box box; /* 0x84 */
    u8 pad9C[0xE0];
    f32 range; /* 0x17C */
} HitSelf;
extern LevelActor **D_80103FCC;
#include "COMMON/SHARED_GAMESLOT.H"
extern char D_002405FC[], D_00240638[];
extern void func_802852C0_de();
extern void func_8023F644_de(void *, void *);
void Anim_ProcessEntityContacts(HitSelf *self) {
    HitState *state = self->state;
    u8 scratch[0x30];
    SortedCandidate list[0x20];
    SortedCandidate *entry;
    u8 *ownerPosition;
    HitOwner *owner;
    Shared_World *world;
    Shared_Game *game;
    LevelActor *candidate;
    s32 total;
    s32 count;
    s32 i, contactIndex;
    s32 kind;
    f32 distance;
    if (state->mode == 0 || !(state->flags & 0x10000)) {
        return;
    }
    entry = list;
    count = i = 0;
    owner = self->owner;
    ownerPosition = (u8 *)owner + 8;
    world = &g_world;
    total = world->moverCount;
    for (; i < total; i++) {
        if (count >= 0x20) break;
        candidate = world->movers[i];
        if ((LevelActor *)owner == candidate) {
            continue;
        }
        if (state->mode == 7 && *D_80103FCC == candidate) {
            continue;
        }
        if ((state->flags & 0x8000) && candidate->type == 0x64F) {
            continue;
        }
        if (owner->kind == 2 && owner->target == candidate) {
            if (*owner->rules & 0x40) {
                continue;
            }
            kind = *(s32 *)candidate->definition;
            if (kind == 1 || kind == 4) {
                continue;
            }
        }
        if (!(self->box.max.x > candidate->bounds.min.x)) continue;
        if (!(self->box.min.x < candidate->bounds.max.x)) continue;
        if (!(self->box.max.z > candidate->bounds.min.z)) continue;
        if (!(self->box.min.z < candidate->bounds.max.z)) continue;
        if (!(self->box.max.y > candidate->bounds.min.y)) continue;
        if (!(self->box.min.y < candidate->bounds.max.y)) continue;
        if (func_8023DAA0_de(self, &candidate->bounds, &distance) != 0) {
            entry->object = candidate;
            entry->distance = distance;
            count++;
            entry++;
        }
    }
    if (count == 0) {
        return;
    }
    func_802852C0_de(list, count, 8, D_00240638, D_002405FC);
    entry = list;
    for (contactIndex = 0; contactIndex < count; contactIndex++, entry++) {
        if (!(entry->distance < self->range)) {
            return;
        }
        candidate = entry->object;
        if ((candidate->flags & 0x300000) && (game = &D_801462C8)->local == 0) {
            func_8023F644_de(self, scratch);
            Anim_TestEntityContact(self, scratch, candidate);
        } else {
            func_8023FD18_de(self, candidate, ownerPosition, &self->box);
        }
    }
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C3654[3] = {
    0x0000000A, 0x00080084, 0x0500000A,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C39D4[3] = {
    0x8E430038, 0x02601021, 0x00761821,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C3724[3] = {
    0x3F800000, 0xBF800000, 0x3F800000,
};
#endif
