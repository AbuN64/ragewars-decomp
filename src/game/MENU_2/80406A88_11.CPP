#include "include_asm.h"

#if defined(VERSION_EU_X)
extern void func_8041B110_de(int id);

int func_80429C50_eu_x(void) { func_8041B110_de(0x1DD); func_8041B110_de(0x1DE); return 0; }
#endif

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
extern int func_80299A08_de(void), func_802999A0_de(s32);
extern void MarkMenuEventHandled(void), Items_ResetActorPools(void *, s32), func_804499B0_de(void *, s32, s32);
extern void func_80286AA8_de(void *, s32, s32), func_8025476C_de(s32), func_8042E988_de(s32), func_802998A8_de(void);
extern int func_8025477C_de(void);
extern u8 D_80145088[], g_world[];
/* Result handler of the main-menu pop-up: for event 0x1DD with answer 0x16 resets the session record D_80145088 and picks a
   next-state id from its mode byte at 0x124D; for 0x1DE passes 0xB when answered 0xB, else -1. Returns 0. */
s32 func_80429C78_eu_x(void) {
    s32 next;

    MarkMenuEventHandled();
    switch (func_80299A08_de()) {
    case 0x1DD:
        if (func_802999A0_de(0) == 0x16) {
            Items_ResetActorPools(D_80145088, 0);
            func_804499B0_de(D_80145088 - 0x48, 0, 0);
            func_80286AA8_de(g_world, 0, 0);
            if (func_8025477C_de() == 0) {
                func_8025476C_de(1);
            }
            *(s32 *)(D_80145088 + 0x17F0) = 8;
            switch (D_80145088[0x124D]) {
            case 0: next = 0x14; break;
            case 1: next = 0xA; break;
            case 2: next = 0xF; break;
            case 3: next = 0xA; break;
            default: next = 3; break;
            }
        } else {
            next = 3;
        }
        break;
    case 0x1DE:
        next = func_802999A0_de(0) == 0xB ? 0xB : -1;
        break;
    default:
        return 0;
    }
    func_8042E988_de(next);
    func_802998A8_de();
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80429C78_eu_x);
#endif
#endif
