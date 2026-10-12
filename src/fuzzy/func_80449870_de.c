#include "types.h"
#include "shared/func_80425674_de_layout.h"
typedef struct { u8 pad0[0x8F]; u8 active; } Info_u1;
typedef struct {
    u8 pad0[0x10E]; s8 mode; u8 pad10F[0x4C9]; Info_u1 *info;
    u8 pad5DC[0x10]; s32 unk5EC; u8 pad5F0[0xD4C];
    s32 timer; s32 state; u8 pad1344[0x10C]; s32 disabled;
} Actor_u1;
extern Shared_Game D_801462C8;
extern s32 D_80145048;
extern u8 D_80145040[];
extern void func_8022A748_de(void *);
extern void func_8021B1E4_de(Actor_u1 *, s32, s32, s32);
extern void func_8044952C_de(Actor_u1 *);
extern void func_802227F4_de(Actor_u1 *, Actor_u1 *, s32);

void func_80449870_de(Actor_u1 *actor)
{
    s32 option = ((D_80145048 < 2) ^ 1) << 1;
    if (!(D_801462C8.flags & 2) || D_801462C8.local) {
        if ((D_801462C8.controllerMode == 1 || D_801462C8.controllerMode == 4) && actor->disabled == 0) {
            if (actor->timer > 0) actor->timer--;
            if (actor->timer == 0) {
                D_801462C8.humanWon = 0;
                func_8022A748_de(D_80145040);
            }
        }
    }
    if ((D_801462C8.controllerMode == 1 || D_801462C8.controllerMode == 4) && actor->disabled == 0) {
        if (actor->timer > 0) {
            func_8021B1E4_de(actor, actor->unk5EC, option, 1);
            func_8044952C_de(actor);
            actor->state = 0;
            return;
        }
        if (D_801462C8.local && actor->mode == 0 && actor->info->active == 0) return;
    }
    func_802227F4_de(actor, actor, 0x12);
    actor->state = 0;
}
