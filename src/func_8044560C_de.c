#include "span_16E000/code_804453C4.h"
#include "types.h"

/* Sets a player state to 2, then in multiplayer (D_801462E5) clears and otherwise sets bit 0x800000 in both of its actor's visibility masks at 0x80 and 0xA8, and refreshes the audio state through func_8025CC6C_de and func_8025CAB0_de with that mask. */





extern u8 D_801462E5;
extern void func_802648C8_de(void);
extern s32 func_8025CC6C_de(s32 mask);
extern void func_8025CAB0_de(s32 value);

void func_8044560C_de(PlayerRecAtC *player) {
    s32 mask;

    player->state = 2;
    func_802648C8_de();
    mask = 0x800000;
    if (D_801462E5 != 0) {
        mask = 0xFF7FFFFF;
        player->actor->mask80 &= mask;
        player->actor->maskA8 &= mask;
    } else {
        player->actor->mask80 |= mask;
        player->actor->maskA8 |= mask;
    }
    func_8025CAB0_de(func_8025CC6C_de(mask));
}

/* Calls func_8026495C_de and nothing else. */
extern void func_8026495C_de();

void func_8044569C_de(void) {
    func_8026495C_de();
}

/* Calls func_804415F4_de and nothing else. */
extern void func_804415F4_de();

void func_804456B8_de(void) {
    func_804415F4_de();
}
