#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/DEVICE_IO.H"
#include "COMMON/HARDWARE_IO.H"
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "GAMECORE/EXTERNS.H"
#include "../../include/libultra/io/epirawread.H"
#include "AUDIO/AUDIO_ASSERT.H"

extern OSPiHandle_s *g_peripheralDomainHandles[];

s32 osEPiRawReadIo(OSPiHandle_s *piHandle, u32 deviceOffset, u32 *outputWord) {
    OSPiHandle_s *previous;
    s32 index;

    if (outputWord == 0) {
        Audio_Assert(&g_extendedPeripheralReadAssertText, &s_epirawreadText, 0x2B);
    }
    while (IO_READ_WORD(PI_STATUS_REG) & 3) {
    }
    index = piHandle->domain;
    previous = g_peripheralDomainHandles[index];
    if (previous != piHandle) {
        if (index == 0) {
            if (previous->latency != piHandle->latency) {
                IO_WRITE(0xA4600014U, piHandle->latency);
            }
            if (previous->pageSize != piHandle->pageSize) {
                IO_WRITE(0xA460001CU, piHandle->pageSize);
            }
            if (previous->relDuration != piHandle->relDuration) {
                IO_WRITE(0xA4600020U, piHandle->relDuration);
            }
            if (previous->pulse != piHandle->pulse) {
                IO_WRITE(0xA4600018U, piHandle->pulse);
            }
        } else {
            if (previous->latency != piHandle->latency) {
                IO_WRITE(0xA4600024U, piHandle->latency);
            }
            if (previous->pageSize != piHandle->pageSize) {
                IO_WRITE(0xA460002CU, piHandle->pageSize);
            }
            if (previous->relDuration != piHandle->relDuration) {
                IO_WRITE(0xA4600030U, piHandle->relDuration);
            }
            if (previous->pulse != piHandle->pulse) {
                IO_WRITE(0xA4600028U, piHandle->pulse);
            }
        }
        g_peripheralDomainHandles[index] = piHandle;
    }
    *outputWord = IO_READ_WORD(piHandle->baseAddress | deviceOffset | 0xA0000000U);
    return 0;
}
