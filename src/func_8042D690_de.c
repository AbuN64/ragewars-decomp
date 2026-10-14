#include "span_16E000/code_8042BD40.h"
#include "types.h"
/* Runs one frame of the screen D_800E53C0's confirmation prompt while D_800E28E0 is not positive:
   on the first frame it marks the prompt open at 0x320 and asks func_802991D4_de for message 0x238,
   or 0x237 when func_8040EBD0_de rejects the object loaded for 0x238, then calls func_802A2360_de. Once
   the choice word D_80154020[1] reads one it clears it and either enables the prompt's object at
   0xE4 and records the choice at 0x328, when the pending action D_80154020[0] is -1, or disables
   the object, clears 0x328 and hands the pending action to func_80298368_de through func_8029973C_de.
   Returns zero. On eu-x both message ids are renumbered 5 higher. */



extern struct Screen_func_8042D690_de *D_800E53C0;
extern s32 D_800E28E0;
extern s32 D_80154020[];

extern void *func_8040EC30_de(s32, s32);
extern s32 func_8040EBD0_de(void *);
extern void func_802991D4_de(s32);
extern void func_802A2360_de();
extern void func_8040E8D8_de(void *, s32);
extern void func_8029973C_de();
extern void func_80298368_de(s32);

#if defined(VERSION_DE)
enum { CONFIRM_MESSAGE = 0x234, FALLBACK_MESSAGE = 0x233 };
#elif defined(VERSION_EU_X)
enum { CONFIRM_MESSAGE = 0x23D, FALLBACK_MESSAGE = 0x23C };
#else
enum { CONFIRM_MESSAGE = 0x238, FALLBACK_MESSAGE = 0x237 };
#endif

s32 func_8042D690_de(s32 context) {
    s32 *choice;
    s32 taken;
    s32 message;

    if (D_800E28E0 <= 0) {
        if (D_800E53C0->open == 0) {
            D_800E53C0->open = 1;
            if (func_8040EBD0_de(func_8040EC30_de(context, CONFIRM_MESSAGE)) == 0) {
                message = CONFIRM_MESSAGE;
            } else {
                message = FALLBACK_MESSAGE;
            }
            func_802991D4_de(message);
            func_802A2360_de();
        }
        choice = &D_80154020[1];
        taken = choice[0];
        if (taken == 1) {
            choice[0] = 0;
            if (choice[-1] != -1) {
                func_8040E8D8_de(D_800E53C0->object, 0);
                D_800E53C0->choice = 0;
                func_8029973C_de();
                func_80298368_de(choice[-1]);
                return 0;
            }
            func_8040E8D8_de(D_800E53C0->object, 1);
            D_800E53C0->choice = taken;
        }
    }
    return 0;
}
