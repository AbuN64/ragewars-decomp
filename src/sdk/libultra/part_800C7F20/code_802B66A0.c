#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/ALDELAY28.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"



s32 __voiceNeedsNoteKill(void *arg0, s32 targetVoice, s32 releaseDeadline) {
    s32 amount;
    s32 total;
    s32 result;
    char *next;
    char *cur;

    total = 0;
    cur = ((ALSeqPlayer *)arg0)->evtq.allocList.next;
    result = 1;
    if (cur != 0) {
        do {
            amount = ((ALEventListItem *)cur)->delta;
            next = ((ALEventListItem *)cur)->node.next;
            total += amount;
            if (((ALEventListItem *)cur)->evt.type == 5 && (s32)((ALEvent *)&((ALEventListItem *)cur)->evt)->msg.note.voice == targetVoice) {
                if (releaseDeadline < total) {
                    if (next != 0) {
                        ((ALEventListItem *)next)->delta = ((ALEventListItem *)next)->delta + amount;
                    }
                    alUnlink(cur);
                    alLink(cur, &((ALSeqPlayer *)arg0)->evtq.freeList.next);
                    goto done;
                }
                result = 0;
                goto done;
            }
            cur = next;
        } while (cur != 0);
    }
done:
    return result;
}

/* __lookupVoice, drafted from ultralib src/audio/seqplayer.c: walk the sequence player's allocated
   voice list for the voice playing a key on a channel that is not being released. */









ALVoiceState *__lookupVoice(ALSeqPlayer *seqp, u8 key, u8 channel)
{
    ALVoiceState *vs;

    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
        if ((vs->key == key) && (vs->channel == channel) &&
            (vs->phase != 3) && (vs->phase != 4))
            return vs;
    }
    return 0;
}
