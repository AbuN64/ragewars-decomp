#include "span_16E000/code_804196C0.h"
#include "types.h"

/* Sets how many more times a counted-loop sequence repeats; func_804196D8_de decrements it each
   time the sequence wraps and stops when it reaches zero. func_804198CC_de clears it on creation. */


void func_80419A04_de(struct FrameSequence_func_804199DC_de *sequence, s32 loops) {
    sequence->loops = loops;
}
