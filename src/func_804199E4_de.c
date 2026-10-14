#include "span_16E000/code_804196C0.h"
#include "types.h"

/* Sets how long each frame of a sequence is shown; func_804196D8_de advances the frame once the
   time accumulated at 0x54 exceeds this. func_804198CC_de clears it when it builds the sequence. */


void func_804199E4_de(struct FrameSequence_func_804199DC_de *sequence, s32 duration) {
    sequence->duration = duration;
}
