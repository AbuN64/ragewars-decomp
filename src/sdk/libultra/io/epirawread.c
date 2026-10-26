#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/DEVICE_IO.H"
#include "COMMON/HARDWARE_IO.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "GAMECORE/EXTERNS.H"
#include "sdk/libultra/io/epirawread.H"
#include "AUDIO_3/802BFD40.H"

extern OSPiHandle_s *D_800D4380[];

s32 func_802B9590_de(OSPiHandle_s *arg0, u32 arg1, u32 *arg2) {
    OSPiHandle_s *previous;
    s32 index;

    if (arg2 == 0) {
        Audio_Assert(&D_800C7950_de, &s_epirawreadText, 0x2B);
    }
    while (IO_READ_WORD(PI_STATUS_REG) & 3) {
    }
    index = arg0->domain;
    previous = D_800D4380[index];
    if (previous != arg0) {
        if (index == 0) {
            if (previous->latency != arg0->latency) {
                IO_WRITE(0xA4600014U, arg0->latency);
            }
            if (previous->pageSize != arg0->pageSize) {
                IO_WRITE(0xA460001CU, arg0->pageSize);
            }
            if (previous->relDuration != arg0->relDuration) {
                IO_WRITE(0xA4600020U, arg0->relDuration);
            }
            if (previous->pulse != arg0->pulse) {
                IO_WRITE(0xA4600018U, arg0->pulse);
            }
        } else {
            if (previous->latency != arg0->latency) {
                IO_WRITE(0xA4600024U, arg0->latency);
            }
            if (previous->pageSize != arg0->pageSize) {
                IO_WRITE(0xA460002CU, arg0->pageSize);
            }
            if (previous->relDuration != arg0->relDuration) {
                IO_WRITE(0xA4600030U, arg0->relDuration);
            }
            if (previous->pulse != arg0->pulse) {
                IO_WRITE(0xA4600028U, arg0->pulse);
            }
        }
        D_800D4380[index] = arg0;
    }
    *arg2 = IO_READ_WORD(arg0->baseAddress | arg1 | 0xA0000000U);
    return 0;
}
