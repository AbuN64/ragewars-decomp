#include "COMMON/LLDIVRESULT.H"
#include "abi.h"
#include "acmd.h"
#include "COMMON/MATH_HELPERS.H"
#include "../../../include/LOAD_DECODE.H"
#include "COMMON/AUDIO_LOADDECODEDSAMPLES.H"
#include "TYPES.H"
#include "include_asm.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"

/* 802BE370_2.CPP */
#if !(defined(VERSION_DE) || defined(VERSION_EU))
/* Decode ADPCM samples, restarting loops and clearing exhausted input.
 * The decode helper uses the existing table-opaque view of this same filter. */
Acmd *alAdpcmPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    s16 inp;
    s32 tsam;
    s32 nframes;
    s32 nbytes;
    s32 overFlow;
    s32 startZero;
    s32 nOver;
    s32 nSam;
    s32 op;
    s32 nLeft;
    s32 bEnd;
    s32 decoded = 0;
    s32 looped = 0;
    ALLoadFilter48_2 *f = (ALLoadFilter48_2 *)filter;
    if (outCount == 0)
        return ptr;
    inp = 0;
    aLoadADPCM(ptr++, f->bookSize,
               Sound_GetCachedAudioBlockAddress(f->table->waveInfo.adpcmWave.book->book, f->bookSize));
    looped = (outCount + f->sample > f->loop.end) && (f->loop.count != 0);
    if (looped)
        nSam = f->loop.end - f->sample;
    else
        nSam = outCount;
    if (f->lastsam)
        nLeft = 16 - f->lastsam;
    else
        nLeft = 0;
    tsam = nSam - nLeft;
    if (tsam < 0) tsam = 0;
    nframes = (tsam + 16 - 1) >> 4;
    nbytes = nframes * 9;
    if (looped) {
        ptr = decodeChunk(ptr, (ALLoadFilter48_2 *)f, tsam, nbytes, *outp, inp, f->first);
        if (f->lastsam)
            *outp += (f->lastsam << 1);
        else
            *outp += (16 << 1);
        f->lastsam = f->loop.start & 0xf;
        f->memin = (s32)f->table->base + 9 *
            ((s32)(f->loop.start >> 4) + 1);
        f->sample = f->loop.start;
        bEnd = *outp;
        while (outCount > nSam) {
            outCount -= nSam;
            op = (bEnd + ((nframes + 1) << (4 + 1))) & ~0x1f;
            bEnd += (nSam << 1);
            if ((f->loop.count != -1) && (f->loop.count != 0))
                f->loop.count--;
            nSam = RW_MIN_LT(outCount, f->loop.end - f->loop.start);
            tsam = nSam - 16 + f->lastsam;
            if (tsam < 0) tsam = 0;
            nframes = (tsam + 16 - 1) >> 4;
            nbytes = nframes * 9;
            ptr = decodeChunk(ptr, (ALLoadFilter48_2 *)f, tsam, nbytes, op, inp, f->first | 0x02);
            aDMEMMove(ptr++, op + (f->lastsam << 1), bEnd, nSam << 1);
        }
        f->lastsam = (outCount + f->lastsam) & 0xf;
        f->sample += outCount;
        f->memin += 9 * nframes;
        return ptr;
    }
    nSam = nframes << 4;
    overFlow = f->memin + nbytes - ((s32)f->table->base + f->table->len);
    if (overFlow < 0)
        overFlow = 0;
    nOver = (overFlow / 9) << 4;
    if (nOver > nSam + nLeft)
        nOver = nSam + nLeft;
    nbytes -= overFlow;
    if ((nOver - (nOver & 0xf)) < outCount) {
        decoded = 1;
        ptr = decodeChunk(ptr, (ALLoadFilter48_2 *)f, nSam - nOver, nbytes, *outp, inp, f->first);
        if (f->lastsam)
            *outp += (f->lastsam << 1);
        else
            *outp += (16 << 1);
        f->lastsam = (outCount + f->lastsam) & 0xf;
        f->sample += outCount;
        f->memin += 9 * nframes;
    } else {
        f->lastsam = 0;
        f->memin += 9 * nframes;
    }
    if (nOver) {
        f->lastsam = 0;
        if (decoded)
            startZero = (nLeft + nSam - nOver) << 1;
        else
            startZero = 0;
        aClearBuffer(ptr++, startZero + *outp, nOver << 1);
    }
    return ptr;
}
#endif

#if defined(VERSION_DE)
Acmd *alAdpcmPull(ALLoadFilter48_2 *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    s16 inp;
    s32 tsam;
    s32 nframes;
    s32 nbytes;
    s32 overFlow;
    s32 startZero;
    s32 nOver;
    s32 nSam;
    s32 op;
    s32 nLeft;
    s32 bEnd;
    s32 decoded = 0;
    s32 looped = 0;

    ALLoadFilter48_2 *f = filter;

    if (outCount == 0)
        return ptr;

    inp = 0;
    aLoadADPCM(ptr++, f->bookSize,
               Sound_GetCachedAudioBlockAddress(f->table->waveInfo.adpcmWave.book->book, f->bookSize));

    looped = (outCount + f->sample > f->loop.end) && (f->loop.count != 0);
    if (looped)
        nSam = f->loop.end - f->sample;
    else
        nSam = outCount;

    if (f->lastsam)
        nLeft = 16 - f->lastsam;
    else
        nLeft = 0;
    tsam = nSam - nLeft;
    if (tsam < 0) tsam = 0;

    nframes = (tsam + 16 - 1) >> 4;
    nbytes = nframes * 9;

    if (looped) {

        ptr = decodeChunk(ptr, (ALLoadFilter48_2 *)f, tsam, nbytes, *outp, inp, f->first);

        if (f->lastsam)
            *outp += (f->lastsam << 1);
        else
            *outp += (16 << 1);

        f->lastsam = f->loop.start & 0xf;
        f->memin = (s32)f->table->base + 9 *
            ((s32)(f->loop.start >> 4) + 1);
        f->sample = f->loop.start;

        bEnd = *outp;
        while (outCount > nSam) {

            outCount -= nSam;

            op = (bEnd + ((nframes + 1) << (4 + 1))) & ~0x1f;

            bEnd += (nSam << 1);

            if ((f->loop.count != -1) && (f->loop.count != 0))
                f->loop.count--;

            nSam = (((outCount) < (f->loop.end - f->loop.start)) ? (outCount) : (f->loop.end - f->loop.start));
            tsam = nSam - 16 + f->lastsam;
            if (tsam < 0) tsam = 0;
            nframes = (tsam + 16 - 1) >> 4;
            nbytes = nframes * 9;
            ptr = decodeChunk(ptr, (ALLoadFilter48_2 *)f, tsam, nbytes, op, inp, f->first | 0x02);

            aDMEMMove(ptr++, op + (f->lastsam << 1), bEnd, nSam << 1);
        }

        f->lastsam = (outCount + f->lastsam) & 0xf;
        f->sample += outCount;
        f->memin += 9 * nframes;
        return ptr;
    }

    nSam = nframes << 4;

    overFlow = f->memin + nbytes - ((s32)f->table->base + f->table->len);
    if (overFlow < 0)
        overFlow = 0;
    nOver = (overFlow / 9) << 4;
    if (nOver > nSam + nLeft)
        nOver = nSam + nLeft;

    nbytes -= overFlow;

    if ((nOver - (nOver & 0xf)) < outCount) {
        decoded = 1;
        ptr = decodeChunk(ptr, (ALLoadFilter48_2 *)f, nSam - nOver, nbytes, *outp, inp, f->first);

        if (f->lastsam)
            *outp += (f->lastsam << 1);
        else
            *outp += (16 << 1);

        f->lastsam = (outCount + f->lastsam) & 0xf;
        f->sample += outCount;
        f->memin += 9 * nframes;
    } else {
        f->lastsam = 0;
        f->memin += 9 * nframes;
    }

    if (nOver) {
        f->lastsam = 0;
        if (decoded)
            startZero = (nLeft + nSam - nOver) << 1;
        else
            startZero = 0;
        aClearBuffer(ptr++, startZero + *outp, nOver << 1);
    }

    return ptr;
}
#endif

#if defined(VERSION_EU)
#include "../../../include/LOAD_DECODE.H"

Acmd *alAdpcmPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd        *ptr = p;
    s16         inp;
    s32         tsam;
    s32         nframes;
    s32         nbytes;
    s32         overFlow;
    s32         startZero;
    s32         nOver;
    s32         nSam;
    s32         op;
    s32         nLeft;
    s32         bEnd;
    s32         decoded = 0;
    s32         looped = 0;

    ALLoadFilter48_2 *f = (ALLoadFilter48_2 *)filter;

    if (outCount == 0)
        return ptr;

    inp = 0;
    aLoadADPCM(ptr++, f->bookSize,
               Sound_GetCachedAudioBlockAddress(f->table->waveInfo.adpcmWave.book->book, f->bookSize));

    looped = (outCount + f->sample > f->loop.end) && (f->loop.count != 0);
    if (looped)
        nSam = f->loop.end - f->sample;
    else
        nSam = outCount;

    if (f->lastsam)
        nLeft = 16 - f->lastsam;
    else
        nLeft = 0;
    tsam = nSam - nLeft;
    if (tsam<0) tsam = 0;

    nframes = (tsam+16-1)>>4;
    nbytes =  nframes*9;

    if (looped){

        ptr = decodeChunk(ptr, f, tsam, nbytes, *outp, inp, f->first);


        if (f->lastsam)
            *outp += (f->lastsam<<1);
        else
            *outp += (16<<1);


        f->lastsam = f->loop.start &0xf;
        f->memin = (s32) f->table->base + 9 *
            ((s32) (f->loop.start>>4) + 1);
        f->sample = f->loop.start;

        bEnd = *outp;
        while (outCount > nSam){

            outCount -= nSam;


            op = (bEnd + ((nframes+1)<<(4+1))) & ~0x1f;


            bEnd += (nSam<<1);


            if ((f->loop.count != -1) && (f->loop.count != 0))
                f->loop.count--;


            nSam = (outCount < f->loop.end - f->loop.start ? outCount : f->loop.end - f->loop.start);
            tsam = nSam - 16 + f->lastsam;
            if (tsam<0) tsam = 0;
            nframes = (tsam+16-1)>>4;
            nbytes =  nframes*9;
            ptr = decodeChunk(ptr, f, tsam, nbytes, op, inp, f->first | 2);

            aDMEMMove(ptr++, op+(f->lastsam<<1), bEnd, nSam<<1);

        }

        f->lastsam = (outCount + f->lastsam) & 0xf;
        f->sample += outCount;
        f->memin += 9*nframes;

        return ptr;
    }



    nSam = nframes<<4;


    overFlow = f->memin + nbytes - ((s32) f->table->base + f->table->len);
    if (overFlow < 0)
        overFlow = 0;
    nOver = (overFlow/9)<<4;
    if (nOver > nSam + nLeft)
        nOver = nSam + nLeft;

    nbytes -= overFlow;

    if ((nOver - (nOver & 0xf))< outCount){
        decoded = 1;
        ptr = decodeChunk(ptr, f, nSam - nOver, nbytes, *outp, inp, f->first);

        if (f->lastsam)
            *outp += (f->lastsam<<1);
        else
            *outp += (16<<1);

        f->lastsam = (outCount + f->lastsam) & 0xf;
        f->sample += outCount;
        f->memin += 9*nframes;
    } else {
        f->lastsam = 0;
        f->memin += 9*nframes;
    }


    if (nOver){
        f->lastsam = 0;
        if (decoded)
            startZero = (nLeft + nSam - nOver)<<1;
        else
            startZero = 0;
        aClearBuffer(ptr++, startZero + *outp, nOver<<1);
    }

    return ptr;
}
#endif

/* Streams raw 16-bit samples into DMEM for the requested byte count: clears the output when the wave table is empty, otherwise refills a 0x100-sample block at g_audioTransformInputStream through Audio_NextDecodedSampleBlock and osWritebackDCache whenever the filter has none left (clearing and stopping when none arrives), then loads the available samples at 8-byte alignment and moves them into place. Adapted from alRaw16Pull (alRaw16Pull) with the loop handling replaced by the streamed block, updated through a pointer to g_audioTransformInputStream. */
extern s32 Audio_NextDecodedSampleBlock();

extern void osWritebackDCache(s32 buffer, s32 size);

/* alRaw16Pull, drafted from ultralib src/audio/load.c: DMA raw 16-bit samples into DMEM at 8-byte
   alignment for the requested output count, restarting from the loop start and merging the
   sections in DMEM when the count crosses the loop end, and clearing what runs past the table. */
Acmd *alRaw16Pull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
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
    ALLoadFilter48_2 *f = (ALLoadFilter48_2 *)filter;
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

Acmd *Audio_LoadDecodedSamples(ALLoadFilter48_2 *filter, s16 *outp, s32 byteCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    s32 nbytes;
    s32 dramAlign;
    s32 dmemAlign;
    s32 nSam;
    s32 op;
    ALLoadFilter48_2 *f = filter;
    s32 *stream;
    op = *outp;
    if (f->table->base == 0) {
        aClearBuffer(ptr++, op, byteCount << 1);
        return ptr;
    }
    if (byteCount != 0) {
        stream = &g_audioTransformInputStream;
        do {
            nSam = byteCount;
            if (f->sample == 0) {
                g_audioTransformInputStream = Audio_NextDecodedSampleBlock();
                if (g_audioTransformInputStream == 0) {
                    aClearBuffer(ptr++, op, byteCount << 1);
                    return ptr;
                }
                osWritebackDCache(g_audioTransformInputStream, 0x200);
                f->sample = 0x100;
            }
            if (f->sample < byteCount) {
                nSam = f->sample;
            }
            nbytes = nSam << 1;
            dramAlign = g_audioTransformInputStream & 0x7;
            nbytes += dramAlign;
            if (op & 0x7) {
                dmemAlign = 8 - (op & 0x7);
            } else {
                dmemAlign = 0;
            }
            aSetBuffer(ptr++, 0, op + dmemAlign, 0, nbytes + 8 - (nbytes & 0x7));
            aLoadBuffer(ptr++, (g_audioTransformInputStream & 0x1FFFFFFF) - dramAlign);
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

/* alLoadParam, drafted from ultralib src/audio/load.c: set a load filter's wave table, choosing the
   pull handler and loop points by the table's type, or reset its decode state. This cartridge's
   version has no table length rounding and a third wave type (2) handled by Audio_LoadDecodedSamples; the
   handlers are addressed by the cartridge at 0x002Cxxxx (alAdpcmPull_Address, alRaw16Pull_Address, Audio_LoadDecodedSamples_Address). */
 /* alCopy */

 /* alAdpcmPull */
 /* alRaw16Pull */
 /* the type 2 pull handler */

s32 alLoadParam(void *filter, s32 paramID, struct ALWaveTable_s *param)
{
    ALLoadFilter48_2 *a = (ALLoadFilter48_2 *)filter;
    ALFilter_s14 *f = (ALFilter_s14 *)filter;

    switch (paramID) {
        case 5: /* AL_FILTER_SET_WAVETABLE */
            a->table = param;
            a->memin = (s32)a->table->base;
            a->sample = 0;
            switch (a->table->type) {
                case 0: /* AL_ADPCM_WAVE */
                    f->handler = &alAdpcmPull_Address;
                    a->bookSize = 2 * a->table->waveInfo.adpcmWave.book->order *
                        a->table->waveInfo.adpcmWave.book->npredictors * 8;
                    if (a->table->waveInfo.adpcmWave.loop) {
                        a->loop.start = a->table->waveInfo.adpcmWave.loop->start;
                        a->loop.end = a->table->waveInfo.adpcmWave.loop->end;
                        a->loop.count = a->table->waveInfo.adpcmWave.loop->count;
                        ((void (*)(void *, void *, s32))alCopy)(a->table->waveInfo.adpcmWave.loop->state,
                                      a->lstate, sizeof(ADPCM_STATE));
                    } else {
                        a->loop.start = a->loop.end = a->loop.count = 0;
                    }
                    break;

                case 1: /* AL_RAW16_WAVE */
                    f->handler = &alRaw16Pull_Address;
                    if (a->table->waveInfo.rawWave.loop) {
                        a->loop.start = a->table->waveInfo.rawWave.loop->start;
                        a->loop.end = a->table->waveInfo.rawWave.loop->end;
                        a->loop.count = a->table->waveInfo.rawWave.loop->count;
                    } else {
                        a->loop.start = a->loop.end = a->loop.count = 0;
                    }
                    break;

                case 2:
                    f->handler = &Audio_LoadDecodedSamples_Address;
                    a->loop.start = a->loop.end = a->loop.count = 0;
                    break;

                default:
                    break;
            }
            break;

        case 4: /* AL_FILTER_RESET */
            a->lastsam = 0;
            a->first = 1;
            a->sample = 0;

            if (a->table) {
                a->memin = (s32)a->table->base;
                if (a->table->type == 0) {
                    if (a->table->waveInfo.adpcmWave.loop)
                        a->loop.count = a->table->waveInfo.adpcmWave.loop->count;
                } else if (a->table->type == 1) {
                    if (a->table->waveInfo.rawWave.loop)
                        a->loop.count = a->table->waveInfo.rawWave.loop->count;
                }
            }
            break;

        default:
            break;
    }
}

/* decodeChunk, libultra's ADPCM chunk decoder called by alAdpcmPull (alAdpcmPull): DMA the next
   ADPCM bytes into DMEM aligned down to 8 bytes, set the loop state when looping, and queue the ADPCM
   decode of tsam samples. */
Acmd *decodeChunk(Acmd *ptr, ALLoadFilter48_2 *f, s32 tsam, s32 nbytes, s16 outp, s16 inp, u32 flags)
{
    s32 dramAlign, dramLoc;

    if (nbytes > 0) {
        dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
        dramAlign = dramLoc & 0x7;
        nbytes += dramAlign;
        aSetBuffer(ptr++, 0, inp, 0, nbytes + 8 - (nbytes & 0x7));
        aLoadBuffer(ptr++, dramLoc - dramAlign);
    } else
        dramAlign = 0;

    if (flags & 0x02) {
        aSetLoop(ptr++, ((u32)(f->lstate) & 0x1FFFFFFF));
    }

    aSetBuffer(ptr++, 0, inp + dramAlign, outp, tsam << 1);
    aADPCMdec(ptr++, flags, ((u32)(f->state) & 0x1FFFFFFF));
    f->first = 0;

    return ptr;
}

#if defined(VERSION_US)
unsigned int k_LoadEncodedWords[1] = {
    0x72696453,
};
#endif

/* 802C6A00_18.CPP */
#if defined(VERSION_US_REV1)
unsigned char g_LoadTrailingBytesBlock3[4] = { 0x45, 0x00, 0x00, 0x08 };
#endif

/* 802C6A00_19.CPP */
#if defined(VERSION_EU_X)
unsigned char g_LoadTrailingBytesBlock2[4] = { 0x45, 0x00, 0x00, 0x08 };
#endif

/* 802C6A00_2.CPP */
#if defined(VERSION_DE)
unsigned char g_LoadTrailingBytes[4] = { 0x3C, 0x04, 0x80, 0x0D };
#endif

/* 802C6A00_3.CPP */
#if defined(VERSION_EU)
unsigned char g_LoadTrailingBytesBlock1[4] = { 0xAF, 0xBF, 0x00, 0x18 };
#endif
