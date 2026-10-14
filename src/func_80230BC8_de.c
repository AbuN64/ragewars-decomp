#include "common/unused.h"
#include "shared/gameplay_transition.h"
#include "span_1000/code_8022C894.h"
#include "shared/gameplay_round_rules.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022F3E8.h"
#include "types.h"
/* Advances a player's second charging action: when the trigger is released (as in func_802312C8_de) or the
 * cooldown is past D_800C8008, it switches to action 2, runs func_8022AF40_de and func_8022B00C_de, plays sound
 * 0x794 at the player's target or position and pushes the charge at 0x128 by the release amount; otherwise
 * it grows the charge by the charge rate and each time the cue timer at 0x64 runs out adds the cue period
 * back and plays the charge cue (0x3F9 in a multiplayer match without controller, 0x4CB otherwise).
 * Adapted from func_802312C8_de. */



extern s32 D_800CA2D8_de;
extern f32 D_800D2988;
extern s32 D_80140FF8;
extern void func_80214178_de(void *, void *, s32);

extern void func_8022AF40_de(void *);

extern s32 func_8025DE54_de(s16, Vec3, void *, s32);
extern void func_80274870_de(f32 *, f32, f32);


















static inline s32 released(void *actor, char *player) {
    char *control;
    s32 latch;

    if (((Actor_func_8022D290_de *)player)->unk_0x11D8 > D_800C8008) {
        return 1;
    }
    if ((((Actor_func_8024A7A0_de *)actor)->flags & 0x300000) && ((Actor_func_8022D290_de *)player)->unk_0x1450 != 0) {
        control = ((Actor_func_8022D290_de *)player)->unk_0x1454;
        latch = ((Brain_func_80212D78_eu_x *)control)->triggerLatch;
        ((Brain_func_80212D78_eu_x *)control)->triggerLatch = 0;
        return latch == 0;
    }
    if (!(((Actor_func_8022D290_de *)player)->unk_0x06AC & 0x2000)) {
        return 1;
    }
    if (((Actor_func_8022D290_de *)player)->unk_0x11B4 != 0) {
        return 1;
    }
    return func_80222AA4_de(player, ((Actor_func_8022D290_de *)player)->unk_0x062E) == 0;
}

void func_80230BC8_de(void *actor, void *attack) {
    char *player;
    Vec3 *position;
    char *target;

    player = ((Actor_func_8024A7A0_de *)actor)->controller;
    target = ((Actor_func_8022D290_de *)player)->unk_0x05DC;
    if (target != 0) {
        position = &((SharedRecAt564V1 *)target)->position;
    } else {
        position = &((Shared_ActorView *)player)->position.vector;
    }
    if (released(actor, player)) {
        func_80214178_de(actor, attack, 2);
        func_8022AF40_de(player);
        func_8022B00C_de(player);
        func_8025DE54_de(0x794, *position, position, -1);
        func_80274870_de(&((Dest *)attack)->charge, (f32)D_800CA2D8_de * D_800C2F1C_de, 0.4f);
        return;
    }
    func_80274870_de(&((Dest *)attack)->charge, (f32)D_800CA2D8_de * D_800C2F20_de, 0.4f);
    ((Dest *)attack)->cueTimer -= D_800D2988;
    if (((Dest *)attack)->cueTimer <= 0.0f) {
        ((Dest *)attack)->cueTimer += D_800C2F24_de;
        if (((Actor_func_8022D290_de *)player)->unk_0x1450 == 0 && D_80140FF8 == 1) {
            func_8021A9A4_de(((Actor_func_8024A7A0_de *)actor)->controller, 0x3F9);
        } else {
            func_8021A9A4_de(((Actor_func_8024A7A0_de *)actor)->controller, 0x4CB);
        }
    }
}
