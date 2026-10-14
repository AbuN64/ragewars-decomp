#include "shared/level_actor.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022D944.h"
#include "types.h"
/* Eases a player's crouch depth at 0x718: the target is D_800C7ED0[0] while input bits 0xC0000 are
   held or crouching is forced at 0x71C (which also enters state 4 unless already in it) and zero
   otherwise; the depth moves a quarter of the way through func_80274870_de, steps smaller than
   D_800C7ED0[1] downward or D_800C7ED8[0] upward are dropped, and bit 0x80 of the flags is set while
   D_800C7ED8[1] less the depth lies within D_800C7EE0 to (&D_800C7EE0)[1], cleared otherwise. */

extern f32 D_800C7ED0[];
extern f32 D_800C7ED8[];

extern s32 func_802227F4_de(void *, void *, s32);
extern void func_80274870_de(f32 *value, f32 target, f32 rate);






void func_8022DC44_de(Player *arg0, LevelActor *arg1, s32 unused, s32 *flags) {
    s32 held;
    s32 crouch;
    f32 target;
    f32 depth;
    f32 step;
    f32 clearance;
    f32 moved;
    f32 lo;

    held = arg1->motionState & 0xC0000;
    crouch = held != 0;
    if (arg0->forceCrouch != 0) {
        crouch = 1;
        if (arg0->pose != 4) {
            func_802227F4_de(arg0, arg1, 4);
        }
    }
    target = 0.0f;
    if (crouch) {
        target = D_800C7ED0[0];
    }
    depth = arg0->crouchDepth;
    func_80274870_de(&depth, target, 0.25f);
    do {
        step = depth - arg0->crouchDepth;
        if (step < 0.0f) {
            if (-step < D_800C7ED0[1]) {
                goto still;
            }
        } else if (step < D_800C7ED8[0]) {
        still:
            step = 0.0f;
        }
        moved = arg0->crouchDepth + step;
        clearance = D_800C7ED8[1] - moved;
        lo = D_800C7EE0;
    } while (0);
    arg0->crouchDepth = moved;
    if (lo <= clearance && clearance <= (&D_800C7EE0)[1]) {
        *flags |= 0x80;
    } else {
        *flags &= ~0x80;
    }
}
