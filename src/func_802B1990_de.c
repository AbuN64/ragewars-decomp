#include "span_1000/code_802B0388.h"
#include "types.h"






void func_802B1990_de(void *arg0) {
    ALSeqPlayer_func_802B0C94_de *player = arg0;
    s32 i;
    s32 off;
    s32 c40, c7f, c5, cc8;
    f32 val;

    i = 0;
    if (player->maxChannels != 0) {
        c40 = 0x40;
        c7f = 0x7F;
        c5 = 5;
        cc8 = 0xC8;
        val = D_800C74CC_de;
        do {
            off = i << 4;
            player->chanState[i].instrument = 0;
            player->chanState[i].fxId = 0;
            player->chanState[i].fxmix = 0;
            player->chanState[i].pan = (u8) c40;
            player->chanState[i].vol = (u8) c7f;
            player->chanState[i].priority = (u8) c5;
            player->chanState[i].sustain = 0;
            player->chanState[i].bendRange = (u16) cc8;
            player->chanState[i].pitchBend = val;
            i += 1;
        } while (i < (s32) player->maxChannels);
    }
}
