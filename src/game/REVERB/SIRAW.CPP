#include "TYPES.H"
#include "COMMON/CONTROLLER_MOTOR_STATE.H"
#include "AUDIO/SIRAW.H"

/** Report whether either low bit of the VI current register is set. */
int Audio_IsSerialInterfaceBusy(void) {
    return (*(volatile unsigned int *)0xA4800018 & 3) != 0;
}
