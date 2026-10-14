#include "span_16E000/code_804251F4.h"
#include "types.h"
/* Starts the ambient track for the current stage D_8015402C (stage 4, 9, 22 and 35 select tracks
   0 to 3): returns -1 when the stage has no track or when func_80265650_de reports the slot busy,
   otherwise starts it on arg0's 400-byte slot of D_80102C24 through func_80265688_de and returns
   0x13BC. */

extern u8 D_80102C24[];
extern s32 D_8015402C;
extern s32 func_80265650_de(u8 *, s32);
extern void func_80265688_de(u8 *, s32, s32);

s32 func_80425DFC_de(s32 arg0) {
    s32 result;
    s32 track;
    u8 *slot;

    result = -1;
    switch (D_8015402C) {
    case 4:
        track = 0;
        break;
    case 9:
        track = 1;
        break;
    case 0x16:
        track = 2;
        break;
    case 0x23:
        track = 3;
        break;
    default:
        track = -1;
        break;
    }
    if (track != -1) {
        slot = &D_80102C24[arg0 * 0x190];
        if (func_80265650_de(slot, track) == 0) {
            result = 0x13BC;
            func_80265688_de(slot, track, 1);
        }
    }
    return result;
}
