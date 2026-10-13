#include "common/types_8fd754e1e915.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80231F5C.h"
#include "types.h"



extern s32 func_802301F4_de(void *, void *);
extern s32 func_8025DE54_de(s16, Vec3, s32, s32);

extern s32 func_80214178_de(void *, void *, s32);
extern void func_8022B190_de(s32);








void func_80232CEC_de(void *arg0, void *arg1) {
    Player *state;

    state = ((Shared_Actor *)arg0)->entity;
    if (((WeaponFireState *)arg1)->triggerMode != 0) {
        if (func_802301F4_de(arg0, arg1) != 0) {
            ((WeaponFireState *)arg1)->triggerMode = 0;
            ((WeaponFireState *)arg1)->queuedAction = -1;
        } else {
            switch (state->selectedAction) {
            case 8:
                func_8025DE54_de(0xA3E, state->pos,
                              (s32)((char *)state + 8), -1);
            case 0:
            case 14:
                func_8022B00C_de(state);
                func_80214178_de(arg0, arg1, 2);
                break;
            default:
                func_80214178_de(arg0, arg1, 2);
                break;
            }
        }
        state->controllerMode = 1;
        state->controllerTimer = 0;
    } else if ((state->selectedAction == 12) &&
               ((state->inputFlags & 0x4000) != 0)) {
        func_8022B190_de((s32)state);
    }
}
