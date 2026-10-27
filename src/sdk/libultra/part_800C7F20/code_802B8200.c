#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"





s32 func_802B3130_de(void *synth, void **selectedVoice, s16 requestedPriority) {
    s16 lowestPriority;
    s32 voiceStolen;
    s32 stolenResultCopy;
    void *candidateVoice;

    lowestPriority = requestedPriority;
    candidateVoice = ((ALSynth_func_802B3000_de *)synth)->pLameList.next;
    voiceStolen = 0;
    if ((candidateVoice != 0) || (candidateVoice = ((ALSynth_func_802B3000_de *)synth)->pFreeList.next, (candidateVoice != 0))) {
        *selectedVoice = candidateVoice;
        alUnlink(candidateVoice);
        alLink(candidateVoice, &((ALSynth_func_802B3000_de *)synth)->pAllocList.next);
    } else {
        candidateVoice = ((ALSynth_func_802B3000_de *)synth)->pAllocList.next;
        stolenResultCopy = voiceStolen;
        if (candidateVoice != 0) {
            do {
                if ((lowestPriority >= ((Node_func_802B3130_de *)candidateVoice)->limit->limit) &&
                    (((Node_func_802B3130_de *)candidateVoice)->flags == 0)) {
                    *selectedVoice = candidateVoice;
                    voiceStolen = 1;
                    lowestPriority = (s16)(u16)((Node_func_802B3130_de *)candidateVoice)->limit->limit;
                }
                candidateVoice = ((Node_func_802B3130_de *)candidateVoice)->next;
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
