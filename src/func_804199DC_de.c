#include "span_16E000/code_804196C0.h"
#include "types.h"

/* func_804196D8_de advances a frame sequence: it adds elapsed time into offset 0x54 and, once that
   exceeds the duration at 0x58, moves the frame index at 0x4C through the -1 terminated array at
   0x48. func_804198CC_de resets the index through here after counting the frames. */


void func_804199DC_de(struct FrameSequence_func_804199DC_de *sequence, s32 frame) {
    sequence->frame = frame;
}
