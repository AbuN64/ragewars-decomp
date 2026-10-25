#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/EXTERNS.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520_6.h"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"
#include "AUDIO_3/802BFD40.H"

/* _sndpVoiceHandler, drafted from ultralib src/audio/sndplayer.c: the sound player's synthesizer
   callback; reposts the frame API event or handles the pending event until the next one is in
   the future, then advances the player's time by that delta. The pointer to the pending event
   is held in a local, standing in for the address register -fforce-addr kept for it. */













   /* _handleEvent */
extern s32 func_802B003C_de(ALEventQueue *, ALEvent *);       /* alEvtqNextEvent */

s32 func_802B2BBC_de(void *node)
{
    ALSndPlayer *sndp = (ALSndPlayer *)node;
    ALSndpEvent evt;
    ALSndpEvent *next = (ALSndpEvent *)&sndp->nextEvent;

    do {
        switch (sndp->nextEvent.type) {
            case 5: /* AL_SNDP_API_EVT */
                evt.common.type = 5;
                func_802B00D4_de(&sndp->evtq, (ALEvent *)&evt, sndp->frameTime);
                break;
            default:
                func_802B2780_de(sndp, next);
                break;
        }
        sndp->nextDelta = func_802B003C_de(&sndp->evtq, &sndp->nextEvent);
    } while (sndp->nextDelta == 0);

    sndp->curTime += sndp->nextDelta;
    return sndp->nextDelta;
}

extern s32 func_802BD170_de(s32);








void func_802B2C48_de(ALEventQueue *arg0, void *arg1) {
    s32 saved;
    ALEventListItem *cur;
    ALEventListItem *next;

    saved = func_802BD170_de(1);
    cur = (ALEventListItem *)arg0->allocList.next;
    if (cur != 0) {
        do {
            next = (ALEventListItem *)cur->node.next;
            if (((ALSndpEvent *)&cur->evt)->common.state == arg1) {
                if (next != 0) {
                    next->delta = next->delta + cur->delta;
                }
                func_802B2450_de(cur);
                func_802B2480_de(cur, arg0);
            }
            cur = next;
        } while (cur != 0);
    }
    func_802BD170_de(saved);
}

s32 func_802B2CF0_de(s32 val, f32 div) {
    f32 fval;
    f64 dresult;
    s32 result;

    if (div == 0.0f) {
        Audio_Assert(D_800C7548, D_800C754C, 0x11D);
    }

    result = 0x7FFFFFFF;
    fval = (f32)val / div;
    dresult = (f64)fval;
    if (!(D_800C7560 < dresult)) {
        result = (s32)dresult;
    }
    return result;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802B2CA8[2] = {
    0x73540000, 0x02000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_802B2CF0_de_padding_B3C58[1] = {
    0x00000000,
};
#endif
