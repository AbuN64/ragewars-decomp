#include "types.h"
#include "span_1000/code_802B369C.h"
extern char D_800C7570;
extern char D_800C7574;
extern void func_802BAC50_de(void *, void *, s32);
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
