#include "span_1000/code_802B0388.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE028.h"
#include "types.h"



extern s32 func_802AE9B0_de(s32 arg0, s32 *arg1);
extern void func_802B00D4_de(ALEventQueue *, Message_func_802AF150_de *, s32);




void func_802AFD00_de(void *arg0) {
    struct ALSeqPlayer_func_802B0C94_de *player = arg0;
    Message_func_802AF150_de sp10;
    s32 sp20;
    s32 field18;

    if (player->state == 1) {
        field18 = (s32)player->target;
        if (field18 != 0 && (func_802AE9B0_de(field18, &sp20) & 0xFF)) {
            sp10.type = 0;
            func_802B00D4_de(&player->evtq, &sp10, sp20 * player->uspt);
        }
    }
}
