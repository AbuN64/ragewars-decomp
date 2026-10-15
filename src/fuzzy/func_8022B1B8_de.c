#include "types.h"
#include "common/types_8a8189af7b05.h"
typedef struct TogglePlayer { u8 pad0[0x5dc]; void *owner; u8 pad5e0[0xc1c]; f32 timer; Vec3 position; s32 mode; u8 pad1210[0x248]; Vec3 source; u8 pad1464[0xc]; Vec3 direction; s32 enabled; u8 pad1480[0x180]; u8 matrix[0x40]; } TogglePlayer;
extern f32 D_800C2D0C_de;
extern void *D_800D311C,*D_800D3120,*D_800D3124;
#include "shared/menu_match_globals.h"
extern void func_8025DF34_de(s32);
extern void func_80273198_de(f32 *,Vec3 *);
extern void func_80271F9C_de(Vec3 *,Vec3 *,f32);
extern void func_80271F34_de(Vec3 *,Vec3 *,Vec3 *);
extern void func_80273448_de(f32 *,f32,f32,f32);
extern void func_80273D6C_de(f32 *);
extern void func_8027027C_de(f32 *,void *);
extern void func_80237E80_de(void *,void *,void *);
void func_8022B1B8_de(TogglePlayer *player,s32 mode) {
    f32 matrix[16];
    Vec3 position;
    void *owner,*message;
    if (player->enabled != 0) {
        if (player->timer > 0.0f) {
            player->timer = 0;
            func_8025DF34_de(0x578);
            owner = player->owner;
            if (owner == 0) return;
            message = D_800D311C;
        } else {
            player->position = player->source;
            player->mode = mode;
            player->timer = D_800C2D0C_de;
            func_80273198_de(matrix,&player->direction);
            func_80271F9C_de(&position,&player->direction,5.12f);
            func_80271F34_de(&position,&position,&player->position);
            func_80273448_de(matrix,position.x,position.y,position.z);
            func_80273D6C_de(matrix);
            func_8027027C_de(matrix,player->matrix);
            func_8025DF34_de(0x578);
            owner = player->owner;
            if (owner == 0) return;
            message = D_800D3124;
            if (mode != 0) message = D_800D3120;
        }
        func_80237E80_de(&D_80145088,owner,message);
    }
}
