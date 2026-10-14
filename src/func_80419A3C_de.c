#include "span_16E000/code_804196C0.h"
#include "types.h"

/* Tests whether any of the given playback mode bits are set; func_804196D8_de asks it about bit 1
   (forward), 0x10 (ping-pong), 0x20 (counted loop) and 8 (loop) on every tick. */


s32 func_80419A3C_de(struct FrameSequence_func_804199DC_de *sequence, s32 bits) {
    return (sequence->unk5C & bits) != 0;
}
