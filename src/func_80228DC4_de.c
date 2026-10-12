#include "types.h"

#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "span_1000/code_80225D10.h"
#include "span_C76B0/data.h"
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_8027207C_de(f32 *);
extern void func_80271F9C_de(void *, void *, f32);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);

static inline s32 playerHasForce(ForcePlayer *player, f32 zero) { s32 value = 0; if (zero < player->strength) value = 1; return value; }
void func_80228DC4_de(void *listObject, void *bodyObject) {
    ForcePlayerList *list = listObject;
    ForceBody *body = bodyObject;
    ForcePlayer *player;
    s32 changed;
    Vec3 delta, direction;
    f32 distance, force, dot;
    f32 one, zero;
    player = list->head;
    changed = 0;
    if (player != 0) {
        zero = 0.0f;
        one = D_800C2C14_de;
    do {
        if (player->active != 0 && playerHasForce(player, zero)) {
            func_80271F68_de(&delta, &player->origin, &body->position);
            distance = (delta.x * delta.x + delta.y * delta.y) + delta.z * delta.z;
            func_8027207C_de(&delta.x);
            changed = 1;
            if (D_800C2C18_de < distance) {
                force = D_800C2C1C_de / distance;
                if (D_800D2988 < one) force *= D_800D2988;
                if (player->attract == 0) force = -force;
                direction = body->velocity;
                func_8027207C_de(&direction.x);
                dot = delta.x * direction.x + delta.y * direction.y;
                dot += delta.z * direction.z;
                if (dot < zero) dot = -dot;
                dot += one;
                dot *= D_800C2C20_de;
                force *= dot;
                func_80271F9C_de(&delta, &delta, force);
            }
            func_80271F34_de(&body->velocity, &body->velocity, &delta);
        }
        player = player->next;
    } while (player != 0);
    }
    if (changed != 0) {
        delta = body->velocity;
        func_8027207C_de(&delta.x);
        body->direction = delta;
    }
}
