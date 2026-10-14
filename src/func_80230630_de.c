#include "common/unused.h"
#include "shared/gameplay_transition.h"
#include "span_1000/code_8022C894.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022F3E8.h"
#include "types.h"



extern char D_800CE8DC;
extern AudioState D_801468A0;


extern s16 func_8022F96C_de(void *arg0);
extern void func_8022B9C4_de(void *arg0);
extern s32 func_8025DE54_de(s16 arg0, Vec3 position, s32 arg4, s32 arg5);
extern void func_8022FDAC_de(void *arg0, void *arg1);












void func_80230630_de(void *arg0, void *arg1) {
    s32 state;
    void *actor;
    AudioState *audio;
    s32 mode;

    actor = ((Actor_func_8024A7A0_de *)arg0)->controller;
    state = *(s16 *)(&D_800CE8DC +
                     (((Actor_func_8022D290_de *)actor)->unk_0x0650 * 0x18));
    if ((s8)((Dest *)arg1)->count != 0) {
        if (func_80222AA4_de(actor, ((Actor_func_8022D290_de *)actor)->unk_0x062E) == 0) {
            if (((Dest *)arg1)->field13C == 2) {
                ((Dest *)arg1)->field13C = 1;
                if (func_80222AA4_de(actor, ((Actor_func_8022D290_de *)actor)->unk_0x062E) == 0) {
                    ((Actor_func_8022D290_de *)actor)->unk_0x0770 = func_8022F96C_de(actor);
                }
            }
        }
    }
    func_8022B9C4_de(actor);
    ((Actor_func_8022D290_de *)actor)->unk_0x11FC = 0;
    ((WeaponAnimationState *)((Shared_ActorView *)actor)->controller)->speed = 0;
    ((Dest *)arg1)->field138 = 0;

    audio = &D_801468A0;
    if ((audio->active != 0) &&
        (((Shared_ActorView *)actor)->controls->transientFlag != 0)) {
        if (((Actor_func_8022D290_de *)actor)->unk_0x06B0 & 0x2000) {
            mode = audio->mode;
            switch (mode) {
            case 0:
                func_8025DE54_de(0x18A1,
                              ((Shared_ActorView *)actor)->position.vector,
                              (s32)&((Player *)actor)->pos, -1);
                break;
            case 1:
                func_8025DE54_de(0x1969,
                              ((Shared_ActorView *)actor)->position.vector,
                              (s32)&((Player *)actor)->pos, -1);
                break;
            case 2:
                func_8025DE54_de(0x1905,
                              ((Shared_ActorView *)actor)->position.vector,
                              (s32)&((Player *)actor)->pos, -1);
                break;
            }
        }
    } else if ((state != 1) && (state != 7) &&
               ((s8)((Dest *)arg1)->count != 0)) {
        func_8022FDAC_de(arg0, arg1);
    }
}
