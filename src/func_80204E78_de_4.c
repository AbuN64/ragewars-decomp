#include "span_1000/code_80204E78.h"
#include "types.h"
/* Applies a hit to a damageable object: when its descriptor at 0x18 takes the hit (flag 1 for hits
   without bit 0x200, flag 2 for hits with it) it lowers the health at 0x4 by the damage, not below
   zero, turns the remaining percentage into the damage stage with the lowest threshold above it to set
   the model and time at 0x124 and 0x128 and the stage byte, and runs func_80214178_de (kind 2 when the
   descriptor has flag 0x40, else 1) once the health reaches zero. */











extern void func_80214178_de(Damageable *obj, Health *health, s32 kind);

void func_802050C0_eu(Damageable *obj, Health *health, Hit *hit)
{
    s32 canHit = 0;
    s32 flags;
    s32 remaining;
    u8 percent;
    u8 best;
    s32 bestIndex;
    s32 i;
    s32 kind;
    Damage *damage;

    flags = obj->desc->damage.flags;
    damage = &obj->desc->damage;
    bestIndex = canHit;
    if (flags & 1) {
        canHit = ((hit->flags >> 9) ^ 1) & 1;
    }
    if ((flags & 2) && (hit->flags & 0x200)) {
        canHit = 1;
    }
    if (canHit) {
        remaining = health->health - hit->damage;
        if (remaining < 0) {
            remaining = 0;
        }
        best = 100;
        health->health = remaining;
        percent = ((f32)remaining / (f32)health->maxHealth) * 100.0f;
        for (i = 0; i < 4; i++) {
            if (damage->threshold[i] < best && damage->threshold[i] != 0 &&
                percent < damage->threshold[i]) {
                best = damage->threshold[i];
                bestIndex = i;
            }
        }
        health->model = damage->model[bestIndex];
        health->time = damage->time[bestIndex];
        obj->stage = damage->model[bestIndex];
        if (health->health == 0) {
            kind = 1;
            if (obj->desc->damage.flags & 0x40) {
                kind = 2;
            }
            func_80214178_de(obj, health, kind);
        }
    }
}
