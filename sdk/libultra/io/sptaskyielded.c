#include "include_asm.h"
#include "COMMON/AIPROFILE.H"
#include "../../include/libultra/io/sptaskyielded.h"
#include "../../include/libultra/io/spgetstat.h"


s32 osSpTaskYielded(void *taskState)
{
    s32 selected_bit;
    u32 status;
    ResourceKeyView *state = taskState;

    status = __osSpGetStatus();
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
