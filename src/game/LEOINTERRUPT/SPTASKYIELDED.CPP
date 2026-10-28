#include "include_asm.h"
#include "COMMON/AIPROFILE.H"
#include "AUDIO/SPTASKYIELDED.H"
#include "AUDIO/SPGETSTAT.H"


s32 Audio_CheckSignalProcessorTaskYield(void *arg0)
{
    s32 selected_bit;
    u32 status;
    func_80203E78_S1 *state = arg0;

    status = Audio_ReadSignalProcessorStatus();
    selected_bit = status >> 8;
    selected_bit = selected_bit & 1;
    if (status & 0x80) {
        state->unk4 = (state->unk4 | selected_bit) & ~2;
    }
    return selected_bit;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BA0BC[1] = {
    0x5F624475,
};
#endif
