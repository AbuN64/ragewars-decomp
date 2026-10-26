#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALAUXBUS_S.H"
#include "TYPES.H"
#include "sdk/libgultra_inferred/802B8DE0_2.H"
#include "AUDIO_3/802BFD40.H"

extern char D_800C7570;

extern char s_audioSynthesizerText;


s32 func_802B3D10_de(ALSynth4C *drvr, ALPlayer_s14 **client) {
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

s32 func_802B3DB8_de(func_8022E694_S1 *arg0, s32 arg1) {
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
