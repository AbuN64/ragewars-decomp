#include "span_16E000/code_804196C0.h"
#include "types.h"

/* Clears playback mode bits in a frame sequence; func_80419A18_de sets them and func_804196D8_de clears
   bit 1 or 2 when it reverses a ping-pong sequence. */


void func_80419A28_de(struct FrameSequence_func_804199DC_de *sequence, s32 bits) {
    sequence->unk5C &= ~bits;
}
