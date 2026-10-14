#include "span_1000/code_802B4730.h"
#include "types.h"

extern void func_802B53E0_de(void *arg0, void *a, void *b, s32 c);
extern s32 func_802B0340_de(s32, s32, void *, s32, s32);

extern char D_002B4730;
extern char D_002B51B8;

void func_802B45DC_de(void *arg0, s32 arg1) {
    s32 result;
    ALEnvMixer *mixer = arg0;

    func_802B53E0_de(arg0, &D_002B4730, &D_002B51B8, 4);
    result = func_802B0340_de(0, 0, arg1, 1, 0x50);
    mixer->state = result;
    mixer->first = 1;
    mixer->motion = 0;
    mixer->volume = 1;
    mixer->ltgt = 1;
    mixer->rtgt = 1;
    mixer->cvolL = 1;
    mixer->cvolR = 1;
    mixer->dryamt = 0;
    mixer->wetamt = 0;
    mixer->lratm = 1;
    mixer->lratl = 0;
    mixer->delta = 0;
    mixer->segEnd = 0;
    mixer->pan = 0;
    mixer->ctrlList = 0;
    mixer->ctrlTail = 0;
    mixer->sources = 0;
}
