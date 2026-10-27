#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"





s32 _allocatePVoice(void *synth, void **selectedVoice, s16 requestedPriority) {
    s16 lowestPriority;
    s32 voiceStolen;
    s32 stolenResultCopy;
    void *candidateVoice;

    lowestPriority = requestedPriority;
    candidateVoice = ((ALSynthalSynAllocVoice *)synth)->pLameList.next;
    voiceStolen = 0;
    if ((candidateVoice != 0) || (candidateVoice = ((ALSynthalSynAllocVoice *)synth)->pFreeList.next, (candidateVoice != 0))) {
        *selectedVoice = candidateVoice;
        alUnlink(candidateVoice);
        alLink(candidateVoice, &((ALSynthalSynAllocVoice *)synth)->pAllocList.next);
    } else {
        candidateVoice = ((ALSynthalSynAllocVoice *)synth)->pAllocList.next;
        stolenResultCopy = voiceStolen;
        if (candidateVoice != 0) {
            do {
                if ((lowestPriority >= ((NodeallocatePVoice *)candidateVoice)->limit->limit) &&
                    (((NodeallocatePVoice *)candidateVoice)->flags == 0)) {
                    *selectedVoice = candidateVoice;
                    voiceStolen = 1;
                    lowestPriority = (s16)(u16)((NodeallocatePVoice *)candidateVoice)->limit->limit;
                }
                candidateVoice = ((NodeallocatePVoice *)candidateVoice)->next;
                stolenResultCopy = voiceStolen;
            } while (candidateVoice != 0);
        }
    }
    return voiceStolen;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802B3118[2] = {
    0x00000066, 0x00000004,
};
#endif
