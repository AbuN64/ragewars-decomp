#include "COMMON/BOX_CONTACT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/OUTPUT.H"
#include "COMMON/RENDERSORTRECORD.H"
#include "COMMON/OBJB.H"
#include "TYPES.H"
#include "ANIM/8023EEF0_3.H"
#include "RENDER_2/8022AE90_5.H"

s32 func_8023E8D4_de(CapsuleSweep *ray, Polygon_func_8023E8D4_de *poly, s32 keep);
void func_8044A07C_de(struct Object_func_8044A07C_de *);
void func_80271FC8_de(CVector3 *, f32, void *, void *);
void func_80265E10_de(void *, void *, s32, s32, CVector3, ContactEffectStyle);
s32 func_802833D0_de(void *);

s32 func_8023F750_de(BoxContactRay *ray, void *unused, BoxContactActor *actor, CVector3 *origin,
                    CVector3 *vertices, BoxContactTransform *transform, s32 index) {
    CVector3 *corners[4], *current;
    CVector3 normal, delta, hit, edge, offset;
    BoxContactPolygon polygon;
    CVector3 effectPosition;
    ContactEffectStyle style;
    ContactProjectile *projectile;
    s32 face, i, next, inside, found;
    f32 denominator, distance, fraction;
    found = 0;
    for (face = 0; face < 6; face++) {
        switch (face) {
        case 0:
            corners[0] = &vertices[7]; corners[1] = &vertices[6];
            corners[2] = &vertices[5]; corners[3] = &vertices[4];
            Particle_SubtractVectors(&normal, &vertices[4], &vertices[0]); break;
        case 1:
            corners[0] = &vertices[4]; corners[1] = &vertices[5];
            corners[2] = &vertices[1]; corners[3] = &vertices[0];
            Particle_SubtractVectors(&normal, &vertices[0], &vertices[3]); break;
        case 2:
            corners[0] = &vertices[7]; corners[1] = &vertices[4];
            corners[2] = &vertices[0]; corners[3] = &vertices[3];
            Particle_SubtractVectors(&normal, &vertices[3], &vertices[2]); break;
        case 3:
            corners[0] = &vertices[6]; corners[1] = &vertices[7];
            corners[2] = &vertices[3]; corners[3] = &vertices[2];
            Particle_SubtractVectors(&normal, &vertices[2], &vertices[1]); break;
        case 4:
            corners[0] = &vertices[5]; corners[1] = &vertices[6];
            corners[2] = &vertices[2]; corners[3] = &vertices[1];
            Particle_SubtractVectors(&normal, &vertices[1], &vertices[0]); break;
        case 5:
            corners[0] = &vertices[0]; corners[1] = &vertices[1];
            corners[2] = &vertices[2]; corners[3] = &vertices[3];
            Particle_SubtractVectors(&normal, &vertices[3], &vertices[7]); break;
        }
        denominator = (normal.x * ray->direction.x + normal.y * ray->direction.y + normal.z * ray->direction.z);
        if (denominator == 0.0f) continue;
        Particle_SubtractVectors(&delta, origin, corners[0]);
        distance = (delta.x * normal.x + delta.y * normal.y + delta.z * normal.z);
        if (distance == 0.0f) continue;
        fraction = -distance / denominator;
        if (!(fraction < ray->nearest.t)) continue;
        hit.x = origin->x + fraction * ray->direction.x;
        hit.y = origin->y + fraction * ray->direction.y;
        hit.z = origin->z + fraction * ray->direction.z;
        inside = 1;
        for (i = 0; i < 4; i++) {
            next = i == 3 ? 0 : i + 1;
            current = corners[i];
            Particle_SubtractVectors(&edge, corners[next], current);
            Particle_SubtractVectors(&offset, &hit, current);
            if ((edge.x * offset.x + edge.y * offset.y + edge.z * offset.z) < 0.0f) { inside = 0; break; }
        }
        if (!inside) continue;
        if (func_8024E2C4_de(actor)) polygon.kind = ray->material->alternateKind;
        else polygon.kind = ray->material->kind;
        polygon.type = 8;
        polygon.response = ray->material->response;
        polygon.count = 0; polygon.flags = 0;
        polygon.normal = normal; polygon.valid = 1; polygon.point = *corners[0];
        if (!func_8023E8D4_de(ray, &polygon, 1)) continue;
        ray->nearest.actor = actor; ray->nearest.index = index;
        if (transform) ray->nearest.transform = *transform;
        found = 1;
        projectile = ray->projectile;
        if (projectile->type != 2 || (projectile->kind != 0x414 && projectile->kind != 0x42D)) continue;
        if (projectile->owner == actor) {
            func_8044A07C_de(actor->widget);
            ray->projectile->contactState = found;
            return 0;
        }
        if (projectile->lastHit == actor) continue;
        projectile->lastHit = actor;
        ray->projectile->ticks = 0;
        func_80271FC8_de(&effectPosition, ray->nearest.t, &ray->projectile->position, &ray->end);
        style.kind = 5; style.flags = 0x2300; style.mode = 5;
        style.red = ray->projectile->color.x;
        style.green = ray->projectile->color.y;
        style.blue = ray->projectile->color.z;
        func_80265E10_de(actor, ray->projectile, 2, -1, effectPosition, style);
        if (*actor->kind == 11 && ray->projectile->kind == 0x42D) {
            func_802833D0_de(ray->projectile);
            func_8022B730_de(actor, 2.0f);
        }
    }
    return found;
}
