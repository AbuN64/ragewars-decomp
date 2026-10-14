#include "types.h"

typedef struct HealingActor {
    u8 pad[0x5E4];
    s32 health;
    u8 pad5E8[0x258];
    f32 recoveryTime;
    u8 pad844[4];
    s32 recovering;
} HealingActor;

extern f32 D_800D2988;
extern f32 D_800C2D20_de;
extern f32 D_800C2D24_de;
extern s32 func_8021BFC4_de(HealingActor *, void *, s32, s32, s32);

void func_8022BE20_de(HealingActor *actor, void *source) {
    f32 elapsed = actor->recoveryTime + D_800D2988;
    s32 missing;
    s32 amount;

    actor->recoveryTime = elapsed;
    if (D_800C2D20_de < elapsed) {
        missing = 150 - (actor->health >> 8);
        amount = 1;
        if (missing > 0) {
            missing /= 15;
            if (missing > 0) {
                amount = missing;
            }
        }
        actor->recovering = 1;
        func_8021BFC4_de(actor, source, amount << 8, 0, 0x1F);
        actor->recoveryTime = actor->recoveryTime - D_800C2D24_de;
    }
}
