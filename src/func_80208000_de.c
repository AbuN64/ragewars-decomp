#include "span_1000/code_80208000.h"
#include "types.h"
/* Resets a player controller: marks the active, requested and committed selections empty, sets the
   request kind to 0xB, clears the four link words at 0x14 to -1, resets the stage counters at 0x1BC
   and 0x1C8 and the target list, installs the default table D_800CE040 through func_8020986C_de and mode
   2 through func_80209874_de, zeroes the tracking values from 0x23C to 0x260, runs the resets
   func_802110C4_de, func_80209988_de and func_8020999C_de, and clears the remaining state words. */

extern char D_800CE040;
extern void func_8020986C_de(void *, char *, s32);
extern void func_80209874_de(void *, s32);
extern void func_802110C4_de(void *);

extern void func_8020999C_de(void *);

void func_80208000_de(s32 *arg0) {
    s32 i;
    s32 none;

    arg0[1] = -1;
    arg0[2] = -1;
    arg0[3] = 0xB;
    arg0[4] = -1;
    arg0[11] = 0;
    arg0[12] = 0;
    arg0[13] = 0;
    none = -1;
    for (i = 3; i >= 0; i--) {
        arg0[5 + i] = none;
    }
    arg0[10] = -1;
    arg0[0x1BC / 4] = 0xFFFF;
    arg0[0x220 / 4] = 0;
    arg0[0x1C8 / 4] = 0;
    arg0[14] = 1;
    arg0[15] = 0;
    arg0[25] = 0;
    arg0[0x28C / 4] = 0;
    arg0[26] = 0;
    arg0[0xBC / 4] = -1;
    arg0[0x224 / 4] = -1;
    arg0[0x228 / 4] = 0;
    for (i = 0; i < 10; i++) {
        arg0[15 + i] = 0;
        arg0[27 + i] = 0;
        arg0[37 + i] = 0;
    }
    arg0[0x238 / 4] = 0;
    func_8020986C_de(arg0, &D_800CE040, none);
    func_80209874_de(arg0, 2);
    ((f32 *) arg0)[0x244 / 4] = 0.0f;
    arg0[0x23C / 4] = 0;
    arg0[0x240 / 4] = 0;
    ((f32 *) arg0)[0x250 / 4] = ((f32 *) arg0)[0x254 / 4] = ((f32 *) arg0)[0x248 / 4] =
        ((f32 *) arg0)[0x24C / 4] = ((f32 *) arg0)[0x258 / 4] = ((f32 *) arg0)[0x25C / 4] =
        ((f32 *) arg0)[0x260 / 4] = ((f32 *) arg0)[0x244 / 4];
    func_802110C4_de(arg0);
    func_80209988_de(arg0);
    func_8020999C_de(arg0);
    arg0[0x318 / 4] = 0;
    arg0[0x31C / 4] = 0;
    arg0[0x320 / 4] = -1;
    arg0[0x324 / 4] = 0;
    arg0[0x328 / 4] = 0;
    arg0[0x2D8 / 4] = 0;
    arg0[0x2E4 / 4] = 0;
    arg0[0x2EC / 4] = 0;
    arg0[0x2E8 / 4] = 0;
    arg0[0x2DC / 4] = 0;
    arg0[0x2E0 / 4] = 0;
    arg0[0x32C / 4] = -1;
}
