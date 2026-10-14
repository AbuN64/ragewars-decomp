#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B369C.h"
#include "abi.h"
#include "types.h"
#include "acmd.h"
#include "abi.h"

extern ALGlobals *D_800D4070; /* alGlobals */

extern s32 func_802B3DB8_de(ALSynth4C *, s32);         /* _timeToSamplesNoRound */
extern void func_802B3C7C_de(ALSynth4C *);             /* _collectPVoices */

Acmd *func_802B3A44_de(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen)
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
