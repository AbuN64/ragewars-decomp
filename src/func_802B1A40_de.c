#include "span_1000/code_802B0388.h"
#include "types.h"

/* Initialize one channel of the sequence player's channel table. */
void func_802B1A40_de(void *arg0, s32 index) {
    ALSeqPlayer *player = arg0;

    player->chanState[index].fxId = 0;
    player->chanState[index].fxmix = 0;
    player->chanState[index].pan = 0x40;
    player->chanState[index].vol = 0x7F;
    player->chanState[index].priority = 5;
    player->chanState[index].sustain = 0;
    player->chanState[index].bendRange = 0xC8;
    player->chanState[index].pitchBend = D_800C74D0_de;
}
