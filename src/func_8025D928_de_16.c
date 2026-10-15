#include "span_1000/code_8025D948.h"
#include "abi.h"
#include "acmd.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B369C.h"
#include "types.h"

extern void *func_802B0340_de(u8 *, s32, ALHeap *, s32, s32);

       /* alHeapDBAlloc */
extern void func_802B4598_de(ALSave *);

                             /* alSaveNew */
extern void func_802B44B0_de(ALAuxBus_s *, void *, s32);

              /* alAuxBusNew */
extern void func_802B4454_de(ALMainBus_s *, void *, s32);

             /* alMainBusNew */
extern void *func_802B64C0_de(ALSynth *, s16, ALSynConfig *, ALHeap *);

 /* alSynAllocFX */
extern s32 func_802B5540_de(void *, s32, void *);

                   /* alMainBusParam */


                   /* alLink */
extern void func_802B43A4_de(ALLoadFilter *, ALDMANew, ALHeap *);

   /* alLoadNew */

                   /* alLoadParam */
extern void func_802B450C_de(ALResampler *, ALHeap *);

              /* alResampleNew */
extern s32 func_802B5730_de(void *, s32, void *);

                   /* alResampleParam */
extern void func_802B45DC_de(ALEnvMixer4C *, ALHeap *);

               /* alEnvmixerNew */

                   /* alEnvmixerParam */
extern s32 func_802B3EDC_de(void *, s32, void *);

                   /* alAuxBusParam */
extern s32 func_802B6480_de(void *, s32, void *);

 /* alGlobals */

extern s32 func_802B3DB8_de(ALSynth4C *, s32);

         /* _timeToSamplesNoRound */
extern void func_802B3C7C_de(ALSynth4C *);

s32 func_802B2450_de(s32);

                   /* alSaveParam */

void func_802B3770_de(ALSynth *drvr, ALSynConfig *c)
{
    extern void func_802B2480_de(ListLink *, ListLink *);
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
        func_802B2480_de((ListLink *)pv, &drvr->pFreeList);
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

             /* _collectPVoices */

Acmd *func_802B3A44_de(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen)
{
    extern ALGlobals *D_800D4070;
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

    for (drvr->paramSamples = func_802B3D10_de(drvr, &client);
         drvr->paramSamples - drvr->curSamples < outLen;
         drvr->paramSamples = func_802B3D10_de(drvr, &client)) {
        drvr->paramSamples &= ~0xf;
        client->samplesLeft += func_802B3DB8_de(drvr, (*client->handler)(client));
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
    func_802B3C7C_de(drvr);
    return cmdlEnd;
}

void *func_802B3BF8_de(void) {
    extern func_802B8CC8_S1 *D_800D4070;
    void *temp_v0;
    void *var_v1;

    temp_v0 = D_800D4070->unk2C;
    var_v1 = 0;
    if (temp_v0 != 0) {
        var_v1 = temp_v0;
        D_800D4070->unk2C = *(void **)var_v1;
        *(void **)var_v1 = 0;
    }
    return var_v1;
}

void func_802B3C24_de(void *arg0) {
    extern void *D_800D4070;
    struct ALParam_s1C *parameter = arg0;
    ALGlobals *head = D_800D4070;
    parameter->next = head->drvr.paramList;
    head->drvr.paramList = arg0;
}

void func_802B3C3C_de(s32 arg0, s32 arg1) {
    s32 func_802B2480_de(s32, s32);
    func_802B2450_de(arg1);
    func_802B2480_de(arg1, arg0 + 0x14);
}
