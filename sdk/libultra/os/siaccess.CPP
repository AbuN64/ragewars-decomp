#include "TYPES.H"
#include "COMMON/CONTROLLER_MOTOR_STATE.H"
#include "TYPES.H"
#include "../../include/os.h"
#include "../../include/libultra/os/siaccess.h"

void __osSiRelAccess(void) {
    osSendMesg(&g_serialInterfaceAccessQueue, 0, 0);
}
