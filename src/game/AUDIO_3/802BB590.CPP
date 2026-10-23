#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"
#include "COMMON/ALAUXBUS_S.H"
#include "AUDIO_3/802B8840.H"
#include "COMMON/ALDELAY28.H"
#include "TYPES.H"

extern void func_802B3F10_de(s32 arg0, s32 arg1, s32 arg2);
extern s32 alMainBusParam(void *arg0, s32 arg1, s32 arg2);




s32 func_802B64C0_de(ALSynth *arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 scaled = arg1 * 0x4C;
    s32 temp_a2;

    func_802B3F10_de((s32)arg0->auxBus + scaled + 0x20, arg2, arg3);
    temp_a2 = (s32)arg0->auxBus + scaled;
    alFxParam((int *)(temp_a2 + 0x20), 1, temp_a2);
    alMainBusParam(arg0->mainBus, 2, (s32)arg0->auxBus + scaled + 0x20);
    return (s32)arg0->auxBus + scaled + 0x20;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802B6484[3] = {
    0x03000000, 0x0000116D, 0x5F416D6D,
};
#endif
