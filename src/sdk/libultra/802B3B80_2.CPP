#include "include_asm.h"

#if defined(VERSION_EU)
#include "TYPES.H"
#include "COMMON/ALSEQUENCEPLAYER.H"
#include "COMMON/OBJECTSTATE10_2.H"
#include "sdk/al_globals.h"
extern s32 D_002B0554;
extern void *func_802B0340_de(s32, s32, void *, s32, s32);
extern void func_802B1990_de(void *);
extern void func_802AFFC0_de(void *, void *, s32);
extern void alSynAddPlayer(void *, void *);

void func_802B0670_eu(struct ALSequencePlayer *seqp, InitParams *c) {
    void *heap = c->context;
    void *drvr = D_800D4070;
    ALVoiceState *vs;
    ALVoiceState *voices;
    ALEventListItem *items;
    s32 i;
    seqp->base.chanMask = 0xFF;
    seqp->base.uspt = 0x1E8;
    seqp->base.bank = 0;
    seqp->base.target = 0;
    seqp->base.nextDelta = 0;
    seqp->base.state = 0;
    seqp->base.vol = 0x7FFF;
    seqp->base.drvr = drvr;
    seqp->base.debugFlags = c->debugFlags;
    seqp->base.frameTime = 0x3E80;
    seqp->base.curTime = 0;
    seqp->base.initOsc = c->value10;
    seqp->base.updateOsc = c->value14;
    seqp->base.stopOsc = c->value18;
    seqp->loopStart = 0;
    seqp->loopEnd = 0;
    seqp->loopCount = 0;
    seqp->base.nextEvent.type = 9;
    seqp->base.maxChannels = c->kind;
    seqp->base.chanState = func_802B0340_de(0, 0, heap, c->kind, sizeof(ALChanState10));
    func_802B1990_de(seqp);
    voices = func_802B0340_de(0, 0, heap, c->count38, sizeof(ALVoiceState));
    seqp->base.vFreeList = 0;
    for (i = 0; i < c->count38; i++) {
        vs = &voices[i];
        vs->next = seqp->base.vFreeList;
        seqp->base.vFreeList = vs;
    }
    seqp->base.vAllocHead = 0;
    seqp->base.vAllocTail = 0;
    items = func_802B0340_de(0, 0, heap, c->count1C, sizeof(ALEventListItem));
    func_802AFFC0_de(&seqp->base.evtq, items, c->count1C);
    seqp->base.node.next = 0;
    seqp->base.node.handler = &D_002B0554;
    seqp->base.node.clientData = seqp;
    alSynAddPlayer(D_800D4070, seqp);
}
#endif
