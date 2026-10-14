#include "span_1000/code_802B0388.h"
#include "types.h"








/** Store a new history slot (pointer + selected byte/word fields) into the ring buffer at arg0+0x60. */
void func_802B1AC0_de(void *arg0, void *arg1, s32 arg2) {
    s32 stride = arg2 * 0x10;

    ((ALChanState10 *)(stride + (s32)((ALSeqPlayer *)arg0)->chanState))->instrument = arg1;
    ((ALChanState10 *)((stride + (s32)((ALSeqPlayer *)arg0)->chanState)))->pan = ((ALInstrument *)arg1)->pan;
    ((ALChanState10 *)((stride + (s32)((ALSeqPlayer *)arg0)->chanState)))->vol = ((ALInstrument *)arg1)->volume;
    ((ALChanState10 *)((stride + (s32)((ALSeqPlayer *)arg0)->chanState)))->priority = ((ALInstrument *)arg1)->priority;
    ((ALChanState10 *)((stride + (s32)((ALSeqPlayer *)arg0)->chanState)))->bendRange = (u16)((ALInstrument *)arg1)->bendRange;
}
