#include "span_1000/code_80208000.h"
#include "shared/gameplay_transition.h"
#include "span_1000/code_8020FDB0.h"
#include "types.h"
#include "span_1000/code_8020EAE0.h"
#include "span_1000/code_802106E0.h"







void func_802100E0_de(void *arg0) {
    AiController *controller = arg0;
    s32 temp_v0;

    if ((func_802744D4_de() % 100) < 0x15) {
        do {
            temp_v0 = func_80232ABC_de(controller->player);
        } while (temp_v0 >= 0x10);
        ((Shared_ActorView *)controller->player)->nextWeapon = temp_v0;
        if (temp_v0 != ((Shared_ActorView *)controller->player)->selectedAction) {
            controller->unk2E4 = 0;
        }
    }
}
