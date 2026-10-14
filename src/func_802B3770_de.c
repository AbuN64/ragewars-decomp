#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B369C.h"
/* alSynNew, drafted from ultralib src/audio/synthesizer.c: builds the synthesizer from its config,
   allocating the save filter, the aux and main busses (with an effect when one is configured),
   every physical voice with its decoder, resampler and envelope mixer chain, and the free list of
   parameter updates. */
#include "types.h"

extern void *func_802B0340_de(u8 *, s32, ALHeap *, s32, s32);       /* alHeapDBAlloc */
extern void func_802B4598_de(ALSave *);                             /* alSaveNew */
extern void func_802B44B0_de(ALAuxBus_s *, void *, s32);              /* alAuxBusNew */
extern void func_802B4454_de(ALMainBus_s *, void *, s32);             /* alMainBusNew */
extern void *func_802B64C0_de(ALSynth *, s16, ALSynConfig *, ALHeap *); /* alSynAllocFX */
extern s32 func_802B5540_de(void *, s32, void *);                   /* alMainBusParam */
extern void func_802B2480_de(Link_func_802596B4_de *, Link_func_802596B4_de *);                   /* alLink */
extern void func_802B43A4_de(ALLoadFilter *, ALDMANew, ALHeap *);   /* alLoadNew */
extern s32 func_802BEAA4_de(void *, s32, void *);                   /* alLoadParam */
extern void func_802B450C_de(ALResampler *, ALHeap *);              /* alResampleNew */
extern s32 func_802B5730_de(void *, s32, void *);                   /* alResampleParam */
extern void func_802B45DC_de(ALEnvMixer4C *, ALHeap *);               /* alEnvmixerNew */
extern s32 func_802B51B8_de(void *, s32, void *);                   /* alEnvmixerParam */
extern s32 func_802B3EDC_de(void *, s32, void *);                   /* alAuxBusParam */
extern s32 func_802B6480_de(void *, s32, void *);                   /* alSaveParam */

void func_802B3770_de(ALSynth *drvr, ALSynConfig *c)
{
    s32 i;
    PVoice_s *pv;
    PVoice_s *pvoices;
    ALHeap *hp = c->heap;
    ALSave *save;
    ALFilter_s14 *sources;
    ALParam_s1C *params;
    ALParam_s1C *paramPtr;

    drvr->head = 0;
    drvr->numPVoices = c->maxPVoices;
    drvr->curSamples = 0;
    drvr->paramSamples = 0;
    drvr->outputRate = c->outputRate;
    drvr->maxOutSamples = 160;
    drvr->dma = (ALDMANew)c->dmaproc;

    save = func_802B0340_de(0, 0, hp, 1, sizeof(ALSave));
    func_802B4598_de(save);
    drvr->outputFilter = (ALFilter_s14 *)save;

    drvr->auxBus = func_802B0340_de(0, 0, hp, 1, sizeof(ALAuxBus_s));
    drvr->maxAuxBusses = 1;
    sources = func_802B0340_de(0, 0, hp, c->maxPVoices, sizeof(ALFilter_s14 *));
    func_802B44B0_de(drvr->auxBus, sources, c->maxPVoices);

    drvr->mainBus = func_802B0340_de(0, 0, hp, 1, sizeof(ALMainBus_s));
    sources = func_802B0340_de(0, 0, hp, c->maxPVoices, sizeof(ALFilter_s14 *));
    func_802B4454_de(drvr->mainBus, sources, c->maxPVoices);

    if (c->fxType != 0) {
        func_802B64C0_de(drvr, 0, c, hp);
    } else
        func_802B5540_de(drvr->mainBus, 2, &drvr->auxBus[0]); /* AL_FILTER_ADD_SOURCE */

    drvr->pFreeList.next = 0;
    drvr->pFreeList.prev = 0;
    drvr->pLameList.next = 0;
    drvr->pLameList.prev = 0;
    drvr->pAllocList.next = 0;
    drvr->pAllocList.prev = 0;

    pvoices = func_802B0340_de(0, 0, hp, c->maxPVoices, sizeof(PVoice_s));
    for (i = 0; i < c->maxPVoices; i++) {
        pv = &pvoices[i];
        func_802B2480_de((Link_func_802596B4_de *)pv, &drvr->pFreeList);
        pv->vvoice = 0;

        func_802B43A4_de(&pv->decoder, drvr->dma, hp);
        func_802BEAA4_de(&pv->decoder, 1, 0); /* AL_FILTER_SET_SOURCE */

        func_802B450C_de(&pv->resampler, hp);
        func_802B5730_de(&pv->resampler, 1, &pv->decoder);

        func_802B45DC_de(&pv->envmixer, hp);
        func_802B51B8_de(&pv->envmixer, 1, &pv->resampler);

        func_802B3EDC_de(drvr->auxBus, 2, &pv->envmixer);

        pv->channelKnob = (ALFilter_s14 *)&pv->envmixer;
    }

    func_802B6480_de(save, 1, drvr->mainBus);

    params = func_802B0340_de(0, 0, hp, c->maxUpdates, sizeof(ALParam_s1C));
    drvr->paramList = 0;
    for (i = 0; i < c->maxUpdates; i++) {
        paramPtr = &params[i];
        paramPtr->next = drvr->paramList;
        drvr->paramList = paramPtr;
    }
    drvr->heap = hp;
}
