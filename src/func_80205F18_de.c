#include "span_1000/code_80204E78.h"
#include "types.h"





extern u8 D_801462E5[];
extern u8 D_80142226;
extern f32 D_800C1AC8_de;


extern void func_80214178_de(Actor_func_80205F18_de *actor, Action *action, s32 arg2);
/* Starts an eligible actor action with a random delay and descriptor duration, applies its flags and callback, then clears the pending flag when required. */
void func_80205F18_de(Actor_func_80205F18_de *actor, Action *action) {
    ActionInfo *info = &actor->desc->info;
    if ((info->flags & 0x10) && (D_801462E5[0] == 0 || D_801462E5[1] != 1)) {
        actor->flags &= ~0x100;
        return;
    }
    action->delay = func_80274A90_de(D_800C1AC8_de, D_800C1ACC_de);
    action->timer = 0;
    action->duration = info->duration;
    if (actor->model == 0x644 || (info->flags & 8)) actor->flags &= ~0x2000;
    func_80214178_de(actor, action, 0);
    if (!(info->flags & 0x10) || D_80142226 == 1) return;
    actor->flags &= ~0x100;
}
