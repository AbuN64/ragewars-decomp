#include "COMMON/RESOURCELOCKSTATE.H"
#include "TYPES.H"
#include "sdk/os.h"

extern s32 D_801047E0;
void func_80253CEC_de(s32 arg0, s32 message)
{
  osSendMesg(&D_801047E0, message, 1);
}
