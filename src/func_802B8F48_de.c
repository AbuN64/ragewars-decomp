#include "span_1000/code_802B8DD0.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B369C.h"
#include "types.h"

extern char D_800C7570;

extern char D_800C7574;

extern void func_802BAC50_de(void *, void *, s32);

extern f32 D_800C7590[2];

s32 func_802B3D10_de(ALSynth4C *drvr, ALPlayer_s14 **client) {
 s32 smallest = 0x7FFFFFFF;
 ALPlayer_s14 *scan;
 if (drvr->head == 0) func_802BAC50_de(&D_800C7570, &D_800C7574, 0x133);
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
