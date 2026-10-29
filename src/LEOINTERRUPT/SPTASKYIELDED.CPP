#include "include_asm.h"
#include "COMMON/AIPROFILE.H"
#include "AUDIO/SPTASKYIELDED.H"
#include "AUDIO/SPGETSTAT.H"


s32 Audio_CheckSignalProcessorTaskYield(void *taskState)
{
    s32 selected_bit;
    u32 status;
    ResourceKeyView *state = taskState;

    status = Audio_ReadSignalProcessorStatus();
    selected_bit = status >> 8;
    selected_bit = selected_bit & 1;
    if (status & 0x80) {
        state->key = (state->key | selected_bit) & ~2;
    }
    return selected_bit;
}

#if defined(VERSION_US)
unsigned int k_SptaskyieldedEncodedWords[1] = {
    0x5F624475,
};
#endif
