#include "include_asm.h"
#include "COMMON/ALDELAY28.H"
#include "COMMON/ALAUXBUS_S.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALPARAM_S.H"
#include "TYPES.H"
#include "sdk/libgultra_inferred/802B975C_5.H"

extern s32 D_002B5570;
extern s32 D_002B5730;

s32 func_802B0340_de(s32 a, s32 b, void *c, s32 d, s32 e);

void func_802B450C_de(ALResampler_s *arg0, s32 arg1) {
    s32 result;
    f32 k;

    alFilterNew(arg0, &D_002B5570, &D_002B5730, 1);
    result = func_802B0340_de(0, 0, arg1, 1, 0x20);
    k = D_800C75E0_de;
    arg0->state = (void *)result;
    arg0->delta = 0;
    arg0->first = 1;
    arg0->motion = 0;
    arg0->upitch = 0;
    arg0->ctrlList = 0;
    arg0->ctrlTail = 0;
    arg0->ratio = k;
}

extern s32 D_002B6380;
extern s32 D_002B6480;
void alSaveNew(ALSave *arg0) {
    alFilterNew(arg0, (s32) &D_002B6380, (s32) &D_002B6480, 3);
    arg0->dramout = 0;
    arg0->first = 1;
}

extern s32 func_802B0340_de(s32, s32, void *, s32, s32);
extern char D_002B4730, D_002B51B8;

void func_802B45DC_de(ALEnvMixer *arg0, ALHeap *arg1) {
    s32 result;
    ALEnvMixer *mixer = arg0;

    alFilterNew(arg0, &D_002B4730, &D_002B51B8, 4);
    result = func_802B0340_de(0, 0, arg1, 1, 0x50);
    mixer->state = (void *)result;
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
    mixer->lratm = 1;
    mixer->lratl = 0;
    mixer->delta = 0;
    mixer->segEnd = 0;
    mixer->pan = 0;
    mixer->ctrlList = 0;
    mixer->ctrlTail = 0;
    mixer->sources = 0;
}
