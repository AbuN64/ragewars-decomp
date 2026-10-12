#include "types.h"

typedef struct { f32 x, y, z; } Vector;
typedef struct Player Player;
struct Player { u8 pad0[0x5D0]; s32 active; u8 pad5D4[0xC28]; f32 strength; Vector origin; s32 attract; u8 pad1210[0x4D0]; Player *next; };
typedef struct { u8 pad0[0x20]; Player *head; } PlayerList;
typedef struct { u8 pad0[8]; Vector position; u8 pad14[8]; Vector velocity; u8 pad28[0x14C]; Vector direction; } Body;
extern f32 D_800D2988, D_800C2C14_de, D_800C2C18_de, D_800C2C1C_de, D_800C2C20_de;
extern void func_80271F68_de(Vector *, Vector *, Vector *);
extern void func_8027207C_de(Vector *);
extern void func_80271F9C_de(Vector *, Vector *, f32);
extern void func_80271F34_de(Vector *, Vector *, Vector *);

void func_80228DC4_de(PlayerList *list, Body *body) {
    Player *player;
    s32 changed;
    Vector delta, direction;
    f32 distance, force, dot;
    player = list->head;
    changed = 0;
    while (player != 0) {
        if (player->active != 0 && 0.0f < player->strength) {
            func_80271F68_de(&delta, &player->origin, &body->position);
            distance = (delta.x * delta.x + delta.y * delta.y) + delta.z * delta.z;
            func_8027207C_de(&delta);
            changed = 1;
            if (D_800C2C18_de < distance) {
                force = D_800C2C1C_de / distance;
                if (D_800D2988 < D_800C2C14_de) force *= D_800D2988;
                if (player->attract == 0) force = -force;
                direction = body->velocity;
                func_8027207C_de(&direction);
                dot = (delta.x * direction.x + delta.y * direction.y) + delta.z * direction.z;
                if (dot < 0.0f) dot = -dot;
                dot = (dot + D_800C2C14_de) * D_800C2C20_de;
                force *= dot;
                func_80271F9C_de(&delta, &delta, force);
            }
            func_80271F34_de(&body->velocity, &body->velocity, &delta);
        }
        player = player->next;
    }
    if (changed != 0) {
        delta = body->velocity;
        func_8027207C_de(&delta);
        body->direction = delta;
    }
}
