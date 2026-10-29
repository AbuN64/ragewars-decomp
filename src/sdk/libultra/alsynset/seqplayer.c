#include "sdk/libgultra.h"
#include "COMMON/ALBANK_S.H"
#include "COMMON/OBJRECAT18V1.H"
#include "TYPES.H"

void Seqplayer_SetTempoMicrosecondsPerTick(ALSeqPlayer *player, f32 tempo) {
    ALSeq_s *sequence;

    sequence = player->target;
    if (sequence != 0) {
        player->uspt = (s32)(tempo * sequence->qnpt);
        return;
    }
    player->uspt = 0x1E8;
}
