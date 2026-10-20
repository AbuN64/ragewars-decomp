#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"

/* The native ABI receives full words. Narrowing happens at the byte stores,
 * so callers may pass values such as 0x80 and 0xFF without sign extension. */
void func_802391AC_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
 do { if (arg0 != 0) { ((GameplayCamera *)arg0)->fadeStep = (s8) arg4; ((GameplayCamera *)arg0)->fadeMode = arg1; ((GameplayCamera *)arg0)->fadeStart = arg2; ((GameplayCamera *)arg0)->fadeEnd = arg3; ((GameplayCamera *)arg0)->fadeState = 0; ((GameplayCamera *)arg0)->fadeRed = (s8) arg5; ((GameplayCamera *)arg0)->fadeGreen = (s8) arg6; ((GameplayCamera *)arg0)->fadeBlue = (s8) arg7; ((GameplayCamera *)arg0)->fadeCounter = 0; ((GameplayCamera *)arg0)->fadeEnabled = 1; } } while (0);
}
