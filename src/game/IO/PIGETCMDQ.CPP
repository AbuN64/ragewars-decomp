#include "include_asm.h"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "IO/PIGETCMDQ.H"

s32 Io_GetPeripheralCommandQueue(void)
{
  int interruptMask;
  s32 *commandQueueAddress;
  interruptMask = (*((s32 *) (((s8 *) (&g_piManagerState)) + 0))) != 0;
  if (interruptMask)
  {
    if (commandQueueAddress)
    {
      commandQueueAddress = (s32 *) (((s8 *) (&g_piManagerState)) + 8);
      return *commandQueueAddress;
    }
    else
    {
      commandQueueAddress = (s32 *) (((s8 *) (&g_piManagerState)) + 8);
      return *commandQueueAddress;
    }
  }
  return 0;
}

#if defined(VERSION_EU)
unsigned int func_802B8DC8_de_padding_B9C68[2] = {
    0x46010002, 0x3C01800D,
};
#endif

#if defined(VERSION_DE)
unsigned int func_802B8DC8_de_padding_B99C8[2] = {
    0x0080A021, 0xAFB5002C,
};
#endif
