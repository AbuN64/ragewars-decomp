#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802AE028.h"
#include "types.h"
#include "span_1000/code_802B0388.h"






void func_802AFDFC_de(void *arg0, f32 arg1) {
    ALSeqPlayer *player = arg0;
    ALCSeq_s *temp_v0;

    temp_v0 = player->target;
    if (temp_v0 != 0) {
        player->uspt = (s32)(arg1 * temp_v0->qnpt);
        return;
    }
    player->uspt = 0x1E8;
}
