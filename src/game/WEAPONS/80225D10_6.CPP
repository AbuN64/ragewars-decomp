#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/OBJRECV5.H"
#include "COMMON/TRIPLE.H"
#include "FX_2/80271B18.H"

static inline s32 playerHasForce(ForcePlayer *player, f32 zero) { s32 value = 0; if (zero < player->strength) value = 1; return value; }
void func_80228DC4_de(void *listObject, void *bodyObject) {
    ForcePlayerList *list = listObject;
    ForceBody *body = bodyObject;
    ForcePlayer *player;
    s32 changed;
    CVector3 delta, direction;
    f32 distance, force, dot;
    f32 one, zero;
    player = list->head;
    changed = 0;
    if (player != 0) {
        zero = 0.0f;
        one = D_800C2C14_de;
    do {
        if (player->active != 0 && playerHasForce(player, zero)) {
            Particle_SubtractVectors(&delta, &player->origin, &body->position);
            distance = (delta.x * delta.x + delta.y * delta.y) + delta.z * delta.z;
            Particle_NormalizeVec3(&delta);
            changed = 1;
            if (D_800C2C18_de < distance) {
                force = D_800C2C1C_de / distance;
                if (D_800D2988 < one) force *= D_800D2988;
                if (player->attract == 0) force = -force;
                direction = body->velocity;
                Particle_NormalizeVec3(&direction);
                dot = delta.x * direction.x + delta.y * direction.y;
                dot += delta.z * direction.z;
                if (dot < zero) dot = -dot;
                dot += one;
                dot *= D_800C2C20_de;
                force *= dot;
                Particle_ScaleVector(&delta, &delta, force);
            }
            Particle_AddVec3(&body->velocity, &body->velocity, &delta);
        }
        player = player->next;
    } while (player != 0);
    }
    if (changed != 0) {
        delta = body->velocity;
        Particle_NormalizeVec3(&delta);
        body->direction = delta;
    }
}
