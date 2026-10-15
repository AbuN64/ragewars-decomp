#include "span_1000/code_80204E78.h"
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"

void func_802050A0_de(Damageable *obj, Health *health, Hit *hit)
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
