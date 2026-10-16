#include "sdk/libgultra.h"
#include "span_1000/code_802B7058.h"
#include "TYPES.H"

/* Returns whether the audio interface status register at 0xA450000C has its top bit (FIFO full)
   set. */
s32 __osAiDeviceBusy(void) {
    return *(volatile s32 *) 0xA450000C >> 31 != 0;
}
