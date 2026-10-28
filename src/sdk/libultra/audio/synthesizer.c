#include "COMMON/EXTERNS_2.H"
#include "abi.h"
#include "acmd.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/STATERECAT34.H"
#include "COMMON/ALAUXBUS_S.H"
#include "sdk/libultra/audio/synthesizer.h"
#include "TYPES.H"
#include "sdk/libgultra_inferred/802B8DE0_2.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"
#include "sdk/al_globals.h"
#include "sdk/libgultra.h"
#include "COMMON/UNUSED.H"
#include "include_asm.h"
#include "COMMON/OSPIHANDLE_S.H"
#include "AUDIO/802BFD40.H"

extern void *func_802B0340_de(u8 *, s32, ALHeap *, s32, s32);

       /* alHeapDBAlloc */
extern void alSaveNew(ALSave *);

                             /* alSaveNew */
extern void alAuxBusNew(ALAuxBus_s *, void *, s32);

              /* alAuxBusNew */
extern void alMainBusNew(ALMainBus_s *, void *, s32);

             /* alMainBusNew */
extern void *Audio_AllocateSynthesizerEffect(ALSynth *, s16, ALSynConfig *, ALHeap *);

 /* alSynAllocFX */
extern s32 alMainBusParam(void *, s32, void *);

                   /* alMainBusParam */


                   /* alLink */
extern void alLoadNew(ALLoadFilter *, ALDMANew, ALHeap *);

   /* alLoadNew */

                   /* alLoadParam */
extern void alResampleNew(ALResampler *, ALHeap *);

              /* alResampleNew */
extern s32 alResampleParam(void *, s32, void *);

                   /* alResampleParam */
extern void alEnvmixerNew(ALEnvMixer4C *, ALHeap *);

               /* alEnvmixerNew */

                   /* alEnvmixerParam */
extern s32 alAuxBusParam(void *, s32, void *);

                   /* alAuxBusParam */
extern s32 alSaveParam(void *, s32, ALFilter_s14 *);

 /* alGlobals */

s32 _timeToSamplesNoRound(func_8022E694_S1 *arg0, s32 arg1);

         /* _timeToSamplesNoRound */
void _collectPVoices(void *arg0);


                   /* alSaveParam */

void alSynNew(ALSynth *drvr, ALSynConfig *c)
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
    alSaveNew(save);
    drvr->outputFilter = (ALFilter_s14 *)save;

    drvr->auxBus = func_802B0340_de(0, 0, hp, 1, sizeof(ALAuxBus_s));
    drvr->maxAuxBusses = 1;
    sources = func_802B0340_de(0, 0, hp, c->maxPVoices, sizeof(ALFilter_s14 *));
    alAuxBusNew(drvr->auxBus, sources, c->maxPVoices);

    drvr->mainBus = func_802B0340_de(0, 0, hp, 1, sizeof(ALMainBus_s));
    sources = func_802B0340_de(0, 0, hp, c->maxPVoices, sizeof(ALFilter_s14 *));
    alMainBusNew(drvr->mainBus, sources, c->maxPVoices);

    if (c->fxType != 0) {
        Audio_AllocateSynthesizerEffect(drvr, 0, c, hp);
    } else
        alMainBusParam(drvr->mainBus, 2, &drvr->auxBus[0]); /* AL_FILTER_ADD_SOURCE */

    drvr->pFreeList.next = 0;
    drvr->pFreeList.prev = 0;
    drvr->pLameList.next = 0;
    drvr->pLameList.prev = 0;
    drvr->pAllocList.next = 0;
    drvr->pAllocList.prev = 0;

    pvoices = func_802B0340_de(0, 0, hp, c->maxPVoices, sizeof(PVoice_s));
    for (i = 0; i < c->maxPVoices; i++) {
        pv = &pvoices[i];
        alLink((ListLink *)pv, &drvr->pFreeList);
        pv->vvoice = 0;

        alLoadNew(&pv->decoder, drvr->dma, hp);
        alLoadParam(&pv->decoder, 1, 0); /* AL_FILTER_SET_SOURCE */

        alResampleNew(&pv->resampler, hp);
        alResampleParam(&pv->resampler, 1, &pv->decoder);

        alEnvmixerNew(&pv->envmixer, hp);
        alEnvmixerParam(&pv->envmixer, 1, &pv->resampler);

        alAuxBusParam(drvr->auxBus, 2, &pv->envmixer);

        pv->channelKnob = (ALFilter_s14 *)&pv->envmixer;
    }

    alSaveParam(save, 1, drvr->mainBus);

    params = func_802B0340_de(0, 0, hp, c->maxUpdates, sizeof(ALParam_s1C));
    drvr->paramList = 0;
    for (i = 0; i < c->maxUpdates; i++) {
        paramPtr = &params[i];
        paramPtr->next = drvr->paramList;
        drvr->paramList = paramPtr;
    }
    drvr->heap = hp;
}

             /* _collectPVoices */

Acmd *alAudioFrame(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen)
{
    ALPlayer_s14 *client;
    ALFilter_sC *output;
    ALSynth4C *drvr = &D_800D4070->drvr;
    s16 tmp = 0;
    Acmd *cmdlEnd = cmdList;
    Acmd *cmdPtr;
    s32 nOut;
    s16 *lOutBuf = outBuf;

    if (drvr->head == 0) {
        *cmdLen = 0;
        return cmdList;
    }

    for (drvr->paramSamples = __nextSampleTime(drvr, &client);
         drvr->paramSamples - drvr->curSamples < outLen;
         drvr->paramSamples = __nextSampleTime(drvr, &client)) {
        drvr->paramSamples &= ~0xf;
        client->samplesLeft += _timeToSamplesNoRound(drvr, (*client->handler)(client));
    }
    drvr->paramSamples &= ~0xf;

    while (outLen > 0) {
        nOut = ((drvr->maxOutSamples) < (outLen) ? (drvr->maxOutSamples) : (outLen));

        cmdPtr = cmdlEnd;
        aSegment(cmdPtr++, 0, 0);

        output = drvr->outputFilter;
        (*output->setParam)(output, 6, lOutBuf); /* AL_FILTER_SET_DRAM */
        cmdlEnd = (*output->handler)(output, &tmp, nOut, drvr->curSamples, cmdPtr);

        outLen -= nOut;
        lOutBuf += nOut << 1;
        drvr->curSamples += nOut;
    }

    *cmdLen = (s32)(cmdlEnd - cmdList);
    _collectPVoices(drvr);
    return cmdlEnd;
}

void *Audio_AllocParam(void) {
    void *head;
    void *param;

    head = D_800D4070->drvr.paramList;
    param = 0;
    if (head != 0) {
        param = head;
        D_800D4070->drvr.paramList = *(void **)param;
        *(void **)param = 0;
    }
    return param;
}

void Audio_FreeParam(void *arg0) {
    struct ALParam_s1C *parameter = arg0;
    ALGlobals *head = D_800D4070;
    parameter->next = head->drvr.paramList;
    head->drvr.paramList = arg0;
}

void _freePVoice(s32 arg0, s32 listLink) {
    alUnlink((ListLink *)listLink);
    alLink(listLink, arg0 + 0x14);
}

void _collectPVoices(void *arg0) {
    void *node;

    node = ((ALSynth4C *)arg0)->pLameList.next;
    if (node != 0) {
        do {
            alUnlink(node);
            alLink(node, (char *)arg0 + 4);
            node = ((ALSynth4C *)arg0)->pLameList.next;
        } while (node != 0);
    }
}

s32 _timeToSamples(func_8022E694_S1 *arg0, s32 arg1) {
    f32 v;
    int idx;

    v = (f32)arg1 * (f32)arg0->unk44;
    idx = 0;
    v = v * D_800C7588[idx];
    v = v + D_800C7588[1];
    return (s32)v & ~0xF;
}

extern char D_800C7570;

extern char s_audioSynthesizerText;


s32 __nextSampleTime(ALSynth4C *drvr, ALPlayer_s14 **client) {
 s32 smallest = 0x7FFFFFFF;
 ALPlayer_s14 *scan;
 if (drvr->head == 0) Audio_Assert(&D_800C7570, &s_audioSynthesizerText, 0x133);
 *client = 0;
 scan = drvr->head;
 if (scan != 0) {
  do {
   if (scan->samplesLeft - drvr->curSamples < smallest) {
    *client = scan;
    smallest = scan->samplesLeft - drvr->curSamples;
   }
   scan = scan->next;
  } while (scan != 0);
 }
 return (*client)->samplesLeft;
}

s32 _timeToSamplesNoRound(func_8022E694_S1 *arg0, s32 arg1) {
    f32 v;
    int idx;

    v = (f32)arg1 * (f32)arg0->unk44;
    idx = 0;
    v = v * D_800C7590[idx];
    v = v + D_800C7590[1];
    return (s32)v;
}

#if defined(VERSION_EU_X)
unsigned int func_802B40D4_eu_x_padding_B4CD4[3] = {
    0x00021040, 0x8623001A, 0x3C01800E,
};
#endif

#if defined(VERSION_DE)
unsigned int func_802B3DF4_de_padding_B49F4[3] = {
    0xAFB40028, 0x00A0A021, 0xAFB30024,
};
#endif
