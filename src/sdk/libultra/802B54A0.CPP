#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "sdk/BUF16B.H"
#include "sdk/libgultra/part_800C7F20/code_802B66A0_3.h"
#include "sdk/al_globals.h"

#if !(defined(VERSION_EU))
s32 func_802B0340_de(s32 a, s32 b, void *c, s32 d, s32 e);
extern void func_802AFFC0_de(void *, void *, s32);
extern void alSynAddPlayer(void *, void *);

void alCSPNew(SeqInitPlayer *p, ALSeqpConfig *c) {
    void *heap = c->heap;
    void *driver = D_800D4070;
    SeqFreeVoice *voice;
    void *events;
    s32 i;
    p->mask = 255;
    p->uspt = 488;
    p->bank = 0;
    p->target = 0;
    p->delta = 0;
    p->state = 0;
    p->volume = 32767;
    p->driver = driver;
    p->debug = c->debug;
    p->frameTime = 16000;
    p->time = 0;
    p->initOsc = c->initOsc;
    p->updateOsc = c->updateOsc;
    p->stopOsc = c->stopOsc;
    p->loopStart = 0;
    p->loopEnd = 0;
    p->loopCount = 0;
    p->eventType = 9;
    p->channels = c->channels;
    p->channelState = func_802B0340_de(0, 0, heap, c->channels, 16);
    __initChanState(p);
    {
        SeqFreeVoice *base = func_802B0340_de(0, 0, heap, c->voices, 56);
        p->freeList = 0;
        i = 0;
        if (c->voices > 0) {
            voice = base;
            do {
                voice->next = p->freeList;
                p->freeList = voice;
                i++;
                voice++;
            } while (i < c->voices);
        }
    }
    p->allocHead = 0;
    p->allocTail = 0;
    events = func_802B0340_de(0, 0, heap, c->events, 28);
    func_802AFFC0_de(p->queue, events, c->events);
    p->next = 0;
    p->callback = &D_002B0554;
    p->self = p;
    alSynAddPlayer(D_800D4070, p);
}
#endif
