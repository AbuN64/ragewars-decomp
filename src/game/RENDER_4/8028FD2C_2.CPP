#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "sdk/os.h"

void Render_SendSchedulerTask(s32 arg0, s32 arg1) {
    func_802BB420_de(arg0 + 0x78, arg1, 1);
    func_802BB420_de(arg0 + 0x40, 6, 1);
}
