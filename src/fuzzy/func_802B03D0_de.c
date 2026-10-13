#include "types.h"
#include "n64sdk.h"

typedef struct SeqFreeVoice { struct SeqFreeVoice *next; char pad[0x34]; } SeqFreeVoice;
typedef struct SeqInitConfig {
    s32 voices, events;
    u8 channels, debug;
    u8 pad[2];
    void *heap;
    void *initOsc, *updateOsc, *stopOsc;
} SeqInitConfig;
typedef struct SeqInitPlayer {
    void *next;
    struct SeqInitPlayer *self;
    void *callback;
    char padC[8];
    void *driver;
    void *target;
    s32 time;
    void *bank;
    s32 uspt, delta, state;
    u16 mask;
    s16 volume;
    u8 channels, debug;
    u8 pad36[2];
    s16 eventType;
    char pad3A[0xE];
    char queue[0x14];
    s32 frameTime;
    void *channelState;
    SeqFreeVoice *allocHead, *allocTail, *freeList;
    void *initOsc, *updateOsc, *stopOsc;
    void *loopStart, *loopEnd;
    s32 loopCount;
} SeqInitPlayer;
extern void *D_800D4070;
extern char D_002B0554;
extern void *func_802B0340_de(s32, s32, void *, s32, s32);
extern void func_802B1990_de(void *);
extern void func_802AFFC0_de(void *, void *, s32);
extern void func_802B2FB0_de(void *, void *);

void func_802B03D0_de(SeqInitPlayer *p, SeqInitConfig *c) {
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
    func_802B1990_de(p);
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
    func_802B2FB0_de(D_800D4070, p);
}
