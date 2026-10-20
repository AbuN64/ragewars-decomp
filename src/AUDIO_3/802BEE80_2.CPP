#include "COMMON/EXTERNS_2.H"
#include "TYPES.H"
#include "COMMON/HARDWARE_IO.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/OSTASK_T.H"
#include "AUDIO_3/802BF1F0.H"
#include "sdk/libgultra/sp.h"

extern s32 __osSpDeviceBusy(void);

void osSpTaskStartGo(void) {
    do {
    } while (__osSpDeviceBusy() != 0);
    func_802BA100_de(0x125U);
}
