#include "span_1000/code_80213ED4.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8027A0F4.h"
#include "TYPES.H"

extern AudioStateA4 D_801468A0;

extern s32 func_8022C460_de(void *arg0);
extern void func_8022B69C_de(void *arg0, f32 arg1, void *arg2);
extern void func_8022B550_de(void *arg0, f32 arg1, f32 arg2, void *arg3,
                          s32 arg4);
extern void func_8022B60C_de(void *arg0, f32 arg1, void *arg2);
extern void func_8022B7F8_de(void *arg0, void *arg1);
extern void func_802227F4_de(void *, void *, s32);

void func_8021C45C_de(void *arg0, void *arg1, s32 arg2, void *arg3) {
    Player *actor = arg0;
    Shared_Particle *event = arg3;
    AudioStateA4 *audio;
    u16 type;

    if (actor->health == 0) {
        return;
    }
    if (func_8022C460_de(actor) != 0) {
        return;
    }
    if (actor->damageCooldown > 0.0f) {
        return;
    }
    audio = &D_801468A0;
    if (audio->field98 != 0 &&
        actor->profile->character == 0xB &&
        audio->fieldA0 > 0) {
        return;
    }
    if (actor->reactionFlags & 0x8000) {
        return;
    }

    type = event->inst.type;
    switch (type) {
    case 0x3FB:
    case 0x4CD:
        func_8022B69C_de(actor, 0.1f, event->owner);
        return;
    case 0x3FD:
    case 0x4CF:
        func_8022B69C_de(actor, 0.125f, event->owner);
        return;
    case 0x3FE:
    case 0x4D0:
        func_8022B69C_de(actor, 0.3f, event->owner);
        return;
    case 0x432:
    case 0x4E3:
        func_8022B550_de(actor, 80.0f, 2.0f, event->owner, 1);
        return;
    case 0x408:
    case 0x4E0:
        func_8022B60C_de(actor, 0.25f, event->owner);
        return;
    case 0x419:
    case 0x4D3:
        func_8022B7F8_de(actor, event->owner);
        return;
    case 0x129:
        actor->cooldown = 0;
        actor->pending = 0;
        if (!(actor->reactionFlags & 0x8000)) {
            if (actor->reactionOwner == 0) {
                actor->reactionOwner = event->owner;
            }
            func_802227F4_de(actor, actor, 0x26);
        }
        return;
    }
}

