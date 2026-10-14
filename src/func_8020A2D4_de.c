#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80209AE8.h"
#include "types.h"
/* Runs a computer player's engagement timer: while the countdown at 0x2E4 is positive it rerolls the
   wait at 0x2E8 as the config's base at 8 plus a random share (scale D_800C6E00) of its spread at 0xC
   and counts down; at zero it counts the opponents in range through func_80283228_de (three counting as
   the whole wait) and either flags waiting at 0x23C while fewer than the wait or starts pursuit with
   the countdown at -1 and a wait from the config's 0x24 and 0x28 (scale D_800C6E04); during pursuit
   the wait runs down, ends early once the player is within D_800C6E08 of its target on the target's
   height, and when it reaches zero flags 0x240 and acts through func_8020A95C_de. Written in the style of
   func_8020A458_de with the random scale loaded into a local first. */






extern char D_8011D8D0;

extern s32 func_80283228_de(char *, void *);
extern void func_80284FF4_de(char *, void *, Vec3 *);
extern f32 func_802726BC_de(Vec3 *, Vec3 *);











void func_8020A2D4_de(void *arg0, void *config) {
    s32 count;
    char *target;
    Vec3 pos;
    f32 range;
    f32 scale;

    if (((ObjectLinks2EC *)(arg0))->unk_2E4 > 0) {
        scale = D_800C6E00;
        ((ObjectLinks2EC *)(arg0))->unk_2E8 = ((IntegerState2C *)(config))->unk_8;
        ((ObjectLinks2EC *)(arg0))->unk_2E8 =
            (f32) ((ObjectLinks2EC *)(arg0))->unk_2E8
            + func_80274564_de(scale) * (f32) ((IntegerState2C *)(config))->unk_C;
        ((ObjectLinks2EC *)(arg0))->unk_2E4 -= 1;
        return;
    }
    if (((ObjectLinks2EC *)(arg0))->unk_2E4 == 0) {
        count = func_80283228_de(&D_8011D8D0, *(void **) arg0);
        if (count == 3) {
            ((ObjectLinks2EC *)(arg0))->unk_2E8 = count;
        }
        if (count < ((ObjectLinks2EC *)(arg0))->unk_2E8) {
            ((ObjectLinks2EC *)(arg0))->unk_23C = 1;
            return;
        }
        ((ObjectLinks2EC *)(arg0))->unk_2E4 = -1;
        scale = D_800C6E04;
        ((ObjectLinks2EC *)(arg0))->unk_2E8 = ((IntegerState2C *)(config))->unk_24;
        ((ObjectLinks2EC *)(arg0))->unk_2E8 =
            (f32) ((ObjectLinks2EC *)(arg0))->unk_2E8
            + func_80274564_de(scale) * (f32) ((IntegerState2C *)(config))->unk_28;
        return;
    }
    ((ObjectLinks2EC *)(arg0))->unk_2E8 -= 1;
    target = ((struct ObjRecAt1D8V2 *) ((ObjectLinks2EC *) arg0)->unk_64)->unk1D8;
    func_80284FF4_de(&D_8011D8D0, *(void **) arg0, &pos);
    range = D_800C6E08;
    pos.y = ((Player *)target)->pos.y;
    if (func_802726BC_de(&pos, &((Player *)(target))->pos) < range) {
        ((ObjectLinks2EC *)(arg0))->unk_2E8 = 0;
    }
    if (((ObjectLinks2EC *)(arg0))->unk_2E8 == 0) {
        ((ObjectLinks2EC *)(arg0))->unk_240 = 1;
        func_8020A95C_de(arg0, config);
    }
}
