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

void func_80270910_de(f32 *dst, PackedMatrixWords *src);

void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);

void func_80272944_de(f32 *m, f32 *in, f32 *out, u32 count);

void func_80253754_de(void *arg0, Node80253610 *arg1);

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
        table = func_8028FDB4_de(*resource, 5);
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
                func_80270910_de(matrix, &actor->bones[i]);
                if (soft) {
                    func_8027347C_de(matrix, 1.5f, 1.5f, 1.5f);
                }
                func_80272944_de(matrix, part->corners, vertices, 8);
                func_8023F750_de(ray, bounds, actor, origin, vertices, part, i);
            }
        }
        func_80253754_de(0, resource);
        return;
    }
    shape = func_8025193C_de(0, actor->shapeId, actor->shapeId, actor->shapeBank, 4, 0, 0, "anim object info", 1);
    if (shape != 0) {
        extent = func_8028FDB4_de(*shape, 0);
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
        func_80253754_de(0, shape);
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

#ifdef NON_MATCHING
#define AN_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
#include "COMMON/WORLD.H"
typedef struct SortedCandidate { u8 *object; f32 distance; } SortedCandidate;
extern u8 **D_80103FCC;
extern u8 D_801462C8[];
extern char D_002405FC[], D_00240638[];
extern void func_802852C0_de();
extern void func_8023F644_de(void *, void *);
void func_80240260_de(u8 *self) {
    u8 *state = AN_FIELD(self, u8 *, 0x40);
    SortedCandidate list[0x20];
    u8 scratch[0x30];
    u8 *owner;
    u8 *candidate;
    s32 total;
    s32 count = 0;
    s32 i;
    s32 kind;
    f32 distance;
    if (AN_FIELD(state, s8, 4) == 0 || !(AN_FIELD(state, u32, 0) & 0x10000)) {
        return;
    }
    owner = AN_FIELD(self, u8 *, 0);
    total = AN_FIELD(&D_8011FE88, s32, 0xB48);
    for (i = 0; i < total && count < 0x20; i++) {
        candidate = AN_FIELD(&D_8011FE88, u8 *, 0x948 + i * 4);
        if (candidate == owner) {
            continue;
        }
        if (AN_FIELD(state, s8, 4) == 7 && *D_80103FCC == candidate) {
            continue;
        }
        if ((AN_FIELD(state, u32, 0) & 0x8000) && AN_FIELD(candidate, u16, 0xE4) == 0x64F) {
            continue;
        }
        if (AN_FIELD(owner, u8, 0) == 2 && AN_FIELD(owner, u8 *, 0x12C) == candidate) {
            if (AN_FIELD(AN_FIELD(owner, u8 *, 0x118), u32, 0) & 0x40) {
                continue;
            }
            kind = AN_FIELD(AN_FIELD(candidate, u8 *, 0x18), s32, 0);
            if (kind == 1 || kind == 4) {
                continue;
            }
        }
        if (!(AN_FIELD(candidate, f32, 0xE8) < AN_FIELD(self, f32, 0x90))) continue;
        if (!(AN_FIELD(self, f32, 0x84) < AN_FIELD(candidate, f32, 0xF4))) continue;
        if (!(AN_FIELD(candidate, f32, 0xF0) < AN_FIELD(self, f32, 0x98))) continue;
        if (!(AN_FIELD(self, f32, 0x8C) < AN_FIELD(candidate, f32, 0xFC))) continue;
        if (!(AN_FIELD(candidate, f32, 0xEC) < AN_FIELD(self, f32, 0x94))) continue;
        if (!(AN_FIELD(self, f32, 0x88) < AN_FIELD(candidate, f32, 0xF8))) continue;
        if (func_8023DAA0_de(self, candidate + 0xE8, &distance) != 0) {
            list[count].object = candidate;
            list[count].distance = distance;
            count++;
        }
    }
    if (count == 0) {
        return;
    }
    func_802852C0_de(list, count, 8, D_00240638, D_002405FC);
    for (i = 0; i < count; i++) {
        if (!(list[i].distance < AN_FIELD(self, f32, 0x17C))) {
            return;
        }
        candidate = list[i].object;
        if ((AN_FIELD(candidate, u32, 0x100) & 0x300000) && D_801462C8[0x1D] == 0) {
            func_8023F644_de(self, scratch);
            Anim_TestEntityContact(self, scratch, candidate);
        } else {
            func_8023FD18_de(self, candidate, owner + 8, self + 0x84);
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_80240260_de);
#endif

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
