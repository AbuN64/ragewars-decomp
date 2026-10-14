#include "abi.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BE0D0.h"
#include "types.h"
#include "abi.h"
#include "acmd.h"
#include "audio_callbacks.h"
#include "math_helpers.h"
/* alRaw16Pull, drafted from ultralib src/audio/load.c: DMA raw 16-bit samples into DMEM at 8-byte
   alignment for the requested output count, restarting from the loop start and merging the
   sections in DMEM when the count crosses the loop end, and clearing what runs past the table. */
Acmd *func_802BE514_de(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    s32 nbytes;
    s32 dramLoc;
    s32 dramAlign;
    s32 dmemAlign;
    s32 overFlow;
    s32 startZero;
    s32 nSam;
    s32 op;
    ALLoadFilter_func_802BE514_de *f = (ALLoadFilter_func_802BE514_de *)filter;
    ALFilter_s14 *a = (ALFilter_s14 *)filter;
    if (outCount == 0)
        return ptr;
    if ((outCount + f->sample > f->loop.end) && (f->loop.count != 0)) {
        nSam = f->loop.end - f->sample;
        nbytes = nSam << 1;
        if (nSam > 0) {
            dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
            dramAlign = dramLoc & 0x7;
            nbytes += dramAlign;
            aSetBuffer(ptr++, 0, *outp, 0, nbytes + 8 - (nbytes & 0x7));
            aLoadBuffer(ptr++, dramLoc - dramAlign);
        } else
            dramAlign = 0;
        *outp += dramAlign;
        f->memin = (s32)f->table->base + (f->loop.start << 1);
        f->sample = f->loop.start;
        op = *outp;
        while (outCount > nSam) {
            op += (nSam << 1);
            outCount -= nSam;
            if ((f->loop.count != -1) && (f->loop.count != 0))
                f->loop.count--;
            nSam = RW_MIN_LT(outCount, f->loop.end - f->loop.start);
            nbytes = nSam << 1;
            dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
            dramAlign = dramLoc & 0x7;
            nbytes += dramAlign;
            if (op & 0x7)
                dmemAlign = 8 - (op & 0x7);
            else
                dmemAlign = 0;
            aSetBuffer(ptr++, 0, op + dmemAlign, 0, nbytes + 8 - (nbytes & 0x7));
            aLoadBuffer(ptr++, dramLoc - dramAlign);
            if (dramAlign || dmemAlign)
                aDMEMMove(ptr++, op + dramAlign + dmemAlign, op, nSam << 1);
        }
        f->sample += outCount;
        f->memin += (outCount << 1);
        return ptr;
    }
    nbytes = outCount << 1;
    overFlow = f->memin + nbytes - ((s32)f->table->base + f->table->len);
    if (overFlow < 0)
        overFlow = 0;
    if (overFlow > nbytes)
        overFlow = nbytes;
    if (overFlow < nbytes) {
        if (outCount > 0) {
            nbytes -= overFlow;
            dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
            dramAlign = dramLoc & 0x7;
            nbytes += dramAlign;
            aSetBuffer(ptr++, 0, *outp, 0, nbytes + 8 - (nbytes & 0x7));
            aLoadBuffer(ptr++, dramLoc - dramAlign);
        } else
            dramAlign = 0;
        *outp += dramAlign;
        f->sample += outCount;
        f->memin += outCount << 1;
    } else {
        f->memin += outCount << 1;
    }
    if (overFlow) {
        startZero = (outCount << 1) - overFlow;
        if (startZero < 0)
            startZero = 0;
        aClearBuffer(ptr++, startZero + *outp, overFlow);
    }
    return ptr;
}
/* Streams raw 16-bit samples into DMEM for the requested byte count: clears the output when the wave table is empty, otherwise refills a 0x100-sample block at D_800D9360 through func_802C016C_de and func_802BD280_de whenever the filter has none left (clearing and stopping when none arrives), then loads the available samples at 8-byte alignment and moves them into place. Adapted from func_802BE514_de (alRaw16Pull) with the loop handling replaced by the streamed block, updated through a pointer to D_800D9360. */
extern s32 D_800D9360;
extern s32 func_802C016C_de();
extern void func_802BD280_de(s32 buffer, s32 size);
Acmd *func_802C3988(void *filter, s16 *outp, s32 byteCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    s32 nbytes;
    s32 dramAlign;
    s32 dmemAlign;
    s32 nSam;
    s32 op;
    ALLoadFilter_func_802BE514_de *f = (ALLoadFilter_func_802BE514_de *)filter;
    s32 *stream;
    op = *outp;
    if (f->table->base == 0) {
        aClearBuffer(ptr++, op, byteCount << 1);
        return ptr;
    }
    if (byteCount != 0) {
        stream = &D_800D9360;
        do {
            nSam = byteCount;
            if (f->sample == 0) {
                D_800D9360 = func_802C016C_de();
                if (D_800D9360 == 0) {
                    aClearBuffer(ptr++, op, byteCount << 1);
                    return ptr;
                }
                func_802BD280_de(D_800D9360, 0x200);
                f->sample = 0x100;
            }
            if (f->sample < byteCount) {
                nSam = f->sample;
            }
            nbytes = nSam << 1;
            dramAlign = D_800D9360 & 0x7;
            nbytes += dramAlign;
            if (op & 0x7) {
                dmemAlign = 8 - (op & 0x7);
            } else {
                dmemAlign = 0;
            }
            aSetBuffer(ptr++, 0, op + dmemAlign, 0, nbytes + 8 - (nbytes & 0x7));
            aLoadBuffer(ptr++, (D_800D9360 & 0x1FFFFFFF) - dramAlign);
            if (dramAlign || dmemAlign) {
                aDMEMMove(ptr++, op + dramAlign + dmemAlign, op, nSam << 1);
            }
            byteCount -= nSam;
            op += nSam << 1;
            *stream += nSam << 1;
            f->sample -= nSam;
        } while (byteCount != 0);
    }
    return ptr;
}
