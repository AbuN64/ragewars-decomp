#include "shared/level_actor.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022C894.h"
#include "types.h"
/* Runs a player's landing state: sets state 0xD when the value at 0x6C8 is zero or 0xE otherwise,
   applies the movement tables D_800CE88C and D_800CE8A4, picks animation 0x8A2 for the model
   D_800CE47C or, unless animation 0x1144 is still running with the byte at 0x10E clear, 0x8A2, 0x8A7
   or 0x14 by the stick at 0x6C0 against D_800C7E94 and D_800C7E98, and switches to state 3 once the
   timer at 0x658 passes D_800C7E9C without input bit 0x20000. */

extern void func_802231D4_de(void *, void *, void *);
extern void func_802238E0_de(void *, void *, void *);
extern s32 func_802227F4_de(void *, void *, s32);
extern char D_800CE88C;
extern char D_800CE8A4;










void func_8022D040_de(void *arg0, Actor_func_8024A7A0_de *arg1) {
    Player *player;
    s32 busy;
    f32 x;

    player = arg0;
    if (player->landing == 0.0f) {
        player->pose = 0xD;
    } else {
        player->pose = 0xE;
    }
    func_802231D4_de(player, arg1, &D_800CE88C);
    func_802238E0_de(player, arg1, &D_800CE8A4);
    busy = 0;
    if (player->animation == 0x1144) {
        busy = player->animationDone == 0;
    }
    if (player->objectId == D_800CE47C) {
        player->animation = 0x8A2;
    } else if (!busy) {
        x = player->stick;
        if (D_800C7E94 <= x) {
            player->animation = 0x8A2;
        } else if (x <= D_800C7E98) {
            player->animation = 0x8A7;
        } else {
            player->animation = 0x14;
        }
    }
    if (!(arg1->motionState & 0x20000) && player->poseTimer > D_800C7E9C) {
        func_802227F4_de(player, arg1, 3);
    }
}
