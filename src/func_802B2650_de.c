#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B2614.h"
#include "span_1000/code_802B7488.h"
#include "types.h"
#include "audio_callbacks.h"
/* alSndpNew, drafted from ultralib src/audio/sndplayer.c: sets up a sound player from its config,
   allocating the sound states and event items from the heap, registers its voice handler with the
   global synthesizer and posts the first frame API event. */

























extern ALGlobals_func_802B2650_de *D_800D4070; /* alGlobals */

extern void *func_802B0340_de(u8 *, s32, ALHeap *, s32, s32);          /* alHeapDBAlloc */
extern void func_802AFFC0_de(ALEventQueue *, ALEventListItem *, s32);  /* alEvtqNew */
extern void func_802B2FB0_de(ALSynth_func_802B2650_de *, ALPlayer_s14 *);                   /* alSynAddPlayer */
extern void func_802B00D4_de(ALEventQueue *, Message_func_802AF150_de *, s32);          /* alEvtqPostEvent */
extern s32 func_802B003C_de(ALEventQueue *, Message_func_802AF150_de *);                /* alEvtqNextEvent */
/* _sndpVoiceHandler (func_802B2BBC_de); the cartridge stores the handler by its 0x002B7C8C address. */
extern s32 D_002B2BBC(void *);

void func_802B2650_de(ALSndPlayer_func_802B2650_de *sndp, ALSndpConfig *c)
{
    u8 *ptr;
    Message_func_802AF150_de evt;
    ALSoundState *sState;
    u32 i;

    sndp->maxSounds = c->maxSounds;
    sndp->target = -1;
    sndp->frameTime = 16000;
    sState = (ALSoundState *)func_802B0340_de(0, 0, c->heap, 1, c->maxSounds * sizeof(ALSoundState));
    sndp->sndState = sState;

    for (i = 0; i < c->maxSounds; i++)
        sState[i].sound = 0;

    ptr = func_802B0340_de(0, 0, c->heap, 1, c->maxEvents * sizeof(ALEventListItem));
    func_802AFFC0_de(&sndp->evtq, (ALEventListItem *)ptr, c->maxEvents);

    sndp->drvr = &D_800D4070->drvr;

    sndp->node.next = 0;
    sndp->node.handler = D_002B2BBC;
    sndp->node.clientData = sndp;
    func_802B2FB0_de(sndp->drvr, &sndp->node);

    evt.type = 5; /* AL_SNDP_API_EVT */
    func_802B00D4_de(&sndp->evtq, (Message_func_802AF150_de *)&evt, sndp->frameTime);
    sndp->nextDelta = func_802B003C_de(&sndp->evtq, &sndp->nextEvent);
}
