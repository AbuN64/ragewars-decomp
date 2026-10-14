#include "shared/gameplay_camera.h"
#include "span_1000/code_80233920.h"
#include "types.h"




/* The native ABI receives full words. Narrowing happens at the byte stores,
 * so callers may pass values such as 0x80 and 0xFF without sign extension. */
void func_802391AC_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
 do { if (arg0 != 0) { ((Shared_func_80234FDC_S2 *)arg0)->fadeStep = (s8) arg4; ((Shared_func_80234FDC_S2 *)arg0)->fadeMode = arg1; ((Shared_func_80234FDC_S2 *)arg0)->fadeStart = arg2; ((Shared_func_80234FDC_S2 *)arg0)->fadeEnd = arg3; ((Shared_func_80234FDC_S2 *)arg0)->fadeState = 0; ((Shared_func_80234FDC_S2 *)arg0)->fadeRed = (s8) arg5; ((Shared_func_80234FDC_S2 *)arg0)->fadeGreen = (s8) arg6; ((Shared_func_80234FDC_S2 *)arg0)->fadeBlue = (s8) arg7; ((Shared_func_80234FDC_S2 *)arg0)->fadeCounter = 0; ((Shared_func_80234FDC_S2 *)arg0)->fadeEnabled = 1; } } while (0);
}
