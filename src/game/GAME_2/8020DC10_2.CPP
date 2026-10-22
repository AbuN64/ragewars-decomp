#include "COMMON/SELF.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ACTORREC.H"
#include "TYPES.H"

s32 func_8020DD04_de(s32);
s32 func_80209874_de(void *, s32);

void func_8020DCA0_de(CloseAttackBrain *arg0) {
    s32 temp_v0;
    if ((func_802744D4_de() % 4) == 1) {
        temp_v0 = func_8020DD04_de((s32)((Player *)arg0->player)->definition + 0x14);
        arg0->combat = temp_v0;
        func_80209874_de(arg0, temp_v0);
    }
}
