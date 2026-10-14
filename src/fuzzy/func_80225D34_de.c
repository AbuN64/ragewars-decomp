#include "types.h"

typedef struct { f32 x, y, z; } Position;
typedef struct { u8 pad0[0x34]; Position pos; f32 height; u8 pad44[0x1A]; u8 duration; } TravelTarget;
typedef struct { u8 pad0[0x6C]; f32 yaw; u8 pad70[0x2E4]; f32 bodyYaw; u8 pad358[0x390]; Position pos; u8 pad6F4[0x100]; f32 elapsed, targetYaw; TravelTarget *target; Position start; } Player;
extern f32 D_800D2988;
extern f32 D_800C2AE0_de, D_800C2AE4_de, D_800C2AE8_de, D_800C2AEC_de, D_800C2AF0_de;
extern u8 D_800CE7E4[];
extern void func_802231D4_de(void *, void *, void *);
extern void func_802227F4_de(void *, void *, s32);

void func_80225D34_de(Player *player, void *body) {
    f32 yaw, targetYaw, distance, otherDistance, alternate, duration, t;
    Position pos;
    func_802231D4_de(player, body, D_800CE7E4);
    if (player->target != 0) {
        player->elapsed += D_800D2988;
        yaw = player->yaw;
        targetYaw = player->targetYaw;
        if (targetYaw != yaw) {
            func_80274020_de(&yaw);
            func_80274020_de(&targetYaw);
            if (yaw > targetYaw) {
                alternate = targetYaw + D_800C2AE0_de;
                distance = yaw - targetYaw;
                otherDistance = alternate - yaw;
            } else {
                alternate = targetYaw - D_800C2AE4_de;
                distance = targetYaw - yaw;
                otherDistance = yaw - alternate;
            }
            if (otherDistance < distance) targetYaw = alternate;
            if (yaw < targetYaw ?
                (yaw += (targetYaw - yaw) * D_800C2AE8_de, targetYaw < yaw) :
                (yaw -= (yaw - targetYaw) * D_800C2AEC_de, yaw < targetYaw)) yaw = targetYaw;
            func_80274020_de(&yaw);
        }
        player->bodyYaw = yaw;
        player->yaw = yaw;
        duration = (f32)(player->target->duration * 15);
        if (player->elapsed < duration) {
            t = player->elapsed / duration;
            pos.x = player->start.x + (player->target->pos.x - player->start.x) * t;
            pos.z = player->start.z + (player->target->pos.z - player->start.z) * t;
            pos.y = player->start.y + (player->target->pos.y - player->start.y) * t + player->target->height * ((t - t * t) * D_800C2AF0_de);
            player->pos = pos;
            return;
        }
    }
    func_802227F4_de(player, body, 2);
}
