#include "span_1000/code_802BE0D0.h"
#include "abi.h"
#include "span_1000/code_802BE0D0.h"
#include "common/unused.h"
#include "types.h"
#include "acmd.h"
#include "abi.h"
#include "audio_callbacks.h"

/* alLoadParam, drafted from ultralib src/audio/load.c: set a load filter's wave table, choosing the
   pull handler and loop points by the table's type, or reset its decode state. This cartridge's
   version has no table length rounding and a third wave type (2) handled by func_802C3988; the
   handlers are addressed by the cartridge at 0x002Cxxxx (D_002BE0D0, D_002BE514, D_002BE898). */
 /* alCopy */

 /* alAdpcmPull */
extern char D_002BE514; /* alRaw16Pull */
extern char D_002BE898; /* the type 2 pull handler */

s32 func_802BEAA4_de(void *filter, s32 paramID, void *param)
{
    ALLoadFilter48 *a = (ALLoadFilter48 *)filter;
    ALFilter_s14 *f = (ALFilter_s14 *)filter;

    switch (paramID) {
        case 5: /* AL_FILTER_SET_WAVETABLE */
            a->table = (struct ALWaveTable_s *)param;
            a->memin = (s32)a->table->base;
            a->sample = 0;
            switch (a->table->type) {
                case 0: /* AL_ADPCM_WAVE */
                    f->handler = &D_002BE0D0;
                    a->bookSize = 2 * a->table->waveInfo.adpcmWave.book->order *
                        a->table->waveInfo.adpcmWave.book->npredictors * 8;
                    if (a->table->waveInfo.adpcmWave.loop) {
                        a->loop.start = a->table->waveInfo.adpcmWave.loop->start;
                        a->loop.end = a->table->waveInfo.adpcmWave.loop->end;
                        a->loop.count = a->table->waveInfo.adpcmWave.loop->count;
                        ((void (*)(void *, void *, s32))func_802B0310_de)(a->table->waveInfo.adpcmWave.loop->state,
                                      a->lstate, sizeof(ADPCM_STATE));
                    } else {
                        a->loop.start = a->loop.end = a->loop.count = 0;
                    }
                    break;

                case 1: /* AL_RAW16_WAVE */
                    f->handler = &D_002BE514;
                    if (a->table->waveInfo.rawWave.loop) {
                        a->loop.start = a->table->waveInfo.rawWave.loop->start;
                        a->loop.end = a->table->waveInfo.rawWave.loop->end;
                        a->loop.count = a->table->waveInfo.rawWave.loop->count;
                    } else {
                        a->loop.start = a->loop.end = a->loop.count = 0;
                    }
                    break;

                case 2:
                    f->handler = &D_002BE898;
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

/* _decodeChunk, libultra's ADPCM chunk decoder called by alAdpcmPull (func_802C31C0): DMA the next
   ADPCM bytes into DMEM aligned down to 8 bytes, set the loop state when looping, and queue the ADPCM
   decode of tsam samples. */
Acmd *func_802BEC34_de(Acmd *ptr, ALLoadFilter48_2 *f, s32 tsam, s32 nbytes, s16 outp, s16 inp, u32 flags)
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
