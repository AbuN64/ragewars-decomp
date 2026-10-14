#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022BA90.h"
#include "types.h"
/* Drains a player's ammunition over time: unless func_80245784_de reports a pause, func_8022C460_de blocks
   the player, D_801371DC is set, bit 1 of D_801462C8 is set or the player's state is below 2, it
   advances the tick counter at 0x84C modulo the period (a fifth of it while 0x80C is set), counting
   only kind 0x20 while the value at 0x670 is positive, and on each wrap takes one from each of the
   three slot counts at 0x5F4 without going below zero. Written from its own assembly with early
   returns and a clamp-at-zero decrement. */
extern s32 D_801462C8;
extern s32 func_80245784_de(void);
extern s32 func_8022C460_de(void *);
void func_8022BF04_de(void *arg0, s32 unused, s32 period, s32 kind) {
    s32 tick;
    if (func_80245784_de() != 0) {
        return;
    }
    if (func_8022C460_de(arg0) != 0) {
        return;
    }
    if (D_801371DC != 0) {
        return;
    }
    if (D_801462C8 & 1) {
        return;
    }
    if ((u16)(((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view650_15.unk650) < 2) {
        return;
    }
    if (((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view80C_107.unk80C != 0) {
        period /= 5;
    }
    if (((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view670_30.unk670 > 0.0f && kind != 0x20) {
        return;
    }
    tick = (((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view84C_149.unk84C + 1) % period;
    ((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view84C_149.unk84C = tick;
    if (tick != 0) {
        return;
    }
    ((((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view5F4_11.unk5F4[0]) = ((((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view5F4_11.unk5F4[0]) - 1 < 0) ? 0 : (((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view5F4_11.unk5F4[0]) - 1);
    ((((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view5F4_11.unk5F4[1]) = ((((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view5F4_11.unk5F4[1]) - 1 < 0) ? 0 : (((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view5F4_11.unk5F4[1]) - 1);
    ((((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view5F4_11.unk5F4[2]) = ((((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view5F4_11.unk5F4[2]) - 1 < 0) ? 0 : (((SharedPlayer_func_80209CD8_de *)(arg0))->views5E8.view5F4_11.unk5F4[2]) - 1);
}
